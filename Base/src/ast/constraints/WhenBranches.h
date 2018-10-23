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
        WhenBranches(const std::vector<std::shared_ptr<WhenBranch>> &branches,
                     const std::optional<std::shared_ptr<AbstractConstraint>> &otherwise);

        const std::string nodeName() const override;

        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::vector<std::shared_ptr<WhenBranch>> branches;
        const std::optional<std::shared_ptr<AbstractConstraint>> otherwise;
    };
}

#endif //BASE_WHENBRANCHES_H
