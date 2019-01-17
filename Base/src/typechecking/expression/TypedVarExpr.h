//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDVAREXPR_H
#define BASE_TYPEDVAREXPR_H

#include "AbstractTypedVal.h"
#include "../definition/AbstractTypedDefinition.h"

namespace enki {
    class TypedVarExpr : public AbstractTypedVal {
    public:
        TypedVarExpr(const std::string &name, const AbstractTypedDefinition* binder, const int binderPosition);

        virtual ~TypedVarExpr();

        const std::string &getName() const;
        const AbstractTypedDefinition* getBinder() const;
        const int getBinderPosition() const;

    private:
        const std::string name;
        const AbstractTypedDefinition* binder;
        const int binderPosition;
    };
}

#endif //BASE_TYPEDVAREXPR_H
