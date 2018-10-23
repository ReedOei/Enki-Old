//
// Created by roei on 10/12/18.
//

#include "AbstractNode.h"

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.

namespace enki {
    AbstractNode::AbstractNode(const std::string &id) : id(id) {}

    AbstractNode::AbstractNode() : id(boost::uuids::to_string(boost::uuids::random_generator()())) {}
    
    const std::string &AbstractNode::identifier() const {
        return id;
    }
}
