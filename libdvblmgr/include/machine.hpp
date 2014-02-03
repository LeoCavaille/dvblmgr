#ifndef MACHINE_HPP_
#define MACHINE_HPP_

#include "yaml/machine.hpp"
#include "ptr/adapter.hpp"

#include <boost/uuid/uuid.hpp>
#include <string>
#include <vector>

class Machine {
public:
  Machine();

  friend YAML::Node YAML::convert<MachinePtr>::encode(const MachinePtr &rhs);
  friend bool YAML::convert<MachinePtr>::decode(const YAML::Node &node,
                                                MachinePtr &rhs);

  std::string getID() const;
  std::string getIP() const { return ip_; }

  bool operator==(const Machine &rhs) const;

  const std::vector<AdapterPtr> &getAdapters() const {
    return adapters_;
  };
  bool isConnected() const { return connected_; }
  void setConnected(const bool &b) { connected_ = b; }

private:
  std::string name_;
  std::string ip_;
  std::vector<AdapterPtr> adapters_;

  bool connected_;
  boost::uuids::uuid ID_;
};

#endif /* MACHINE_HPP_ */
