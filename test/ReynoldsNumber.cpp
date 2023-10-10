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

#include "../include/PhQ/ReynoldsNumber.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(ReynoldsNumber, ArithmeticOperatorAddition) {
  EXPECT_EQ(ReynoldsNumber(1.0) + ReynoldsNumber(2.0), ReynoldsNumber(3.0));
}

TEST(ReynoldsNumber, ArithmeticOperatorDivision) {
  EXPECT_EQ(ReynoldsNumber(8.0) / 2.0, ReynoldsNumber(4.0));

  EXPECT_EQ(ReynoldsNumber(8.0) / ReynoldsNumber(2.0), 4.0);
}

TEST(ReynoldsNumber, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ReynoldsNumber(4.0) * 2.0, ReynoldsNumber(8.0));

  EXPECT_EQ(2.0 * ReynoldsNumber(4.0), ReynoldsNumber(8.0));
}

TEST(ReynoldsNumber, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ReynoldsNumber(3.0) - ReynoldsNumber(2.0), ReynoldsNumber(1.0));
}

TEST(ReynoldsNumber, AssignmentOperatorAddition) {
  ReynoldsNumber quantity{1.0};
  quantity += ReynoldsNumber(2.0);
  EXPECT_EQ(quantity, ReynoldsNumber(3.0));
}

TEST(ReynoldsNumber, AssignmentOperatorDivision) {
  ReynoldsNumber quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ReynoldsNumber(4.0));
}

TEST(ReynoldsNumber, AssignmentOperatorMultiplication) {
  ReynoldsNumber quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ReynoldsNumber(8.0));
}

TEST(ReynoldsNumber, AssignmentOperatorSubtraction) {
  ReynoldsNumber quantity{3.0};
  quantity -= ReynoldsNumber(2.0);
  EXPECT_EQ(quantity, ReynoldsNumber(1.0));
}

TEST(ReynoldsNumber, ComparisonOperators) {
  const ReynoldsNumber first{1.11};
  const ReynoldsNumber second{2.22};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ReynoldsNumber, CopyAssignmentOperator) {
  const ReynoldsNumber first{1.11};
  ReynoldsNumber second = ReynoldsNumber::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ReynoldsNumber, CopyConstructor) {
  const ReynoldsNumber first{1.11};
  const ReynoldsNumber second{first};
  EXPECT_EQ(second, first);
}

TEST(ReynoldsNumber, DefaultConstructor) {
  EXPECT_NO_THROW(ReynoldsNumber{});
}

TEST(ReynoldsNumber, Dimensions) {
  EXPECT_EQ(ReynoldsNumber::Dimensions(), Dimensions{});
}

TEST(ReynoldsNumber, Hash) {
  const ReynoldsNumber first{1.11};
  const ReynoldsNumber second{1.110001};
  const ReynoldsNumber third{-1.11};
  const std::hash<ReynoldsNumber> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ReynoldsNumber, JSON) {
  EXPECT_EQ(ReynoldsNumber(1.11).JSON(), "1.110000000000000");
}

