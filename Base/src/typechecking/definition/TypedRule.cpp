//
// Created by roei on 17/01/19.
//

#include "TypedRule.h"

namespace enki {
    TypedRule::TypedRule(const AbstractIdentifier* identifier, const AbstractTypedConstraint* constraint,
                         const std::vector<const TypedVarExpr*> &parameters)
                         : identifier(identifier), constraint(constraint), parameters(parameters) {}

    TypedRule::~TypedRule() = default;

    const AbstractIdentifier* TypedRule::getIdentifier() const {
        return identifier;
    }

    const AbstractTypedConstraint* TypedRule::getConstraint() const {
        return constraint;
    }

    const std::vector<const TypedVarExpr*> &TypedRule::getParameters() const {
        return parameters;
    }
}
