//
// Created by roei on 18/10/18.
//

#ifndef BASE_WORDIDENTIFIER_H
#define BASE_WORDIDENTIFIER_H

#include "AbstractIdentifier.h"

namespace enki {
    class WordIdentifier : public AbstractIdentifier {
    public:
        explicit WordIdentifier(const std::string &word);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::string &value() const;

    protected:
        bool canUnify(const CompositeIdentifier* other) const override;
        bool canUnify(const IntegerLiteral* other) const override;
        bool canUnify(const SymbolIdentifier* other) const override;
        bool canUnify(const TextLiteral* other) const override;
        bool canUnify(const VarIdentifier* other) const override;
        bool canUnify(const WordIdentifier* other) const override;

    private:
        const std::string word;
    };
}

#endif //BASE_WORDIDENTIFIER_H
