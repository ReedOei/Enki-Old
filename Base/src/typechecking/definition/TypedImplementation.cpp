//
// Created by roei on 17/01/19.
//

#include "TypedImplementation.h"

namespace enki {
    TypedImplementation::TypedImplementation(const AbstractResolvedType* type, const TypedTypeclass* typeclass,
                                             const std::vector<const AbstractTypedDefinition*> &definitions)
            : type(type), typeclass(typeclass), definitions(definitions) {}

    TypedImplementation::~TypedImplementation() = default;

    const AbstractResolvedType* TypedImplementation::getType() const {
        return type;
    }

    const TypedTypeclass* TypedImplementation::getTypeclass() const {
        return typeclass;
    }

    const std::vector<const AbstractTypedDefinition*> &TypedImplementation::getDefinitions() const {
        return definitions;
    }
}
