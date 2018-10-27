//
// Created by roei on 27/10/18.
//

#include "TextLiteral.h"
#include "../AbstractNodeVisitor.h"

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
}
