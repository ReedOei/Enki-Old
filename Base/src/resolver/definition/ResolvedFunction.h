//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDFUNCTION_H
#define BASE_RESOLVEDFUNCTION_H

#include <memory>
#include <optional>
#include <vector>

#include "AbstractResolvedDefinition.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../constraints/AbstractResolvedConstraint.h"
#include "../expression/ResolvedVarExpr.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedFunction : public AbstractResolvedDefinition {
    public:
        ResolvedFunction(const std::shared_ptr<AbstractIdentifier> &identifier,
                         const std::optional<std::shared_ptr<AbstractResolvedConstraint>> &constraints,
                         const std::shared_ptr<AbstractResolvedVal> &returnValue,
                         const std::vector<std::shared_ptr<ResolvedVarExpr>> &parameters);

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> identifier;

        const std::optional<std::shared_ptr<AbstractResolvedConstraint>> constraints;
        const std::shared_ptr<AbstractResolvedVal> returnValue;

        const std::vector<std::shared_ptr<ResolvedVarExpr>> parameters;
    };
}

#endif //BASE_RESOLVEDFUNCTION_H
