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

namespace enki {
    class Resolver {
    public:
        Resolver();

        virtual ~Resolver();

        const ResolvedIntLiteral* resolve(const IntegerLiteral* literal);
        const ResolvedTextLiteral* resolve(const TextLiteral* literal);
        const ResolvedFunction* resolve(const FuncDefinition* func);

        const Error<AbstractResolvedNode> resolve(const AbstractIdentifier *id);

        const Error<AbstractResolvedVal> resolveVal(const AbstractIdentifier *id);

    private:
        std::map<const CompositeIdentifier*, const AbstractResolvedDefinition*> knownIdentifiers;
    };
}

#endif //BASE_RESOLVER_H
