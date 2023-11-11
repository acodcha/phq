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

#include "../include/PhQ/HeatCapacityRatio.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"

namespace PhQ {

namespace {

TEST(HeatCapacityRatio, ArithmeticOperatorAddition) {
  EXPECT_EQ(HeatCapacityRatio(1.0) + HeatCapacityRatio(2.0), HeatCapacityRatio(3.0));
}

TEST(HeatCapacityRatio, ArithmeticOperatorDivision) {
  EXPECT_EQ(HeatCapacityRatio(8.0) / 2.0, HeatCapacityRatio(4.0));

  EXPECT_EQ(HeatCapacityRatio(8.0) / HeatCapacityRatio(2.0), 4.0);
}

TEST(HeatCapacityRatio, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(HeatCapacityRatio(4.0) * 2.0, HeatCapacityRatio(8.0));

  EXPECT_EQ(2.0 * HeatCapacityRatio(4.0), HeatCapacityRatio(8.0));
}

TEST(HeatCapacityRatio, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(HeatCapacityRatio(3.0) - HeatCapacityRatio(2.0), HeatCapacityRatio(1.0));
}

TEST(HeatCapacityRatio, AssignmentOperatorAddition) {
  HeatCapacityRatio quantity{1.0};
  quantity += HeatCapacityRatio(2.0);
  EXPECT_EQ(quantity, HeatCapacityRatio(3.0));
}

TEST(HeatCapacityRatio, AssignmentOperatorDivision) {
  HeatCapacityRatio quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, HeatCapacityRatio(4.0));
}

TEST(HeatCapacityRatio, AssignmentOperatorMultiplication) {
  HeatCapacityRatio quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, HeatCapacityRatio(8.0));
}

TEST(HeatCapacityRatio, AssignmentOperatorSubtraction) {
  HeatCapacityRatio quantity{3.0};
  quantity -= HeatCapacityRatio(2.0);
  EXPECT_EQ(quantity, HeatCapacityRatio(1.0));
}

TEST(HeatCapacityRatio, ComparisonOperators) {
  const HeatCapacityRatio first{1.11};
  const HeatCapacityRatio second{2.22};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(HeatCapacityRatio, CopyAssignmentOperator) {
  const HeatCapacityRatio first{1.11};
  HeatCapacityRatio second = HeatCapacityRatio::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(HeatCapacityRatio, CopyConstructor) {
  const HeatCapacityRatio first{1.11};
  const HeatCapacityRatio second{first};
  EXPECT_EQ(second, first);
}

TEST(HeatCapacityRatio, DefaultConstructor) {
  EXPECT_NO_THROW(HeatCapacityRatio{});
}

TEST(HeatCapacityRatio, Dimensions) {
  EXPECT_EQ(HeatCapacityRatio::Dimensions(), Dimensionless);
}

TEST(HeatCapacityRatio, Hash) {
  const HeatCapacityRatio first{1.11};
  const HeatCapacityRatio second{1.110001};
  const HeatCapacityRatio third{-1.11};
  const std::hash<HeatCapacityRatio> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(HeatCapacityRatio, JSON) {
  EXPECT_EQ(HeatCapacityRatio(1.11).JSON(), "1.110000000000000");
}

TEST(HeatCapacityRatio, MoveAssignmentOperator) {
  HeatCapacityRatio first{1.11};
  HeatCapacityRatio second = HeatCapacityRatio::Zero();
  second = std::move(first);
  EXPECT_EQ(second, HeatCapacityRatio(1.11));
}

TEST(HeatCapacityRatio, MoveConstructor) {
  HeatCapacityRatio first{1.11};
  const HeatCapacityRatio second{std::move(first)};
  EXPECT_EQ(second, HeatCapacityRatio(1.11));
}

TEST(HeatCapacityRatio, MutableValue) {
  HeatCapacityRatio quantity{1.11};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(HeatCapacityRatio, Print) {
  EXPECT_EQ(HeatCapacityRatio(1.11).Print(), "1.110000000000000");
}

TEST(HeatCapacityRatio, SetValue) {
  HeatCapacityRatio quantity{1.11};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(HeatCapacityRatio, SizeOf) {
  EXPECT_EQ(sizeof(HeatCapacityRatio{}), sizeof(double));
}

TEST(HeatCapacityRatio, StandardConstructor) {
  EXPECT_NO_THROW(HeatCapacityRatio(1.11));
}

TEST(HeatCapacityRatio, Stream) {
  std::ostringstream stream;
  stream << HeatCapacityRatio(1.11);
  EXPECT_EQ(stream.str(), HeatCapacityRatio(1.11).Print());
}

TEST(HeatCapacityRatio, Value) {
  EXPECT_EQ(HeatCapacityRatio(1.11).Value(), 1.11);
}

TEST(HeatCapacityRatio, XML) {
  EXPECT_EQ(HeatCapacityRatio(1.11).XML(), "1.110000000000000");
}

TEST(HeatCapacityRatio, YAML) {
  EXPECT_EQ(HeatCapacityRatio(1.11).YAML(), "1.110000000000000");
}

TEST(HeatCapacityRatio, Zero) {
  EXPECT_EQ(HeatCapacityRatio::Zero(), HeatCapacityRatio(0.0));
}

}  // namespace

}  // namespace PhQ
