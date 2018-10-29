//
// Created by roei on 23/10/18.
//

#ifndef BASE_ABSTRACTNODEVISITOR_H
#define BASE_ABSTRACTNODEVISITOR_H

namespace enki {
    class ConjConstraint;
    class SingletonConstraint;
    class WhenBranch;
    class WhenBranches;
    class CompositeIdentifier;
    class IntegerLiteral;
    class TextLiteral;
    class SymbolIdentifier;
    class VarIdentifier;
    class WordIdentifier;
    class FuncDefinition;
    class ImplementationDef;
    class RuleDefinition;
    class Runnable;
    class SumTypeConstructorDef;
    class TypeclassDef;
    class TypeConstructorDef;
    class ConcreteType;
    class FuncType;
    class RuleType;
    class TypeclassConstraint;
    class Comment;
    class Property;

    class AbstractNodeVisitor {
    public:
        virtual ~AbstractNodeVisitor();

        // Constraints
        virtual void visit(const ConjConstraint &constraint) = 0;
        virtual void visit(const SingletonConstraint &constraint) = 0;
        virtual void visit(const WhenBranch &branch) = 0;
        virtual void visit(const WhenBranches &branches) = 0;

        // Identifiers
        virtual void visit(const CompositeIdentifier &identifier) = 0;
        virtual void visit(const IntegerLiteral &literal) = 0;
        virtual void visit(const TextLiteral &literal) = 0;
        virtual void visit(const SymbolIdentifier &symbol) = 0;
        virtual void visit(const VarIdentifier &varName) = 0;
        virtual void visit(const WordIdentifier &word) = 0;

        // Definitions
        virtual void visit(const FuncDefinition &func) = 0;
        virtual void visit(const ImplementationDef &implementation) = 0;
        virtual void visit(const RuleDefinition &rule) = 0;
        virtual void visit(const Runnable &runnable) = 0;
        virtual void visit(const SumTypeConstructorDef &sumTypeConstructor) = 0;
        virtual void visit(const TypeclassDef &typeclass) = 0;
        virtual void visit(const TypeConstructorDef &typeConstructor) = 0;

        // Types
        virtual void visit(const ConcreteType &concreteType) = 0;
        virtual void visit(const FuncType &funcType) = 0;
        virtual void visit(const RuleType &ruleType) = 0;
        virtual void visit(const TypeclassConstraint &typeclassConstraint) = 0;

        // Misc
        virtual void visit(const Comment &comment) = 0;
        virtual void visit(const Property &property) = 0;
    };
}

#endif //BASE_ABSTRACTNODEVISITOR_H
