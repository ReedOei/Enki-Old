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
        ResolvedFuncExpr(const ResolvedFunction* function, const std::vector<const AbstractResolvedVal*> &values);

        virtual ~ResolvedFuncExpr();

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const ResolvedFunction* getFunction() const;

        const std::vector<const AbstractResolvedVal*> &getValues() const;

    private:
        const ResolvedFunction* function;
        const std::vector<const AbstractResolvedVal*> values;
    };
}

#endif //BASE_RESOLVEDFUNCEXPR_H
