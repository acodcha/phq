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
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificEnergy::JoulePerKilogram,
                               SpecificEnergy::JoulePerKilogram),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificEnergy::JoulePerKilogram,
                               SpecificEnergy::NanojoulePerGram),
                   value * 1000000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificEnergy::JoulePerKilogram,
                               SpecificEnergy::FootPoundPerSlug),
                   value / std::pow(0.3048, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificEnergy::JoulePerKilogram,
                               SpecificEnergy::InchPoundPerSlinch),
                   value / std::pow(0.0254, 2));
}

TEST(UnitSpecificEnergy, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificEnergy::JoulePerKilogram,
                               SpecificEnergy::JoulePerKilogram),
                   value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificEnergy::NanojoulePerGram,
                               SpecificEnergy::JoulePerKilogram),
                   value * 0.000001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificEnergy::FootPoundPerSlug,
                               SpecificEnergy::JoulePerKilogram),
                   value * std::pow(0.3048, 2));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, SpecificEnergy::InchPoundPerSlinch,
                               SpecificEnergy::JoulePerKilogram),
                   value * std::pow(0.0254, 2));
}

TEST(UnitSpecificEnergy, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const SpecificEnergy old_unit : Units) {
    for (const SpecificEnergy new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitSpecificEnergy, DimensionSet) {
  EXPECT_EQ(Dimensions<SpecificEnergy>,
            Dimension::Set(Dimension::Time{-2}, Dimension::Length{2}));
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

}  // namespace

}  // namespace PhQ::Unit
