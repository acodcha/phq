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

#include "../include/PhQ/MassDensity.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(MassDensity, ArithmeticAddition) {
  EXPECT_EQ(MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre)
                + MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            MassDensity(3.0, Unit::MassDensity::KilogramPerCubicMetre));

  MassDensity quantity{1.0, Unit::MassDensity::KilogramPerCubicMetre};
  quantity += MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre);
  EXPECT_EQ(
      quantity, MassDensity(3.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, ArithmeticDivision) {
  EXPECT_EQ(MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre) / 2.0,
            MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre));

  EXPECT_EQ(MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre)
                / MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            4.0);

  EXPECT_EQ(
      Mass(8.0, Unit::Mass::Kilogram) / Volume(4.0, Unit::Volume::CubicMetre),
      MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));

  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram)
                / MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
            Volume(2.0, Unit::Volume::CubicMetre));

  MassDensity quantity{8.0, Unit::MassDensity::KilogramPerCubicMetre};
  quantity /= 2.0;
  EXPECT_EQ(
      quantity, MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, ArithmeticMultiplication) {
  EXPECT_EQ(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre) * 2.0,
            MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre));

  EXPECT_EQ(2.0 * MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
            MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre));

  EXPECT_EQ(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)
                * Volume(2.0, Unit::Volume::CubicMetre),
            Mass(8.0, Unit::Mass::Kilogram));

  EXPECT_EQ(Volume(4.0, Unit::Volume::CubicMetre)
                * MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            Mass(8.0, Unit::Mass::Kilogram));

  MassDensity quantity{4.0, Unit::MassDensity::KilogramPerCubicMetre};
  quantity *= 2.0;
  EXPECT_EQ(
      quantity, MassDensity(8.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, ArithmeticSubtraction) {
  EXPECT_EQ(MassDensity(3.0, Unit::MassDensity::KilogramPerCubicMetre)
                - MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre));

  MassDensity quantity{3.0, Unit::MassDensity::KilogramPerCubicMetre};
  quantity -= MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre);
  EXPECT_EQ(
      quantity, MassDensity(1.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, Comparisons) {
  const MassDensity first{0.1, Unit::MassDensity::KilogramPerCubicMetre};
  const MassDensity second{0.2, Unit::MassDensity::KilogramPerCubicMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(MassDensity, CopyAssignment) {
  const MassDensity first{1.11, Unit::MassDensity::KilogramPerCubicMetre};
  MassDensity second = MassDensity::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(MassDensity, CopyConstructor) {
  const MassDensity first{1.11, Unit::MassDensity::KilogramPerCubicMetre};
  const MassDensity second{first};
  EXPECT_EQ(second, first);
}

TEST(MassDensity, Create) {
  constexpr MassDensity quantity =
      MassDensity::Create<Unit::MassDensity::KilogramPerCubicMetre>(1.11);
  EXPECT_EQ(
      quantity, MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, DefaultConstructor) {
  EXPECT_NO_THROW(MassDensity{});
}

TEST(MassDensity, Dimensions) {
  EXPECT_EQ(MassDensity::Dimensions(), RelatedDimensions<Unit::MassDensity>);
}

TEST(MassDensity, Hash) {
  const MassDensity first{1.11, Unit::MassDensity::GramPerCubicMillimetre};
  const MassDensity second{1.110001, Unit::MassDensity::GramPerCubicMillimetre};
  const MassDensity third{-1.11, Unit::MassDensity::GramPerCubicMillimetre};
  const std::hash<MassDensity> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(MassDensity, JSON) {
  EXPECT_EQ(MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"kg/m^3\"}");
  EXPECT_EQ(MassDensity(-2.22, Unit::MassDensity::GramPerCubicMillimetre)
                .JSON(Unit::MassDensity::GramPerCubicMillimetre),
            "{\"value\":-2.220000000000000,\"unit\":\"g/mm^3\"}");
}

TEST(MassDensity, MiscellaneousConstructor) {
  EXPECT_EQ(MassDensity(Mass(8.0, Unit::Mass::Kilogram),
                        Volume(4.0, Unit::Volume::CubicMetre)),
            MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));

  EXPECT_EQ(Mass(MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                 Volume(2.0, Unit::Volume::CubicMetre)),
            Mass(8.0, Unit::Mass::Kilogram));

  EXPECT_EQ(Volume(Mass(8.0, Unit::Mass::Kilogram),
                   MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)),
            Volume(2.0, Unit::Volume::CubicMetre));
}

TEST(MassDensity, MoveAssignment) {
  MassDensity first{1.11, Unit::MassDensity::KilogramPerCubicMetre};
  MassDensity second = MassDensity::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, MoveConstructor) {
  MassDensity first{1.11, Unit::MassDensity::KilogramPerCubicMetre};
  MassDensity second{std::move(first)};
  EXPECT_EQ(
      second, MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(MassDensity, MutableValue) {
  MassDensity quantity{1.11, Unit::MassDensity::KilogramPerCubicMetre};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(MassDensity, Print) {
  EXPECT_EQ(MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).Print(),
            "1.110000000000000 kg/m^3");
  EXPECT_EQ(MassDensity(-2.22, Unit::MassDensity::GramPerCubicMillimetre)
                .Print(Unit::MassDensity::GramPerCubicMillimetre),
            "-2.220000000000000 g/mm^3");
}

TEST(MassDensity, SetValue) {
  MassDensity quantity{1.11, Unit::MassDensity::KilogramPerCubicMetre};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(MassDensity, SizeOf) {
  EXPECT_EQ(sizeof(MassDensity{}), sizeof(double));
}

TEST(MassDensity, StandardConstructor) {
  EXPECT_NO_THROW(MassDensity(1.11, Unit::MassDensity::GramPerCubicMillimetre));
}

TEST(MassDensity, StaticValue) {
  constexpr MassDensity quantity =
      MassDensity::Create<Unit::MassDensity::GramPerCubicMillimetre>(2.0);
  constexpr double value =
      quantity.StaticValue<Unit::MassDensity::GramPerCubicMillimetre>();
  EXPECT_EQ(value, 2.0);
}

TEST(MassDensity, Stream) {
  std::ostringstream stream;
  stream << MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre);
  EXPECT_EQ(
      stream.str(),
      MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).Print());
}

TEST(MassDensity, Unit) {
  EXPECT_EQ(MassDensity::Unit(), Standard<Unit::MassDensity>);
}

TEST(MassDensity, Value) {
  EXPECT_EQ(MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).Value(),
            1.11);
  EXPECT_EQ(MassDensity(2.0, Unit::MassDensity::GramPerCubicMillimetre)
                .Value(Unit::MassDensity::GramPerCubicMillimetre),
            2.0);
}

TEST(MassDensity, XML) {
  EXPECT_EQ(MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).XML(),
            "<value>1.110000000000000</value><unit>kg/m^3</unit>");
  EXPECT_EQ(MassDensity(-2.22, Unit::MassDensity::GramPerCubicMillimetre)
                .XML(Unit::MassDensity::GramPerCubicMillimetre),
            "<value>-2.220000000000000</value><unit>g/mm^3</unit>");
}

TEST(MassDensity, YAML) {
  EXPECT_EQ(MassDensity(1.11, Unit::MassDensity::KilogramPerCubicMetre).YAML(),
            "{value:1.110000000000000,unit:\"kg/m^3\"}");
  EXPECT_EQ(MassDensity(-2.22, Unit::MassDensity::GramPerCubicMillimetre)
                .YAML(Unit::MassDensity::GramPerCubicMillimetre),
            "{value:-2.220000000000000,unit:\"g/mm^3\"}");
}

TEST(MassDensity, Zero) {
  EXPECT_EQ(MassDensity::Zero(),
            MassDensity(0.0, Unit::MassDensity::KilogramPerCubicMetre));
}

}  // namespace

}  // namespace PhQ
