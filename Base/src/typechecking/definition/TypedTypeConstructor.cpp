//
// Created by roei on 17/01/19.
//

#include "TypedTypeConstructor.h"

namespace enki {
    TypedTypeConstructor::TypedTypeConstructor(const AbstractIdentifier* identifier,
                                               const std::vector<const TypedVarExpr*> &parameters,
                                               const std::vector<const TypedProperty*> &fields) : identifier(
            identifier), parameters(parameters), fields(fields) {}

    TypedTypeConstructor::~TypedTypeConstructor() = default;

    const AbstractIdentifier* TypedTypeConstructor::getIdentifier() const {
        return identifier;
    }

    const std::vector<const TypedVarExpr*> &TypedTypeConstructor::getParameters() const {
        return parameters;
    }

    const std::vector<const TypedProperty*> &TypedTypeConstructor::getFields() const {
        return fields;
    }
}
