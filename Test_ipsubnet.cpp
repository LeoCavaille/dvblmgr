#include "ipsubnet.h"
#include "gtest/gtest.h"

TEST(IPSubnetTest, ConstructorBase)
{
	in_addr a;
	inet_aton("8.8.8.8", &a);
	const IPSubnet sub(a, 24);

	ASSERT_EQ(sub.string(), "8.8.8.0/24");
}