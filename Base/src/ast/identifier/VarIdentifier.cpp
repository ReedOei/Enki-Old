//
// Created by roei on 18/10/18.
//

#include <vector>

#include "../AbstractNodeVisitor.h"

#include "VarIdentifier.h"
#include "CompositeIdentifier.h"
#include "IntegerLiteral.h"
#include "SymbolIdentifier.h"
#include "TextLiteral.h"
#include "WordIdentifier.h"
#include "VarIdentifier.h"

namespace enki {
    VarIdentifier::VarIdentifier(const std::string &varName) : varName(varName) {}

    const std::string VarIdentifier::nodeName() const {
        return "VarIdentifier";
    }

    const std::string VarIdentifier::to_string() const {
        return varName;
    }

    void VarIdentifier::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const std::string VarIdentifier::value() const {
        return varName;
    }

    const std::vector<VarIdentifier*> VarIdentifier::variables() const {
        std::vector<VarIdentifier*> v;

        v.push_back(std::make_shared<VarIdentifier>(varName).get());

        return v;
    }

    UnificationResult VarIdentifier::unify(const CompositeIdentifier* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult VarIdentifier::unify(const IntegerLiteral* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult VarIdentifier::unify(const SymbolIdentifier* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult VarIdentifier::unify(const TextLiteral* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult VarIdentifier::unify(const VarIdentifier* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult VarIdentifier::unify(const WordIdentifier* other) const {
        return UnificationResult(this, other);
    }
}
