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

#include "../../include/PhQ/Unit/SpecificEnergy.hpp"

#include <gtest/gtest.h>

#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<SpecificEnergy, 4> Units = {
    SpecificEnergy::JoulePerKilogram,
    SpecificEnergy::NanojoulePerGram,
    SpecificEnergy::FootPoundPerSlug,
    SpecificEnergy::InchPoundPerSlinch,
};

TEST(UnitSpecificEnergy, Abbreviation) {
  EXPECT_EQ(Abbreviation(SpecificEnergy::JoulePerKilogram), "J/kg");
  EXPECT_EQ(Abbreviation(SpecificEnergy::NanojoulePerGram), "nJ/g");
  EXPECT_EQ(Abbreviation(SpecificEnergy::FootPoundPerSlug), "ft·lbf/slug");
  EXPECT_EQ(Abbreviation(SpecificEnergy::InchPoundPerSlinch), "in·lbf/slinch");
}

TEST(UnitSpecificEnergy, ConsistentUnit) {
  EXPECT_EQ(
      ConsistentUnit<SpecificEnergy>(UnitSystem::MetreKilogramSecondKelvin),
      SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(
      ConsistentUnit<SpecificEnergy>(UnitSystem::MillimetreGramSecondKelvin),
      SpecificEnergy::NanojoulePerGram);
  EXPECT_EQ(ConsistentUnit<SpecificEnergy>(UnitSystem::FootPoundSecondRankine),
            SpecificEnergy::FootPoundPerSlug);
  EXPECT_EQ(ConsistentUnit<SpecificEnergy>(UnitSystem::InchPoundSecondRankine),
            SpecificEnergy::InchPoundPerSlinch);
}

TEST(UnitSpecificEnergy, ConvertFromStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<SpecificEnergy,
                                SpecificEnergy::JoulePerKilogram,
                                SpecificEnergy::JoulePerKilogram>(value, value);
  Internal::TestUnitConversions<
      SpecificEnergy, SpecificEnergy::JoulePerKilogram,
      SpecificEnergy::NanojoulePerGram>(value, value * 1000000.0);
  Internal::TestUnitConversions<
      SpecificEnergy, SpecificEnergy::JoulePerKilogram,
      SpecificEnergy::FootPoundPerSlug>(value, value / std::pow(0.3048, 2));
  Internal::TestUnitConversions<
      SpecificEnergy, SpecificEnergy::JoulePerKilogram,
      SpecificEnergy::InchPoundPerSlinch>(value, value / std::pow(0.0254, 2));
}

TEST(UnitSpecificEnergy, ConvertToStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<SpecificEnergy,
                                SpecificEnergy::JoulePerKilogram,
                                SpecificEnergy::JoulePerKilogram>(value, value);
  Internal::TestUnitConversions<
      SpecificEnergy, SpecificEnergy::NanojoulePerGram,
      SpecificEnergy::JoulePerKilogram>(value, value * 0.000001);
  Internal::TestUnitConversions<
      SpecificEnergy, SpecificEnergy::FootPoundPerSlug,
      SpecificEnergy::JoulePerKilogram>(value, value * std::pow(0.3048, 2));
  Internal::TestUnitConversions<
      SpecificEnergy, SpecificEnergy::InchPoundPerSlinch,
      SpecificEnergy::JoulePerKilogram>(value, value * std::pow(0.0254, 2));
}

TEST(UnitSpecificEnergy, Parse) {
  EXPECT_EQ(Parse<SpecificEnergy>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<SpecificEnergy>("J/kg"), SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(Parse<SpecificEnergy>("nJ/g"), SpecificEnergy::NanojoulePerGram);
  EXPECT_EQ(
      Parse<SpecificEnergy>("ft·lbf/slug"), SpecificEnergy::FootPoundPerSlug);
  EXPECT_EQ(Parse<SpecificEnergy>("in·lbf/slinch"),
            SpecificEnergy::InchPoundPerSlinch);
}

TEST(UnitSpecificEnergy, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<SpecificEnergy>,
            Dimensions(Dimension::Time{-2}, Dimension::Length{2}));
}

TEST(UnitSpecificEnergy, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(SpecificEnergy::JoulePerKilogram),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificEnergy::NanojoulePerGram),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(SpecificEnergy::FootPoundPerSlug),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(SpecificEnergy::InchPoundPerSlinch),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitSpecificEnergy, Standard) {
  EXPECT_EQ(Standard<SpecificEnergy>, SpecificEnergy::JoulePerKilogram);
}

TEST(UnitSpecificEnergy, Stream) {
  std::ostringstream stream;
  stream << SpecificEnergy::JoulePerKilogram;
  EXPECT_EQ(stream.str(), Abbreviation(SpecificEnergy::JoulePerKilogram));
}

}  // namespace

}  // namespace PhQ::Unit
