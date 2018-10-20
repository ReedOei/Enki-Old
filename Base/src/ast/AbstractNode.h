//
// Created by roei on 10/12/18.
//

#ifndef BASE_NODE_H
#define BASE_NODE_H

#include <string>

namespace enki {
    class AbstractNode {
    public:
        AbstractNode();
        explicit AbstractNode(const std::string &id);

        virtual const std::string nodeName() const = 0;

        const std::string &identifier() const;

    private:
        const std::string id;
    };
}

#endif //BASE_NODE_H