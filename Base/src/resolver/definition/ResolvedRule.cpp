//
// Created by roei on 20/10/18.
//

#include "ResolvedRule.h"

namespace enki {
    ResolvedRule::ResolvedRule(const std::shared_ptr<AbstractIdentifier> &identifier,
                               const std::shared_ptr<AbstractResolvedConstraint> &constraints,
                               const std::vector<std::shared_ptr<ResolvedVarExpr>> &parameters)
                               : identifier(identifier), constraints(constraints), parameters(parameters) {}

    const std::string ResolvedRule::nodeName() const {
        return "ResolvedRule";
    }

    void ResolvedRule::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        constraints->accept(visitor);

        for (const auto &param : parameters) {
            param->accept(visitor);
        }
    }
}
