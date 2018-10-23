//
// Created by roei on 17/10/18.
//

#include "TypeclassConstraint.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    TypeclassConstraint::TypeclassConstraint(const std::shared_ptr<AbstractIdentifier> &typeclassId,
                                             const std::shared_ptr<AbstractIdentifier> &typevarId,
                                             const std::shared_ptr<AbstractType> &type) : typeclassId(typeclassId),
                                                                                          typevarId(typevarId),
                                                                                          type(type) {}

    const std::string TypeclassConstraint::nodeName() const {
        return "TypeclassConstraint";
    }

    const std::string TypeclassConstraint::to_string() const {
        return typeclassId->to_string() + " " + typevarId->to_string() + " => " + type->to_string();
    }

    void TypeclassConstraint::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        typeclassId->accept(visitor);
        typevarId->accept(visitor);
        type->accept(visitor);
    }
}
