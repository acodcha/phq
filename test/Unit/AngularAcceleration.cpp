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

#include "../../include/PhQ/Unit/AngularAcceleration.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<AngularAcceleration, 15> Units = {
    AngularAcceleration::RadianPerSquareSecond,
    AngularAcceleration::RadianPerSquareMinute,
    AngularAcceleration::RadianPerSquareHour,
    AngularAcceleration::DegreePerSquareSecond,
    AngularAcceleration::DegreePerSquareMinute,
    AngularAcceleration::DegreePerSquareHour,
    AngularAcceleration::ArcminutePerSquareSecond,
    AngularAcceleration::ArcminutePerSquareMinute,
    AngularAcceleration::ArcminutePerSquareHour,
    AngularAcceleration::ArcsecondPerSquareSecond,
    AngularAcceleration::ArcsecondPerSquareMinute,
    AngularAcceleration::ArcsecondPerSquareHour,
    AngularAcceleration::RevolutionPerSquareSecond,
    AngularAcceleration::RevolutionPerSquareMinute,
    AngularAcceleration::RevolutionPerSquareHour,
};

TEST(UnitAngularAcceleration, Abbreviation) {
  EXPECT_EQ(Abbreviation(AngularAcceleration::RadianPerSquareSecond),
            "rad/"
            "s^2");
  EXPECT_EQ(
      Abbreviation(AngularAcceleration::RadianPerSquareMinute), "rad/min^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::RadianPerSquareHour), "rad/hr^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::DegreePerSquareSecond),
            "deg/"
            "s^2");
  EXPECT_EQ(
      Abbreviation(AngularAcceleration::DegreePerSquareMinute), "deg/min^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::DegreePerSquareHour), "deg/hr^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcminutePerSquareSecond),
            "arcmin/s^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcminutePerSquareMinute),
            "arcmin/min^2");
  EXPECT_EQ(
      Abbreviation(AngularAcceleration::ArcminutePerSquareHour), "arcmin/hr^2");

  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcsecondPerSquareSecond),
            "arcsec/s^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::ArcsecondPerSquareMinute),
            "arcsec/min^2");
  EXPECT_EQ(
      Abbreviation(AngularAcceleration::ArcsecondPerSquareHour), "arcsec/hr^2");
  EXPECT_EQ(
      Abbreviation(AngularAcceleration::RevolutionPerSquareSecond), "rev/s^2");
  EXPECT_EQ(Abbreviation(AngularAcceleration::RevolutionPerSquareMinute),
            "rev/min^2");
  EXPECT_EQ(
      Abbreviation(AngularAcceleration::RevolutionPerSquareHour), "rev/hr^2");
}

TEST(UnitAngularAcceleration, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<AngularAcceleration>(
                UnitSystem::MetreKilogramSecondKelvin),
            AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(ConsistentUnit<AngularAcceleration>(
                UnitSystem::MillimetreGramSecondKelvin),
            AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(
      ConsistentUnit<AngularAcceleration>(UnitSystem::FootPoundSecondRankine),
      AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(
      ConsistentUnit<AngularAcceleration>(UnitSystem::InchPoundSecondRankine),
      AngularAcceleration::RadianPerSquareSecond);
}

TEST(UnitAngularAcceleration, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::RadianPerSquareSecond),
      value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::RadianPerSquareMinute),
      value * 3600.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::RadianPerSquareHour),
      value * 12960000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::DegreePerSquareSecond),
      value * 180.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::DegreePerSquareMinute),
      value * 648000.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::DegreePerSquareHour),
      value * 2332800000.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::ArcminutePerSquareSecond),
      value * 10800.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::ArcminutePerSquareMinute),
      value * 38880000.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::ArcminutePerSquareHour),
      value * 139968000000.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::ArcsecondPerSquareSecond),
      value * 648000.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::ArcsecondPerSquareMinute),
      value * 2332800000.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::ArcsecondPerSquareHour),
      value * 8398080000000.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::RevolutionPerSquareSecond),
      value * 0.5 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::RevolutionPerSquareMinute),
      value * 1800.0 / Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::RevolutionPerSquareHour),
      value * 6480000.0 / Pi);
}

