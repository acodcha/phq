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

#include "../../include/PhQ/Unit/Speed.hpp"

#include <array>
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

constexpr std::array<Speed, 39> Units = {
    Speed::NauticalMilePerSecond, Speed::NauticalMilePerMinute, Speed::Knot,
    Speed::MilePerSecond,         Speed::MilePerMinute,         Speed::MilePerHour,
    Speed::KilometrePerSecond,    Speed::KilometrePerMinute,    Speed::KilometrePerHour,
    Speed::MetrePerSecond,        Speed::MetrePerMinute,        Speed::MetrePerHour,
    Speed::YardPerSecond,         Speed::YardPerMinute,         Speed::YardPerHour,
    Speed::FootPerSecond,         Speed::FootPerMinute,         Speed::FootPerHour,
    Speed::DecimetrePerSecond,    Speed::DecimetrePerMinute,    Speed::DecimetrePerHour,
    Speed::InchPerSecond,         Speed::InchPerMinute,         Speed::InchPerHour,
    Speed::CentimetrePerSecond,   Speed::CentimetrePerMinute,   Speed::CentimetrePerHour,
    Speed::MillimetrePerSecond,   Speed::MillimetrePerMinute,   Speed::MillimetrePerHour,
    Speed::MilliinchPerSecond,    Speed::MilliinchPerMinute,    Speed::MilliinchPerHour,
    Speed::MicrometrePerSecond,   Speed::MicrometrePerMinute,   Speed::MicrometrePerHour,
    Speed::MicroinchPerSecond,    Speed::MicroinchPerMinute,    Speed::MicroinchPerHour,
};

TEST(UnitSpeed, Abbreviation) {
  EXPECT_EQ(Abbreviation(Speed::NauticalMilePerSecond), "nmi/s");
  EXPECT_EQ(Abbreviation(Speed::MilePerSecond), "mi/s");
  EXPECT_EQ(Abbreviation(Speed::KilometrePerSecond), "km/s");
  EXPECT_EQ(Abbreviation(Speed::MetrePerSecond), "m/s");
  EXPECT_EQ(Abbreviation(Speed::YardPerSecond), "yd/s");
  EXPECT_EQ(Abbreviation(Speed::FootPerSecond), "ft/s");
  EXPECT_EQ(Abbreviation(Speed::DecimetrePerSecond), "dm/s");
  EXPECT_EQ(Abbreviation(Speed::InchPerSecond), "in/s");
  EXPECT_EQ(Abbreviation(Speed::CentimetrePerSecond), "cm/s");
  EXPECT_EQ(Abbreviation(Speed::MillimetrePerSecond), "mm/s");
  EXPECT_EQ(Abbreviation(Speed::MilliinchPerSecond), "mil/s");
  EXPECT_EQ(Abbreviation(Speed::MicrometrePerSecond), "μm/s");
  EXPECT_EQ(Abbreviation(Speed::MicroinchPerSecond), "μin/s");
  EXPECT_EQ(Abbreviation(Speed::NauticalMilePerMinute), "nmi/min");
  EXPECT_EQ(Abbreviation(Speed::MilePerMinute), "mi/min");
  EXPECT_EQ(Abbreviation(Speed::KilometrePerMinute), "km/min");
  EXPECT_EQ(Abbreviation(Speed::MetrePerMinute), "m/min");
  EXPECT_EQ(Abbreviation(Speed::YardPerMinute), "yd/min");
  EXPECT_EQ(Abbreviation(Speed::FootPerMinute), "ft/min");
  EXPECT_EQ(Abbreviation(Speed::DecimetrePerMinute), "dm/min");
  EXPECT_EQ(Abbreviation(Speed::InchPerMinute), "in/min");
  EXPECT_EQ(Abbreviation(Speed::CentimetrePerMinute), "cm/min");
  EXPECT_EQ(Abbreviation(Speed::MillimetrePerMinute), "mm/min");
  EXPECT_EQ(Abbreviation(Speed::MilliinchPerMinute), "mil/min");
  EXPECT_EQ(Abbreviation(Speed::MicrometrePerMinute), "μm/min");
  EXPECT_EQ(Abbreviation(Speed::MicroinchPerMinute), "μin/min");
  EXPECT_EQ(Abbreviation(Speed::Knot), "kn");
  EXPECT_EQ(Abbreviation(Speed::MilePerHour), "mi/hr");
  EXPECT_EQ(Abbreviation(Speed::KilometrePerHour), "km/hr");
  EXPECT_EQ(Abbreviation(Speed::MetrePerHour), "m/hr");
  EXPECT_EQ(Abbreviation(Speed::YardPerHour), "yd/hr");
  EXPECT_EQ(Abbreviation(Speed::FootPerHour), "ft/hr");
  EXPECT_EQ(Abbreviation(Speed::DecimetrePerHour), "dm/hr");
  EXPECT_EQ(Abbreviation(Speed::InchPerHour), "in/hr");
  EXPECT_EQ(Abbreviation(Speed::CentimetrePerHour), "cm/hr");
  EXPECT_EQ(Abbreviation(Speed::MillimetrePerHour), "mm/hr");
  EXPECT_EQ(Abbreviation(Speed::MilliinchPerHour), "mil/hr");
  EXPECT_EQ(Abbreviation(Speed::MicrometrePerHour), "μm/hr");
  EXPECT_EQ(Abbreviation(Speed::MicroinchPerHour), "μin/hr");
}

