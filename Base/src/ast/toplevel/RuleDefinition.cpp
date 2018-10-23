//
// Created by roei on 18/10/18.
//

#include "RuleDefinition.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    RuleDefinition::RuleDefinition(const std::shared_ptr<AbstractIdentifier> &ruleId,
                                   const std::shared_ptr<AbstractConstraint> &constraint) : ruleId(ruleId),
                                                                                            constraint(constraint) {}

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
}
