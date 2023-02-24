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

#include "../../include/PhQ/Unit/TemperatureDifference.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<TemperatureDifference, 4> Units = {
    TemperatureDifference::Kelvin,
    TemperatureDifference::Celsius,
    TemperatureDifference::Rankine,
    TemperatureDifference::Fahrenheit,
};

TEST(UnitTemperatureDifference, Abbreviation) {
  EXPECT_EQ(Abbreviation(TemperatureDifference::Kelvin), "K");
  EXPECT_EQ(Abbreviation(TemperatureDifference::Celsius), "°C");
  EXPECT_EQ(Abbreviation(TemperatureDifference::Rankine), "°R");
  EXPECT_EQ(Abbreviation(TemperatureDifference::Fahrenheit), "°F");
}

TEST(UnitTemperatureDifference, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<TemperatureDifference>(
                UnitSystem::MetreKilogramSecondKelvin),
            TemperatureDifference::Kelvin);
  EXPECT_EQ(ConsistentUnit<TemperatureDifference>(
                UnitSystem::MillimetreGramSecondKelvin),
            TemperatureDifference::Kelvin);
  EXPECT_EQ(
      ConsistentUnit<TemperatureDifference>(UnitSystem::FootPoundSecondRankine),
      TemperatureDifference::Rankine);
  EXPECT_EQ(
      ConsistentUnit<TemperatureDifference>(UnitSystem::InchPoundSecondRankine),
      TemperatureDifference::Rankine);
}

TEST(UnitTemperatureDifference, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureDifference::Kelvin,
                               TemperatureDifference::Kelvin),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureDifference::Kelvin,
                               TemperatureDifference::Celsius),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureDifference::Kelvin,
                               TemperatureDifference::Rankine),
                   value * 1.8);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureDifference::Kelvin,
                               TemperatureDifference::Fahrenheit),
                   value * 1.8);
}

TEST(UnitTemperatureDifference, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureDifference::Kelvin,
                               TemperatureDifference::Kelvin),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureDifference::Celsius,
                               TemperatureDifference::Kelvin),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureDifference::Rankine,
                               TemperatureDifference::Kelvin),
                   value / 1.8);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, TemperatureDifference::Fahrenheit,
                               TemperatureDifference::Kelvin),
                   value / 1.8);
}

TEST(UnitTemperatureDifference, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const TemperatureDifference old_unit : Units) {
    for (const TemperatureDifference new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitTemperatureDifference, DimensionSet) {
  EXPECT_EQ(
      Dimensions<TemperatureDifference>,
      Dimension::Set(Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
                     Dimension::ElectricCurrent{}, Dimension::Temperature{1}));
}

TEST(UnitTemperatureDifference, Parse) {
  EXPECT_EQ(Parse<TemperatureDifference>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<TemperatureDifference>("K"), TemperatureDifference::Kelvin);
  EXPECT_EQ(Parse<TemperatureDifference>("°C"), TemperatureDifference::Celsius);
  EXPECT_EQ(Parse<TemperatureDifference>("°R"), TemperatureDifference::Rankine);
  EXPECT_EQ(Parse<TemperatureDifference>("°F"),
            TemperatureDifference::Fahrenheit);
}

TEST(UnitTemperatureDifference, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(TemperatureDifference::Kelvin), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureDifference::Celsius), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureDifference::Rankine), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(TemperatureDifference::Fahrenheit), std::nullopt);
}

TEST(UnitTemperatureDifference, StandardUnit) {
  EXPECT_EQ(StandardUnit<TemperatureDifference>, TemperatureDifference::Kelvin);
}

}  // namespace

}  // namespace PhQ::Unit
