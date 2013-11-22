#ifndef MULTIPLEX_H_
#define MULTIPLEX_H_

#include "polarization.h"
#include "channel.h"
#include <vector>

class Multiplex {
public:

private:
	// in Hz
	unsigned int frequency_;
    unsigned int symbolRate_;
	unsigned int priority_;

	Polarization polarization_;
	Modulation modulation_;

	Antenna antenna_;

    std::vector<Channel> channels_;
};

#endif /* MULTIPLEX_H_ */
