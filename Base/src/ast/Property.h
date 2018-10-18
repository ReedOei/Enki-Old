//
// Created by roei on 18/10/18.
//

#ifndef BASE_PROPERTY_H
#define BASE_PROPERTY_H

#include "AbstractNode.h"
#include "identifier/AbstractIdentifier.h"
#include "type/AbstractType.h"

namespace enki {
    class Property : AbstractNode {
    public:
        Property(const AbstractIdentifier* name, const AbstractType* type);

        const std::string nodeName() const override;

    private:
        const AbstractIdentifier* name;
        const AbstractType* type;
    };
}

#endif //BASE_PROPERTY_H
