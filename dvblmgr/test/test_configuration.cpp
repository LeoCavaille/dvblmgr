#include "configuration.hpp"

#include "gtest/gtest.h"

struct cout_redirect {
  cout_redirect(std::streambuf *new_buffer)
      : old(std::cout.rdbuf(new_buffer)) {}

  ~cout_redirect() { std::cout.rdbuf(old); }

private:
  std::streambuf *old;
};

TEST(ConfigurationTest, LoadSaveGoodConfig) {
  ConfigurationPtr cPtr = std::make_shared<Configuration>("yaml/configuration/good.yaml");
  cPtr->load();
  std::stringstream yamlBuffer;
  {
    cout_redirect scopedRedirect(yamlBuffer.rdbuf());
    cPtr->save();
  }

  YAML::Node yamlReloaded = YAML::Load(yamlBuffer.str());
  ConfigurationPtr cReloadedPtr = std::make_shared<Configuration>("");
  cReloadedPtr->load(yamlReloaded);

  ASSERT_EQ(*cPtr, *cReloadedPtr);
}
