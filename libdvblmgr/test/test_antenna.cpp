#include "antenna.hpp"
#include "gtest/gtest.h"

const Antenna a("astra19.2");

TEST(AntennaTest, Antenna_EqualOperator) {
  const Antenna b("hotbird23");
  const Antenna c("astra19.2");
  ASSERT_NE(a, b);
  ASSERT_EQ(a, c);
}