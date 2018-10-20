//
// Created by roei on 18/10/18.
//

#ifndef BASE_INTEGERLITERAL_H
#define BASE_INTEGERLITERAL_H

#include "AbstractLiteralIdentifier.h"

namespace enki {
    class IntegerLiteral : public AbstractLiteralIdentifier {
    public:
        explicit IntegerLiteral(int val);
        IntegerLiteral(const IntegerLiteral& literal);
        ~IntegerLiteral();

        const std::string nodeName() const override;

        const int getVal() const;

    private:
        const int val;
    };
}

#endif //BASE_INTEGERLITERAL_H
