//
// Created by roei on 20/10/18.
//

#include "ResolvedSingletonConstraint.h"

namespace enki {
    ResolvedSingletonConstraint::ResolvedSingletonConstraint(const std::shared_ptr<AbstractResolvedIdentifier> &identifier)
            : identifier(identifier) {}

    const std::string ResolvedSingletonConstraint::nodeName() const {
        return "ResolvedSingletonConstraint";
    }
}
