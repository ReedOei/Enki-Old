//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDSINGLETONCONSTRAINT_H
#define BASE_TYPEDSINGLETONCONSTRAINT_H

#include "AbstractTypedConstraint.h"
#include "../expression/TypedRuleExpr.h"

namespace enki {
    class TypedSingletonConstraint : public AbstractTypedConstraint {
    public:
        explicit TypedSingletonConstraint(const TypedRuleExpr* rule);
        ~TypedSingletonConstraint() override;

        const TypedRuleExpr* getRule() const;

    private:
        const TypedRuleExpr* rule;
    };
}


#endif //BASE_TYPEDSINGLETONCONSTRAINT_H
