//
// Created by roei on 18/10/18.
//

#include "SymbolIdentifier.h"
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

    const std::vector<const VarIdentifier*> SymbolIdentifier::variables() const {
        return std::vector<const VarIdentifier*>();
    }

    UnificationResult SymbolIdentifier::unify(const CompositeIdentifier* other) const {
        return CompositeIdentifier(std::vector<const AbstractIdentifier*>{this}).tryUnify(other);
    }

    UnificationResult SymbolIdentifier::unify(const IntegerLiteral* other) const {
        return UnificationResult();
    }

    UnificationResult SymbolIdentifier::unify(const SymbolIdentifier* other) const {
        return value() == other->value() ? UnificationResult(this, other) : UnificationResult();
    }

    UnificationResult SymbolIdentifier::unify(const TextLiteral* other) const {
        return UnificationResult();
    }

    UnificationResult SymbolIdentifier::unify(const VarIdentifier* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult SymbolIdentifier::unify(const WordIdentifier* other) const {
        return UnificationResult();
    }

    SymbolIdentifier::~SymbolIdentifier() {

    }
}
