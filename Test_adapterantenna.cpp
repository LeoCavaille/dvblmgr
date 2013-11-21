#include "adapter.h"

#include "gtest/gtest.h"

TEST(AdapterAntennaTest, AntennaTypeConstructor)
{
	const AntennaType at = AntennaType::DVB_S;
	EXPECT_EQ(at, AntennaType::DVB_S);
	const AntennaType at2 = AntennaType::DVB_S2;
	EXPECT_EQ(at2, AntennaType::DVB_S2);
	const AntennaType at3 = AntennaType::DVB_T;
	EXPECT_EQ(at3, AntennaType::DVB_T);
}

TEST(AdapterAntennaTest, AntennaTypeCompatConstructor)
{
	std::vector<AntennaType> atc;
	atc.push_back(AntennaType::DVB_S);
	atc.push_back(AntennaType::DVB_S2);
	EXPECT_EQ(atc.size(), 2);
	EXPECT_EQ(atc[0], AntennaType::DVB_S);
	EXPECT_EQ(atc[1], AntennaType::DVB_S2);
}

TEST(AdapterAntennaTest, AntennaConstructor)
{
	const Antenna a("astra19.2");
	EXPECT_EQ(a.getName(), "astra19.2");
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
    EXPECT_EQ(0, adap.getId());
    EXPECT_EQ(2, adap.getFrontendId());
}