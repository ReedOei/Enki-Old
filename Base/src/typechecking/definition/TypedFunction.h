//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDFUNCTION_H
#define BASE_TYPEDFUNCTION_H

#include "AbstractTypedDefinition.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../expression/AbstractTypedVal.h"
#include "../constraints/AbstractTypedConstraint.h"
#include "../expression/TypedVarExpr.h"

namespace enki {
    class TypedFunction : public AbstractTypedDefinition {
    public:
        TypedFunction(const AbstractIdentifier* identifier,
                      const std::optional<const AbstractTypedConstraint*> &constraints,
                      const AbstractTypedVal* returnVal, const std::vector<const TypedVarExpr*> &parameters);
        ~TypedFunction() override;

        const AbstractIdentifier* getIdentifier() const;
        const std::optional<const AbstractTypedConstraint*> &getConstraints() const;
        const AbstractTypedVal* getReturnVal() const;
        const std::vector<const TypedVarExpr*> &getParameters() const;

    protected:
        explicit TypedFunction(const AbstractIdentifier* identifier);

    private:
        const AbstractIdentifier* identifier;

        std::optional<const AbstractTypedConstraint*> constraints;
        const AbstractTypedVal* returnVal;

        std::vector<const TypedVarExpr*> parameters;
    };
}

#endif //BASE_TYPEDFUNCTION_H
