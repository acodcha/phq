// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

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

TEST(UnitSpeed, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const Speed original_unit : Units) {
    for (const Speed intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitSpeed, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::NauticalMilePerSecond, value, value / 1852.0);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::MilePerSecond, value, value / 1609.344);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::KilometrePerSecond, value, value * 0.001);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::MetrePerSecond, value, value);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::YardPerSecond, value, value / 0.9144);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::FootPerSecond, value, value / 0.3048);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::DecimetrePerSecond, value, value * 10.0);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::InchPerSecond, value, value / 0.0254);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::CentimetrePerSecond, value, value * 100.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MillimetrePerSecond, value, value * 1000.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MilliinchPerSecond, value, value / 0.0000254);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MicrometrePerSecond, value, value * 1000000.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MicroinchPerSecond, value, value / 0.0000000254);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::NauticalMilePerMinute, value, value / 1852.0 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MilePerMinute, value, value / 1609.344 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::KilometrePerMinute, value, value * 0.001 * 60.0);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::MetrePerMinute, value, value * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::YardPerMinute, value, value / 0.9144 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::FootPerMinute, value, value / 0.3048 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::DecimetrePerMinute, value, value * 10.0 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::InchPerMinute, value, value / 0.0254 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::CentimetrePerMinute, value, value * 100.0 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MillimetrePerMinute, value, value * 1000.0 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MilliinchPerMinute, value, value / 0.0000254 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MicrometrePerMinute, value, value * 1000000.0 * 60.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MicroinchPerMinute, value, value / 0.0000000254 * 60.0);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::Knot, value, value / 1852.0 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MilePerHour, value, value / 1609.344 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::KilometrePerHour, value, value * 0.001 * 3600.0);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::MetrePerHour, value, value * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::YardPerHour, value, value / 0.9144 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::FootPerHour, value, value / 0.3048 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::DecimetrePerHour, value, value * 10.0 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::InchPerHour, value, value / 0.0254 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::CentimetrePerHour, value, value * 100.0 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MillimetrePerHour, value, value * 1000.0 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MilliinchPerHour, value, value / 0.0000254 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MicrometrePerHour, value, value * 1000000.0 * 3600.0);
  Internal::TestConversions(
      Speed::MetrePerSecond, Speed::MicroinchPerHour, value, value / 0.0000000254 * 3600.0);

  Internal::TestStaticConversions<Speed, Speed::MetrePerSecond, Speed::FootPerSecond>(
      value, value / 0.3048);
}

