//
// Created by roei on 18/10/18.
//

#include <algorithm>
#include <boost/algorithm/string/join.hpp>
#include "CompositeIdentifier.h"
#include "../AbstractNodeVisitor.h"
#include "WordIdentifier.h"
#include "IntegerLiteral.h"
#include "SymbolIdentifier.h"
#include "TextLiteral.h"
#include "VarIdentifier.h"

namespace enki {
    CompositeIdentifier::CompositeIdentifier(const std::vector<const AbstractIdentifier*> &identifiers) : identifiers(identifiers) {}
    CompositeIdentifier::~CompositeIdentifier() = default;

    const std::string CompositeIdentifier::nodeName() const {
        return "CompositeIdentifier";
    }

    void CompositeIdentifier::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &id : identifiers) {
            id->accept(visitor);
        }
    }

    const std::string CompositeIdentifier::to_string() const {
        std::vector<std::string> strings;

        std::transform(identifiers.begin(), identifiers.end(), std::back_inserter(strings),
                       [](auto id) { return "(" + id->to_string() + ")"; });

        return boost::algorithm::join(strings, " ");
    }

    UnificationResult CompositeIdentifier::unify(const CompositeIdentifier* other) const {
        UnificationResult result;

        // TODO: Remove this restriction, and allow them to match as long as the last part is a variable
        if (getIdentifiers().size() != other->getIdentifiers().size()) {
            return result;
        }

        for (auto i = 0; i < getIdentifiers().size(); i++) {
            auto a = getIdentifiers()[i];
            auto b = other->getIdentifiers()[i];

            auto r = a->tryUnify(b);

            if (r.empty()) {
                return UnificationResult();
            } else {
                result.appendAll(r);
            }
        }

        return result;
    }

    UnificationResult CompositeIdentifier::unify(const IntegerLiteral* other) const {
        auto c = new CompositeIdentifier(std::vector<const AbstractIdentifier*> {other});
        auto b = unify(c);
        delete c;

        return b;
    }

    UnificationResult CompositeIdentifier::unify(const SymbolIdentifier* other) const {
        auto c = new CompositeIdentifier(std::vector<const AbstractIdentifier*> {other});
        auto b = unify(c);
        delete c;

        return b;
    }

    UnificationResult CompositeIdentifier::unify(const TextLiteral* other) const {
        auto c = new CompositeIdentifier(std::vector<const AbstractIdentifier*> {other});
        auto b = unify(c);
        delete c;

        return b;
    }

    UnificationResult CompositeIdentifier::unify(const VarIdentifier* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult CompositeIdentifier::unify(const WordIdentifier* other) const {
        auto c = new CompositeIdentifier(std::vector<const AbstractIdentifier*> {other});
        auto b = unify(c);
        delete c;

        return b;
    }

    const std::vector<const VarIdentifier*> CompositeIdentifier::variables() const {
        std::vector<const VarIdentifier*> variables;

        for (const auto &identifier : identifiers) {
            auto vars = identifier->variables();
            variables.insert(variables.end(), vars.begin(), vars.end());
        }

        return variables;
    }

    const std::vector<const AbstractIdentifier*> &CompositeIdentifier::getIdentifiers() const {
        return identifiers;
    }
}

