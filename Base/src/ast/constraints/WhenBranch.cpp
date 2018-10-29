//
// Created by roei on 18/10/18.
//

#include "WhenBranch.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    WhenBranch::WhenBranch(const AbstractConstraint* matcher, const AbstractConstraint* constraint)
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

    const AbstractConstraint* WhenBranch::getMatcher() const {
        return matcher;
    }

    const AbstractConstraint* WhenBranch::getConstraint() const {
        return constraint;
    }

    WhenBranch::~WhenBranch() = default;
}
