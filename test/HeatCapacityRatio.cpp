// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#include <cmath>
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
  HeatCapacityRatio heat_capacity_ratio{1.0};
  heat_capacity_ratio += HeatCapacityRatio(2.0);
  EXPECT_EQ(heat_capacity_ratio, HeatCapacityRatio(3.0));
}

TEST(HeatCapacityRatio, AssignmentOperatorDivision) {
  HeatCapacityRatio heat_capacity_ratio{8.0};
  heat_capacity_ratio /= 2.0;
  EXPECT_EQ(heat_capacity_ratio, HeatCapacityRatio(4.0));
}

TEST(HeatCapacityRatio, AssignmentOperatorMultiplication) {
  HeatCapacityRatio heat_capacity_ratio{4.0};
  heat_capacity_ratio *= 2.0;
  EXPECT_EQ(heat_capacity_ratio, HeatCapacityRatio(8.0));
}

TEST(HeatCapacityRatio, AssignmentOperatorSubtraction) {
  HeatCapacityRatio heat_capacity_ratio{3.0};
  heat_capacity_ratio -= HeatCapacityRatio(2.0);
  EXPECT_EQ(heat_capacity_ratio, HeatCapacityRatio(1.0));
}

TEST(HeatCapacityRatio, ComparisonOperators) {
  const HeatCapacityRatio first{1.0};
  const HeatCapacityRatio second{2.0};
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
  const HeatCapacityRatio first{1.0};
  HeatCapacityRatio second = HeatCapacityRatio::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(HeatCapacityRatio, CopyConstructor) {
  const HeatCapacityRatio first{1.0};
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
  const HeatCapacityRatio first{1.0};
  const HeatCapacityRatio second{1.000001};
  const HeatCapacityRatio third{-1.0};
  const std::hash<HeatCapacityRatio> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(HeatCapacityRatio, JSON) {
  EXPECT_EQ(HeatCapacityRatio(1.0).JSON(), Print(1.0));
}

TEST(HeatCapacityRatio, Mathematics) {
  EXPECT_EQ(std::abs(HeatCapacityRatio(-1.0)), std::abs(-1.0));
  EXPECT_EQ(std::cbrt(HeatCapacityRatio(-8.0)), std::cbrt(-8.0));
  EXPECT_EQ(std::exp(HeatCapacityRatio(2.0)), std::exp(2.0));
  EXPECT_EQ(std::log(HeatCapacityRatio(2.0)), std::log(2.0));
  EXPECT_EQ(std::log2(HeatCapacityRatio(8.0)), std::log2(8.0));
  EXPECT_EQ(std::log10(HeatCapacityRatio(100.0)), std::log10(100.0));
  EXPECT_EQ(std::pow(HeatCapacityRatio(4.0), 3), std::pow(4.0, 3));
  EXPECT_EQ(std::pow(HeatCapacityRatio(4.0), 3L), std::pow(4.0, 3L));
  EXPECT_EQ(std::pow(HeatCapacityRatio(4.0), 3LL), std::pow(4.0, 3LL));
  EXPECT_EQ(std::pow(HeatCapacityRatio(4.0), 3.0F), std::pow(4.0, 3.0F));
  EXPECT_EQ(std::pow(HeatCapacityRatio(4.0), 3.0), std::pow(4.0, 3.0));
  EXPECT_EQ(std::pow(HeatCapacityRatio(4.0), 3.0L), std::pow(4.0, 3.0L));
  EXPECT_EQ(std::sqrt(HeatCapacityRatio(9.0)), std::sqrt(9.0));
}

TEST(HeatCapacityRatio, MoveAssignmentOperator) {
  HeatCapacityRatio first{1.0};
  HeatCapacityRatio second = HeatCapacityRatio::Zero();
  second = std::move(first);
  EXPECT_EQ(second, HeatCapacityRatio(1.0));
}

TEST(HeatCapacityRatio, MoveConstructor) {
  HeatCapacityRatio first{1.0};
  const HeatCapacityRatio second{std::move(first)};
  EXPECT_EQ(second, HeatCapacityRatio(1.0));
}

TEST(HeatCapacityRatio, MutableValue) {
  HeatCapacityRatio heat_capacity_ratio{1.0};
  double& value = heat_capacity_ratio.MutableValue();
  value = 2.0;
  EXPECT_EQ(heat_capacity_ratio.Value(), 2.0);
}

TEST(HeatCapacityRatio, Print) {
  EXPECT_EQ(HeatCapacityRatio(1.0).Print(), Print(1.0));
}

TEST(HeatCapacityRatio, SetValue) {
  HeatCapacityRatio heat_capacity_ratio{1.0};
  heat_capacity_ratio.SetValue(2.0);
  EXPECT_EQ(heat_capacity_ratio.Value(), 2.0);
}

TEST(HeatCapacityRatio, SizeOf) {
  EXPECT_EQ(sizeof(HeatCapacityRatio{}), sizeof(double));
}

TEST(HeatCapacityRatio, StandardConstructor) {
  EXPECT_NO_THROW(HeatCapacityRatio(1.0));
}

TEST(HeatCapacityRatio, Stream) {
  std::ostringstream stream;
  stream << HeatCapacityRatio(1.0);
  EXPECT_EQ(stream.str(), HeatCapacityRatio(1.0).Print());
}

TEST(HeatCapacityRatio, Value) {
  EXPECT_EQ(HeatCapacityRatio(1.0).Value(), 1.0);
}

TEST(HeatCapacityRatio, XML) {
  EXPECT_EQ(HeatCapacityRatio(1.0).XML(), Print(1.0));
}

TEST(HeatCapacityRatio, YAML) {
  EXPECT_EQ(HeatCapacityRatio(1.0).YAML(), Print(1.0));
}

TEST(HeatCapacityRatio, Zero) {
  EXPECT_EQ(HeatCapacityRatio::Zero(), HeatCapacityRatio(0.0));
}

}  // namespace

}  // namespace PhQ
