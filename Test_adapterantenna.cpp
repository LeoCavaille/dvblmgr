#include "adapter.h"

#include "gtest/gtest.h"

TEST(AdapterAntennaTest, AntennaTypeConstructor)
{
	const AntennaType at = AntennaType::DVB_S;
	ASSERT_EQ(at, AntennaType::DVB_S);
	const AntennaType at2 = AntennaType::DVB_S2;
	ASSERT_EQ(at2, AntennaType::DVB_S2);
	const AntennaType at3 = AntennaType::DVB_T;
	ASSERT_EQ(at3, AntennaType::DVB_T);
}

TEST(AdapterAntennaTest, AntennaTypeCompatConstructor)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	ASSERT_EQ(atc.size(), 2);
	ASSERT_EQ(atc[0], AntennaType::DVB_S);
	ASSERT_EQ(atc[1], AntennaType::DVB_S2);
}

TEST(AdapterAntennaTest, AntennaConstructor)
{
	const Antenna a("astra19.2");
	ASSERT_EQ(a.getName(), "astra19.2");
}

TEST(AdapterAntennaTest, AntennaEqualOperator)
{
	const Antenna a("astra19.2");
	const Antenna b("hotbird23");
	const Antenna c("astra19.2");
	ASSERT_NE(a, b);
	ASSERT_EQ(a, c);
}

TEST(AdapterAntennaTest, AdapterConstructor)
{
	// Building an adapter /dev/dvb/adapter0/frontend2
	// with astra19.2 plug and DVB-S/DVB-S2 compatibility

	const Antenna a("astra19.2");
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);

	const Adapter adap(0, 2, a, atc);
    ASSERT_EQ(adap.getId(), 0);
    ASSERT_EQ(adap.getFrontendId(), 2);
    ASSERT_EQ(adap.getAntenna(), a);

}