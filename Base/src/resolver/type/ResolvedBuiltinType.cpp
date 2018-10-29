//
// Created by roei on 22/10/18.
//

#include "ResolvedBuiltinType.h"

namespace enki {
    ResolvedBuiltinType::ResolvedBuiltinType(const std::string &name) : name(name) {}

    const std::string ResolvedBuiltinType::nodeName() const {
        return "ResolvedBuiltinType";
    }

    const std::string ResolvedBuiltinType::typeName() const {
        return name;
    }

    void ResolvedBuiltinType::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    ResolvedBuiltinType::~ResolvedBuiltinType() {

    }
}
