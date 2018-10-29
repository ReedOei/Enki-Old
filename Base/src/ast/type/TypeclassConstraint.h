//
// Created by roei on 17/10/18.
//

#ifndef BASE_TYPECLASSCONSTRAINT_H
#define BASE_TYPECLASSCONSTRAINT_H


#include <memory>
#include "AbstractType.h"
#include "../identifier/AbstractIdentifier.h"

namespace enki {
    class TypeclassConstraint : public AbstractType {
    public:
        TypeclassConstraint(const AbstractIdentifier* typeclassId,
                            const AbstractIdentifier* typevarId,
                            const AbstractType* type);

        virtual ~TypeclassConstraint();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getTypeclassId() const;

        const AbstractIdentifier* getTypevarId() const;

        const AbstractType* getType() const;

    private:
        const AbstractIdentifier* typeclassId;
        const AbstractIdentifier* typevarId;
        const AbstractType* type;
    };
}


#endif //BASE_TYPECLASSCONSTRAINT_H
