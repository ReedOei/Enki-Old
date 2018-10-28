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

        const std::vector<VarIdentifier*> variables() const override;

    protected:
        UnificationResult unify(const CompositeIdentifier* other) const override;

        UnificationResult unify(const IntegerLiteral* other) const override;

        UnificationResult unify(const SymbolIdentifier* other) const override;

        UnificationResult unify(const TextLiteral* other) const override;

        UnificationResult unify(const VarIdentifier* other) const override;

        UnificationResult unify(const WordIdentifier* other) const override;

    private:
        const std::string word;
    };
}

#endif //BASE_WORDIDENTIFIER_H
