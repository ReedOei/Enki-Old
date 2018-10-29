//
// Created by roei on 18/10/18.
//

#ifndef BASE_RULEDEFINITION_H
#define BASE_RULEDEFINITION_H

#include <memory>
#include "AbstractDefinition.h"
#include "../identifier/AbstractIdentifier.h"
#include "../constraints/AbstractConstraint.h"

namespace enki {
    class RuleDefinition : public AbstractDefinition {
    public:
        RuleDefinition(const AbstractIdentifier* ruleId, const AbstractConstraint* constraint);

        virtual ~RuleDefinition();

        const std::string to_string() const override;
        const std::string nodeName() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getRuleId() const;
        const AbstractConstraint* getConstraint() const;

    private:
        const AbstractIdentifier* ruleId;
        const AbstractConstraint* constraint;
    };
}

#endif //BASE_RULEDEFINITION_H
