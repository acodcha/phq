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

#include "../include/PhQ/PoissonRatio.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"

namespace PhQ {

namespace {

TEST(PoissonRatio, ArithmeticOperatorAddition) {
  EXPECT_EQ(PoissonRatio(1.0) + PoissonRatio(2.0), PoissonRatio(3.0));
}

TEST(PoissonRatio, ArithmeticOperatorDivision) {
  EXPECT_EQ(PoissonRatio(8.0) / 2.0, PoissonRatio(4.0));

  EXPECT_EQ(PoissonRatio(8.0) / PoissonRatio(2.0), 4.0);
}

TEST(PoissonRatio, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PoissonRatio(4.0) * 2.0, PoissonRatio(8.0));

  EXPECT_EQ(2.0 * PoissonRatio(4.0), PoissonRatio(8.0));
}

TEST(PoissonRatio, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PoissonRatio(3.0) - PoissonRatio(2.0), PoissonRatio(1.0));
}

TEST(PoissonRatio, AssignmentOperatorAddition) {
  PoissonRatio quantity{1.0};
  quantity += PoissonRatio(2.0);
  EXPECT_EQ(quantity, PoissonRatio(3.0));
}

TEST(PoissonRatio, AssignmentOperatorDivision) {
  PoissonRatio quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, PoissonRatio(4.0));
}

TEST(PoissonRatio, AssignmentOperatorMultiplication) {
  PoissonRatio quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, PoissonRatio(8.0));
}

TEST(PoissonRatio, AssignmentOperatorSubtraction) {
  PoissonRatio quantity{3.0};
  quantity -= PoissonRatio(2.0);
  EXPECT_EQ(quantity, PoissonRatio(1.0));
}

TEST(PoissonRatio, ComparisonOperators) {
  const PoissonRatio first{1.11};
  const PoissonRatio second{2.22};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PoissonRatio, CopyAssignmentOperator) {
  const PoissonRatio first{1.11};
  PoissonRatio second = PoissonRatio::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(PoissonRatio, CopyConstructor) {
  const PoissonRatio first{1.11};
  const PoissonRatio second{first};
  EXPECT_EQ(second, first);
}

TEST(PoissonRatio, DefaultConstructor) {
  EXPECT_NO_THROW(PoissonRatio{});
}

TEST(PoissonRatio, Dimensions) {
  EXPECT_EQ(PoissonRatio::Dimensions(), Dimensionless);
}

TEST(PoissonRatio, Hash) {
  const PoissonRatio first{1.11};
  const PoissonRatio second{1.110001};
  const PoissonRatio third{-1.11};
  const std::hash<PoissonRatio> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PoissonRatio, JSON) {
  EXPECT_EQ(PoissonRatio(1.11).JSON(), "1.110000000000000");
}

TEST(PoissonRatio, MoveAssignmentOperator) {
  PoissonRatio first{1.11};
  PoissonRatio second = PoissonRatio::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PoissonRatio(1.11));
}

TEST(PoissonRatio, MoveConstructor) {
  PoissonRatio first{1.11};
  const PoissonRatio second{std::move(first)};
  EXPECT_EQ(second, PoissonRatio(1.11));
}

TEST(PoissonRatio, MutableValue) {
  PoissonRatio quantity{1.11};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(PoissonRatio, Print) {
  EXPECT_EQ(PoissonRatio(1.11).Print(), "1.110000000000000");
}

TEST(PoissonRatio, SetValue) {
  PoissonRatio quantity{1.11};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(PoissonRatio, SizeOf) {
  EXPECT_EQ(sizeof(PoissonRatio{}), sizeof(double));
}

TEST(PoissonRatio, StandardConstructor) {
  EXPECT_NO_THROW(PoissonRatio(1.11));
}

TEST(PoissonRatio, Stream) {
  std::ostringstream stream;
  stream << PoissonRatio(1.11);
  EXPECT_EQ(stream.str(), PoissonRatio(1.11).Print());
}

TEST(PoissonRatio, Value) {
  EXPECT_EQ(PoissonRatio(1.11).Value(), 1.11);
}

TEST(PoissonRatio, XML) {
  EXPECT_EQ(PoissonRatio(1.11).XML(), "1.110000000000000");
}

TEST(PoissonRatio, YAML) {
  EXPECT_EQ(PoissonRatio(1.11).YAML(), "1.110000000000000");
}

TEST(PoissonRatio, Zero) {
  EXPECT_EQ(PoissonRatio::Zero(), PoissonRatio(0.0));
}

}  // namespace

}  // namespace PhQ
