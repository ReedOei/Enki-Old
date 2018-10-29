//
// Created by roei on 18/10/18.
//

#include "Property.h"
#include "AbstractNodeVisitor.h"

namespace enki {
    Property::Property(const AbstractIdentifier* name, const AbstractType* type) : name(name), type(type) {}

    const std::string Property::nodeName() const {
        return "Property";
    }

    const std::string Property::to_string() const {
        return name->to_string() + " : " + type->to_string();
    }

    void Property::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        name->accept(visitor);
        type->accept(visitor);
    }

    const AbstractIdentifier* Property::getName() const {
        return name;
    }

    const AbstractType* Property::getType() const {
        return type;
    }

    Property::~Property() {

    }
}
