//
// Created by roei on 17/01/19.
//

#include "TypedFunction.h"

namespace enki {
    TypedFunction::TypedFunction(const AbstractIdentifier* identifier,
                                 const std::optional<const AbstractTypedConstraint*> &constraints,
                                 const AbstractTypedVal* returnVal,
                                 const std::vector<const TypedVarExpr*> &parameters)
                                 : identifier(identifier), constraints(constraints), returnVal(returnVal), parameters(parameters) {}

    TypedFunction::TypedFunction(const AbstractIdentifier* identifier) : identifier(identifier) {}

    TypedFunction::~TypedFunction() = default;

    const AbstractIdentifier* TypedFunction::getIdentifier() const {
        return identifier;
    }

    const std::optional<const AbstractTypedConstraint*> &TypedFunction::getConstraints() const {
        return constraints;
    }

    const AbstractTypedVal* TypedFunction::getReturnVal() const {
        return returnVal;
    }

    const std::vector<const TypedVarExpr*> &TypedFunction::getParameters() const {
        return parameters;
    }
}
