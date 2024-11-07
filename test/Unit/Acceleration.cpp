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

#include "../../include/PhQ/Unit/Acceleration.hpp"

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

constexpr std::array<Acceleration, 39> Units = {
  Acceleration::NauticalMilePerSquareSecond,
  Acceleration::NauticalMilePerSquareMinute,
  Acceleration::KnotPerHour,
  Acceleration::MilePerSquareSecond,
  Acceleration::MilePerSquareMinute,
  Acceleration::MilePerSquareHour,
  Acceleration::KilometrePerSquareSecond,
  Acceleration::KilometrePerSquareMinute,
  Acceleration::KilometrePerSquareHour,
  Acceleration::YardPerSquareSecond,
  Acceleration::YardPerSquareMinute,
  Acceleration::YardPerSquareHour,
  Acceleration::MetrePerSquareSecond,
  Acceleration::MetrePerSquareMinute,
  Acceleration::MetrePerSquareHour,
  Acceleration::FootPerSquareSecond,
  Acceleration::FootPerSquareMinute,
  Acceleration::FootPerSquareHour,
  Acceleration::DecimetrePerSquareSecond,
  Acceleration::DecimetrePerSquareMinute,
  Acceleration::DecimetrePerSquareHour,
  Acceleration::InchPerSquareSecond,
  Acceleration::InchPerSquareMinute,
  Acceleration::InchPerSquareHour,
  Acceleration::CentimetrePerSquareSecond,
  Acceleration::CentimetrePerSquareMinute,
  Acceleration::CentimetrePerSquareHour,
  Acceleration::MillimetrePerSquareSecond,
  Acceleration::MillimetrePerSquareMinute,
  Acceleration::MillimetrePerSquareHour,
  Acceleration::MilliinchPerSquareSecond,
  Acceleration::MilliinchPerSquareMinute,
  Acceleration::MilliinchPerSquareHour,
  Acceleration::MicrometrePerSquareSecond,
  Acceleration::MicrometrePerSquareMinute,
  Acceleration::MicrometrePerSquareHour,
  Acceleration::MicroinchPerSquareSecond,
  Acceleration::MicroinchPerSquareMinute,
  Acceleration::MicroinchPerSquareHour,
};

TEST(UnitAcceleration, Abbreviation) {
  EXPECT_EQ(Abbreviation(Acceleration::NauticalMilePerSquareSecond), "nmi/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MilePerSquareSecond), "mi/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::KilometrePerSquareSecond), "km/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::YardPerSquareSecond), "yd/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MetrePerSquareSecond), "m/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::FootPerSquareSecond), "ft/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::DecimetrePerSquareSecond), "dm/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::InchPerSquareSecond), "in/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::CentimetrePerSquareSecond), "cm/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MillimetrePerSquareSecond), "mm/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MilliinchPerSquareSecond), "mil/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MicrometrePerSquareSecond), "μm/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::MicroinchPerSquareSecond), "μin/s^2");
  EXPECT_EQ(Abbreviation(Acceleration::NauticalMilePerSquareMinute), "nmi/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::MilePerSquareMinute), "mi/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::KilometrePerSquareMinute), "km/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::YardPerSquareMinute), "yd/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::MetrePerSquareMinute), "m/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::FootPerSquareMinute), "ft/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::DecimetrePerSquareMinute), "dm/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::InchPerSquareMinute), "in/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::CentimetrePerSquareMinute), "cm/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::MillimetrePerSquareMinute), "mm/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::MilliinchPerSquareMinute), "mil/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::MicrometrePerSquareMinute), "μm/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::MicroinchPerSquareMinute), "μin/min^2");
  EXPECT_EQ(Abbreviation(Acceleration::KnotPerHour), "kn/hr");
  EXPECT_EQ(Abbreviation(Acceleration::MilePerSquareHour), "mi/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::KilometrePerSquareHour), "km/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::YardPerSquareHour), "yd/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::MetrePerSquareHour), "m/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::FootPerSquareHour), "ft/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::DecimetrePerSquareHour), "dm/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::InchPerSquareHour), "in/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::CentimetrePerSquareHour), "cm/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::MillimetrePerSquareHour), "mm/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::MilliinchPerSquareHour), "mil/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::MicrometrePerSquareHour), "μm/hr^2");
  EXPECT_EQ(Abbreviation(Acceleration::MicroinchPerSquareHour), "μin/hr^2");
}

