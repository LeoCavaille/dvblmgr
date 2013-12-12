/*
 * This is some code which was deliberately stolen from someone from another
 * project
 * because I don't like netmasks very much, thank you Utab!
 */

#include "ipsubnet.hpp"

#include <sstream>

IPSubnet::IPSubnet(const in_addr &baseIP, const int &netmask) {
  if (netmask >= 32) {
    netmask_.s_addr = ~0;
    intmask_ = 32;
  } else if (netmask <= 0) {
    netmask_.s_addr = 0;
    intmask_ = 0;
  } else {
    intmask_ = netmask;
    netmask_.s_addr = IPint32lshifted(32 - netmask);
  }
  baseIP_.s_addr = baseIP.s_addr & netmask_.s_addr;
}

// FIXME : to be mutexed
in_addr IPSubnet::get() {
  in_addr returnedAddr = baseIP_;
  int cursor = 0;

  while (pool_.count(cursor) != 0) {
    returnedAddr.s_addr = ntohl(htonl(returnedAddr.s_addr) + 1);
    if (!contain(returnedAddr.s_addr)) {
      // TODO define a better exception here
      throw "IPSubnet full";
    }
    cursor++;
  }
  pool_.insert(cursor);

  return returnedAddr;
}

void IPSubnet::release(const in_addr &addr) {
  pool_.erase(htonl(addr.s_addr) - htonl(baseIP_.s_addr));
}

bool IPSubnet::contain(const u_int32_t &address) const {
  return (baseIP_.s_addr == (address & netmask_.s_addr));
}

bool IPSubnet::contain(const std::string &address) const {
  in_addr a;
  inet_pton(AF_INET, address.c_str(), &a);
  return contain(a.s_addr);
}

int IPSubnet::getBusyCount() const {
  return pool_.size();
}

std::string IPSubnet::string() const {
  std::ostringstream result;
  char buffer[INET_ADDRSTRLEN];
  result << inet_ntop(AF_INET, &baseIP_, buffer, INET_ADDRSTRLEN);
  result << "/";
  result << intmask_;
  return result.str();
}

u_int32_t IPSubnet::IPint32lshifted(const int &zeros) {
  u_int8_t result[4];

  if (zeros >= 8) {
    result[3] = 0;
    if (zeros >= 16) {
      result[2] = 0;
      if (zeros >= 24) {
        result[1] = 0;
        result[0] = ((~(u_int8_t) 0) << (zeros - 24));
      } else {
        result[1] = ((~(u_int8_t) 0) << (zeros - 16));
        result[0] = (~(u_int8_t) 0);
      }
    } else {
      result[2] = ((~(u_int8_t) 0) << (zeros - 8));
      result[1] = (~(u_int8_t) 0);
      result[0] = (~(u_int8_t) 0);
    }
  } else {
    result[3] = ((~(u_int8_t) 0) << zeros);
    result[2] = (~(u_int8_t) 0);
    result[1] = (~(u_int8_t) 0);
    result[0] = (~(u_int8_t) 0);
  }

  return (*((u_int32_t *)result));
}