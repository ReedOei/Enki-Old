//
// Created by roei on 26/11/18.
//

#ifndef BASE_BUILTINFUNCTION_H
#define BASE_BUILTINFUNCTION_H

#include "../../ast/identifier/AbstractIdentifier.h"
#include "ResolvedFunction.h"

namespace enki {
    class BuiltinFunction : public ResolvedFunction {
    public:
        explicit BuiltinFunction(const AbstractIdentifier* identifier);
        ~BuiltinFunction() override;

    public:
        void accept(AbstractResolvedNodeVisitor &visitor) const override;
        const std::string nodeName() const override;
    };
}

#endif //BASE_BUILTINFUNCTION_H
