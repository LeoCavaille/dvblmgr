#include "channel.h"
#include <fstream>

#include "gtest/gtest.h"

TEST(ChannelTest, YAMLGoodParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/channel/good.yaml");
  Channel c = doc.as<Channel>();
}

TEST(ChannelTest, YAMLBadParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/channel/bad.yaml");
  ASSERT_ANY_THROW(Channel c = doc.as<Channel>());
}
