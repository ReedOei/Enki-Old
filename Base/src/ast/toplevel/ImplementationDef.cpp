//
// Created by roei on 18/10/18.
//

#include <algorithm>
#include <boost/algorithm/string/join.hpp>
#include "ImplementationDef.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    ImplementationDef::ImplementationDef(const AbstractIdentifier* implementationId,
                                         const AbstractIdentifier* typeclassId,
                                         const std::vector<const AbstractDefinition*> &definitions)
            : implementationId(implementationId), typeclassId(typeclassId), definitions(definitions) {}

    const std::string ImplementationDef::nodeName() const {
        return "ImplementationDef";
    }

    const std::string ImplementationDef::to_string() const {
        std::vector<std::string> strings;

        std::transform(definitions.begin(), definitions.end(), std::back_inserter(strings),
                [](auto def) { return def->to_string(); });

        return implementationId->to_string() + " is a type of: " + typeclassId->to_string() + " because it has:\n" +
            boost::algorithm::join(strings, "\n") + "\n";
    }

    void ImplementationDef::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        implementationId->accept(visitor);
        typeclassId->accept(visitor);

        for (const auto &def : definitions) {
            def->accept(visitor);
        }
    }

    const AbstractIdentifier* ImplementationDef::getImplementationId() const {
        return implementationId;
    }

    const AbstractIdentifier* ImplementationDef::getTypeclassId() const {
        return typeclassId;
    }

    const std::vector<const AbstractDefinition*> &ImplementationDef::getDefinitions() const {
        return definitions;
    }

    ImplementationDef::~ImplementationDef() {

    }
}
