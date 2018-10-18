//
// Created by roei on 18/10/18.
//

#include "CompositeIdentifier.h"

enki::CompositeIdentifier::CompositeIdentifier(const std::vector<enki::AbstractIdentifier*> &identifiers)
        : identifiers(identifiers) {}
