//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDVAREXPR_H
#define BASE_RESOLVEDVAREXPR_H

#include <string>
#include <memory>
#include "AbstractResolvedVal.h"
#include "../definition/AbstractResolvedDefinition.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedVarExpr : public AbstractResolvedVal {
    public:
        ResolvedVarExpr(const std::string &varName, const AbstractResolvedDefinition* binder, int binderPosition);
        ~ResolvedVarExpr() override;

        const std::string nodeName() const override;
        const std::string &getVarName() const;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const AbstractResolvedDefinition* getBinder() const;
        const int getBinderPosition() const;

    private:
        const std::string varName;

        const AbstractResolvedDefinition* binder;
        const int binderPosition;
    };
}

#endif //BASE_RESOLVEDVAREXPR_H
