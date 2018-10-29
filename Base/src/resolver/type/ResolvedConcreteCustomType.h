//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDCONCRETECUSTOMTYPE_H
#define BASE_RESOLVEDCONCRETECUSTOMTYPE_H

#include <memory>
#include <vector>
#include "../definition/AbstractResolvedTypeConstructor.h"
#include "AbstractResolvedType.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedConcreteCustomType : public AbstractResolvedType {
    public:
        ResolvedConcreteCustomType(const AbstractResolvedTypeConstructor* constructor,
                                   const std::vector<const AbstractResolvedType*> &typeParameters);

        virtual ~ResolvedConcreteCustomType();

        const std::string nodeName() const override;
        const std::string typeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const AbstractResolvedTypeConstructor* getConstructor() const;
        const std::vector<const AbstractResolvedType*> &getTypeParameters() const;

    private:
        const AbstractResolvedTypeConstructor* constructor;
        const std::vector<const AbstractResolvedType*> typeParameters;
    };
}

#endif //BASE_RESOLVEDCONCRETECUSTOMTYPE_H
