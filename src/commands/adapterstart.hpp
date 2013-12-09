#ifndef ADAPTERSTART_HPP_
#define ADAPTERSTART_HPP_

#include "adapter_ptr.h"
#include "multiplex_ptr.h"

#include "../command.hpp"

class AdapterStartCommand : public Command {
public:
  AdapterStartCommand(const AdapterPtr &a, const MultiplexPtr &m);

private:
  const CommandType Type_ = CommandType::ADAPTER_START;
};

#endif /* ADAPTERSTART_HPP_ */
