//
// Created by roei on 18/10/18.
//

#include "TypeclassDef.h"

enki::TypeclassDef::TypeclassDef(const enki::AbstractIdentifier* templateId,
                                 const enki::AbstractIdentifier* typeclassId,
                                 const std::vector<enki::Property*> &properties) : templateId(templateId),
                                                                                   typeclassId(typeclassId),
                                                                                   properties(properties) {}

const std::string enki::TypeclassDef::nodeName() const {
    return "TypeclassDef";
}
