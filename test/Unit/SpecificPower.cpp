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

#include "../../include/PhQ/Unit/SpecificPower.hpp"

#include <array>
#include <cmath>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<SpecificPower, 4> Units = {
    SpecificPower::WattPerKilogram,
    SpecificPower::NanowattPerGram,
    SpecificPower::FootPoundPerSlugPerSecond,
    SpecificPower::InchPoundPerSlinchPerSecond,
};

TEST(UnitSpecificPower, Abbreviation) {
  EXPECT_EQ(Abbreviation(SpecificPower::WattPerKilogram), "W/kg");
  EXPECT_EQ(Abbreviation(SpecificPower::NanowattPerGram), "nW/g");
  EXPECT_EQ(Abbreviation(SpecificPower::FootPoundPerSlugPerSecond), "ft·lbf/slug/s");
  EXPECT_EQ(Abbreviation(SpecificPower::InchPoundPerSlinchPerSecond), "in·lbf/slinch/s");
}

TEST(UnitSpecificPower, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::MetreKilogramSecondKelvin),
            SpecificPower::WattPerKilogram);
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::MillimetreGramSecondKelvin),
            SpecificPower::NanowattPerGram);
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::FootPoundSecondRankine),
            SpecificPower::FootPoundPerSlugPerSecond);
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::InchPoundSecondRankine),
            SpecificPower::InchPoundPerSlinchPerSecond);
}

TEST(UnitSpecificPower, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<SpecificPower>(
      SpecificPower::WattPerKilogram, SpecificPower::WattPerKilogram, value, value);
  Internal::TestConvertAndConvertCopy<SpecificPower>(
      SpecificPower::WattPerKilogram, SpecificPower::NanowattPerGram, value, value * 1000000.0L);
  Internal::TestConvertAndConvertCopy<SpecificPower>(
      SpecificPower::WattPerKilogram, SpecificPower::FootPoundPerSlugPerSecond, value,
      value / std::pow(0.3048L, 2));
  Internal::TestConvertAndConvertCopy<SpecificPower>(
      SpecificPower::WattPerKilogram, SpecificPower::InchPoundPerSlinchPerSecond, value,
      value / std::pow(0.0254L, 2));
}

TEST(UnitSpecificPower, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<SpecificPower, SpecificPower::WattPerKilogram,
                                  SpecificPower::FootPoundPerSlugPerSecond>(
      value, value / std::pow(0.3048L, 2));
}

TEST(UnitSpecificPower, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<SpecificPower>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<SpecificPower>("W/kg"), SpecificPower::WattPerKilogram);
  EXPECT_EQ(ParseEnumeration<SpecificPower>("nW/g"), SpecificPower::NanowattPerGram);
  EXPECT_EQ(
      ParseEnumeration<SpecificPower>("ft·lbf/slug/s"), SpecificPower::FootPoundPerSlugPerSecond);
  EXPECT_EQ(ParseEnumeration<SpecificPower>("in·lbf/slinch/s"),
            SpecificPower::InchPoundPerSlinchPerSecond);
}

TEST(UnitSpecificPower, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<SpecificPower>,
            Dimensions(Dimension::Time{-3}, Dimension::Length{2}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitSpecificPower, RelatedUnitSystem) {
  EXPECT_EQ(
      RelatedUnitSystem(SpecificPower::WattPerKilogram), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(SpecificPower::NanowattPerGram), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificPower::FootPoundPerSlugPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(SpecificPower::InchPoundPerSlinchPerSecond),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitSpecificPower, Standard) {
  EXPECT_EQ(Standard<SpecificPower>, SpecificPower::WattPerKilogram);
}

TEST(UnitSpecificPower, Stream) {
  std::ostringstream stream;
  stream << SpecificPower::WattPerKilogram;
  EXPECT_EQ(stream.str(), Abbreviation(SpecificPower::WattPerKilogram));
}

}  // namespace

}  // namespace PhQ::Unit
