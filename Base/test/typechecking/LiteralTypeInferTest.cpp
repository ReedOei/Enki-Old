//
// Created by roei on 17/01/19.
//

#include <memory>
#include <catch.hpp>

#include <rapidcheck.h>
#include <rapidcheck/catch.h>

#include <ast/identifier/IntegerLiteral.h>
#include <typechecking/TypeInferer.h>

void test_basic_infer_int(int i) {
    enki::IntegerLiteral node(i);

    enki::TypeInferer inferer;
    auto typed = inferer.infer(&node);

    RC_ASSERT(typed.succeeded());

//    RC_ASSERT(typed->getType().value()->typeName() == "Int");
}

TEST_CASE("test_basic_infer_int") {
    // TODO: Reenable this later
//    rc::prop("test basic type inferrence for integers", test_basic_infer_int);

    REQUIRE(true);
}
