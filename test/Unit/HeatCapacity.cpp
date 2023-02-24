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

#include "../../include/PhQ/Unit/HeatCapacity.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<HeatCapacity, 4> Units = {
    HeatCapacity::JoulePerKelvin,
    HeatCapacity::NanojoulePerKelvin,
    HeatCapacity::FootPoundPerRankine,
    HeatCapacity::InchPoundPerRankine,
};

TEST(UnitHeatCapacity, Abbreviation) {
  EXPECT_EQ(Abbreviation(HeatCapacity::JoulePerKelvin), "J/K");
  EXPECT_EQ(Abbreviation(HeatCapacity::NanojoulePerKelvin), "nJ/K");
  EXPECT_EQ(Abbreviation(HeatCapacity::FootPoundPerRankine), "ft·lbf/°R");
  EXPECT_EQ(Abbreviation(HeatCapacity::InchPoundPerRankine), "in·lbf/°R");
}

TEST(UnitHeatCapacity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<HeatCapacity>(UnitSystem::MetreKilogramSecondKelvin),
            HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(
      ConsistentUnit<HeatCapacity>(UnitSystem::MillimetreGramSecondKelvin),
      HeatCapacity::NanojoulePerKelvin);
  EXPECT_EQ(ConsistentUnit<HeatCapacity>(UnitSystem::FootPoundSecondRankine),
            HeatCapacity::FootPoundPerRankine);
  EXPECT_EQ(ConsistentUnit<HeatCapacity>(UnitSystem::InchPoundSecondRankine),
            HeatCapacity::InchPoundPerRankine);
}

TEST(UnitHeatCapacity, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, HeatCapacity::JoulePerKelvin,
                               HeatCapacity::JoulePerKelvin),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, HeatCapacity::JoulePerKelvin,
                               HeatCapacity::NanojoulePerKelvin),
                   value * 1000000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, HeatCapacity::JoulePerKelvin,
                               HeatCapacity::FootPoundPerRankine),
                   value / (0.3048 * 0.45359237 * 9.80665 * 1.8));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, HeatCapacity::JoulePerKelvin,
                               HeatCapacity::InchPoundPerRankine),
                   value / (0.0254 * 0.45359237 * 9.80665 * 1.8));
}

TEST(UnitHeatCapacity, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, HeatCapacity::JoulePerKelvin,
                               HeatCapacity::JoulePerKelvin),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, HeatCapacity::NanojoulePerKelvin,
                               HeatCapacity::JoulePerKelvin),
                   value * 0.000000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, HeatCapacity::FootPoundPerRankine,
                               HeatCapacity::JoulePerKelvin),
                   value * 0.3048 * 0.45359237 * 9.80665 * 1.8);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, HeatCapacity::InchPoundPerRankine,
                               HeatCapacity::JoulePerKelvin),
                   value * 0.0254 * 0.45359237 * 9.80665 * 1.8);
}

TEST(UnitHeatCapacity, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const HeatCapacity old_unit : Units) {
    for (const HeatCapacity new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitHeatCapacity, DimensionSet) {
  EXPECT_EQ(Dimensions<HeatCapacity>,
            Dimension::Set(Dimension::Time{-2}, Dimension::Length{2},
                           Dimension::Mass{1}, Dimension::ElectricCurrent{},
                           Dimension::Temperature{-1}));
}

TEST(UnitHeatCapacity, Parse) {
  EXPECT_EQ(Parse<HeatCapacity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<HeatCapacity>("J/K"), HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(Parse<HeatCapacity>("nJ/K"), HeatCapacity::NanojoulePerKelvin);
  EXPECT_EQ(Parse<HeatCapacity>("ft·lbf/°R"),
            HeatCapacity::FootPoundPerRankine);
  EXPECT_EQ(Parse<HeatCapacity>("in·lbf/°R"),
            HeatCapacity::InchPoundPerRankine);
}

TEST(UnitHeatCapacity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(HeatCapacity::JoulePerKelvin),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(HeatCapacity::NanojoulePerKelvin),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(HeatCapacity::FootPoundPerRankine),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(HeatCapacity::InchPoundPerRankine),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitHeatCapacity, StandardUnit) {
  EXPECT_EQ(StandardUnit<HeatCapacity>, HeatCapacity::JoulePerKelvin);
}

}  // namespace

}  // namespace PhQ::Unit
