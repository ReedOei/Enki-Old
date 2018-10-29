//
// Created by roei on 20/10/18.
//

#ifndef BASE_RESOLVEDIMPLEMENTATION_H
#define BASE_RESOLVEDIMPLEMENTATION_H

#include <memory>
#include <vector>

#include "AbstractResolvedDefinition.h"
#include "ResolvedTypeclass.h"
#include "../type/AbstractResolvedType.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedImplementation : public AbstractResolvedDefinition {
    public:
        ResolvedImplementation(const AbstractResolvedType* implementationType,
                               const ResolvedTypeclass* typeclass,
                               const std::vector<const AbstractResolvedDefinition*> &definitions);

        virtual ~ResolvedImplementation();

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const std::string nodeName() const override;

        const AbstractResolvedType* getImplementationType() const;

        const ResolvedTypeclass* getTypeclass() const;

        const std::vector<const AbstractResolvedDefinition*> &getDefinitions() const;

    private:
        const AbstractResolvedType* implementationType;
        const ResolvedTypeclass* typeclass;

        const std::vector<const AbstractResolvedDefinition*> definitions;
    };
}


#endif //BASE_RESOLVEDIMPLEMENTATION_H
