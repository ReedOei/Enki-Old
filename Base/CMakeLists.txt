cmake_minimum_required(VERSION 3.10)
project(Base)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

find_package(Boost 1.65 COMPONENTS program_options REQUIRED)

add_executable(Base
        src/main.cpp)

add_library(BaseLibrary
        src/ast/AbstractNode.cpp
        src/ast/AbstractNode.h
        src/ast/type/AbstractType.cpp
        src/ast/type/AbstractType.h
        src/ast/type/ConcreteType.cpp
        src/ast/type/ConcreteType.h
        src/ast/type/FuncType.cpp
        src/ast/type/FuncType.h
        src/ast/type/RuleType.cpp
        src/ast/type/RuleType.h
        src/ast/type/TypeclassConstraint.cpp
        src/ast/type/TypeclassConstraint.h
        src/ast/identifier/AbstractIdentifier.cpp
        src/ast/identifier/AbstractIdentifier.h
        src/ast/identifier/VarIdentifier.cpp
        src/ast/identifier/VarIdentifier.h
        src/ast/identifier/WordIdentifier.cpp
        src/ast/identifier/WordIdentifier.h
        src/ast/identifier/SymbolIdentifier.cpp
        src/ast/identifier/SymbolIdentifier.h
        src/ast/identifier/AbstractLiteralIdentifier.cpp
        src/ast/identifier/AbstractLiteralIdentifier.h
        src/ast/identifier/IntegerLiteral.cpp
        src/ast/identifier/IntegerLiteral.h
        src/ast/toplevel/AbstractTopLevel.cpp
        src/ast/toplevel/AbstractTopLevel.h
        src/ast/toplevel/AbstractDefinition.cpp
        src/ast/toplevel/AbstractDefinition.h
        src/ast/toplevel/Runnable.cpp
        src/ast/toplevel/Runnable.h
        src/ast/toplevel/TypeclassDef.cpp
        src/ast/toplevel/TypeclassDef.h
        src/ast/toplevel/ImplementationDef.cpp
        src/ast/toplevel/ImplementationDef.h
        src/ast/Comment.cpp
        src/ast/Comment.h
        src/ast/toplevel/AbstractTypeConstructorDef.cpp
        src/ast/toplevel/AbstractTypeConstructorDef.h
        src/ast/toplevel/TypeConstructorDef.cpp
        src/ast/toplevel/TypeConstructorDef.h
        src/ast/toplevel/SumTypeConstructorDef.cpp
        src/ast/toplevel/SumTypeConstructorDef.h
        src/ast/constraints/AbstractConstraint.cpp
        src/ast/constraints/AbstractConstraint.h
        src/ast/constraints/SingletonConstraint.cpp
        src/ast/constraints/SingletonConstraint.h
        src/ast/constraints/ConjConstraint.cpp
        src/ast/constraints/ConjConstraint.h
        src/ast/constraints/WhenBranches.cpp
        src/ast/constraints/WhenBranches.h
        src/ast/constraints/WhenBranch.cpp
        src/ast/constraints/WhenBranch.h
        src/ast/toplevel/RuleDefinition.cpp
        src/ast/toplevel/RuleDefinition.h
        src/ast/toplevel/FuncDefinition.cpp
        src/ast/toplevel/FuncDefinition.h
        src/ast/identifier/CompositeIdentifier.cpp src/ast/identifier/CompositeIdentifier.h src/ast/Property.cpp src/ast/Property.h src/typechecking/TypedNode.cpp src/typechecking/TypedNode.h src/ast/NodeVisitor.cpp src/ast/NodeVisitor.h src/resolver/AbstractResolvedNode.cpp src/resolver/AbstractResolvedNode.h src/resolver/constraints/AbstractResolvedConstraint.cpp src/resolver/constraints/AbstractResolvedConstraint.h src/resolver/ResolvedNodeVisitor.cpp src/resolver/ResolvedNodeVisitor.h src/resolver/identifier/AbstractResolvedIdentifier.cpp src/resolver/identifier/AbstractResolvedIdentifier.h src/resolver/identifier/ResolvedDefinitionIdentifier.cpp src/resolver/identifier/ResolvedDefinitionIdentifier.h src/resolver/identifier/ResolvedLiteralIdentifier.cpp src/resolver/identifier/ResolvedLiteralIdentifier.h src/resolver/constraints/ResolvedSingletonConstraint.cpp src/resolver/constraints/ResolvedSingletonConstraint.h src/resolver/constraints/ResolvedConjConstraint.cpp src/resolver/constraints/ResolvedConjConstraint.h src/resolver/constraints/ResolvedWhenBranch.cpp src/resolver/constraints/ResolvedWhenBranch.h src/resolver/constraints/ResolvedWhenBranches.cpp src/resolver/constraints/ResolvedWhenBranches.h src/resolver/definition/AbstractResolvedDefinition.cpp src/resolver/definition/AbstractResolvedDefinition.h src/resolver/definition/ResolvedFunction.cpp src/resolver/definition/ResolvedFunction.h src/resolver/definition/ResolvedRule.cpp src/resolver/definition/ResolvedRule.h src/resolver/definition/ResolvedTypeclass.cpp src/resolver/definition/ResolvedTypeclass.h src/resolver/definition/ResolvedImplementation.cpp src/resolver/definition/ResolvedImplementation.h src/resolver/definition/ResolvedTypeConstructor.cpp src/resolver/definition/ResolvedTypeConstructor.h src/resolver/type/AbstractResolvedType.cpp src/resolver/type/AbstractResolvedType.h src/resolver/type/ResolvedFuncType.cpp src/resolver/type/ResolvedFuncType.h src/resolver/type/ResolvedRuleType.cpp src/resolver/type/ResolvedRuleType.h src/resolver/type/ResolvedConcreteType.cpp src/resolver/type/ResolvedConcreteType.h src/resolver/type/ResolvedTypeclassConstraint.cpp src/resolver/type/ResolvedTypeclassConstraint.h src/typechecking/TypeInferer.cpp src/typechecking/TypeInferer.h src/typechecking/TypedNodeVisitor.cpp src/typechecking/TypedNodeVisitor.h)

target_link_libraries(Base BaseLibrary)
target_link_libraries(Base Boost::program_options)

add_subdirectory(lib/rapidcheck)
add_subdirectory(test)
