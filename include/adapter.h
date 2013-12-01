#ifndef ADAPTER_H_
#define ADAPTER_H_

#include "antenna.h"
#include "antennatype.h"
#include "confobject.h"

#include <vector>

class Adapter : public ConfObject {
public:
  Adapter(const unsigned char &id, const unsigned char &frontendId,
          const Antenna &antenna, const std::vector<AntennaType> &compat);

  bool isCompatible(const AntennaType &at) const;

private:
  unsigned char id_;
  unsigned char frontendId_;
  Antenna antenna_;
  std::vector<AntennaType> compat_;
};

#endif /* ADAPTER_H_ */
