//
// Created by roei on 18/10/18.
//

#include "WordIdentifier.h"
#include "../AbstractNodeVisitor.h"

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
}
