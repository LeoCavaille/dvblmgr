#include "modulation.hpp"

#include <algorithm>
#include <stdexcept>

Modulation::Modulation() : type_(none), typeString_("none") {}

Modulation::Modulation(Enum m) : type_(m), typeString_(ToString(m)) {}

Modulation::Modulation(const std::string &mString)
    : type_(FromString(mString)) {
  typeString_ = ToString(type_);
}

bool Modulation::operator==(const Modulation::Enum &e) const {
  return type_ == e;
}

bool Modulation::operator==(const Modulation &mPtr) const {
  return type_ == mPtr.type_;
}

Modulation::Enum Modulation::FromString(std::string mString) {
  transform(mString.begin(), mString.end(), mString.begin(), toupper);
  if (mString == "QPSK") {
    return qpsk;
  } else if (mString == "8PSK") {
    return eightpsk;
  } else if (mString == "NONE") {
    return none;
  }

  return invalid;
}

std::string Modulation::ToString(const Modulation::Enum &m) {
  switch (m) {
  case none: { return "NONE"; }
  case qpsk: { return "QPSK"; }
  case eightpsk: { return "8PSK"; }
  default: { return "INVALID"; }
  }
}
