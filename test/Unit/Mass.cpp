// Copyright 2020 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Unit/Mass.hpp"

#include <gtest/gtest.h>

#include "Base.hpp"

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
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::MetreKilogramSecondKelvin),
            Mass::Kilogram);
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::MillimetreGramSecondKelvin),
            Mass::Gram);
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::FootPoundSecondRankine),
            Mass::Slug);
  EXPECT_EQ(ConsistentUnit<Mass>(UnitSystem::InchPoundSecondRankine),
            Mass::Slinch);
}

TEST(UnitMass, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Kilogram, Mass::Kilogram), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Kilogram, Mass::Gram),
                   value * 1000.0);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Kilogram, Mass::Slug),
                   value * 0.3048 / (0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Kilogram, Mass::Slinch),
                   value * 0.0254 / (0.45359237 * 9.80665));
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Kilogram, Mass::Pound),
                   value / 0.45359237);
}

TEST(UnitMass, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Kilogram, Mass::Kilogram), value);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Gram, Mass::Kilogram),
                   value * 0.001);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Slug, Mass::Kilogram),
                   value * 0.45359237 * 9.80665 / 0.3048);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Slinch, Mass::Kilogram),
                   value * 0.45359237 * 9.80665 / 0.0254);
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Mass::Pound, Mass::Kilogram),
                   value * 0.45359237);
}

TEST(UnitMass, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Mass old_unit : Units) {
    for (const Mass new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitMass, DimensionSet) {
  EXPECT_EQ(Dimensions<Mass>,
            Dimension::Set(Dimension::Time{0}, Dimension::Length{0},
                           Dimension::Mass{1}));
}

TEST(UnitMass, Parse) {
  EXPECT_EQ(Parse<Mass>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Mass>("kg"), Mass::Kilogram);
  EXPECT_EQ(Parse<Mass>("g"), Mass::Gram);
  EXPECT_EQ(Parse<Mass>("slug"), Mass::Slug);
  EXPECT_EQ(Parse<Mass>("slinch"), Mass::Slinch);
  EXPECT_EQ(Parse<Mass>("lbm"), Mass::Pound);
}

TEST(UnitMass, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Mass::Kilogram),
            UnitSystem::MetreKilogramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Mass::Gram),
            UnitSystem::MillimetreGramSecondKelvin);
  EXPECT_EQ(RelatedUnitSystem(Mass::Slug), UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Mass::Slinch),
            UnitSystem::InchPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(Mass::Pound), std::nullopt);
}

TEST(UnitMass, StandardUnit) { EXPECT_EQ(StandardUnit<Mass>, Mass::Kilogram); }

}  // namespace

}  // namespace PhQ::Unit
