//
// Created by roei on 18/10/18.
//

#ifndef BASE_FUNCDEFINITION_H
#define BASE_FUNCDEFINITION_H

#include <memory>
#include "AbstractDefinition.h"
#include "../identifier/AbstractIdentifier.h"
#include "../constraints/AbstractConstraint.h"

namespace enki {
    class FuncDefinition : public AbstractDefinition {
    public:
        FuncDefinition(const std::shared_ptr<AbstractIdentifier> &funcId,
                       const std::shared_ptr<AbstractConstraint> &constraint);

        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::string nodeName() const override;

    private:
        const std::shared_ptr<AbstractIdentifier> funcId;
        const std::shared_ptr<AbstractConstraint> constraint;
    };
}

#endif //BASE_FUNCDEFINITION_H
