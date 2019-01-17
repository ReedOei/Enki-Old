//
// Created by roei on 19/10/18.
//

#ifndef BASE_TYPEDNODE_H
#define BASE_TYPEDNODE_H

#include <memory>
#include <optional>
#include <vector>

#include "../resolver/AbstractResolvedNode.h"
#include "../resolver/type/AbstractResolvedType.h"

namespace enki {
    class TypedNode {
    public:
        TypedNode();
        virtual ~TypedNode();
    };
}

#endif //BASE_TYPEDNODE_H
