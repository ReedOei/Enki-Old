//
// Created by roei on 27/10/18.
//

#ifndef BASE_DEFAULTRESOLVEDNODEVISITOR_H
#define BASE_DEFAULTRESOLVEDNODEVISITOR_H

#include <resolver/AbstractResolvedNodeVisitor.h>

namespace enki {
    class DefaultResolvedNodeVisitor : public AbstractResolvedNodeVisitor {
    public:
        void visit(const ResolvedConjConstraint &constraint) override;
        void visit(const ResolvedSingletonConstraint &constraint) override;
        void visit(const ResolvedWhenBranch &whenBranch) override;
        void visit(const ResolvedWhenBranches &whenBranches) override;

        void visit(const ResolvedFunction &function) override;
        void visit(const ResolvedImplementation &implementation) override;
        void visit(const ResolvedProperty &property) override;
        void visit(const ResolvedRule &rule) override;
        void visit(const ResolvedSumTypeConstructor &constructor) override;
        void visit(const ResolvedTypeclass &typeclass) override;
        void visit(const ResolvedTypeConstructor &constructor) override;

        void visit(const ResolvedFuncExpr &funcExpr) override;
        void visit(const ResolvedIntLiteral &literal) override;
        void visit(const ResolvedRuleExpr &ruleExpr) override;
        void visit(const ResolvedTextLiteral &literal) override;
        void visit(const ResolvedVarExpr &varExpr) override;

        void visit(const ResolvedBuiltinType &builtinType) override;
        void visit(const ResolvedConcreteCustomType &customType) override;
        void visit(const ResolvedFuncType &funcType) override;
        void visit(const ResolvedRuleType &ruleType) override;
        void visit(const ResolvedTypeclassConstraint &typeclassConstraint) override;

        void visit(const BuiltinFunction &builtinFunction) override;
        void visit(const BuiltinRule &builtinRule) override;
    };
}

#endif //BASE_DEFAULTRESOLVEDNODEVISITOR_H
