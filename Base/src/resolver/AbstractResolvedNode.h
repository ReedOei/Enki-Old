//
// Created by roei on 20/10/18.
//

#ifndef BASE_ABSTRACTRESOLVEDNODE_H
#define BASE_ABSTRACTRESOLVEDNODE_H

#include "../ast/AbstractNode.h"

namespace enki {
    class AbstractResolvedNodeVisitor;

    class AbstractResolvedNode {
    public:
        AbstractResolvedNode();
        explicit AbstractResolvedNode(const std::string &id);
        
        virtual void accept(AbstractResolvedNodeVisitor &visitor) const = 0;

        virtual const std::string nodeName() const = 0;

        const std::string &identifier() const;

    private:
        const std::string id;
    };
}

#endif //BASE_ABSTRACTRESOLVEDNODE_H
