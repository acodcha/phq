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

#include "../../include/PhQ/Unit/MassDensity.hpp"

#include <array>
#include <cmath>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Mass.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<MassDensity, 6> Units = {
    MassDensity::KilogramPerCubicMetre, MassDensity::GramPerCubicMillimetre,
    MassDensity::SlugPerCubicFoot,      MassDensity::SlinchPerCubicInch,
    MassDensity::PoundPerCubicFoot,     MassDensity::PoundPerCubicInch,
};

TEST(UnitMassDensity, Abbreviation) {
  EXPECT_EQ(Abbreviation(MassDensity::KilogramPerCubicMetre), "kg/m^3");
  EXPECT_EQ(Abbreviation(MassDensity::GramPerCubicMillimetre), "g/mm^3");
  EXPECT_EQ(Abbreviation(MassDensity::SlugPerCubicFoot), "slug/ft^3");
  EXPECT_EQ(Abbreviation(MassDensity::SlinchPerCubicInch), "slinch/in^3");
  EXPECT_EQ(Abbreviation(MassDensity::PoundPerCubicFoot), "lbm/ft^3");
  EXPECT_EQ(Abbreviation(MassDensity::PoundPerCubicInch), "lbm/in^3");
}

TEST(UnitMassDensity, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<MassDensity>(UnitSystem::MetreKilogramSecondKelvin),
            MassDensity::KilogramPerCubicMetre);
  EXPECT_EQ(ConsistentUnit<MassDensity>(UnitSystem::MillimetreGramSecondKelvin),
            MassDensity::GramPerCubicMillimetre);
  EXPECT_EQ(ConsistentUnit<MassDensity>(UnitSystem::FootPoundSecondRankine),
            MassDensity::SlugPerCubicFoot);
  EXPECT_EQ(ConsistentUnit<MassDensity>(UnitSystem::InchPoundSecondRankine),
            MassDensity::SlinchPerCubicInch);
}

TEST(UnitMassDensity, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertAndConvertCopy<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::KilogramPerCubicMetre, value, value);
  Internal::TestConvertAndConvertCopy<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::GramPerCubicMillimetre, value,
      value * 0.000001L);
  Internal::TestConvertAndConvertCopy<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::SlugPerCubicFoot, value,
      value * std::pow(0.3048L, 4) / (0.45359237L * 9.80665L));
  Internal::TestConvertAndConvertCopy<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::SlinchPerCubicInch, value,
      value * std::pow(0.0254L, 4) / (0.45359237L * 9.80665L));
  Internal::TestConvertAndConvertCopy<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::PoundPerCubicFoot, value,
      value * std::pow(0.3048L, 3) / 0.45359237L);
  Internal::TestConvertAndConvertCopy<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::PoundPerCubicInch, value,
      value * std::pow(0.0254L, 3) / 0.45359237L);
}

TEST(UnitMassDensity, Parse) {
  EXPECT_EQ(Parse<MassDensity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<MassDensity>("kg/m^3"), MassDensity::KilogramPerCubicMetre);
  EXPECT_EQ(Parse<MassDensity>("g/mm^3"), MassDensity::GramPerCubicMillimetre);
  EXPECT_EQ(Parse<MassDensity>("slug/ft^3"), MassDensity::SlugPerCubicFoot);
  EXPECT_EQ(Parse<MassDensity>("slinch/in^3"), MassDensity::SlinchPerCubicInch);
  EXPECT_EQ(Parse<MassDensity>("lbm/ft^3"), MassDensity::PoundPerCubicFoot);
  EXPECT_EQ(Parse<MassDensity>("lbm/in^3"), MassDensity::PoundPerCubicInch);
}

TEST(UnitMassDensity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<MassDensity>,
            Dimensions(Dimension::Time{}, Dimension::Length{-3}, Dimension::Mass{1}));
}

TEST(UnitMassDensity, RelatedUnitSystem) {
  EXPECT_EQ(
      RelatedUnitSystem(MassDensity::KilogramPerCubicMetre), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::GramPerCubicMillimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::SlugPerCubicFoot), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::SlinchPerCubicInch), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::PoundPerCubicFoot), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::PoundPerCubicInch), std::nullopt);
}

TEST(UnitMassDensity, Standard) {
  EXPECT_EQ(Standard<MassDensity>, MassDensity::KilogramPerCubicMetre);
}

TEST(UnitMassDensity, StaticConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestStaticConvertCopy<MassDensity, MassDensity::KilogramPerCubicMetre,
                                  MassDensity::SlugPerCubicFoot>(
      value, value * std::pow(0.3048L, 4) / (0.45359237L * 9.80665L));
}

TEST(UnitMassDensity, Stream) {
  std::ostringstream stream;
  stream << MassDensity::KilogramPerCubicMetre;
  EXPECT_EQ(stream.str(), Abbreviation(MassDensity::KilogramPerCubicMetre));
}

}  // namespace

}  // namespace PhQ::Unit
