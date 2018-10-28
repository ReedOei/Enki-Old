//
// Created by roei on 18/10/18.
//

#ifndef BASE_VARIDENITIFIER_H
#define BASE_VARIDENITIFIER_H

#include "AbstractIdentifier.h"

namespace enki {
    class VarIdentifier : public AbstractIdentifier {
    public:
        explicit VarIdentifier(const std::string &varName);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::string value() const;

        const std::vector<VarIdentifier*> variables() const override;

    protected:
        UnificationResult unify(const CompositeIdentifier* other) const override;
        UnificationResult unify(const IntegerLiteral* other) const override;
        UnificationResult unify(const SymbolIdentifier* other) const override;
        UnificationResult unify(const TextLiteral* other) const override;
        UnificationResult unify(const VarIdentifier* other) const override;
        UnificationResult unify(const WordIdentifier* other) const override;

    private:
        const std::string varName;
    };
}

#endif //BASE_VARIDENITIFIER_H
