//
// Created by roei on 17/01/19.
//

#include "TypedTypeclass.h"

namespace enki {
    TypedTypeclass::TypedTypeclass(const AbstractIdentifier* implementedTypeIdentifier,
                                   const AbstractIdentifier* identifier,
                                   const std::vector<const TypedProperty*> &properties)
            : implementedTypeIdentifier(implementedTypeIdentifier), identifier(identifier), properties(properties) {}

    TypedTypeclass::~TypedTypeclass() = default;

    const AbstractIdentifier* TypedTypeclass::getImplementedTypeIdentifier() const {
        return implementedTypeIdentifier;
    }

    const AbstractIdentifier* TypedTypeclass::getIdentifier() const {
        return identifier;
    }

    const std::vector<const TypedProperty*> &TypedTypeclass::getProperties() const {
        return properties;
    }
}
