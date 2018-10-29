//
// Created by roei on 18/10/18.
//

#ifndef BASE_RUNNABLE_H
#define BASE_RUNNABLE_H

#include <memory>
#include "AbstractTopLevel.h"
#include "../constraints/AbstractConstraint.h"

namespace enki {
    class Runnable : public AbstractTopLevel {
    public:
        explicit Runnable(const AbstractConstraint* constraint);

        virtual ~Runnable();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractConstraint* getConstraint() const;

    private:
        const AbstractConstraint* constraint;
    };
}

#endif //BASE_RUNNABLE_H
