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
    class WhenBranches : AbstractConstraint {
    public:
        WhenBranches(const std::vector<WhenBranch*> &branches, const std::optional<AbstractConstraint*> &otherwise);

        const std::string nodeName() const override;

    private:
        const std::vector<WhenBranch*> branches;
        const std::optional<AbstractConstraint*> otherwise;
    };
}

#endif //BASE_WHENBRANCHES_H
