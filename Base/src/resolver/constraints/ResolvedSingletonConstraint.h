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
        explicit ResolvedSingletonConstraint(const std::shared_ptr<ResolvedRuleExpr> &rule);

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<ResolvedRuleExpr> rule;
    };
}

#endif //BASE_RESOLVEDSINGLETONCONSTRAINT_H
