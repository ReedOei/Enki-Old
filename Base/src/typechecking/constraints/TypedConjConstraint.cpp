//
// Created by roei on 17/01/19.
//

#include "TypedConjConstraint.h"

namespace enki {
    TypedConjConstraint::TypedConjConstraint(const std::vector<const AbstractTypedConstraint*> &constraints)
            : constraints(constraints) {}

    TypedConjConstraint::~TypedConjConstraint() = default;

    const std::vector<const AbstractTypedConstraint*> &TypedConjConstraint::getConstraints() const {
        return constraints;
    }
}
