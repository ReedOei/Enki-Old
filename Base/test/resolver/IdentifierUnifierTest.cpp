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

void different_integers_dont_unify(int a, int b) {
    RC_PRE(a != b);

    auto aNode = std::make_shared<enki::IntegerLiteral>(a);
    auto bNode = std::make_shared<enki::IntegerLiteral>(b);

    RC_ASSERT_FALSE(aNode->tryUnify(bNode.get()));
}

void same_integers_unify(int x) {
    auto aNode = std::make_shared<enki::IntegerLiteral>(x);
    auto bNode = std::make_shared<enki::IntegerLiteral>(x);

    RC_ASSERT(aNode->tryUnify(bNode.get()));
}

TEST_CASE("try unifying integers with integers") {
    rc::prop("different integers never unify", different_integers_dont_unify);
    rc::prop("the same integer always unifies", same_integers_unify);
}

void different_texts_dont_unify(const std::string a, const std::string b) {
    RC_PRE(a != b);

    auto aNode = std::make_shared<enki::TextLiteral>(a);
    auto bNode = std::make_shared<enki::TextLiteral>(b);

    RC_ASSERT_FALSE(aNode->tryUnify(bNode.get()));
}

void same_text_unify(const std::string x) {
    auto aNode = std::make_shared<enki::TextLiteral>(x);
    auto bNode = std::make_shared<enki::TextLiteral>(x);

    RC_ASSERT(aNode->tryUnify(bNode.get()));
}

TEST_CASE("try unifying text with text") {
    rc::prop("different texts never unify", different_texts_dont_unify);
    rc::prop("the same text always unifies", same_text_unify);
}

void different_words_dont_unify(const std::string a, const std::string b) {
    RC_PRE(a != b);

    auto aNode = std::make_shared<enki::WordIdentifier>(a);
    auto bNode = std::make_shared<enki::WordIdentifier>(b);

    RC_ASSERT_FALSE(aNode->tryUnify(bNode.get()));
}

void same_word_unify(const std::string x) {
    auto aNode = std::make_shared<enki::WordIdentifier>(x);
    auto bNode = std::make_shared<enki::WordIdentifier>(x);

    RC_ASSERT(aNode->tryUnify(bNode.get()));
}

TEST_CASE("try unifying words with words") {
    rc::prop("different words never unify", different_words_dont_unify);
    rc::prop("the same word always unifies", same_word_unify);
}

void different_symbols_dont_unify(const std::string a, const std::string b) {
    RC_PRE(a != b);

    auto aNode = std::make_shared<enki::TextLiteral>(a);
    auto bNode = std::make_shared<enki::TextLiteral>(b);

    RC_ASSERT_FALSE(aNode->tryUnify(bNode.get()));
}

void same_symbol_unify(const std::string x) {
    auto aNode = std::make_shared<enki::TextLiteral>(x);
    auto bNode = std::make_shared<enki::TextLiteral>(x);

    RC_ASSERT(aNode->tryUnify(bNode.get()));
}

TEST_CASE("try unifying symbols with symbols") {
    rc::prop("different symbols never unify", different_symbols_dont_unify);
    rc::prop("the same symbol always unifies", same_symbol_unify);
}

void vars_always_unify(const std::string varName,
                       const std::string otherVarName,
                       const std::string word,
                       const std::string symbol,
                       const std::string text,
                       int i) {
    auto varNode = std::make_shared<enki::VarIdentifier>(varName);

    auto otherVarNode = std::make_shared<enki::VarIdentifier>(otherVarName);
    auto wordNode = std::make_shared<enki::WordIdentifier>(word);
    auto symbolNode = std::make_shared<enki::SymbolIdentifier>(symbol);
    auto textNode = std::make_shared<enki::TextLiteral>(text);
    auto intNode = std::make_shared<enki::IntegerLiteral>(i);

    RC_ASSERT(varNode->tryUnify(otherVarNode.get()));
    RC_ASSERT(varNode->tryUnify(wordNode.get()));
    RC_ASSERT(varNode->tryUnify(symbolNode.get()));
    RC_ASSERT(varNode->tryUnify(textNode.get()));
    RC_ASSERT(varNode->tryUnify(intNode.get()));
}

TEST_CASE("Vars will unify with anything") {
    rc::prop("vars always unify", vars_always_unify);
}

void never_unify_simple_ids(const std::string word,
                            const std::string symbol,
                            const std::string text,
                            int i) {
    auto wordNode = std::make_shared<enki::WordIdentifier>(word);
    auto symbolNode = std::make_shared<enki::SymbolIdentifier>(symbol);
    auto textNode = std::make_shared<enki::TextLiteral>(text);
    auto intNode = std::make_shared<enki::IntegerLiteral>(i);

    // TODO: There has to be a better way, right?
    RC_ASSERT_FALSE(wordNode->tryUnify(symbolNode.get()));
    RC_ASSERT_FALSE(wordNode->tryUnify(textNode.get()));
    RC_ASSERT_FALSE(wordNode->tryUnify(intNode.get()));

    RC_ASSERT_FALSE(symbolNode->tryUnify(wordNode.get()));
    RC_ASSERT_FALSE(symbolNode->tryUnify(textNode.get()));
    RC_ASSERT_FALSE(symbolNode->tryUnify(intNode.get()));

    RC_ASSERT_FALSE(textNode->tryUnify(wordNode.get()));
    RC_ASSERT_FALSE(textNode->tryUnify(symbolNode.get()));
    RC_ASSERT_FALSE(textNode->tryUnify(intNode.get()));

    RC_ASSERT_FALSE(intNode->tryUnify(wordNode.get()));
    RC_ASSERT_FALSE(intNode->tryUnify(symbolNode.get()));
    RC_ASSERT_FALSE(intNode->tryUnify(textNode.get()));
}

TEST_CASE("Different simple identifiers never unify") {
    rc::prop("Different simple indentifiers never unify", never_unify_simple_ids);
}

void same_word_composite_id_match(const std::vector<std::string> &words) {
    RC_PRE(!words.empty());

    std::vector<std::shared_ptr<enki::AbstractIdentifier>> ids;
    std::transform(words.begin(), words.end(), std::back_inserter(ids),
            [](auto word) { return std::make_shared<enki::WordIdentifier>(word); });

    auto compositeIdA = std::make_shared<enki::CompositeIdentifier>(ids);
    auto compositeIdB = std::make_shared<enki::CompositeIdentifier>(ids);

    RC_ASSERT(compositeIdA->tryUnify(compositeIdB.get()));
}

TEST_CASE("Unify composite identifiers") {
    rc::prop("Identifiers composed of the same words match", same_word_composite_id_match);
}
