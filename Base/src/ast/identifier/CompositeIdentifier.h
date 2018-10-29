//
// Created by roei on 18/10/18.
//

#ifndef BASE_COMPOSITEIDENTIFIER_H
#define BASE_COMPOSITEIDENTIFIER_H

#include <vector>
#include <memory>
#include "AbstractIdentifier.h"

namespace enki {
    class CompositeIdentifier : public AbstractIdentifier {
    public:
        explicit CompositeIdentifier(const std::vector<const AbstractIdentifier*> &identifiers);
        ~CompositeIdentifier() override;

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::vector<const AbstractIdentifier*> &getIdentifiers() const;

        const std::vector<const VarIdentifier*> variables() const override;

    protected:
        UnificationResult unify(const CompositeIdentifier* other) const override;
        UnificationResult unify(const IntegerLiteral* other) const override;
        UnificationResult unify(const SymbolIdentifier* other) const override;
        UnificationResult unify(const TextLiteral* other) const override;
        UnificationResult unify(const VarIdentifier* other) const override;
        UnificationResult unify(const WordIdentifier* other) const override;

    private:
        const std::vector<const AbstractIdentifier*> identifiers;
    };
}

#endif //BASE_COMPOSITEIDENTIFIER_H
