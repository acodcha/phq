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

#include "../../include/PhQ/Unit/SubstanceAmount.hpp"

#include <array>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Dimension/ElectricCurrent.hpp"
#include "../../include/PhQ/Dimension/Length.hpp"
#include "../../include/PhQ/Dimension/Mass.hpp"
#include "../../include/PhQ/Dimension/SubstanceAmount.hpp"
#include "../../include/PhQ/Dimension/Temperature.hpp"
#include "../../include/PhQ/Dimension/Time.hpp"
#include "../../include/PhQ/Dimensions.hpp"
#include "../../include/PhQ/UnitSystem.hpp"
#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<SubstanceAmount, 5> Units = {
    SubstanceAmount::Mole,     SubstanceAmount::Kilomole,  SubstanceAmount::Megamole,
    SubstanceAmount::Gigamole, SubstanceAmount::Particles,
};

TEST(UnitSubstanceAmount, Abbreviation) {
  EXPECT_EQ(Abbreviation(SubstanceAmount::Mole), "mol");
  EXPECT_EQ(Abbreviation(SubstanceAmount::Kilomole), "kmol");
  EXPECT_EQ(Abbreviation(SubstanceAmount::Megamole), "Mmol");
  EXPECT_EQ(Abbreviation(SubstanceAmount::Gigamole), "Gmol");
  EXPECT_EQ(Abbreviation(SubstanceAmount::Particles), "particles");
}

TEST(UnitSubstanceAmount, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<SubstanceAmount>(UnitSystem::MetreKilogramSecondKelvin),
            SubstanceAmount::Mole);
  EXPECT_EQ(ConsistentUnit<SubstanceAmount>(UnitSystem::MillimetreGramSecondKelvin),
            SubstanceAmount::Mole);
  EXPECT_EQ(
      ConsistentUnit<SubstanceAmount>(UnitSystem::FootPoundSecondRankine), SubstanceAmount::Mole);
  EXPECT_EQ(
      ConsistentUnit<SubstanceAmount>(UnitSystem::InchPoundSecondRankine), SubstanceAmount::Mole);
}

TEST(UnitSubstanceAmount, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const SubstanceAmount original_unit : Units) {
    for (const SubstanceAmount intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitSubstanceAmount, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(SubstanceAmount::Mole, SubstanceAmount::Mole, value, value);
  Internal::TestConversions(SubstanceAmount::Mole, SubstanceAmount::Kilomole, value, value * 0.001);
  Internal::TestConversions(
      SubstanceAmount::Mole, SubstanceAmount::Megamole, value, value * 0.000001);
  Internal::TestConversions(
      SubstanceAmount::Mole, SubstanceAmount::Gigamole, value, value * 0.000000001);
  Internal::TestConversions(
      SubstanceAmount::Mole, SubstanceAmount::Particles, value, value * 6.02214076e23);

  Internal::TestStaticConversions<SubstanceAmount, SubstanceAmount::Mole,
                                  SubstanceAmount::Particles>(value, value * 6.02214076e23);
}

TEST(UnitSubstanceAmount, ConvertToStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(SubstanceAmount::Mole, SubstanceAmount::Mole, value, value);
  Internal::TestConversions(
      SubstanceAmount::Kilomole, SubstanceAmount::Mole, value, value * 1000.0);
  Internal::TestConversions(
      SubstanceAmount::Megamole, SubstanceAmount::Mole, value, value * 1000000.0);
  Internal::TestConversions(
      SubstanceAmount::Gigamole, SubstanceAmount::Mole, value, value * 1000000000.0);
  Internal::TestConversions(
      SubstanceAmount::Particles, SubstanceAmount::Mole, value, value / 6.02214076e23);

  Internal::TestStaticConversions<SubstanceAmount, SubstanceAmount::Particles,
                                  SubstanceAmount::Mole>(value, value / 6.02214076e23);
}

TEST(UnitSubstanceAmount, Parse) {
  EXPECT_EQ(Parse<SubstanceAmount>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<SubstanceAmount>("mol"), SubstanceAmount::Mole);
  EXPECT_EQ(Parse<SubstanceAmount>("kmol"), SubstanceAmount::Kilomole);
  EXPECT_EQ(Parse<SubstanceAmount>("Mmol"), SubstanceAmount::Megamole);
  EXPECT_EQ(Parse<SubstanceAmount>("Gmol"), SubstanceAmount::Gigamole);
  EXPECT_EQ(Parse<SubstanceAmount>("particles"), SubstanceAmount::Particles);
}

TEST(UnitSubstanceAmount, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<SubstanceAmount>,
            Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{1}));
}

TEST(UnitSubstanceAmount, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(SubstanceAmount::Mole), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(SubstanceAmount::Kilomole), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(SubstanceAmount::Megamole), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(SubstanceAmount::Gigamole), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(SubstanceAmount::Particles), std::nullopt);
}

TEST(UnitSubstanceAmount, Standard) {
  EXPECT_EQ(Standard<SubstanceAmount>, SubstanceAmount::Mole);
}

TEST(UnitSubstanceAmount, Stream) {
  std::ostringstream stream;
  stream << SubstanceAmount::Mole;
  EXPECT_EQ(stream.str(), Abbreviation(SubstanceAmount::Mole));
}

}  // namespace

}  // namespace PhQ::Unit
