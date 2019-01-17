//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDSINGLETONCONSTRAINT_H
#define BASE_RESOLVEDSINGLETONCONSTRAINT_H

#include <memory>
#include <vector>
#include "AbstractResolvedConstraint.h"
#include "../expression/ResolvedRuleExpr.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedSingletonConstraint : public AbstractResolvedConstraint {
    public:
        explicit ResolvedSingletonConstraint(const ResolvedRuleExpr* rule);
        ~ResolvedSingletonConstraint() override;

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const ResolvedRuleExpr* getRule() const;

    private:
        const ResolvedRuleExpr* rule;
    };
}

#endif //BASE_RESOLVEDSINGLETONCONSTRAINT_H
