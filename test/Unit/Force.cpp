// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/Unit/Force.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Force, 9> Units = {
    Force::Newton,     Force::Kilonewton,  Force::Meganewton,
    Force::Giganewton, Force::Millinewton, Force::Micronewton,
    Force::Nanonewton, Force::Dyne,        Force::Pound,
};

TEST(UnitForce, Abbreviation) {
  EXPECT_EQ(Abbreviation(Force::Newton), "N");
  EXPECT_EQ(Abbreviation(Force::Kilonewton), "kN");
  EXPECT_EQ(Abbreviation(Force::Meganewton), "MN");
  EXPECT_EQ(Abbreviation(Force::Giganewton), "GN");
  EXPECT_EQ(Abbreviation(Force::Millinewton), "mN");
  EXPECT_EQ(Abbreviation(Force::Micronewton), "μN");
  EXPECT_EQ(Abbreviation(Force::Nanonewton), "nN");
  EXPECT_EQ(Abbreviation(Force::Dyne), "dyn");
  EXPECT_EQ(Abbreviation(Force::Pound), "lbf");
}

TEST(UnitForce, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::MetreKilogramSecondKelvin),
            Force::Newton);
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::MillimetreGramSecondKelvin),
            Force::Micronewton);
  EXPECT_EQ(
      ConsistentUnit<Force>(UnitSystem::FootPoundSecondRankine), Force::Pound);
  EXPECT_EQ(
      ConsistentUnit<Force>(UnitSystem::InchPoundSecondRankine), Force::Pound);
}

TEST(UnitForce, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Newton), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::Kilonewton), value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::Meganewton), value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Giganewton),
                   value * 0.000000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::Millinewton), value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::Micronewton), value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Nanonewton),
                   value * 1000000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Newton, Force::Dyne), value * 100000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Pound),
                   value / (0.45359237 * 9.80665));
}

TEST(UnitForce, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Newton), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Kilonewton, Force::Newton), value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Meganewton, Force::Newton), value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Giganewton, Force::Newton),
                   value * 1000000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Millinewton, Force::Newton), value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Micronewton, Force::Newton), value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Nanonewton, Force::Newton),
                   value * 0.000000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Force::Dyne, Force::Newton), value * 0.00001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Pound, Force::Newton),
                   value * 0.45359237 * 9.80665);
}

TEST(UnitForce, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Force old_unit : Units) {
    for (const Force new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitForce, Parse) {
  EXPECT_EQ(Parse<Force>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Force>("N"), Force::Newton);
  EXPECT_EQ(Parse<Force>("kN"), Force::Kilonewton);
  EXPECT_EQ(Parse<Force>("MN"), Force::Meganewton);
  EXPECT_EQ(Parse<Force>("GN"), Force::Giganewton);
  EXPECT_EQ(Parse<Force>("mN"), Force::Millinewton);
  EXPECT_EQ(Parse<Force>("μN"), Force::Micronewton);
  EXPECT_EQ(Parse<Force>("nN"), Force::Nanonewton);
  EXPECT_EQ(Parse<Force>("dyn"), Force::Dyne);
  EXPECT_EQ(Parse<Force>("lbf"), Force::Pound);
}

TEST(UnitForce, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Force>,
            Dimensions(
                Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{1}));
}

TEST(UnitForce, RelatedUnitSystem) {
  EXPECT_EQ(
      RelatedUnitSystem(Force::Newton), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Force::Kilonewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Meganewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Giganewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Millinewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Micronewton),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Force::Nanonewton), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Dyne), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Force::Pound), std::nullopt);
}

TEST(UnitForce, Standard) {
  EXPECT_EQ(Standard<Force>, Force::Newton);
}

TEST(UnitForce, Stream) {
  std::ostringstream stream;
  stream << Force::Newton;
  EXPECT_EQ(stream.str(), Abbreviation(Force::Newton));
}

}  // namespace

}  // namespace PhQ::Unit
