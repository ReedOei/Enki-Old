//
// Created by roei on 23/10/18.
//

#ifndef BASE_DEFAULTNODEVISITOR_H
#define BASE_DEFAULTNODEVISITOR_H

#include "AbstractNodeVisitor.h"

namespace enki {
    template <typename T>
    class DefaultNodeVisitor : public AbstractNodeVisitor {
    public:
        explicit DefaultNodeVisitor(T t);

        void visit(const ConjConstraint &constraint) override;
        void visit(const SingletonConstraint &constraint) override;
        void visit(const WhenBranch &branch) override;
        void visit(const WhenBranches &branches) override;

        void visit(const CompositeIdentifier &identifier) override;
        void visit(const IntegerLiteral &literal) override;
        void visit(const TextLiteral &literal) override;
        void visit(const SymbolIdentifier &symbol) override;
        void visit(const VarIdentifier &varName) override;
        void visit(const WordIdentifier &word) override;

        void visit(const FuncDefinition &func) override;
        void visit(const ImplementationDef &implementation) override;
        void visit(const RuleDefinition &rule) override;
        void visit(const Runnable &runnable) override;
        void visit(const SumTypeConstructorDef &sumTypeConstructor) override;
        void visit(const TypeclassDef &typeclass) override;
        void visit(const TypeConstructorDef &typeConstructor) override;

        void visit(const ConcreteType &concreteType) override;
        void visit(const FuncType &funcType) override;
        void visit(const RuleType &ruleType) override;
        void visit(const TypeclassConstraint &typeclassConstraint) override;

        void visit(const Comment &comment) override;
        void visit(const Property &property) override;

    private:
        T t;
    };
}

#endif //BASE_DEFAULTNODEVISITOR_H
