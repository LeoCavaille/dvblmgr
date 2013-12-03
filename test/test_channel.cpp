#include "channel.h"
#include <fstream>

#include "gtest/gtest.h"

TEST(ChannelTest, YAMLGoodParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/channel/good.yaml");
  Channel c = doc.as<Channel>();

  Channel d("France 2", 1234, {2342, 2343, 2344});

  ASSERT_EQ(c, d);
}

TEST(ChannelTest, YAMLBadParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/channel/bad.yaml");
  ASSERT_ANY_THROW(Channel c = doc.as<Channel>());
}

TEST(ChannelTest, YAMLGoodEncoding) {
  Channel d("France 2", 1234, {2342, 2343, 2344});

  YAML::Node doc;
  // Magic operator overloading!
  doc = d;

  Channel c = doc.as<Channel>();

  ASSERT_EQ(c, d);
}