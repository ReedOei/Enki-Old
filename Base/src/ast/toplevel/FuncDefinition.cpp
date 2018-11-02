//
// Created by roei on 18/10/18.
//

#include "FuncDefinition.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    FuncDefinition::FuncDefinition(const AbstractIdentifier* funcId, const std::optional<const AbstractConstraint*> &constraint,
                                   const AbstractIdentifier* val) : funcId(funcId), constraint(constraint), val(val) {}

    FuncDefinition::~FuncDefinition() = default;

    const std::string FuncDefinition::nodeName() const {
        return "FuncDefinition";
    }

    const std::string FuncDefinition::to_string() const {
        if (constraint.has_value()) {
            return funcId->to_string() + " is: \n" + constraint.value()->to_string() + ", and\n" + val->to_string();
        } else {
            return funcId->to_string() + " is: \n" + val->to_string();
        }
    }

    void FuncDefinition::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        funcId->accept(visitor);

        if (constraint.has_value()) {
            constraint.value()->accept(visitor);
        }

        val->accept(visitor);
    }

    const AbstractIdentifier* FuncDefinition::getFuncId() const {
        return funcId;
    }

    const std::optional<const AbstractConstraint*> FuncDefinition::getConstraint() const {
        return constraint;
    }

    const AbstractIdentifier* FuncDefinition::getVal() const {
        return val;
    }
}
