//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDRULE_H
#define BASE_TYPEDRULE_H

#include "AbstractTypedDefinition.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../constraints/AbstractTypedConstraint.h"
#include "../expression/TypedVarExpr.h"

namespace enki {
    class TypedRule : public AbstractTypedDefinition {
    public:
        TypedRule(const AbstractIdentifier* identifier, const AbstractTypedConstraint* constraint,
                  const std::vector<const TypedVarExpr*> &parameters);
        ~TypedRule() override;

        const AbstractIdentifier* getIdentifier() const;
        const AbstractTypedConstraint* getConstraint() const;
        const std::vector<const TypedVarExpr*> &getParameters() const;

    private:
        const AbstractIdentifier* identifier;
        const AbstractTypedConstraint* constraint;
        const std::vector<const TypedVarExpr*> parameters;
    };
}

#endif //BASE_TYPEDRULE_H
