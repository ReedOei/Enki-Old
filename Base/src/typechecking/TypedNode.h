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
        TypedNode(const std::shared_ptr<AbstractResolvedNode> &node,
                  const std::optional<std::vector<std::shared_ptr<AbstractResolvedType>>> &inType,
                  const std::optional<std::shared_ptr<AbstractResolvedType>> &outType);

        const std::optional<std::shared_ptr<AbstractResolvedType>> getType();

        const std::shared_ptr<AbstractResolvedNode> &getNode() const;

        const std::optional<std::vector<std::shared_ptr<AbstractResolvedType>>> &getInType() const;

        const std::optional<std::shared_ptr<AbstractResolvedType>> &getOutType() const;

    private:
        const std::shared_ptr<AbstractResolvedNode> node;

        const std::optional<std::vector<std::shared_ptr<AbstractResolvedType>>> inType;
        const std::optional<std::shared_ptr<AbstractResolvedType>> outType;
    };
}

#endif //BASE_TYPEDNODE_H
