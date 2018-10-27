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
        explicit CompositeIdentifier(const std::vector<std::shared_ptr<AbstractIdentifier>> &identifiers);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::vector<std::shared_ptr<AbstractIdentifier>> &ids() const;

    protected:
        bool canUnify(const CompositeIdentifier* other) const override;
        bool canUnify(const IntegerLiteral* other) const override;
        bool canUnify(const SymbolIdentifier* other) const override;
        bool canUnify(const TextLiteral* other) const override;
        bool canUnify(const VarIdentifier* other) const override;
        bool canUnify(const WordIdentifier* other) const override;

    private:
        const std::vector<std::shared_ptr<AbstractIdentifier>> identifiers;
    };
}

#endif //BASE_COMPOSITEIDENTIFIER_H
