//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDTYPECONSTRUCTOR_H
#define BASE_RESOLVEDTYPECONSTRUCTOR_H

#include <memory>
#include <vector>

#include "AbstractResolvedTypeConstructor.h"
#include "ResolvedProperty.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedTypeConstructor : public AbstractResolvedTypeConstructor {
    public:
        ResolvedTypeConstructor(const std::shared_ptr<AbstractIdentifier> &identifier,
                                const std::vector<std::shared_ptr<ResolvedVarExpr>> &parameters,
                                const std::vector<std::shared_ptr<ResolvedProperty>> &fields);

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const std::string nodeName() const override;
        const std::string constructorTypeName() const override;

    private:
        const std::shared_ptr<AbstractIdentifier> identifier;
        const std::vector<std::shared_ptr<ResolvedVarExpr>> parameters;
        const std::vector<std::shared_ptr<ResolvedProperty>> fields;
    };
}

#endif //BASE_RESOLVEDTYPECONSTRUCTOR_H
