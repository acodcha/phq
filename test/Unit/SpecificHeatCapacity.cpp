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

#include "../../include/PhQ/Unit/SpecificHeatCapacity.hpp"

#include <array>
#include <cmath>
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

constexpr std::array<SpecificHeatCapacity, 4> Units = {
    SpecificHeatCapacity::JoulePerKilogramPerKelvin,
    SpecificHeatCapacity::NanojoulePerGramPerKelvin,
    SpecificHeatCapacity::FootPoundPerSlugPerRankine,
    SpecificHeatCapacity::InchPoundPerSlinchPerRankine,
};

TEST(UnitSpecificHeatCapacity, Abbreviation) {
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::JoulePerKilogramPerKelvin), "J/kg/K");
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::NanojoulePerGramPerKelvin), "nJ/g/K");
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::FootPoundPerSlugPerRankine), "ft·lbf/slug/°R");
  EXPECT_EQ(Abbreviation(SpecificHeatCapacity::InchPoundPerSlinchPerRankine), "in·lbf/slinch/°R");
}

TEST(UnitSpecificHeatCapacity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(UnitSystem::MetreKilogramSecondKelvin),
            SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(UnitSystem::MillimetreGramSecondKelvin),
            SpecificHeatCapacity::NanojoulePerGramPerKelvin);
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(UnitSystem::FootPoundSecondRankine),
            SpecificHeatCapacity::FootPoundPerSlugPerRankine);
  EXPECT_EQ(ConsistentUnit<SpecificHeatCapacity>(UnitSystem::InchPoundSecondRankine),
            SpecificHeatCapacity::InchPoundPerSlinchPerRankine);
}

TEST(UnitSpecificHeatCapacity, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<SpecificHeatCapacity>(
      SpecificHeatCapacity::JoulePerKilogramPerKelvin,
      SpecificHeatCapacity::JoulePerKilogramPerKelvin, value, value);
  Internal::TestConvert<SpecificHeatCapacity>(
      SpecificHeatCapacity::JoulePerKilogramPerKelvin,
      SpecificHeatCapacity::NanojoulePerGramPerKelvin, value, value * 1000000.0L);
  Internal::TestConvert<SpecificHeatCapacity>(
      SpecificHeatCapacity::JoulePerKilogramPerKelvin,
      SpecificHeatCapacity::FootPoundPerSlugPerRankine, value,
      value / (1.8L * std::pow(0.3048L, 2)));
  Internal::TestConvert<SpecificHeatCapacity>(
      SpecificHeatCapacity::JoulePerKilogramPerKelvin,
      SpecificHeatCapacity::InchPoundPerSlinchPerRankine, value,
      value / (1.8L * std::pow(0.0254L, 2)));
}

TEST(UnitSpecificHeatCapacity, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<SpecificHeatCapacity,
                                  SpecificHeatCapacity::JoulePerKilogramPerKelvin,
                                  SpecificHeatCapacity::FootPoundPerSlugPerRankine>(
      value, value / (1.8L * std::pow(0.3048L, 2)));
}

TEST(UnitSpecificHeatCapacity, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<SpecificHeatCapacity>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<SpecificHeatCapacity>("J/kg/K"),
            SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(ParseEnumeration<SpecificHeatCapacity>("nJ/g/K"),
            SpecificHeatCapacity::NanojoulePerGramPerKelvin);
  EXPECT_EQ(ParseEnumeration<SpecificHeatCapacity>("ft·lbf/slug/°R"),
            SpecificHeatCapacity::FootPoundPerSlugPerRankine);
  EXPECT_EQ(ParseEnumeration<SpecificHeatCapacity>("in·lbf/slinch/°R"),
            SpecificHeatCapacity::InchPoundPerSlinchPerRankine);
}

TEST(UnitSpecificHeatCapacity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<SpecificHeatCapacity>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{-1},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitSpecificHeatCapacity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::FootPoundPerSlugPerRankine),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(SpecificHeatCapacity::InchPoundPerSlinchPerRankine),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitSpecificHeatCapacity, Standard) {
  EXPECT_EQ(Standard<SpecificHeatCapacity>, SpecificHeatCapacity::JoulePerKilogramPerKelvin);
}

TEST(UnitSpecificHeatCapacity, Stream) {
  std::ostringstream stream;
  stream << SpecificHeatCapacity::JoulePerKilogramPerKelvin;
  EXPECT_EQ(stream.str(), Abbreviation(SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

}  // namespace

}  // namespace PhQ::Unit
