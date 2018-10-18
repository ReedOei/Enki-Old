//
// Created by roei on 18/10/18.
//

#include "TypeConstructorDef.h"

enki::TypeConstructorDef::TypeConstructorDef(const enki::AbstractIdentifier* identifier,
                                             const std::vector<std::pair<enki::AbstractIdentifier*, enki::AbstractType*>> &members)
        : identifier(identifier), members(members) {}

const std::string enki::TypeConstructorDef::nodeName() const {
    return "TypeConstructoDef";
}
