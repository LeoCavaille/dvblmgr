#include "channel.h"
#include "vectorcompare.hpp"

Channel::Channel() : broadcast_(false) {}

Channel::Channel(const std::string name, const unsigned int &sid,
                 const std::vector<unsigned int> &pids)
    : name_(name), sid_(sid), pids_(pids), broadcast_(false) {}


bool Channel::operator==(const Channel &rhs) const {
  return name_ == rhs.name_ && sid_ == rhs.sid_ && compareVectors(pids_, rhs.pids_);
}

bool Channel::operator!=(const Channel &rhs) const {
  return !(*this==rhs);
}
