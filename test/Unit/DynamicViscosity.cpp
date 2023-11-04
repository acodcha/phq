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

#include "../../include/PhQ/Unit/DynamicViscosity.hpp"

#include <gtest/gtest.h>

#include "../Unit.hpp"

namespace PhQ::Unit {

namespace {

constexpr std::array<DynamicViscosity, 7> Units = {
    DynamicViscosity::PascalSecond,
    DynamicViscosity::KilopascalSecond,
    DynamicViscosity::MegapascalSecond,
    DynamicViscosity::GigapascalSecond,
    DynamicViscosity::Poise,
    DynamicViscosity::PoundSecondPerSquareFoot,
    DynamicViscosity::PoundSecondPerSquareInch,
};

TEST(UnitDynamicViscosity, Abbreviation) {
  EXPECT_EQ(Abbreviation(DynamicViscosity::PascalSecond), "Pa·s");
  EXPECT_EQ(Abbreviation(DynamicViscosity::KilopascalSecond), "kPa·s");
  EXPECT_EQ(Abbreviation(DynamicViscosity::MegapascalSecond), "MPa·s");
  EXPECT_EQ(Abbreviation(DynamicViscosity::GigapascalSecond), "GPa·s");
  EXPECT_EQ(Abbreviation(DynamicViscosity::Poise), "P");
  EXPECT_EQ(
      Abbreviation(DynamicViscosity::PoundSecondPerSquareFoot), "lbf·s/ft^2");
  EXPECT_EQ(
      Abbreviation(DynamicViscosity::PoundSecondPerSquareInch), "lbf·s/in^2");
}

TEST(UnitDynamicViscosity, ConsistentUnit) {
  EXPECT_EQ(
      ConsistentUnit<DynamicViscosity>(UnitSystem::MetreKilogramSecondKelvin),
      DynamicViscosity::PascalSecond);
  EXPECT_EQ(
      ConsistentUnit<DynamicViscosity>(UnitSystem::MillimetreGramSecondKelvin),
      DynamicViscosity::PascalSecond);
  EXPECT_EQ(
      ConsistentUnit<DynamicViscosity>(UnitSystem::FootPoundSecondRankine),
      DynamicViscosity::PoundSecondPerSquareFoot);
  EXPECT_EQ(
      ConsistentUnit<DynamicViscosity>(UnitSystem::InchPoundSecondRankine),
      DynamicViscosity::PoundSecondPerSquareInch);
}

TEST(UnitDynamicViscosity, ConvertFromStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<DynamicViscosity,
                                DynamicViscosity::PascalSecond,
                                DynamicViscosity::PascalSecond>(value, value);
  Internal::TestUnitConversions<
      DynamicViscosity, DynamicViscosity::PascalSecond,
      DynamicViscosity::KilopascalSecond>(value, value * 0.001);
  Internal::TestUnitConversions<
      DynamicViscosity, DynamicViscosity::PascalSecond,
      DynamicViscosity::MegapascalSecond>(value, value * 0.000001);
  Internal::TestUnitConversions<
      DynamicViscosity, DynamicViscosity::PascalSecond,
      DynamicViscosity::GigapascalSecond>(value, value * 0.000000001);
  Internal::TestUnitConversions<DynamicViscosity,
                                DynamicViscosity::PascalSecond,
                                DynamicViscosity::Poise>(value, value * 10.0);
  Internal::TestUnitConversions<DynamicViscosity,
                                DynamicViscosity::PascalSecond,
                                DynamicViscosity::PoundSecondPerSquareFoot>(
      value, value * std::pow(0.3048, 2) / (0.45359237 * 9.80665));
  Internal::TestUnitConversions<DynamicViscosity,
                                DynamicViscosity::PascalSecond,
                                DynamicViscosity::PoundSecondPerSquareInch>(
      value, value * std::pow(0.0254, 2) / (0.45359237 * 9.80665));
}

TEST(UnitDynamicViscosity, ConvertToStandard) {
  constexpr double value{10.0};
  Internal::TestUnitConversions<DynamicViscosity,
                                DynamicViscosity::PascalSecond,
                                DynamicViscosity::PascalSecond>(value, value);
  Internal::TestUnitConversions<
      DynamicViscosity, DynamicViscosity::KilopascalSecond,
      DynamicViscosity::PascalSecond>(value, value * 1000.0);
  Internal::TestUnitConversions<
      DynamicViscosity, DynamicViscosity::MegapascalSecond,
      DynamicViscosity::PascalSecond>(value, value * 1000000.0);
  Internal::TestUnitConversions<
      DynamicViscosity, DynamicViscosity::GigapascalSecond,
      DynamicViscosity::PascalSecond>(value, value * 1000000000.0);
  Internal::TestUnitConversions<DynamicViscosity, DynamicViscosity::Poise,
                                DynamicViscosity::PascalSecond>(
      value, value * 0.1);
  Internal::TestUnitConversions<DynamicViscosity,
                                DynamicViscosity::PoundSecondPerSquareFoot,
                                DynamicViscosity::PascalSecond>(
      value, value * 0.45359237 * 9.80665 / std::pow(0.3048, 2));
  Internal::TestUnitConversions<DynamicViscosity,
                                DynamicViscosity::PoundSecondPerSquareInch,
                                DynamicViscosity::PascalSecond>(
      value, value * 0.45359237 * 9.80665 / std::pow(0.0254, 2));
}

TEST(UnitDynamicViscosity, Parse) {
  EXPECT_EQ(Parse<DynamicViscosity>("Hello world!"), std::nullopt);
  EXPECT_EQ(Parse<DynamicViscosity>("Pa·s"), DynamicViscosity::PascalSecond);
  EXPECT_EQ(
      Parse<DynamicViscosity>("kPa·s"), DynamicViscosity::KilopascalSecond);
  EXPECT_EQ(
      Parse<DynamicViscosity>("MPa·s"), DynamicViscosity::MegapascalSecond);
  EXPECT_EQ(
      Parse<DynamicViscosity>("GPa·s"), DynamicViscosity::GigapascalSecond);
  EXPECT_EQ(Parse<DynamicViscosity>("P"), DynamicViscosity::Poise);
  EXPECT_EQ(Parse<DynamicViscosity>("lbf·s/ft^2"),
            DynamicViscosity::PoundSecondPerSquareFoot);
  EXPECT_EQ(Parse<DynamicViscosity>("lbf·s/in^2"),
            DynamicViscosity::PoundSecondPerSquareInch);
}

TEST(UnitDynamicViscosity, RelatedDimensions) {
  EXPECT_EQ(RelatedDimensions<DynamicViscosity>,
            Dimensions(Dimension::Time{-1}, Dimension::Length{-1},
                       Dimension::Mass{1}));
}

TEST(UnitDynamicViscosity, RelatedUnitSystem) {
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::PascalSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(DynamicViscosity::KilopascalSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(DynamicViscosity::MegapascalSecond), std::nullopt);
  EXPECT_EQ(
      RelatedUnitSystem(DynamicViscosity::GigapascalSecond), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::Poise), std::nullopt);
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::PoundSecondPerSquareFoot),
            UnitSystem::FootPoundSecondRankine);
  EXPECT_EQ(RelatedUnitSystem(DynamicViscosity::PoundSecondPerSquareInch),
            UnitSystem::InchPoundSecondRankine);
}

TEST(UnitDynamicViscosity, Standard) {
  EXPECT_EQ(Standard<DynamicViscosity>, DynamicViscosity::PascalSecond);
}

TEST(UnitDynamicViscosity, Stream) {
  std::ostringstream stream;
  stream << DynamicViscosity::PascalSecond;
  EXPECT_EQ(stream.str(), Abbreviation(DynamicViscosity::PascalSecond));
}

}  // namespace

}  // namespace PhQ::Unit
