#include "configuration.hpp"
#include "broadcastlistgenerator.hpp"

#include "gtest/gtest.h"
// #include <iostream>

TEST(BroadcastlistGeneratorTest, GenerateAssignementConfig) {
  ConfigurationPtr cPtr = std::make_shared<Configuration>("yaml/broadcastlistgenerator/good.yaml");
  cPtr->load();

  BroadcastListGenerator generator(cPtr);
  generator.setOffline(true);
  Assignement assignement = generator.generateAssignement();
  ASSERT_TRUE(assignement.size() == 5);
}
