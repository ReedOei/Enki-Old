//
// Created by roei on 18/10/18.
//

#include "Property.h"

enki::Property::Property(const enki::AbstractIdentifier* name, const enki::AbstractType* type) : name(name),
                                                                                                 type(type) {}

const std::string enki::Property::nodeName() const {
    return "Property";
}
