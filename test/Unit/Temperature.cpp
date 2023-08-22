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

#include "../../include/PhQ/Unit/Temperature.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Temperature, 4> Units = {
    Temperature::Kelvin,
    Temperature::Celsius,
    Temperature::Rankine,
    Temperature::Fahrenheit,
};

TEST(UnitTemperature, Abbreviation) {
  EXPECT_EQ(Abbreviation(Temperature::Kelvin), "K");
  EXPECT_EQ(Abbreviation(Temperature::Celsius), "°C");
  EXPECT_EQ(Abbreviation(Temperature::Rankine), "°R");
  EXPECT_EQ(Abbreviation(Temperature::Fahrenheit), "°F");
}

TEST(UnitTemperature, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Temperature>(UnitSystem::MetreKilogramSecondKelvin),
            Temperature::Kelvin);
  EXPECT_EQ(ConsistentUnit<Temperature>(UnitSystem::MillimetreGramSecondKelvin),
            Temperature::Kelvin);
  EXPECT_EQ(ConsistentUnit<Temperature>(UnitSystem::FootPoundSecondRankine),
            Temperature::Rankine);
  EXPECT_EQ(ConsistentUnit<Temperature>(UnitSystem::InchPoundSecondRankine),
            Temperature::Rankine);
}

TEST(UnitTemperature, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Temperature::Kelvin, Temperature::Kelvin), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Temperature::Kelvin, Temperature::Celsius),
      value - 273.15);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Temperature::Kelvin, Temperature::Rankine),
      value * 1.8);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Temperature::Kelvin, Temperature::Fahrenheit),
      (value * 1.8) - 459.67);
}

TEST(UnitTemperature, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Temperature::Kelvin, Temperature::Kelvin), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Temperature::Celsius, Temperature::Kelvin),
      value + 273.15);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Temperature::Rankine, Temperature::Kelvin),
      value / 1.8);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Temperature::Fahrenheit, Temperature::Kelvin),
      (value + 459.67) / 1.8);
}

TEST(UnitTemperature, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Temperature old_unit : Units) {
    for (const Temperature new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitTemperature, Parse) {
  EXPECT_EQ(Parse<Temperature>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Temperature>("K"), Temperature::Kelvin);
  EXPECT_EQ(Parse<Temperature>("°C"), Temperature::Celsius);
  EXPECT_EQ(Parse<Temperature>("°R"), Temperature::Rankine);
  EXPECT_EQ(Parse<Temperature>("°F"), Temperature::Fahrenheit);
}

TEST(UnitTemperature, RelatedDimensions) {
  EXPECT_EQ(
      RelatedDimensions<Temperature>,
      Dimensions(Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
                 Dimension::ElectricCurrent{}, Dimension::Temperature{1}));
}

TEST(UnitTemperature, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Temperature::Kelvin), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Temperature::Celsius), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Temperature::Rankine), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Temperature::Fahrenheit), std::nullopt);
}

TEST(UnitTemperature, Standard) {
  EXPECT_EQ(Standard<Temperature>, Temperature::Kelvin);
}

}  // namespace

}  // namespace PhQ::Unit
