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

    bool CompositeIdentifier::canUnify(const CompositeIdentifier* other) const {
        // TODO: Remove this restriction, and allow them to match as long as the last part is a variable
        if (ids().size() != other->ids().size()) {
            return false;
        }

        for (auto i = 0; i < ids().size(); i++) {
            auto a = ids()[i];
            auto b = other->ids()[i];

            if (!a->tryUnify(b.get())) {
                return false;
            }
        }

        return true;
    }

    bool CompositeIdentifier::canUnify(const IntegerLiteral* other) const {
        std::vector<std::shared_ptr<AbstractIdentifier>> ids {std::make_shared<IntegerLiteral>(other->value())};
        return canUnify(std::make_shared<CompositeIdentifier>(ids).get());
    }

    bool CompositeIdentifier::canUnify(const SymbolIdentifier* other) const {
        std::vector<std::shared_ptr<AbstractIdentifier>> ids {std::make_shared<SymbolIdentifier>(other->value())};
        return canUnify(std::make_shared<CompositeIdentifier>(ids).get());
    }

    bool CompositeIdentifier::canUnify(const TextLiteral* other) const {
        std::vector<std::shared_ptr<AbstractIdentifier>> ids {std::make_shared<TextLiteral>(other->value())};
        return canUnify(std::make_shared<CompositeIdentifier>(ids).get());
    }

    bool CompositeIdentifier::canUnify(const VarIdentifier* other) const {
        return true;
    }

    bool CompositeIdentifier::canUnify(const WordIdentifier* other) const {
        std::vector<std::shared_ptr<AbstractIdentifier>> ids {std::make_shared<WordIdentifier>(other->value())};
        return canUnify(std::make_shared<CompositeIdentifier>(ids).get());
    }
}
