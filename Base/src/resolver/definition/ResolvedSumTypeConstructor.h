//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDSUMTYPECONSTRUCTOR_H
#define BASE_RESOLVEDSUMTYPECONSTRUCTOR_H

#include <memory>
#include <vector>

#include "AbstractResolvedTypeConstructor.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../expression/ResolvedVarExpr.h"
#include "ResolvedTypeConstructor.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedSumTypeConstructor : public AbstractResolvedTypeConstructor {
    public:
        ResolvedSumTypeConstructor(const std::shared_ptr<AbstractIdentifier> &identifier,
                                   const std::vector<std::shared_ptr<ResolvedVarExpr>> &parameters,
                                   const std::vector<std::shared_ptr<ResolvedTypeConstructor>> &constructors);

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const std::string nodeName() const override;
        const std::string constructorTypeName() const override;

    private:
        const std::shared_ptr<AbstractIdentifier> identifier;
        const std::vector<std::shared_ptr<ResolvedVarExpr>> parameters;

        const std::vector<std::shared_ptr<ResolvedTypeConstructor>> constructors;
    };
}


#endif //BASE_RESOLVEDSUMTYPECONSTRUCTOR_H
