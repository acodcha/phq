// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/DisplacementGradient.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/Dyad.hpp"
#include "../include/PhQ/ScalarDisplacementGradient.hpp"
#include "../include/PhQ/Strain.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(DisplacementGradient, ArithmeticOperatorAddition) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)
                + DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0),
            DisplacementGradient(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0));
}

TEST(DisplacementGradient, ArithmeticOperatorDivision) {
  EXPECT_EQ(DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0) / 2.0,
            DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DisplacementGradient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0) * 2.0,
            DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  EXPECT_EQ(2.0 * DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
}

TEST(DisplacementGradient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(DisplacementGradient(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0)
                - DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0),
            DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DisplacementGradient, AssignmentOperatorAddition) {
  DisplacementGradient displacement_gradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  displacement_gradient +=
      DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  EXPECT_EQ(displacement_gradient,
            DisplacementGradient(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0));
}

TEST(DisplacementGradient, AssignmentOperatorDivision) {
  DisplacementGradient displacement_gradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  displacement_gradient /= 2.0;
  EXPECT_EQ(
      displacement_gradient, DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DisplacementGradient, AssignmentOperatorMultiplication) {
  DisplacementGradient displacement_gradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  displacement_gradient *= 2.0;
  EXPECT_EQ(displacement_gradient,
            DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
}

TEST(DisplacementGradient, AssignmentOperatorSubtraction) {
  DisplacementGradient displacement_gradient(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0);
  displacement_gradient -=
      DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  EXPECT_EQ(
      displacement_gradient, DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DisplacementGradient, ComparisonOperators) {
  constexpr DisplacementGradient first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  constexpr DisplacementGradient second(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.000001);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(DisplacementGradient, Constructor) {
  EXPECT_EQ(
      DisplacementGradient(std::array<double, 9>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}),
      DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  EXPECT_EQ(DisplacementGradient(Dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}),
            DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  EXPECT_EQ(Strain(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)),
            Strain(1.0, -3.0, 5.0, 5.0, -7.0, 9.0));
}

TEST(DisplacementGradient, CopyAssignmentOperator) {
  {
    const DisplacementGradient<float> first{
      1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    DisplacementGradient<double> second = DisplacementGradient<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, DisplacementGradient<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    const DisplacementGradient<double> first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    DisplacementGradient<double> second = DisplacementGradient<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, DisplacementGradient<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    const DisplacementGradient<long double> first{
      1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    DisplacementGradient<double> second = DisplacementGradient<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, DisplacementGradient<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
}

TEST(DisplacementGradient, CopyConstructor) {
  {
    const DisplacementGradient<float> first{
      1.0F, -2.0F, 3.0F, -4.0F, 5.0F, -6.0F, 7.0F, -8.0F, 9.0F};
    const DisplacementGradient<double> second{first};
    EXPECT_EQ(
        second, DisplacementGradient<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    const DisplacementGradient<double> first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    const DisplacementGradient<double> second{first};
    EXPECT_EQ(
        second, DisplacementGradient<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
  {
    const DisplacementGradient<long double> first{
      1.0L, -2.0L, 3.0L, -4.0L, 5.0L, -6.0L, 7.0L, -8.0L, 9.0L};
    const DisplacementGradient<double> second{first};
    EXPECT_EQ(
        second, DisplacementGradient<double>(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  }
}

TEST(DisplacementGradient, DefaultConstructor) {
  EXPECT_NO_THROW(DisplacementGradient<>{});
}

TEST(DisplacementGradient, Dimensions) {
  EXPECT_EQ(DisplacementGradient<>::Dimensions(), Dimensionless);
}

TEST(DisplacementGradient, Hash) {
  constexpr DisplacementGradient first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  constexpr DisplacementGradient second(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.00001);
  constexpr DisplacementGradient third(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, 8.0, 9.0);
  const std::hash<DisplacementGradient<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DisplacementGradient, JSON) {
  EXPECT_EQ(
      DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).JSON(),
      "{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
          + ",\"yx\":" + Print(-4.0) + ",\"yy\":" + Print(5.0) + ",\"yz\":" + Print(-6.0)
          + ",\"zx\":" + Print(7.0) + ",\"zy\":" + Print(-8.0) + ",\"zz\":" + Print(9.0) + "}");
}

TEST(DisplacementGradient, MoveAssignmentOperator) {
  DisplacementGradient first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  DisplacementGradient second = DisplacementGradient<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DisplacementGradient, MoveConstructor) {
  DisplacementGradient first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  const DisplacementGradient second{std::move(first)};
  EXPECT_EQ(second, DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DisplacementGradient, MutableValue) {
  DisplacementGradient displacement_gradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  Dyad<>& value = displacement_gradient.MutableValue();
  value = Dyad{-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18};
  EXPECT_EQ(displacement_gradient.Value(),
            Dyad(-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(DisplacementGradient, Performance) {
  DisplacementGradient displacement_gradient_1{
    1.2345678901234567890, 2.3456789012345678901, 3.4567890123456789012,
    4.5678901234567890123, 5.6789012345678901234, 6.7890123456789012345,
    7.8901234567890123456, 8.9012345678901234567, 9.0123456789012345678};
  DisplacementGradient displacement_gradient_2{
    1.2345678901234567890, 2.3456789012345678901, 3.4567890123456789012,
    4.5678901234567890123, 5.6789012345678901234, 6.7890123456789012345,
    7.8901234567890123456, 8.9012345678901234567, 9.0123456789012345678};
  std::array<double, 9> reference1{
    1.2345678901234567890, 2.3456789012345678901, 3.4567890123456789012,
    4.5678901234567890123, 5.6789012345678901234, 6.7890123456789012345,
    7.8901234567890123456, 8.9012345678901234567, 9.0123456789012345678};
  std::array<double, 9> reference2{
    1.2345678901234567890, 2.3456789012345678901, 3.4567890123456789012,
    4.5678901234567890123, 5.6789012345678901234, 6.7890123456789012345,
    7.8901234567890123456, 8.9012345678901234567, 9.0123456789012345678};
  Internal::TestDyadPerformance(
      displacement_gradient_1, displacement_gradient_2, reference1, reference2);
}

TEST(DisplacementGradient, Print) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + ", " + Print(-6.0) + "; " + Print(7.0) + ", " + Print(-8.0) + ", "
                + Print(9.0) + ")");
}

TEST(DisplacementGradient, SetValue) {
  DisplacementGradient displacement_gradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  displacement_gradient.SetValue(
      Dyad(-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
  EXPECT_EQ(displacement_gradient.Value(),
            Dyad(-10.10, 11.0, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(DisplacementGradient, SizeOf) {
  EXPECT_EQ(sizeof(DisplacementGradient<>{}), 9 * sizeof(double));
}

TEST(DisplacementGradient, Stream) {
  std::ostringstream stream;
  stream << DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  EXPECT_EQ(
      stream.str(), DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).Print());
}

TEST(DisplacementGradient, Value) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).Value(),
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DisplacementGradient, XML) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).XML(),
            "<xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0) + "</xz><yx>"
                + Print(-4.0) + "</yx><yy>" + Print(5.0) + "</yy><yz>" + Print(-6.0) + "</yz><zx>"
                + Print(7.0) + "</zx><zy>" + Print(-8.0) + "</zy><zz>" + Print(9.0) + "</zz>");
}

TEST(DisplacementGradient, XYZ) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).xx(),
            ScalarDisplacementGradient(1.0));
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).xy(),
            ScalarDisplacementGradient(-2.0));
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).xz(),
            ScalarDisplacementGradient(3.0));
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).yx(),
            ScalarDisplacementGradient(-4.0));
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).yy(),
            ScalarDisplacementGradient(5.0));
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).yz(),
            ScalarDisplacementGradient(-6.0));
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).zx(),
            ScalarDisplacementGradient(7.0));
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).zy(),
            ScalarDisplacementGradient(-8.0));
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).zz(),
            ScalarDisplacementGradient(9.0));
}

TEST(DisplacementGradient, YAML) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).YAML(),
            "{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yx:" + Print(-4.0)
                + ",yy:" + Print(5.0) + ",yz:" + Print(-6.0) + ",zx:" + Print(7.0)
                + ",zy:" + Print(-8.0) + ",zz:" + Print(9.0) + "}");
}

TEST(DisplacementGradient, Zero) {
  EXPECT_EQ(DisplacementGradient<>::Zero(),
            DisplacementGradient(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
