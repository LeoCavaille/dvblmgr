#include "configuration.hpp"

#include "multiplextnt.h"
#include "multiplexsat.h"

#include <iostream>

#define DEFAULT_CONFIG "/etc/dvblmgr/dvblmgr.conf"

Configuration::Configuration(const std::string& filename)
    : filename_(filename) {}

void Configuration::load() {
	if (filename_.empty()){
	  filename_ = DEFAULT_CONFIG;
	}
	config_ = YAML::LoadFile(filename_);
	parse();
}

void Configuration::save(){
  config_.reset();

  for(auto &m : multiplexs_){
    MultiplexSatPtr psat = std::dynamic_pointer_cast<MultiplexSat>(m);
    if(psat != nullptr){
      config_["multiplexs"].push_back(YAML::convert<MultiplexSatPtr>::encode(psat));
      continue;
    }

    MultiplexTntPtr ptnt = std::dynamic_pointer_cast<MultiplexTnt>(m);
    if(ptnt != nullptr){
      config_["multiplexs"].push_back(YAML::convert<MultiplexTntPtr>::encode(ptnt));
      continue;
    }

  }

  YAML::Emitter out;
  out << config_;
  std::cout << out.c_str() << std::endl;
}

void Configuration::parse(){
	parseMultiplexs();
	parseServers();
}

void Configuration::parseMultiplexs(){
	if(! config_["multiplexs"] || ! config_["multiplexs"].IsSequence()){
		std::cerr << "WARNING: no multiplexs defined in the configuration" << std::endl;
		return;
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
