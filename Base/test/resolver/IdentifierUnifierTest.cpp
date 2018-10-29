//
// Created by roei on 27/10/18.
//

#include <memory>
#include <catch.hpp>

#include <rapidcheck.h>
#include <rapidcheck/catch.h>

#include <ast/identifier/AbstractIdentifier.h>
#include <ast/identifier/IntegerLiteral.h>
#include <ast/identifier/WordIdentifier.h>
#include <ast/identifier/CompositeIdentifier.h>
#include <ast/identifier/VarIdentifier.h>
#include <ast/identifier/SymbolIdentifier.h>
#include <ast/identifier/TextLiteral.h>
#include <ast/identifier/unification/UnificationResult.h>

void different_integers_dont_unify(int a, int b) {
    RC_PRE(a != b);

    enki::IntegerLiteral aNode(a);
    enki::IntegerLiteral bNode(b);

    RC_ASSERT_FALSE(aNode.tryUnify(&bNode).succeeded());
}

void same_integers_unify(int x) {
    enki::IntegerLiteral aNode(x);
    enki::IntegerLiteral bNode(x);

    RC_ASSERT(aNode.tryUnify(&bNode).succeeded());
}

TEST_CASE("try unifying integers with integers") {
    rc::prop("different integers never unify", different_integers_dont_unify);
    rc::prop("the same integer always unifies", same_integers_unify);

    REQUIRE(true); // So catch reports success
}

void different_texts_dont_unify(const std::string a, const std::string b) {
    RC_PRE(a != b);

    enki::TextLiteral aNode(a);
    enki::TextLiteral bNode(b);

    RC_ASSERT_FALSE(aNode.tryUnify(&bNode).succeeded());
}

void same_text_unify(const std::string x) {
    enki::TextLiteral aNode(x);
    enki::TextLiteral bNode(x);

    RC_ASSERT(aNode.tryUnify(&bNode).succeeded());
}

TEST_CASE("try unifying text with text") {
    rc::prop("different texts never unify", different_texts_dont_unify);
    rc::prop("the same text always unifies", same_text_unify);

    REQUIRE(true); // So catch reports success
}

void different_words_dont_unify(const std::string a, const std::string b) {
    RC_PRE(a != b);

    enki::WordIdentifier aNode(a);
    enki::WordIdentifier bNode(b);

    RC_ASSERT_FALSE(aNode.tryUnify(&bNode).succeeded());
}

void same_word_unify(const std::string x) {
    enki::WordIdentifier aNode(x);
    enki::WordIdentifier bNode(x);

    RC_ASSERT(aNode.tryUnify(&bNode).succeeded());
}

TEST_CASE("try unifying words with words") {
    rc::prop("different words never unify", different_words_dont_unify);
    rc::prop("the same word always unifies", same_word_unify);

    REQUIRE(true); // So catch reports success
}

void different_symbols_dont_unify(const std::string a, const std::string b) {
    RC_PRE(a != b);

    enki::SymbolIdentifier aNode(a);
    enki::SymbolIdentifier bNode(b);

    RC_ASSERT_FALSE(aNode.tryUnify(&bNode).succeeded());
}

void same_symbol_unify(const std::string x) {
    enki::SymbolIdentifier aNode(x);
    enki::SymbolIdentifier bNode(x);

    RC_ASSERT(aNode.tryUnify(&bNode).succeeded());
}

TEST_CASE("try unifying symbols with symbols") {
    rc::prop("different symbols never unify", different_symbols_dont_unify);
    rc::prop("the same symbol always unifies", same_symbol_unify);

    REQUIRE(true); // So catch reports success
}

void vars_always_unify(const std::string varName,
                       const std::string otherVarName,
                       const std::string word,
                       const std::string symbol,
                       const std::string text,
                       int i) {
    enki::VarIdentifier varNode(varName);

    enki::VarIdentifier otherVarNode(otherVarName);
    enki::WordIdentifier wordNode(word);
    enki::SymbolIdentifier symbolNode(symbol);
    enki::TextLiteral textNode(text);
    enki::IntegerLiteral intNode(i);

    RC_ASSERT(varNode.tryUnify(&otherVarNode).succeeded());
    RC_ASSERT(varNode.tryUnify(&wordNode).succeeded());
    RC_ASSERT(varNode.tryUnify(&symbolNode).succeeded());
    RC_ASSERT(varNode.tryUnify(&textNode).succeeded());
    RC_ASSERT(varNode.tryUnify(&intNode).succeeded());
}

