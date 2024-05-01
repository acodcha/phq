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

TEST(UnitAngularSpeed, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const AngularSpeed original_unit : Units) {
    for (const AngularSpeed intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitAngularSpeed, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(
      AngularSpeed::RadianPerSecond, AngularSpeed::RadianPerSecond, value, value);
  Internal::TestConversions(
      AngularSpeed::RadianPerSecond, AngularSpeed::RadianPerMinute, value, value * 60.0);
  Internal::TestConversions(
      AngularSpeed::RadianPerSecond, AngularSpeed::RadianPerHour, value, value * 3600.0);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::DegreePerSecond, value,
                            value * 180.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::DegreePerMinute, value,
                            value * 10800.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::DegreePerHour, value,
                            value * 648000.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::ArcminutePerSecond, value,
                            value * 10800.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::ArcminutePerMinute, value,
                            value * 648000.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::ArcminutePerHour, value,
                            value * 38880000.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::ArcsecondPerSecond, value,
                            value * 648000.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::ArcsecondPerMinute, value,
                            value * 38880000.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::ArcsecondPerHour, value,
                            value * 2332800000.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::RevolutionPerSecond, value,
                            value * 0.5 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::RevolutionPerMinute, value,
                            value * 30.0 / Pi<double>);
  Internal::TestConversions(AngularSpeed::RadianPerSecond, AngularSpeed::RevolutionPerHour, value,
                            value * 1800.0 / Pi<double>);

  Internal::TestStaticConversions<AngularSpeed, AngularSpeed::RadianPerSecond,
                                  AngularSpeed::DegreePerSecond>(value, value * 180.0 / Pi<double>);
}

TEST(UnitAngularSpeed, ConvertToStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(
      AngularSpeed::RadianPerSecond, AngularSpeed::RadianPerSecond, value, value);
  Internal::TestConversions(
      AngularSpeed::RadianPerMinute, AngularSpeed::RadianPerSecond, value, value / 60.0);
  Internal::TestConversions(
      AngularSpeed::RadianPerHour, AngularSpeed::RadianPerSecond, value, value / 3600.0);
  Internal::TestConversions(AngularSpeed::DegreePerSecond, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 180.0);
  Internal::TestConversions(AngularSpeed::DegreePerMinute, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 10800.0);
  Internal::TestConversions(AngularSpeed::DegreePerHour, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 648000.0);
  Internal::TestConversions(AngularSpeed::ArcminutePerSecond, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 10800.0);
  Internal::TestConversions(AngularSpeed::ArcminutePerMinute, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 648000.0);
  Internal::TestConversions(AngularSpeed::ArcminutePerHour, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 38880000.0);
  Internal::TestConversions(AngularSpeed::ArcsecondPerSecond, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 648000.0);
  Internal::TestConversions(AngularSpeed::ArcsecondPerMinute, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 38880000.0);
  Internal::TestConversions(AngularSpeed::ArcsecondPerHour, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 2332800000.0);
  Internal::TestConversions(AngularSpeed::RevolutionPerSecond, AngularSpeed::RadianPerSecond, value,
                            value * 2.0 * Pi<double>);
  Internal::TestConversions(AngularSpeed::RevolutionPerMinute, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 30.0);
  Internal::TestConversions(AngularSpeed::RevolutionPerHour, AngularSpeed::RadianPerSecond, value,
                            value * Pi<double> / 1800.0);

  Internal::TestStaticConversions<AngularSpeed, AngularSpeed::DegreePerSecond,
                                  AngularSpeed::RadianPerSecond>(value, value * Pi<double> / 180.0);
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

TEST(UnitAngularSpeed, Stream) {
  std::ostringstream stream;
  stream << AngularSpeed::RadianPerSecond;
  EXPECT_EQ(stream.str(), Abbreviation(AngularSpeed::RadianPerSecond));
}

}  // namespace

}  // namespace PhQ::Unit
