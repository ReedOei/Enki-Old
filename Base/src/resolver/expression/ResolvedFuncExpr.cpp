//
// Created by roei on 22/10/18.
//

#include "ResolvedFuncExpr.h"

namespace enki {
    ResolvedFuncExpr::ResolvedFuncExpr(const ResolvedFunction* function,
                                       const std::vector<const AbstractResolvedVal*> &values) : function(function),
                                                                                                values(values) {}
    ResolvedFuncExpr::~ResolvedFuncExpr() = default;

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

    const ResolvedFunction* ResolvedFuncExpr::getFunction() const {
        return function;
    }

    const std::vector<const AbstractResolvedVal*> &ResolvedFuncExpr::getValues() const {
        return values;
    }
}
