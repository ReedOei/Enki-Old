//
// Created by roei on 18/10/18.
//

#ifndef BASE_IMPLEMENTATIONDEF_H
#define BASE_IMPLEMENTATIONDEF_H

#include <vector>
#include "AbstractTopLevel.h"
#include "../identifier/AbstractIdentifier.h"
#include "AbstractDefinition.h"

namespace enki {
    class ImplementationDef : public AbstractTopLevel {
    public:
        ImplementationDef(const AbstractIdentifier* implementationId, const AbstractIdentifier* typeclassId,
                          const std::vector<AbstractDefinition*> &definitions);

        const std::string nodeName() const override;

    private:
        const AbstractIdentifier* implementationId;
        const AbstractIdentifier* typeclassId;

        const std::vector<AbstractDefinition*> definitions;
    };
}

#endif //BASE_IMPLEMENTATIONDEF_H
