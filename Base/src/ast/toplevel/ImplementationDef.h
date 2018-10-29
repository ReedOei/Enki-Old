//
// Created by roei on 18/10/18.
//

#ifndef BASE_IMPLEMENTATIONDEF_H
#define BASE_IMPLEMENTATIONDEF_H

#include <vector>
#include <memory>
#include "AbstractTopLevel.h"
#include "../identifier/AbstractIdentifier.h"
#include "AbstractDefinition.h"

namespace enki {
    class ImplementationDef : public AbstractTopLevel {
    public:
        ImplementationDef(const AbstractIdentifier* implementationId,
                          const AbstractIdentifier* typeclassId,
                          const std::vector<const AbstractDefinition*> &definitions);

        virtual ~ImplementationDef();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getImplementationId() const;

        const AbstractIdentifier* getTypeclassId() const;

        const std::vector<const AbstractDefinition*> &getDefinitions() const;

    private:
        const AbstractIdentifier* implementationId;
        const AbstractIdentifier* typeclassId;

        const std::vector<const AbstractDefinition*> definitions;
    };
}

#endif //BASE_IMPLEMENTATIONDEF_H
