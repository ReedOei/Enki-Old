//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDFUNCEXPR_H
#define BASE_RESOLVEDFUNCEXPR_H

#include "AbstractResolvedVal.h"
#include "../definition/ResolvedFunction.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedFuncExpr : public AbstractResolvedVal {
    public:
        ResolvedFuncExpr(const std::shared_ptr<ResolvedFunction> &function,
                         const std::vector<std::shared_ptr<AbstractResolvedVal>> &values);

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::shared_ptr<ResolvedFunction> function;
        const std::vector<std::shared_ptr<AbstractResolvedVal>> values;
    };
}

#endif //BASE_RESOLVEDFUNCEXPR_H
