//
// Created by roei on 26/11/18.
//

#ifndef BASE_BUILTINRULE_H
#define BASE_BUILTINRULE_H

#include "../../ast/identifier/AbstractIdentifier.h"
#include "ResolvedRule.h"

namespace enki {
    class BuiltinRule : public ResolvedRule {
    public:
        BuiltinRule(const AbstractIdentifier* identifier, const AbstractResolvedConstraint* constraints,
                    const std::vector<const ResolvedVarExpr*> &parameters);
        ~BuiltinRule() override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;
        const std::string nodeName() const override;
    };
}

#endif //BASE_BUILTINRULE_H
