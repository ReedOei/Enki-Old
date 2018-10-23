//
// Created by roei on 18/10/18.
//

#ifndef BASE_SYMBOLIDENTIFIER_H
#define BASE_SYMBOLIDENTIFIER_H

#include "AbstractIdentifier.h"

namespace enki {
    class SymbolIdentifier : public AbstractIdentifier {
    public:
        explicit SymbolIdentifier(const std::string &symbol);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

    private:
        const std::string symbol;
    };
}

#endif //BASE_SYMBOLIDENTIFIER_H
