//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDFUNCEXPR_H
#define BASE_TYPEDFUNCEXPR_H

#include "AbstractTypedVal.h"
#include "../definition/TypedFunction.h"

namespace enki {
    class TypedFuncExpr : public AbstractTypedVal {
    public:
        TypedFuncExpr(const TypedFunction* function, const std::vector<const AbstractTypedVal*> &values);
        ~TypedFuncExpr() override;

        const TypedFunction* getFunction() const;

        const std::vector<const AbstractTypedVal*> &getValues() const;

    private:
        const TypedFunction* function;
        const std::vector<const AbstractTypedVal*> values;
    };
}

#endif //BASE_TYPEDFUNCEXPR_H
