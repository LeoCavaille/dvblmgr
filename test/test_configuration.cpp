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
  Configuration c("yaml/configuration/good.yaml");
  c.load();
  std::stringstream yamlBuffer;
  {
    cout_redirect scopedRedirect(yamlBuffer.rdbuf());
    c.save();
  }

  YAML::Node yamlReloaded = YAML::Load(yamlBuffer.str());
  Configuration cReloaded("");
  cReloaded.load(yamlReloaded);

  ASSERT_EQ(c, cReloaded);
}
