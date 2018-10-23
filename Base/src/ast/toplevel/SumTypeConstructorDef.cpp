//
// Created by roei on 18/10/18.
//

#include <boost/algorithm/string/join.hpp>
#include "SumTypeConstructorDef.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    SumTypeConstructorDef::SumTypeConstructorDef(const std::shared_ptr<AbstractIdentifier> &identifier,
                                                 const std::vector<std::shared_ptr<AbstractTypeConstructorDef>> &variants)
            : identifier(identifier), variants(variants) {}

    const std::string enki::SumTypeConstructorDef::nodeName() const {
        return "SumTypeConstructorDef";
    }

    const std::string SumTypeConstructorDef::to_string() const {
        std::vector<std::string> strings;

        std::transform(variants.begin(), variants.end(), std::back_inserter(strings),
                [](auto variant) { return variant->to_string(); });

        return identifier->to_string() + " may be:\n" +
                boost::algorithm::join(strings, "\n");
    }

    void SumTypeConstructorDef::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        identifier->accept(visitor);

        for (const auto &variant : variants) {
            variant->accept(visitor);
        }
    }
}
