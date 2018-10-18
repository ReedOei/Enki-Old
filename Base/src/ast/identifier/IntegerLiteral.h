//
// Created by roei on 18/10/18.
//

#ifndef BASE_INTEGERLITERAL_H
#define BASE_INTEGERLITERAL_H

#include "AbstractLiteralIdentifier.h"

namespace enki {
    class IntegerLiteral : AbstractLiteralIdentifier {
    public:
        explicit IntegerLiteral(int val);

        const std::string nodeName() const override;

    private:
        const int val;
    };
}

#endif //BASE_INTEGERLITERAL_H
