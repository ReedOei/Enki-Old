//
// Created by roei on 22/10/18.
//

#ifndef BASE_ABSTRACTRESOLVEDLITERAL_H
#define BASE_ABSTRACTRESOLVEDLITERAL_H

#include "AbstractResolvedVal.h"

namespace enki {
    class AbstractResolvedLiteral : public AbstractResolvedVal {
    public:
        virtual ~AbstractResolvedLiteral();
    };
}

#endif //BASE_ABSTRACTRESOLVEDLITERAL_H
