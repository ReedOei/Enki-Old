//
// Created by roei on 18/10/18.
//

#ifndef BASE_RULEDEFINITION_H
#define BASE_RULEDEFINITION_H

#include "AbstractDefinition.h"
#include "../identifier/AbstractIdentifier.h"
#include "../constraints/AbstractConstraint.h"

namespace enki {
    class RuleDefinition : AbstractDefinition {
    public:
        RuleDefinition(const AbstractIdentifier* ruleId, const AbstractConstraint* constraint);

        const std::string nodeName() const override;

    private:
        const AbstractIdentifier* ruleId;
        const AbstractConstraint* constraint;
    };
}

#endif //BASE_RULEDEFINITION_H
