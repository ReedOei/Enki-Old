//
// Created by roei on 20/10/18.
//

#include <memory>
#include <catch.hpp>

#include <rapidcheck.h>
#include <rapidcheck/catch.h>

#include <ast/identifier/IntegerLiteral.h>
#include <typechecking/TypeInferer.h>

#include "TypeInfererTest.h"

void test_basic_infer_int(int i) {
    auto node = std::make_shared<enki::IntegerLiteral>(i);

    RC_ASSERT(node->nodeName() == "IntegerLiteral");

    enki::TypeInferer inferer;

    auto typed = inferer.infer(node);

    RC_ASSERT(typed.has_value());

    RC_ASSERT(typed->getType().has_value());
    RC_ASSERT(typed->getOutType().has_value());
    RC_ASSERT_FALSE(typed->getInType().has_value());

    RC_ASSERT(typed->getType().value()->typeName() == "Int");
}

TEST_CASE("test_basic_infer_int") {
    rc::prop("test basic type inferrence for integers", test_basic_infer_int);
}
