//
// Created by roei on 18/10/18.
//

#ifndef BASE_SINGLETONCONSTRAINT_H
#define BASE_SINGLETONCONSTRAINT_H

#include "AbstractConstraint.h"
#include "../identifier/AbstractIdentifier.h"

namespace enki {
    class SingletonConstraint : AbstractConstraint {
    public:
        explicit SingletonConstraint(const AbstractIdentifier* identifier);

        const std::string nodeName() const override;

    private:
        const AbstractIdentifier* identifier;
    };
}

#endif //BASE_SINGLETONCONSTRAINT_H
