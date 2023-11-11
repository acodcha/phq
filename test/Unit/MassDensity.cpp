// Copyright 2020-2023 Alexandre Coderre-Chabot
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

TEST(UnitMassDensity, ConvertFromStandard) {
  constexpr double value{10.0};

  Internal::TestConversions(
      MassDensity::KilogramPerCubicMetre, MassDensity::KilogramPerCubicMetre, value, value);
  Internal::TestConversions(MassDensity::KilogramPerCubicMetre, MassDensity::GramPerCubicMillimetre,
                            value, value * 0.000001);
  Internal::TestConversions(MassDensity::KilogramPerCubicMetre, MassDensity::SlugPerCubicFoot,
                            value, value * std::pow(0.3048, 4) / (0.45359237 * 9.80665));
  Internal::TestConversions(MassDensity::KilogramPerCubicMetre, MassDensity::SlinchPerCubicInch,
                            value, value * std::pow(0.0254, 4) / (0.45359237 * 9.80665));
  Internal::TestConversions(MassDensity::KilogramPerCubicMetre, MassDensity::PoundPerCubicFoot,
                            value, value * std::pow(0.3048, 3) / 0.45359237);
  Internal::TestConversions(MassDensity::KilogramPerCubicMetre, MassDensity::PoundPerCubicInch,
                            value, value * std::pow(0.0254, 3) / 0.45359237);

  Internal::TestStaticConversions<MassDensity, MassDensity::KilogramPerCubicMetre,
                                  MassDensity::SlugPerCubicFoot>(
      value, value * std::pow(0.3048, 4) / (0.45359237 * 9.80665));
}

TEST(UnitMassDensity, ConvertToStandard) {
  constexpr double value{10.0};

  Internal::TestConversions(
      MassDensity::KilogramPerCubicMetre, MassDensity::KilogramPerCubicMetre, value, value);
  Internal::TestConversions(MassDensity::GramPerCubicMillimetre, MassDensity::KilogramPerCubicMetre,
                            value, value * 1000000.0);
  Internal::TestConversions(MassDensity::SlugPerCubicFoot, MassDensity::KilogramPerCubicMetre,
                            value, value * 0.45359237 * 9.80665 / std::pow(0.3048, 4));
  Internal::TestConversions(MassDensity::SlinchPerCubicInch, MassDensity::KilogramPerCubicMetre,
                            value, value * 0.45359237 * 9.80665 / std::pow(0.0254, 4));
  Internal::TestConversions(MassDensity::PoundPerCubicFoot, MassDensity::KilogramPerCubicMetre,
                            value, value * 0.45359237 / std::pow(0.3048, 3));
  Internal::TestConversions(MassDensity::PoundPerCubicInch, MassDensity::KilogramPerCubicMetre,
                            value, value * 0.45359237 / std::pow(0.0254, 3));

  Internal::TestStaticConversions<MassDensity, MassDensity::SlugPerCubicFoot,
                                  MassDensity::KilogramPerCubicMetre>(
      value, value * 0.45359237 * 9.80665 / std::pow(0.3048, 4));
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

TEST(UnitMassDensity, Stream) {
  std::ostringstream stream;
  stream << MassDensity::KilogramPerCubicMetre;
  EXPECT_EQ(stream.str(), Abbreviation(MassDensity::KilogramPerCubicMetre));
}

}  // namespace

}  // namespace PhQ::Unit
