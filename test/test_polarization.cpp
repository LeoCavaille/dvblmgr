#include "polarization.h"

#include "gtest/gtest.h"

TEST(PolarizationTest, VerticalYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/polarization/vertical.yaml");
  PolarizationPtr p = std::make_shared<Polarization>();

  ASSERT_TRUE(YAML::convert<PolarizationPtr>::decode(doc["polarization"], p));
  ASSERT_EQ(*p, Polarization::vertical);
}

TEST(PolarizationTest, HorizontalYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/polarization/horizontal.yaml");
  PolarizationPtr p = std::make_shared<Polarization>();

  ASSERT_TRUE(YAML::convert<PolarizationPtr>::decode(doc["polarization"], p));
  ASSERT_EQ(*p, Polarization::horizontal);
}

TEST(PolarizationTest, InvalidYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/polarization/bad.yaml");
  PolarizationPtr p = std::make_shared<Polarization>();

  ASSERT_FALSE(YAML::convert<PolarizationPtr>::decode(doc["polarization"], p));
  ASSERT_EQ(*p, Polarization::invalid);
}
