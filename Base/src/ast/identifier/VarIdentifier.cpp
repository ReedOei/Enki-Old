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

    bool VarIdentifier::canUnify(const CompositeIdentifier* other) const {
        return true;
    }

    bool VarIdentifier::canUnify(const IntegerLiteral* other) const {
        return true;
    }

    bool VarIdentifier::canUnify(const SymbolIdentifier* other) const {
        return true;
    }

    bool VarIdentifier::canUnify(const TextLiteral* other) const {
        return true;
    }

    bool VarIdentifier::canUnify(const VarIdentifier* other) const {
        return true;
    }

    bool VarIdentifier::canUnify(const WordIdentifier* other) const {
        return true;
    }

    const std::string VarIdentifier::value() const {
        return varName;
    }
}
