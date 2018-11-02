//
// Created by roei on 17/10/18.
//

#ifndef BASE_ABSTRACTIDENTIFIER_H
#define BASE_ABSTRACTIDENTIFIER_H

#include <memory>
#include <vector>
#include <optional>

#include "../AbstractNode.h"
#include "unification/UnificationResult.h"

namespace enki {
    class CompositeIdentifier;
    class IntegerLiteral;
    class SymbolIdentifier;
    class TextLiteral;
    class VarIdentifier;
    class WordIdentifier;

    class AbstractIdentifier : public AbstractNode {
    public:
        AbstractIdentifier();
        ~AbstractIdentifier() override;

        UnificationResult tryUnify(const AbstractIdentifier* other) const;

        virtual const std::vector<const VarIdentifier*> variables() const = 0;

    protected:
        virtual UnificationResult unify(const CompositeIdentifier* other) const = 0;
        virtual UnificationResult unify(const IntegerLiteral* other) const = 0;
        virtual UnificationResult unify(const SymbolIdentifier* other) const = 0;
        virtual UnificationResult unify(const TextLiteral* other) const = 0;
        virtual UnificationResult unify(const VarIdentifier* other) const = 0;
        virtual UnificationResult unify(const WordIdentifier* other) const = 0;
    };
}

#endif //BASE_ABSTRACTIDENTIFIER_H
