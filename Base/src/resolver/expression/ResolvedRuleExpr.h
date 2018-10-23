//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDRULEEXPR_H
#define BASE_RESOLVEDRULEEXPR_H

#include "AbstractResolvedExpr.h"
#include "../definition/ResolvedRule.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedRuleExpr : public AbstractResolvedExpr {
    public:
        ResolvedRuleExpr(const std::shared_ptr<ResolvedRule> &rule,
                         const std::vector<std::shared_ptr<AbstractResolvedVal>> &values);

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<ResolvedRule> rule;
        const std::vector<std::shared_ptr<AbstractResolvedVal>> values;
    };
}


#endif //BASE_RESOLVEDRULEEXPR_H
