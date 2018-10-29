#include <utility>

//
// Created by roei on 27/10/18.
//

#ifndef BASE_UNIFICATIONRESULT_H
#define BASE_UNIFICATIONRESULT_H

#include <memory>
#include <vector>

namespace enki {
    class AbstractIdentifier;

    class UnificationResult {
    public:
        UnificationResult();
        UnificationResult(const AbstractIdentifier* a, const AbstractIdentifier* b);
        UnificationResult(const std::vector<std::pair<const AbstractIdentifier*, const AbstractIdentifier*>> &unified);

        virtual ~UnificationResult();

        const std::vector<std::pair<const AbstractIdentifier*, const AbstractIdentifier*>> &getUnified() const;

        void appendAll(const UnificationResult &other);

        bool empty();
        bool succeeded();

    private:
        std::vector<std::pair<const AbstractIdentifier*, const AbstractIdentifier*>> unified;
    };
}

#endif //BASE_UNIFICATIONRESULT_H
