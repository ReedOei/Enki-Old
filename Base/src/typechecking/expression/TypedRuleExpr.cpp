//
// Created by roei on 17/01/19.
//

#include "TypedRuleExpr.h"

namespace enki {
    TypedRuleExpr::TypedRuleExpr(const TypedRule* rule,
                                 const std::vector<const AbstractTypedVal*> &values)
                                 : rule(rule), values(values) {}

    TypedRuleExpr::~TypedRuleExpr() = default;

    const TypedRule* TypedRuleExpr::getRule() const {
        return rule;
    }

    const std::vector<const AbstractTypedVal*> &TypedRuleExpr::getValues() const {
        return values;
    }
}
