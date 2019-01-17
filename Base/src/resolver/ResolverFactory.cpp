//
// Created by roei on 05/11/18.
//

#include "ResolverFactory.h"
#include "../ast/toplevel/FuncDefinition.h"
#include "../ast/identifier/WordIdentifier.h"
#include "../ast/identifier/CompositeIdentifier.h"
#include "../ast/identifier/VarIdentifier.h"
#include "../ast/identifier/SymbolIdentifier.h"

namespace enki {
    ResolverFactory::ResolverFactory() {
        auto builtinFunctionName = new WordIdentifier("__builtin_function");

        // multiplication
        auto multSym = new SymbolIdentifier("*");
        auto multA = new VarIdentifier("A");
        auto multB = new VarIdentifier("B");
        auto multName = new CompositeIdentifier(std::vector<const AbstractIdentifier*>{multA, multSym, multB});

        auto multBuiltinName = new WordIdentifier("mult_op");
        auto multRetVal = new CompositeIdentifier(std::vector<const AbstractIdentifier*>{builtinFunctionName, multBuiltinName, multA, multB});

        auto newFunc = new FuncDefinition(multName, std::optional<const AbstractConstraint*>(), multRetVal);

        functions.push_back(newFunc);
    }

    ResolverFactory::~ResolverFactory() {
        for (const auto func : functions) {
            delete func;
        }
    }

    Error<Resolver> ResolverFactory::create() const {
        auto resolver = new Resolver();

        for (const auto func : functions) {
            auto resolvedFunc = resolver->resolve(func);

            if (!resolvedFunc.succeeded()) {
                return Error<Resolver>("Failed to resolve built-in function: " + func->getFuncId()->to_string());
            }
        }

        return Error(resolver);
    }
}
