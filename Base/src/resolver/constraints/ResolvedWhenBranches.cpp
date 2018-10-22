//
// Created by roei on 20/10/18.
//

#include "ResolvedWhenBranches.h"

namespace enki {
    ResolvedWhenBranches::ResolvedWhenBranches(const std::vector<std::shared_ptr<ResolvedWhenBranch>> &branches,
                                               const std::optional<std::shared_ptr<AbstractResolvedConstraint>> &otherwise)
            : branches(branches), otherwise(otherwise) {}

    const std::string ResolvedWhenBranches::nodeName() const {
        return "ResolvedWhenBranches";
    }
}
