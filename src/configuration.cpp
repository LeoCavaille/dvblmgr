#include "configuration.hpp"

#include "multiplextnt.h"
#include "multiplexsat.h"

#include <iostream>

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
	if(! config_["multiplexs"]){
		std::cerr << "WARNING: no multiplexs defined in the configuration" << std::endl;
	}
	for(auto m : config_["multiplexs"])
	{
		if(! m["type"]){
			std::cerr << "ERROR: multiplex with no type" << std::endl;
		}
		std::string type = m["type"].as<std::string>();
		std::transform(type.begin(), type.end(),type.begin(), ::toupper);
		if(type == "TNT"){
			MultiplexTntPtr mPtr = std::make_shared<MultiplexTnt>();
			YAML::convert<MultiplexTntPtr>::decode(m, mPtr);
			multiplexs_.push_back(mPtr);
		}
		else if (type == "SAT"){
			MultiplexSatPtr mPtr = std::make_shared<MultiplexSat>();
			YAML::convert<MultiplexSatPtr>::decode(m, mPtr);
			multiplexs_.push_back(mPtr);
		}
		else{
			std::cerr << "ERROR: multiplex type MUST be tnt or sat" << std::endl;
		}
	}

}

void Configuration::parseServers(){

}

void Configuration::check(){
	checkChannelDupes();

}

void Configuration::checkChannelDupes(){

}
