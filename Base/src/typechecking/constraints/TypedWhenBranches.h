//
// Created by roei on 17/01/19.
//

#ifndef BASE_TYPEDWHENBRANCHES_H
#define BASE_TYPEDWHENBRANCHES_H

#include "TypedWhenBranch.h"

namespace enki {
    class TypedWhenBranches : public AbstractTypedConstraint {
    public:
        TypedWhenBranches(const std::vector<const TypedWhenBranch*> &branches,
                          const std::optional<const AbstractTypedConstraint*> &otherwise);
        ~TypedWhenBranches() override;

        const std::vector<const TypedWhenBranch*> &getBranches() const;
        const std::optional<const AbstractTypedConstraint*> &getOtherwise() const;

    private:
        const std::vector<const TypedWhenBranch*> branches;
        const std::optional<const AbstractTypedConstraint*> otherwise;
    };
}

#endif //BASE_TYPEDWHENBRANCHES_H
