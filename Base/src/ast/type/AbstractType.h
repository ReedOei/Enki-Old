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

    const std::string to_string(Mode &mode) {
        switch (mode) {
            case IN:
                return "+";
            case OUT:
                return "-";
            case PARTIAL:
                return "?";
        }
    }

    class AbstractType : public AbstractNode {
    public:
        AbstractType();
    };
}

#endif //BASE_ABSTRACTTYPE_H
