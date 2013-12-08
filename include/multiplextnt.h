#ifndef MULTIPLEXTNT_H_
#define MULTIPLEXTNT_H_

#include "multiplex.h"

#include "multiplextnt_yaml.h"

class MultiplexTnt;

class MultiplexTnt : public Multiplex {
public:
  bool isCompatible(const AdapterPtr &a) const;

  friend YAML::Node YAML::convert<MultiplexTntPtr>::encode(const MultiplexTntPtr &rhs);
  friend bool YAML::convert<MultiplexTntPtr>::decode(const YAML::Node &node,
		  MultiplexTntPtr rhs);

private:
  // in Hz
  unsigned int bandwidth_;
};

#endif /* MULTIPLEXTNT_H_ */
