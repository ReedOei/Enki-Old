//
// Created by roei on 17/10/18.
//

#include "ConcreteType.h"

enki::ConcreteType::ConcreteType(const enki::AbstractIdentifier *typeName) : typeName(typeName) {}

const std::string enki::ConcreteType::nodeName() const {
    return "ConcreteType";
}

