//
// Created by roei on 18/10/18.
//

#include <boost/algorithm/string/join.hpp>
#include "TypeclassDef.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    TypeclassDef::TypeclassDef(const std::shared_ptr<AbstractIdentifier> &templateId,
                               const std::shared_ptr<AbstractIdentifier> &typeclassId,
                               const std::vector<std::shared_ptr<Property>> &properties) : templateId(templateId),
                                                                                           typeclassId(typeclassId),
                                                                                           properties(properties) {}

    const std::string enki::TypeclassDef::nodeName() const {
        return "TypeclassDef";
    }

    const std::string TypeclassDef::to_string() const {
        std::vector<std::string> strings;

        std::transform(properties.begin(), properties.end(), std::back_inserter(strings),
                [](auto prop) { return prop->to_string(); });

        return templateId->to_string() + " is a type of: " + typeclassId->to_string() + " if it has:\n" +
               boost::algorithm::join(strings, "\n");
    }

    void TypeclassDef::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        templateId->accept(visitor);
        typeclassId->accept(visitor);

        for (const auto &prop : properties) {
            prop->accept(visitor);
        }
    }
}
