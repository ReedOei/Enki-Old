//
// Created by roei on 18/10/18.
//

#ifndef BASE_PROPERTY_H
#define BASE_PROPERTY_H

#include <memory>
#include "AbstractNode.h"
#include "identifier/AbstractIdentifier.h"
#include "type/AbstractType.h"

namespace enki {
    class Property : AbstractNode {
    public:
        Property(const std::shared_ptr<AbstractIdentifier> &name, const std::shared_ptr<AbstractType> &type);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> name;
        const std::shared_ptr<AbstractType> type;
    };
}

#endif //BASE_PROPERTY_H
