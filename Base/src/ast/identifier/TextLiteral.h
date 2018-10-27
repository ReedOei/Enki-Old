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

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::string value() const;

    protected:
        bool canUnify(const CompositeIdentifier* other) const override;
        bool canUnify(const IntegerLiteral* other) const override;
        bool canUnify(const SymbolIdentifier* other) const override;
        bool canUnify(const TextLiteral* other) const override;
        bool canUnify(const VarIdentifier* other) const override;
        bool canUnify(const WordIdentifier* other) const override;

    private:
        const std::string str;
    };
}


#endif //BASE_TEXTLITERAL_H
