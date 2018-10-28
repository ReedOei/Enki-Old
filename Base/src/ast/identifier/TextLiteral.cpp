//
// Created by roei on 27/10/18.
//

#include "TextLiteral.h"
#include "../AbstractNodeVisitor.h"
#include "CompositeIdentifier.h"
#include "VarIdentifier.h"
#include "CompositeIdentifier.h"
#include "IntegerLiteral.h"
#include "SymbolIdentifier.h"
#include "TextLiteral.h"
#include "WordIdentifier.h"
#include "VarIdentifier.h"

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

    const std::vector<VarIdentifier*> TextLiteral::variables() const {
        return std::vector<VarIdentifier*>();
    }

    UnificationResult TextLiteral::unify(const CompositeIdentifier* other) const {
        return UnificationResult();
    }

    UnificationResult TextLiteral::unify(const IntegerLiteral* other) const {
        return UnificationResult();
    }

    UnificationResult TextLiteral::unify(const SymbolIdentifier* other) const {
        return UnificationResult();
    }

    UnificationResult TextLiteral::unify(const TextLiteral* other) const {
        return value() == other->value() ? UnificationResult(this, other) : UnificationResult();
    }

    UnificationResult TextLiteral::unify(const VarIdentifier* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult TextLiteral::unify(const WordIdentifier* other) const {
        return UnificationResult();
    }
}
