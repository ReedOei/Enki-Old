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
        ResolvedTypeclass(const std::shared_ptr<AbstractIdentifier> &implementedTypeIdentifier,
                          const std::shared_ptr<AbstractIdentifier> &identifier,
                          const std::vector<std::shared_ptr<ResolvedProperty>> &properties);

        const std::string nodeName() const override;
        const std::string typeclassName() const;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> implementedTypeIdentifier;
        const std::shared_ptr<AbstractIdentifier> identifier;

        const std::vector<std::shared_ptr<ResolvedProperty>> properties;
    };
}


#endif //BASE_RESOLVEDTYPECLASS_H
