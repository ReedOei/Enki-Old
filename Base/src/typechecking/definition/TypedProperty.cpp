//
// Created by roei on 17/01/19.
//

#include "TypedProperty.h"

namespace enki {
    TypedProperty::TypedProperty(const AbstractIdentifier* identifier,
                                 const std::vector<const TypedVarExpr*> &parameters,
                                 const AbstractResolvedType* type)
                                 : identifier(identifier), parameters(parameters), type(type) {}

    TypedProperty::~TypedProperty() = default;

    const AbstractIdentifier* TypedProperty::getIdentifier() const {
        return identifier;
    }

    const std::vector<const TypedVarExpr*> &TypedProperty::getParameters() const {
        return parameters;
    }

    const AbstractResolvedType* TypedProperty::getType() const {
        return type;
    }
}
