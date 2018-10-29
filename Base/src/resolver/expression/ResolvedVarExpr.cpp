//
// Created by roei on 22/10/18.
//

#include "ResolvedVarExpr.h"

namespace enki {
    ResolvedVarExpr::ResolvedVarExpr(const std::string &varName, const AbstractResolvedDefinition* binder,
                                     const int binderPosition) : varName(varName), binder(binder),
                                                                 binderPosition(binderPosition) {}

    const std::string ResolvedVarExpr::nodeName() const {
        return "ResolvedVarExpr";
    }

    const std::string &ResolvedVarExpr::getVarName() const {
        return varName;
    }

    void ResolvedVarExpr::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        binder->accept(visitor);
    }

    const AbstractResolvedDefinition* ResolvedVarExpr::getBinder() const {
        return binder;
    }

    const int ResolvedVarExpr::getBinderPosition() const {
        return binderPosition;
    }

    ResolvedVarExpr::~ResolvedVarExpr() {

    }
}
