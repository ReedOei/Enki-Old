//
// Created by roei on 20/10/18.
//

#include "ResolvedWhenBranch.h"

namespace enki {
    ResolvedWhenBranch::ResolvedWhenBranch(const std::shared_ptr<AbstractResolvedConstraint> &matcher,
                                           const std::shared_ptr<AbstractResolvedConstraint> &constraint)
            : matcher(matcher), constraint(constraint) {}

    const std::string ResolvedWhenBranch::nodeName() const {
        return "ResolvedWhenBranch";
    }

    void ResolvedWhenBranch::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        matcher->accept(visitor);
        constraint->accept(visitor);
    }
}
