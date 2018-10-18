//
// Created by roei on 18/10/18.
//

#include "Runnable.h"

enki::Runnable::Runnable(const enki::AbstractConstraint* constraint) : constraint(constraint) {}

const std::string enki::Runnable::nodeName() const {
    return "Runnable";
}
