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

#include "../Unit.hpp"

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
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RadianPerSquareSecond,
      AngularAcceleration::RadianPerSquareSecond>(value, value);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RadianPerSquareSecond,
      AngularAcceleration::RadianPerSquareMinute>(value, value * 3600.0);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RadianPerSquareSecond,
      AngularAcceleration::RadianPerSquareHour>(value, value * 12960000.0);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RadianPerSquareSecond,
      AngularAcceleration::DegreePerSquareSecond>(value, value * 180.0 / Pi);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RadianPerSquareSecond,
      AngularAcceleration::DegreePerSquareMinute>(value, value * 648000.0 / Pi);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RadianPerSquareSecond,
                                AngularAcceleration::DegreePerSquareHour>(
      value, value * 2332800000.0 / Pi);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RadianPerSquareSecond,
                                AngularAcceleration::ArcminutePerSquareSecond>(
      value, value * 10800.0 / Pi);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RadianPerSquareSecond,
                                AngularAcceleration::ArcminutePerSquareMinute>(
      value, value * 38880000.0 / Pi);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RadianPerSquareSecond,
                                AngularAcceleration::ArcminutePerSquareHour>(
      value, value * 139968000000.0 / Pi);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RadianPerSquareSecond,
                                AngularAcceleration::ArcsecondPerSquareSecond>(
      value, value * 648000.0 / Pi);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RadianPerSquareSecond,
                                AngularAcceleration::ArcsecondPerSquareMinute>(
      value, value * 2332800000.0 / Pi);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RadianPerSquareSecond,
                                AngularAcceleration::ArcsecondPerSquareHour>(
      value, value * 8398080000000.0 / Pi);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RadianPerSquareSecond,
      AngularAcceleration::RevolutionPerSquareSecond>(value, value * 0.5 / Pi);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RadianPerSquareSecond,
                                AngularAcceleration::RevolutionPerSquareMinute>(
      value, value * 1800.0 / Pi);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RadianPerSquareSecond,
                                AngularAcceleration::RevolutionPerSquareHour>(
      value, value * 6480000.0 / Pi);
}

TEST(UnitAngularAcceleration, ConvertToStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RadianPerSquareSecond,
      AngularAcceleration::RadianPerSquareSecond>(value, value);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RadianPerSquareMinute,
      AngularAcceleration::RadianPerSquareSecond>(value, value / 3600.0);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RadianPerSquareHour,
      AngularAcceleration::RadianPerSquareSecond>(value, value / 12960000.0);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::DegreePerSquareSecond,
      AngularAcceleration::RadianPerSquareSecond>(value, value * Pi / 180.0);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::DegreePerSquareMinute,
      AngularAcceleration::RadianPerSquareSecond>(value, value * Pi / 648000.0);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::DegreePerSquareHour,
                                AngularAcceleration::RadianPerSquareSecond>(
      value, value * Pi / 2332800000.0);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::ArcminutePerSquareSecond,
      AngularAcceleration::RadianPerSquareSecond>(value, value * Pi / 10800.0);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::ArcminutePerSquareMinute,
                                AngularAcceleration::RadianPerSquareSecond>(
      value, value * Pi / 38880000.0);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::ArcminutePerSquareHour,
                                AngularAcceleration::RadianPerSquareSecond>(
      value, value * Pi / 139968000000.0);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::ArcsecondPerSquareSecond,
      AngularAcceleration::RadianPerSquareSecond>(value, value * Pi / 648000.0);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::ArcsecondPerSquareMinute,
                                AngularAcceleration::RadianPerSquareSecond>(
      value, value * Pi / 2332800000.0);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::ArcsecondPerSquareHour,
                                AngularAcceleration::RadianPerSquareSecond>(
      value, value * Pi / 8398080000000.0);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RevolutionPerSquareSecond,
      AngularAcceleration::RadianPerSquareSecond>(value, value * 2.0 * Pi);
  Internal::TestUnitConversions<
      AngularAcceleration, AngularAcceleration::RevolutionPerSquareMinute,
      AngularAcceleration::RadianPerSquareSecond>(value, value * Pi / 1800.0);
  Internal::TestUnitConversions<AngularAcceleration,
                                AngularAcceleration::RevolutionPerSquareHour,
                                AngularAcceleration::RadianPerSquareSecond>(
      value, value * Pi / 6480000.0);
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

TEST(UnitAngularAcceleration, RelatedDimensions) {
  EXPECT_EQ(
      RelatedDimensions<AngularAcceleration>, Dimensions{Dimension::Time{-2}});
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

TEST(UnitAngularAcceleration, Standard) {
  EXPECT_EQ(Standard<AngularAcceleration>,
            AngularAcceleration::RadianPerSquareSecond);
}

TEST(UnitAngularAcceleration, Stream) {
  std::ostringstream stream;
  stream << AngularAcceleration::RadianPerSquareSecond;
  EXPECT_EQ(
      stream.str(), Abbreviation(AngularAcceleration::RadianPerSquareSecond));
}

}  // namespace

}  // namespace PhQ::Unit
