// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

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
  DisplacementGradient quantity(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  quantity += DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  EXPECT_EQ(quantity, DisplacementGradient(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0));
}

TEST(DisplacementGradient, AssignmentOperatorDivision) {
  DisplacementGradient quantity(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  quantity /= 2.0;
  EXPECT_EQ(quantity, DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DisplacementGradient, AssignmentOperatorMultiplication) {
  DisplacementGradient quantity(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  quantity *= 2.0;
  EXPECT_EQ(quantity, DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
}

TEST(DisplacementGradient, AssignmentOperatorSubtraction) {
  DisplacementGradient quantity(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0);
  quantity -= DisplacementGradient(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  EXPECT_EQ(quantity, DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(DisplacementGradient, ComparisonOperators) {
  constexpr DisplacementGradient first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  constexpr DisplacementGradient second(
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.990001);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(DisplacementGradient, CopyAssignmentOperator) {
  constexpr DisplacementGradient first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  DisplacementGradient second = DisplacementGradient::Zero();
  second = first;
  EXPECT_EQ(second, DisplacementGradient(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
}

TEST(DisplacementGradient, CopyConstructor) {
  constexpr DisplacementGradient first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  constexpr DisplacementGradient second{first};
  EXPECT_EQ(second, DisplacementGradient(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
}

TEST(DisplacementGradient, DefaultConstructor) {
  EXPECT_NO_THROW(DisplacementGradient{});
}

TEST(DisplacementGradient, Dimensions) {
  EXPECT_EQ(DisplacementGradient::Dimensions(), Dimensions());
}

TEST(DisplacementGradient, Hash) {
  constexpr DisplacementGradient first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  constexpr DisplacementGradient second(
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.990001);
  constexpr DisplacementGradient third(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, 8.88, 9.99);
  const std::hash<DisplacementGradient> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DisplacementGradient, JSON) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).JSON(),
            "{\"xx\":1.000000000000000,\"xy\":-2.000000000000000,\"xz\":3.000000000000000,\"yx\":-"
            "4.000000000000000,\"yy\":5.000000000000000,\"yz\":-6.000000000000000,\"zx\":7."
            "000000000000000,\"zy\":-8.000000000000000,\"zz\":9.000000000000000}");
}

TEST(DisplacementGradient, MiscellaneousConstructors) {
  EXPECT_EQ(Strain(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)),
            Strain(1.0, -3.0, 5.0, 5.0, -7.0, 9.0));
}

TEST(DisplacementGradient, MoveAssignmentOperator) {
  DisplacementGradient first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  DisplacementGradient second = DisplacementGradient::Zero();
  second = std::move(first);
  EXPECT_EQ(second, DisplacementGradient(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
}

TEST(DisplacementGradient, MoveConstructor) {
  DisplacementGradient first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  const DisplacementGradient second{std::move(first)};
  EXPECT_EQ(second, DisplacementGradient(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
}

TEST(DisplacementGradient, MutableValue) {
  DisplacementGradient quantity(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  Dyad& value = quantity.MutableValue();
  value = Dyad{-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18};
  EXPECT_EQ(
      quantity.Value(), Dyad(-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(DisplacementGradient, Print) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).Print(),
            "(1.000000000000000, -2.000000000000000, 3.000000000000000; -4.000000000000000, "
            "5.000000000000000, -6.000000000000000; 7.000000000000000, -8.000000000000000, "
            "9.000000000000000)");
}

TEST(DisplacementGradient, SetValue) {
  DisplacementGradient quantity(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  quantity.SetValue(Dyad(-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
  EXPECT_EQ(
      quantity.Value(), Dyad(-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18));
}

TEST(DisplacementGradient, SizeOf) {
  EXPECT_EQ(sizeof(DisplacementGradient{}), 9 * sizeof(double));
}

TEST(DisplacementGradient, StandardConstructor) {
  EXPECT_EQ(DisplacementGradient(
                std::array<double, 9>{1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}),
            DisplacementGradient(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
  EXPECT_EQ(DisplacementGradient(Dyad{1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}),
            DisplacementGradient(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
}

TEST(DisplacementGradient, Stream) {
  std::ostringstream stream;
  stream << DisplacementGradient(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  EXPECT_EQ(stream.str(),
            DisplacementGradient(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99).Print());
}

TEST(DisplacementGradient, Value) {
  EXPECT_EQ(DisplacementGradient(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99).Value(),
            Dyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
}

TEST(DisplacementGradient, XML) {
  EXPECT_EQ(DisplacementGradient(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).XML(),
            "<xx>1.000000000000000</xx><xy>-2.000000000000000</xy><xz>3.000000000000000</"
            "xz><yx>-4.000000000000000</yx><yy>5.000000000000000</yy><yz>-6.000000000000000</"
            "yz><zx>7.000000000000000</zx><zy>-8.000000000000000</zy><zz>9.000000000000000</zz>");
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
            "{xx:1.000000000000000,xy:-2.000000000000000,xz:3.000000000000000,yx:-4."
            "000000000000000,yy:5.000000000000000,yz:-6.000000000000000,zx:7.000000000000000,zy:-8."
            "000000000000000,zz:9.000000000000000}");
}

TEST(DisplacementGradient, Zero) {
  EXPECT_EQ(DisplacementGradient::Zero(),
            DisplacementGradient(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
