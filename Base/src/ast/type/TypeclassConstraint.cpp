//
// Created by roei on 17/10/18.
//

#include "TypeclassConstraint.h"

enki::TypeclassConstraint::TypeclassConstraint(const enki::AbstractIdentifier* identifier,
                                               const enki::AbstractType* type) : identifier(identifier), type(type) {}

const std::string enki::TypeclassConstraint::nodeName() const {
    return "TypeclassConstraint";
}
