//
// Created by roei on 18/10/18.
//

#ifndef BASE_SUMTYPECONSTRUCTORDEF_H
#define BASE_SUMTYPECONSTRUCTORDEF_H

#include <vector>
#include <memory>
#include "AbstractTypeConstructorDef.h"
#include "../identifier/AbstractIdentifier.h"

namespace enki {
    class SumTypeConstructorDef : public AbstractTypeConstructorDef {
    public:
        SumTypeConstructorDef(const AbstractIdentifier* identifier, std::vector<const AbstractTypeConstructorDef*> variants);

        virtual ~SumTypeConstructorDef();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getIdentifier() const;
        const std::vector<const AbstractTypeConstructorDef*> &getVariants() const;

    private:
        const AbstractIdentifier* identifier;
        const std::vector<const AbstractTypeConstructorDef*> variants;
    };
}

#endif //BASE_SUMTYPECONSTRUCTORDEF_H
