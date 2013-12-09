#ifndef SERVER_H_
#define SERVER_H_

#include "server_yaml.h"
#include "adapter_ptr.h"

#include <string>
#include <vector>

class Server {
public:
  Server();

  friend YAML::Node YAML::convert<ServerPtr>::encode(const ServerPtr &rhs);
  friend bool YAML::convert<ServerPtr>::decode(const YAML::Node &node,
                                               ServerPtr &rhs);

  bool operator== (const Server &rhs) const;

private:
  std::string name_;
  std::vector<AdapterPtr> adapters_;

  bool connected_;
};

#endif /* SERVER_H_ */
