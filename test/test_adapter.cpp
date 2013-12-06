#include "adapter.h"
#include "antenna.h"
#include "broadcasttype.h"
#include "gtest/gtest.h"

AntennaPtr ant = std::make_shared<Antenna>("astra19.2");
BroadcastTypePtr bt1 = std::make_shared<BroadcastType>("DVB-S");
BroadcastTypePtr bt2 = std::make_shared<BroadcastType>("DVB-S2");
BroadcastTypePtr bt3 = std::make_shared<BroadcastType>("DVB-T");

std::vector<BroadcastTypePtr> btc { bt1, bt2 };

const Adapter adap(0, 2, ant, btc);

TEST(AdapterTest, Adapter_IsCompatible) {

  BroadcastTypePtr p1 = std::make_shared<BroadcastType>(BroadcastType::dvbs);
  BroadcastTypePtr p2 = std::make_shared<BroadcastType>(BroadcastType::dvbt);

  ASSERT_TRUE(adap.isCompatible(p1));
  ASSERT_FALSE(adap.isCompatible(p2));
}
