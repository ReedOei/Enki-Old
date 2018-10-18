//
// Created by roei on 18/10/18.
//

#include "SingletonConstraint.h"

enki::SingletonConstraint::SingletonConstraint(const enki::AbstractIdentifier* identifier) : identifier(identifier) {}

const std::string enki::SingletonConstraint::nodeName() const {
    return "SingletonConstraint";
}
