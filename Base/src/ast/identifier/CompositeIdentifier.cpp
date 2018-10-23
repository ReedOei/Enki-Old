//
// Created by roei on 18/10/18.
//

#include <algorithm>
#include <boost/algorithm/string/join.hpp>
#include "CompositeIdentifier.h"
#include "../AbstractNodeVisitor.h"

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
}
