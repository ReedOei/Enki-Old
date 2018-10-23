//
// Created by roei on 22/10/18.
//

#include "ResolvedRuleExpr.h"

namespace enki {
    ResolvedRuleExpr::ResolvedRuleExpr(const std::shared_ptr<ResolvedRule> &rule,
                                       const std::vector<std::shared_ptr<AbstractResolvedVal>> &values) : rule(
            rule), values(values) {}

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
}
