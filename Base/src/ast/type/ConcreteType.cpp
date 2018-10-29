//
// Created by roei on 17/10/18.
//

#include "ConcreteType.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    ConcreteType::ConcreteType(const AbstractIdentifier* typeName) : typeName(typeName) {}

    const std::string ConcreteType::nodeName() const {
        return "ConcreteType";
    }

    const std::string ConcreteType::to_string() const {
        return typeName->to_string();
    }

    void ConcreteType::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const AbstractIdentifier* ConcreteType::getTypeName() const {
        return typeName;
    }

    ConcreteType::~ConcreteType() {

    }
}

