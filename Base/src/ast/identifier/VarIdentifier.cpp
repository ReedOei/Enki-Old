//
// Created by roei on 18/10/18.
//

#include "VarIdentifier.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    VarIdentifier::VarIdentifier(const std::string &varName) : varName(varName) {}

    const std::string VarIdentifier::nodeName() const {
        return "VarIdentifier";
    }

    const std::string VarIdentifier::to_string() const {
        return varName;
    }

    void VarIdentifier::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }
}
