#include "antenna.hpp"

Antenna::Antenna() {}

Antenna::Antenna(const std::string &name) : name_(name) {}

bool Antenna::operator==(const Antenna &rhs) const {
  return name_ == rhs.name_;
}

bool Antenna::operator!=(const Antenna &rhs) const { return !(*this == rhs); }
