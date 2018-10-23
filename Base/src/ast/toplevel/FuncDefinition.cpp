//
// Created by roei on 18/10/18.
//

#include "FuncDefinition.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    FuncDefinition::FuncDefinition(const std::shared_ptr<AbstractIdentifier> &funcId,
                                   const std::shared_ptr<AbstractConstraint> &constraint) : funcId(funcId),
                                                                                            constraint(constraint) {}

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
}
