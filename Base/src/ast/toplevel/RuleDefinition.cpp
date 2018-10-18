//
// Created by roei on 18/10/18.
//

#include "RuleDefinition.h"

enki::RuleDefinition::RuleDefinition(const enki::AbstractIdentifier* ruleId, const enki::AbstractConstraint* constraint)
        : ruleId(ruleId), constraint(constraint) {}

const std::string enki::RuleDefinition::nodeName() const {
    return "RuleDefinition";
}
