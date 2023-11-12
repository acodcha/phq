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

#include "../include/PhQ/DisplacementGradientScalar.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"

namespace PhQ {

namespace {

TEST(DisplacementGradientScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(DisplacementGradientScalar(1.0) + DisplacementGradientScalar(2.0),
            DisplacementGradientScalar(3.0));
}

TEST(DisplacementGradientScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(DisplacementGradientScalar(8.0) / 2.0, DisplacementGradientScalar(4.0));

  EXPECT_EQ(DisplacementGradientScalar(8.0) / DisplacementGradientScalar(2.0), 4.0);
}

TEST(DisplacementGradientScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(DisplacementGradientScalar(4.0) * 2.0, DisplacementGradientScalar(8.0));

  EXPECT_EQ(2.0 * DisplacementGradientScalar(4.0), DisplacementGradientScalar(8.0));
}

TEST(DisplacementGradientScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(DisplacementGradientScalar(3.0) - DisplacementGradientScalar(2.0),
            DisplacementGradientScalar(1.0));
}

TEST(DisplacementGradientScalar, AssignmentOperatorAddition) {
  DisplacementGradientScalar quantity{1.0};
  quantity += DisplacementGradientScalar(2.0);
  EXPECT_EQ(quantity, DisplacementGradientScalar(3.0));
}

TEST(DisplacementGradientScalar, AssignmentOperatorDivision) {
  DisplacementGradientScalar quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, DisplacementGradientScalar(4.0));
}

TEST(DisplacementGradientScalar, AssignmentOperatorMultiplication) {
  DisplacementGradientScalar quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, DisplacementGradientScalar(8.0));
}

TEST(DisplacementGradientScalar, AssignmentOperatorSubtraction) {
  DisplacementGradientScalar quantity{3.0};
  quantity -= DisplacementGradientScalar(2.0);
  EXPECT_EQ(quantity, DisplacementGradientScalar(1.0));
}

TEST(DisplacementGradientScalar, ComparisonOperators) {
  const DisplacementGradientScalar first{1.11};
  const DisplacementGradientScalar second{2.22};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(DisplacementGradientScalar, CopyAssignmentOperator) {
  const DisplacementGradientScalar first{1.11};
  DisplacementGradientScalar second = DisplacementGradientScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DisplacementGradientScalar, CopyConstructor) {
  const DisplacementGradientScalar first{1.11};
  const DisplacementGradientScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(DisplacementGradientScalar, DefaultConstructor) {
  EXPECT_NO_THROW(DisplacementGradientScalar{});
}

TEST(DisplacementGradientScalar, Dimensions) {
  EXPECT_EQ(DisplacementGradientScalar::Dimensions(), Dimensionless);
}

TEST(DisplacementGradientScalar, Hash) {
  const DisplacementGradientScalar first{1.11};
  const DisplacementGradientScalar second{1.110001};
  const DisplacementGradientScalar third{-1.11};
  const std::hash<DisplacementGradientScalar> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DisplacementGradientScalar, JSON) {
  EXPECT_EQ(DisplacementGradientScalar(1.11).JSON(), "1.110000000000000");
}

TEST(DisplacementGradientScalar, MoveAssignmentOperator) {
  DisplacementGradientScalar first{1.11};
  DisplacementGradientScalar second = DisplacementGradientScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(second, DisplacementGradientScalar(1.11));
}

TEST(DisplacementGradientScalar, MoveConstructor) {
  DisplacementGradientScalar first{1.11};
  const DisplacementGradientScalar second{std::move(first)};
  EXPECT_EQ(second, DisplacementGradientScalar(1.11));
}

TEST(DisplacementGradientScalar, MutableValue) {
  DisplacementGradientScalar quantity{1.11};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(DisplacementGradientScalar, Print) {
  EXPECT_EQ(DisplacementGradientScalar(1.11).Print(), "1.110000000000000");
}

TEST(DisplacementGradientScalar, SetValue) {
  DisplacementGradientScalar quantity{1.11};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(DisplacementGradientScalar, SizeOf) {
  EXPECT_EQ(sizeof(DisplacementGradientScalar{}), sizeof(double));
}

TEST(DisplacementGradientScalar, StandardConstructor) {
  EXPECT_NO_THROW(DisplacementGradientScalar(1.11));
}

TEST(DisplacementGradientScalar, Stream) {
  std::ostringstream stream;
  stream << DisplacementGradientScalar(1.11);
  EXPECT_EQ(stream.str(), DisplacementGradientScalar(1.11).Print());
}

TEST(DisplacementGradientScalar, Value) {
  EXPECT_EQ(DisplacementGradientScalar(1.11).Value(), 1.11);
}

TEST(DisplacementGradientScalar, XML) {
  EXPECT_EQ(DisplacementGradientScalar(1.11).XML(), "1.110000000000000");
}

TEST(DisplacementGradientScalar, YAML) {
  EXPECT_EQ(DisplacementGradientScalar(1.11).YAML(), "1.110000000000000");
}

TEST(DisplacementGradientScalar, Zero) {
  EXPECT_EQ(DisplacementGradientScalar::Zero(), DisplacementGradientScalar(0.0));
}

}  // namespace

}  // namespace PhQ
