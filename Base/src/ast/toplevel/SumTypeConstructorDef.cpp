//
// Created by roei on 18/10/18.
//

#include "SumTypeConstructorDef.h"

enki::SumTypeConstructorDef::SumTypeConstructorDef(const std::vector<enki::AbstractTypeConstructorDef*> &variants)
        : variants(variants) {}

const std::string enki::SumTypeConstructorDef::nodeName() const {
    return "SumTypeConstructorDef";
}
