//
// Created by roei on 18/10/18.
//

#include "WhenBranch.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    WhenBranch::WhenBranch(const std::shared_ptr<AbstractConstraint> &matcher,
                           const std::shared_ptr<AbstractConstraint> &constraint)
                           : matcher(matcher), constraint(constraint) {}

    const std::string WhenBranch::nodeName() const {
        return "WhenBranch";
    }

    void WhenBranch::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        matcher->accept(visitor);
        constraint->accept(visitor);
    }

    const std::string WhenBranch::to_string() const {
        return "when " + matcher->to_string() + " then: " + constraint->to_string();
    }
}
