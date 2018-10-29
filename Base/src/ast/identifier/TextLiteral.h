//
// Created by roei on 27/10/18.
//

#ifndef BASE_TEXTLITERAL_H
#define BASE_TEXTLITERAL_H

#include "AbstractIdentifier.h"

namespace enki {
    class TextLiteral : public AbstractIdentifier {
    public:
        explicit TextLiteral(const std::string &str);

        virtual ~TextLiteral();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::string value() const;

        const std::vector<const VarIdentifier*> variables() const override;

    protected:
        UnificationResult unify(const CompositeIdentifier* other) const override;
        UnificationResult unify(const IntegerLiteral* other) const override;
        UnificationResult unify(const SymbolIdentifier* other) const override;
        UnificationResult unify(const TextLiteral* other) const override;
        UnificationResult unify(const VarIdentifier* other) const override;
        UnificationResult unify(const WordIdentifier* other) const override;

    private:
        const std::string str;
    };
}


#endif //BASE_TEXTLITERAL_H
