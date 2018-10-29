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
        FuncDefinition(const AbstractIdentifier* funcId, const AbstractConstraint* constraint,
                       const AbstractIdentifier* val);

        virtual ~FuncDefinition();

        const std::string to_string() const override;
        const std::string nodeName() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getFuncId() const;
        const AbstractConstraint* getConstraint() const;
        const AbstractIdentifier* getVal() const;

    private:
        const AbstractIdentifier* funcId;
        const AbstractConstraint* constraint;
        const AbstractIdentifier* val;
    };
}

#endif //BASE_FUNCDEFINITION_H
