//
// Created by roei on 20/10/18.
//

#include <iostream>
#include "ResolvedFunction.h"

#include "../Resolver.h"
#include "../../ast/identifier/VarIdentifier.h"

namespace enki {
    ResolvedFunction::ResolvedFunction(const AbstractIdentifier* identifier) : identifier(identifier) {}
    ResolvedFunction::~ResolvedFunction() {
        for (const auto p : parameters) {
            delete p;
        }

        if (constraints.has_value()) {
            delete constraints.value();
        }

        delete returnValue;
    }

    const std::string enki::ResolvedFunction::nodeName() const {
        return "ResolvedFunction";
    }

    void ResolvedFunction::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        if (constraints.has_value()) {
            constraints.value()->accept(visitor);
        }

        returnValue->accept(visitor);

        for (const auto &param : parameters) {
            param->accept(visitor);
        }
    }

    const Error<ResolvedFunction> createFunction(Resolver &resolver, const FuncDefinition* funcDef) {
        auto func = new ResolvedFunction(funcDef->getFuncId());

        auto vars = funcDef->getFuncId()->variables();

        std::map<std::string, const ResolvedVarExpr*> varMap;
        for (auto i = 0; i < vars.size(); i++) {
            const auto v = new ResolvedVarExpr(vars[i]->value(), func, i);
            func->parameters.push_back(v);
            varMap[vars[i]->value()] = v;
        }

        auto funcVal = resolver.resolveVal(varMap, funcDef->getVal());

        if (funcVal.succeeded()) {
            func->returnValue = funcVal.ok();

            if (funcDef->getConstraint().has_value()) {
                return resolver.resolve(varMap, funcDef->getConstraint().value()).bind<ResolvedFunction>([=](auto constraint) {
                    func->constraints = constraint;

                    return Error(func);
                });
            } else {
                return Error(func);
            }
        } else {
            delete func;
            return Error<ResolvedFunction>(funcVal.getMsg());
        }
    }

    const AbstractIdentifier* ResolvedFunction::getIdentifier() const {
        return identifier;
    }

    const std::optional<const AbstractResolvedConstraint*> &ResolvedFunction::getConstraints() const {
        return constraints;
    }

    const AbstractResolvedVal* ResolvedFunction::getReturnValue() const {
        return returnValue;
    }

    const std::vector<const ResolvedVarExpr*> &ResolvedFunction::getParameters() const {
        return parameters;
    }
}