TEST(UnitSpeed, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Speed>(UnitSystem::MetreKilogramSecondKelvin), Speed::MetrePerSecond);
  EXPECT_EQ(
      ConsistentUnit<Speed>(UnitSystem::MillimetreGramSecondKelvin), Speed::MillimetrePerSecond);
  EXPECT_EQ(ConsistentUnit<Speed>(UnitSystem::FootPoundSecondRankine), Speed::FootPerSecond);
  EXPECT_EQ(ConsistentUnit<Speed>(UnitSystem::InchPoundSecondRankine), Speed::InchPerSecond);
}

TEST(UnitSpeed, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::NauticalMilePerSecond, value, value / 1852.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MilePerSecond, value, value / 1609.344L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::KilometrePerSecond, value, value * 0.001L);
  Internal::TestConvert<Speed>(Speed::MetrePerSecond, Speed::MetrePerSecond, value, value);
  Internal::TestConvert<Speed>(Speed::MetrePerSecond, Speed::YardPerSecond, value, value / 0.9144L);
  Internal::TestConvert<Speed>(Speed::MetrePerSecond, Speed::FootPerSecond, value, value / 0.3048L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::DecimetrePerSecond, value, value * 10.0L);
  Internal::TestConvert<Speed>(Speed::MetrePerSecond, Speed::InchPerSecond, value, value / 0.0254L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::CentimetrePerSecond, value, value * 100.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MillimetrePerSecond, value, value * 1000.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MilliinchPerSecond, value, value / 0.0000254L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MicrometrePerSecond, value, value * 1000000.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MicroinchPerSecond, value, value / 0.0000000254L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::NauticalMilePerMinute, value, value / 1852.0L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MilePerMinute, value, value / 1609.344L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::KilometrePerMinute, value, value * 0.001L * 60.0L);
  Internal::TestConvert<Speed>(Speed::MetrePerSecond, Speed::MetrePerMinute, value, value * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::YardPerMinute, value, value / 0.9144L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::FootPerMinute, value, value / 0.3048L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::DecimetrePerMinute, value, value * 10.0L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::InchPerMinute, value, value / 0.0254L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::CentimetrePerMinute, value, value * 100.0L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MillimetrePerMinute, value, value * 1000.0L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MilliinchPerMinute, value, value / 0.0000254L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MicrometrePerMinute, value, value * 1000000.0L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MicroinchPerMinute, value, value / 0.0000000254L * 60.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::Knot, value, value / 1852.0L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MilePerHour, value, value / 1609.344L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::KilometrePerHour, value, value * 0.001L * 3600.0L);
  Internal::TestConvert<Speed>(Speed::MetrePerSecond, Speed::MetrePerHour, value, value * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::YardPerHour, value, value / 0.9144L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::FootPerHour, value, value / 0.3048L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::DecimetrePerHour, value, value * 10.0L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::InchPerHour, value, value / 0.0254L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::CentimetrePerHour, value, value * 100.0L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MillimetrePerHour, value, value * 1000.0L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MilliinchPerHour, value, value / 0.0000254L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MicrometrePerHour, value, value * 1000000.0L * 3600.0L);
  Internal::TestConvert<Speed>(
      Speed::MetrePerSecond, Speed::MicroinchPerHour, value, value / 0.0000000254L * 3600.0L);
}

