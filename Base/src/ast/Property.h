//
// Created by roei on 18/10/18.
//

#ifndef BASE_PROPERTY_H
#define BASE_PROPERTY_H

#include <memory>
#include "AbstractNode.h"
#include "identifier/AbstractIdentifier.h"
#include "type/AbstractType.h"

namespace enki {
    class Property : AbstractNode {
    public:
        Property(const AbstractIdentifier* name, const AbstractType* type);

        virtual ~Property();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getName() const;

        const AbstractType* getType() const;

    private:
        const AbstractIdentifier* name;
        const AbstractType* type;
    };
}

#endif //BASE_PROPERTY_H
