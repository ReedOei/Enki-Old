//
// Created by roei on 18/10/18.
//

#ifndef BASE_TYPECONSTRUCTORDEF_H
#define BASE_TYPECONSTRUCTORDEF_H

#include <vector>
#include "AbstractTypeConstructorDef.h"
#include "../identifier/AbstractIdentifier.h"
#include "../type/AbstractType.h"

namespace enki {
    class TypeConstructorDef : public AbstractTypeConstructorDef {
    public:
        TypeConstructorDef(const AbstractIdentifier* identifier,
                           const std::vector<std::pair<AbstractIdentifier*, AbstractType*>> &members);

        const std::string nodeName() const override;

    private:
        const AbstractIdentifier* identifier;
        const std::vector<std::pair<AbstractIdentifier*, AbstractType*>> members;
    };
}

#endif //BASE_TYPECONSTRUCTORDEF_H
