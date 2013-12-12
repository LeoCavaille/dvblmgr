#ifndef HEARTBEAT_HPP_
#define HEARTBEAT_HPP_

#include "ptr/machine.hpp"

#include "../command.hpp"


class Heartbeat : public Command {
public:
  Heartbeat(const MachinePtr &mPtr);

private:
  const CommandType Type_ = CommandType::HEARTBEAT;
};

#endif /* HEARTBEAT_HPP_ */
