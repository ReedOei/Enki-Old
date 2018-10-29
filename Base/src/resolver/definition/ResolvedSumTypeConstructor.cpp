//
// Created by roei on 22/10/18.
//

#include "ResolvedSumTypeConstructor.h"

namespace enki {
    ResolvedSumTypeConstructor::ResolvedSumTypeConstructor(const AbstractIdentifier* identifier,
                                                           const std::vector<const ResolvedVarExpr*> &parameters,
                                                           const std::vector<const ResolvedTypeConstructor*> &constructors)
            : identifier(identifier), parameters(parameters), constructors(constructors) {}

    const std::string ResolvedSumTypeConstructor::nodeName() const {
        return "ResolvedSumTypeConstructor";
    }

    const std::string ResolvedSumTypeConstructor::constructorTypeName() const {
        return identifier->to_string();
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

    const AbstractIdentifier* ResolvedSumTypeConstructor::getIdentifier() const {
        return identifier;
    }

    const std::vector<const ResolvedVarExpr*> &ResolvedSumTypeConstructor::getParameters() const {
        return parameters;
    }

    const std::vector<const ResolvedTypeConstructor*> &ResolvedSumTypeConstructor::getConstructors() const {
        return constructors;
    }

    ResolvedSumTypeConstructor::~ResolvedSumTypeConstructor() {

    }
}
