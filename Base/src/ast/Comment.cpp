//
// Created by roei on 18/10/18.
//

#include "Comment.h"
#include "AbstractNodeVisitor.h"

namespace enki {
    Comment::Comment(const std::string &str) : str(str) {}

    const std::string &Comment::string() const {
        return str;
    }

    const std::string Comment::nodeName() const {
        return "Comment";
    }

    const std::string Comment::to_string() const {
        return "-- " + string();
    }

    void Comment::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    Comment::~Comment() {

    }
}
