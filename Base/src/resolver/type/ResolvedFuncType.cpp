//
// Created by roei on 20/10/18.
//

#include "ResolvedFuncType.h"

namespace enki {
    ResolvedFuncType::ResolvedFuncType(const std::shared_ptr<AbstractResolvedType> &inType,
                                        const std::shared_ptr<AbstractResolvedType> &outType) : inType(inType),
                                                                                                outType(outType) {}

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
}
