//
// Created by roei on 17/10/18.
//

#ifndef BASE_RULETYPE_H
#define BASE_RULETYPE_H


#include <vector>
#include <memory>
#include "AbstractType.h"

namespace enki {
    class RuleType : public AbstractType {
    public:
        explicit RuleType(const std::vector<std::pair<Mode, std::shared_ptr<AbstractType>>> &modes);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::vector<std::pair<Mode, std::shared_ptr<AbstractType>>> modes;
    };
}

#endif //BASE_RULETYPE_H
