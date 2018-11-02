//
// Created by roei on 29/10/18.
//

#include <memory>
#include <catch.hpp>

#include <rapidcheck.h>
#include <rapidcheck/catch.h>
#include <ast/identifier/CompositeIdentifier.h>
#include <ast/toplevel/FuncDefinition.h>
#include <ast/identifier/IntegerLiteral.h>
#include <ast/identifier/VarIdentifier.h>
#include <ast/identifier/WordIdentifier.h>
#include <ast/identifier/unification/UnificationResult.h>
#include <resolver/definition/ResolvedFunction.h>
#include <resolver/Resolver.h>

void resolve_constant_function(const std::vector<std::string> &funcId, int c) {
    RC_PRE(!funcId.empty());

    std::vector<const enki::AbstractIdentifier*> ids;

    int varCount = 0;

    for (const auto &word : funcId) {
        const auto isVar = *rc::gen::arbitrary<bool>();

        if (isVar) {
            varCount++;
            ids.push_back(new enki::VarIdentifier(word));
        } else {
            ids.push_back(new enki::WordIdentifier(word));
        }
    }

    enki::CompositeIdentifier id(ids);

    enki::IntegerLiteral literal(c);
    enki::FuncDefinition definition(&id, std::optional<const enki::AbstractConstraint*>(), &literal);

    enki::Resolver resolver;

    auto resolved = resolver.resolve(&definition);

    RC_ASSERT(resolved.succeeded());

    RC_ASSERT(resolved.ok()->getParameters().size() == varCount);

    for (const auto param : resolved.ok()->getParameters()) {
        RC_ASSERT(param->getBinder() == resolved.ok());
    }

    auto constraints = resolved.ok()->getConstraints();
    RC_ASSERT_FALSE(constraints.has_value());

    auto resolveId = resolved.ok()->getIdentifier();
    RC_ASSERT(resolveId->tryUnify(&id).succeeded());

    auto retVal = resolved.ok()->getReturnValue();

    if (auto retValLit = dynamic_cast<const enki::ResolvedIntLiteral*>(retVal)) {
        RC_ASSERT(retValLit->value() == c);
    } else {
        RC_ASSERT(false);
    }

    for (const auto &component : ids) {
        delete component;
    }

    delete resolved.ok();
}

TEST_CASE("resolve_constant_function") {
    rc::prop("resolve_constant_function", resolve_constant_function);

    REQUIRE(true);
}
