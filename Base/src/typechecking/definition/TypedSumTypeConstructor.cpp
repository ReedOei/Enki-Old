//
// Created by roei on 17/01/19.
//

#include "TypedSumTypeConstructor.h"

namespace enki {
    TypedSumTypeConstructor::TypedSumTypeConstructor(const AbstractIdentifier* identifier,
                                                     const std::vector<const TypedVarExpr*> &parameters,
                                                     const std::vector<const TypedTypeConstructor*> &constructors)
            : identifier(identifier), parameters(parameters), constructors(constructors) {}

    TypedSumTypeConstructor::~TypedSumTypeConstructor() = default;

    const AbstractIdentifier* TypedSumTypeConstructor::getIdentifier() const {
        return identifier;
    }

    const std::vector<const TypedVarExpr*> &TypedSumTypeConstructor::getParameters() const {
        return parameters;
    }

    const std::vector<const TypedTypeConstructor*> &TypedSumTypeConstructor::getConstructors() const {
        return constructors;
    }

}
