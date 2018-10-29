//
// Created by roei on 18/10/18.
//

#ifndef BASE_SINGLETONCONSTRAINT_H
#define BASE_SINGLETONCONSTRAINT_H

#include <memory>
#include "AbstractConstraint.h"
#include "../identifier/AbstractIdentifier.h"

namespace enki {
    class SingletonConstraint : public AbstractConstraint {
    public:
        explicit SingletonConstraint(const AbstractIdentifier* &identifier);

        virtual ~SingletonConstraint();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getIdentifier() const;

    private:
        const AbstractIdentifier* identifier;
    };
}

#endif //BASE_SINGLETONCONSTRAINT_H
