#include "ipsubnet.hpp"

#include "gtest/gtest.h"

TEST(IPSubnetTest, ConstructorBase) {
  in_addr a;
  inet_pton(AF_INET, "239.255.42.0", &a);
  const IPSubnet sub(a, 24);

  ASSERT_EQ(sub.string(), "239.255.42.0/24");
}

in_addr a;
int status = inet_pton(AF_INET, "239.255.42.0", &a);
const IPSubnet sub(a, 24);

TEST(IPSubnetTest, ContainLowerBound) {
  in_addr b;
  inet_pton(AF_INET, "239.255.42.0", &b);
  ASSERT_TRUE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, ContainMiddle) {
  in_addr b;
  inet_pton(AF_INET, "239.255.42.125", &b);
  ASSERT_TRUE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, ContainUpperBound) {
  in_addr b;
  inet_pton(AF_INET, "239.255.42.255", &b);
  ASSERT_TRUE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, NotContainLowerBound) {
  in_addr b;
  inet_pton(AF_INET, "239.255.41.255", &b);
  ASSERT_FALSE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, NotContainUpperBound) {
  in_addr b;
  inet_pton(AF_INET, "239.255.43.0", &b);
  ASSERT_FALSE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, NotContainAtAll) {
  in_addr b;
  inet_pton(AF_INET, "8.8.8.8", &b);
  ASSERT_FALSE(sub.contain(b.s_addr));
}

TEST(IPSubnetTest, GetOne) {
  in_addr b;
  inet_pton(AF_INET, "239.255.42.0", &b);
  IPSubnet sub(b, 24);

  in_addr c = sub.get();
  ASSERT_TRUE(sub.contain(c.s_addr));

  ASSERT_EQ(sub.getBusyCount(), 1);
}

TEST(IPSubnetTest, GetMultiple) {
  in_addr b;
  inet_pton(AF_INET, "239.255.42.0", &b);
  IPSubnet sub(b, 24);

  in_addr fromPool;

  // 239.255.42.0 in little endian
  // Warning little endian ANNOYING ADDITIONS !
  uint32_t addr = 0x002AFFEF;

  fromPool = sub.get();
  ASSERT_EQ(fromPool.s_addr, addr);
  fromPool = sub.get();
  ASSERT_EQ(fromPool.s_addr, ntohl(htonl(addr) + 1));
  fromPool = sub.get();
  ASSERT_EQ(fromPool.s_addr, ntohl(htonl(addr) + 2));

  ASSERT_EQ(sub.getBusyCount(), 3);
}

TEST(IPSubnetTest, GetUntilNoMore) {
  in_addr b;
  inet_pton(AF_INET, "239.255.42.0", &b);
  IPSubnet sub(b, 24);

  for (int i = 0; i < 256; i++) {
    sub.get();
    ASSERT_EQ(sub.getBusyCount(), i + 1);
  }
  // FIXME when created a dedicated exception with ASSERT_THROW()
  ASSERT_ANY_THROW(sub.get());
}

TEST(IPSubnetTest, GetAndReleaseOne) {
  in_addr b;
  inet_pton(AF_INET, "239.255.42.0", &b);
  IPSubnet sub(b, 24);

  in_addr c = sub.get();
  ASSERT_EQ(sub.getBusyCount(), 1);
  sub.release(c);
  ASSERT_EQ(sub.getBusyCount(), 0);
}

TEST(IPSubnetTest, GetAndReleaseMultiple) {
  in_addr b;
  inet_pton(AF_INET, "239.255.42.0", &b);
  IPSubnet sub(b, 24);

  in_addr c = sub.get();
  ASSERT_EQ(sub.getBusyCount(), 1);
  in_addr d = sub.get();
  ASSERT_EQ(sub.getBusyCount(), 2);
  in_addr e = sub.get();
  ASSERT_EQ(sub.getBusyCount(), 3);
  in_addr f = sub.get();
  ASSERT_EQ(sub.getBusyCount(), 4);
  in_addr g = sub.get();
  ASSERT_EQ(sub.getBusyCount(), 5);

  sub.release(c);
  ASSERT_EQ(sub.getBusyCount(), 4);
  sub.release(d);
  ASSERT_EQ(sub.getBusyCount(), 3);
  sub.release(f);
  ASSERT_EQ(sub.getBusyCount(), 2);

  // 239.255.42.0 in little endian
  uint32_t addr = 0x002AFFEF;

  ASSERT_EQ(e.s_addr, ntohl(htonl(addr) + 2));
  ASSERT_EQ(g.s_addr, ntohl(htonl(addr) + 4));
}
