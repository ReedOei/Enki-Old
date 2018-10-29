//
// Created by roei on 22/10/18.
//

#include "ResolvedTypeConstructor.h"

namespace enki {
    ResolvedTypeConstructor::ResolvedTypeConstructor(const AbstractIdentifier* identifier,
                                                     const std::vector<const ResolvedVarExpr*> &parameters,
                                                     const std::vector<const ResolvedProperty*> &fields) : identifier(
            identifier), parameters(parameters), fields(fields) {}

    const std::string ResolvedTypeConstructor::nodeName() const {
        return "ResolvedTypeConstructor";
    }

    const std::string ResolvedTypeConstructor::constructorTypeName() const {
        return identifier->to_string();
    }

    void ResolvedTypeConstructor::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &param : parameters) {
            param->accept(visitor);
        }

        for (const auto &field : fields) {
            field->accept(visitor);
        }
    }

    const AbstractIdentifier* ResolvedTypeConstructor::getIdentifier() const {
        return identifier;
    }

    const std::vector<const ResolvedVarExpr*> &ResolvedTypeConstructor::getParameters() const {
        return parameters;
    }

    const std::vector<const ResolvedProperty*> &ResolvedTypeConstructor::getFields() const {
        return fields;
    }

    ResolvedTypeConstructor::~ResolvedTypeConstructor() {

    }
}
