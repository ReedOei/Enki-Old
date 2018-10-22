//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDWHENBRANCH_H
#define BASE_RESOLVEDWHENBRANCH_H

#include <memory>

#include <resolver/identifier/AbstractResolvedIdentifier.h>
#include "AbstractResolvedConstraint.h"

namespace enki {
    class ResolvedWhenBranch : AbstractResolvedConstraint {
    public:
        ResolvedWhenBranch(const std::shared_ptr<AbstractResolvedConstraint> &matcher,
                           const std::shared_ptr<AbstractResolvedConstraint> &constraint);

        const std::string nodeName() const override;

    private:
        const std::shared_ptr<AbstractResolvedConstraint> matcher;
        const std::shared_ptr<AbstractResolvedConstraint> constraint;
    };
}

#endif //BASE_RESOLVEDWHENBRANCH_H
