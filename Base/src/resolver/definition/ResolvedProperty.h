//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDPROPERTY_H
#define BASE_RESOLVEDPROPERTY_H

#include <vector>

#include "../AbstractResolvedNode.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../expression/ResolvedVarExpr.h"
#include "../type/AbstractResolvedType.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedProperty : public AbstractResolvedNode {
    public:
        ResolvedProperty(const std::shared_ptr<AbstractIdentifier> &identifier,
                         const std::vector<std::shared_ptr<ResolvedVarExpr>> &parameters,
                         const std::shared_ptr<AbstractResolvedType> &type);

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> identifier;

        const std::vector<std::shared_ptr<ResolvedVarExpr>> parameters;
        const std::shared_ptr<AbstractResolvedType> type;
    };
}

#endif //BASE_RESOLVEDPROPERTY_H
