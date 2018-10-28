//
// Created by roei on 27/10/18.
//

#include "Resolver.h"
#include "expression/ResolvedIntLiteral.h"
#include "../ast/identifier/IntegerLiteral.h"
#include "../ast/identifier/TextLiteral.h"
#include "definition/ResolvedFunction.h"
#include "expression/ResolvedFuncExpr.h"

namespace enki {
    Resolver::Resolver() = default;

    const std::shared_ptr<ResolvedIntLiteral> Resolver::resolve(const std::shared_ptr<IntegerLiteral> &literal) {
        return std::make_shared<ResolvedIntLiteral>(literal->value());
    }

    const std::shared_ptr<ResolvedTextLiteral> Resolver::resolve(const std::shared_ptr<TextLiteral> &literal) {
        return std::make_shared<ResolvedTextLiteral>(literal->value());
    }

    const std::optional<std::shared_ptr<AbstractResolvedNode>> Resolver::resolve(const std::shared_ptr<AbstractIdentifier> &id) {
        for (const auto &identifier : knownIdentifiers) {
            if (id->tryUnify(reinterpret_cast<const AbstractIdentifier*>(identifier.first.get())).succeeded()) {
                return identifier.second;
            }
        }

        return std::optional<std::shared_ptr<AbstractResolvedExpr>>();
    }

    const std::shared_ptr<ResolvedFunction> Resolver::resolve(const std::shared_ptr<FuncDefinition> &func) {
        return std::shared_ptr<ResolvedFunction>();
    }

    const std::optional<std::shared_ptr<AbstractResolvedVal>> Resolver::resolveVal(const std::shared_ptr<AbstractIdentifier> &id) {
        auto definition = resolve(id);

        if (definition.has_value()) {
            if (auto func = std::dynamic_pointer_cast<ResolvedFunction>(definition.value())) {
//                return std::optional(std::make_shared<ResolvedFuncExpr>(func));
            }
        }

        return std::optional<std::shared_ptr<AbstractResolvedVal>>();
    }
}
