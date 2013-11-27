#ifndef CHANNEL_H_
#define CHANNEL_H_

#include "confobject.h"

#include <vector>
#include <string>

class Channel:
    public ConfObject
{

private:
    unsigned int sid_;
    std::vector<int> pid_;
    std::string name_;

};

#endif /* CHANNEL_H_ */
