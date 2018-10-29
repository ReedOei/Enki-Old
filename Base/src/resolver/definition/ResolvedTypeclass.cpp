//
// Created by roei on 20/10/18.
//

#include "ResolvedTypeclass.h"

namespace enki {
    ResolvedTypeclass::ResolvedTypeclass(const AbstractIdentifier* implementedTypeIdentifier,
                                         const AbstractIdentifier* identifier,
                                         const std::vector<const ResolvedProperty*> &properties)
            : implementedTypeIdentifier(implementedTypeIdentifier), identifier(identifier), properties(properties) {}

    const std::string ResolvedTypeclass::nodeName() const {
        return "ResolvedTypeclass";
    }

    const std::string ResolvedTypeclass::typeclassName() const {
        return identifier->to_string();
    }

    void ResolvedTypeclass::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &property : properties) {
            property->accept(visitor);
        }
    }

    const AbstractIdentifier* ResolvedTypeclass::getImplementedTypeIdentifier() const {
        return implementedTypeIdentifier;
    }

    const AbstractIdentifier* ResolvedTypeclass::getIdentifier() const {
        return identifier;
    }

    const std::vector<const ResolvedProperty*> &ResolvedTypeclass::getProperties() const {
        return properties;
    }

    ResolvedTypeclass::~ResolvedTypeclass() {

    }

}
