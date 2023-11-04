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

#include "../../include/PhQ/Unit/HeatCapacity.hpp"

#include <gtest/gtest.h>

#include "../Unit.hpp"

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
  Internal::TestUnitConversions<HeatCapacity, HeatCapacity::JoulePerKelvin,
                                HeatCapacity::JoulePerKelvin>(value, value);
  Internal::TestUnitConversions<HeatCapacity, HeatCapacity::JoulePerKelvin,
                                HeatCapacity::NanojoulePerKelvin>(
      value, value * 1000000000.0);
  Internal::TestUnitConversions<HeatCapacity, HeatCapacity::JoulePerKelvin,
                                HeatCapacity::FootPoundPerRankine>(
      value, value / (0.3048 * 0.45359237 * 9.80665 * 1.8));
  Internal::TestUnitConversions<HeatCapacity, HeatCapacity::JoulePerKelvin,
                                HeatCapacity::InchPoundPerRankine>(
      value, value / (0.0254 * 0.45359237 * 9.80665 * 1.8));
}

TEST(UnitHeatCapacity, ConvertToStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<HeatCapacity, HeatCapacity::JoulePerKelvin,
                                HeatCapacity::JoulePerKelvin>(value, value);
  Internal::TestUnitConversions<HeatCapacity, HeatCapacity::NanojoulePerKelvin,
                                HeatCapacity::JoulePerKelvin>(
      value, value * 0.000000001);
  Internal::TestUnitConversions<HeatCapacity, HeatCapacity::FootPoundPerRankine,
                                HeatCapacity::JoulePerKelvin>(
      value, value * 0.3048 * 0.45359237 * 9.80665 * 1.8);
  Internal::TestUnitConversions<HeatCapacity, HeatCapacity::InchPoundPerRankine,
                                HeatCapacity::JoulePerKelvin>(
      value, value * 0.0254 * 0.45359237 * 9.80665 * 1.8);
}

TEST(UnitHeatCapacity, Parse) {
  EXPECT_EQ(Parse<HeatCapacity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<HeatCapacity>("J/K"), HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(Parse<HeatCapacity>("nJ/K"), HeatCapacity::NanojoulePerKelvin);
  EXPECT_EQ(
      Parse<HeatCapacity>("ft·lbf/°R"), HeatCapacity::FootPoundPerRankine);
  EXPECT_EQ(
      Parse<HeatCapacity>("in·lbf/°R"), HeatCapacity::InchPoundPerRankine);
}

TEST(UnitHeatCapacity, RelatedDimensions) {
  EXPECT_EQ(
      RelatedDimensions<HeatCapacity>,
      Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{}, Dimension::Temperature{-1}));
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

TEST(UnitHeatCapacity, Standard) {
  EXPECT_EQ(Standard<HeatCapacity>, HeatCapacity::JoulePerKelvin);
}

TEST(UnitHeatCapacity, Stream) {
  std::ostringstream stream;
  stream << HeatCapacity::JoulePerKelvin;
  EXPECT_EQ(stream.str(), Abbreviation(HeatCapacity::JoulePerKelvin));
}

}  // namespace

}  // namespace PhQ::Unit
