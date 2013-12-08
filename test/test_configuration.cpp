#include "configuration.hpp"

#include "gtest/gtest.h"

TEST(ConfigurationTest, LoadGoodConfig) {
	Configuration c("yaml/configuration/good.yaml");
	c.load();
}
