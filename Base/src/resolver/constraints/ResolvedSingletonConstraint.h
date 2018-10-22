//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDSINGLETONCONSTRAINT_H
#define BASE_RESOLVEDSINGLETONCONSTRAINT_H

#include <memory>

#include <resolver/identifier/AbstractResolvedIdentifier.h>
#include "AbstractResolvedConstraint.h"

namespace enki {
    class ResolvedSingletonConstraint : AbstractResolvedConstraint {
    public:
        explicit ResolvedSingletonConstraint(const std::shared_ptr<AbstractResolvedIdentifier> &identifier);

        const std::string nodeName() const override;

    private:
        const std::shared_ptr<AbstractResolvedIdentifier> identifier;
    };
}

#endif //BASE_RESOLVEDSINGLETONCONSTRAINT_H
