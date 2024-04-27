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

#include "../../include/PhQ/Unit/Mass.hpp"

#include <array>
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

constexpr std::array<Mass, 5> Units = {
    Mass::Kilogram, Mass::Gram, Mass::Slug, Mass::Slinch, Mass::Pound,
};

TEST(UnitMass, Abbreviation) {
  EXPECT_EQ(Abbreviation(Mass::Kilogram), "kg");
  EXPECT_EQ(Abbreviation(Mass::Gram), "g");
  EXPECT_EQ(Abbreviation(Mass::Slug), "slug");
  EXPECT_EQ(Abbreviation(Mass::Slinch), "slinch");
  EXPECT_EQ(Abbreviation(Mass::Pound), "lbm");
}

TEST(UnitMass, ConsistentUnit) {
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::MetreKilogramSecondKelvin), Mass::Kilogram);
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::MillimetreGramSecondKelvin), Mass::Gram);
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::FootPoundSecondRankine), Mass::Slug);
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::InchPoundSecondRankine), Mass::Slinch);
}

TEST(UnitMass, ConversionReciprocity) {
  constexpr double original_value{1.234567890123456789};
  for (const Mass original_unit : Units) {
    for (const Mass intermediary_unit : Units) {
      Internal::TestConversionReciprocity(original_unit, intermediary_unit, original_value);
    }
  }
}

TEST(UnitMass, ConvertFromStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(Mass::Kilogram, Mass::Kilogram, value, value);
  Internal::TestConversions(Mass::Kilogram, Mass::Gram, value, value * 1000.0);
  Internal::TestConversions(
      Mass::Kilogram, Mass::Slug, value, value * 0.3048 / (0.45359237 * 9.80665));
  Internal::TestConversions(
      Mass::Kilogram, Mass::Slinch, value, value * 0.0254 / (0.45359237 * 9.80665));
  Internal::TestConversions(Mass::Kilogram, Mass::Pound, value, value / 0.45359237);

  Internal::TestStaticConversions<Mass, Mass::Kilogram, Mass::Slug>(
      value, value * 0.3048 / (0.45359237 * 9.80665));
}

TEST(UnitMass, ConvertToStandard) {
  constexpr double value{1.234567890123456789};

  Internal::TestConversions(Mass::Kilogram, Mass::Kilogram, value, value);
  Internal::TestConversions(Mass::Gram, Mass::Kilogram, value, value * 0.001);
  Internal::TestConversions(
      Mass::Slug, Mass::Kilogram, value, value * 0.45359237 * 9.80665 / 0.3048);
  Internal::TestConversions(
      Mass::Slinch, Mass::Kilogram, value, value * 0.45359237 * 9.80665 / 0.0254);
  Internal::TestConversions(Mass::Pound, Mass::Kilogram, value, value * 0.45359237);

  Internal::TestStaticConversions<Mass, Mass::Slug, Mass::Kilogram>(
      value, value * 0.45359237 * 9.80665 / 0.3048);
}

TEST(UnitMass, Parse) {
  EXPECT_EQ(Parse<Mass>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Mass>("kg"), Mass::Kilogram);
  EXPECT_EQ(Parse<Mass>("g"), Mass::Gram);
  EXPECT_EQ(Parse<Mass>("slug"), Mass::Slug);
  EXPECT_EQ(Parse<Mass>("slinch"), Mass::Slinch);
  EXPECT_EQ(Parse<Mass>("lbm"), Mass::Pound);
}

TEST(UnitMass, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<Mass>,
            Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{1}));
}

TEST(UnitMass, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Mass::Kilogram), UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Mass::Gram), UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Mass::Slug), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Mass::Slinch), UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Mass::Pound), std::nullopt);
}

TEST(UnitMass, Standard) {
  EXPECT_EQ(Standard<Mass>, Mass::Kilogram);
}

TEST(UnitMass, Stream) {
  std::ostringstream stream;
  stream << Mass::Kilogram;
  EXPECT_EQ(stream.str(), Abbreviation(Mass::Kilogram));
}

}  // namespace

}  // namespace PhQ::Unit
