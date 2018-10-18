//
// Created by roei on 18/10/18.
//

#include "WordIdentifier.h"

enki::WordIdentifier::WordIdentifier(const std::string &word) : word(word) {}

const std::string enki::WordIdentifier::nodeName() const {
    return "WordIdentifier";
}
