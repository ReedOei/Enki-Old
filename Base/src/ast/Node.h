//
// Created by roei on 10/12/18.
//

#ifndef BASE_NODE_H
#define BASE_NODE_H

#include <string>

class Node {
public:
    virtual std::string &nodeName() = 0;
};

#endif //BASE_NODE_H
