//
// Created by roei on 20/10/18.
//

#ifndef BASE_ABSTRACTRESOLVEDCONSTRAINT_H
#define BASE_ABSTRACTRESOLVEDCONSTRAINT_H

#include "../AbstractResolvedNode.h"

namespace enki {
    class AbstractResolvedConstraint : public AbstractResolvedNode {
    public:
        virtual ~AbstractResolvedConstraint();
    };
}

#endif //BASE_ABSTRACTRESOLVEDCONSTRAINT_H
