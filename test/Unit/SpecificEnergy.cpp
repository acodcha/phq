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

#include "../../include/PhQ/Unit/SpecificEnergy.hpp"

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

constexpr std::array<SpecificEnergy, 4> Units = {
    SpecificEnergy::JoulePerKilogram,
    SpecificEnergy::NanojoulePerGram,
    SpecificEnergy::FootPoundPerSlug,
    SpecificEnergy::InchPoundPerSlinch,
};

TEST(UnitSpecificEnergy, Abbreviation) {
  EXPECT_EQ(Abbreviation(SpecificEnergy::JoulePerKilogram), "J/kg");
  EXPECT_EQ(Abbreviation(SpecificEnergy::NanojoulePerGram), "nJ/g");
  EXPECT_EQ(Abbreviation(SpecificEnergy::FootPoundPerSlug), "ft·lbf/slug");
  EXPECT_EQ(Abbreviation(SpecificEnergy::InchPoundPerSlinch), "in·lbf/slinch");
}

TEST(UnitSpecificEnergy, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<SpecificEnergy>(UnitSystem::MetreKilogramSecondKelvin),
            SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(ConsistentUnit<SpecificEnergy>(UnitSystem::MillimetreGramSecondKelvin),
            SpecificEnergy::NanojoulePerGram);
  EXPECT_EQ(ConsistentUnit<SpecificEnergy>(UnitSystem::FootPoundSecondRankine),
            SpecificEnergy::FootPoundPerSlug);
  EXPECT_EQ(ConsistentUnit<SpecificEnergy>(UnitSystem::InchPoundSecondRankine),
            SpecificEnergy::InchPoundPerSlinch);
}

TEST(UnitSpecificEnergy, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<SpecificEnergy>(
      SpecificEnergy::JoulePerKilogram, SpecificEnergy::JoulePerKilogram, value, value);
  Internal::TestConvertAndConvertCopy<SpecificEnergy>(
      SpecificEnergy::JoulePerKilogram, SpecificEnergy::NanojoulePerGram, value,
      value * 1000000.0L);
  Internal::TestConvertAndConvertCopy<SpecificEnergy>(
      SpecificEnergy::JoulePerKilogram, SpecificEnergy::FootPoundPerSlug, value,
      value / std::pow(0.3048L, 2));
  Internal::TestConvertAndConvertCopy<SpecificEnergy>(
      SpecificEnergy::JoulePerKilogram, SpecificEnergy::InchPoundPerSlinch, value,
      value / std::pow(0.0254L, 2));
}

TEST(UnitSpecificEnergy, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<SpecificEnergy>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<SpecificEnergy>("J/kg"), SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(ParseEnumeration<SpecificEnergy>("nJ/g"), SpecificEnergy::NanojoulePerGram);
  EXPECT_EQ(ParseEnumeration<SpecificEnergy>("ft·lbf/slug"), SpecificEnergy::FootPoundPerSlug);
  EXPECT_EQ(ParseEnumeration<SpecificEnergy>("in·lbf/slinch"), SpecificEnergy::InchPoundPerSlinch);
}

TEST(UnitSpecificEnergy, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<SpecificEnergy>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitSpecificEnergy, RelatedUnitSystem) {
  EXPECT_EQ(
      RelatedUnitSystem(SpecificEnergy::JoulePerKilogram), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(SpecificEnergy::NanojoulePerGram), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(SpecificEnergy::FootPoundPerSlug), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(
      RelatedUnitSystem(SpecificEnergy::InchPoundPerSlinch), UnitSystem::InchPoundSecondRankine);
}

TEST(UnitSpecificEnergy, Standard) {
  EXPECT_EQ(Standard<SpecificEnergy>, SpecificEnergy::JoulePerKilogram);
}

TEST(UnitSpecificEnergy, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<SpecificEnergy, SpecificEnergy::JoulePerKilogram,
                                  SpecificEnergy::FootPoundPerSlug>(
      value, value / std::pow(0.3048L, 2));
}

TEST(UnitSpecificEnergy, Stream) {
  std::ostringstream stream;
  stream << SpecificEnergy::JoulePerKilogram;
  EXPECT_EQ(stream.str(), Abbreviation(SpecificEnergy::JoulePerKilogram));
}

}  // namespace

}  // namespace PhQ::Unit
