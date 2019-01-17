//
// Created by roei on 05/11/18.
//

#ifndef BASE_RESOLVERFACTORY_H
#define BASE_RESOLVERFACTORY_H

#include "Resolver.h"

namespace enki {
    class ResolverFactory {
    public:
        ResolverFactory();
        virtual ~ResolverFactory();

        Error<Resolver> create() const;

    private:
        std::vector<FuncDefinition*> functions;
    };
}


#endif //BASE_RESOLVERFACTORY_H
