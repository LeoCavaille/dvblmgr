#include "adapter.h"
#include "gtest/gtest.h"

TEST(AdapterTest, Constructor)
{
	const Adapter a(0);
    EXPECT_EQ(0, a.getId());
}