//
// Created by roei on 20/10/18.
//

#ifndef BASE_TYPEINFERER_H
#define BASE_TYPEINFERER_H

#include <optional>
#include <memory>
#include "../ast/AbstractNode.h"
#include "TypedNode.h"

namespace enki {
    class TypeInferer {
    public:
        TypeInferer();

        const std::optional<TypedNode> infer(std::shared_ptr<AbstractNode> node);
    };
}

#endif //BASE_TYPEINFERER_H
