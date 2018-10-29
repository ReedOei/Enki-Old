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
        explicit ResolvedRuleType(const std::vector<std::pair<std::optional<Mode>, const AbstractResolvedType*>> &types);

        virtual ~ResolvedRuleType();

        const std::string nodeName() const override;
        const std::string typeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const std::vector<std::pair<std::optional<Mode>, const AbstractResolvedType*>> &getTypes() const;

    private:
        const std::vector<std::pair<std::optional<Mode>, const AbstractResolvedType*>> types;
    };
}


#endif //BASE_RESOLVEDRULETYPE_H
