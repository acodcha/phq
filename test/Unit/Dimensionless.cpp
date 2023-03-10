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

#include "../../include/PhQ/Unit/Dimensionless.hpp"

#include <gtest/gtest.h>

namespace PhQ::Unit {

namespace {

constexpr std::array<Dimensionless, 1> Units = {
    Dimensionless::Dimensionless,
};

TEST(UnitFrequency, Abbreviation) {
  EXPECT_EQ(Abbreviation(Dimensionless::Dimensionless), "");
}

TEST(UnitFrequency, ConsistentUnit) {
  EXPECT_EQ(
      ConsistentUnit<Dimensionless>(UnitSystem::MetreKilogramSecondKelvin),
      Dimensionless::Dimensionless);
  EXPECT_EQ(
      ConsistentUnit<Dimensionless>(UnitSystem::MillimetreGramSecondKelvin),
      Dimensionless::Dimensionless);
  EXPECT_EQ(ConsistentUnit<Dimensionless>(UnitSystem::FootPoundSecondRankine),
            Dimensionless::Dimensionless);
  EXPECT_EQ(ConsistentUnit<Dimensionless>(UnitSystem::InchPoundSecondRankine),
            Dimensionless::Dimensionless);
}

TEST(UnitFrequency, ConvertFromStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Dimensionless::Dimensionless,
                               Dimensionless::Dimensionless),
                   value);
}

TEST(UnitFrequency, ConvertToStandard) {
  constexpr double value{10.0};
  EXPECT_DOUBLE_EQ(ConvertCopy(value, Dimensionless::Dimensionless,
                               Dimensionless::Dimensionless),
                   value);
}

TEST(UnitFrequency, ConvertVerification) {
  double value{10.0};
  std::array<double, 3> array{10.0, -20.0, 30.0};
  std::vector<double> std_vector{10.0, -20.0, 30.0, -40.0};
  Value::Vector value_vector{10.0, -20.0, 30.0};
  Value::SymmetricDyad symdyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0};
  Value::Dyad dyad{10.0, -20.0, 30.0, -40.0, 50.0, -60.0, 70.0, -80.0, 90.0};
  for (const Dimensionless old_unit : Units) {
    for (const Dimensionless new_unit : Units) {
      Convert(value, old_unit, new_unit);
      Convert(array, old_unit, new_unit);
      Convert(std_vector, old_unit, new_unit);
      Convert(value_vector, old_unit, new_unit);
      Convert(symdyad, old_unit, new_unit);
      Convert(dyad, old_unit, new_unit);
    }
  }
}

TEST(UnitFrequency, DimensionSet) {
  EXPECT_EQ(Dimensions<Dimensionless>, Dimension::Set());
}

TEST(UnitFrequency, Parse) {
  EXPECT_EQ(Parse<Dimensionless>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<Dimensionless>(""), Dimensionless::Dimensionless);
}

TEST(UnitFrequency, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(Dimensionless::Dimensionless), std::nullopt);
}

TEST(UnitFrequency, StandardUnit) {
  EXPECT_EQ(StandardUnit<Dimensionless>, Dimensionless::Dimensionless);
}

}  // namespace

}  // namespace PhQ::Unit
