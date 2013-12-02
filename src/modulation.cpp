#include "modulation.h"

#include <algorithm>
#include <stdexcept>

Modulation::Modulation() : mod_(none), modString_("None") {}

Modulation::Modulation(Enum m) : mod_(m), modString_(ToString(m)) {}

Modulation::Modulation(const std::string &mString)
    : mod_(FromString(mString)), modString_(mString) {}

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
  case none: { return "none"; }
  case qpsk: { return "qpsk"; }
  case eightpsk: { return "8psk"; }
  case invalid: { return "invalid"; }
  }
  // Remove annoying -Wreturn-type warning
  return "OOPS";
}

