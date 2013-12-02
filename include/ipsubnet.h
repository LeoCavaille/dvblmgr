#ifndef IPSUBNET_H_
#define IPSUBNET_H_

#include "confobject.h"

#include <set>
#include <string>
#include <arpa/inet.h>

class IPSubnet : public ConfObject {
public:
  IPSubnet(const in_addr &baseIP, const int &netmask);

  in_addr get();
  void release(const in_addr &addr);
  int getBusyCount() const;

  bool contain(const u_int32_t &address) const;
  bool contain(const std::string &address) const;

  std::string string() const;

private:
  in_addr baseIP_;
  in_addr netmask_;
  int intmask_;

  std::set<int> pool_;

private:
  static u_int32_t IPint32lshifted(const int &shift);
};

#endif /* IPSUBNET_H_ */
