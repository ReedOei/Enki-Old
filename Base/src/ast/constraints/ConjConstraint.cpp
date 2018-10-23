//
// Created by roei on 18/10/18.
//

#include <algorithm>
#include <boost/algorithm/string/join.hpp>

#include "ConjConstraint.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    ConjConstraint::ConjConstraint(const std::vector<std::shared_ptr<AbstractConstraint>> &constraints)
            : constraints(constraints) {}

    const std::string ConjConstraint::nodeName() const {
        return "ConjConstraint";
    }

    void ConjConstraint::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        for (const auto &constraint : constraints) {
            constraint->accept(visitor);
        }
    }

    const std::string ConjConstraint::to_string() const {
        std::string result;

        std::vector<std::string> strings;
        std::transform(constraints.begin(), constraints.end(), std::back_inserter(strings),
                [](auto constraint) { return constraint->to_string(); });

        return boost::algorithm::join(strings, ", and") + ".";
    }
}
