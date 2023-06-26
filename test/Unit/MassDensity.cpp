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

#include "../../include/PhQ/Unit/MassDensity.hpp"

#include <gtest/gtest.h>

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
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::KilogramPerCubicMetre,
                               MassDensity::KilogramPerCubicMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::KilogramPerCubicMetre,
                               MassDensity::GramPerCubicMillimetre),
                   value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::KilogramPerCubicMetre,
                               MassDensity::SlugPerCubicFoot),
                   value * std::pow(0.3048, 4) / (0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::KilogramPerCubicMetre,
                               MassDensity::SlinchPerCubicInch),
                   value * std::pow(0.0254, 4) / (0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::KilogramPerCubicMetre,
                               MassDensity::PoundPerCubicFoot),
                   value * std::pow(0.3048, 3) / 0.45359237);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::KilogramPerCubicMetre,
                               MassDensity::PoundPerCubicInch),
                   value * std::pow(0.0254, 3) / 0.45359237);
}

TEST(UnitMassDensity, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::KilogramPerCubicMetre,
                               MassDensity::KilogramPerCubicMetre),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::GramPerCubicMillimetre,
                               MassDensity::KilogramPerCubicMetre),
                   value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::SlugPerCubicFoot,
                               MassDensity::KilogramPerCubicMetre),
                   value * 0.45359237 * 9.80665 / std::pow(0.3048, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::SlinchPerCubicInch,
                               MassDensity::KilogramPerCubicMetre),
                   value * 0.45359237 * 9.80665 / std::pow(0.0254, 4));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::PoundPerCubicFoot,
                               MassDensity::KilogramPerCubicMetre),
                   value * 0.45359237 / std::pow(0.3048, 3));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, MassDensity::PoundPerCubicInch,
                               MassDensity::KilogramPerCubicMetre),
                   value * 0.45359237 / std::pow(0.0254, 3));
}

TEST(UnitMassDensity, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const MassDensity old_unit : Units) {
    for (const MassDensity new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitMassDensity, DimensionSet) {
  EXPECT_EQ(Dimensions<MassDensity>,
            Dimension::Set(
                Dimension::Time{}, Dimension::Length{-3}, Dimension::Mass{1}));
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

TEST(UnitMassDensity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(MassDensity::KilogramPerCubicMetre),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::GramPerCubicMillimetre),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::SlugPerCubicFoot),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::SlinchPerCubicInch),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::PoundPerCubicFoot), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(MassDensity::PoundPerCubicInch), std::nullopt);
}

TEST(UnitMassDensity, StandardUnit) {
  EXPECT_EQ(StandardUnit<MassDensity>, MassDensity::KilogramPerCubicMetre);
}

}  // namespace

}  // namespace PhQ::Unit
