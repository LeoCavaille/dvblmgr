#include "multiplex.h"

std::string Multiplex::getType(const YAML::Node& node) {
    if(!node["type"]) {
        return "UNKNOWN";
    }

    std::string type = node["type"].as<std::string>();
    std::transform(type.begin(), type.end(),type.begin(), ::toupper);

    if(type == "TNT" || type == "SAT") {
        return type;
    }
    else{
        return "UNKNOWN";
    }
}