//
// Created by roei on 22/10/18.
//

#include "ResolvedProperty.h"

namespace enki {
    ResolvedProperty::ResolvedProperty(const std::shared_ptr<AbstractIdentifier> &identifier,
                                       const std::vector<std::shared_ptr<ResolvedVarExpr>> &parameters,
                                       const std::shared_ptr<AbstractResolvedType> &type) : identifier(
            identifier), parameters(parameters), type(type) {}

    const std::string ResolvedProperty::nodeName() const {
        return "ResolvedPropery";
    }

    void ResolvedProperty::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &param : parameters) {
            param->accept(visitor);
        }

        type->accept(visitor);
    }
}
