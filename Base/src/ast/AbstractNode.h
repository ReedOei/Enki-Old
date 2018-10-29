//
// Created by roei on 10/12/18.
//

#ifndef BASE_NODE_H
#define BASE_NODE_H

#include <string>

namespace enki {
    class AbstractNodeVisitor;

    class AbstractNode {
    public:
        virtual ~AbstractNode();

        virtual const std::string nodeName() const = 0;
        virtual const std::string to_string() const = 0;
        virtual void accept(AbstractNodeVisitor &visitor) const = 0;
    };
}

#endif //BASE_NODE_H
