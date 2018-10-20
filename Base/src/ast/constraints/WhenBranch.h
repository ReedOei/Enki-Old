//
// Created by roei on 18/10/18.
//

#ifndef BASE_WHENBRANCH_H
#define BASE_WHENBRANCH_H

#include <boost/shared_ptr.hpp>
#include "../AbstractNode.h"
#include "../identifier/AbstractIdentifier.h"
#include "AbstractConstraint.h"

namespace enki {
    class WhenBranch : public AbstractNode {
    public:
        WhenBranch(const std::shared_ptr<AbstractIdentifier> &matcher,
                   const std::shared_ptr<AbstractConstraint> &constraint);

    private:
        const std::string nodeName() const override;

    private:
        const std::shared_ptr<AbstractIdentifier> matcher;
        const std::shared_ptr<AbstractConstraint> constraint;
    };
}

#endif //BASE_WHENBRANCH_H
