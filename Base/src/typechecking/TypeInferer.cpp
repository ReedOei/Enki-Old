//
// Created by roei on 20/10/18.
//

#include "TypeInferer.h"

enki::TypeInferer::TypeInferer() = default;

const std::optional<enki::TypedNode> enki::TypeInferer::infer(const std::shared_ptr<enki::AbstractNode> node) {
    return std::optional<enki::TypedNode>();
}
