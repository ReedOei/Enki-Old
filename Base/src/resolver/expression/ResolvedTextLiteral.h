//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDTEXTLITERAL_H
#define BASE_RESOLVEDTEXTLITERAL_H

#include "AbstractResolvedLiteral.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedTextLiteral : public AbstractResolvedLiteral {
    public:
        explicit ResolvedTextLiteral(const std::string &v);

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

    private:
        const std::string v;
    };
}

#endif //BASE_RESOLVEDTEXTLITERAL_H
