//
// Created by roei on 18/10/18.
//

#include "SymbolIdentifier.h"
#include "../AbstractNodeVisitor.h"
#include "CompositeIdentifier.h"

namespace enki {
    enki::SymbolIdentifier::SymbolIdentifier(const std::string &symbol) : symbol(symbol) {}

    const std::string enki::SymbolIdentifier::nodeName() const {
        return "SymbolIdentifier";
    }

    const std::string enki::SymbolIdentifier::to_string() const {
        return symbol;
    }

    void enki::SymbolIdentifier::accept(enki::AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const std::string &SymbolIdentifier::value() const {
        return symbol;
    }

    bool SymbolIdentifier::canUnify(const CompositeIdentifier* other) const {
        return other->tryUnify(this);
    }

    bool SymbolIdentifier::canUnify(const IntegerLiteral* other) const {
        return false;
    }

    bool SymbolIdentifier::canUnify(const SymbolIdentifier* other) const {
        return other->value() == value();
    }

    bool SymbolIdentifier::canUnify(const TextLiteral* other) const {
        return false;
    }

    bool SymbolIdentifier::canUnify(const VarIdentifier* other) const {
        return true;
    }

    bool SymbolIdentifier::canUnify(const WordIdentifier* other) const {
        return false;
    }
}
