//
// Created by roei on 18/10/18.
//

#ifndef BASE_COMMENT_H
#define BASE_COMMENT_H

#include "AbstractNode.h"

namespace enki {
    class Comment : AbstractNode {
    public:
        explicit Comment(const std::string &str);

        const std::string nodeName() const override;
        const std::string to_string() const override;

        void accept(AbstractNodeVisitor &visitor) const override;

        const std::string &string() const;

    private:
        const std::string str;
    };
}

#endif //BASE_COMMENT_H
