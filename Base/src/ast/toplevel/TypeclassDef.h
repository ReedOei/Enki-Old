//
// Created by roei on 18/10/18.
//

#ifndef BASE_TYPECLASSDEF_H
#define BASE_TYPECLASSDEF_H

#include <vector>
#include <memory>
#include "AbstractTopLevel.h"
#include "../identifier/AbstractIdentifier.h"
#include "../Property.h"

namespace enki {
    class TypeclassDef : public AbstractTopLevel {
    public:
        TypeclassDef(const std::shared_ptr<AbstractIdentifier> &templateId,
                     const std::shared_ptr<AbstractIdentifier> &typeclassId,
                     const std::vector<std::shared_ptr<Property>> &properties);

        const std::string nodeName() const override;

        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> templateId;
        const std::shared_ptr<AbstractIdentifier> typeclassId;

        const std::vector<std::shared_ptr<Property>> properties;
    };
}

#endif //BASE_TYPECLASSDEF_H
