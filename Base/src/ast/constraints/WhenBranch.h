//
// Created by roei on 18/10/18.
//

#ifndef BASE_WHENBRANCH_H
#define BASE_WHENBRANCH_H

#include "../AbstractNode.h"
#include "../identifier/AbstractIdentifier.h"
#include "AbstractConstraint.h"

namespace enki {
    class WhenBranch : AbstractNode {
    public:
        WhenBranch(const AbstractIdentifier* matcher, const AbstractConstraint* constraint);

    private:
        const std::string nodeName() const override;

    private:
        const AbstractIdentifier* matcher;
        const AbstractConstraint* constraint;
    };
}

#endif //BASE_WHENBRANCH_H
