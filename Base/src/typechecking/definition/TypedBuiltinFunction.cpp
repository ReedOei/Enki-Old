//
// Created by roei on 17/01/19.
//

#include "TypedBuiltinFunction.h"

namespace enki {
    TypedBuiltinFunction::TypedBuiltinFunction(const AbstractIdentifier* identifier) : TypedFunction(identifier) {}

    TypedBuiltinFunction::~TypedBuiltinFunction() = default;
}
