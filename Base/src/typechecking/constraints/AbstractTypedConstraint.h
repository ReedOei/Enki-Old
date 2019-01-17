//
// Created by roei on 17/01/19.
//

#ifndef BASE_ABSTRACTTYPEDCONSTRAINT_H
#define BASE_ABSTRACTTYPEDCONSTRAINT_H

#include "../TypedNode.h"

namespace enki {
    class AbstractTypedConstraint : public TypedNode {
    public:
        AbstractTypedConstraint();
        ~AbstractTypedConstraint() override;
    };
}

#endif //BASE_ABSTRACTTYPEDCONSTRAINT_H
