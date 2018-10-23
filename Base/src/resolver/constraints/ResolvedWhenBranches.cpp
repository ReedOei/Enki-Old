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

    void ResolvedWhenBranches::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &branch : branches) {
            branch->accept(visitor);
        }

        if (otherwise.has_value()) {
            otherwise.value()->accept(visitor);
        }
    }
}
