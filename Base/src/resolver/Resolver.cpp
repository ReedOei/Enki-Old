//
// Created by roei on 27/10/18.
//

#include "Resolver.h"
#include "expression/ResolvedIntLiteral.h"
#include "../ast/identifier/IntegerLiteral.h"
#include "../ast/identifier/TextLiteral.h"

namespace enki {
    Resolver::Resolver() = default;

    const std::shared_ptr<ResolvedIntLiteral> Resolver::resolve(const std::shared_ptr<IntegerLiteral> &literal) {
        return std::make_shared<ResolvedIntLiteral>(literal->value());
    }

    const std::shared_ptr<ResolvedTextLiteral> Resolver::resolve(const std::shared_ptr<TextLiteral> &literal) {
        return std::make_shared<ResolvedTextLiteral>(literal->value());
    }

    const std::shared_ptr<AbstractResolvedNode> Resolver::resolve(const std::shared_ptr<AbstractIdentifier> &id) {
        for (const auto &identifiers : knownIdentifiers) {
        }

        return std::shared_ptr<AbstractResolvedExpr>();
    }

    const std::shared_ptr<ResolvedFunction> Resolver::resolve(const std::shared_ptr<FuncDefinition> &func) {
        return std::shared_ptr<ResolvedFunction>();
    }
}