TEST(UnitAcceleration, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Acceleration>(UnitSystem::MetreKilogramSecondKelvin),
            Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(ConsistentUnit<Acceleration>(UnitSystem::MillimetreGramSecondKelvin),
            Acceleration::MillimetrePerSquareSecond);
  EXPECT_EQ(ConsistentUnit<Acceleration>(UnitSystem::FootPoundSecondRankine),
            Acceleration::FootPerSquareSecond);
  EXPECT_EQ(ConsistentUnit<Acceleration>(UnitSystem::InchPoundSecondRankine),
            Acceleration::InchPerSquareSecond);
}

TEST(UnitAcceleration, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::NauticalMilePerSquareSecond, value,
      value / 1852.0L);
  Internal::TestConvert<Acceleration>(Acceleration::MetrePerSquareSecond,
                                      Acceleration::MilePerSquareSecond, value, value / 1609.344L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::KilometrePerSquareSecond, value,
      value * 0.001L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MetrePerSquareSecond, value, value);
  Internal::TestConvert<Acceleration>(Acceleration::MetrePerSquareSecond,
                                      Acceleration::YardPerSquareSecond, value, value / 0.9144L);
  Internal::TestConvert<Acceleration>(Acceleration::MetrePerSquareSecond,
                                      Acceleration::FootPerSquareSecond, value, value / 0.3048L);
  Internal::TestConvert<Acceleration>(Acceleration::MetrePerSquareSecond,
                                      Acceleration::DecimetrePerSquareSecond, value, value * 10.0L);
  Internal::TestConvert<Acceleration>(Acceleration::MetrePerSquareSecond,
                                      Acceleration::InchPerSquareSecond, value, value / 0.0254L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::CentimetrePerSquareSecond, value,
      value * 100.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MillimetrePerSquareSecond, value,
      value * 1000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MilliinchPerSquareSecond, value,
      value / 0.0000254L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MicrometrePerSquareSecond, value,
      value * 1000000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MicroinchPerSquareSecond, value,
      value / 0.0000000254L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::NauticalMilePerSquareMinute, value,
      value / 1852.0L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MilePerSquareMinute, value,
      value / 1609.344L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::KilometrePerSquareMinute, value,
      value * 0.001L * 3600.0L);
  Internal::TestConvert<Acceleration>(Acceleration::MetrePerSquareSecond,
                                      Acceleration::MetrePerSquareMinute, value, value * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::YardPerSquareMinute, value,
      value / 0.9144L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::FootPerSquareMinute, value,
      value / 0.3048L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::DecimetrePerSquareMinute, value,
      value * 10.0L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::InchPerSquareMinute, value,
      value / 0.0254L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::CentimetrePerSquareMinute, value,
      value * 100.0L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MillimetrePerSquareMinute, value,
      value * 1000.0L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MilliinchPerSquareMinute, value,
      value / 0.0000254L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MicrometrePerSquareMinute, value,
      value * 1000000.0L * 3600.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MicroinchPerSquareMinute, value,
      value / 0.0000000254L * 3600.0L);
  Internal::TestConvert<Acceleration>(Acceleration::MetrePerSquareSecond, Acceleration::KnotPerHour,
                                      value, value / 1852.0L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MilePerSquareHour, value,
      value / 1609.344L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::KilometrePerSquareHour, value,
      value * 0.001L * 12960000.0L);
  Internal::TestConvert<Acceleration>(Acceleration::MetrePerSquareSecond,
                                      Acceleration::MetrePerSquareHour, value, value * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::YardPerSquareHour, value,
      value / 0.9144L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::FootPerSquareHour, value,
      value / 0.3048L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::DecimetrePerSquareHour, value,
      value * 10.0L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::InchPerSquareHour, value,
      value / 0.0254L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::CentimetrePerSquareHour, value,
      value * 100.0L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MillimetrePerSquareHour, value,
      value * 1000.0L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MilliinchPerSquareHour, value,
      value / 0.0000254L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MicrometrePerSquareHour, value,
      value * 1000000.0L * 12960000.0L);
  Internal::TestConvert<Acceleration>(
      Acceleration::MetrePerSquareSecond, Acceleration::MicroinchPerSquareHour, value,
      value / 0.0000000254L * 12960000.0L);
}

