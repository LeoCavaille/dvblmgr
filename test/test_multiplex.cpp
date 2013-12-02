#include "multiplex.h"
#include <fstream>

#include "gtest/gtest.h"

TEST(MultiplexTest, YAMLGoodParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/multiplex/good.yaml");
}
