#ifndef MULTIPLEX_H_
#define MULTIPLEX_H_

#include "adapterptr.h"
#include "antennaptr.h"
#include "antennatypeptr.h"
#include "channelptr.h"
#include "modulationptr.h"
#include "polarizationptr.h"

#include "confobject.h"

#include <vector>

class Multiplex : public ConfObject {
public:
  bool isCompatible(const AdapterPtr &a) const;

private:
  // in Hz
  unsigned int frequency_;
  unsigned int symbolRate_;
  unsigned int priority_;

  PolarizationPtr p_polarization_;
  ModulationPtr p_modulation_;

  AntennaPtr antenna_;
  AntennaTypePtr antennaType_;

  std::vector<ChannelPtr> channels_;
};

#endif /* MULTIPLEX_H_ */
