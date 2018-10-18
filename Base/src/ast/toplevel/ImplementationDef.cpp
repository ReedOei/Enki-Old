//
// Created by roei on 18/10/18.
//

#include "ImplementationDef.h"

enki::ImplementationDef::ImplementationDef(const enki::AbstractIdentifier* implementationId,
                                           const enki::AbstractIdentifier* typeclassId,
                                           const std::vector<enki::AbstractDefinition*> &definitions)
        : implementationId(implementationId), typeclassId(typeclassId), definitions(definitions) {}

const std::string enki::ImplementationDef::nodeName() const {
    return "ImplementationDef";
}
