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
        SumTypeConstructorDef(const std::shared_ptr<AbstractIdentifier> &identifier,
                              const std::vector<std::shared_ptr<AbstractTypeConstructorDef>> &variants);

        const std::string nodeName() const override;

        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> identifier;
        const std::vector<std::shared_ptr<AbstractTypeConstructorDef>> variants;
    };
}

#endif //BASE_SUMTYPECONSTRUCTORDEF_H
