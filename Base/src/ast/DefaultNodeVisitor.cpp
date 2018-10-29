//
// Created by roei on 23/10/18.
//

#include "DefaultNodeVisitor.h"

namespace enki {
    template<typename T>
    DefaultNodeVisitor<T>::DefaultNodeVisitor(T t) : t(t) {}

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const ConjConstraint &constraint) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const SingletonConstraint &constraint) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const WhenBranch &branch) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const WhenBranches &branches) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const CompositeIdentifier &identifier) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const TextLiteral &literal) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const IntegerLiteral &literal) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const SymbolIdentifier &symbol) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const VarIdentifier &varName) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const WordIdentifier &word) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const FuncDefinition &func) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const ImplementationDef &implementation) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const RuleDefinition &rule) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const Runnable &runnable) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const SumTypeConstructorDef &sumTypeConstructor) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const TypeclassDef &typeclass) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const TypeConstructorDef &typeConstructor) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const ConcreteType &concreteType) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const FuncType &funcType) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const RuleType &ruleType) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const TypeclassConstraint &typeclassConstraint) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const Comment &comment) {

    }

    template<typename T>
    void DefaultNodeVisitor<T>::visit(const Property &property) {

    }

    template<typename T>
    DefaultNodeVisitor<T>::~DefaultNodeVisitor() {

    }
}
