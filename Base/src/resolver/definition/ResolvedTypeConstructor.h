//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDTYPECONSTRUCTOR_H
#define BASE_RESOLVEDTYPECONSTRUCTOR_H

#include <memory>
#include <vector>

#include "AbstractResolvedTypeConstructor.h"
#include "ResolvedProperty.h"
#include "../../ast/identifier/AbstractIdentifier.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedTypeConstructor : public AbstractResolvedTypeConstructor {
    public:
        ResolvedTypeConstructor(const AbstractIdentifier* identifier,
                                const std::vector<const ResolvedVarExpr*> &parameters,
                                const std::vector<const ResolvedProperty*> &fields);

        virtual ~ResolvedTypeConstructor();

        const std::string nodeName() const override;
        const std::string constructorTypeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const AbstractIdentifier* getIdentifier() const;
        const std::vector<const ResolvedVarExpr*> &getParameters() const;
        const std::vector<const ResolvedProperty*> &getFields() const;

    private:
        const AbstractIdentifier* identifier;
        const std::vector<const ResolvedVarExpr*> parameters;
        const std::vector<const ResolvedProperty*> fields;
    };
}

#endif //BASE_RESOLVEDTYPECONSTRUCTOR_H
