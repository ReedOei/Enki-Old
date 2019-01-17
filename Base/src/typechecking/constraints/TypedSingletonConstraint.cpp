//
// Created by roei on 17/01/19.
//

#include "TypedSingletonConstraint.h"

namespace enki {
    TypedSingletonConstraint::TypedSingletonConstraint(const TypedRuleExpr* rule) : rule(rule) {}

    TypedSingletonConstraint::~TypedSingletonConstraint() = default;

    const TypedRuleExpr* TypedSingletonConstraint::getRule() const {
        return rule;
    }
}
