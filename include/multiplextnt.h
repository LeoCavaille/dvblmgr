#ifndef MULTIPLEXTNT_H_
#define MULTIPLEXTNT_H_

#include "multiplex.h"

class MultiplexTnt : public Multiplex {
public:
  bool isCompatible(const AdapterPtr &a) const;

private:
  // in Hz
  unsigned int bandwidth_;
};

#endif /* MULTIPLEXTNT_H_ */
