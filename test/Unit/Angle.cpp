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

#include "../../include/PhQ/Unit/Angle.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<Angle, 4> Units = {
    Angle::Radian,
    Angle::Degree,
    Angle::Arcminute,
    Angle::Arcsecond,
};

TEST(UnitAngle, Abbreviation) {
  EXPECT_EQ(Abbreviation(Angle::Radian), "rad");
  EXPECT_EQ(Abbreviation(Angle::Degree), "deg");
  EXPECT_EQ(Abbreviation(Angle::Arcminute), "arcmin");
  EXPECT_EQ(Abbreviation(Angle::Arcsecond), "arcsec");
}

TEST(UnitAngle, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::MetreKilogramSecondKelvin),
            Angle::Radian);
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::MillimetreGramSecondKelvin),
            Angle::Radian);
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::FootPoundSecondRankine),
            Angle::Radian);
  EXPECT_EQ(ConsistentUnit<Angle>(UnitSystem::InchPoundSecondRankine),
            Angle::Radian);
}

TEST(UnitAngle, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Angle::Radian, Angle::Radian), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Angle::Radian, Angle::Degree),
                   value * 180.0 / Pi);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Angle::Radian, Angle::Arcminute),
                   value * 10800.0 / Pi);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Angle::Radian, Angle::Arcsecond),
                   value * 648000.0 / Pi);
}

TEST(UnitAngle, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Angle::Radian, Angle::Radian), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Angle::Degree, Angle::Radian),
                   value * Pi / 180.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Angle::Arcminute, Angle::Radian),
                   value * Pi / 10800.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Angle::Arcsecond, Angle::Radian),
                   value * Pi / 648000.0);
}

TEST(UnitAngle, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Angle old_unit : Units) {
    for (const Angle new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitAngle, DimensionSet) {
  EXPECT_EQ(Dimensions<Angle>, Dimension::Set{});
}

TEST(UnitAngle, Parse) {
  EXPECT_EQ(Parse<Angle>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Angle>("rad"), Angle::Radian);
  EXPECT_EQ(Parse<Angle>("deg"), Angle::Degree);
  EXPECT_EQ(Parse<Angle>("arcmin"), Angle::Arcminute);
  EXPECT_EQ(Parse<Angle>("arcsec"), Angle::Arcsecond);
}

TEST(UnitAngle, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Angle::Radian), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Degree), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Arcminute), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(Angle::Arcsecond), std::nullopt);
}

TEST(UnitAngle, StandardUnit) { EXPECT_EQ(StandardUnit<Angle>, Angle::Radian); }

}  // namespace

}  // namespace PhQ::Unit
