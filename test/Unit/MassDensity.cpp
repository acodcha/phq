// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

TEST(UnitMassDensity, Convert) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::KilogramPerCubicMetre, value, value);
  Internal::TestConvert<MassDensity>(MassDensity::KilogramPerCubicMetre,
                                     MassDensity::GramPerCubicMillimetre, value, value * 0.000001L);
  Internal::TestConvert<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::SlugPerCubicFoot, value,
      value * std::pow(0.3048L, 4) / (0.45359237L * 9.80665L));
  Internal::TestConvert<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::SlinchPerCubicInch, value,
      value * std::pow(0.0254L, 4) / (0.45359237L * 9.80665L));
  Internal::TestConvert<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::PoundPerCubicFoot, value,
      value * std::pow(0.3048L, 3) / 0.45359237L);
  Internal::TestConvert<MassDensity>(
      MassDensity::KilogramPerCubicMetre, MassDensity::PoundPerCubicInch, value,
      value * std::pow(0.0254L, 3) / 0.45359237L);
}

TEST(UnitMassDensity, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<MassDensity, MassDensity::KilogramPerCubicMetre,
                                  MassDensity::SlugPerCubicFoot>(
      value, value * std::pow(0.3048L, 4) / (0.45359237L * 9.80665L));
}

TEST(UnitMassDensity, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<MassDensity>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<MassDensity>("kg/m^3"), MassDensity::KilogramPerCubicMetre);
  EXPECT_EQ(ParseEnumeration<MassDensity>("g/mm^3"), MassDensity::GramPerCubicMillimetre);
  EXPECT_EQ(ParseEnumeration<MassDensity>("slug/ft^3"), MassDensity::SlugPerCubicFoot);
  EXPECT_EQ(ParseEnumeration<MassDensity>("slinch/in^3"), MassDensity::SlinchPerCubicInch);
  EXPECT_EQ(ParseEnumeration<MassDensity>("lbm/ft^3"), MassDensity::PoundPerCubicFoot);
  EXPECT_EQ(ParseEnumeration<MassDensity>("lbm/in^3"), MassDensity::PoundPerCubicInch);
}

TEST(UnitMassDensity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<MassDensity>,
            Dimensions(Dimension::Time{0}, Dimension::Length{-3}, Dimension::Mass{1},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{0}));
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
