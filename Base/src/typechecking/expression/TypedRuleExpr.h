//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDRULEEXPR_H
#define BASE_TYPEDRULEEXPR_H

#include "AbstractTypedExpr.h"
#include "AbstractTypedVal.h"
#include "../definition/TypedRule.h"

namespace enki {
    class TypedRuleExpr : public AbstractTypedExpr {
    public:
        TypedRuleExpr(const TypedRule* rule, const std::vector<const AbstractTypedVal*> &values);
        ~TypedRuleExpr() override;

        const TypedRule* getRule() const;
        const std::vector<const AbstractTypedVal*> &getValues() const;

    private:
        const TypedRule* rule;
        const std::vector<const AbstractTypedVal*> values;
    };
}

#endif //BASE_TYPEDRULEEXPR_H
