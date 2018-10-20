//
// Created by roei on 18/10/18.
//

#include "IntegerLiteral.h"

enki::IntegerLiteral::IntegerLiteral(int val) : val(val) {}

const std::string enki::IntegerLiteral::nodeName() const {
    return "IntegerLiteral";
}

const int enki::IntegerLiteral::getVal() const {
    return val;
}

enki::IntegerLiteral::IntegerLiteral(const enki::IntegerLiteral &literal) : val(literal.val) {}

enki::IntegerLiteral::~IntegerLiteral() = default;
