#include "polarization.h"

#include <algorithm>

Polarization::Polarization() : polarization_(none), pString_("NONE") {}

Polarization::Polarization(Enum p) : polarization_(p), pString_(ToString(p)) {}

Polarization::Polarization(const std::string &pString) {
  polarization_ = FromString(pString);
  pString_ = ToString(polarization_);
}

bool Polarization::operator==(const Enum &rhs) const
{
  return (polarization_ == rhs);
}

bool Polarization::operator==(const PolarizationPtr &rhs) const
{
  return (polarization_ == rhs->polarization_);
}

Polarization::Enum Polarization::FromString(std::string pString) {
  transform(pString.begin(), pString.end(), pString.begin(), toupper);

  if (pString == "VERTICAL") {
    return vertical;
  } else if (pString == "HORIZONTAL") {
    return horizontal;
  } else if (pString == "NONE") {
    return none;
  }

  return invalid;
}

std::string Polarization::ToString(const Polarization::Enum &p) {
  switch (p) {
  case vertical: { return "VERTICAL"; }
  case horizontal: { return "HORIZONTAL"; }
  case none: { return "NONE"; }
  }

  return "INVALID";
}

