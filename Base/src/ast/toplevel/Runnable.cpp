//
// Created by roei on 18/10/18.
//

#include "Runnable.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    Runnable::Runnable(const std::shared_ptr<AbstractConstraint> &constraint) : constraint(constraint) {}

    const std::string Runnable::nodeName() const {
        return "Runnable";
    }

    const std::string Runnable::to_string() const {
        return constraint->to_string();
    }

    void Runnable::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
        constraint->accept(visitor);
    }
}
