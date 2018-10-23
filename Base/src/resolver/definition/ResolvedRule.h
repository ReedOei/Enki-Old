//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDRULE_H
#define BASE_RESOLVEDRULE_H

#include <memory>
#include <vector>
#include "AbstractResolvedDefinition.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../constraints/AbstractResolvedConstraint.h"
#include "../expression/ResolvedVarExpr.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedRule : public AbstractResolvedDefinition {
    public:
        ResolvedRule(const std::shared_ptr<AbstractIdentifier> &identifier,
                     const std::shared_ptr<AbstractResolvedConstraint> &constraints,
                     const std::vector<std::shared_ptr<ResolvedVarExpr>> &parameters);

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> identifier;
        const std::shared_ptr<AbstractResolvedConstraint> constraints;
        const std::vector<std::shared_ptr<ResolvedVarExpr>> parameters;
    };
}

#endif //BASE_RESOLVEDRULE_H
