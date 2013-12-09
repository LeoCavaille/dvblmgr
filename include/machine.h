#ifndef MACHINE_H_
#define MACHINE_H_

#include "machine_yaml.h"
#include "adapter_ptr.h"

#include <string>
#include <vector>

class Machine {
public:
  Machine();

  friend YAML::Node YAML::convert<MachinePtr>::encode(const MachinePtr &rhs);
  friend bool YAML::convert<MachinePtr>::decode(const YAML::Node &node,
                                               MachinePtr &rhs);

  bool operator== (const Machine &rhs) const;

private:
  std::string name_;
  std::vector<AdapterPtr> adapters_;

  bool connected_;
};

#endif /* MACHINE_H_ */
