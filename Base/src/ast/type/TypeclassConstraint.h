//
// Created by roei on 17/10/18.
//

#ifndef BASE_TYPECLASSCONSTRAINT_H
#define BASE_TYPECLASSCONSTRAINT_H


#include "AbstractType.h"
#include "../identifier/AbstractIdentifier.h"

namespace enki {
    class TypeclassConstraint : AbstractType {
    public:
        TypeclassConstraint(const AbstractIdentifier* identifier, const AbstractType* type);

        const std::string nodeName() const override;

    private:
        const AbstractIdentifier* identifier;
        const AbstractType* type;
    };
}


#endif //BASE_TYPECLASSCONSTRAINT_H
