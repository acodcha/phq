// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

#include "../../include/PhQ/Unit/DynamicViscosity.hpp"

#include <array>
#include <cmath>
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

constexpr std::array<DynamicViscosity, 7> Units = {
    DynamicViscosity::PascalSecond,
    DynamicViscosity::KilopascalSecond,
    DynamicViscosity::MegapascalSecond,
    DynamicViscosity::GigapascalSecond,
    DynamicViscosity::Poise,
    DynamicViscosity::PoundSecondPerSquareFoot,
    DynamicViscosity::PoundSecondPerSquareInch,
};

TEST(UnitDynamicViscosity, Abbreviation) {
  EXPECT_EQ(Abbreviation(DynamicViscosity::PascalSecond), "Pa·s");
  EXPECT_EQ(Abbreviation(DynamicViscosity::KilopascalSecond), "kPa·s");
  EXPECT_EQ(Abbreviation(DynamicViscosity::MegapascalSecond), "MPa·s");
  EXPECT_EQ(Abbreviation(DynamicViscosity::GigapascalSecond), "GPa·s");
  EXPECT_EQ(Abbreviation(DynamicViscosity::Poise), "P");
  EXPECT_EQ(Abbreviation(DynamicViscosity::PoundSecondPerSquareFoot), "lbf·s/ft^2");
  EXPECT_EQ(Abbreviation(DynamicViscosity::PoundSecondPerSquareInch), "lbf·s/in^2");
}

TEST(UnitDynamicViscosity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<DynamicViscosity>(UnitSystem::MetreKilogramSecondKelvin),
            DynamicViscosity::PascalSecond);
  EXPECT_EQ(ConsistentUnit<DynamicViscosity>(UnitSystem::MillimetreGramSecondKelvin),
            DynamicViscosity::PascalSecond);
  EXPECT_EQ(ConsistentUnit<DynamicViscosity>(UnitSystem::FootPoundSecondRankine),
            DynamicViscosity::PoundSecondPerSquareFoot);
  EXPECT_EQ(ConsistentUnit<DynamicViscosity>(UnitSystem::InchPoundSecondRankine),
            DynamicViscosity::PoundSecondPerSquareInch);
}

TEST(UnitDynamicViscosity, ConvertFromStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<DynamicViscosity>(
      DynamicViscosity::PascalSecond, DynamicViscosity::PascalSecond, value, value);
  Internal::TestConvertAndConvertCopy<DynamicViscosity>(
      DynamicViscosity::PascalSecond, DynamicViscosity::KilopascalSecond, value, value * 0.001L);
  Internal::TestConvertAndConvertCopy<DynamicViscosity>(
      DynamicViscosity::PascalSecond, DynamicViscosity::MegapascalSecond, value, value * 0.000001L);
  Internal::TestConvertAndConvertCopy<DynamicViscosity>(
      DynamicViscosity::PascalSecond, DynamicViscosity::GigapascalSecond, value,
      value * 0.000000001L);
  Internal::TestConvertAndConvertCopy<DynamicViscosity>(
      DynamicViscosity::PascalSecond, DynamicViscosity::Poise, value, value * 10.0L);
  Internal::TestConvertAndConvertCopy<DynamicViscosity>(
      DynamicViscosity::PascalSecond, DynamicViscosity::PoundSecondPerSquareFoot, value,
      value * std::pow(0.3048L, 2) / (0.45359237L * 9.80665L));
  Internal::TestConvertAndConvertCopy<DynamicViscosity>(
      DynamicViscosity::PascalSecond, DynamicViscosity::PoundSecondPerSquareInch, value,
      value * std::pow(0.0254L, 2) / (0.45359237L * 9.80665L));
}

TEST(UnitDynamicViscosity, Parse) {
  EXPECT_EQ(Parse<DynamicViscosity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<DynamicViscosity>("Pa·s"), DynamicViscosity::PascalSecond);
  EXPECT_EQ(Parse<DynamicViscosity>("kPa·s"), DynamicViscosity::KilopascalSecond);
  EXPECT_EQ(Parse<DynamicViscosity>("MPa·s"), DynamicViscosity::MegapascalSecond);
  EXPECT_EQ(Parse<DynamicViscosity>("GPa·s"), DynamicViscosity::GigapascalSecond);
  EXPECT_EQ(Parse<DynamicViscosity>("P"), DynamicViscosity::Poise);
  EXPECT_EQ(Parse<DynamicViscosity>("lbf·s/ft^2"), DynamicViscosity::PoundSecondPerSquareFoot);
  EXPECT_EQ(Parse<DynamicViscosity>("lbf·s/in^2"), DynamicViscosity::PoundSecondPerSquareInch);
}

TEST(UnitDynamicViscosity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<DynamicViscosity>,
            Dimensions(Dimension::Time{-1}, Dimension::Length{-1}, Dimension::Mass{1}));
}

TEST(UnitDynamicViscosity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::PascalSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::KilopascalSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::MegapascalSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::GigapascalSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::Poise), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::PoundSecondPerSquareFoot),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::PoundSecondPerSquareInch),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitDynamicViscosity, Standard) {
  EXPECT_EQ(Standard<DynamicViscosity>, DynamicViscosity::PascalSecond);
}

TEST(UnitDynamicViscosity, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<DynamicViscosity, DynamicViscosity::PascalSecond,
                                  DynamicViscosity::KilopascalSecond>(value, value * 0.001L);
}

TEST(UnitDynamicViscosity, Stream) {
  std::ostringstream stream;
  stream << DynamicViscosity::PascalSecond;
  EXPECT_EQ(stream.str(), Abbreviation(DynamicViscosity::PascalSecond));
}

}  // namespace

}  // namespace PhQ::Unit
