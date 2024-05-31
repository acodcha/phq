// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/ReynoldsNumber.hpp"

#include <cmath>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/DynamicViscosity.hpp"
#include "../include/PhQ/KinematicViscosity.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/MassDensity.hpp"
#include "../include/PhQ/Speed.hpp"
#include "../include/PhQ/Unit/Diffusivity.hpp"
#include "../include/PhQ/Unit/DynamicViscosity.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Unit/MassDensity.hpp"
#include "../include/PhQ/Unit/Speed.hpp"

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
  ReynoldsNumber reynolds_number{1.0};
  reynolds_number += ReynoldsNumber(2.0);
  EXPECT_EQ(reynolds_number, ReynoldsNumber(3.0));
}

TEST(ReynoldsNumber, AssignmentOperatorDivision) {
  ReynoldsNumber reynolds_number{8.0};
  reynolds_number /= 2.0;
  EXPECT_EQ(reynolds_number, ReynoldsNumber(4.0));
}

TEST(ReynoldsNumber, AssignmentOperatorMultiplication) {
  ReynoldsNumber reynolds_number{4.0};
  reynolds_number *= 2.0;
  EXPECT_EQ(reynolds_number, ReynoldsNumber(8.0));
}

TEST(ReynoldsNumber, AssignmentOperatorSubtraction) {
  ReynoldsNumber reynolds_number{3.0};
  reynolds_number -= ReynoldsNumber(2.0);
  EXPECT_EQ(reynolds_number, ReynoldsNumber(1.0));
}

