#include "multiplex.hpp"
#include "polarization.hpp"
#include "modulation.hpp"
#include "channel.hpp"
#include "broadcasttype.hpp"
#include "multiplexsat.hpp"
#include "multiplextnt.hpp"
#include "antenna.hpp"
#include <fstream>

#include "gtest/gtest.h"

TEST(MultiplexTest, YAMLGoodSATParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/multiplex/good_dvbs.yaml");
  std::string type = Multiplex::getType(doc);

  ASSERT_EQ(type, "SAT");

  MultiplexSatPtr m = std::make_shared<MultiplexSat>();
  ASSERT_TRUE(YAML::convert<MultiplexSatPtr>::decode(doc, m));

  // We don't test if channels are correctly parsed here
  std::vector<ChannelPtr> channels = {};
  MultiplexSat ms(
      "sat-1", 586166000, std::make_shared<BroadcastType>(BroadcastType::dvbs),
      channels, 1337, std::make_shared<Polarization>(Polarization::vertical),
      std::make_shared<Modulation>(Modulation::qpsk),
      std::make_shared<Antenna>("astra19.2"));

  ASSERT_EQ(*m, ms);
}

TEST(MultiplexTest, YAMLGoodTNTParsing) {
  YAML::Node doc = YAML::LoadFile("yaml/multiplex/good_dvbt.yaml");
  std::string type = Multiplex::getType(doc);

  ASSERT_EQ(type, "TNT");

  MultiplexTntPtr m = std::make_shared<MultiplexTnt>();
  ASSERT_TRUE(YAML::convert<MultiplexTntPtr>::decode(doc, m));

  // We don't test if channels are correctly parsed here
  std::vector<ChannelPtr> channels = {};
  MultiplexTnt ms("tnt-1", 586166000,
                  std::make_shared<BroadcastType>(BroadcastType::dvbt),
                  channels, 8);

  ASSERT_EQ(*m, ms);
}

TEST(MultiplexTest, YAMLGoodSATEncoding) {
  std::vector<ChannelPtr> channels = {};
  MultiplexSatPtr ms = std::make_shared<MultiplexSat>(
      "SAT_15", 123214534, std::make_shared<BroadcastType>(BroadcastType::dvbs),
      channels, 12857453,
      std::make_shared<Polarization>(Polarization::vertical),
      std::make_shared<Modulation>(Modulation::qpsk),
      std::make_shared<Antenna>("astra42.12"));

  YAML::Node node;
  node = ms;

  MultiplexSatPtr m = std::make_shared<MultiplexSat>();
  ASSERT_TRUE(YAML::convert<MultiplexSatPtr>::decode(node, m));

  ASSERT_EQ(*m, *ms);
}

TEST(MultiplexTest, YAMLGoodTNTEncoding) {
  std::vector<ChannelPtr> channels = {};
  MultiplexTntPtr ms = std::make_shared<MultiplexTnt>(
      "tnt-42", 189346, std::make_shared<BroadcastType>(BroadcastType::dvbt),
      channels, 12);

  YAML::Node node;
  node = ms;

  MultiplexTntPtr m = std::make_shared<MultiplexTnt>();
  ASSERT_TRUE(YAML::convert<MultiplexTntPtr>::decode(node, m));

  ASSERT_EQ(*m, *ms);
}
