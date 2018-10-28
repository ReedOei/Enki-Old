//
// Created by roei on 17/10/18.
//

#include <optional>
#include "AbstractIdentifier.h"

#include "VarIdentifier.h"
#include "CompositeIdentifier.h"
#include "IntegerLiteral.h"
#include "SymbolIdentifier.h"
#include "TextLiteral.h"
#include "WordIdentifier.h"

namespace enki {
    AbstractIdentifier::AbstractIdentifier() = default;

    UnificationResult AbstractIdentifier::tryUnify(const AbstractIdentifier* other) const {
        if (auto ci = dynamic_cast<const CompositeIdentifier*>(other)) {
            return unify(ci);
        } else if (auto i = dynamic_cast<const IntegerLiteral*>(other)) {
            return unify(i);
        } else if (auto si = dynamic_cast<const SymbolIdentifier*>(other)) {
            return unify(si);
        } else if (auto t = dynamic_cast<const TextLiteral*>(other)) {
            return unify(t);
        } else if (auto vi = dynamic_cast<const VarIdentifier*>(other)) {
            return unify(vi);
        } else if (auto wi = dynamic_cast<const WordIdentifier*>(other)) {
            return unify(wi);
        }

        return UnificationResult();
    }
}
