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

#include "../Unit.hpp"

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
  EXPECT_EQ(
      Abbreviation(SpecificPower::FootPoundPerSlugPerSecond), "ft·lbf/slug/s");
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
  Internal::TestUnitConversions<SpecificPower, SpecificPower::WattPerKilogram,
                                SpecificPower::WattPerKilogram>(value, value);
  Internal::TestUnitConversions<SpecificPower, SpecificPower::WattPerKilogram,
                                SpecificPower::NanowattPerGram>(
      value, value * 1000000.0);
  Internal::TestUnitConversions<SpecificPower, SpecificPower::WattPerKilogram,
                                SpecificPower::FootPoundPerSlugPerSecond>(
      value, value / std::pow(0.3048, 2));
  Internal::TestUnitConversions<SpecificPower, SpecificPower::WattPerKilogram,
                                SpecificPower::InchPoundPerSlinchPerSecond>(
      value, value / std::pow(0.0254, 2));
}

TEST(UnitSpecificPower, ConvertToStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<SpecificPower, SpecificPower::WattPerKilogram,
                                SpecificPower::WattPerKilogram>(value, value);
  Internal::TestUnitConversions<SpecificPower, SpecificPower::NanowattPerGram,
                                SpecificPower::WattPerKilogram>(
      value, value * 0.000001);
  Internal::TestUnitConversions<
      SpecificPower, SpecificPower::FootPoundPerSlugPerSecond,
      SpecificPower::WattPerKilogram>(value, value * std::pow(0.3048, 2));
  Internal::TestUnitConversions<
      SpecificPower, SpecificPower::InchPoundPerSlinchPerSecond,
      SpecificPower::WattPerKilogram>(value, value * std::pow(0.0254, 2));
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

TEST(UnitSpecificPower, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<SpecificPower>,
            Dimensions(Dimension::Time{-3}, Dimension::Length{2}));
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

TEST(UnitSpecificPower, Standard) {
  EXPECT_EQ(Standard<SpecificPower>, SpecificPower::WattPerKilogram);
}

TEST(UnitSpecificPower, Stream) {
  std::ostringstream stream;
  stream << SpecificPower::WattPerKilogram;
  EXPECT_EQ(stream.str(), Abbreviation(SpecificPower::WattPerKilogram));
}

}  // namespace

}  // namespace PhQ::Unit
