//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDPROPERTY_H
#define BASE_RESOLVEDPROPERTY_H

#include <vector>

#include "../AbstractResolvedNode.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../expression/ResolvedVarExpr.h"
#include "../type/AbstractResolvedType.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedProperty : public AbstractResolvedNode {
    public:
        ResolvedProperty(const AbstractIdentifier* identifier, const std::vector<const ResolvedVarExpr*> &parameters,
                         const AbstractResolvedType* type);

        virtual ~ResolvedProperty();

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const AbstractIdentifier* getIdentifier() const;

        const std::vector<const ResolvedVarExpr*> &getParameters() const;

        const AbstractResolvedType* getType() const;

    private:
        const AbstractIdentifier* identifier;

        const std::vector<const ResolvedVarExpr*> parameters;
        const AbstractResolvedType* type;
    };
}

#endif //BASE_RESOLVEDPROPERTY_H
