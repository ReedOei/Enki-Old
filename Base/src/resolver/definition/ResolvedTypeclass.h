//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDTYPECLASS_H
#define BASE_RESOLVEDTYPECLASS_H

#include <memory>
#include <vector>

#include "AbstractResolvedDefinition.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "ResolvedProperty.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedTypeclass : public AbstractResolvedDefinition {
    public:
        ResolvedTypeclass(const AbstractIdentifier* implementedTypeIdentifier, const AbstractIdentifier* identifier,
                          const std::vector<const ResolvedProperty*> &properties);

        virtual ~ResolvedTypeclass();

        const std::string nodeName() const override;
        const std::string typeclassName() const;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const AbstractIdentifier* getImplementedTypeIdentifier() const;
        const AbstractIdentifier* getIdentifier() const;
        const std::vector<const ResolvedProperty*> &getProperties() const;

    private:
        const AbstractIdentifier* implementedTypeIdentifier;
        const AbstractIdentifier* identifier;

        const std::vector<const ResolvedProperty*> properties;
    };
}


#endif //BASE_RESOLVEDTYPECLASS_H
