#include "multiplex.h"
#include <fstream>

#include "gtest/gtest.h"

TEST(MultiplexTest, YAMLGoodParsing) {
  YAML::Node doc = YAML::LoadFile("test/yaml/multiplex/good.yaml");
  Channel c = doc.as<Channel>();
}