TEST(UnitSpeed, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Speed, Speed::MetrePerSecond, Speed::FootPerSecond>(
      value, value / 0.3048L);
}

TEST(UnitSpeed, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Speed>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Speed>("nmi/s"), Speed::NauticalMilePerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("mi/s"), Speed::MilePerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("km/s"), Speed::KilometrePerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("m/s"), Speed::MetrePerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("yd/s"), Speed::YardPerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("ft/s"), Speed::FootPerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("dm/s"), Speed::DecimetrePerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("in/s"), Speed::InchPerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("cm/s"), Speed::CentimetrePerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("mm/s"), Speed::MillimetrePerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("mil/s"), Speed::MilliinchPerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("μm/s"), Speed::MicrometrePerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("μin/s"), Speed::MicroinchPerSecond);
  EXPECT_EQ(ParseEnumeration<Speed>("nmi/min"), Speed::NauticalMilePerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("mi/min"), Speed::MilePerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("km/min"), Speed::KilometrePerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("m/min"), Speed::MetrePerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("yd/min"), Speed::YardPerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("ft/min"), Speed::FootPerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("dm/min"), Speed::DecimetrePerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("in/min"), Speed::InchPerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("cm/min"), Speed::CentimetrePerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("mm/min"), Speed::MillimetrePerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("mil/min"), Speed::MilliinchPerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("μm/min"), Speed::MicrometrePerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("μin/min"), Speed::MicroinchPerMinute);
  EXPECT_EQ(ParseEnumeration<Speed>("kn"), Speed::Knot);
  EXPECT_EQ(ParseEnumeration<Speed>("mi/hr"), Speed::MilePerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("km/hr"), Speed::KilometrePerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("m/hr"), Speed::MetrePerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("yd/hr"), Speed::YardPerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("ft/hr"), Speed::FootPerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("dm/hr"), Speed::DecimetrePerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("in/hr"), Speed::InchPerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("cm/hr"), Speed::CentimetrePerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("mm/hr"), Speed::MillimetrePerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("mil/hr"), Speed::MilliinchPerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("μm/hr"), Speed::MicrometrePerHour);
  EXPECT_EQ(ParseEnumeration<Speed>("μin/hr"), Speed::MicroinchPerHour);
}

TEST(UnitSpeed, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Speed>,
            Dimensions(Dimension::Time{-1}, Dimension::Length{1}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitSpeed, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Speed::NauticalMilePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MilePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::KilometrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MetrePerSecond), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Speed::YardPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::FootPerSecond), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Speed::DecimetrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::InchPerSecond), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Speed::CentimetrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MillimetrePerSecond), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Speed::MilliinchPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MicrometrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MicroinchPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::NauticalMilePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MilePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::KilometrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::YardPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::FootPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::DecimetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::InchPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::CentimetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MillimetrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MilliinchPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MicrometrePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MicroinchPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::Knot), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MilePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::KilometrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::YardPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::FootPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::DecimetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::InchPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::CentimetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MillimetrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MilliinchPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MicrometrePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MicroinchPerHour), std::nullopt);
}

TEST(UnitSpeed, Standard) {
  EXPECT_EQ(Standard<Speed>, Speed::MetrePerSecond);
}

TEST(UnitSpeed, Stream) {
  std::ostringstream stream;
  stream << Speed::MetrePerSecond;
  EXPECT_EQ(stream.str(), Abbreviation(Speed::MetrePerSecond));
}

}  // namespace

}  // namespace PhQ::Unit
