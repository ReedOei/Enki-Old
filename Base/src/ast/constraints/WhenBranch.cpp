//
// Created by roei on 18/10/18.
//

#include "WhenBranch.h"

enki::WhenBranch::WhenBranch(const std::shared_ptr<enki::AbstractIdentifier> &matcher,
                             const std::shared_ptr<enki::AbstractConstraint> &constraint) : matcher(matcher),
                                                                                            constraint(constraint) {}

const std::string enki::WhenBranch::nodeName() const {
    return "WhenBranch";
}
