#include "channel.h"

#include "gtest/gtest.h"

TEST(ChannelTest, YAMLGoodParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/channel/good.yaml");
  ChannelPtr c = std::make_shared<Channel>();
  ASSERT_TRUE(YAML::convert<ChannelPtr>::decode(doc, c));

  Channel d("France 2", 1234, {2342, 2343, 2344});

  ASSERT_EQ(*c, d);
}

TEST(ChannelTest, YAMLBadParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/channel/bad.yaml");
  ChannelPtr c = std::make_shared<Channel>();
  ASSERT_ANY_THROW(ASSERT_FALSE(YAML::convert<ChannelPtr>::decode(doc, c)));
}

TEST(ChannelTest, YAMLGoodEncoding) {
  ChannelPtr d = std::make_shared<Channel>("France 2", 1234, std::vector<unsigned int> {2342, 2343, 2344});

  YAML::Node doc;
  // Magic operator overloading!
  doc = d;

  ChannelPtr c = std::make_shared<Channel>();
  ASSERT_TRUE(YAML::convert<ChannelPtr>::decode(doc, c));

  ASSERT_EQ(*c, *d);
}

