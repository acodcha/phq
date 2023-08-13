// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/Unit/Speed.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Speed, 36> Units = {
    Speed::MilePerSecond,       Speed::MilePerMinute,
    Speed::MilePerHour,         Speed::KilometrePerSecond,
    Speed::KilometrePerMinute,  Speed::KilometrePerHour,
    Speed::MetrePerSecond,      Speed::MetrePerMinute,
    Speed::MetrePerHour,        Speed::YardPerSecond,
    Speed::YardPerMinute,       Speed::YardPerHour,
    Speed::FootPerSecond,       Speed::FootPerMinute,
    Speed::FootPerHour,         Speed::DecimetrePerSecond,
    Speed::DecimetrePerMinute,  Speed::DecimetrePerHour,
    Speed::InchPerSecond,       Speed::InchPerMinute,
    Speed::InchPerHour,         Speed::CentimetrePerSecond,
    Speed::CentimetrePerMinute, Speed::CentimetrePerHour,
    Speed::MillimetrePerSecond, Speed::MillimetrePerMinute,
    Speed::MillimetrePerHour,   Speed::MilliinchPerSecond,
    Speed::MilliinchPerMinute,  Speed::MilliinchPerHour,
    Speed::MicrometrePerSecond, Speed::MicrometrePerMinute,
    Speed::MicrometrePerHour,   Speed::MicroinchPerSecond,
    Speed::MicroinchPerMinute,  Speed::MicroinchPerHour,
};

TEST(UnitSpeed, Abbreviation) {
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
  EXPECT_EQ(ConsistentUnit<Speed>(UnitSystem::MetreKilogramSecondKelvin),
            Speed::MetrePerSecond);
  EXPECT_EQ(ConsistentUnit<Speed>(UnitSystem::MillimetreGramSecondKelvin),
            Speed::MillimetrePerSecond);
  EXPECT_EQ(ConsistentUnit<Speed>(UnitSystem::FootPoundSecondRankine),
            Speed::FootPerSecond);
  EXPECT_EQ(ConsistentUnit<Speed>(UnitSystem::InchPoundSecondRankine),
            Speed::InchPerSecond);
}

TEST(UnitSpeed, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MilePerSecond),
      value / 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::KilometrePerSecond),
      value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MetrePerSecond), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::YardPerSecond),
      value / 0.9144);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::FootPerSecond),
      value / 0.3048);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::DecimetrePerSecond),
      value * 10.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::InchPerSecond),
      value / 0.0254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::CentimetrePerSecond),
      value * 100.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MillimetrePerSecond),
      value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MilliinchPerSecond),
      value / 0.0000254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MicrometrePerSecond),
      value * 1000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MicroinchPerSecond),
      value / 0.0000000254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MilePerMinute),
      value / 1609.344 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::KilometrePerMinute),
      value * 0.001 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MetrePerMinute),
      value * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::YardPerMinute),
      value / 0.9144 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::FootPerMinute),
      value / 0.3048 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::DecimetrePerMinute),
      value * 10.0 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::InchPerMinute),
      value / 0.0254 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::CentimetrePerMinute),
      value * 100.0 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MillimetrePerMinute),
      value * 1000.0 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MilliinchPerMinute),
      value / 0.0000254 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MicrometrePerMinute),
      value * 1000000.0 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MicroinchPerMinute),
      value / 0.0000000254 * 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MilePerHour),
      value / 1609.344 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::KilometrePerHour),
      value * 0.001 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MetrePerHour),
      value * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::YardPerHour),
      value / 0.9144 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::FootPerHour),
      value / 0.3048 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::DecimetrePerHour),
      value * 10.0 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::InchPerHour),
      value / 0.0254 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::CentimetrePerHour),
      value * 100.0 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MillimetrePerHour),
      value * 1000.0 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MilliinchPerHour),
      value / 0.0000254 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MicrometrePerHour),
      value * 1000000.0 * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MicroinchPerHour),
      value / 0.0000000254 * 3600.0);
}

