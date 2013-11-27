#ifndef ANTENNA_H_
#define ANTENNA_H_

#include "confobject.h"

#include <string>

class Antenna:
    public ConfObject
{
public:
	Antenna(const std::string& name): name_(name)
	{}

	std::string const& getName() const 
	{
		return name_;
	}

	bool operator==(const Antenna& rhs) const
	{
		return name_ == rhs.name_;
	}
	bool operator!=(const Antenna& rhs) const
	{
		return !(*this == rhs);
	}

private:
	std::string name_;
};


#endif /* ANTENNA_H_ */
