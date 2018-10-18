//
// Created by roei on 18/10/18.
//

#include "WhenBranch.h"

enki::WhenBranch::WhenBranch(const enki::AbstractIdentifier* matcher, const enki::AbstractConstraint* constraint)
        : matcher(matcher), constraint(constraint) {}

const std::string enki::WhenBranch::nodeName() const {
    return "WhenBranch";
}
