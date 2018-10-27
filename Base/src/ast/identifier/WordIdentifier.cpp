//
// Created by roei on 18/10/18.
//

#include "WordIdentifier.h"
#include "../AbstractNodeVisitor.h"
#include "CompositeIdentifier.h"

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

    bool WordIdentifier::canUnify(const CompositeIdentifier* other) const {
        return other->tryUnify(this);
    }

    bool WordIdentifier::canUnify(const IntegerLiteral* other) const {
        return false;
    }

    bool WordIdentifier::canUnify(const SymbolIdentifier* other) const {
        return false;
    }

    bool WordIdentifier::canUnify(const TextLiteral* other) const {
        return false;
    }

    bool WordIdentifier::canUnify(const VarIdentifier* other) const {
        return true;
    }

    bool WordIdentifier::canUnify(const WordIdentifier* other) const {
        return value() == other->value();
    }
}
