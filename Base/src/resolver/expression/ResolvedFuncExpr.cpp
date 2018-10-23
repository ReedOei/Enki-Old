//
// Created by roei on 22/10/18.
//

#include "ResolvedFuncExpr.h"

namespace enki {
    ResolvedFuncExpr::ResolvedFuncExpr(const std::shared_ptr<ResolvedFunction> &function,
                                       const std::vector<std::shared_ptr<AbstractResolvedVal>> &values)
            : function(function), values(values) {}

    const std::string ResolvedFuncExpr::nodeName() const {
        return "ResolvedFuncExpr";
    }

    void ResolvedFuncExpr::accept(AbstractResolvedNodeVisitor &visitor) const {
        visitor.visit(*this);

        function->accept(visitor);

        for (const auto &val : values) {
            val->accept(visitor);
        }
    }
}
