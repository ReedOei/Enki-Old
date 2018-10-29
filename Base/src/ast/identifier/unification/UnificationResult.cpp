//
// Created by roei on 27/10/18.
//

#include "UnificationResult.h"

namespace enki {
    UnificationResult::UnificationResult() = default;
    UnificationResult::UnificationResult(
            const std::vector<std::pair<const AbstractIdentifier*, const AbstractIdentifier*>> &unified) : unified(unified) {}

    const std::vector<std::pair<const AbstractIdentifier*, const AbstractIdentifier*>> &UnificationResult::getUnified() const {
        return unified;
    }

    void UnificationResult::appendAll(const UnificationResult &other) {
        unified.insert(unified.end(), other.getUnified().begin(), other.getUnified().end());
    }

    bool UnificationResult::empty() {
        return getUnified().empty();
    }

    UnificationResult::UnificationResult(const AbstractIdentifier* a, const AbstractIdentifier* b)
    : unified(std::vector {std::make_pair(a, b)}) {}

    bool UnificationResult::succeeded() {
        return !empty();
    }

    UnificationResult::~UnificationResult() = default;
}
