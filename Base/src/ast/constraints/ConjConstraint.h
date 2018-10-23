//
// Created by roei on 18/10/18.
//

#ifndef BASE_CONJCONSTRAINT_H
#define BASE_CONJCONSTRAINT_H

#include <vector>
#include <memory>
#include "AbstractConstraint.h"

namespace enki {
    class ConjConstraint : public AbstractConstraint {
    public:
        explicit ConjConstraint(const std::vector<std::shared_ptr<AbstractConstraint>> &constraints);

        const std::string nodeName() const override;

        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::vector<std::shared_ptr<AbstractConstraint>> constraints;
    };
}

#endif //BASE_CONJCONSTRAINT_H
