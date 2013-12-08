#include "multiplex.h"
#include "multiplexsat.h"
#include "multiplextnt.h"
#include <fstream>

#include "gtest/gtest.h"

TEST(MultiplexTest, YAMLGoodSATParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/multiplex/good_dvbs.yaml");
  std::string type = Multiplex::getType(doc);

  ASSERT_EQ(type, "SAT");

  MultiplexSatPtr m = std::make_shared<MultiplexSat>();
  ASSERT_TRUE(YAML::convert<MultiplexSatPtr>::decode(doc, m));
}

TEST(MultiplexTest, YAMLGoodTNTParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/multiplex/good_dvbt.yaml");
  std::string type = Multiplex::getType(doc);

  ASSERT_EQ(type, "TNT");

  MultiplexTntPtr m = std::make_shared<MultiplexTnt>();
  ASSERT_TRUE(YAML::convert<MultiplexTntPtr>::decode(doc, m));
}
