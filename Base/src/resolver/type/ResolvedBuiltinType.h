//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDBUILTINTYPE_H
#define BASE_RESOLVEDBUILTINTYPE_H

#include "AbstractResolvedType.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedBuiltinType : public AbstractResolvedType {
    public:
        explicit ResolvedBuiltinType(const std::string &name);

        const std::string nodeName() const override;
        const std::string typeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::string name;
    };
}

#endif //BASE_RESOLVEDBUILTINTYPE_H
