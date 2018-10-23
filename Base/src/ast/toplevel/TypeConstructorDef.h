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
        TypeConstructorDef(const std::shared_ptr<AbstractIdentifier> &identifier,
                           const std::vector<std::pair<std::shared_ptr<AbstractIdentifier>, std::shared_ptr<AbstractType>>> &members);

        const std::string nodeName() const override;

        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractIdentifier> identifier;
        const std::vector<std::pair<std::shared_ptr<AbstractIdentifier>, std::shared_ptr<AbstractType>>> members;
    };
}

#endif //BASE_TYPECONSTRUCTORDEF_H
