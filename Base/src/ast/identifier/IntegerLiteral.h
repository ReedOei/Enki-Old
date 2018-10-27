//
// Created by roei on 18/10/18.
//

#ifndef BASE_INTEGERLITERAL_H
#define BASE_INTEGERLITERAL_H

#include "AbstractLiteralIdentifier.h"

namespace enki {
    class IntegerLiteral : public AbstractLiteralIdentifier {
    public:
        explicit IntegerLiteral(int val);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const int value() const;

    protected:
        bool canUnify(const CompositeIdentifier* other) const override;
        bool canUnify(const IntegerLiteral* other) const override;
        bool canUnify(const SymbolIdentifier* other) const override;
        bool canUnify(const TextLiteral* other) const override;
        bool canUnify(const VarIdentifier* other) const override;
        bool canUnify(const WordIdentifier* other) const override;

    private:
        const int val;
    };
}

#endif //BASE_INTEGERLITERAL_H
