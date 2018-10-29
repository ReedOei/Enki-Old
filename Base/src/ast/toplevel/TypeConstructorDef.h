//
// Created by roei on 18/10/18.
//

#ifndef BASE_TYPECONSTRUCTORDEF_H
#define BASE_TYPECONSTRUCTORDEF_H

#include <vector>
#include <memory>
#include "AbstractTypeConstructorDef.h"
#include "../identifier/AbstractIdentifier.h"
#include "../type/AbstractType.h"

namespace enki {
    class TypeConstructorDef : public AbstractTypeConstructorDef {
    public:
        TypeConstructorDef(const AbstractIdentifier* identifier,
                           const std::vector<std::pair<const AbstractIdentifier*, const AbstractType*>> &members);

        virtual ~TypeConstructorDef();

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const AbstractIdentifier* getIdentifier() const;
        const std::vector<std::pair<const AbstractIdentifier*, const AbstractType*>> &getMembers() const;

    private:
        const AbstractIdentifier* identifier;
        const std::vector<std::pair<const AbstractIdentifier*, const AbstractType*>> members;
    };
}

#endif //BASE_TYPECONSTRUCTORDEF_H
