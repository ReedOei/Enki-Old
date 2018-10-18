//
// Created by roei on 18/10/18.
//

#ifndef BASE_TYPECLASSDEF_H
#define BASE_TYPECLASSDEF_H

#include <vector>
#include "AbstractTopLevel.h"
#include "../identifier/AbstractIdentifier.h"
#include "../Property.h"

namespace enki {
    class TypeclassDef : AbstractTopLevel {
    public:
        TypeclassDef(const AbstractIdentifier* templateId, const AbstractIdentifier* typeclassId,
                     const std::vector<Property*> &properties);

        const std::string nodeName() const override;

    private:
        const AbstractIdentifier* templateId;
        const AbstractIdentifier* typeclassId;

        const std::vector<Property*> properties;
    };
}

#endif //BASE_TYPECLASSDEF_H
