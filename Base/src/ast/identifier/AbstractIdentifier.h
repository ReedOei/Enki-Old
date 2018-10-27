//
// Created by roei on 17/10/18.
//

#ifndef BASE_ABSTRACTIDENTIFIER_H
#define BASE_ABSTRACTIDENTIFIER_H

#include <memory>
#include "../AbstractNode.h"

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

        bool tryUnify(const AbstractIdentifier* other) const;

    protected:
        virtual bool canUnify(const CompositeIdentifier* other) const = 0;
        virtual bool canUnify(const IntegerLiteral* other) const = 0;
        virtual bool canUnify(const SymbolIdentifier* other) const = 0;
        virtual bool canUnify(const TextLiteral* other) const = 0;
        virtual bool canUnify(const VarIdentifier* other) const = 0;
        virtual bool canUnify(const WordIdentifier* other) const = 0;
    };
}

#endif //BASE_ABSTRACTIDENTIFIER_H
