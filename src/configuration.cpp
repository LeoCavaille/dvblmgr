#include "configuration.hpp"

Configuration::Configuration(const std::string& filename)
    : filename_(filename) {}

void Configuration::load() {
	if (filename_.empty()){

	}
	config_ = YAML::LoadFile(filename_);
	parse();
}

void Configuration::parse(){
	parseMultiplexs();
	parseServers();
}

void Configuration::parseMultiplexs(){

}

void Configuration::parseServers(){

}
