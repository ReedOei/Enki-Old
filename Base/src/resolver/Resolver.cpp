//
// Created by roei on 27/10/18.
//

#include "Resolver.h"
#include "expression/ResolvedIntLiteral.h"
#include "constraints/ResolvedSingletonConstraint.h"
#include "../ast/constraints/SingletonConstraint.h"
#include "../ast/constraints/ConjConstraint.h"
#include "../ast/constraints/WhenBranch.h"
#include "../ast/constraints/WhenBranches.h"
#include "../ast/identifier/IntegerLiteral.h"
#include "../ast/identifier/TextLiteral.h"
#include "../ast/identifier/WordIdentifier.h"
#include "../ast/identifier/VarIdentifier.h"
#include "../ast/identifier/SymbolIdentifier.h"
#include "../ast/toplevel/FuncDefinition.h"
#include "definition/ResolvedFunction.h"
#include "expression/ResolvedFuncExpr.h"

namespace enki {
    Resolver::Resolver() = default;
    Resolver::~Resolver() = default;

    const ResolvedIntLiteral* Resolver::resolve(const IntegerLiteral* literal) {
        return new ResolvedIntLiteral(literal->value());
    }

    const ResolvedTextLiteral* Resolver::resolve(const TextLiteral* literal) {
        return new ResolvedTextLiteral(literal->value());
    }

    const Error<AbstractResolvedNode> Resolver::resolve(const AbstractIdentifier* id) {
        for (const auto &identifier : knownIdentifiers) {
            if (id->tryUnify(reinterpret_cast<const AbstractIdentifier*>(identifier.first)).succeeded()) {
                return Error<AbstractResolvedNode>(identifier.second);
            }
        }

        return Error<AbstractResolvedNode>("Unknown identifier: " + id->to_string());
    }

    const Error<ResolvedFunction> Resolver::resolve(const FuncDefinition* func) {
        return createFunction(*this, func);
    }

    const Error<AbstractResolvedConstraint> Resolver::resolve(const std::map<std::string, const ResolvedVarExpr*> &vars, const AbstractConstraint* constraint) {
        if (auto sc = dynamic_cast<const SingletonConstraint*>(constraint)) {
            return resolveRule(sc->getIdentifier()).bind<AbstractResolvedConstraint>([=](auto resolved) {
                return resolveParameters(vars, sc->getIdentifier(),
                                         resolved->getIdentifier()).template bind<AbstractResolvedConstraint>(
                        [=](auto params) {
                            return Error<AbstractResolvedConstraint>(
                                    new ResolvedSingletonConstraint(new ResolvedRuleExpr(resolved, *params)));
                        });
            });
        }

        return Error<AbstractResolvedConstraint>("temp");
    }

    const Error<ResolvedRule> Resolver::resolveRule(const AbstractIdentifier* id) {
        return Error<ResolvedRule>("temp");
    }

    const Error<AbstractResolvedVal> Resolver::resolveVal(const std::map<std::string, const ResolvedVarExpr*> &vars, const AbstractIdentifier* id) {
        auto definition = resolve(id);

        // Check if this is a function call
        if (definition.succeeded()) {
            if (auto func = dynamic_cast<const ResolvedFunction*>(definition.getRight())) {
                return resolveParameters(vars, id, func->getIdentifier()).bind<AbstractResolvedVal>([=](auto params) {
                    return Error<AbstractResolvedVal>(new ResolvedFuncExpr(func, *params));
                });
            }
        }

        // Check if it's some literal value
        if (auto tl = dynamic_cast<const TextLiteral*>(id)) {
            return Error<AbstractResolvedVal>(resolve(tl));
        } else if (auto il = dynamic_cast<const IntegerLiteral*>(id)) {
            return Error<AbstractResolvedVal>(resolve(il));
        } else if (auto v = dynamic_cast<const VarIdentifier*>(id)) {
            auto rv = vars.find(v->value());
            if (rv != vars.end()) {
                return Error<AbstractResolvedVal>(rv->second);
            } else {
                return Error<AbstractResolvedVal>("Unknown variable name: " + v->value());
            }
        }

        return Error<AbstractResolvedVal>("Could not resolve identifier: " + id->to_string());
    }

    const Error<std::vector<const AbstractResolvedVal*>>
    Resolver::resolveParameters(const std::map<std::string, const ResolvedVarExpr*> &vars,
                                const AbstractIdentifier* callExpr, const AbstractIdentifier* called) {
        auto unificationResult = callExpr->tryUnify(called);

        auto values = new std::vector<const AbstractResolvedVal*>();

        // Go through each unification pair, and make sure we can resolve every value.
        // If there's one we can't resolve, then we have to exit
        for (const auto matchPair : unificationResult.getUnified()) {
            auto resolvedOpt = resolveVal(vars, matchPair.first);

            if (resolvedOpt.succeeded()) {
                values->push_back(resolvedOpt.ok());
            } else {
                return Error<std::vector<const AbstractResolvedVal*>>("Could not resolve parameter: " + matchPair.first->to_string());
            }
        }

        return Error(values);
    }
}
