#include "adapter.h"
#include "gtest/gtest.h"

const Antenna a("astra19.2");

TEST(AdapterTest, Adapter_GetId)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	const Adapter adap(0, 2, a, atc);
	ASSERT_EQ(adap.getId(), 0);
}

TEST(AdapterTest, Adapter_GetFrontendId)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	const Adapter adap(0, 2, a, atc);
	ASSERT_EQ(adap.getFrontendId(), 2);
}

TEST(AdapterTest, Adapter_GetAntenna)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	const Adapter adap(0, 2, a, atc);
	ASSERT_EQ(adap.getAntenna(), a);
}

TEST(AdapterTest, Adapter_IsCompatible)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	const Adapter adap(0, 2, a, atc);
    ASSERT_TRUE(adap.isCompatible(AntennaType::DVB_S));
    ASSERT_FALSE(adap.isCompatible(AntennaType::DVB_T));
}