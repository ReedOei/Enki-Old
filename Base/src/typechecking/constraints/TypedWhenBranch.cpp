//
// Created by roei on 17/01/19.
//

#include "TypedWhenBranch.h"

namespace enki {
    TypedWhenBranch::TypedWhenBranch(const AbstractTypedConstraint* matcher,
                                     const AbstractTypedConstraint* constraint)
                                     : matcher(matcher), constraint(constraint) {}

    TypedWhenBranch::~TypedWhenBranch() = default;

    const AbstractTypedConstraint* TypedWhenBranch::getMatcher() const {
        return matcher;
    }

    const AbstractTypedConstraint* TypedWhenBranch::getConstraint() const {
        return constraint;
    }

}
