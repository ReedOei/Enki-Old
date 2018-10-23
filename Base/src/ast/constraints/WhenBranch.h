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
        WhenBranch(const std::shared_ptr<AbstractConstraint> &matcher,
                   const std::shared_ptr<AbstractConstraint> &constraint);

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::string nodeName() const override;

        const std::string to_string() const override;

    private:
        const std::shared_ptr<AbstractConstraint> matcher;
        const std::shared_ptr<AbstractConstraint> constraint;
    };
}

#endif //BASE_WHENBRANCH_H
