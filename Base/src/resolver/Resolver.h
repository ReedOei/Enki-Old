//
// Created by roei on 27/10/18.
//

#ifndef BASE_RESOLVER_H
#define BASE_RESOLVER_H

#include <memory>
#include "../ast/DefaultNodeVisitor.h"
#include "AbstractResolvedNode.h"
#include "expression/ResolvedIntLiteral.h"
#include "expression/ResolvedTextLiteral.h"

namespace enki {
    class Resolver {
    public:
        Resolver();

        const std::shared_ptr<ResolvedIntLiteral> resolve(const std::shared_ptr<IntegerLiteral> &literal);
        const std::shared_ptr<ResolvedTextLiteral> resolve(const std::shared_ptr<TextLiteral> &literal);
    };
}

#endif //BASE_RESOLVER_H
