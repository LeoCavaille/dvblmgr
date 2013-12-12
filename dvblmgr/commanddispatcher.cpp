#include "commanddispatcher.hpp"

#include "command.hpp"

#include <chrono>
#include <iostream>

CommandDispatcher::CommandDispatcher() :
stopSignal_(false)
{}

void CommandDispatcher::queue(const CommandPtr &cPtr) {
	mutex_.lock();
	commands_.push_back(cPtr);
	mutex_.unlock();
}

void CommandDispatcher::mainLoop() {
	while(true) {
		mutex_.lock();
		if(stopSignal_) {
			std::cerr << "INFO: CommandDispatcher required to stop, stopping !" << std::endl;
			mutex_.unlock();
			return;
		}
		mutex_.unlock();
		std::cerr << "INFO: CommandDispatcher mainLoop reporting" << std::endl;
		while(gotCommands()) {
			launchCommands();
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void CommandDispatcher::start() {
	std::cerr << "INFO: CommandDispatcher starting" << std::endl;
	dispatcherThread_ = std::thread(&CommandDispatcher::mainLoop, this);
}

void CommandDispatcher::stop() {
	mutex_.lock();
	stopSignal_ = true;
	mutex_.unlock();
	dispatcherThread_.join();
}

bool CommandDispatcher::gotCommands() const { return commands_.size() != 0; }

void CommandDispatcher::launchCommands() {
	mutex_.lock();
  CommandPtr cPtr = commands_.front();
  cPtr->execute();
  commands_.pop_front();
  mutex_.unlock();
}
