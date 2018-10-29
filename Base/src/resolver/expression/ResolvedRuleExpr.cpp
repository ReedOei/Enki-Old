#include <utility>

#include <utility>

//
// Created by roei on 22/10/18.
//

#include "ResolvedRuleExpr.h"

namespace enki {
    ResolvedRuleExpr::ResolvedRuleExpr(const ResolvedRule* rule, std::vector<const AbstractResolvedVal*> values)
        : rule(rule), values(std::move(values)) {}

    const std::string ResolvedRuleExpr::nodeName() const {
        return "ResolvedRuleExpr";
    }

    void ResolvedRuleExpr::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        rule->accept(visitor);

        for (const auto &val : values) {
            val->accept(visitor);
        }
    }

    const ResolvedRule* ResolvedRuleExpr::getRule() const {
        return rule;
    }

    const std::vector<const AbstractResolvedVal*> &ResolvedRuleExpr::getValues() const {
        return values;
    }

    ResolvedRuleExpr::~ResolvedRuleExpr() {

    }
}
