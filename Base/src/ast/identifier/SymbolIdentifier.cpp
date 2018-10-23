//
// Created by roei on 18/10/18.
//

#include "SymbolIdentifier.h"
#include "../AbstractNodeVisitor.h"

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
}
