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
        TypeclassDef(const AbstractIdentifier* templateId, const AbstractIdentifier* typeclassId, const std::vector<const Property*> &properties);

        virtual ~TypeclassDef();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getTemplateId() const;
        const AbstractIdentifier* getTypeclassId() const;
        const std::vector<const Property*> &getProperties() const;

    private:
        const AbstractIdentifier* templateId;
        const AbstractIdentifier* typeclassId;

        const std::vector<const Property*> properties;
    };
}

#endif //BASE_TYPECLASSDEF_H
