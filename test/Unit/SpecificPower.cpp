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

#include "../../include/PhQ/Unit/SpecificPower.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<SpecificPower, 4> Units = {
    SpecificPower::WattPerKilogram,
    SpecificPower::NanowattPerGram,
    SpecificPower::FootPoundPerSlugPerSecond,
    SpecificPower::InchPoundPerSlinchPerSecond,
};

TEST(UnitSpecificPower, Abbreviation) {
  EXPECT_EQ(Abbreviation(SpecificPower::WattPerKilogram), "W/kg");
  EXPECT_EQ(Abbreviation(SpecificPower::NanowattPerGram), "nW/g");
  EXPECT_EQ(Abbreviation(SpecificPower::FootPoundPerSlugPerSecond),
            "ft·lbf/slug/s");
  EXPECT_EQ(Abbreviation(SpecificPower::InchPoundPerSlinchPerSecond),
            "in·lbf/slinch/s");
}

TEST(UnitSpecificPower, ConsistentUnit) {
  EXPECT_EQ(
      ConsistentUnit<SpecificPower>(UnitSystem::MetreKilogramSecondKelvin),
      SpecificPower::WattPerKilogram);
  EXPECT_EQ(
      ConsistentUnit<SpecificPower>(UnitSystem::MillimetreGramSecondKelvin),
      SpecificPower::NanowattPerGram);
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::FootPoundSecondRankine),
            SpecificPower::FootPoundPerSlugPerSecond);
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::InchPoundSecondRankine),
            SpecificPower::InchPoundPerSlinchPerSecond);
}

TEST(UnitSpecificPower, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificPower::WattPerKilogram,
                               SpecificPower::WattPerKilogram),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificPower::WattPerKilogram,
                               SpecificPower::NanowattPerGram),
                   value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificPower::WattPerKilogram,
                               SpecificPower::FootPoundPerSlugPerSecond),
                   value / std::pow(0.3048, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificPower::WattPerKilogram,
                               SpecificPower::InchPoundPerSlinchPerSecond),
                   value / std::pow(0.0254, 2));
}

TEST(UnitSpecificPower, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificPower::WattPerKilogram,
                               SpecificPower::WattPerKilogram),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificPower::NanowattPerGram,
                               SpecificPower::WattPerKilogram),
                   value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificPower::FootPoundPerSlugPerSecond,
                               SpecificPower::WattPerKilogram),
                   value * std::pow(0.3048, 2));
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SpecificPower::InchPoundPerSlinchPerSecond,
                  SpecificPower::WattPerKilogram),
      value * std::pow(0.0254, 2));
}

TEST(UnitSpecificPower, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const SpecificPower old_unit : Units) {
    for (const SpecificPower new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitSpecificPower, DimensionSet) {
  EXPECT_EQ(Dimensions<SpecificPower>,
            Dimension::Set(Dimension::Time{-3}, Dimension::Length{2}));
}

TEST(UnitSpecificPower, Parse) {
  EXPECT_EQ(Parse<SpecificPower>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<SpecificPower>("W/kg"), SpecificPower::WattPerKilogram);
  EXPECT_EQ(Parse<SpecificPower>("nW/g"), SpecificPower::NanowattPerGram);
  EXPECT_EQ(Parse<SpecificPower>("ft·lbf/slug/s"),
            SpecificPower::FootPoundPerSlugPerSecond);
  EXPECT_EQ(Parse<SpecificPower>("in·lbf/slinch/s"),
            SpecificPower::InchPoundPerSlinchPerSecond);
}

TEST(UnitSpecificPower, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(SpecificPower::WattPerKilogram),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificPower::NanowattPerGram),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificPower::FootPoundPerSlugPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(SpecificPower::InchPoundPerSlinchPerSecond),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitSpecificPower, StandardUnit) {
  EXPECT_EQ(StandardUnit<SpecificPower>, SpecificPower::WattPerKilogram);
}

}  // namespace

}  // namespace PhQ::Unit
