//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDWHENBRANCH_H
#define BASE_TYPEDWHENBRANCH_H

#include "AbstractTypedConstraint.h"

namespace enki {
    class TypedWhenBranch : public AbstractTypedConstraint {
    public:
        TypedWhenBranch(const AbstractTypedConstraint* matcher, const AbstractTypedConstraint* constraint);
        ~TypedWhenBranch() override;

        const AbstractTypedConstraint* getMatcher() const;
        const AbstractTypedConstraint* getConstraint() const;

    private:
        const AbstractTypedConstraint* matcher;
        const AbstractTypedConstraint* constraint;
    };
}

#endif //BASE_TYPEDWHENBRANCH_H
