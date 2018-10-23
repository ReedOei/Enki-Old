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
        ImplementationDef(const std::shared_ptr<AbstractIdentifier> &implementationId,
                          const std::shared_ptr<AbstractIdentifier> &typeclassId,
                          const std::vector<std::shared_ptr<AbstractDefinition>> &definitions);

        const std::string nodeName() const override;

        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> implementationId;
        const std::shared_ptr<AbstractIdentifier> typeclassId;

        const std::vector<std::shared_ptr<AbstractDefinition>> definitions;
    };
}

#endif //BASE_IMPLEMENTATIONDEF_H
