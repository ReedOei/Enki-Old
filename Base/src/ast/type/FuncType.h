//
// Created by roei on 17/10/18.
//

#ifndef BASE_FUNCTYPE_H
#define BASE_FUNCTYPE_H

#include <memory>
#include "AbstractType.h"

namespace enki {
    class FuncType : public AbstractType {
    public:
        FuncType(const std::shared_ptr<AbstractType> &inType, const std::shared_ptr<AbstractType> &outType);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<AbstractType> inType;
        const std::shared_ptr<AbstractType> outType;
    };
}

#endif //BASE_FUNCTYPE_H
