//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDRULETYPE_H
#define BASE_RESOLVEDRULETYPE_H

#include <memory>
#include <optional>
#include <vector>
#include "AbstractResolvedType.h"
#include "../../ast/type/AbstractType.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedRuleType : public AbstractResolvedType {
    public:
        explicit ResolvedRuleType(
                const std::vector<std::shared_ptr<std::pair<std::optional<Mode>, std::shared_ptr<AbstractResolvedType>>>> &types);

        const std::string nodeName() const override;
        const std::string typeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::vector<std::shared_ptr<std::pair<std::optional<Mode>, std::shared_ptr<AbstractResolvedType>>>> types;
    };
}


#endif //BASE_RESOLVEDRULETYPE_H
