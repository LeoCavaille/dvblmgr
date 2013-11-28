#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "confobject.h"

#include <vector>
#include <string>

class Channel:
    public ConfObject
{


private:
	// Main characteristics
    unsigned int sid_;
    std::vector<int> pid_;
    std::string name_;


    // Broadcast utils
    bool broadcast_;
    
};

#endif /* CHANNEL_H_ */
