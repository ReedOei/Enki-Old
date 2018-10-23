//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDIMPLEMENTATION_H
#define BASE_RESOLVEDIMPLEMENTATION_H

#include <memory>
#include <vector>

#include "AbstractResolvedDefinition.h"
#include "ResolvedTypeclass.h"
#include "../type/AbstractResolvedType.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedImplementation : public AbstractResolvedDefinition {
    public:
        ResolvedImplementation(const std::shared_ptr<AbstractResolvedType> &implementationType,
                               const std::shared_ptr<ResolvedTypeclass> &typeclass,
                               const std::vector<std::shared_ptr<AbstractResolvedDefinition>> &definitions);

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const std::string nodeName() const override;

    private:
        const std::shared_ptr<AbstractResolvedType> implementationType;
        const std::shared_ptr<ResolvedTypeclass> typeclass;

        const std::vector<std::shared_ptr<AbstractResolvedDefinition>> definitions;
    };
}


#endif //BASE_RESOLVEDIMPLEMENTATION_H
