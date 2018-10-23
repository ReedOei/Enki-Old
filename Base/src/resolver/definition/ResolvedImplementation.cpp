//
// Created by roei on 20/10/18.
//

#include "ResolvedImplementation.h"

namespace enki {
    ResolvedImplementation::ResolvedImplementation(
            const std::shared_ptr<AbstractResolvedType> &implementationType,
            const std::shared_ptr<ResolvedTypeclass> &typeclass,
            const std::vector<std::shared_ptr<AbstractResolvedDefinition>> &definitions) : implementationType(
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
}
