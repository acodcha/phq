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

constexpr std::array<Speed, 12> Units = {
    Speed::MilePerSecond,       Speed::KilometrePerSecond,
    Speed::MetrePerSecond,      Speed::YardPerSecond,
    Speed::FootPerSecond,       Speed::DecimetrePerSecond,
    Speed::InchPerSecond,       Speed::CentimetrePerSecond,
    Speed::MillimetrePerSecond, Speed::MilliinchPerSecond,
    Speed::MicrometrePerSecond, Speed::MicroinchPerSecond,
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
}

TEST(UnitSpeed, StandardUnit) {
  EXPECT_EQ(StandardUnit<Speed>, Speed::MetrePerSecond);
}

}  // namespace

}  // namespace PhQ::Unit
