//
// Created by roei on 18/10/18.
//

#ifndef BASE_WORDIDENTIFIER_H
#define BASE_WORDIDENTIFIER_H

#include "AbstractIdentifier.h"

namespace enki {
    class WordIdentifier : public AbstractIdentifier {
    public:
        explicit WordIdentifier(const std::string &word);

        const std::string nodeName() const override;

    private:
        const std::string word;
    };
}

#endif //BASE_WORDIDENTIFIER_H