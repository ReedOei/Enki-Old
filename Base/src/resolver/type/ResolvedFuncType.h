//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDFUNCTYPE_H
#define BASE_RESOLVEDFUNCTYPE_H

#include <memory>
#include "AbstractResolvedType.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedFuncType : public AbstractResolvedType {
    public:
        ResolvedFuncType(const std::shared_ptr<AbstractResolvedType> &inType,
                         const std::shared_ptr<AbstractResolvedType> &outType);

        const std::string nodeName() const override;
        const std::string typeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractResolvedType> inType;
        const std::shared_ptr<AbstractResolvedType> outType;
    };
}

#endif //BASE_RESOLVEDFUNCTYPE_H
