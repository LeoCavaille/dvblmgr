#ifndef SERVER_H_
#define SERVER_H_

#include "server_yaml.h"

#include <string>

class Server {
public:
	Server();

  friend YAML::Node YAML::convert<ServerPtr>::encode(const ServerPtr &rhs);
  friend bool YAML::convert<ServerPtr>::decode(const YAML::Node &node,
		  ServerPtr &rhs);


private:
	std::string name_;

	bool connected_;
};




#endif /* SERVER_H_ */
