//
// Created by roei on 18/10/18.
//

#include "WordIdentifier.h"
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
    WordIdentifier::WordIdentifier(const std::string &word) : word(word) {}

    const std::string WordIdentifier::nodeName() const {
        return "WordIdentifier";
    }

    const std::string WordIdentifier::to_string() const {
        return word;
    }

    void WordIdentifier::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const std::string &WordIdentifier::value() const {
        return word;
    }

    const std::vector<VarIdentifier*> WordIdentifier::variables() const {
        return std::vector<VarIdentifier*>();
    }

    UnificationResult WordIdentifier::unify(const CompositeIdentifier* other) const {
        return other->tryUnify(this);
    }

    UnificationResult WordIdentifier::unify(const IntegerLiteral* other) const {
        return UnificationResult();
    }

    UnificationResult WordIdentifier::unify(const SymbolIdentifier* other) const {
        return UnificationResult();
    }

    UnificationResult WordIdentifier::unify(const TextLiteral* other) const {
        return UnificationResult();
    }

    UnificationResult WordIdentifier::unify(const VarIdentifier* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult WordIdentifier::unify(const WordIdentifier* other) const {
        return value() == other->value() ? UnificationResult(this, other) : UnificationResult();
    }
}
