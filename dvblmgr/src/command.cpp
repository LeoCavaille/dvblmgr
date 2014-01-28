#include "command.hpp"

#include <iostream>

Command::Command() {}

void Command::execute() const {
  std::cerr << "Execute command" << std::endl;
  std::cerr << "\tType: " << static_cast<unsigned int>(type_)
            << "\tRecipient: " << recipient_ << std::endl;
  std::cerr << "\tMessage: " << message_ << std::endl;
}
