//
// Created by roei on 20/10/18.
//

#include "ResolvedTypeclassConstraint.h"

namespace enki {
    ResolvedTypeclassConstraint::ResolvedTypeclassConstraint(const ResolvedTypeclass* typeclass,
                                                             const ResolvedVarExpr* typeVar,
                                                             const AbstractResolvedType* constrainedType) : typeclass(
            typeclass), typeVar(typeVar), constrainedType(constrainedType) {}

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

    const ResolvedTypeclass* ResolvedTypeclassConstraint::getTypeclass() const {
        return typeclass;
    }

    const ResolvedVarExpr* ResolvedTypeclassConstraint::getTypeVar() const {
        return typeVar;
    }

    const AbstractResolvedType* ResolvedTypeclassConstraint::getConstrainedType() const {
        return constrainedType;
    }

    ResolvedTypeclassConstraint::~ResolvedTypeclassConstraint() {

    }
}
