//
// Created by roei on 18/10/18.
//

#include "VarIdentifier.h"

enki::VarIdentifier::VarIdentifier(const std::string &varName) : varName(varName) {}

const std::string enki::VarIdentifier::nodeName() const {
    return "VarIdentifier";
}
