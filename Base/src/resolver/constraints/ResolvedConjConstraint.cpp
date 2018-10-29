//
// Created by roei on 20/10/18.
//

#include "ResolvedConjConstraint.h"

namespace enki {
    ResolvedConjConstraint::ResolvedConjConstraint(
            const std::vector<const AbstractResolvedConstraint*> &constraints) : constraints(constraints) {}

    const std::string ResolvedConjConstraint::nodeName() const {
        return "ResolvedConjConstraint";
    }

    void ResolvedConjConstraint::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &constraint : constraints) {
            constraint->accept(visitor);
        }
    }

    const std::vector<const AbstractResolvedConstraint*> &ResolvedConjConstraint::getConstraints() const {
        return constraints;
    }

    ResolvedConjConstraint::~ResolvedConjConstraint() {

    }
}
