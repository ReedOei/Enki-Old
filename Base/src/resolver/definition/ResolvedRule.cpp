//
// Created by roei on 20/10/18.
//

#include "ResolvedRule.h"

namespace enki {
    ResolvedRule::ResolvedRule(const AbstractIdentifier* identifier, const AbstractResolvedConstraint* constraints,
                               const std::vector<const ResolvedVarExpr*> &parameters) : identifier(identifier),
                                                                                        constraints(constraints),
                                                                                        parameters(parameters) {}

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

    const AbstractIdentifier* ResolvedRule::getIdentifier() const {
        return identifier;
    }

    const AbstractResolvedConstraint* ResolvedRule::getConstraints() const {
        return constraints;
    }

    const std::vector<const ResolvedVarExpr*> &ResolvedRule::getParameters() const {
        return parameters;
    }

    ResolvedRule::~ResolvedRule() {

    }
}
