//
// Created by roei on 18/10/18.
//

#ifndef BASE_RUNNABLE_H
#define BASE_RUNNABLE_H

#include "AbstractTopLevel.h"
#include "../constraints/AbstractConstraint.h"

namespace enki {
    class Runnable : AbstractTopLevel {
    public:
        explicit Runnable(const AbstractConstraint* constraint);

        const std::string nodeName() const override;

    private:
        const AbstractConstraint* constraint;
    };
}

#endif //BASE_RUNNABLE_H
