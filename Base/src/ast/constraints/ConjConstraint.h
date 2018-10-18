//
// Created by roei on 18/10/18.
//

#ifndef BASE_CONJCONSTRAINT_H
#define BASE_CONJCONSTRAINT_H

#include <vector>
#include "AbstractConstraint.h"

namespace enki {
    class ConjConstraint : AbstractConstraint {
    public:
        explicit ConjConstraint(const std::vector<AbstractConstraint*> &constraints);

        const std::string nodeName() const override;

    private:
        const std::vector<AbstractConstraint*> constraints;
    };
}

#endif //BASE_CONJCONSTRAINT_H
