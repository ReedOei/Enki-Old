//
// Created by roei on 17/10/18.
//

#include "FuncType.h"

enki::FuncType::FuncType(const enki::AbstractType &inType, const enki::AbstractType &utType) : inType(inType),
                                                                                               outType(outType) {}

const std::string enki::FuncType::nodeName() const {
    return "FuncType";
}
