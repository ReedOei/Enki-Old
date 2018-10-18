//
// Created by roei on 18/10/18.
//

#include "Comment.h"

const std::string & enki::Comment::string() const {
    return str;
}

enki::Comment::Comment(const std::string &str) : str(str) {}

const std::string enki::Comment::nodeName() const {
    return "Comment";
}
