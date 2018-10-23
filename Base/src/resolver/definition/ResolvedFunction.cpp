//
// Created by roei on 20/10/18.
//

#include "ResolvedFunction.h"

namespace enki {
    ResolvedFunction::ResolvedFunction(const std::shared_ptr<AbstractIdentifier> &identifier,
                                       const std::optional<std::shared_ptr<AbstractResolvedConstraint>> &constraints,
                                       const std::shared_ptr<AbstractResolvedVal> &returnValue,
                                       const std::vector<std::shared_ptr<ResolvedVarExpr>> &parameters)
                                       : identifier(identifier),
                                         constraints(constraints),
                                         returnValue(returnValue),
                                         parameters(parameters) {}

    const std::string enki::ResolvedFunction::nodeName() const {
        return "ResolvedFunction";
    }

    void ResolvedFunction::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        if (constraints.has_value()) {
            constraints.value()->accept(visitor);
        }

        returnValue->accept(visitor);

        for (const auto &param : parameters) {
            param->accept(visitor);
        }
    }
}
