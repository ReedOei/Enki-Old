//
// Created by roei on 17/10/18.
//

#ifndef BASE_FUNCTYPE_H
#define BASE_FUNCTYPE_H

#include "AbstractType.h"

namespace enki {
    class FuncType : AbstractType {
    public:
        FuncType(const AbstractType &inType, const AbstractType &utType);

        const std::string nodeName() const override;

    private:
        const AbstractType &inType;
        const AbstractType &outType;
    };
}

#endif //BASE_FUNCTYPE_H
