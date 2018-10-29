//
// Created by roei on 18/10/18.
//

#include <boost/algorithm/string/join.hpp>
#include "WhenBranches.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    WhenBranches::WhenBranches(const std::vector<const WhenBranch*> &branches,
                               const std::optional<const AbstractConstraint*> &otherwise)
                               : branches(branches), otherwise(otherwise) {}
    WhenBranches::~WhenBranches() = default;

    const std::string WhenBranches::nodeName() const {
        return "WhenBranches";
    }

    void WhenBranches::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &branch : branches) {
            branch->accept(visitor);
        }

        if (otherwise.has_value()) {
            otherwise.value()->accept(visitor);
        }
    }

    const std::string WhenBranches::to_string() const {
        std::vector<std::string> strings;

        std::transform(branches.begin(), branches.end(), std::back_inserter(strings),
                [](auto branch) { return branch->to_string(); });

        std::string temp = boost::algorithm::join(strings, "\n");

        if (otherwise.has_value()) {
            return temp + "\n" + "otherwise then: " + otherwise.value()->to_string() + "\n";
        } else {
            return temp + "\n";
        }
    }

    const std::vector<const WhenBranch*> &WhenBranches::getBranches() const {
        return branches;
    }

    const std::optional<const AbstractConstraint*> &WhenBranches::getOtherwise() const {
        return otherwise;
    }
}
