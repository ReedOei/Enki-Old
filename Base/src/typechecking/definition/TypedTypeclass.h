//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDTYPECLASS_H
#define BASE_TYPEDTYPECLASS_H

#include "AbstractTypedDefinition.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "TypedProperty.h"

namespace enki {
    class TypedTypeclass : public AbstractTypedDefinition {
    public:
        TypedTypeclass(const AbstractIdentifier* implementedTypeIdentifier, const AbstractIdentifier* identifier,
                       const std::vector<const TypedProperty*> &properties);
        ~TypedTypeclass() override;

        const AbstractIdentifier* getImplementedTypeIdentifier() const;
        const AbstractIdentifier* getIdentifier() const;
        const std::vector<const TypedProperty*> &getProperties() const;

    private:
        const AbstractIdentifier* implementedTypeIdentifier;
        const AbstractIdentifier* identifier;

        const std::vector<const TypedProperty*> properties;
    };
}

#endif //BASE_TYPEDTYPECLASS_H
