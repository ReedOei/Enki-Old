//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDPROPERTY_H
#define BASE_TYPEDPROPERTY_H

#include "AbstractTypedDefinition.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../expression/TypedVarExpr.h"

namespace enki {
    class TypedProperty : public AbstractTypedDefinition {
    public:
        TypedProperty(const AbstractIdentifier* identifier, const std::vector<const TypedVarExpr*> &parameters,
                      const AbstractResolvedType* type);
        ~TypedProperty() override;

        const AbstractIdentifier* getIdentifier() const;
        const std::vector<const TypedVarExpr*> &getParameters() const;
        const AbstractResolvedType* getType() const;

    private:
        const AbstractIdentifier* identifier;

        const std::vector<const TypedVarExpr*> parameters;
        const AbstractResolvedType* type;
    };
}

#endif //BASE_TYPEDPROPERTY_H
