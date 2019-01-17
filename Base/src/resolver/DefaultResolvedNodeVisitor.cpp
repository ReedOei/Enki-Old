//
// Created by roei on 22/10/18.
//

#include "DefaultResolvedNodeVisitor.h"

namespace enki {
    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedConjConstraint &constraint) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedSingletonConstraint &constraint) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedWhenBranch &whenBranch) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedWhenBranches &whenBranches) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedFunction &function) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedImplementation &implementation) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedProperty &property) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedRule &rule) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedSumTypeConstructor &constructor) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedTypeclass &typeclass) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedTypeConstructor &constructor) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedFuncExpr &funcExpr) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedIntLiteral &literal) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedRuleExpr &ruleExpr) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedTextLiteral &literal) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedVarExpr &varExpr) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedBuiltinType &builtinType) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedConcreteCustomType &customType) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedFuncType &funcType) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedRuleType &ruleType) {

    }

    template<typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const ResolvedTypeclassConstraint &typeclassConstraint) {

    }

    template <typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const BuiltinFunction &builtinFunction) {
    }

    template <typename T>
    void DefaultResolvedNodeVisitor<T>::visit(const BuiltinRule &builtinRule) {
    }

    template<typename T>
    const T &DefaultResolvedNodeVisitor<T>::visitorValue() const {
        return t;
    }

    template<typename T>
    DefaultResolvedNodeVisitor<T>::~DefaultResolvedNodeVisitor() = default;
}
