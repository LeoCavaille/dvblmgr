#include "multiplex.h"
#include <fstream>

#include "gtest/gtest.h"

TEST(MultiplexTest, YAMLGoodSATParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/multiplex/good_dvbs.yaml");
}

TEST(MultiplexTest, YAMLGoodTNTParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/multiplex/good_dvbt.yaml");
}
