//
// Created by roei on 17/01/19.
//

#include "TypedIntLiteral.h"

namespace enki {
    TypedIntLiteral::TypedIntLiteral(int v) : v(v) {}

    TypedIntLiteral::~TypedIntLiteral() = default;

    const int TypedIntLiteral::getV() const {
        return v;
    }
}
