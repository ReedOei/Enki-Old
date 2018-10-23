//
// Created by roei on 18/10/18.
//

#include "IntegerLiteral.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    IntegerLiteral::IntegerLiteral(int val) : val(val) {}

    const std::string IntegerLiteral::nodeName() const {
        return "IntegerLiteral";
    }

    const std::string IntegerLiteral::to_string() const {
        return std::to_string(val);
    }

    void IntegerLiteral::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const int IntegerLiteral::getVal() const {
        return val;
    }
}
