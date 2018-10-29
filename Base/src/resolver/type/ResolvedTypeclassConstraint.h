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
        ResolvedTypeclassConstraint(const ResolvedTypeclass* typeclass, const ResolvedVarExpr* typeVar,
                                    const AbstractResolvedType* constrainedType);

        virtual ~ResolvedTypeclassConstraint();

        const std::string nodeName() const override;
        const std::string typeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const ResolvedTypeclass* getTypeclass() const;
        const ResolvedVarExpr* getTypeVar() const;
        const AbstractResolvedType* getConstrainedType() const;

    private:
        const ResolvedTypeclass* typeclass;
        const ResolvedVarExpr* typeVar;

        const AbstractResolvedType* constrainedType;
    };
}


#endif //BASE_RESOLVEDTYPECLASSCONSTRAINT_H
