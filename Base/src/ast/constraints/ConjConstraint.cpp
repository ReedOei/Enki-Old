//
// Created by roei on 18/10/18.
//

#include "ConjConstraint.h"

enki::ConjConstraint::ConjConstraint(const std::vector<enki::AbstractConstraint*> &constraints) : constraints(
        constraints) {}

const std::string enki::ConjConstraint::nodeName() const {
    return "ConjConstraint";
}
