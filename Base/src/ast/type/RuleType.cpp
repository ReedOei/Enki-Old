//
// Created by roei on 17/10/18.
//

#include <boost/algorithm/string/join.hpp>
#include "RuleType.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    RuleType::RuleType(const std::vector<std::pair<Mode, const AbstractType*>> &modes) : modes(modes) {}

    const std::string RuleType::nodeName() const {
        return "RuleType";
    }

    const std::string RuleType::to_string() const {
        std::vector<std::string> strings;

        std::transform(modes.begin(), modes.end(), std::back_inserter(strings),
                [](auto mode) { return enki::to_string(mode.first) + mode.second->to_string(); });

        return "(" + boost::algorithm::join(strings, ", ") + ")";
    }

    void RuleType::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &mode : modes) {
            mode.second->accept(visitor);
        }
    }

    const std::vector<std::pair<Mode, const AbstractType*>> &RuleType::getModes() const {
        return modes;
    }

    RuleType::~RuleType() {

    }
}
