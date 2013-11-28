#include "ipsubnet.h"
#include "gtest/gtest.h"

TEST(IPSubnetTest, ConstructorBase)
{
	in_addr a;
	inet_aton("239.255.42.0", &a);
	const IPSubnet sub(a, 24);

	ASSERT_EQ(sub.string(), "239.255.42.0/24");
}

TEST(IPSubnetTest, Contain)
{
	in_addr a;
	inet_aton("239.255.42.0", &a);
	const IPSubnet sub(a, 24);

	ASSERT_TRUE(sub.contain("239.255.42.0"));
	ASSERT_TRUE(sub.contain("239.255.42.25"));
	ASSERT_TRUE(sub.contain("239.255.42.255"));
	ASSERT_FALSE(sub.contain("239.255.41.255"));
	ASSERT_FALSE(sub.contain("239.255.43.0"));
	ASSERT_FALSE(sub.contain("8.8.8.8"));
}