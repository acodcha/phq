// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
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

TEST(UnitSubstanceAmount, ConvertAndConvertCopy) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvert<SubstanceAmount>(
      SubstanceAmount::Mole, SubstanceAmount::Mole, value, value);
  Internal::TestConvert<SubstanceAmount>(
      SubstanceAmount::Mole, SubstanceAmount::Kilomole, value, value * 0.001L);
  Internal::TestConvert<SubstanceAmount>(
      SubstanceAmount::Mole, SubstanceAmount::Megamole, value, value * 0.000001L);
  Internal::TestConvert<SubstanceAmount>(
      SubstanceAmount::Mole, SubstanceAmount::Gigamole, value, value * 0.000000001L);
  Internal::TestConvert<SubstanceAmount>(
      SubstanceAmount::Mole, SubstanceAmount::Particles, value, value * 6.02214076E23L);
}

TEST(UnitSubstanceAmount, ConvertStatically) {
  constexpr long double value{1.234567890123456789L};
  Internal::TestConvertStatically<SubstanceAmount, SubstanceAmount::Mole,
                                  SubstanceAmount::Particles>(value, value * 6.02214076E23L);
}

TEST(UnitSubstanceAmount, ParseEnumeration) {
  EXPECT_EQ(ParseEnumeration<SubstanceAmount>("Hello world!"), std::nullopt);
  EXPECT_EQ(ParseEnumeration<SubstanceAmount>("mol"), SubstanceAmount::Mole);
  EXPECT_EQ(ParseEnumeration<SubstanceAmount>("kmol"), SubstanceAmount::Kilomole);
  EXPECT_EQ(ParseEnumeration<SubstanceAmount>("Mmol"), SubstanceAmount::Megamole);
  EXPECT_EQ(ParseEnumeration<SubstanceAmount>("Gmol"), SubstanceAmount::Gigamole);
  EXPECT_EQ(ParseEnumeration<SubstanceAmount>("particles"), SubstanceAmount::Particles);
}

TEST(UnitSubstanceAmount, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<SubstanceAmount>,
            Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
                       Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                       Dimension::SubstanceAmount{1}, Dimension::LuminousIntensity{0}));
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
