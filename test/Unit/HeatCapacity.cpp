// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

TEST(UnitHeatCapacity, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<HeatCapacity>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<HeatCapacity>("J/K"), HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(ParseEnumeration<HeatCapacity>("nJ/K"), HeatCapacity::NanojoulePerKelvin);
  EXPECT_EQ(ParseEnumeration<HeatCapacity>("ft·lbf/°R"), HeatCapacity::FootPoundPerRankine);
  EXPECT_EQ(ParseEnumeration<HeatCapacity>("in·lbf/°R"), HeatCapacity::InchPoundPerRankine);
}

TEST(UnitHeatCapacity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<HeatCapacity>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{}, Dimension::Temperature{-1},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
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
