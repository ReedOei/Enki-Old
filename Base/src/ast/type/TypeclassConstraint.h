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
        TypeclassConstraint(const std::shared_ptr<AbstractIdentifier> &typeclassId,
                            const std::shared_ptr<AbstractIdentifier> &typevarId,
                            const std::shared_ptr<AbstractType> &type);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> typeclassId;
        const std::shared_ptr<AbstractIdentifier> typevarId;
        const std::shared_ptr<AbstractType> type;
    };
}


#endif //BASE_TYPECLASSCONSTRAINT_H
