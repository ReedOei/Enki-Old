//
// Created by roei on 20/10/18.
//

#ifndef BASE_ABSTRACTRESOLVEDNODE_H
#define BASE_ABSTRACTRESOLVEDNODE_H

#include "../ast/AbstractNode.h"

namespace enki {
    class AbstractResolvedNodeVisitor;

    class AbstractResolvedNode : public AbstractNode {
    public:
        virtual void accept(AbstractResolvedNodeVisitor &visitor) const = 0;
    };
}

#endif //BASE_ABSTRACTRESOLVEDNODE_H
