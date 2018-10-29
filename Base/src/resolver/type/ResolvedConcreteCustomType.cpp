//
// Created by roei on 22/10/18.
//

#include "ResolvedConcreteCustomType.h"

namespace enki {
    ResolvedConcreteCustomType::ResolvedConcreteCustomType(const AbstractResolvedTypeConstructor* constructor,
                                                           const std::vector<const AbstractResolvedType*> &typeParameters)
            : constructor(constructor), typeParameters(typeParameters) {}

    const std::string ResolvedConcreteCustomType::nodeName() const {
        return "ResolvedConcreteCustomType";
    }

    const std::string ResolvedConcreteCustomType::typeName() const {
        return constructor->constructorTypeName();
    }

    void ResolvedConcreteCustomType::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        constructor->accept(visitor);

        for (const auto &typeParam : typeParameters) {
            typeParam->accept(visitor);
        }
    }

    const AbstractResolvedTypeConstructor* ResolvedConcreteCustomType::getConstructor() const {
        return constructor;
    }

    const std::vector<const AbstractResolvedType*> &ResolvedConcreteCustomType::getTypeParameters() const {
        return typeParameters;
    }

    ResolvedConcreteCustomType::~ResolvedConcreteCustomType() {

    }
}
