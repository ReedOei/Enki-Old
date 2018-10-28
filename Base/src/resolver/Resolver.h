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

namespace enki {
    class Resolver {
    public:
        Resolver();

        const std::shared_ptr<ResolvedIntLiteral> resolve(const std::shared_ptr<IntegerLiteral> &literal);
        const std::shared_ptr<ResolvedTextLiteral> resolve(const std::shared_ptr<TextLiteral> &literal);
        const std::shared_ptr<ResolvedFunction> resolve(const std::shared_ptr<FuncDefinition> &func);

        const std::optional<std::shared_ptr<AbstractResolvedNode>> resolve(const std::shared_ptr<AbstractIdentifier> &id);

        const std::optional<std::shared_ptr<AbstractResolvedVal>> resolveVal(const std::shared_ptr<AbstractIdentifier> &id);

    private:
        std::map<std::shared_ptr<CompositeIdentifier>, std::shared_ptr<AbstractResolvedDefinition>> knownIdentifiers;
    };
}

#endif //BASE_RESOLVER_H
