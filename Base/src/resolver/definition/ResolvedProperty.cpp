//
// Created by roei on 22/10/18.
//

#include "ResolvedProperty.h"

namespace enki {
    ResolvedProperty::ResolvedProperty(const AbstractIdentifier* identifier,
                                       const std::vector<const ResolvedVarExpr*> &parameters,
                                       const AbstractResolvedType* type) : identifier(identifier),
                                                                           parameters(parameters), type(type) {}

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

    const AbstractIdentifier* ResolvedProperty::getIdentifier() const {
        return identifier;
    }

    const std::vector<const ResolvedVarExpr*> &ResolvedProperty::getParameters() const {
        return parameters;
    }

    const AbstractResolvedType* ResolvedProperty::getType() const {
        return type;
    }

    ResolvedProperty::~ResolvedProperty() {

    }
}