TEST(ReynoldsNumber, MiscellaneousConstructors) {
  EXPECT_EQ(ReynoldsNumber(
                MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                Speed(4.0, Unit::Speed::MetrePerSecond),
                Length(8.0, Unit::Length::Metre),
                DynamicViscosity(16.0, Unit::DynamicViscosity::PascalSecond)),
            ReynoldsNumber(4.0));

  EXPECT_EQ(
      ReynoldsNumber(
          Speed(8.0, Unit::Speed::MetrePerSecond),
          Length(4.0, Unit::Length::Metre),
          KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond)),
      ReynoldsNumber(16.0));

  EXPECT_EQ(Length(ReynoldsNumber(16.0),
                   DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                   MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                   Speed(2.0, Unit::Speed::MetrePerSecond)),
            Length(16.0, Unit::Length::Metre));

  EXPECT_EQ(
      Length(ReynoldsNumber(4.0),
             KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond),
             Speed(2.0, Unit::Speed::MetrePerSecond)),
      Length(16.0, Unit::Length::Metre));

  EXPECT_EQ(Speed(ReynoldsNumber(16.0),
                  DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                  MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                  Length(2.0, Unit::Length::Metre)),
            Speed(16.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      Speed(ReynoldsNumber(8.0),
            KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
            Length(2.0, Unit::Length::Metre)),
      Speed(16.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      MassDensity(ReynoldsNumber(16.0),
                  DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                  Speed(4.0, Unit::Speed::MetrePerSecond),
                  Length(2.0, Unit::Length::Metre)),
      MassDensity(16.0, Unit::MassDensity::KilogramPerCubicMetre));

  EXPECT_EQ(
      KinematicViscosity(Speed(8.0, Unit::Speed::MetrePerSecond),
                         Length(4.0, Unit::Length::Metre), ReynoldsNumber(2.0)),
      KinematicViscosity(16.0, Unit::Diffusivity::SquareMetrePerSecond));

  EXPECT_EQ(DynamicViscosity(
                MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                Speed(4.0, Unit::Speed::MetrePerSecond),
                Length(8.0, Unit::Length::Metre), ReynoldsNumber(16.0)),
            DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(ReynoldsNumber, MiscellaneousMethods) {
  EXPECT_EQ(ReynoldsNumber(16.0).DynamicViscosity(
                MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                Speed(4.0, Unit::Speed::MetrePerSecond),
                Length(8.0, Unit::Length::Metre)),
            DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));

  EXPECT_EQ(ReynoldsNumber(2.0).KinematicViscosity(
                Speed(8.0, Unit::Speed::MetrePerSecond),
                Length(4.0, Unit::Length::Metre)),
            KinematicViscosity(16.0, Unit::Diffusivity::SquareMetrePerSecond));

  EXPECT_EQ(ReynoldsNumber(16.0).Length(
                DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                Speed(2.0, Unit::Speed::MetrePerSecond)),
            Length(16.0, Unit::Length::Metre));

  EXPECT_EQ(
      ReynoldsNumber(8.0).Length(
          KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
          Speed(2.0, Unit::Speed::MetrePerSecond)),
      Length(16.0, Unit::Length::Metre));

  EXPECT_EQ(ReynoldsNumber(16.0).MassDensity(
                DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                Speed(4.0, Unit::Speed::MetrePerSecond),
                Length(2.0, Unit::Length::Metre)),
            MassDensity(16.0, Unit::MassDensity::KilogramPerCubicMetre));

  EXPECT_EQ(ReynoldsNumber(16.0).Speed(
                DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                Length(2.0, Unit::Length::Metre)),
            Speed(16.0, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(
      ReynoldsNumber(8.0).Speed(
          KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
          Length(2.0, Unit::Length::Metre)),
      Speed(16.0, Unit::Speed::MetrePerSecond));
}

TEST(ReynoldsNumber, MoveAssignmentOperator) {
  ReynoldsNumber first{1.11};
  ReynoldsNumber second = ReynoldsNumber::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ReynoldsNumber(1.11));
}

TEST(ReynoldsNumber, MoveConstructor) {
  ReynoldsNumber first{1.11};
  ReynoldsNumber second{std::move(first)};
  EXPECT_EQ(second, ReynoldsNumber(1.11));
}

TEST(ReynoldsNumber, MutableValue) {
  ReynoldsNumber quantity{1.11};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ReynoldsNumber, Print) {
  EXPECT_EQ(ReynoldsNumber(1.11).Print(), "1.110000000000000");
}

TEST(ReynoldsNumber, SetValue) {
  ReynoldsNumber quantity{1.11};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ReynoldsNumber, SizeOf) {
  EXPECT_EQ(sizeof(ReynoldsNumber{}), sizeof(double));
}

TEST(ReynoldsNumber, StandardConstructor) {
  EXPECT_NO_THROW(ReynoldsNumber(1.11));
}

TEST(ReynoldsNumber, Stream) {
  std::ostringstream stream;
  stream << ReynoldsNumber(1.11);
  EXPECT_EQ(stream.str(), ReynoldsNumber(1.11).Print());
}

TEST(ReynoldsNumber, Value) {
  EXPECT_EQ(ReynoldsNumber(1.11).Value(), 1.11);
}

TEST(ReynoldsNumber, XML) {
  EXPECT_EQ(ReynoldsNumber(1.11).XML(), "1.110000000000000");
}

TEST(ReynoldsNumber, YAML) {
  EXPECT_EQ(ReynoldsNumber(1.11).YAML(), "1.110000000000000");
}

TEST(ReynoldsNumber, Zero) {
  EXPECT_EQ(ReynoldsNumber::Zero(), ReynoldsNumber(0.0));
}

}  // namespace

}  // namespace PhQ
