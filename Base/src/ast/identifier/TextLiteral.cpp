//
// Created by roei on 27/10/18.
//

#include "TextLiteral.h"
#include "../AbstractNodeVisitor.h"
#include "CompositeIdentifier.h"

namespace enki {
    TextLiteral::TextLiteral(const std::string &str) : str(str) {}

    const std::string TextLiteral::nodeName() const {
        return "TextLiteral";
    }

    const std::string TextLiteral::to_string() const {
        return "\"" + str + "\"";
    }

    void TextLiteral::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const std::string TextLiteral::value() const {
        return str;
    }

    bool TextLiteral::canUnify(const CompositeIdentifier* other) const {
        return other->tryUnify(this);
    }

    bool TextLiteral::canUnify(const IntegerLiteral* other) const {
        return false;
    }

    bool TextLiteral::canUnify(const SymbolIdentifier* other) const {
        return false;
    }

    bool TextLiteral::canUnify(const TextLiteral* other) const {
        return value() == other->value();
    }

    bool TextLiteral::canUnify(const VarIdentifier* other) const {
        return true;
    }

    bool TextLiteral::canUnify(const WordIdentifier* other) const {
        return false;
    }
}
