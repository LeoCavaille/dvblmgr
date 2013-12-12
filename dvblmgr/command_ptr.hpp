#ifndef COMMANDPTR_H_
#define COMMANDPTR_H_

#include <memory>

class Command;
typedef std::shared_ptr<Command> CommandPtr;

#endif /* COMMANDPTR_H_ */
