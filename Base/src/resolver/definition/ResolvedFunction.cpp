//
// Created by roei on 20/10/18.
//

#include "ResolvedFunction.h"

#include "../Resolver.h"
#include "../../ast/identifier/VarIdentifier.h"

namespace enki {
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

    ResolvedFunction::ResolvedFunction(const AbstractIdentifier* identifier) : identifier(identifier) {}

    const ResolvedFunction* createFunction(Resolver &resolver, const FuncDefinition* funcDef) {
        auto func = new ResolvedFunction(funcDef->getFuncId());

        auto vars = funcDef->getFuncId()->variables();
        for (auto i = 0; i < vars.size(); i++) {
//            func->parameters.push_back(new ResolvedVarExpr(vars[i], func, i));
        }

        return func;
    }

    const AbstractIdentifier* ResolvedFunction::getIdentifier() const {
        return identifier;
    }

    const std::optional<const AbstractResolvedConstraint*> &ResolvedFunction::getConstraints() const {
        return constraints;
    }

    AbstractResolvedVal* ResolvedFunction::getReturnValue() const {
        return returnValue;
    }

    const std::vector<const ResolvedVarExpr*> &ResolvedFunction::getParameters() const {
        return parameters;
    }

    ResolvedFunction::~ResolvedFunction() {

    }
}
