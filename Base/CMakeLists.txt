cmake_minimum_required(VERSION 3.10)
project(Base)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

find_package(Boost 1.65 COMPONENTS program_options REQUIRED)

add_executable(Base
        src/main.cpp
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
        src/ast/identifier/CompositeIdentifier.cpp src/ast/identifier/CompositeIdentifier.h src/ast/Property.cpp src/ast/Property.h)

target_link_libraries(Base Boost::program_options)

add_subdirectory(lib/rapidcheck)
add_subdirectory(test)
