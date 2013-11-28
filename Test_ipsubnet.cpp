#include "ipsubnet.h"

#include "gtest/gtest.h"

TEST(IPSubnetTest, ConstructorBase)
{
	in_addr a;
	inet_pton(AF_INET, "239.255.42.0", &a);
	const IPSubnet sub(a, 24);

	ASSERT_EQ(sub.string(), "239.255.42.0/24");
}

in_addr a;
int status = inet_pton(AF_INET, "239.255.42.0", &a);
const IPSubnet sub(a, 24);

TEST(IPSubnetTest, ContainLowerBound)
{
	in_addr b;
	inet_pton(AF_INET, "239.255.42.0", &b);
	ASSERT_TRUE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, ContainMiddle)
{
	in_addr b;
	inet_pton(AF_INET, "239.255.42.125", &b);
	ASSERT_TRUE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, ContainUpperBound)
{
	in_addr b;
	inet_pton(AF_INET, "239.255.42.255", &b);
	ASSERT_TRUE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, NotContainLowerBound)
{
	in_addr b;
	inet_pton(AF_INET, "239.255.41.255", &b);
	ASSERT_FALSE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, NotContainUpperBound)
{
	in_addr b;
	inet_pton(AF_INET, "239.255.43.0", &b);
	ASSERT_FALSE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, NotContainAtAll)
{
	in_addr b;
	inet_pton(AF_INET, "8.8.8.8", &b);
	ASSERT_FALSE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, GetOne)
{
	in_addr a;
	inet_pton(AF_INET, "239.255.42.0", &a);
	const IPSubnet sub(a, 24);

	// TODO
	ASSERT_TRUE(false);
}

TEST(IPSubnetTest, GetMultiple)
{
	in_addr a;
	inet_pton(AF_INET, "239.255.42.0", &a);
	const IPSubnet sub(a, 24);

	// TODO
	ASSERT_TRUE(false);
}

TEST(IPSubnetTest, GetUntilNoMore)
{
	in_addr a;
	inet_pton(AF_INET, "239.255.42.0", &a);
	const IPSubnet sub(a, 24);

	// TODO
	ASSERT_TRUE(false);
}

TEST(IPSubnetTest, GetAndReleaseOne)
{
	in_addr a;
	inet_pton(AF_INET, "239.255.42.0", &a);
	const IPSubnet sub(a, 24);

	// TODO
	ASSERT_TRUE(false);
}

TEST(IPSubnetTest, GetAndReleaseMultiple)
{
	in_addr a;
	inet_pton(AF_INET, "239.255.42.0", &a);
	const IPSubnet sub(a, 24);

	// TODO
	ASSERT_TRUE(false);
}