TEST(UnitSpeed, ConvertToStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(
      Speed::NauticalMilePerSecond, Speed::MetrePerSecond, value, value * 1852.0);
  Internal::TestConversions(Speed::MilePerSecond, Speed::MetrePerSecond, value, value * 1609.344);
  Internal::TestConversions(
      Speed::KilometrePerSecond, Speed::MetrePerSecond, value, value * 1000.0);
  Internal::TestConversions(Speed::MetrePerSecond, Speed::MetrePerSecond, value, value);
  Internal::TestConversions(Speed::YardPerSecond, Speed::MetrePerSecond, value, value * 0.9144);
  Internal::TestConversions(Speed::FootPerSecond, Speed::MetrePerSecond, value, value * 0.3048);
  Internal::TestConversions(Speed::DecimetrePerSecond, Speed::MetrePerSecond, value, value * 0.1);
  Internal::TestConversions(Speed::InchPerSecond, Speed::MetrePerSecond, value, value * 0.0254);
  Internal::TestConversions(Speed::CentimetrePerSecond, Speed::MetrePerSecond, value, value * 0.01);
  Internal::TestConversions(
      Speed::MillimetrePerSecond, Speed::MetrePerSecond, value, value * 0.001);
  Internal::TestConversions(
      Speed::MilliinchPerSecond, Speed::MetrePerSecond, value, value * 0.0000254);
  Internal::TestConversions(
      Speed::MicrometrePerSecond, Speed::MetrePerSecond, value, value * 0.000001);
  Internal::TestConversions(
      Speed::MicroinchPerSecond, Speed::MetrePerSecond, value, value * 0.0000000254);
  Internal::TestConversions(
      Speed::NauticalMilePerMinute, Speed::MetrePerSecond, value, value * 1852.0 / 60.0);
  Internal::TestConversions(
      Speed::MilePerMinute, Speed::MetrePerSecond, value, value * 1609.344 / 60.0);
  Internal::TestConversions(
      Speed::KilometrePerMinute, Speed::MetrePerSecond, value, value * 1000.0 / 60.0);
  Internal::TestConversions(Speed::MetrePerMinute, Speed::MetrePerSecond, value, value / 60.0);
  Internal::TestConversions(
      Speed::YardPerMinute, Speed::MetrePerSecond, value, value * 0.9144 / 60.0);
  Internal::TestConversions(
      Speed::FootPerMinute, Speed::MetrePerSecond, value, value * 0.3048 / 60.0);
  Internal::TestConversions(
      Speed::DecimetrePerMinute, Speed::MetrePerSecond, value, value * 0.1 / 60.0);
  Internal::TestConversions(
      Speed::InchPerMinute, Speed::MetrePerSecond, value, value * 0.0254 / 60.0);
  Internal::TestConversions(
      Speed::CentimetrePerMinute, Speed::MetrePerSecond, value, value * 0.01 / 60.0);
  Internal::TestConversions(
      Speed::MillimetrePerMinute, Speed::MetrePerSecond, value, value * 0.001 / 60.0);
  Internal::TestConversions(
      Speed::MilliinchPerMinute, Speed::MetrePerSecond, value, value * 0.0000254 / 60.0);
  Internal::TestConversions(
      Speed::MicrometrePerMinute, Speed::MetrePerSecond, value, value * 0.000001 / 60.0);
  Internal::TestConversions(
      Speed::MicroinchPerMinute, Speed::MetrePerSecond, value, value * 0.0000000254 / 60.0);
  Internal::TestConversions(Speed::Knot, Speed::MetrePerSecond, value, value * 1852.0 / 3600.0);
  Internal::TestConversions(
      Speed::MilePerHour, Speed::MetrePerSecond, value, value * 1609.344 / 3600.0);
  Internal::TestConversions(
      Speed::KilometrePerHour, Speed::MetrePerSecond, value, value * 1000.0 / 3600.0);
  Internal::TestConversions(Speed::MetrePerHour, Speed::MetrePerSecond, value, value / 3600.0);
  Internal::TestConversions(
      Speed::YardPerHour, Speed::MetrePerSecond, value, value * 0.9144 / 3600.0);
  Internal::TestConversions(
      Speed::FootPerHour, Speed::MetrePerSecond, value, value * 0.3048 / 3600.0);
  Internal::TestConversions(
      Speed::DecimetrePerHour, Speed::MetrePerSecond, value, value * 0.1 / 3600.0);
  Internal::TestConversions(
      Speed::InchPerHour, Speed::MetrePerSecond, value, value * 0.0254 / 3600.0);
  Internal::TestConversions(
      Speed::CentimetrePerHour, Speed::MetrePerSecond, value, value * 0.01 / 3600.0);
  Internal::TestConversions(
      Speed::MillimetrePerHour, Speed::MetrePerSecond, value, value * 0.001 / 3600.0);
  Internal::TestConversions(
      Speed::MilliinchPerHour, Speed::MetrePerSecond, value, value * 0.0000254 / 3600.0);
  Internal::TestConversions(
      Speed::MicrometrePerHour, Speed::MetrePerSecond, value, value * 0.000001 / 3600.0);
  Internal::TestConversions(
      Speed::MicroinchPerHour, Speed::MetrePerSecond, value, value * 0.0000000254 / 3600.0);

  Internal::TestStaticConversions<Speed, Speed::FootPerSecond, Speed::MetrePerSecond>(
      value, value * 0.3048);
}

