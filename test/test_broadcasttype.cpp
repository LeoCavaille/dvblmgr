#include "broadcasttype.h"

#include "gtest/gtest.h"

TEST(BroadcastTypeTest, DVBSYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/broadcasttype/dvbs.yaml");
  BroadcastTypePtr bt = doc["broadcastType"].as<BroadcastTypePtr>();

  ASSERT_EQ(*bt, BroadcastType::dvbs);
}

TEST(BroadcastTypeTest, DVBS2YamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/broadcasttype/dvbs2.yaml");
  BroadcastTypePtr bt = doc["broadcastType"].as<BroadcastTypePtr>();

  ASSERT_EQ(*bt, BroadcastType::dvbstwo);
}

TEST(BroadcastTypeTest, DVBTYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/broadcasttype/dvbt.yaml");
  BroadcastTypePtr bt = doc["broadcastType"].as<BroadcastTypePtr>();

  ASSERT_EQ(*bt, BroadcastType::dvbt);
}

TEST(BroadcastTypeTest, InvalidYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/broadcasttype/bad.yaml");
  ASSERT_ANY_THROW(doc["broadcastType"].as<BroadcastTypePtr>());
}
