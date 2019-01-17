//
// Created by roei on 20/10/18.
//

#include "TypeInferer.h"

namespace enki {
    TypeInferer::TypeInferer() = default;

    const Error<TypedNode> TypeInferer::infer(const AbstractNode* node) {
        return Error<TypedNode>("placeholder");
    }
}
