//
// Created by roei on 20/10/18.
//

#ifndef BASE_ABSTRACTRESOLVEDTYPE_H
#define BASE_ABSTRACTRESOLVEDTYPE_H

#include <string>

namespace enki {
    class AbstractResolvedType {
    public:
        virtual const std::string typeName() const = 0;
    };
}

#endif //BASE_ABSTRACTRESOLVEDTYPE_H
