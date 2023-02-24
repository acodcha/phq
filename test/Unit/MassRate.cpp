// Copyright 2020 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Unit/MassRate.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<MassRate, 5> Units = {
    MassRate::KilogramPerSecond, MassRate::GramPerSecond,
    MassRate::SlugPerSecond,     MassRate::SlinchPerSecond,
    MassRate::PoundPerSecond,
};

TEST(UnitMassRate, Abbreviation) {
  EXPECT_EQ(Abbreviation(MassRate::KilogramPerSecond), "kg/s");
  EXPECT_EQ(Abbreviation(MassRate::GramPerSecond), "g/s");
  EXPECT_EQ(Abbreviation(MassRate::SlugPerSecond), "slug/s");
  EXPECT_EQ(Abbreviation(MassRate::SlinchPerSecond), "slinch/s");
  EXPECT_EQ(Abbreviation(MassRate::PoundPerSecond), "lbm/s");
}

TEST(UnitMassRate, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<MassRate>(UnitSystem::MetreKilogramSecondKelvin),
            MassRate::KilogramPerSecond);
  EXPECT_EQ(ConsistentUnit<MassRate>(UnitSystem::MillimetreGramSecondKelvin),
            MassRate::GramPerSecond);
  EXPECT_EQ(ConsistentUnit<MassRate>(UnitSystem::FootPoundSecondRankine),
            MassRate::SlugPerSecond);
  EXPECT_EQ(ConsistentUnit<MassRate>(UnitSystem::InchPoundSecondRankine),
            MassRate::SlinchPerSecond);
}

TEST(UnitMassRate, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassRate::KilogramPerSecond,
                               MassRate::KilogramPerSecond),
                   value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MassRate::KilogramPerSecond, MassRate::GramPerSecond),
      value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MassRate::KilogramPerSecond, MassRate::SlugPerSecond),
      value * 0.3048 / (0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassRate::KilogramPerSecond,
                               MassRate::SlinchPerSecond),
                   value * 0.0254 / (0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MassRate::KilogramPerSecond, MassRate::PoundPerSecond),
      value / 0.45359237);
}

TEST(UnitMassRate, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassRate::KilogramPerSecond,
                               MassRate::KilogramPerSecond),
                   value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MassRate::GramPerSecond, MassRate::KilogramPerSecond),
      value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MassRate::SlugPerSecond, MassRate::KilogramPerSecond),
      value * 0.45359237 * 9.80665 / 0.3048);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassRate::SlinchPerSecond,
                               MassRate::KilogramPerSecond),
                   value * 0.45359237 * 9.80665 / 0.0254);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, MassRate::PoundPerSecond, MassRate::KilogramPerSecond),
      value * 0.45359237);
}

TEST(UnitMassRate, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const MassRate old_unit : Units) {
    for (const MassRate new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitMassRate, DimensionSet) {
  EXPECT_EQ(Dimensions<MassRate>,
            Dimension::Set(Dimension::Time{-1}, Dimension::Length{0},
                           Dimension::Mass{1}));
}

TEST(UnitMassRate, Parse) {
  EXPECT_EQ(Parse<MassRate>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<MassRate>("kg/s"), MassRate::KilogramPerSecond);
  EXPECT_EQ(Parse<MassRate>("g/s"), MassRate::GramPerSecond);
  EXPECT_EQ(Parse<MassRate>("slug/s"), MassRate::SlugPerSecond);
  EXPECT_EQ(Parse<MassRate>("slinch/s"), MassRate::SlinchPerSecond);
  EXPECT_EQ(Parse<MassRate>("lbm/s"), MassRate::PoundPerSecond);
}

TEST(UnitMassRate, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(MassRate::KilogramPerSecond),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(MassRate::GramPerSecond),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(MassRate::SlugPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(MassRate::SlinchPerSecond),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(MassRate::PoundPerSecond), std::nullopt);
}

TEST(UnitMassRate, StandardUnit) {
  EXPECT_EQ(StandardUnit<MassRate>, MassRate::KilogramPerSecond);
}

}  // namespace

}  // namespace PhQ::Unit