TEST(UnitAngularAcceleration, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareSecond,
                  AngularAcceleration::RadianPerSquareSecond),
      value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RadianPerSquareMinute,
                  AngularAcceleration::RadianPerSquareSecond),
      value / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularAcceleration::RadianPerSquareHour,
                               AngularAcceleration::RadianPerSquareSecond),
                   value / 12960000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::DegreePerSquareSecond,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 180.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::DegreePerSquareMinute,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 648000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularAcceleration::DegreePerSquareHour,
                               AngularAcceleration::RadianPerSquareSecond),
                   value * Pi / 2332800000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::ArcminutePerSquareSecond,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 10800.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::ArcminutePerSquareMinute,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 38880000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::ArcminutePerSquareHour,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 139968000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::ArcsecondPerSquareSecond,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 648000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::ArcsecondPerSquareMinute,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 2332800000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::ArcsecondPerSquareHour,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 8398080000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RevolutionPerSquareSecond,
                  AngularAcceleration::RadianPerSquareSecond),
      value * 2.0 * Pi);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RevolutionPerSquareMinute,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 1800.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, AngularAcceleration::RevolutionPerSquareHour,
                  AngularAcceleration::RadianPerSquareSecond),
      value * Pi / 6480000.0);
}

TEST(UnitAngularAcceleration, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const AngularAcceleration old_unit : Units) {
    for (const AngularAcceleration new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitAngularAcceleration, Dimensions) {
  EXPECT_EQ(
      Dimensions<AngularAcceleration>, Dimension::Set{Dimension::Time{-2}});
}

TEST(UnitAngularAcceleration, Parse) {
  EXPECT_EQ(Parse<AngularAcceleration>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<AngularAcceleration>("rad/s^2"),
            AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(Parse<AngularAcceleration>("rad/min^2"),
            AngularAcceleration::RadianPerSquareMinute);
  EXPECT_EQ(Parse<AngularAcceleration>("rad/hr^2"),
            AngularAcceleration::RadianPerSquareHour);
  EXPECT_EQ(Parse<AngularAcceleration>("deg/s^2"),
            AngularAcceleration::DegreePerSquareSecond);
  EXPECT_EQ(Parse<AngularAcceleration>("deg/min^2"),
            AngularAcceleration::DegreePerSquareMinute);
  EXPECT_EQ(Parse<AngularAcceleration>("deg/hr^2"),
            AngularAcceleration::DegreePerSquareHour);
  EXPECT_EQ(Parse<AngularAcceleration>("arcmin/s^2"),
            AngularAcceleration::ArcminutePerSquareSecond);
  EXPECT_EQ(Parse<AngularAcceleration>("arcmin/min^2"),
            AngularAcceleration::ArcminutePerSquareMinute);
  EXPECT_EQ(Parse<AngularAcceleration>("arcmin/hr^2"),
            AngularAcceleration::ArcminutePerSquareHour);
  EXPECT_EQ(Parse<AngularAcceleration>("arcsec/s^2"),
            AngularAcceleration::ArcsecondPerSquareSecond);
  EXPECT_EQ(Parse<AngularAcceleration>("arcsec/min^2"),
            AngularAcceleration::ArcsecondPerSquareMinute);
  EXPECT_EQ(Parse<AngularAcceleration>("arcsec/hr^2"),
            AngularAcceleration::ArcsecondPerSquareHour);
  EXPECT_EQ(Parse<AngularAcceleration>("rev/s^2"),
            AngularAcceleration::RevolutionPerSquareSecond);
  EXPECT_EQ(Parse<AngularAcceleration>("rev/min^2"),
            AngularAcceleration::RevolutionPerSquareMinute);
  EXPECT_EQ(Parse<AngularAcceleration>("rev/hr^2"),
            AngularAcceleration::RevolutionPerSquareHour);
}

TEST(UnitAngularAcceleration, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RadianPerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RadianPerSquareMinute),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RadianPerSquareHour),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::DegreePerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::DegreePerSquareMinute),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::DegreePerSquareHour),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcminutePerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcminutePerSquareMinute),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcminutePerSquareHour),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcsecondPerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcsecondPerSquareMinute),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::ArcsecondPerSquareHour),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RevolutionPerSquareSecond),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RevolutionPerSquareMinute),
            std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularAcceleration::RevolutionPerSquareHour),
            std::nullopt);
}

TEST(UnitAngularAcceleration, StandardUnit) {
  EXPECT_EQ(StandardUnit<AngularAcceleration>,
            AngularAcceleration::RadianPerSquareSecond);
}

}  // namespace

}  // namespace PhQ::Unit
