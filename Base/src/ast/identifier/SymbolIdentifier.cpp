//
// Created by roei on 18/10/18.
//

#include "SymbolIdentifier.h"

enki::SymbolIdentifier::SymbolIdentifier(const std::string &symbol) : symbol(symbol) {}

const std::string enki::SymbolIdentifier::nodeName() const {
    return "SymbolIdentifier";
}
