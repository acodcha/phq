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

#include "../../include/PhQ/Unit/SpecificHeatCapacity.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<SpecificHeatCapacity, 4> Units = {
    SpecificHeatCapacity::JoulePerKilogramPerKelvin,
    SpecificHeatCapacity::NanojoulePerGramPerKelvin,
    SpecificHeatCapacity::FootPoundPerSlugPerRankine,
    SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
};

TEST(UnitSpecificHeatCapacity, Abbreviation) {
  EXPECT_EQ(
      Abbreviation(SpecificHeatCapacity::JoulePerKilogramPerKelvin), "J/kg/K");
  EXPECT_EQ(
      Abbreviation(SpecificHeatCapacity::NanojoulePerGramPerKelvin), "nJ/g/K");
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::FootPoundPerSlugPerRankine),
            "ft·lbf/slug/°R");
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::InchPoundPerSlinchPerRankine),
            "in·lbf/slinch/°R");
}

TEST(UnitSpecificHeatCapacity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(
                UnitSystem::MetreKilogramSecondKelvin),
            SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(
                UnitSystem::MillimetreGramSecondKelvin),
            SpecificHeatCapacity::NanojoulePerGramPerKelvin);
  EXPECT_EQ(
      ConsistentUnit<SpecificHeatCapacity>(UnitSystem::FootPoundSecondRankine),
      SpecificHeatCapacity::FootPoundPerSlugPerRankine);
  EXPECT_EQ(
      ConsistentUnit<SpecificHeatCapacity>(UnitSystem::InchPoundSecondRankine),
      SpecificHeatCapacity::InchPoundPerSlinchPerRankine);
}

TEST(UnitSpecificHeatCapacity, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                  SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                  SpecificHeatCapacity::NanojoulePerGramPerKelvin),
      value * 1000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                  SpecificHeatCapacity::FootPoundPerSlugPerRankine),
      value / (1.8 * std::pow(0.3048, 2)));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                  SpecificHeatCapacity::InchPoundPerSlinchPerRankine),
      value / (1.8 * std::pow(0.0254, 2)));
}

TEST(UnitSpecificHeatCapacity, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                  SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SpecificHeatCapacity::NanojoulePerGramPerKelvin,
                  SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      value * 0.000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SpecificHeatCapacity::FootPoundPerSlugPerRankine,
                  SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      value * 1.8 * std::pow(0.3048, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
                  SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      value * 1.8 * std::pow(0.0254, 2));
}

TEST(UnitSpecificHeatCapacity, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const SpecificHeatCapacity old_unit : Units) {
    for (const SpecificHeatCapacity new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitSpecificHeatCapacity, DimensionSet) {
  EXPECT_EQ(Dimensions<SpecificHeatCapacity>,
            Dimension::Set(
                Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{},
                Dimension::ElectricCurrent{}, Dimension::Temperature{-1}));
}

TEST(UnitSpecificHeatCapacity, Parse) {
  EXPECT_EQ(Parse<SpecificHeatCapacity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<SpecificHeatCapacity>("J/kg/K"),
            SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(Parse<SpecificHeatCapacity>("nJ/g/K"),
            SpecificHeatCapacity::NanojoulePerGramPerKelvin);
  EXPECT_EQ(Parse<SpecificHeatCapacity>("ft·lbf/slug/°R"),
            SpecificHeatCapacity::FootPoundPerSlugPerRankine);
  EXPECT_EQ(Parse<SpecificHeatCapacity>("in·lbf/slinch/°R"),
            SpecificHeatCapacity::InchPoundPerSlinchPerRankine);
}

TEST(UnitSpecificHeatCapacity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::FootPoundPerSlugPerRankine),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(
      RelatedUnitSystem(SpecificHeatCapacity::InchPoundPerSlinchPerRankine),
      UnitSystem::InchPoundSecondRankine);
}

TEST(UnitSpecificHeatCapacity, StandardUnit) {
  EXPECT_EQ(StandardUnit<SpecificHeatCapacity>,
            SpecificHeatCapacity::JoulePerKilogramPerKelvin);
}

}  // namespace

}  // namespace PhQ::Unit
