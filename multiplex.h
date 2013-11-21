#ifndef MULTIPLEX_H_
#define MULTIPLEX_H_

#include "polarization.h"

class Multiplex {
public:

private:
	// in Hz
	unsigned int frequency_;
	unsigned int symbolRate_;

	Polarization polarization_;
	Modulation modulation_;

	Antenna antenna_;

	
};

#endif /* MULTIPLEX_H_ */
