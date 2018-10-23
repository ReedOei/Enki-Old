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

    private:
        const std::vector<std::shared_ptr<AbstractIdentifier>> identifiers;
    };
}

#endif //BASE_COMPOSITEIDENTIFIER_H