TEST_CASE("Vars will unify with anything") {
    rc::prop("vars always unify", vars_always_unify);

    REQUIRE(true); // So catch reports success
}

void never_unify_simple_ids(const std::string word,
                            const std::string symbol,
                            const std::string text,
                            int i) {
    enki::WordIdentifier wordNode(word);
    enki::SymbolIdentifier symbolNode(symbol);
    enki::TextLiteral textNode(text);
    enki::IntegerLiteral intNode(i);

    // TODO: There has to be a better way, right?
    RC_ASSERT_FALSE(wordNode.tryUnify(&symbolNode).succeeded());
    RC_ASSERT_FALSE(wordNode.tryUnify(&textNode).succeeded());
    RC_ASSERT_FALSE(wordNode.tryUnify(&intNode).succeeded());

    RC_ASSERT_FALSE(symbolNode.tryUnify(&wordNode).succeeded());
    RC_ASSERT_FALSE(symbolNode.tryUnify(&textNode).succeeded());
    RC_ASSERT_FALSE(symbolNode.tryUnify(&intNode).succeeded());

    RC_ASSERT_FALSE(textNode.tryUnify(&wordNode).succeeded());
    RC_ASSERT_FALSE(textNode.tryUnify(&symbolNode).succeeded());
    RC_ASSERT_FALSE(textNode.tryUnify(&intNode).succeeded());

    RC_ASSERT_FALSE(intNode.tryUnify(&wordNode).succeeded());
    RC_ASSERT_FALSE(intNode.tryUnify(&symbolNode).succeeded());
    RC_ASSERT_FALSE(intNode.tryUnify(&textNode).succeeded());
}

TEST_CASE("Different simple identifiers never unify") {
    rc::prop("Different simple indentifiers never unify", never_unify_simple_ids);

    REQUIRE(true); // So catch reports success
}

void same_word_composite_id_match(const std::vector<std::string> &words) {
    RC_PRE(!words.empty());

    std::vector<const enki::AbstractIdentifier*> ids;
//    std::transform(words.begin(), words.end(), std::back_inserter(ids),
//            [](auto word) { return new enki::WordIdentifier(word); });

    for (const auto word : words) {
        ids.push_back(new enki::WordIdentifier(word));
    }

    enki::CompositeIdentifier compositeIdA(ids);
    enki::CompositeIdentifier compositeIdB(ids);

    RC_ASSERT(compositeIdA.tryUnify(&compositeIdB).succeeded());

    for (const auto i : ids) {
        delete i;
    }
}

void match_with_vars(const std::vector<std::string> &words) {
    RC_PRE(!words.empty());

    std::vector<const enki::AbstractIdentifier*> ids;
    std::transform(words.begin(), words.end(), std::back_inserter(ids),
                   [](auto word) { return new enki::WordIdentifier(word); });

    std::vector<const enki::AbstractIdentifier*> aIds;
    std::transform(words.begin(), words.end(), std::back_inserter(aIds),
                   [](auto word) {
                       const auto isVar = *rc::gen::arbitrary<bool>();

                       if (isVar) {
                           const auto name = *rc::gen::arbitrary<std::string>();
                           return static_cast<const enki::AbstractIdentifier*>(new enki::VarIdentifier(name));
                       } else {
                           return static_cast<const enki::AbstractIdentifier*>(new enki::WordIdentifier(word));
                       }
                   });

    enki::CompositeIdentifier compositeIdA(aIds);
    enki::CompositeIdentifier compositeIdB(ids);

    RC_ASSERT(compositeIdA.tryUnify(&compositeIdB).succeeded());

    for (const auto i : aIds) {
        delete i;
    }
    for (const auto i : ids) {
        delete i;
    }
}

TEST_CASE("Unify composite identifiers") {
    rc::prop("Identifiers composed of the same words match", same_word_composite_id_match);
    rc::prop("Identifiers composed of the same words or variables match", match_with_vars);

    REQUIRE(true); // So catch reports success
}
