//
// Created by roei on 22/10/18.
//

#include "ResolvedSumTypeConstructor.h"

namespace enki {
    ResolvedSumTypeConstructor::ResolvedSumTypeConstructor(
            const std::shared_ptr<AbstractIdentifier> &identifier,
            const std::vector<std::shared_ptr<ResolvedVarExpr>> &parameters,
            const std::vector<std::shared_ptr<ResolvedTypeConstructor>> &constructors) : identifier(identifier),
                                                                                         parameters(parameters),
                                                                                         constructors(constructors) {}

    const std::string ResolvedSumTypeConstructor::nodeName() const {
        return "ResolvedSumTypeConstructor";
    }

    const std::string ResolvedSumTypeConstructor::constructorTypeName() const {
        return "PLACEHOLDER"; // identifier->to_string();
    }

    void ResolvedSumTypeConstructor::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &param : parameters) {
            param->accept(visitor);
        }

        for (const auto &constructor : constructors) {
            constructor->accept(visitor);
        }
    }
}
