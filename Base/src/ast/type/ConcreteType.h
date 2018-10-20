//
// Created by roei on 17/10/18.
//

#ifndef BASE_CONCRETETYPE_H
#define BASE_CONCRETETYPE_H

#include "AbstractType.h"
#include "../identifier/AbstractIdentifier.h"

namespace enki {
    class ConcreteType : public AbstractType {
    public:
        explicit ConcreteType(const AbstractIdentifier *typeName);

        const std::string nodeName() const override;

    private:
        const AbstractIdentifier *typeName;
    };
}

#endif //BASE_CONCRETETYPE_H
