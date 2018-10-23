//
// Created by roei on 20/10/18.
//

#ifndef BASE_ABSTRACTRESOLVEDTYPE_H
#define BASE_ABSTRACTRESOLVEDTYPE_H

#include "../AbstractResolvedNode.h"

namespace enki {
    class AbstractResolvedType : public AbstractResolvedNode {
    public:
        virtual const std::string typeName() const = 0;
    };
}

#endif //BASE_ABSTRACTRESOLVEDTYPE_H
