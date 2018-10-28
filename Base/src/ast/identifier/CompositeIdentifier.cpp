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
    CompositeIdentifier::CompositeIdentifier(const std::vector<std::shared_ptr<AbstractIdentifier>> &identifiers)
            : identifiers(identifiers) {}

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

    const std::vector<std::shared_ptr<AbstractIdentifier>> &CompositeIdentifier::ids() const {
        return identifiers;
    }

    UnificationResult CompositeIdentifier::unify(const CompositeIdentifier* other) const {
        UnificationResult result;

        // TODO: Remove this restriction, and allow them to match as long as the last part is a variable
        if (ids().size() != other->ids().size()) {
            return result;
        }

        for (auto i = 0; i < ids().size(); i++) {
            auto a = ids()[i];
            auto b = other->ids()[i];

            auto r = a->tryUnify(b.get());

            if (r.empty()) {
                return UnificationResult();
            } else {
                result.appendAll(r);
            }
        }

        return result;
    }

    UnificationResult CompositeIdentifier::unify(const IntegerLiteral* other) const {
        return unify(std::make_shared<CompositeIdentifier>(std::vector<std::shared_ptr<AbstractIdentifier>> {std::make_shared<IntegerLiteral>(other->value())}).get());
    }

    UnificationResult CompositeIdentifier::unify(const SymbolIdentifier* other) const {
        return unify(std::make_shared<CompositeIdentifier>(std::vector<std::shared_ptr<AbstractIdentifier>> {std::make_shared<SymbolIdentifier>(other->value())}).get());
    }

    UnificationResult CompositeIdentifier::unify(const TextLiteral* other) const {
        return unify(std::make_shared<CompositeIdentifier>(std::vector<std::shared_ptr<AbstractIdentifier>> {std::make_shared<TextLiteral>(other->value())}).get());
    }

    UnificationResult CompositeIdentifier::unify(const VarIdentifier* other) const {
        return UnificationResult(this, other);
    }

    UnificationResult CompositeIdentifier::unify(const WordIdentifier* other) const {
        return unify(std::make_shared<CompositeIdentifier>(std::vector<std::shared_ptr<AbstractIdentifier>> {std::make_shared<WordIdentifier>(other->value())}).get());
    }

    const std::vector<VarIdentifier*> CompositeIdentifier::variables() const {
        std::vector<VarIdentifier*> variables;

        for (const auto &identifier : identifiers) {
            variables.insert(variables.end(), identifier->variables().begin(), identifier->variables().end());
        }

        return variables;
    }
}

