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
        WhenBranch(const AbstractConstraint* matcher, const AbstractConstraint* constraint);

        virtual ~WhenBranch();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractConstraint* getMatcher() const;
        const AbstractConstraint* getConstraint() const;

    private:
        const AbstractConstraint* matcher;
        const AbstractConstraint* constraint;
    };
}

#endif //BASE_WHENBRANCH_H
