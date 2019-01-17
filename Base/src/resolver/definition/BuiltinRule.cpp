//
// Created by roei on 26/11/18.
//

#include "BuiltinRule.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    BuiltinRule::BuiltinRule(const AbstractIdentifier* identifier, const AbstractResolvedConstraint* constraints,
                             const std::vector<const ResolvedVarExpr*> &parameters) : ResolvedRule(identifier,
                                                                                                   constraints,
                                                                                                   parameters) {}
    BuiltinRule::~BuiltinRule() = default;

    void BuiltinRule::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const std::string BuiltinRule::nodeName() const {
        return "BuiltinRule";
    }
}
