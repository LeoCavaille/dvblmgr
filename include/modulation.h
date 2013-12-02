#ifndef MODULATION_H_
#define MODULATION_H_

#include "confobject.h"

#include <string>

class Modulation : public ConfObject {
public:
  enum Enum {
    none,
    qpsk,
    eightpsk,
    invalid
  };

  Modulation();
  Modulation(Enum m);
  explicit Modulation(const std::string &m);

  bool operator==(const std::string &ss) const;
  static Enum FromString(std::string mString);
  static std::string ToString(const Enum &m);

private:
  Enum mod_;
  std::string modString_;
};

#endif /* MODULATION_H_ */
