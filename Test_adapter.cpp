#include "adapter.h"
#include "gtest/gtest.h"

TEST(AdapterTest, Constructor)
{
	// Building an adapter /dev/dvb/adapter0/frontend2
	const Adapter a(0,2);
    EXPECT_EQ(0, a.getId());
    EXPECT_EQ(2, a.getFrontendId());
}