//
// Created by roei on 18/10/18.
//

#include "IntegerLiteral.h"
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
    IntegerLiteral::IntegerLiteral(int val) : val(val) {}
    IntegerLiteral::~IntegerLiteral() = default;

    const std::string IntegerLiteral::nodeName() const {
        return "IntegerLiteral";
    }

    const std::string IntegerLiteral::to_string() const {
        return std::to_string(val);
    }

    void IntegerLiteral::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const int IntegerLiteral::value() const {
        return val;
    }

    const std::vector<const VarIdentifier*> IntegerLiteral::variables() const {
        return std::vector<const VarIdentifier*>();
    }

    UnificationResult IntegerLiteral::unify(const CompositeIdentifier* other) const {
        return CompositeIdentifier(std::vector<const AbstractIdentifier*>{this}).tryUnify(other);
    }

    UnificationResult IntegerLiteral::unify(const IntegerLiteral* other) const {
        return value() == other->value() ? UnificationResult(this, other) : UnificationResult();
    }

    UnificationResult IntegerLiteral::unify(const SymbolIdentifier* other) const {
        return UnificationResult();
    }

    UnificationResult IntegerLiteral::unify(const TextLiteral* other) const {
        return UnificationResult();
    }

    UnificationResult IntegerLiteral::unify(const VarIdentifier* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult IntegerLiteral::unify(const WordIdentifier* other) const {
        return UnificationResult();
    }
}
