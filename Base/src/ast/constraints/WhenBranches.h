//
// Created by roei on 18/10/18.
//

#ifndef BASE_WHENBRANCHES_H
#define BASE_WHENBRANCHES_H

#include <vector>
#include <optional>
#include "AbstractConstraint.h"
#include "WhenBranch.h"

namespace enki {
    class WhenBranches : public AbstractConstraint {
    public:
        WhenBranches(const std::vector<const WhenBranch*> &branches,
                     const std::optional<const AbstractConstraint*> &otherwise);

        virtual ~WhenBranches();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::vector<const WhenBranch*> &getBranches() const;
        const std::optional<const AbstractConstraint*> &getOtherwise() const;

    private:
        const std::vector<const WhenBranch*> branches;
        const std::optional<const AbstractConstraint*> otherwise;
    };
}

#endif //BASE_WHENBRANCHES_H
