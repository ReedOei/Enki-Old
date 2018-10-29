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
        explicit RuleType(const std::vector<std::pair<Mode, const AbstractType*>> &modes);

        virtual ~RuleType();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::vector<std::pair<Mode, const AbstractType*>> &getModes() const;

    private:
        const std::vector<std::pair<Mode, const AbstractType*>> modes;
    };
}

#endif //BASE_RULETYPE_H