TEST(ReynoldsNumber, ComparisonOperators) {
  const ReynoldsNumber first{1.0};
  const ReynoldsNumber second{2.0};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ReynoldsNumber, Constructor) {
  EXPECT_NO_THROW(ReynoldsNumber(1.0));
  EXPECT_EQ(
      ReynoldsNumber(MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                     Speed(4.0, Unit::Speed::MetrePerSecond), Length(8.0, Unit::Length::Metre),
                     DynamicViscosity(16.0, Unit::DynamicViscosity::PascalSecond)),
      ReynoldsNumber(4.0));
  EXPECT_EQ(
      ReynoldsNumber(Speed(8.0, Unit::Speed::MetrePerSecond), Length(4.0, Unit::Length::Metre),
                     KinematicViscosity(2.0, Unit::Diffusivity::SquareMetrePerSecond)),
      ReynoldsNumber(16.0));
  EXPECT_EQ(
      Length(ReynoldsNumber(16.0), DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
             MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
             Speed(2.0, Unit::Speed::MetrePerSecond)),
      Length(16.0, Unit::Length::Metre));
  EXPECT_EQ(
      Length(ReynoldsNumber(4.0), KinematicViscosity(8.0, Unit::Diffusivity::SquareMetrePerSecond),
             Speed(2.0, Unit::Speed::MetrePerSecond)),
      Length(16.0, Unit::Length::Metre));
  EXPECT_EQ(Speed(ReynoldsNumber(16.0), DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                  MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                  Length(2.0, Unit::Length::Metre)),
            Speed(16.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(
      Speed(ReynoldsNumber(8.0), KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
            Length(2.0, Unit::Length::Metre)),
      Speed(16.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(
      MassDensity(ReynoldsNumber(16.0), DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                  Speed(4.0, Unit::Speed::MetrePerSecond), Length(2.0, Unit::Length::Metre)),
      MassDensity(16.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(KinematicViscosity(Speed(8.0, Unit::Speed::MetrePerSecond),
                               Length(4.0, Unit::Length::Metre), ReynoldsNumber(2.0)),
            KinematicViscosity(16.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(DynamicViscosity(MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                             Speed(4.0, Unit::Speed::MetrePerSecond),
                             Length(8.0, Unit::Length::Metre), ReynoldsNumber(16.0)),
            DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
}

TEST(ReynoldsNumber, CopyAssignmentOperator) {
  {
    const ReynoldsNumber<float> first(1.0F);
    ReynoldsNumber<double> second = ReynoldsNumber<double>::Zero();
    second = first;
    EXPECT_EQ(second, ReynoldsNumber<double>(1.0));
  }
  {
    const ReynoldsNumber<double> first(1.0);
    ReynoldsNumber<double> second = ReynoldsNumber<double>::Zero();
    second = first;
    EXPECT_EQ(second, ReynoldsNumber<double>(1.0));
  }
  {
    const ReynoldsNumber<long double> first(1.0L);
    ReynoldsNumber<double> second = ReynoldsNumber<double>::Zero();
    second = first;
    EXPECT_EQ(second, ReynoldsNumber<double>(1.0));
  }
}

TEST(ReynoldsNumber, CopyConstructor) {
  {
    const ReynoldsNumber<float> first(1.0F);
    const ReynoldsNumber<double> second{first};
    EXPECT_EQ(second, ReynoldsNumber<double>(1.0));
  }
  {
    const ReynoldsNumber<double> first(1.0);
    const ReynoldsNumber<double> second{first};
    EXPECT_EQ(second, ReynoldsNumber<double>(1.0));
  }
  {
    const ReynoldsNumber<long double> first(1.0L);
    const ReynoldsNumber<double> second{first};
    EXPECT_EQ(second, ReynoldsNumber<double>(1.0));
  }
}

TEST(ReynoldsNumber, DefaultConstructor) {
  EXPECT_NO_THROW(ReynoldsNumber<>{});
}

TEST(ReynoldsNumber, Dimensions) {
  EXPECT_EQ(ReynoldsNumber<>::Dimensions(), Dimensionless);
}

TEST(ReynoldsNumber, Hash) {
  const ReynoldsNumber first{1.0};
  const ReynoldsNumber second{1.000001};
  const ReynoldsNumber third{-1.0};
  const std::hash<ReynoldsNumber<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ReynoldsNumber, JSON) {
  EXPECT_EQ(ReynoldsNumber(1.0).JSON(), Print(1.0));
}

TEST(ReynoldsNumber, Mathematics) {
  EXPECT_EQ(std::abs(ReynoldsNumber(-1.0)), std::abs(-1.0));
  EXPECT_EQ(std::cbrt(ReynoldsNumber(-8.0)), std::cbrt(-8.0));
  EXPECT_EQ(std::exp(ReynoldsNumber(2.0)), std::exp(2.0));
  EXPECT_EQ(std::log(ReynoldsNumber(2.0)), std::log(2.0));
  EXPECT_EQ(std::log2(ReynoldsNumber(8.0)), std::log2(8.0));
  EXPECT_EQ(std::log10(ReynoldsNumber(100.0)), std::log10(100.0));
  EXPECT_EQ(std::pow(ReynoldsNumber(4.0), 3), std::pow(4.0, 3));
  EXPECT_EQ(std::pow(ReynoldsNumber(4.0), 3L), std::pow(4.0, 3L));
  EXPECT_EQ(std::pow(ReynoldsNumber(4.0), 3LL), std::pow(4.0, 3LL));
  EXPECT_EQ(std::pow(ReynoldsNumber(4.0), 3.0F), std::pow(4.0, 3.0F));
  EXPECT_EQ(std::pow(ReynoldsNumber(4.0), 3.0), std::pow(4.0, 3.0));
  EXPECT_EQ(std::pow(ReynoldsNumber(4.0), 3.0L), std::pow(4.0, 3.0L));
  EXPECT_EQ(std::sqrt(ReynoldsNumber(9.0)), std::sqrt(9.0));
}

TEST(ReynoldsNumber, MiscellaneousMethods) {
  EXPECT_EQ(ReynoldsNumber(16.0).DynamicViscosity(
                MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                Speed(4.0, Unit::Speed::MetrePerSecond), Length(8.0, Unit::Length::Metre)),
            DynamicViscosity(4.0, Unit::DynamicViscosity::PascalSecond));
  EXPECT_EQ(ReynoldsNumber(2.0).KinematicViscosity(
                Speed(8.0, Unit::Speed::MetrePerSecond), Length(4.0, Unit::Length::Metre)),
            KinematicViscosity(16.0, Unit::Diffusivity::SquareMetrePerSecond));
  EXPECT_EQ(ReynoldsNumber(16.0).Length(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                                        MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                                        Speed(2.0, Unit::Speed::MetrePerSecond)),
            Length(16.0, Unit::Length::Metre));
  EXPECT_EQ(
      ReynoldsNumber(8.0).Length(KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
                                 Speed(2.0, Unit::Speed::MetrePerSecond)),
      Length(16.0, Unit::Length::Metre));
  EXPECT_EQ(ReynoldsNumber(16.0).MassDensity(
                DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                Speed(4.0, Unit::Speed::MetrePerSecond), Length(2.0, Unit::Length::Metre)),
            MassDensity(16.0, Unit::MassDensity::KilogramPerCubicMetre));
  EXPECT_EQ(ReynoldsNumber(16.0).Speed(DynamicViscosity(8.0, Unit::DynamicViscosity::PascalSecond),
                                       MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
                                       Length(2.0, Unit::Length::Metre)),
            Speed(16.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(
      ReynoldsNumber(8.0).Speed(KinematicViscosity(4.0, Unit::Diffusivity::SquareMetrePerSecond),
                                Length(2.0, Unit::Length::Metre)),
      Speed(16.0, Unit::Speed::MetrePerSecond));
}

TEST(ReynoldsNumber, MoveAssignmentOperator) {
  ReynoldsNumber first{1.0};
  ReynoldsNumber second = ReynoldsNumber<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ReynoldsNumber(1.0));
}

TEST(ReynoldsNumber, MoveConstructor) {
  ReynoldsNumber first{1.0};
  const ReynoldsNumber second{std::move(first)};
  EXPECT_EQ(second, ReynoldsNumber(1.0));
}

TEST(ReynoldsNumber, MutableValue) {
  ReynoldsNumber reynolds_number{1.0};
  double& value = reynolds_number.MutableValue();
  value = 2.0;
  EXPECT_EQ(reynolds_number.Value(), 2.0);
}

TEST(ReynoldsNumber, Print) {
  EXPECT_EQ(ReynoldsNumber(1.0).Print(), Print(1.0));
}

TEST(ReynoldsNumber, SetValue) {
  ReynoldsNumber reynolds_number{1.0};
  reynolds_number.SetValue(2.0);
  EXPECT_EQ(reynolds_number.Value(), 2.0);
}

TEST(ReynoldsNumber, SizeOf) {
  EXPECT_EQ(sizeof(ReynoldsNumber<>{}), sizeof(double));
}

TEST(ReynoldsNumber, Stream) {
  std::ostringstream stream;
  stream << ReynoldsNumber(1.0);
  EXPECT_EQ(stream.str(), ReynoldsNumber(1.0).Print());
}

TEST(ReynoldsNumber, Value) {
  EXPECT_EQ(ReynoldsNumber(1.0).Value(), 1.0);
}

TEST(ReynoldsNumber, XML) {
  EXPECT_EQ(ReynoldsNumber(1.0).XML(), Print(1.0));
}

TEST(ReynoldsNumber, YAML) {
  EXPECT_EQ(ReynoldsNumber(1.0).YAML(), Print(1.0));
}

TEST(ReynoldsNumber, Zero) {
  EXPECT_EQ(ReynoldsNumber<>::Zero(), ReynoldsNumber(0.0));
}

}  // namespace

}  // namespace PhQ
