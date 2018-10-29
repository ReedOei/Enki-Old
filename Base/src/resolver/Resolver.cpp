//
// Created by roei on 27/10/18.
//

#include "Resolver.h"
#include "expression/ResolvedIntLiteral.h"
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

    const ResolvedFunction* Resolver::resolve(const FuncDefinition* func) {
        return createFunction(*this, func);
    }

    const Error<AbstractResolvedVal> Resolver::resolveVal(const AbstractIdentifier* id) {
        auto definition = resolve(id);

        // Check if this is a function call
        if (definition.succeeded()) {
            if (auto func = dynamic_cast<const ResolvedFunction*>(definition.getRight())) {
                auto unificationResult = id->tryUnify(func->getIdentifier());

                std::vector<const AbstractResolvedVal*> values;

                // Go through each unification pair, and make sure we can resolve every value.
                // If there's one we can't resolve, then we have to exit
                for (const auto matchPair : unificationResult.getUnified()) {
                    auto resolvedOpt = resolveVal(matchPair.first);

                    if (resolvedOpt.succeeded()) {
                        values.push_back(resolvedOpt.ok());
                    } else {
                        // TODO: Replace this with an error message

                        return Error<AbstractResolvedVal>("Could not resolve parameter: " + matchPair.first->to_string());
                    }
                }

                return Error<AbstractResolvedVal>(new ResolvedFuncExpr(func, values));
            }
        }

        // Check if it's some literal value
        if (auto tl = dynamic_cast<const TextLiteral*>(id)) {
            return Error<AbstractResolvedVal>(resolve(tl));
        } else if (auto il = dynamic_cast<const IntegerLiteral*>(id)) {
            return Error<AbstractResolvedVal>(resolve(il));
        }

        return Error<AbstractResolvedVal>("Could not resolve identifier: " + id->to_string());
    }

    Resolver::~Resolver() {

    }
}
