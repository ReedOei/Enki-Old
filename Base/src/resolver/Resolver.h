//
// Created by roei on 27/10/18.
//

#ifndef BASE_RESOLVER_H
#define BASE_RESOLVER_H

#include <memory>
#include <map>

#include "../ast/DefaultNodeVisitor.h"
#include "AbstractResolvedNode.h"
#include "expression/ResolvedIntLiteral.h"
#include "expression/ResolvedTextLiteral.h"
#include "definition/AbstractResolvedDefinition.h"
#include "../ast/identifier/AbstractIdentifier.h"
#include "../util/Error.h"
#include "../ast/constraints/AbstractConstraint.h"
#include "constraints/AbstractResolvedConstraint.h"

namespace enki {
    class Resolver {
    public:
        Resolver();
        virtual ~Resolver();

        const ResolvedIntLiteral* resolve(const IntegerLiteral* literal);
        const ResolvedTextLiteral* resolve(const TextLiteral* literal);
        const Error<ResolvedFunction> resolve(const FuncDefinition* func);

        const Error<AbstractResolvedNode> resolve(const AbstractIdentifier* id);
        const Error<AbstractResolvedConstraint> resolve(const std::map<std::string, const ResolvedVarExpr*> &vars, const AbstractConstraint* constraint);
        const Error<ResolvedRule> resolveRule(const AbstractIdentifier* id);
        const Error<AbstractResolvedVal> resolveVal(const std::map<std::string, const ResolvedVarExpr*> &vars, const AbstractIdentifier* id);

        const Error<std::vector<const AbstractResolvedVal*>> resolveParameters(
                const std::map<std::string, const ResolvedVarExpr*> &vars,
                const AbstractIdentifier* callExpr,
                const AbstractIdentifier* called);

    private:
        std::map<const CompositeIdentifier*, const AbstractResolvedDefinition*> knownIdentifiers;
    };
}

#endif //BASE_RESOLVER_H
