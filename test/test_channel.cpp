#include "channel.h"

#include "gtest/gtest.h"

TEST(ChannelTest, YAMLGoodParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/channel/good.yaml");
  ChannelPtr c = doc.as<ChannelPtr>();

  Channel d("France 2", 1234, {2342, 2343, 2344});

  ASSERT_EQ(*c, d);
}

TEST(ChannelTest, YAMLBadParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/channel/bad.yaml");
  ASSERT_ANY_THROW(ChannelPtr c = doc.as<ChannelPtr>());
}

TEST(ChannelTest, YAMLGoodEncoding) {
  ChannelPtr d = std::make_shared<Channel>("France 2", 1234, {2342, 2343, 2344});
  //ChannelPtr d(new Channel("France 2", 1234, {2342, 2343, 2344}));
  //Channel d("France 2", 1234, {2342, 2343, 2344});w

  YAML::Node doc;
  // Magic operator overloading!
  doc = d;

  ChannelPtr c = doc.as<ChannelPtr>();

  ASSERT_EQ(*c, *d);
}

