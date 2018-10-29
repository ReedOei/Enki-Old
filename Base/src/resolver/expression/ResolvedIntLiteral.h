//
// Created by roei on 22/10/18.
//

#ifndef BASE_RESOLVEDINTLITERAL_H
#define BASE_RESOLVEDINTLITERAL_H

#include "AbstractResolvedLiteral.h"
#include "../AbstractResolvedNodeVisitor.h"

namespace enki {
    class ResolvedIntLiteral : public AbstractResolvedLiteral {
    public:
        explicit ResolvedIntLiteral(int v);

        virtual ~ResolvedIntLiteral();

        const std::string nodeName() const override;

        void accept(AbstractResolvedNodeVisitor &visitor) const override;

        const int value() const;

    private:
        const int v;
    };
}

#endif //BASE_RESOLVEDINTLITERAL_H