TEST(UnitAcceleration, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<Acceleration, Acceleration::MetrePerSquareSecond,
                                  Acceleration::FootPerSquareSecond>(value, value / 0.3048L);
}

TEST(UnitAcceleration, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<Acceleration>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<Acceleration>("nmi/s^2"), Acceleration::NauticalMilePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("mi/s^2"), Acceleration::MilePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("km/s^2"), Acceleration::KilometrePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("yd/s^2"), Acceleration::YardPerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("m/s^2"), Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("ft/s^2"), Acceleration::FootPerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("dm/s^2"), Acceleration::DecimetrePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("in/s^2"), Acceleration::InchPerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("cm/s^2"), Acceleration::CentimetrePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("mm/s^2"), Acceleration::MillimetrePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("mil/s^2"), Acceleration::MilliinchPerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("μm/s^2"), Acceleration::MicrometrePerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("μin/s^2"), Acceleration::MicroinchPerSquareSecond);
  EXPECT_EQ(ParseEnumeration<Acceleration>("nmi/min^2"), Acceleration::NauticalMilePerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("mi/min^2"), Acceleration::MilePerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("km/min^2"), Acceleration::KilometrePerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("yd/min^2"), Acceleration::YardPerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("m/min^2"), Acceleration::MetrePerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("ft/min^2"), Acceleration::FootPerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("dm/min^2"), Acceleration::DecimetrePerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("in/min^2"), Acceleration::InchPerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("cm/min^2"), Acceleration::CentimetrePerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("mm/min^2"), Acceleration::MillimetrePerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("mil/min^2"), Acceleration::MilliinchPerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("μm/min^2"), Acceleration::MicrometrePerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("μin/min^2"), Acceleration::MicroinchPerSquareMinute);
  EXPECT_EQ(ParseEnumeration<Acceleration>("kn/hr"), Acceleration::KnotPerHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("mi/hr^2"), Acceleration::MilePerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("km/hr^2"), Acceleration::KilometrePerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("yd/hr^2"), Acceleration::YardPerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("m/hr^2"), Acceleration::MetrePerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("ft/hr^2"), Acceleration::FootPerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("dm/hr^2"), Acceleration::DecimetrePerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("in/hr^2"), Acceleration::InchPerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("cm/hr^2"), Acceleration::CentimetrePerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("mm/hr^2"), Acceleration::MillimetrePerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("mil/hr^2"), Acceleration::MilliinchPerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("μm/hr^2"), Acceleration::MicrometrePerSquareHour);
  EXPECT_EQ(ParseEnumeration<Acceleration>("μin/hr^2"), Acceleration::MicroinchPerSquareHour);
}

TEST(UnitAcceleration, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Acceleration>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{1}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
}

TEST(UnitAcceleration, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Acceleration::NauticalMilePerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MilePerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::KilometrePerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::YardPerSquareSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(Acceleration::MetrePerSquareSecond), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(Acceleration::FootPerSquareSecond), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::DecimetrePerSquareSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(Acceleration::InchPerSquareSecond), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::CentimetrePerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MillimetrePerSquareSecond),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MilliinchPerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MicrometrePerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MicroinchPerSquareSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::NauticalMilePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MilePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::KilometrePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::YardPerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MetrePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::FootPerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::DecimetrePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::InchPerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::CentimetrePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MillimetrePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MilliinchPerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MicrometrePerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MicroinchPerSquareMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::KnotPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MilePerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::KilometrePerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::YardPerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MetrePerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::FootPerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::DecimetrePerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::InchPerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::CentimetrePerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MillimetrePerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MilliinchPerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MicrometrePerSquareHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Acceleration::MicroinchPerSquareHour), std::nullopt);
}

TEST(UnitAcceleration, Standard) {
  EXPECT_EQ(Standard<Acceleration>, Acceleration::MetrePerSquareSecond);
}

TEST(UnitAcceleration, Stream) {
  std::ostringstream stream;
  stream << Acceleration::MetrePerSquareSecond;
  EXPECT_EQ(stream.str(), Abbreviation(Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ::Unit
