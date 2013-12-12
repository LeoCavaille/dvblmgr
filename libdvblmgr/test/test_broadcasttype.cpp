#include "broadcasttype.hpp"

#include "gtest/gtest.h"

TEST(BroadcastTypeTest, DVBSYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/broadcasttype/dvbs.yaml");
  BroadcastTypePtr p = std::make_shared<BroadcastType>();
  
  ASSERT_TRUE(YAML::convert<BroadcastTypePtr>::decode(doc["broadcastType"], p));
  ASSERT_EQ(*p, BroadcastType::dvbs);
}

TEST(BroadcastTypeTest, DVBS2YamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/broadcasttype/dvbs2.yaml");
  BroadcastTypePtr p = std::make_shared<BroadcastType>();

  ASSERT_TRUE(YAML::convert<BroadcastTypePtr>::decode(doc["broadcastType"], p));
  ASSERT_EQ(*p, BroadcastType::dvbstwo);
}

TEST(BroadcastTypeTest, DVBTYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/broadcasttype/dvbt.yaml");
  BroadcastTypePtr p = std::make_shared<BroadcastType>();

  ASSERT_TRUE(YAML::convert<BroadcastTypePtr>::decode(doc["broadcastType"], p));
  ASSERT_EQ(*p, BroadcastType::dvbt);
}

TEST(BroadcastTypeTest, InvalidYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/broadcasttype/bad.yaml");
  BroadcastTypePtr p = std::make_shared<BroadcastType>();

  ASSERT_FALSE(YAML::convert<BroadcastTypePtr>::decode(doc["broadcastType"], p));
  ASSERT_EQ(*p, BroadcastType::invalid);
}
