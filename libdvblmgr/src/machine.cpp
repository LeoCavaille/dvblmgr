#include "machine.hpp"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

Machine::Machine() : connected_(false){
  ID_ = boost::uuids::random_generator()();
}

std::string Machine::getID() const {
  return boost::lexical_cast<std::string>(ID_);
}
