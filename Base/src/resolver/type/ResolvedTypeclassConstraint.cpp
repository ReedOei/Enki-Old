//
// Created by roei on 20/10/18.
//

#include "ResolvedTypeclassConstraint.h"

namespace enki {
    ResolvedTypeclassConstraint::ResolvedTypeclassConstraint(
            const std::shared_ptr<ResolvedTypeclass> &typeclass,
            const std::shared_ptr<ResolvedVarExpr> &typeVar,
            const std::shared_ptr<AbstractResolvedType> &constrainedType) : typeclass(typeclass), typeVar(typeVar),
                                                                            constrainedType(constrainedType) {}

    const std::string ResolvedTypeclassConstraint::nodeName() const {
        return "ResovledTypeclassConstraint";
    }

    const std::string ResolvedTypeclassConstraint::typeName() const {
        return typeclass->typeclassName() + " " + typeVar->getVarName() + " => " + constrainedType->typeName();
    }

    void ResolvedTypeclassConstraint::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        typeclass->accept(visitor);
        typeVar->accept(visitor);
        constrainedType->accept(visitor);
    }
}
