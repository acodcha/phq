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

#include "../../include/PhQ/Unit/AngularAcceleration.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<AngularAcceleration, 15> Units = {
    AngularAcceleration::RadianPerSquareSecond,     AngularAcceleration::RadianPerSquareMinute,
    AngularAcceleration::RadianPerSquareHour,       AngularAcceleration::DegreePerSquareSecond,
    AngularAcceleration::DegreePerSquareMinute,     AngularAcceleration::DegreePerSquareHour,
    AngularAcceleration::ArcminutePerSquareSecond,  AngularAcceleration::ArcminutePerSquareMinute,
    AngularAcceleration::ArcminutePerSquareHour,    AngularAcceleration::ArcsecondPerSquareSecond,
    AngularAcceleration::ArcsecondPerSquareMinute,  AngularAcceleration::ArcsecondPerSquareHour,
    AngularAcceleration::RevolutionPerSquareSecond, AngularAcceleration::RevolutionPerSquareMinute,
    AngularAcceleration::RevolutionPerSquareHour,
};

TEST(UnitAngularAcceleration, Abbreviation) {
  EXPECT_EQ(Abbreviation(AngularAcceleration::RadianPerSquareSecond), "rad/s^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::RadianPerSquareMinute), "rad/min^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::RadianPerSquareHour), "rad/hr^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::DegreePerSquareSecond), "deg/s^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::DegreePerSquareMinute), "deg/min^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::DegreePerSquareHour), "deg/hr^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcminutePerSquareSecond), "arcmin/s^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcminutePerSquareMinute), "arcmin/min^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcminutePerSquareHour), "arcmin/hr^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcsecondPerSquareSecond), "arcsec/s^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcsecondPerSquareMinute), "arcsec/min^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcsecondPerSquareHour), "arcsec/hr^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::RevolutionPerSquareSecond), "rev/s^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::RevolutionPerSquareMinute), "rev/min^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::RevolutionPerSquareHour), "rev/hr^2");
}

TEST(UnitAngularAcceleration, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<AngularAcceleration>(UnitSystem::MetreKilogramSecondKelvin),
            AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(ConsistentUnit<AngularAcceleration>(UnitSystem::MillimetreGramSecondKelvin),
            AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(ConsistentUnit<AngularAcceleration>(UnitSystem::FootPoundSecondRankine),
            AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(ConsistentUnit<AngularAcceleration>(UnitSystem::InchPoundSecondRankine),
            AngularAcceleration::RadianPerSquareSecond);
}

TEST(UnitAngularAcceleration, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::RadianPerSquareSecond, value,
      value);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::RadianPerSquareMinute, value,
      value * 3600.0L);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::RadianPerSquareHour, value,
      value * 12960000.0L);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::DegreePerSquareSecond, value,
      value * 180.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::DegreePerSquareMinute, value,
      value * 648000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::DegreePerSquareHour, value,
      value * 2332800000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::ArcminutePerSquareSecond,
      value, value * 10800.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::ArcminutePerSquareMinute,
      value, value * 38880000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::ArcminutePerSquareHour,
      value, value * 139968000000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::ArcsecondPerSquareSecond,
      value, value * 648000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::ArcsecondPerSquareMinute,
      value, value * 2332800000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::ArcsecondPerSquareHour,
      value, value * 8398080000000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::RevolutionPerSquareSecond,
      value, value * 0.5L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::RevolutionPerSquareMinute,
      value, value * 1800.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularAcceleration>(
      AngularAcceleration::RadianPerSquareSecond, AngularAcceleration::RevolutionPerSquareHour,
      value, value * 6480000.0L / Pi<long double>);
}

TEST(UnitAngularAcceleration, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("Hello world!"), std::nullopt);
  EXPECT_EQ(
      ParseEnumeration<AngularAcceleration>("rad/s^2"), AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("rad/min^2"),
            AngularAcceleration::RadianPerSquareMinute);
  EXPECT_EQ(
      ParseEnumeration<AngularAcceleration>("rad/hr^2"), AngularAcceleration::RadianPerSquareHour);
  EXPECT_EQ(
      ParseEnumeration<AngularAcceleration>("deg/s^2"), AngularAcceleration::DegreePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("deg/min^2"),
            AngularAcceleration::DegreePerSquareMinute);
  EXPECT_EQ(
      ParseEnumeration<AngularAcceleration>("deg/hr^2"), AngularAcceleration::DegreePerSquareHour);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("arcmin/s^2"),
            AngularAcceleration::ArcminutePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("arcmin/min^2"),
            AngularAcceleration::ArcminutePerSquareMinute);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("arcmin/hr^2"),
            AngularAcceleration::ArcminutePerSquareHour);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("arcsec/s^2"),
            AngularAcceleration::ArcsecondPerSquareSecond);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("arcsec/min^2"),
            AngularAcceleration::ArcsecondPerSquareMinute);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("arcsec/hr^2"),
            AngularAcceleration::ArcsecondPerSquareHour);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("rev/s^2"),
            AngularAcceleration::RevolutionPerSquareSecond);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("rev/min^2"),
            AngularAcceleration::RevolutionPerSquareMinute);
  EXPECT_EQ(ParseEnumeration<AngularAcceleration>("rev/hr^2"),
            AngularAcceleration::RevolutionPerSquareHour);
}

TEST(UnitAngularAcceleration, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<AngularAcceleration>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{0}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitAngularAcceleration, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RadianPerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RadianPerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RadianPerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::DegreePerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::DegreePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::DegreePerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcminutePerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcminutePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcminutePerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcsecondPerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcsecondPerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcsecondPerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RevolutionPerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RevolutionPerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RevolutionPerSquareHour), std::nullopt);
}

TEST(UnitAngularAcceleration, Standard) {
  EXPECT_EQ(Standard<AngularAcceleration>, AngularAcceleration::RadianPerSquareSecond);
}

TEST(UnitAngularAcceleration, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<AngularAcceleration, AngularAcceleration::RadianPerSquareSecond,
                                  AngularAcceleration::DegreePerSquareSecond>(
      value, value * 180.0L / Pi<long double>);
}

TEST(UnitAngularAcceleration, Stream) {
  std::ostringstream stream;
  stream << AngularAcceleration::RadianPerSquareSecond;
  EXPECT_EQ(stream.str(), Abbreviation(AngularAcceleration::RadianPerSquareSecond));
}

}  // namespace

}  // namespace PhQ::Unit
