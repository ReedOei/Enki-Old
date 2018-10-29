//
// Created by roei on 17/10/18.
//

#include "FuncType.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    FuncType::FuncType(const AbstractType* inType, const AbstractType* outType)
            : inType(inType), outType(outType) {}

    const std::string FuncType::nodeName() const {
        return "FuncType";
    }

    const std::string FuncType::to_string() const {
        return inType->to_string() + " -> " + outType->to_string();
    }

    void FuncType::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        inType->accept(visitor);
        outType->accept(visitor);
    }

    const AbstractType* FuncType::getInType() const {
        return inType;
    }

    const AbstractType* FuncType::getOutType() const {
        return outType;
    }

    FuncType::~FuncType() {

    }
}
