//
// Created by roei on 20/10/18.
//

#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include "AbstractResolvedNode.h"

namespace enki {
    AbstractResolvedNode::AbstractResolvedNode(const std::string &id) : id(id) {}

    AbstractResolvedNode::AbstractResolvedNode() : id(boost::uuids::to_string(boost::uuids::random_generator()())) {}

    const std::string &AbstractResolvedNode::identifier() const {
        return id;
    }

    AbstractResolvedNode::~AbstractResolvedNode() {

    }
}
