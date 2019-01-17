//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDTYPECONSTRUCTOR_H
#define BASE_TYPEDTYPECONSTRUCTOR_H

#include "AbstractTypedDefinition.h"
#include "TypedProperty.h"

namespace enki {
    class TypedTypeConstructor : public AbstractTypedDefinition {
    public:
        TypedTypeConstructor(const AbstractIdentifier* identifier, const std::vector<const TypedVarExpr*> &parameters,
                             const std::vector<const TypedProperty*> &fields);
        ~TypedTypeConstructor() override;

        const AbstractIdentifier* getIdentifier() const;
        const std::vector<const TypedVarExpr*> &getParameters() const;
        const std::vector<const TypedProperty*> &getFields() const;

    private:
        const AbstractIdentifier* identifier;
        const std::vector<const TypedVarExpr*> parameters;
        const std::vector<const TypedProperty*> fields;
    };
}

#endif //BASE_TYPEDTYPECONSTRUCTOR_H
