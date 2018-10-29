//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDSUMTYPECONSTRUCTOR_H
#define BASE_RESOLVEDSUMTYPECONSTRUCTOR_H

#include <memory>
#include <vector>

#include "AbstractResolvedTypeConstructor.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../expression/ResolvedVarExpr.h"
#include "ResolvedTypeConstructor.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedSumTypeConstructor : public AbstractResolvedTypeConstructor {
    public:
        ResolvedSumTypeConstructor(const AbstractIdentifier* identifier,
                                   const std::vector<const ResolvedVarExpr*> &parameters,
                                   const std::vector<const ResolvedTypeConstructor*> &constructors);

        virtual ~ResolvedSumTypeConstructor();

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const std::string nodeName() const override;
        const std::string constructorTypeName() const override;

        const AbstractIdentifier* getIdentifier() const;
        const std::vector<const ResolvedVarExpr*> &getParameters() const;
        const std::vector<const ResolvedTypeConstructor*> &getConstructors() const;

    private:
        const AbstractIdentifier* identifier;
        const std::vector<const ResolvedVarExpr*> parameters;

        const std::vector<const ResolvedTypeConstructor*> constructors;
    };
}


#endif //BASE_RESOLVEDSUMTYPECONSTRUCTOR_H
