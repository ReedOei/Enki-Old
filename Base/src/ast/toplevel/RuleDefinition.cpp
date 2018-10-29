//
// Created by roei on 18/10/18.
//

#include "RuleDefinition.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    RuleDefinition::RuleDefinition(const AbstractIdentifier* ruleId, const AbstractConstraint* constraint)
        : ruleId(ruleId), constraint(constraint) {}

    const std::string enki::RuleDefinition::nodeName() const {
        return "RuleDefinition";
    }

    const std::string RuleDefinition::to_string() const {
        return ruleId->to_string() + " if:\n" + constraint->to_string();
    }

    void RuleDefinition::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        ruleId->accept(visitor);
        constraint->accept(visitor);
    }

    const AbstractIdentifier* RuleDefinition::getRuleId() const {
        return ruleId;
    }

    const AbstractConstraint* RuleDefinition::getConstraint() const {
        return constraint;
    }

    RuleDefinition::~RuleDefinition() {

    }
}
