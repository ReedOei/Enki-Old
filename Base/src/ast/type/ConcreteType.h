//
// Created by roei on 17/10/18.
//

#ifndef BASE_CONCRETETYPE_H
#define BASE_CONCRETETYPE_H

#include <memory>
#include "AbstractType.h"
#include "../identifier/AbstractIdentifier.h"

namespace enki {
    class ConcreteType : public AbstractType {
    public:
        explicit ConcreteType(const AbstractIdentifier* typeName);

        virtual ~ConcreteType();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getTypeName() const;

    private:
        const AbstractIdentifier* typeName;
    };
}

#endif //BASE_CONCRETETYPE_H
