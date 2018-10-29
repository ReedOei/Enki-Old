//
// Created by roei on 20/10/18.
//

#include "ResolvedWhenBranch.h"

namespace enki {
    ResolvedWhenBranch::ResolvedWhenBranch(const AbstractResolvedConstraint* matcher,
                                           const AbstractResolvedConstraint* constraint)
            : matcher(matcher), constraint(constraint) {}

    const std::string ResolvedWhenBranch::nodeName() const {
        return "ResolvedWhenBranch";
    }

    void ResolvedWhenBranch::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        matcher->accept(visitor);
        constraint->accept(visitor);
    }

    const AbstractResolvedConstraint* ResolvedWhenBranch::getMatcher() const {
        return matcher;
    }

    const AbstractResolvedConstraint* ResolvedWhenBranch::getConstraint() const {
        return constraint;
    }

    ResolvedWhenBranch::~ResolvedWhenBranch() {

    }
}
