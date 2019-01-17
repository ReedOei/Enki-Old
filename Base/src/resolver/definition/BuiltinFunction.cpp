//
// Created by roei on 26/11/18.
//

#include "BuiltinFunction.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    BuiltinFunction::BuiltinFunction(const AbstractIdentifier* identifier) : ResolvedFunction(identifier) {}
    BuiltinFunction::~BuiltinFunction() = default;

    void BuiltinFunction::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);
    }

    const std::string BuiltinFunction::nodeName() const {
        return "BuiltinFunction";
    }
}
