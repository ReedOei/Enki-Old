//
// Created by roei on 18/10/18.
//

#include "WhenBranches.h"

enki::WhenBranches::WhenBranches(const std::vector<std::shared_ptr<enki::WhenBranch>> &branches,
                                 const std::optional<std::shared_ptr<enki::AbstractConstraint>> &otherwise) : branches(
        branches), otherwise(otherwise) {}

const std::string enki::WhenBranches::nodeName() const {
    return "WhenBranches";
}

