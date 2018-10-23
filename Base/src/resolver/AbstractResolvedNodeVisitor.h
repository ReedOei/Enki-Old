//
// Created by roei on 20/10/18.
//

#ifndef BASE_ABSTRACTRESOLVEDNODEVISITOR_H
#define BASE_ABSTRACTRESOLVEDNODEVISITOR_H

namespace enki {
    class ResolvedConjConstraint;
    class ResolvedSingletonConstraint;
    class ResolvedWhenBranch;
    class ResolvedWhenBranches;

    class ResolvedFunction;
    class ResolvedImplementation;
    class ResolvedProperty;
    class ResolvedRule;
    class ResolvedSumTypeConstructor;
    class ResolvedTypeclass;
    class ResolvedTypeConstructor;

    class ResolvedFuncExpr;
    class ResolvedIntLiteral;
    class ResolvedRuleExpr;
    class ResolvedTextLiteral;
    class ResolvedVarExpr;

    class ResolvedBuiltinType;
    class ResolvedConcreteCustomType;
    class ResolvedFuncType;
    class ResolvedRuleType;
    class ResolvedTypeclassConstraint;

    class AbstractResolvedNodeVisitor {
    public:
        // Constraints
        virtual void visit(const ResolvedConjConstraint &constraint) = 0;
        virtual void visit(const ResolvedSingletonConstraint &constraint) = 0;
        virtual void visit(const ResolvedWhenBranch &whenBranch) = 0;
        virtual void visit(const ResolvedWhenBranches &whenBranches) = 0;

        // Definitions
        virtual void visit(const ResolvedFunction &function) = 0;
        virtual void visit(const ResolvedImplementation &implementation) = 0;
        virtual void visit(const ResolvedProperty &property) = 0;
        virtual void visit(const ResolvedRule &rule) = 0;
        virtual void visit(const ResolvedSumTypeConstructor &constructor) = 0;
        virtual void visit(const ResolvedTypeclass &typeclass) = 0;
        virtual void visit(const ResolvedTypeConstructor &constructor) = 0;

        // Expressions
        virtual void visit(const ResolvedFuncExpr &funcExpr) = 0;
        virtual void visit(const ResolvedIntLiteral &literal) = 0;
        virtual void visit(const ResolvedRuleExpr &ruleExpr) = 0;
        virtual void visit(const ResolvedTextLiteral &literal) = 0;
        virtual void visit(const ResolvedVarExpr &varExpr) = 0;

        // Typesvoid
        virtual void visit(const ResolvedBuiltinType &builtinType) = 0;
        virtual void visit(const ResolvedConcreteCustomType &customType) = 0;
        virtual void visit(const ResolvedFuncType &funcType) = 0;
        virtual void visit(const ResolvedRuleType &ruleType) = 0;
        virtual void visit(const ResolvedTypeclassConstraint& typeclassConstraint) = 0;
    };
}

#endif //BASE_ABSTRACTRESOLVEDNODEVISITOR_H
