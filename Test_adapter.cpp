#include "adapter.h"
#include "gtest/gtest.h"

const Antenna a("astra19.2");
std::vector<AntennaType> atc { AntennaType::DVB_S, AntennaType::DVB_S2 };
const Adapter adap(0, 2, a, atc);

TEST(AdapterTest, Adapter_GetId)
{
	ASSERT_EQ(adap.getId(), 0);
}

TEST(AdapterTest, Adapter_GetFrontendId)
{
	ASSERT_EQ(adap.getFrontendId(), 2);
}

TEST(AdapterTest, Adapter_GetAntenna)
{
	ASSERT_EQ(adap.getAntenna(), a);
}

TEST(AdapterTest, Adapter_IsCompatible)
{
    ASSERT_TRUE(adap.isCompatible(AntennaType::DVB_S));
    ASSERT_FALSE(adap.isCompatible(AntennaType::DVB_T));
}
