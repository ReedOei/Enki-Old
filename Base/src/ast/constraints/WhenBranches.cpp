//
// Created by roei on 18/10/18.
//

#include "WhenBranches.h"

enki::WhenBranches::WhenBranches(const std::vector<enki::WhenBranch*> &branches,
                                 const std::optional<enki::AbstractConstraint*> &otherwise) : branches(branches),
                                                                                             otherwise(otherwise) {}

const std::string enki::WhenBranches::nodeName() const {
    return "WhenBranches";
}
