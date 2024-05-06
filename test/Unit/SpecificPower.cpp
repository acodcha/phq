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

#include "../../include/PhQ/Unit/SpecificPower.hpp"

#include <array>
#include <cmath>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
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
  EXPECT_EQ(Abbreviation(SpecificPower::FootPoundPerSlugPerSecond), "ft·lbf/slug/s");
  EXPECT_EQ(Abbreviation(SpecificPower::InchPoundPerSlinchPerSecond), "in·lbf/slinch/s");
}

TEST(UnitSpecificPower, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::MetreKilogramSecondKelvin),
            SpecificPower::WattPerKilogram);
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::MillimetreGramSecondKelvin),
            SpecificPower::NanowattPerGram);
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::FootPoundSecondRankine),
            SpecificPower::FootPoundPerSlugPerSecond);
  EXPECT_EQ(ConsistentUnit<SpecificPower>(UnitSystem::InchPoundSecondRankine),
            SpecificPower::InchPoundPerSlinchPerSecond);
}

TEST(UnitSpecificPower, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<SpecificPower>(
      SpecificPower::WattPerKilogram, SpecificPower::WattPerKilogram, value, value);
  Internal::TestConvertAndConvertCopy<SpecificPower>(
      SpecificPower::WattPerKilogram, SpecificPower::NanowattPerGram, value, value * 1000000.0L);
  Internal::TestConvertAndConvertCopy<SpecificPower>(
      SpecificPower::WattPerKilogram, SpecificPower::FootPoundPerSlugPerSecond, value,
      value / std::pow(0.3048L, 2));
  Internal::TestConvertAndConvertCopy<SpecificPower>(
      SpecificPower::WattPerKilogram, SpecificPower::InchPoundPerSlinchPerSecond, value,
      value / std::pow(0.0254L, 2));
}

TEST(UnitSpecificPower, Parse) {
  EXPECT_EQ(Parse<SpecificPower>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<SpecificPower>("W/kg"), SpecificPower::WattPerKilogram);
  EXPECT_EQ(Parse<SpecificPower>("nW/g"), SpecificPower::NanowattPerGram);
  EXPECT_EQ(Parse<SpecificPower>("ft·lbf/slug/s"), SpecificPower::FootPoundPerSlugPerSecond);
  EXPECT_EQ(Parse<SpecificPower>("in·lbf/slinch/s"), SpecificPower::InchPoundPerSlinchPerSecond);
}

TEST(UnitSpecificPower, RelatedDimensions) {
  EXPECT_EQ(
      RelatedDimensions<SpecificPower>, Dimensions(Dimension::Time{-3}, Dimension::Length{2}));
}

TEST(UnitSpecificPower, RelatedUnitSystem) {
  EXPECT_EQ(
      RelatedUnitSystem(SpecificPower::WattPerKilogram), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(
      RelatedUnitSystem(SpecificPower::NanowattPerGram), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificPower::FootPoundPerSlugPerSecond),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(SpecificPower::InchPoundPerSlinchPerSecond),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitSpecificPower, Standard) {
  EXPECT_EQ(Standard<SpecificPower>, SpecificPower::WattPerKilogram);
}

TEST(UnitSpecificPower, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<SpecificPower, SpecificPower::WattPerKilogram,
                                  SpecificPower::FootPoundPerSlugPerSecond>(
      value, value / std::pow(0.3048L, 2));
}

TEST(UnitSpecificPower, Stream) {
  std::ostringstream stream;
  stream << SpecificPower::WattPerKilogram;
  EXPECT_EQ(stream.str(), Abbreviation(SpecificPower::WattPerKilogram));
}

}  // namespace

}  // namespace PhQ::Unit
