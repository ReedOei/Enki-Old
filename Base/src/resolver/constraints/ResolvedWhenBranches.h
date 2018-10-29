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
        ResolvedWhenBranches(const std::vector<const ResolvedWhenBranch*> &branches,
                             const std::optional<const AbstractResolvedConstraint*> &otherwise);

        virtual ~ResolvedWhenBranches();

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const std::vector<const ResolvedWhenBranch*> &getBranches() const;
        const std::optional<const AbstractResolvedConstraint*> &getOtherwise() const;

    private:
        const std::vector<const ResolvedWhenBranch*> branches;
        const std::optional<const AbstractResolvedConstraint*> otherwise;
    };
}


#endif //BASE_RESOLVEDWHENBRANCHES_H
