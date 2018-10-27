//
// Created by roei on 18/10/18.
//

#include "IntegerLiteral.h"
#include "../AbstractNodeVisitor.h"
#include "CompositeIdentifier.h"

namespace enki {
    IntegerLiteral::IntegerLiteral(int val) : val(val) {}

    const std::string IntegerLiteral::nodeName() const {
        return "IntegerLiteral";
    }

    const std::string IntegerLiteral::to_string() const {
        return std::to_string(val);
    }

    void IntegerLiteral::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const int IntegerLiteral::value() const {
        return val;
    }

    bool IntegerLiteral::canUnify(const CompositeIdentifier* other) const {
        return other->tryUnify(this);
    }

    bool IntegerLiteral::canUnify(const IntegerLiteral* other) const {
        return other->value() == value();
    }

    bool IntegerLiteral::canUnify(const SymbolIdentifier* other) const {
        return false;
    }

    bool IntegerLiteral::canUnify(const TextLiteral* other) const {
        return false;
    }

    bool IntegerLiteral::canUnify(const VarIdentifier* other) const {
        return true;
    }

    bool IntegerLiteral::canUnify(const WordIdentifier* other) const {
        return false;
    }
}
