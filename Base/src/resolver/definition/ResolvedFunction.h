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

namespace enki {
    class Resolver;

    const ResolvedFunction* createFunction(Resolver &resolver, const FuncDefinition* funcDef);

    class ResolvedFunction : public AbstractResolvedDefinition {
    public:
        virtual ~ResolvedFunction();

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        friend const ResolvedFunction* createFunction(Resolver &resolver, const FuncDefinition* funcDef);

        const AbstractIdentifier* getIdentifier() const;
        const std::optional<const AbstractResolvedConstraint*> &getConstraints() const;
        AbstractResolvedVal* getReturnValue() const;
        const std::vector<const ResolvedVarExpr*> &getParameters() const;

    private:
        explicit ResolvedFunction(const AbstractIdentifier* identifier);

        const AbstractIdentifier* identifier;

        std::optional<const AbstractResolvedConstraint*> constraints;
        AbstractResolvedVal* returnValue;

        std::vector<const ResolvedVarExpr*> parameters;
    };
}

#endif //BASE_RESOLVEDFUNCTION_H
