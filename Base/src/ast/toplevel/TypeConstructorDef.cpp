//
// Created by roei on 18/10/18.
//

#include <boost/algorithm/string/join.hpp>
#include "TypeConstructorDef.h"
#include "../AbstractNodeVisitor.h"

namespace enki {
    TypeConstructorDef::TypeConstructorDef(const AbstractIdentifier* identifier,
                                           const std::vector<std::pair<const AbstractIdentifier*, const AbstractType*>> &members)
            : identifier(identifier), members(members) {}

    const std::string TypeConstructorDef::nodeName() const {
        return "TypeConstructoDef";
    }

    const std::string TypeConstructorDef::to_string() const {
        std::vector<std::string> strings;

        std::transform(members.begin(), members.end(), std::back_inserter(strings),
                [](auto member) { return member.first->to_string() + " : " + member.second->to_string(); });

        return identifier->to_string() + " has: (" +
               boost::algorithm::join(strings, "\n") + ").";
    }

    void TypeConstructorDef::accept(AbstractNodeVisitor &visitor) const {
        visitor.visit(*this);

        identifier->accept(visitor);

        for (const auto &member : members) {
            member.first->accept(visitor);
            member.second->accept(visitor);
        }
    }

    const AbstractIdentifier* TypeConstructorDef::getIdentifier() const {
        return identifier;
    }

    const std::vector<std::pair<const AbstractIdentifier*, const AbstractType*>> &
    TypeConstructorDef::getMembers() const {
        return members;
    }

    TypeConstructorDef::~TypeConstructorDef() {

    }
}
