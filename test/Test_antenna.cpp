#include "antenna.h"
#include "antennatype.h"
#include "gtest/gtest.h"

const AntennaType at = AntennaType::DVB_S;
const AntennaType at2 = AntennaType::DVB_S2;
const AntennaType at3 = AntennaType::DVB_T;

const Antenna a("astra19.2");

TEST(AntennaTest, Antenna_GetName)
{
	ASSERT_EQ(a.getName(), "astra19.2");
}

TEST(AntennaTest, Antenna_EqualOperator)
{
	const Antenna b("hotbird23");
	const Antenna c("astra19.2");
	ASSERT_NE(a, b);
	ASSERT_EQ(a, c);
}