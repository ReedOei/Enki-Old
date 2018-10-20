//
// Created by roei on 17/10/18.
//

#ifndef BASE_ABSTRACTTYPE_H
#define BASE_ABSTRACTTYPE_H

#include <string>
#include "../AbstractNode.h"

namespace enki {
    enum Mode {
        IN,
        OUT,
        PARTIAL
    };

    class AbstractType : public AbstractNode {
    public:
        AbstractType();
    };
}

#endif //BASE_ABSTRACTTYPE_H
