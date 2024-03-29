cmake_minimum_required(VERSION 3.10)
project(Base)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(Boost 1.54 COMPONENTS program_options REQUIRED)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

ExternalProject_Add(
        Catch
        PREFIX ${CMAKE_BINARY_DIR}/catch
        URL https://github.com/catchorg/Catch2/releases/download/v2.4.1/catch.hpp
        DOWNLOAD_NO_EXTRACT 1
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
)

set(CTEST_MEMORYCHECK_COMMAND "/usr/bin/valgrind")
set(MEMORYCHECK_COMMAND_OPTIONS "--xml=yes --xml-file=test.xml --leak-check=full")
include(CTest)

add_executable(Base
        src/main.cpp src/util/Either.h src/util/Error.h)

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
        src/ast/identifier/CompositeIdentifier.cpp
        src/ast/identifier/CompositeIdentifier.h src/ast/Property.cpp src/ast/Property.h src/typechecking/TypedNode.cpp src/typechecking/TypedNode.h src/resolver/AbstractResolvedNode.cpp src/resolver/AbstractResolvedNode.h src/resolver/constraints/AbstractResolvedConstraint.cpp src/resolver/constraints/AbstractResolvedConstraint.h src/resolver/AbstractResolvedNodeVisitor.cpp src/resolver/AbstractResolvedNodeVisitor.h src/resolver/constraints/ResolvedSingletonConstraint.cpp src/resolver/constraints/ResolvedSingletonConstraint.h src/resolver/constraints/ResolvedConjConstraint.cpp src/resolver/constraints/ResolvedConjConstraint.h src/resolver/constraints/ResolvedWhenBranch.cpp src/resolver/constraints/ResolvedWhenBranch.h src/resolver/constraints/ResolvedWhenBranches.cpp src/resolver/constraints/ResolvedWhenBranches.h src/resolver/definition/AbstractResolvedDefinition.cpp src/resolver/definition/AbstractResolvedDefinition.h src/resolver/definition/ResolvedFunction.cpp src/resolver/definition/ResolvedFunction.h src/resolver/definition/ResolvedRule.cpp src/resolver/definition/ResolvedRule.h src/resolver/definition/ResolvedTypeclass.cpp src/resolver/definition/ResolvedTypeclass.h src/resolver/definition/ResolvedImplementation.cpp src/resolver/definition/ResolvedImplementation.h src/resolver/definition/AbstractResolvedTypeConstructor.cpp src/resolver/definition/AbstractResolvedTypeConstructor.h src/resolver/type/AbstractResolvedType.cpp src/resolver/type/AbstractResolvedType.h src/resolver/type/ResolvedFuncType.cpp src/resolver/type/ResolvedFuncType.h src/resolver/type/ResolvedRuleType.cpp src/resolver/type/ResolvedRuleType.h src/resolver/type/ResolvedTypeclassConstraint.cpp src/resolver/type/ResolvedTypeclassConstraint.h src/typechecking/TypeInferer.cpp src/typechecking/TypeInferer.h src/typechecking/TypedNodeVisitor.cpp src/typechecking/TypedNodeVisitor.h
        src/resolver/expression/ResolvedRuleExpr.cpp src/resolver/expression/ResolvedRuleExpr.h src/resolver/expression/AbstractResolvedExpr.cpp src/resolver/expression/AbstractResolvedExpr.h src/resolver/expression/AbstractResolvedVal.cpp src/resolver/expression/AbstractResolvedVal.h src/resolver/expression/ResolvedFuncExpr.cpp src/resolver/expression/ResolvedFuncExpr.h src/resolver/expression/AbstractResolvedLiteral.cpp src/resolver/expression/AbstractResolvedLiteral.h src/resolver/expression/ResolvedVarExpr.cpp src/resolver/expression/ResolvedVarExpr.h src/resolver/definition/ResolvedProperty.cpp src/resolver/definition/ResolvedProperty.h src/resolver/definition/ResolvedTypeConstructor.cpp src/resolver/definition/ResolvedTypeConstructor.h src/resolver/definition/ResolvedSumTypeConstructor.cpp src/resolver/definition/ResolvedSumTypeConstructor.h src/resolver/expression/ResolvedIntLiteral.cpp src/resolver/expression/ResolvedIntLiteral.h src/resolver/expression/ResolvedTextLiteral.cpp src/resolver/expression/ResolvedTextLiteral.h src/resolver/type/ResolvedBuiltinType.cpp src/resolver/type/ResolvedBuiltinType.h src/resolver/type/ResolvedConcreteCustomType.cpp src/resolver/type/ResolvedConcreteCustomType.h src/resolver/DefaultResolvedNodeVisitor.cpp src/resolver/DefaultResolvedNodeVisitor.h src/ast/AbstractNodeVisitor.cpp src/ast/AbstractNodeVisitor.h src/ast/DefaultNodeVisitor.cpp src/ast/DefaultNodeVisitor.h src/resolver/Resolver.cpp src/resolver/Resolver.h src/ast/identifier/TextLiteral.cpp src/ast/identifier/TextLiteral.h
        src/ast/identifier/unification/UnificationResult.cpp src/ast/identifier/unification/UnificationResult.h src/resolver/ResolverFactory.cpp src/resolver/ResolverFactory.h
        src/resolver/definition/BuiltinFunction.cpp src/resolver/definition/BuiltinFunction.h src/resolver/definition/BuiltinRule.cpp src/resolver/definition/BuiltinRule.h)

target_link_libraries(Base BaseLibrary)
target_link_libraries(Base Boost::program_options)

add_subdirectory(lib/rapidcheck)
add_subdirectory(test)
