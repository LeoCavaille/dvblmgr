#ifndef MULTIPLEX_H_
#define MULTIPLEX_H_

#include "adapter.h"
#include "antenna.h"
#include "antennatype.h"
#include "modulation.h"
#include "polarization.h"
#include "channel.h"
#include <vector>

class Multiplex {
public:
  bool isCompatible(const Adapter &a) const;

private:
  // in Hz
  unsigned int frequency_;
  unsigned int symbolRate_;
  unsigned int priority_;

  Polarization polarization_;
  Modulation modulation_;

  Antenna antenna_;
  AntennaType antennaType_;

  std::vector<Channel> channels_;
};

#endif /* MULTIPLEX_H_ */
