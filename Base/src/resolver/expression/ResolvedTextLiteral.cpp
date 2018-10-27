//
// Created by roei on 22/10/18.
//

#include "ResolvedTextLiteral.h"

namespace enki {
    ResolvedTextLiteral::ResolvedTextLiteral(const std::string &v) : v(v) {}

    const std::string ResolvedTextLiteral::nodeName() const {
        return "ResolvedTextLiteral";
    }

    void ResolvedTextLiteral::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const std::string &ResolvedTextLiteral::value() const {
        return v;
    }
}
