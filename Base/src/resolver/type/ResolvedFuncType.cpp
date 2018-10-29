//
// Created by roei on 20/10/18.
//

#include "ResolvedFuncType.h"

namespace enki {
    ResolvedFuncType::ResolvedFuncType(const AbstractResolvedType* inType, const AbstractResolvedType* outType)
        : inType(inType), outType(outType) {}

    const std::string ResolvedFuncType::nodeName() const {
        return "ResolvedFuncType";
    }

    const std::string ResolvedFuncType::typeName() const {
        return inType->typeName() + " -> " + outType->typeName();
    }

    void ResolvedFuncType::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        inType->accept(visitor);
        outType->accept(visitor);
    }

    const AbstractResolvedType* ResolvedFuncType::getInType() const {
        return inType;
    }

    const AbstractResolvedType* ResolvedFuncType::getOutType() const {
        return outType;
    }

    ResolvedFuncType::~ResolvedFuncType() {

    }
}
