//
// Created by roei on 17/01/19.
//

#include "TypedWhenBranches.h"

namespace enki {
    TypedWhenBranches::TypedWhenBranches(const std::vector<const TypedWhenBranch*> &branches,
                                         const std::optional<const AbstractTypedConstraint*> &otherwise)
                                         : branches(branches), otherwise(otherwise) {}

    TypedWhenBranches::~TypedWhenBranches() = default;

    const std::vector<const TypedWhenBranch*> &TypedWhenBranches::getBranches() const {
        return branches;
    }

    const std::optional<const AbstractTypedConstraint*> &TypedWhenBranches::getOtherwise() const {
        return otherwise;
    }
}
