//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDWHENBRANCHES_H
#define BASE_RESOLVEDWHENBRANCHES_H

#include <vector>
#include <optional>

#include "AbstractResolvedConstraint.h"
#include "ResolvedWhenBranch.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedWhenBranches : public AbstractResolvedConstraint {
    public:
        ResolvedWhenBranches(const std::vector<std::shared_ptr<ResolvedWhenBranch>> &branches,
                             const std::optional<std::shared_ptr<AbstractResolvedConstraint>> &otherwise);

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::vector<std::shared_ptr<ResolvedWhenBranch>> branches;
        const std::optional<std::shared_ptr<AbstractResolvedConstraint>> otherwise;
    };
}


#endif //BASE_RESOLVEDWHENBRANCHES_H
