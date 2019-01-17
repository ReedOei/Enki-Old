//
// Created by roei on 17/01/19.
//

#include "TypedFuncExpr.h"

namespace enki {
    TypedFuncExpr::TypedFuncExpr(const TypedFunction* function,
                                 const std::vector<const AbstractTypedVal*> &values)
                                 : function(function), values(values) {}

    TypedFuncExpr::~TypedFuncExpr() = default;

    const TypedFunction* TypedFuncExpr::getFunction() const {
        return function;
    }

    const std::vector<const AbstractTypedVal*> &TypedFuncExpr::getValues() const {
        return values;
    }
}
