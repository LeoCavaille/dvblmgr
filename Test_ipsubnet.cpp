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
	in_addr b;
	inet_pton(AF_INET, "239.255.42.0", &b);
	IPSubnet sub(b, 24);

	in_addr c = sub.get();
	ASSERT_TRUE(sub.contain(c.s_addr));
}

TEST(IPSubnetTest, GetMultiple)
{
	in_addr b;
	inet_pton(AF_INET, "239.255.42.0", &b);
	IPSubnet sub(b, 24);

	int count = 10;
	std::set<in_addr_t> ip_set;
	in_addr addr_to_add;
	for (int i = 0; i < count; ++i)
	{
		ip_set.insert(sub.get().s_addr);
	}

	ASSERT_EQ(ip_set.size(), count);
}

TEST(IPSubnetTest, GetUntilNoMore)
{
	in_addr b;
	inet_pton(AF_INET, "239.255.42.0", &b);
	IPSubnet sub(b, 24);

	int counter = 0;
	bool is_empty = false;
	while(!is_empty) {
		try {
			sub.get();
			counter++;
		}
		catch (std::string message) {
			is_empty = true;
		}
	}

	ASSERT_EQ(counter, 256); // 2 ** (32-24)
}

TEST(IPSubnetTest, GetAndReleaseOne)
{
	in_addr b;
	inet_pton(AF_INET, "239.255.42.0", &b);
	IPSubnet sub(b, 24);

	in_addr c = sub.get();
	sub.release(c);

	ASSERT_TRUE(sub.is_available(c));
}

TEST(IPSubnetTest, GetAndReleaseMultiple)
{
	in_addr b;
	inet_pton(AF_INET, "239.255.42.0", &b);
	IPSubnet sub(b, 24);

	in_addr c = sub.get();
	in_addr d = sub.get();
	in_addr e = sub.get();
	in_addr f = sub.get();
	in_addr g = sub.get();

	sub.release(c);
	sub.release(d);
	sub.release(f);

	ASSERT_TRUE(sub.is_available(c));
	ASSERT_TRUE(sub.is_available(d));
	ASSERT_TRUE(sub.is_available(f));

	ASSERT_FALSE(sub.is_available(e));
	ASSERT_FALSE(sub.is_available(g));
}
