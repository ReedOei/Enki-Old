//
// Created by roei on 20/10/18.
//

#include "ResolvedImplementation.h"

namespace enki {
    ResolvedImplementation::ResolvedImplementation(
            const AbstractResolvedType* implementationType,
            const ResolvedTypeclass* typeclass,
            const std::vector<const AbstractResolvedDefinition*> &definitions) : implementationType(
            implementationType), typeclass(typeclass), definitions(definitions) {}

    const std::string ResolvedImplementation::nodeName() const {
        return "ResolvedImplementation";
    }

    void ResolvedImplementation::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        implementationType->accept(visitor);
        typeclass->accept(visitor);

        for (const auto &def : definitions) {
            def->accept(visitor);
        }
    }

    const AbstractResolvedType* ResolvedImplementation::getImplementationType() const {
        return implementationType;
    }

    const ResolvedTypeclass* ResolvedImplementation::getTypeclass() const {
        return typeclass;
    }

    const std::vector<const AbstractResolvedDefinition*> &ResolvedImplementation::getDefinitions() const {
        return definitions;
    }

    ResolvedImplementation::~ResolvedImplementation() {

    }
}
