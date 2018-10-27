//
// Created by roei on 22/10/18.
//

#include "ResolvedIntLiteral.h"

namespace enki {
    ResolvedIntLiteral::ResolvedIntLiteral(const int v) : v(v) {}

    const std::string ResolvedIntLiteral::nodeName() const {
        return "ResolvedIntLiteral";
    }

    void ResolvedIntLiteral::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const int ResolvedIntLiteral::value() const {
        return v;
    }
}
