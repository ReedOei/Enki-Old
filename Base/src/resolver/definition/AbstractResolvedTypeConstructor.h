//
// Created by roei on 20/10/18.
//

#ifndef BASE_ABSTRACTRESOLVEDTYPECONSTRUCTOR_H
#define BASE_ABSTRACTRESOLVEDTYPECONSTRUCTOR_H

#include "AbstractResolvedDefinition.h"

namespace enki {
    class AbstractResolvedTypeConstructor : public AbstractResolvedDefinition {
    public:
        virtual ~AbstractResolvedTypeConstructor();

        virtual const std::string constructorTypeName() const = 0;
    };
}


#endif //BASE_ABSTRACTRESOLVEDTYPECONSTRUCTOR_H
