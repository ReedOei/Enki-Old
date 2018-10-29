//
// Created by roei on 20/10/18.
//

#include "ResolvedRuleType.h"

namespace enki {
    ResolvedRuleType::ResolvedRuleType(
            const std::vector<std::pair<std::optional<Mode>, const AbstractResolvedType*>> &types) : types(types) {}

    const std::string ResolvedRuleType::nodeName() const {
        return "ResolvedRuleType";
    }

    const std::string ResolvedRuleType::typeName() const {
        std::string s;

        s += "(";

        for (const auto &t : types) {
            if (t.first.has_value()) {
                switch (t.first.value()) {
                    case IN:
                        s += "+";
                        break;
                    case OUT:
                        s += "-";
                        break;
                    case PARTIAL:
                        s += "?";
                        break;
                }
            } else {
                s += "???";
            }

            s += t.second->typeName();

            s += ", ";
        }

        s += ")";

        return s;
    }

    void ResolvedRuleType::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &type : types) {
            type.second->accept(visitor);
        }
    }

    const std::vector<std::pair<std::optional<Mode>, const AbstractResolvedType*>> &ResolvedRuleType::getTypes() const {
        return types;
    }

    ResolvedRuleType::~ResolvedRuleType() {

    }
}
