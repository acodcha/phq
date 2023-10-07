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

#include "../include/PhQ/DynamicViscosity.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(DynamicViscosity, ArithmeticAddition) {
  EXPECT_EQ(DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond)
                + DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            DynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond));

  DynamicViscosity quantity{1.0, Unit::DynamicViscosity::PascalSecond};
  quantity += DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(
      quantity, DynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, ArithmeticDivision) {
  EXPECT_EQ(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond) / 2.0,
            DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond)
                / DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            4.0);

  EXPECT_EQ(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond)
                / MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
            KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond));

  EXPECT_EQ(
      DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond)
          / KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
      MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));

  DynamicViscosity quantity{8.0, Unit::DynamicViscosity::PascalSecond};
  quantity /= 2.0;
  EXPECT_EQ(
      quantity, DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, ArithmeticMultiplication) {
  EXPECT_EQ(DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond) * 2.0,
            DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(2.0 * DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond),
            DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond)
                * MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(
      MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)
          * KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond),
      DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));

  DynamicViscosity quantity{4.0, Unit::DynamicViscosity::PascalSecond};
  quantity *= 2.0;
  EXPECT_EQ(
      quantity, DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, ArithmeticSubtraction) {
  EXPECT_EQ(DynamicViscosity(3.0, Unit::DynamicViscosity::PascalSecond)
                - DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond),
            DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));

  DynamicViscosity quantity{3.0, Unit::DynamicViscosity::PascalSecond};
  quantity -= DynamicViscosity(2.0, Unit::DynamicViscosity::PascalSecond);
  EXPECT_EQ(
      quantity, DynamicViscosity(1.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, Comparisons) {
  const DynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  const DynamicViscosity second{2.22, Unit::DynamicViscosity::PascalSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(DynamicViscosity, CopyAssignment) {
  const DynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  DynamicViscosity second = DynamicViscosity::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DynamicViscosity, CopyConstructor) {
  const DynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  const DynamicViscosity second{first};
  EXPECT_EQ(second, first);
}

TEST(DynamicViscosity, Create) {
  constexpr DynamicViscosity quantity =
      DynamicViscosity::Create<Unit::DynamicViscosity::PascalSecond>(1.11);
  EXPECT_EQ(
      quantity, DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond));
}

TEST(DynamicViscosity, DefaultConstructor) {
  EXPECT_NO_THROW(DynamicViscosity{});
}

TEST(DynamicViscosity, Dimensions) {
  EXPECT_EQ(DynamicViscosity::Dimensions(),
            RelatedDimensions<Unit::DynamicViscosity>);
}

TEST(DynamicViscosity, Hash) {
  const DynamicViscosity first{1.11, Unit::DynamicViscosity::KilopascalSecond};
  const DynamicViscosity second{
      1.110001, Unit::DynamicViscosity::KilopascalSecond};
  const DynamicViscosity third{-1.11, Unit::DynamicViscosity::KilopascalSecond};
  const std::hash<DynamicViscosity> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DynamicViscosity, JSON) {
  EXPECT_EQ(DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Pa·s\"}");
  EXPECT_EQ(DynamicViscosity(-2.22, Unit::DynamicViscosity::KilopascalSecond)
                .JSON(Unit::DynamicViscosity::KilopascalSecond),
            "{\"value\":-2.220000000000000,\"unit\":\"kPa·s\"}");
}

TEST(DynamicViscosity, MiscellaneousConstructors) {
  EXPECT_EQ(
      DynamicViscosity(
          MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
          KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond)),
      DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(KinematicViscosity(
                DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)),
            KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond));

  EXPECT_EQ(
      MassDensity(
          DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
          KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond)),
      MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));
}

TEST(DynamicViscosity, MoveAssignment) {
  const DynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  DynamicViscosity second{1.11, Unit::DynamicViscosity::PascalSecond};
  DynamicViscosity third = DynamicViscosity::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(DynamicViscosity, MoveConstructor) {
  const DynamicViscosity first{1.11, Unit::DynamicViscosity::PascalSecond};
  DynamicViscosity second{1.11, Unit::DynamicViscosity::PascalSecond};
  DynamicViscosity third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(DynamicViscosity, MutableValue) {
  DynamicViscosity quantity{1.11, Unit::DynamicViscosity::PascalSecond};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(DynamicViscosity, Print) {
  EXPECT_EQ(
      DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Print(),
      "1.110000000000000 Pa·s");
  EXPECT_EQ(DynamicViscosity(-2.22, Unit::DynamicViscosity::KilopascalSecond)
                .Print(Unit::DynamicViscosity::KilopascalSecond),
            "-2.220000000000000 kPa·s");
}

TEST(DynamicViscosity, SetValue) {
  DynamicViscosity quantity{1.11, Unit::DynamicViscosity::PascalSecond};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(DynamicViscosity, SizeOf) {
  EXPECT_EQ(sizeof(DynamicViscosity{}), sizeof(double));
}

TEST(DynamicViscosity, StandardConstructor) {
  EXPECT_NO_THROW(
      DynamicViscosity(1.11, Unit::DynamicViscosity::KilopascalSecond));
}

TEST(DynamicViscosity, StaticValue) {
  constexpr DynamicViscosity quantity =
      DynamicViscosity::Create<Unit::DynamicViscosity::KilopascalSecond>(1.11);
  constexpr double value =
      quantity.StaticValue<Unit::DynamicViscosity::KilopascalSecond>();
  EXPECT_EQ(value, 1.11);
}

TEST(DynamicViscosity, Stream) {
  const DynamicViscosity quantity{1.11, Unit::DynamicViscosity::PascalSecond};
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(DynamicViscosity, Unit) {
  EXPECT_EQ(DynamicViscosity::Unit(), Standard<Unit::DynamicViscosity>);
}

TEST(DynamicViscosity, Value) {
  EXPECT_EQ(
      DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).Value(),
      1.11);
  EXPECT_EQ(DynamicViscosity(1.11, Unit::DynamicViscosity::KilopascalSecond)
                .Value(Unit::DynamicViscosity::KilopascalSecond),
            1.11);
}

TEST(DynamicViscosity, XML) {
  EXPECT_EQ(DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).XML(),
            "<value>1.110000000000000</value><unit>Pa·s</unit>");
  EXPECT_EQ(DynamicViscosity(-2.22, Unit::DynamicViscosity::KilopascalSecond)
                .XML(Unit::DynamicViscosity::KilopascalSecond),
            "<value>-2.220000000000000</value><unit>kPa·s</unit>");
}

TEST(DynamicViscosity, YAML) {
  EXPECT_EQ(DynamicViscosity(1.11, Unit::DynamicViscosity::PascalSecond).YAML(),
            "{value:1.110000000000000,unit:\"Pa·s\"}");
  EXPECT_EQ(DynamicViscosity(-2.22, Unit::DynamicViscosity::KilopascalSecond)
                .YAML(Unit::DynamicViscosity::KilopascalSecond),
            "{value:-2.220000000000000,unit:\"kPa·s\"}");
}

TEST(DynamicViscosity, Zero) {
  EXPECT_EQ(DynamicViscosity::Zero(),
            DynamicViscosity(0.0, Unit::DynamicViscosity::PascalSecond));
}

}  // namespace

}  // namespace PhQ
