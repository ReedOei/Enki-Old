//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDCONJCONSTRAINT_H
#define BASE_RESOLVEDCONJCONSTRAINT_H

#include <vector>
#include <memory>
#include "AbstractResolvedConstraint.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedConjConstraint : public AbstractResolvedConstraint {
    public:
        explicit ResolvedConjConstraint(const std::vector<const AbstractResolvedConstraint*> &constraints);

        virtual ~ResolvedConjConstraint();

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const std::string nodeName() const override;

        const std::vector<const AbstractResolvedConstraint*> &getConstraints() const;

    private:
        const std::vector<const AbstractResolvedConstraint*> constraints;
    };
}

#endif //BASE_RESOLVEDCONJCONSTRAINT_H
