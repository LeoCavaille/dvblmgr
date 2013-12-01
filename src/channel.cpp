#include "channel.h"

Channel::Channel() : broadcast_(false) {}

Channel::Channel(const std::string name, const unsigned int &sid,
                 const std::vector<unsigned int> &pids)
    : name_(name), sid_(sid), pids_(pids), broadcast_(false) {}
