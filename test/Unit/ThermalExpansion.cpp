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

#include "../../include/PhQ/Unit/ThermalExpansion.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<ThermalExpansion, 4> Units = {
    ThermalExpansion::PerKelvin,
    ThermalExpansion::PerCelsius,
    ThermalExpansion::PerRankine,
    ThermalExpansion::PerFahrenheit,
};

TEST(UnitThermalExpansion, Abbreviation) {
  EXPECT_EQ(Abbreviation(ThermalExpansion::PerKelvin), "1/K");
  EXPECT_EQ(Abbreviation(ThermalExpansion::PerCelsius), "1/°C");
  EXPECT_EQ(Abbreviation(ThermalExpansion::PerRankine), "1/°R");
  EXPECT_EQ(Abbreviation(ThermalExpansion::PerFahrenheit), "1/°F");
}

TEST(UnitThermalExpansion, ConsistentUnit) {
  EXPECT_EQ(
      ConsistentUnit<ThermalExpansion>(UnitSystem::MetreKilogramSecondKelvin),
      ThermalExpansion::PerKelvin);
  EXPECT_EQ(
      ConsistentUnit<ThermalExpansion>(UnitSystem::MillimetreGramSecondKelvin),
      ThermalExpansion::PerKelvin);
  EXPECT_EQ(
      ConsistentUnit<ThermalExpansion>(UnitSystem::FootPoundSecondRankine),
      ThermalExpansion::PerRankine);
  EXPECT_EQ(
      ConsistentUnit<ThermalExpansion>(UnitSystem::InchPoundSecondRankine),
      ThermalExpansion::PerRankine);
}

TEST(UnitThermalExpansion, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, ThermalExpansion::PerKelvin,
                               ThermalExpansion::PerKelvin),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, ThermalExpansion::PerKelvin,
                               ThermalExpansion::PerCelsius),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, ThermalExpansion::PerKelvin,
                               ThermalExpansion::PerRankine),
                   value / 1.8);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, ThermalExpansion::PerKelvin,
                               ThermalExpansion::PerFahrenheit),
                   value / 1.8);
}

TEST(UnitThermalExpansion, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, ThermalExpansion::PerKelvin,
                               ThermalExpansion::PerKelvin),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, ThermalExpansion::PerCelsius,
                               ThermalExpansion::PerKelvin),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, ThermalExpansion::PerRankine,
                               ThermalExpansion::PerKelvin),
                   value * 1.8);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, ThermalExpansion::PerFahrenheit,
                               ThermalExpansion::PerKelvin),
                   value * 1.8);
}

TEST(UnitThermalExpansion, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const ThermalExpansion old_unit : Units) {
    for (const ThermalExpansion new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitThermalExpansion, DimensionSet) {
  EXPECT_EQ(
      Dimensions<ThermalExpansion>,
      Dimension::Set(Dimension::Time{}, Dimension::Length{}, Dimension::Mass{},
                     Dimension::ElectricCurrent{}, Dimension::Temperature{-1}));
}

TEST(UnitThermalExpansion, Parse) {
  EXPECT_EQ(Parse<ThermalExpansion>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<ThermalExpansion>("1/K"), ThermalExpansion::PerKelvin);
  EXPECT_EQ(Parse<ThermalExpansion>("1/°C"), ThermalExpansion::PerCelsius);
  EXPECT_EQ(Parse<ThermalExpansion>("1/°R"), ThermalExpansion::PerRankine);
  EXPECT_EQ(Parse<ThermalExpansion>("1/°F"), ThermalExpansion::PerFahrenheit);
}

TEST(UnitThermalExpansion, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(ThermalExpansion::PerKelvin), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ThermalExpansion::PerCelsius), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ThermalExpansion::PerRankine), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(ThermalExpansion::PerFahrenheit), std::nullopt);
}

TEST(UnitThermalExpansion, StandardUnit) {
  EXPECT_EQ(StandardUnit<ThermalExpansion>, ThermalExpansion::PerKelvin);
}

}  // namespace

}  // namespace PhQ::Unit
