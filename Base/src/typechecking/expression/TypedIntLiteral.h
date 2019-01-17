//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDINTLITERAL_H
#define BASE_TYPEDINTLITERAL_H

#include "AbstractTypedLiteral.h"

namespace enki {
    class TypedIntLiteral : public AbstractTypedLiteral {
    public:
        explicit TypedIntLiteral(int v);
        ~TypedIntLiteral() override;

        const int getV() const;

    private:
        const int v;
    };
}

#endif //BASE_TYPEDINTLITERAL_H
