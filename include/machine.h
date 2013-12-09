#ifndef MACHINE_H_
#define MACHINE_H_

#include "machine_yaml.h"
#include "adapter_ptr.h"

#include "confobject.h"

#include <boost/uuid/uuid.hpp>
#include <string>
#include <vector>

class Machine :
	public ConfObject {
public:
  Machine();
  Machine(const ConfigurationPtr& cPtr);

  friend YAML::Node YAML::convert<MachinePtr>::encode(const MachinePtr &rhs);
  friend bool YAML::convert<MachinePtr>::decode(const YAML::Node &node,
                                               MachinePtr &rhs);

  std::string getID() const;

  bool operator== (const Machine &rhs) const;

  const std::vector<AdapterPtr>& getAdapters() const { return adapters_; };
  bool connected() const {
	return connected_;
  }

private:
  std::string name_;
  std::vector<AdapterPtr> adapters_;

  bool connected_;
  boost::uuids::uuid ID_;
};

#endif /* MACHINE_H_ */
