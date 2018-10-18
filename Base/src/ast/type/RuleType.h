//
// Created by roei on 17/10/18.
//

#ifndef BASE_RULETYPE_H
#define BASE_RULETYPE_H


#include <vector>
#include "AbstractType.h"

namespace enki {
    class RuleType : AbstractType {
    public:
        explicit RuleType(const std::vector<std::pair<Mode, AbstractType*>> &modes);

        const std::string nodeName() const override;

    private:
        const std::vector<std::pair<Mode, AbstractType*>> modes;
    };
}

#endif //BASE_RULETYPE_H
