//
// Created by roei on 20/10/18.
//

#include "ResolvedTypeclass.h"

namespace enki {
    ResolvedTypeclass::ResolvedTypeclass(const std::shared_ptr<AbstractIdentifier> &implementedTypeIdentifier,
                                         const std::shared_ptr<AbstractIdentifier> &identifier,
                                         const std::vector<std::shared_ptr<ResolvedProperty>> &properties)
            : implementedTypeIdentifier(implementedTypeIdentifier), identifier(identifier), properties(properties) {}

    const std::string ResolvedTypeclass::nodeName() const {
        return "ResolvedTypeclass";
    }

    const std::string ResolvedTypeclass::typeclassName() const {
        return "PLACEHOLDER"; // identifier->to_string();
    }

    void ResolvedTypeclass::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &property : properties) {
            property->accept(visitor);
        }
    }
}
