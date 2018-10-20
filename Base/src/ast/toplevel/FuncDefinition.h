//
// Created by roei on 18/10/18.
//

#ifndef BASE_FUNCDEFINITION_H
#define BASE_FUNCDEFINITION_H

#include "AbstractDefinition.h"
#include "../identifier/AbstractIdentifier.h"
#include "../constraints/AbstractConstraint.h"

namespace enki {
    class FuncDefinition : public AbstractDefinition {
    public:
        FuncDefinition(const AbstractIdentifier* funcId, const AbstractConstraint* constraint);

        const std::string nodeName() const override;

    private:
        const AbstractIdentifier* funcId;
        const AbstractConstraint* constraint;
    };
}

#endif //BASE_FUNCDEFINITION_H
