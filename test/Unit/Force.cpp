// Copyright 2020 Alexandre Coderre-Chabot
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

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Force, 3> Units = {
    Force::Newton,
    Force::Micronewton,
    Force::Pound,
};

TEST(UnitEnergyFlux, Abbreviation) {
  EXPECT_EQ(Abbreviation(Force::Newton), "N");
  EXPECT_EQ(Abbreviation(Force::Micronewton), "μN");
  EXPECT_EQ(Abbreviation(Force::Pound), "lbf");
}

TEST(UnitEnergyFlux, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::MetreKilogramSecondKelvin),
            Force::Newton);
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::MillimetreGramSecondKelvin),
            Force::Micronewton);
  EXPECT_EQ(ConsistentUnit<Force>(UnitSystem::FootPoundSecondRankine),
            Force::Pound);
}

TEST(UnitEnergyFlux, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Newton), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Micronewton),
                   value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Pound),
                   value / (0.45359237 * 9.80665));
}

TEST(UnitEnergyFlux, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Newton, Force::Newton), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Micronewton, Force::Newton),
                   value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Force::Pound, Force::Newton),
                   value * 0.45359237 * 9.80665);
}

TEST(UnitEnergyFlux, ConvertVerification) {
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

TEST(UnitEnergyFlux, DimensionSet) {
  EXPECT_EQ(Dimensions<Force>,
            Dimension::Set(Dimension::Time{-2}, Dimension::Length{1},
                           Dimension::Mass{1}));
}

TEST(UnitEnergyFlux, Parse) {
  EXPECT_EQ(Parse<Force>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Force>("N"), Force::Newton);
  EXPECT_EQ(Parse<Force>("μN"), Force::Micronewton);
  EXPECT_EQ(Parse<Force>("lbf"), Force::Pound);
}

TEST(UnitEnergyFlux, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Force::Newton),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Force::Micronewton),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Force::Pound), std::nullopt);
}

TEST(UnitEnergyFlux, StandardUnit) {
  EXPECT_EQ(StandardUnit<Force>, Force::Newton);
}

}  // namespace

}  // namespace PhQ::Unit
