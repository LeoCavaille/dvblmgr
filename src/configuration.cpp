#include "configuration.h"

Configuration::Configuration(const std::string filename): filename_(filename)
{}

void Configuration::parse()
{
    config_ = YAML::LoadFile(filename_);
}

