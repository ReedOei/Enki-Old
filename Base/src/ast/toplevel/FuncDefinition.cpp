//
// Created by roei on 18/10/18.
//

#include "FuncDefinition.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    FuncDefinition::FuncDefinition(const AbstractIdentifier* funcId, const AbstractConstraint* constraint,
                                   const AbstractIdentifier* val) : funcId(funcId), constraint(constraint), val(val) {}

    const std::string FuncDefinition::nodeName() const {
        return "FuncDefinition";
    }

    const std::string FuncDefinition::to_string() const {
        return funcId->to_string() + " is: \n" + constraint->to_string();
    }

    void FuncDefinition::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        funcId->accept(visitor);
        constraint->accept(visitor);
    }

    const AbstractIdentifier* FuncDefinition::getFuncId() const {
        return funcId;
    }

    const AbstractConstraint* FuncDefinition::getConstraint() const {
        return constraint;
    }

    const AbstractIdentifier* FuncDefinition::getVal() const {
        return val;
    }

    FuncDefinition::~FuncDefinition() {

    }
}
