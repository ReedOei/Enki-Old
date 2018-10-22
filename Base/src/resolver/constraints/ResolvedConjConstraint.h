//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDCONJCONSTRAINT_H
#define BASE_RESOLVEDCONJCONSTRAINT_H

#include <vector>
#include <memory>
#include "AbstractResolvedConstraint.h"

namespace enki {
    class ResolvedConjConstraint : AbstractResolvedConstraint {
    public:
        explicit ResolvedConjConstraint(const std::vector<std::shared_ptr<AbstractResolvedConstraint>> &constraints);

        const std::string nodeName() const override;

    private:
        const std::vector<std::shared_ptr<AbstractResolvedConstraint>> constraints;
    };
}

#endif //BASE_RESOLVEDCONJCONSTRAINT_H
