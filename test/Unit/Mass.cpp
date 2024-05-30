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

#include "../../include/PhQ/Unit/Mass.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Mass.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Mass, 5> Units = {
    Mass::Kilogram, Mass::Gram, Mass::Slug, Mass::Slinch, Mass::Pound,
};

TEST(UnitMass, Abbreviation) {
  EXPECT_EQ(Abbreviation(Mass::Kilogram), "kg");
  EXPECT_EQ(Abbreviation(Mass::Gram), "g");
  EXPECT_EQ(Abbreviation(Mass::Slug), "slug");
  EXPECT_EQ(Abbreviation(Mass::Slinch), "slinch");
  EXPECT_EQ(Abbreviation(Mass::Pound), "lbm");
}

TEST(UnitMass, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::MetreKilogramSecondKelvin), Mass::Kilogram);
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::MillimetreGramSecondKelvin), Mass::Gram);
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::FootPoundSecondRankine), Mass::Slug);
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::InchPoundSecondRankine), Mass::Slinch);
}

TEST(UnitMass, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<Mass>(Mass::Kilogram, Mass::Kilogram, value, value);
  Internal::TestConvertAndConvertCopy<Mass>(Mass::Kilogram, Mass::Gram, value, value * 1000.0L);
  Internal::TestConvertAndConvertCopy<Mass>(
      Mass::Kilogram, Mass::Slug, value, value * 0.3048L / (0.45359237L * 9.80665L));
  Internal::TestConvertAndConvertCopy<Mass>(
      Mass::Kilogram, Mass::Slinch, value, value * 0.0254L / (0.45359237L * 9.80665L));
  Internal::TestConvertAndConvertCopy<Mass>(
      Mass::Kilogram, Mass::Pound, value, value / 0.45359237L);
}

TEST(UnitMass, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Mass, Mass::Kilogram, Mass::Slug>(
      value, value * 0.3048L / (0.45359237L * 9.80665L));
}

TEST(UnitMass, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Mass>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Mass>("kg"), Mass::Kilogram);
  EXPECT_EQ(ParseEnumeration<Mass>("g"), Mass::Gram);
  EXPECT_EQ(ParseEnumeration<Mass>("slug"), Mass::Slug);
  EXPECT_EQ(ParseEnumeration<Mass>("slinch"), Mass::Slinch);
  EXPECT_EQ(ParseEnumeration<Mass>("lbm"), Mass::Pound);
}

TEST(UnitMass, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Mass>,
            Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitMass, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Mass::Kilogram), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Mass::Gram), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Mass::Slug), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Mass::Slinch), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Mass::Pound), std::nullopt);
}

TEST(UnitMass, Standard) {
  EXPECT_EQ(Standard<Mass>, Mass::Kilogram);
}

TEST(UnitMass, Stream) {
  std::ostringstream stream;
  stream << Mass::Kilogram;
  EXPECT_EQ(stream.str(), Abbreviation(Mass::Kilogram));
}

}  // namespace

}  // namespace PhQ::Unit
