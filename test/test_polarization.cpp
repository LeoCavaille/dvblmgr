#include "polarization.h"

#include "gtest/gtest.h"

TEST(PolarizationTest, VerticalYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/polarization/vertical.yaml");
  PolarizationPtr p = doc["polarization"].as<PolarizationPtr>();

  ASSERT_EQ(*p, Polarization::vertical);
}

TEST(PolarizationTest, HorizontalYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/polarization/horizontal.yaml");
  PolarizationPtr p = doc["polarization"].as<PolarizationPtr>();

  ASSERT_EQ(*p, Polarization::horizontal);
}

TEST(PolarizationTest, InvalidYamlParse) {
  YAML::Node doc = YAML::LoadFile("yaml/polarization/bad.yaml");
  ASSERT_ANY_THROW(doc["polarization"].as<PolarizationPtr>());
}
