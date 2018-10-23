//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDTYPECLASSCONSTRAINT_H
#define BASE_RESOLVEDTYPECLASSCONSTRAINT_H

#include "AbstractResolvedType.h"
#include "../definition/ResolvedTypeclass.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedTypeclassConstraint : public AbstractResolvedType {
    public:
        ResolvedTypeclassConstraint(const std::shared_ptr<ResolvedTypeclass> &typeclass,
                                    const std::shared_ptr<ResolvedVarExpr> &typeVar,
                                    const std::shared_ptr<AbstractResolvedType> &constrainedType);

        const std::string nodeName() const override;
        const std::string typeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<ResolvedTypeclass> typeclass;
        const std::shared_ptr<ResolvedVarExpr> typeVar;

        const std::shared_ptr<AbstractResolvedType> constrainedType;
    };
}


#endif //BASE_RESOLVEDTYPECLASSCONSTRAINT_H
