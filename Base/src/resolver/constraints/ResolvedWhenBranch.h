//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDWHENBRANCH_H
#define BASE_RESOLVEDWHENBRANCH_H

#include <memory>

#include "AbstractResolvedConstraint.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedWhenBranch : public AbstractResolvedConstraint {
    public:
        ResolvedWhenBranch(const AbstractResolvedConstraint* matcher,
                           const AbstractResolvedConstraint* constraint);

        virtual ~ResolvedWhenBranch();

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const std::string nodeName() const override;

        const AbstractResolvedConstraint* getMatcher() const;

        const AbstractResolvedConstraint* getConstraint() const;

    private:
        const AbstractResolvedConstraint* matcher;
        const AbstractResolvedConstraint* constraint;
    };
}

#endif //BASE_RESOLVEDWHENBRANCH_H
