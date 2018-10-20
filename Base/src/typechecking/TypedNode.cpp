//
// Created by roei on 19/10/18.
//

#include "TypedNode.h"

namespace enki {
    TypedNode::TypedNode(const std::shared_ptr<AbstractResolvedNode> &node,
                         const std::optional<std::vector<std::shared_ptr<AbstractResolvedType>>> &inType,
                         const std::optional<std::shared_ptr<AbstractResolvedType>> &outType) : node(node),
                                                                                                inType(inType),
                                                                                                outType(outType) {}

    const std::shared_ptr<AbstractResolvedNode> &TypedNode::getNode() const {
        return node;
    }

    const std::optional<std::vector<std::shared_ptr<AbstractResolvedType>>> &TypedNode::getInType() const {
        return inType;
    }

    const std::optional<std::shared_ptr<AbstractResolvedType>> &TypedNode::getOutType() const {
        return outType;
    }

    const std::optional<std::shared_ptr<AbstractResolvedType>> TypedNode::getType() {
        if (!getInType().has_value() && getOutType().has_value()) {
            return std::optional(getOutType().value());
        } else {
            return std::optional<std::shared_ptr<AbstractResolvedType>>();
        }
    }
}
