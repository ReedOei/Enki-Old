//
// Created by roei on 17/10/18.
//

#include "RuleType.h"

enki::RuleType::RuleType(const std::vector<std::pair<enki::Mode, enki::AbstractType*>> &modes) : modes(modes) {}

const std::string enki::RuleType::nodeName() const {
    return "RuleType";
}
