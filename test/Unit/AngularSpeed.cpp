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

#include "../../include/PhQ/Unit/AngularSpeed.hpp"

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

constexpr std::array<AngularSpeed, 15> Units = {
    AngularSpeed::RadianPerSecond,     AngularSpeed::RadianPerMinute,
    AngularSpeed::RadianPerHour,       AngularSpeed::DegreePerSecond,
    AngularSpeed::DegreePerMinute,     AngularSpeed::DegreePerHour,
    AngularSpeed::ArcminutePerSecond,  AngularSpeed::ArcminutePerMinute,
    AngularSpeed::ArcminutePerHour,    AngularSpeed::ArcsecondPerSecond,
    AngularSpeed::ArcsecondPerMinute,  AngularSpeed::ArcsecondPerHour,
    AngularSpeed::RevolutionPerSecond, AngularSpeed::RevolutionPerMinute,
    AngularSpeed::RevolutionPerHour,
};

TEST(UnitAngularSpeed, Abbreviation) {
  EXPECT_EQ(Abbreviation(AngularSpeed::RadianPerSecond), "rad/s");
  EXPECT_EQ(Abbreviation(AngularSpeed::RadianPerMinute), "rad/min");
  EXPECT_EQ(Abbreviation(AngularSpeed::RadianPerHour), "rad/hr");
  EXPECT_EQ(Abbreviation(AngularSpeed::DegreePerSecond), "deg/s");
  EXPECT_EQ(Abbreviation(AngularSpeed::DegreePerMinute), "deg/min");
  EXPECT_EQ(Abbreviation(AngularSpeed::DegreePerHour), "deg/hr");
  EXPECT_EQ(Abbreviation(AngularSpeed::ArcminutePerSecond), "arcmin/s");
  EXPECT_EQ(Abbreviation(AngularSpeed::ArcminutePerMinute), "arcmin/min");
  EXPECT_EQ(Abbreviation(AngularSpeed::ArcminutePerHour), "arcmin/hr");
  EXPECT_EQ(Abbreviation(AngularSpeed::ArcsecondPerSecond), "arcsec/s");
  EXPECT_EQ(Abbreviation(AngularSpeed::ArcsecondPerMinute), "arcsec/min");
  EXPECT_EQ(Abbreviation(AngularSpeed::ArcsecondPerHour), "arcsec/hr");
  EXPECT_EQ(Abbreviation(AngularSpeed::RevolutionPerSecond), "rev/s");
  EXPECT_EQ(Abbreviation(AngularSpeed::RevolutionPerMinute), "rev/min");
  EXPECT_EQ(Abbreviation(AngularSpeed::RevolutionPerHour), "rev/hr");
}

TEST(UnitAngularSpeed, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<AngularSpeed>(UnitSystem::MetreKilogramSecondKelvin),
            AngularSpeed::RadianPerSecond);
  EXPECT_EQ(ConsistentUnit<AngularSpeed>(UnitSystem::MillimetreGramSecondKelvin),
            AngularSpeed::RadianPerSecond);
  EXPECT_EQ(ConsistentUnit<AngularSpeed>(UnitSystem::FootPoundSecondRankine),
            AngularSpeed::RadianPerSecond);
  EXPECT_EQ(ConsistentUnit<AngularSpeed>(UnitSystem::InchPoundSecondRankine),
            AngularSpeed::RadianPerSecond);
}

TEST(UnitAngularSpeed, ConvertFromStandard) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::RadianPerSecond, value, value);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::RadianPerMinute, value, value * 60.0L);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::RadianPerHour, value, value * 3600.0L);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::DegreePerSecond, value,
      value * 180.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::DegreePerMinute, value,
      value * 10800.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::DegreePerHour, value,
      value * 648000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::ArcminutePerSecond, value,
      value * 10800.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::ArcminutePerMinute, value,
      value * 648000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::ArcminutePerHour, value,
      value * 38880000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::ArcsecondPerSecond, value,
      value * 648000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::ArcsecondPerMinute, value,
      value * 38880000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::ArcsecondPerHour, value,
      value * 2332800000.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::RevolutionPerSecond, value,
      value * 0.5L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::RevolutionPerMinute, value,
      value * 30.0L / Pi<long double>);
  Internal::TestConvertAndConvertCopy<AngularSpeed>(
      AngularSpeed::RadianPerSecond, AngularSpeed::RevolutionPerHour, value,
      value * 1800.0L / Pi<long double>);
}

TEST(UnitAngularSpeed, Parse) {
  EXPECT_EQ(Parse<AngularSpeed>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<AngularSpeed>("rad/s"), AngularSpeed::RadianPerSecond);
  EXPECT_EQ(Parse<AngularSpeed>("rad/min"), AngularSpeed::RadianPerMinute);
  EXPECT_EQ(Parse<AngularSpeed>("rad/hr"), AngularSpeed::RadianPerHour);
  EXPECT_EQ(Parse<AngularSpeed>("deg/s"), AngularSpeed::DegreePerSecond);
  EXPECT_EQ(Parse<AngularSpeed>("deg/min"), AngularSpeed::DegreePerMinute);
  EXPECT_EQ(Parse<AngularSpeed>("deg/hr"), AngularSpeed::DegreePerHour);
  EXPECT_EQ(Parse<AngularSpeed>("arcmin/s"), AngularSpeed::ArcminutePerSecond);
  EXPECT_EQ(Parse<AngularSpeed>("arcmin/min"), AngularSpeed::ArcminutePerMinute);
  EXPECT_EQ(Parse<AngularSpeed>("arcmin/hr"), AngularSpeed::ArcminutePerHour);
  EXPECT_EQ(Parse<AngularSpeed>("arcsec/s"), AngularSpeed::ArcsecondPerSecond);
  EXPECT_EQ(Parse<AngularSpeed>("arcsec/min"), AngularSpeed::ArcsecondPerMinute);
  EXPECT_EQ(Parse<AngularSpeed>("arcsec/hr"), AngularSpeed::ArcsecondPerHour);
  EXPECT_EQ(Parse<AngularSpeed>("rev/s"), AngularSpeed::RevolutionPerSecond);
  EXPECT_EQ(Parse<AngularSpeed>("rev/min"), AngularSpeed::RevolutionPerMinute);
  EXPECT_EQ(Parse<AngularSpeed>("rev/hr"), AngularSpeed::RevolutionPerHour);
}

TEST(UnitAngularSpeed, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<AngularSpeed>, Dimensions{Dimension::Time{-1}});
}

TEST(UnitAngularSpeed, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RadianPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RadianPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RadianPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::DegreePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::DegreePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::DegreePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::ArcminutePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::ArcminutePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::ArcminutePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::ArcsecondPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::ArcsecondPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::ArcsecondPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RevolutionPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RevolutionPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RevolutionPerHour), std::nullopt);
}

TEST(UnitAngularSpeed, Standard) {
  EXPECT_EQ(Standard<AngularSpeed>, AngularSpeed::RadianPerSecond);
}

TEST(UnitAngularSpeed, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<AngularSpeed, AngularSpeed::RadianPerSecond,
                                  AngularSpeed::DegreePerSecond>(
      value, value * 180.0L / Pi<long double>);
}

TEST(UnitAngularSpeed, Stream) {
  std::ostringstream stream;
  stream << AngularSpeed::RadianPerSecond;
  EXPECT_EQ(stream.str(), Abbreviation(AngularSpeed::RadianPerSecond));
}

}  // namespace

}  // namespace PhQ::Unit
