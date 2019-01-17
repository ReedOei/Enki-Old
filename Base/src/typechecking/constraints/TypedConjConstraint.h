//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDCONJCONSTRAINT_H
#define BASE_TYPEDCONJCONSTRAINT_H

#include "AbstractTypedConstraint.h"

namespace enki {
    class TypedConjConstraint : public AbstractTypedConstraint {
    public:
        explicit TypedConjConstraint(const std::vector<const AbstractTypedConstraint*> &constraints);
        ~TypedConjConstraint() override;

        const std::vector<const AbstractTypedConstraint*> &getConstraints() const;

    private:
        const std::vector<const AbstractTypedConstraint*> constraints;
    };
}

#endif //BASE_TYPEDCONJCONSTRAINT_H
