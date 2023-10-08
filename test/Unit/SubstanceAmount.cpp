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

#include "../../include/PhQ/Unit/SubstanceAmount.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<SubstanceAmount, 5> Units = {
    SubstanceAmount::Mole,      SubstanceAmount::Kilomole,
    SubstanceAmount::Megamole,  SubstanceAmount::Gigamole,
    SubstanceAmount::Particles,
};

TEST(UnitSubstanceAmount, Abbreviation) {
  EXPECT_EQ(Abbreviation(SubstanceAmount::Mole), "mol");
  EXPECT_EQ(Abbreviation(SubstanceAmount::Kilomole), "kmol");
  EXPECT_EQ(Abbreviation(SubstanceAmount::Megamole), "Mmol");
  EXPECT_EQ(Abbreviation(SubstanceAmount::Gigamole), "Gmol");
  EXPECT_EQ(Abbreviation(SubstanceAmount::Particles), "particles");
}

TEST(UnitSubstanceAmount, ConsistentUnit) {
  EXPECT_EQ(
      ConsistentUnit<SubstanceAmount>(UnitSystem::MetreKilogramSecondKelvin),
      SubstanceAmount::Mole);
  EXPECT_EQ(
      ConsistentUnit<SubstanceAmount>(UnitSystem::MillimetreGramSecondKelvin),
      SubstanceAmount::Mole);
  EXPECT_EQ(ConsistentUnit<SubstanceAmount>(UnitSystem::FootPoundSecondRankine),
            SubstanceAmount::Mole);
  EXPECT_EQ(ConsistentUnit<SubstanceAmount>(UnitSystem::InchPoundSecondRankine),
            SubstanceAmount::Mole);
}

TEST(UnitSubstanceAmount, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Mole, SubstanceAmount::Mole), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Mole, SubstanceAmount::Kilomole),
      value * 0.001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Mole, SubstanceAmount::Megamole),
      value * 0.000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Mole, SubstanceAmount::Gigamole),
      value * 0.000000001);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Mole, SubstanceAmount::Particles),
      value * 6.02214076e23);
}

TEST(UnitSubstanceAmount, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Mole, SubstanceAmount::Mole), value);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Kilomole, SubstanceAmount::Mole),
      value * 1000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Megamole, SubstanceAmount::Mole),
      value * 1000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Gigamole, SubstanceAmount::Mole),
      value * 1000000000.0);
  EXPECT_DOUBLE_EQ(
      ConvertCopy(value, SubstanceAmount::Particles, SubstanceAmount::Mole),
      value / 6.02214076e23);
}

TEST(UnitSubstanceAmount, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const SubstanceAmount old_unit : Units) {
    for (const SubstanceAmount new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
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
  EXPECT_EQ(
      RelatedDimensions<SubstanceAmount>,
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
