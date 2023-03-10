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

#include "../../include/PhQ/Unit/AngularSpeed.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<AngularSpeed, 9> Units = {
    AngularSpeed::RadianPerSecond,     AngularSpeed::RadianPerMinute,
    AngularSpeed::RadianPerHour,       AngularSpeed::DegreePerSecond,
    AngularSpeed::DegreePerMinute,     AngularSpeed::DegreePerHour,
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
  EXPECT_EQ(Abbreviation(AngularSpeed::RevolutionPerSecond), "rev/s");
  EXPECT_EQ(Abbreviation(AngularSpeed::RevolutionPerMinute), "rev/min");
  EXPECT_EQ(Abbreviation(AngularSpeed::RevolutionPerHour), "rev/hr");
}

TEST(UnitAngularSpeed, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<AngularSpeed>(UnitSystem::MetreKilogramSecondKelvin),
            AngularSpeed::RadianPerSecond);
  EXPECT_EQ(
      ConsistentUnit<AngularSpeed>(UnitSystem::MillimetreGramSecondKelvin),
      AngularSpeed::RadianPerSecond);
  EXPECT_EQ(ConsistentUnit<AngularSpeed>(UnitSystem::FootPoundSecondRankine),
            AngularSpeed::RadianPerSecond);
  EXPECT_EQ(ConsistentUnit<AngularSpeed>(UnitSystem::InchPoundSecondRankine),
            AngularSpeed::RadianPerSecond);
}

TEST(UnitAngularSpeed, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::RadianPerSecond),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::RadianPerMinute),
                   value * 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::RadianPerHour),
                   value * 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::DegreePerSecond),
                   value * 180.0 / Pi);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::DegreePerMinute),
                   value * 10800.0 / Pi);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::DegreePerHour),
                   value * 648000.0 / Pi);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::RevolutionPerSecond),
                   value * 0.5 / Pi);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::RevolutionPerMinute),
                   value * 30.0 / Pi);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::RevolutionPerHour),
                   value * 1800.0 / Pi);
}

TEST(UnitAngularSpeed, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerSecond,
                               AngularSpeed::RadianPerSecond),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerMinute,
                               AngularSpeed::RadianPerSecond),
                   value / 60.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RadianPerHour,
                               AngularSpeed::RadianPerSecond),
                   value / 3600.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::DegreePerSecond,
                               AngularSpeed::RadianPerSecond),
                   value * Pi / 180.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::DegreePerMinute,
                               AngularSpeed::RadianPerSecond),
                   value * Pi / 10800.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::DegreePerHour,
                               AngularSpeed::RadianPerSecond),
                   value * Pi / 648000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RevolutionPerSecond,
                               AngularSpeed::RadianPerSecond),
                   value * 2.0 * Pi);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RevolutionPerMinute,
                               AngularSpeed::RadianPerSecond),
                   value * Pi / 30.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, AngularSpeed::RevolutionPerHour,
                               AngularSpeed::RadianPerSecond),
                   value * Pi / 1800.0);
}

TEST(UnitAngularSpeed, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const AngularSpeed old_unit : Units) {
    for (const AngularSpeed new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitAngularSpeed, Dimensions) {
  EXPECT_EQ(Dimensions<AngularSpeed>, Dimension::Set{Dimension::Time{-1}});
}

TEST(UnitAngularSpeed, Parse) {
  EXPECT_EQ(Parse<AngularSpeed>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<AngularSpeed>("rad/s"), AngularSpeed::RadianPerSecond);
  EXPECT_EQ(Parse<AngularSpeed>("rad/min"), AngularSpeed::RadianPerMinute);
  EXPECT_EQ(Parse<AngularSpeed>("rad/hr"), AngularSpeed::RadianPerHour);
  EXPECT_EQ(Parse<AngularSpeed>("deg/s"), AngularSpeed::DegreePerSecond);
  EXPECT_EQ(Parse<AngularSpeed>("deg/min"), AngularSpeed::DegreePerMinute);
  EXPECT_EQ(Parse<AngularSpeed>("deg/hr"), AngularSpeed::DegreePerHour);
  EXPECT_EQ(Parse<AngularSpeed>("rev/s"), AngularSpeed::RevolutionPerSecond);
  EXPECT_EQ(Parse<AngularSpeed>("rev/min"), AngularSpeed::RevolutionPerMinute);
  EXPECT_EQ(Parse<AngularSpeed>("rev/hr"), AngularSpeed::RevolutionPerHour);
}

TEST(UnitAngularSpeed, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RadianPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RadianPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RadianPerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::DegreePerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::DegreePerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::DegreePerHour), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RevolutionPerSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RevolutionPerMinute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(AngularSpeed::RevolutionPerHour), std::nullopt);
}

TEST(UnitAngularSpeed, StandardUnit) {
  EXPECT_EQ(StandardUnit<AngularSpeed>, AngularSpeed::RadianPerSecond);
}

}  // namespace

}  // namespace PhQ::Unit
