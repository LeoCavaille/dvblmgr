#include "adapter.h"
#include "gtest/gtest.h"

const AntennaType at = AntennaType::DVB_S;
const AntennaType at2 = AntennaType::DVB_S2;
const AntennaType at3 = AntennaType::DVB_T;

const Antenna a("astra19.2");

TEST(AdapterAntennaTest, Antenna_GetName)
{
	ASSERT_EQ(a.getName(), "astra19.2");
}

TEST(AdapterAntennaTest, Antenna_EqualOperator)
{
	const Antenna b("hotbird23");
	const Antenna c("astra19.2");
	ASSERT_NE(a, b);
	ASSERT_EQ(a, c);
}

TEST(AdapterAntennaTest, Adapter_GetId)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	const Adapter adap(0, 2, a, atc);
	ASSERT_EQ(adap.getId(), 0);
}

TEST(AdapterAntennaTest, Adapter_GetFrontendId)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	const Adapter adap(0, 2, a, atc);
	ASSERT_EQ(adap.getFrontendId(), 2);
}

TEST(AdapterAntennaTest, Adapter_GetAntenna)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	const Adapter adap(0, 2, a, atc);
	ASSERT_EQ(adap.getAntenna(), a);
}

TEST(AdapterAntennaTest, Adapter_IsCompatible)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	const Adapter adap(0, 2, a, atc);
    ASSERT_TRUE(adap.isCompatible(AntennaType::DVB_S));
    ASSERT_FALSE(adap.isCompatible(AntennaType::DVB_T));
}