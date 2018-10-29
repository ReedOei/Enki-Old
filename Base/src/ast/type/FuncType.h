//
// Created by roei on 17/10/18.
//

#ifndef BASE_FUNCTYPE_H
#define BASE_FUNCTYPE_H

#include <memory>
#include "AbstractType.h"

namespace enki {
    class FuncType : public AbstractType {
    public:
        FuncType(const AbstractType* inType, const AbstractType* outType);

        virtual ~FuncType();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractType* getInType() const;
        const AbstractType* getOutType() const;

    private:
        const AbstractType* inType;
        const AbstractType* outType;
    };
}

#endif //BASE_FUNCTYPE_H
