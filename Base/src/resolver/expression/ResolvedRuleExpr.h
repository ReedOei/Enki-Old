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
        virtual ~ResolvedRuleExpr();

        ResolvedRuleExpr(const ResolvedRule* rule, std::vector<const AbstractResolvedVal*> values);

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const ResolvedRule* getRule() const;
        const std::vector<const AbstractResolvedVal*> &getValues() const;

    private:
        const ResolvedRule* rule;
        const std::vector<const AbstractResolvedVal*> values;
    };
}


#endif //BASE_RESOLVEDRULEEXPR_H
