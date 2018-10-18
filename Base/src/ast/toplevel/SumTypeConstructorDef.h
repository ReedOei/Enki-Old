//
// Created by roei on 18/10/18.
//

#ifndef BASE_SUMTYPECONSTRUCTORDEF_H
#define BASE_SUMTYPECONSTRUCTORDEF_H

#include <vector>
#include "AbstractTypeConstructorDef.h"

namespace enki {
    class SumTypeConstructorDef : AbstractTypeConstructorDef {
    public:
        explicit SumTypeConstructorDef(const std::vector<AbstractTypeConstructorDef*> &variants);

        const std::string nodeName() const override;

    private:
        const std::vector<AbstractTypeConstructorDef*> variants;
    };
}

#endif //BASE_SUMTYPECONSTRUCTORDEF_H
