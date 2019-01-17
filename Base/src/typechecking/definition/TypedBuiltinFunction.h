//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDBUILTINFUNCTION_H
#define BASE_TYPEDBUILTINFUNCTION_H

#include "TypedFunction.h"

namespace enki {
    class TypedBuiltinFunction : public TypedFunction {
    public:
        explicit TypedBuiltinFunction(const AbstractIdentifier* identifier);
        ~TypedBuiltinFunction() override;
    };
}

#endif //BASE_TYPEDBUILTINFUNCTION_H
