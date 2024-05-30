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

#include "../../include/PhQ/Unit/Angle.hpp"

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

constexpr std::array<Angle, 5> Units = {
    Angle::Radian, Angle::Degree, Angle::Arcminute, Angle::Arcsecond, Angle::Revolution,
};

TEST(UnitAngle, Abbreviation) {
  EXPECT_EQ(Abbreviation(Angle::Radian), "rad");
  EXPECT_EQ(Abbreviation(Angle::Degree), "deg");
  EXPECT_EQ(Abbreviation(Angle::Arcminute), "arcmin");
  EXPECT_EQ(Abbreviation(Angle::Arcsecond), "arcsec");
  EXPECT_EQ(Abbreviation(Angle::Revolution), "rev");
}

TEST(UnitAngle, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::MetreKilogramSecondKelvin), Angle::Radian);
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::MillimetreGramSecondKelvin), Angle::Radian);
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::FootPoundSecondRankine), Angle::Radian);
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::InchPoundSecondRankine), Angle::Radian);
}

TEST(UnitAngle, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<Angle>(Angle::Radian, Angle::Radian, value, value);
  Internal::TestConvert<Angle>(
      Angle::Radian, Angle::Degree, value, value * 180.0L / Pi<long double>);
  Internal::TestConvert<Angle>(
      Angle::Radian, Angle::Arcminute, value, value * 10800.0L / Pi<long double>);
  Internal::TestConvert<Angle>(
      Angle::Radian, Angle::Arcsecond, value, value * 648000.0L / Pi<long double>);
  Internal::TestConvert<Angle>(
      Angle::Radian, Angle::Revolution, value, value / (2.0L * Pi<long double>));
}

TEST(UnitAngle, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Angle, Angle::Radian, Angle::Degree>(
      value, value * 180.0L / Pi<long double>);
}

TEST(UnitAngle, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Angle>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Angle>("rad"), Angle::Radian);
  EXPECT_EQ(ParseEnumeration<Angle>("deg"), Angle::Degree);
  EXPECT_EQ(ParseEnumeration<Angle>("arcmin"), Angle::Arcminute);
  EXPECT_EQ(ParseEnumeration<Angle>("arcsec"), Angle::Arcsecond);
  EXPECT_EQ(ParseEnumeration<Angle>("rev"), Angle::Revolution);
}

TEST(UnitAngle, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Angle>, Dimensionless);
}

TEST(UnitAngle, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Angle::Radian), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Degree), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Arcminute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Arcsecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Revolution), std::nullopt);
}

TEST(UnitAngle, Standard) {
  EXPECT_EQ(Standard<Angle>, Angle::Radian);
}

TEST(UnitAngle, Stream) {
  std::ostringstream stream;
  stream << Angle::Radian;
  EXPECT_EQ(stream.str(), Abbreviation(Angle::Radian));
}

}  // namespace

}  // namespace PhQ::Unit
