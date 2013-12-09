#include "broadcasttype.h"

#include <algorithm>

BroadcastType::BroadcastType() : type_(none), typeString_("NONE") {}

BroadcastType::BroadcastType(Enum m) : type_(m), typeString_(ToString(m)) {}

BroadcastType::BroadcastType(const std::string &mString)
    : type_(FromString(mString))
{
  typeString_ = ToString(type_);
}

bool BroadcastType::operator==(const Enum &rhs) const
{
  return (type_ == rhs);
}

bool BroadcastType::operator==(const BroadcastType &rhs) const
{
  return (type_ == rhs.type_);
}

BroadcastType::Enum BroadcastType::FromString(std::string mString) {
  transform(mString.begin(), mString.end(), mString.begin(), toupper);

  if (mString == "DVB-S") {
    return dvbs;
  } else if (mString == "DVB-S2") {
    return dvbstwo;
  } else if (mString == "DVB-T") {
    return dvbt;
  } else if (mString == "NONE") {
    return none;
  }

  return invalid;
}

std::string BroadcastType::ToString(const BroadcastType::Enum &m) {
  switch (m) {
  case none: { return "NONE"; }
  case dvbs: { return "DVB-S"; }
  case dvbstwo: { return "DVB-S2"; }
  case dvbt: { return "DVB-T"; }
  }

  return "INVALID";
}

