//
// Created by roei on 20/10/18.
//

#include "ResolvedSingletonConstraint.h"

namespace enki {
    ResolvedSingletonConstraint::ResolvedSingletonConstraint(const std::shared_ptr<ResolvedRuleExpr> &rule) : rule(
            rule) {}

    const std::string ResolvedSingletonConstraint::nodeName() const {
        return "ResolvedSingletonConstraint";
    }

    void ResolvedSingletonConstraint::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        rule->accept(visitor);
    }
}
