//
// Created by roei on 18/10/18.
//

#include "FuncDefinition.h"

enki::FuncDefinition::FuncDefinition(const enki::AbstractIdentifier* funcId, const enki::AbstractConstraint* constraint)
        : funcId(funcId), constraint(constraint) {}

const std::string enki::FuncDefinition::nodeName() const {
    return "FuncDefinition";
}
