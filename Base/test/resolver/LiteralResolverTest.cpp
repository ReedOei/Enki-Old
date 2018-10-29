#include <utility>

//
// Created by roei on 27/10/18.
//

#include <memory>
#include <catch.hpp>

#include <rapidcheck.h>
#include <rapidcheck/catch.h>
#include <ast/identifier/IntegerLiteral.h>
#include <resolver/Resolver.h>
#include <ast/identifier/TextLiteral.h>
#include <resolver/expression/ResolvedIntLiteral.h>
#include <resolver/expression/ResolvedTextLiteral.h>

#include "DefaultResolvedNodeVisitor.h"

class IntLiteralTestVisitor : public enki::DefaultResolvedNodeVisitor {
public:
    explicit IntLiteralTestVisitor(int t) : t(t) {}

    void visit(const enki::ResolvedIntLiteral &literal) override {
        visitedNodes++;
        RC_ASSERT(literal.value() == t);
    }

    int visitedNodes = 0;
    int t = 0;
};

class TextLiteralTestVisitor : public enki::DefaultResolvedNodeVisitor {
public:
    explicit TextLiteralTestVisitor(std::string str) : str(std::move(str)) {}

    void visit(const enki::ResolvedTextLiteral &literal) override {
        visitedNodes++;
        RC_ASSERT(literal.value() == str);
    }

    int visitedNodes = 0;
    const std::string str;
};

void test_basic_resolve_int(int i) {
    auto lit = new enki::IntegerLiteral(i);

    enki::Resolver resolver;

    auto resolvedLit = resolver.resolve(lit);

    IntLiteralTestVisitor visitor(i);
    resolvedLit->accept(visitor);

    RC_ASSERT(visitor.visitedNodes == 1);

    delete resolvedLit;
    delete lit;
}

void test_basic_resolve_text(const std::string &str) {
    auto lit = new enki::TextLiteral(str);

    enki::Resolver resolver;

    auto resolvedLit = resolver.resolve(lit);

    TextLiteralTestVisitor visitor(str);
    resolvedLit->accept(visitor);

    RC_ASSERT(visitor.visitedNodes == 1);

    delete resolvedLit;
    delete lit;
}

TEST_CASE("can resolve integer literals") {
rc::prop("can resolve integer literals", test_basic_resolve_int);
}

TEST_CASE("can resolve text literals") {
rc::prop("can resolve text literals", test_basic_resolve_text);
}
