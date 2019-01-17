//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDIMPLEMENTATION_H
#define BASE_TYPEDIMPLEMENTATION_H

#include "AbstractTypedDefinition.h"
#include "TypedTypeclass.h"

namespace enki {
    class TypedImplementation : public AbstractTypedDefinition {
    public:
        TypedImplementation(const AbstractResolvedType* type, const TypedTypeclass* typeclass,
                            const std::vector<const AbstractTypedDefinition*> &definitions);
        ~TypedImplementation() override;

        const AbstractResolvedType* getType() const;
        const TypedTypeclass* getTypeclass() const;
        const std::vector<const AbstractTypedDefinition*> &getDefinitions() const;

    private:
        const AbstractResolvedType* type;
        const TypedTypeclass* typeclass;

        const std::vector<const AbstractTypedDefinition*> definitions;
    };
}

#endif //BASE_TYPEDIMPLEMENTATION_H