TEST(UnitSpeed, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MilePerSecond, Speed::MetrePerSecond),
      value * 1609.344);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::KilometrePerSecond, Speed::MetrePerSecond),
      value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerSecond, Speed::MetrePerSecond), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::YardPerSecond, Speed::MetrePerSecond),
      value * 0.9144);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::FootPerSecond, Speed::MetrePerSecond),
      value * 0.3048);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::DecimetrePerSecond, Speed::MetrePerSecond),
      value * 0.1);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::InchPerSecond, Speed::MetrePerSecond),
      value * 0.0254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::CentimetrePerSecond, Speed::MetrePerSecond),
      value * 0.01);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MillimetrePerSecond, Speed::MetrePerSecond),
      value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MilliinchPerSecond, Speed::MetrePerSecond),
      value * 0.0000254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MicrometrePerSecond, Speed::MetrePerSecond),
      value * 0.000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MicroinchPerSecond, Speed::MetrePerSecond),
      value * 0.0000000254);

  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MilePerMinute, Speed::MetrePerSecond),
      value * 1609.344 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::KilometrePerMinute, Speed::MetrePerSecond),
      value * 1000.0 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerMinute, Speed::MetrePerSecond),
      value / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::YardPerMinute, Speed::MetrePerSecond),
      value * 0.9144 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::FootPerMinute, Speed::MetrePerSecond),
      value * 0.3048 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::DecimetrePerMinute, Speed::MetrePerSecond),
      value * 0.1 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::InchPerMinute, Speed::MetrePerSecond),
      value * 0.0254 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::CentimetrePerMinute, Speed::MetrePerSecond),
      value * 0.01 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MillimetrePerMinute, Speed::MetrePerSecond),
      value * 0.001 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MilliinchPerMinute, Speed::MetrePerSecond),
      value * 0.0000254 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MicrometrePerMinute, Speed::MetrePerSecond),
      value * 0.000001 / 60.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MicroinchPerMinute, Speed::MetrePerSecond),
      value * 0.0000000254 / 60.0);

  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MilePerHour, Speed::MetrePerSecond),
      value * 1609.344 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::KilometrePerHour, Speed::MetrePerSecond),
      value * 1000.0 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MetrePerHour, Speed::MetrePerSecond),
      value / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::YardPerHour, Speed::MetrePerSecond),
      value * 0.9144 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::FootPerHour, Speed::MetrePerSecond),
      value * 0.3048 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::DecimetrePerHour, Speed::MetrePerSecond),
      value * 0.1 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::InchPerHour, Speed::MetrePerSecond),
      value * 0.0254 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::CentimetrePerHour, Speed::MetrePerSecond),
      value * 0.01 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MillimetrePerHour, Speed::MetrePerSecond),
      value * 0.001 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MilliinchPerHour, Speed::MetrePerSecond),
      value * 0.0000254 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MicrometrePerHour, Speed::MetrePerSecond),
      value * 0.000001 / 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, Speed::MicroinchPerHour, Speed::MetrePerSecond),
      value * 0.0000000254 / 3600.0);
}

TEST(UnitSpeed, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Speed old_unit : Units) {
    for (const Speed new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitSpeed, DimensionSet) {
  EXPECT_EQ(Dimensions<Speed>,
            Dimension::Set(Dimension::Time{-1}, Dimension::Length{1}));
}

TEST(UnitSpeed, Parse) {
  EXPECT_EQ(Parse<Speed>("Hello world!"), std::nullopt);
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

TEST(UnitSpeed, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Speed::MilePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::KilometrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MetrePerSecond),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Speed::YardPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::FootPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Speed::DecimetrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::InchPerSecond),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Speed::CentimetrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MillimetrePerSecond),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Speed::MilliinchPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MicrometrePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Speed::MicroinchPerSecond), std::nullopt);
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

TEST(UnitSpeed, Standard) { EXPECT_EQ(Standard<Speed>, Speed::MetrePerSecond); }

}  // namespace

}  // namespace PhQ::Unit
