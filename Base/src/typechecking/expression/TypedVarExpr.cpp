//
// Created by roei on 17/01/19.
//

#include "TypedVarExpr.h"

namespace enki {
    TypedVarExpr::TypedVarExpr(const std::string &name, const AbstractTypedDefinition* binder, const int binderPosition)
    : name(name), binder(binder), binderPosition(binderPosition) {}

    TypedVarExpr::~TypedVarExpr() = default;

    const std::string &TypedVarExpr::getName() const {
        return name;
    }

    const AbstractTypedDefinition* TypedVarExpr::getBinder() const {
        return binder;
    }

    const int TypedVarExpr::getBinderPosition() const {
        return binderPosition;
    }
}
