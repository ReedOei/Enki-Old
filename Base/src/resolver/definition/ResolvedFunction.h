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
#include "../../ast/toplevel/FuncDefinition.h"
#include "../../util/Error.h"

namespace enki {
    class Resolver;

    const Error<ResolvedFunction> createFunction(Resolver &resolver, const FuncDefinition* funcDef);

    class ResolvedFunction : public AbstractResolvedDefinition {
    public:
        ~ResolvedFunction() override;

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        friend const Error<ResolvedFunction> createFunction(Resolver &resolver, const FuncDefinition* funcDef);

        const AbstractIdentifier* getIdentifier() const;
        const std::optional<const AbstractResolvedConstraint*> &getConstraints() const;
        const AbstractResolvedVal* getReturnValue() const;
        const std::vector<const ResolvedVarExpr*> &getParameters() const;

    private:

        const AbstractIdentifier* identifier;

        std::optional<const AbstractResolvedConstraint*> constraints;
        const AbstractResolvedVal* returnValue;

        std::vector<const ResolvedVarExpr*> parameters;
    protected:
        explicit ResolvedFunction(const AbstractIdentifier* identifier);
    };
}

#endif //BASE_RESOLVEDFUNCTION_H
