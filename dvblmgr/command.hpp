#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include "commandtype.h"

#include <string>

class Command {
public:
  Command();
  Command(const unsigned char &type, const std::string &recipient,
          const std::string &message);

  void execute() const;

protected:
  CommandType type_;
  std::string recipient_;
  std::string message_;
};

#endif /* COMMAND_HPP_ */
