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
        ResolvedFuncType(const AbstractResolvedType* inType, const AbstractResolvedType* outType);

        virtual ~ResolvedFuncType();

        const std::string nodeName() const override;
        const std::string typeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const AbstractResolvedType* getInType() const;

        const AbstractResolvedType* getOutType() const;

    private:
        const AbstractResolvedType* inType;
        const AbstractResolvedType* outType;
    };
}

#endif //BASE_RESOLVEDFUNCTYPE_H
