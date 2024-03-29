//
// Created by roei on 18/10/18.
//

#include "SingletonConstraint.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    SingletonConstraint::SingletonConstraint(const AbstractIdentifier* &identifier) : identifier(identifier) {}

    const std::string SingletonConstraint::nodeName() const {
        return "SingletonConstraint";
    }

    void SingletonConstraint::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        identifier->accept(visitor);
    }

    const std::string SingletonConstraint::to_string() const {
        return identifier->to_string();
    }

    const AbstractIdentifier* SingletonConstraint::getIdentifier() const {
        return identifier;
    }

    SingletonConstraint::~SingletonConstraint() = default;
}
