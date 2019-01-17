//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDSUMTYPECONSTRUCTOR_H
#define BASE_TYPEDSUMTYPECONSTRUCTOR_H

#include "../expression/TypedVarExpr.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "TypedTypeConstructor.h"
#include "AbstractTypedDefinition.h"

namespace enki {
    class TypedSumTypeConstructor : public AbstractTypedDefinition {
    public:
        TypedSumTypeConstructor(const AbstractIdentifier* identifier,
                                const std::vector<const TypedVarExpr*> &parameters,
                                const std::vector<const TypedTypeConstructor*> &constructors);
        ~TypedSumTypeConstructor() override;

        const AbstractIdentifier* getIdentifier() const;
        const std::vector<const TypedVarExpr*> &getParameters() const;
        const std::vector<const TypedTypeConstructor*> &getConstructors() const;

    private:
        const AbstractIdentifier* identifier;
        const std::vector<const TypedVarExpr*> parameters;

        const std::vector<const TypedTypeConstructor*> constructors;
    };
}

#endif //BASE_TYPEDSUMTYPECONSTRUCTOR_H
