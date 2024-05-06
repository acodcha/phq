// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#include "../../include/PhQ/Unit/HeatCapacity.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/ElectricCurrent.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Mass.hpp"
#include "../../include/PhQ/Dimension/Temperature.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
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
  EXPECT_EQ(ConsistentUnit<HeatCapacity>(UnitSystem::MillimetreGramSecondKelvin),
            HeatCapacity::NanojoulePerKelvin);
  EXPECT_EQ(ConsistentUnit<HeatCapacity>(UnitSystem::FootPoundSecondRankine),
            HeatCapacity::FootPoundPerRankine);
  EXPECT_EQ(ConsistentUnit<HeatCapacity>(UnitSystem::InchPoundSecondRankine),
            HeatCapacity::InchPoundPerRankine);
}

TEST(UnitHeatCapacity, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<HeatCapacity>(
      HeatCapacity::JoulePerKelvin, HeatCapacity::JoulePerKelvin, value, value);
  Internal::TestConvertAndConvertCopy<HeatCapacity>(
      HeatCapacity::JoulePerKelvin, HeatCapacity::NanojoulePerKelvin, value, value * 1000000000.0L);
  Internal::TestConvertAndConvertCopy<HeatCapacity>(
      HeatCapacity::JoulePerKelvin, HeatCapacity::FootPoundPerRankine, value,
      value / (0.3048L * 0.45359237L * 9.80665L * 1.8L));
  Internal::TestConvertAndConvertCopy<HeatCapacity>(
      HeatCapacity::JoulePerKelvin, HeatCapacity::InchPoundPerRankine, value,
      value / (0.0254L * 0.45359237L * 9.80665L * 1.8L));
}

TEST(UnitHeatCapacity, Parse) {
  EXPECT_EQ(Parse<HeatCapacity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<HeatCapacity>("J/K"), HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(Parse<HeatCapacity>("nJ/K"), HeatCapacity::NanojoulePerKelvin);
  EXPECT_EQ(Parse<HeatCapacity>("ft·lbf/°R"), HeatCapacity::FootPoundPerRankine);
  EXPECT_EQ(Parse<HeatCapacity>("in·lbf/°R"), HeatCapacity::InchPoundPerRankine);
}

TEST(UnitHeatCapacity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<HeatCapacity>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{}, Dimension::Temperature{-1}));
}

TEST(UnitHeatCapacity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(HeatCapacity::JoulePerKelvin), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(HeatCapacity::NanojoulePerKelvin), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(HeatCapacity::FootPoundPerRankine), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(
      RelatedUnitSystem(HeatCapacity::InchPoundPerRankine), UnitSystem::InchPoundSecondRankine);
}

TEST(UnitHeatCapacity, Standard) {
  EXPECT_EQ(Standard<HeatCapacity>, HeatCapacity::JoulePerKelvin);
}

TEST(UnitHeatCapacity, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<HeatCapacity, HeatCapacity::JoulePerKelvin,
                                  HeatCapacity::FootPoundPerRankine>(
      value, value / (0.3048L * 0.45359237L * 9.80665L * 1.8L));
}

TEST(UnitHeatCapacity, Stream) {
  std::ostringstream stream;
  stream << HeatCapacity::JoulePerKelvin;
  EXPECT_EQ(stream.str(), Abbreviation(HeatCapacity::JoulePerKelvin));
}

}  // namespace

}  // namespace PhQ::Unit
