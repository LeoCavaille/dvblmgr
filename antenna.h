#ifndef ANTENNA_H_
#define ANTENNA_H_

#include <string>

class Antenna {
public:
	Antenna(const std::string& name): name_(name)
	{}

	std::string const& getName() const 
	{
		return name_;
	}
private:
	std::string name_;
};


#endif /* ANTENNA_H_ */
