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
#include <ast/identifier/SymbolIdentifier.h>
#include <ast/identifier/CompositeIdentifier.h>
#include <ast/identifier/VarIdentifier.h>
#include <ast/identifier/WordIdentifier.h>
#include <ast/identifier/AbstractIdentifier.h>
#include <ast/identifier/unification/UnificationResult.h>
#include <resolver/definition/ResolvedFunction.h>
#include <resolver/expression/ResolvedFuncExpr.h>
#include <resolver/Resolver.h>
#include <resolver/ResolverFactory.h>

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

    enki::ResolverFactory resolverFactory;

    auto newResolver = resolverFactory.create().ok();
    auto resolver = new enki::Resolver(*newResolver);
    auto resolved = resolver->resolve(&definition);

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
    delete resolver;
}

TEST_CASE("resolve_constant_function") {
    rc::prop("resolve_constant_function", resolve_constant_function);

    REQUIRE(true); // Just so we get a notification it passed
}

void resolve_builtin_function_mult(int a, int b) {
    enki::ResolverFactory resolverFactory;
    auto newResolver = resolverFactory.create().ok();
    auto resolver = new enki::Resolver(*newResolver);

    enki::SymbolIdentifier multSym("*");
    enki::IntegerLiteral multA(a);
    enki::IntegerLiteral multB(b);

    enki::CompositeIdentifier funcId(std::vector<const enki::AbstractIdentifier*>{&multA, &multSym, &multB});
    auto resolvedMult = resolver->resolve(&funcId);

    RC_ASSERT(resolvedMult.succeeded());

    // It must resolve to be a resolved function
    if (auto func = dynamic_cast<const enki::ResolvedFunction*>(resolvedMult.ok())) {
        RC_ASSERT(func->getParameters().size() == 2); // 2 parameters

        for (auto i = 0; i < func->getParameters().size(); i++) {
            RC_ASSERT(func->getParameters()[i]->getBinderPosition() == i);
            RC_ASSERT(func->getParameters()[i]->getBinder() == func);
        }
    } else {
        RC_FAIL("Did not resolve to be a ResolvedFuncExpr");
    }

    delete resolver;
}

TEST_CASE("resolve_builtin_function_mult") {
    rc::prop("resolve_builtin_function_mult", resolve_builtin_function_mult);

    REQUIRE(true); // Just so we get a notification it passed
}

TEST_CASE("resolve_nonexistent_function_fails") {
    enki::ResolverFactory resolverFactory;
    auto newResolver = resolverFactory.create().ok();
    auto resolver = new enki::Resolver(*newResolver);

    enki::WordIdentifier nonexistent("thisfunctiondefinitionshouldnotexisteversoresolvingitshouldfail");

    auto res = resolver->resolve(&nonexistent);

    REQUIRE(!res.succeeded());

    delete resolver;
}
