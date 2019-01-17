//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDRULE_H
#define BASE_RESOLVEDRULE_H

#include <memory>
#include <vector>
#include "AbstractResolvedDefinition.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../constraints/AbstractResolvedConstraint.h"
#include "../expression/ResolvedVarExpr.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedRule : public AbstractResolvedDefinition {
    public:
        ResolvedRule(const AbstractIdentifier* identifier, const AbstractResolvedConstraint* constraints,
                     const std::vector<const ResolvedVarExpr*> &parameters);
        ~ResolvedRule() override;

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const AbstractIdentifier* getIdentifier() const;
        const AbstractResolvedConstraint* getConstraints() const;
        const std::vector<const ResolvedVarExpr*> &getParameters() const;

    private:
        const AbstractIdentifier* identifier;
        const AbstractResolvedConstraint* constraints;
        const std::vector<const ResolvedVarExpr*> parameters;
    };
}

#endif //BASE_RESOLVEDRULE_H