TEST(UnitSpeed, Parse) {
  EXPECT_EQ(Parse<Speed>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Speed>("nmi/s"), Speed::NauticalMilePerSecond);
  EXPECT_EQ(Parse<Speed>("mi/s"), Speed::MilePerSecond);
  EXPECT_EQ(Parse<Speed>("km/s"), Speed::KilometrePerSecond);
  EXPECT_EQ(Parse<Speed>("m/s"), Speed::MetrePerSecond);
  EXPECT_EQ(Parse<Speed>("yd/s"), Speed::YardPerSecond);
  EXPECT_EQ(Parse<Speed>("ft/s"), Speed::FootPerSecond);
  EXPECT_EQ(Parse<Speed>("dm/s"), Speed::DecimetrePerSecond);
  EXPECT_EQ(Parse<Speed>("in/s"), Speed::InchPerSecond);
  EXPECT_EQ(Parse<Speed>("cm/s"), Speed::CentimetrePerSecond);
  EXPECT_EQ(Parse<Speed>("mm/s"), Speed::MillimetrePerSecond);
  EXPECT_EQ(Parse<Speed>("mil/s"), Speed::MilliinchPerSecond);
  EXPECT_EQ(Parse<Speed>("μm/s"), Speed::MicrometrePerSecond);
  EXPECT_EQ(Parse<Speed>("μin/s"), Speed::MicroinchPerSecond);
  EXPECT_EQ(Parse<Speed>("nmi/min"), Speed::NauticalMilePerMinute);
  EXPECT_EQ(Parse<Speed>("mi/min"), Speed::MilePerMinute);
  EXPECT_EQ(Parse<Speed>("km/min"), Speed::KilometrePerMinute);
  EXPECT_EQ(Parse<Speed>("m/min"), Speed::MetrePerMinute);
  EXPECT_EQ(Parse<Speed>("yd/min"), Speed::YardPerMinute);
  EXPECT_EQ(Parse<Speed>("ft/min"), Speed::FootPerMinute);
  EXPECT_EQ(Parse<Speed>("dm/min"), Speed::DecimetrePerMinute);
  EXPECT_EQ(Parse<Speed>("in/min"), Speed::InchPerMinute);
  EXPECT_EQ(Parse<Speed>("cm/min"), Speed::CentimetrePerMinute);
  EXPECT_EQ(Parse<Speed>("mm/min"), Speed::MillimetrePerMinute);
  EXPECT_EQ(Parse<Speed>("mil/min"), Speed::MilliinchPerMinute);
  EXPECT_EQ(Parse<Speed>("μm/min"), Speed::MicrometrePerMinute);
  EXPECT_EQ(Parse<Speed>("μin/min"), Speed::MicroinchPerMinute);
  EXPECT_EQ(Parse<Speed>("kn"), Speed::Knot);
  EXPECT_EQ(Parse<Speed>("mi/hr"), Speed::MilePerHour);
  EXPECT_EQ(Parse<Speed>("km/hr"), Speed::KilometrePerHour);
  EXPECT_EQ(Parse<Speed>("m/hr"), Speed::MetrePerHour);
  EXPECT_EQ(Parse<Speed>("yd/hr"), Speed::YardPerHour);
  EXPECT_EQ(Parse<Speed>("ft/hr"), Speed::FootPerHour);
  EXPECT_EQ(Parse<Speed>("dm/hr"), Speed::DecimetrePerHour);
  EXPECT_EQ(Parse<Speed>("in/hr"), Speed::InchPerHour);
  EXPECT_EQ(Parse<Speed>("cm/hr"), Speed::CentimetrePerHour);
  EXPECT_EQ(Parse<Speed>("mm/hr"), Speed::MillimetrePerHour);
  EXPECT_EQ(Parse<Speed>("mil/hr"), Speed::MilliinchPerHour);
  EXPECT_EQ(Parse<Speed>("μm/hr"), Speed::MicrometrePerHour);
  EXPECT_EQ(Parse<Speed>("μin/hr"), Speed::MicroinchPerHour);
}

TEST(UnitSpeed, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Speed>, Dimensions(Dimension::Time{-1}, Dimension::Length{1}));
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
