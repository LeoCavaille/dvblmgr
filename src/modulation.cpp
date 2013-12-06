#include "modulation.h"

#include <algorithm>
#include <stdexcept>

Modulation::Modulation() : type_(none), typeString_("none") {}

Modulation::Modulation(Enum m) : type_(m), typeString_(ToString(m)) {}

Modulation::Modulation(const std::string &mString)
    : type_(FromString(mString))
{
  typeString_ = ToString(type_);
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

  throw std::invalid_argument("Not a valid Modulation value: " + mString);
  // Remove annoying -Wreturn-type warning
  return invalid;
}

std::string Modulation::ToString(const Modulation::Enum &m) {
  switch (m) {
  case none: { return "NONE"; }
  case qpsk: { return "QPSK"; }
  case eightpsk: { return "8PSK"; }
  case invalid: { return "INVALID"; }
  }
  // Remove annoying -Wreturn-type warning
  return "OOPS";
}

