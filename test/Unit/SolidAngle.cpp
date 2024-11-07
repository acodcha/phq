// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../../include/PhQ/Unit/SolidAngle.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<SolidAngle, 4> Units = {
  SolidAngle::Steradian,
  SolidAngle::SquareDegree,
  SolidAngle::SquareArcminute,
  SolidAngle::SquareArcsecond,
};

TEST(UnitAngle, Abbreviation) {
  EXPECT_EQ(Abbreviation(SolidAngle::Steradian), "sr");
  EXPECT_EQ(Abbreviation(SolidAngle::SquareDegree), "deg^2");
  EXPECT_EQ(Abbreviation(SolidAngle::SquareArcminute), "arcmin^2");
  EXPECT_EQ(Abbreviation(SolidAngle::SquareArcsecond), "arcsec^2");
}

TEST(UnitAngle, ConsistentUnit) {
  EXPECT_EQ(
      ConsistentUnit<SolidAngle>(UnitSystem::MetreKilogramSecondKelvin), SolidAngle::Steradian);
  EXPECT_EQ(
      ConsistentUnit<SolidAngle>(UnitSystem::MillimetreGramSecondKelvin), SolidAngle::Steradian);
  EXPECT_EQ(ConsistentUnit<SolidAngle>(UnitSystem::FootPoundSecondRankine), SolidAngle::Steradian);
  EXPECT_EQ(ConsistentUnit<SolidAngle>(UnitSystem::InchPoundSecondRankine), SolidAngle::Steradian);
}

TEST(UnitAngle, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<SolidAngle>(SolidAngle::Steradian, SolidAngle::Steradian, value, value);
  Internal::TestConvert<SolidAngle>(SolidAngle::Steradian, SolidAngle::SquareDegree, value,
                                    value * 180.0L * 180.0L / (Pi<long double> * Pi<long double>));
  Internal::TestConvert<SolidAngle>(
      SolidAngle::Steradian, SolidAngle::SquareArcminute, value,
      value * 10800.0L * 10800.0L / (Pi<long double> * Pi<long double>));
  Internal::TestConvert<SolidAngle>(
      SolidAngle::Steradian, SolidAngle::SquareArcsecond, value,
      value * 648000.0L * 648000.0L / (Pi<long double> * Pi<long double>));
}

TEST(UnitAngle, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<SolidAngle, SolidAngle::Steradian, SolidAngle::SquareDegree>(
      value, value * 180.0L * 180.0L / (Pi<long double> * Pi<long double>));
}

TEST(UnitAngle, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<SolidAngle>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<SolidAngle>("sr"), SolidAngle::Steradian);
  EXPECT_EQ(ParseEnumeration<SolidAngle>("deg^2"), SolidAngle::SquareDegree);
  EXPECT_EQ(ParseEnumeration<SolidAngle>("arcmin^2"), SolidAngle::SquareArcminute);
  EXPECT_EQ(ParseEnumeration<SolidAngle>("arcsec^2"), SolidAngle::SquareArcsecond);
}

TEST(UnitAngle, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<SolidAngle>, Dimensionless);
}

TEST(UnitAngle, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(SolidAngle::Steradian), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(SolidAngle::SquareDegree), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(SolidAngle::SquareArcminute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(SolidAngle::SquareArcsecond), std::nullopt);
}

TEST(UnitAngle, Standard) {
  EXPECT_EQ(Standard<SolidAngle>, SolidAngle::Steradian);
}

TEST(UnitAngle, Stream) {
  std::ostringstream stream;
  stream << SolidAngle::Steradian;
  EXPECT_EQ(stream.str(), Abbreviation(SolidAngle::Steradian));
}

}  // namespace

}  // namespace PhQ::Unit
