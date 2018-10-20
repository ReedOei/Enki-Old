//
// Created by roei on 18/10/18.
//

#ifndef BASE_COMPOSITEIDENTIFIER_H
#define BASE_COMPOSITEIDENTIFIER_H

#include <vector>
#include "AbstractIdentifier.h"

namespace enki {
    class CompositeIdentifier : public AbstractIdentifier {
    public:
        explicit CompositeIdentifier(const std::vector<AbstractIdentifier*> &identifiers);

    private:
        const std::vector<AbstractIdentifier*> identifiers;
    };
}

#endif //BASE_COMPOSITEIDENTIFIER_H
