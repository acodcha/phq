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

#include "../include/PhQ/ScalarStrain.hpp"

#include <cmath>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"

namespace PhQ {

namespace {

TEST(ScalarStrain, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarStrain(1.0) + ScalarStrain(2.0), ScalarStrain(3.0));
}

TEST(ScalarStrain, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarStrain(8.0) / 2.0, ScalarStrain(4.0));
  EXPECT_EQ(ScalarStrain(8.0) / ScalarStrain(2.0), 4.0);
}

TEST(ScalarStrain, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarStrain(4.0) * 2.0, ScalarStrain(8.0));
  EXPECT_EQ(2.0 * ScalarStrain(4.0), ScalarStrain(8.0));
}

TEST(ScalarStrain, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarStrain(3.0) - ScalarStrain(2.0), ScalarStrain(1.0));
}

TEST(ScalarStrain, AssignmentOperatorAddition) {
  ScalarStrain quantity{1.0};
  quantity += ScalarStrain(2.0);
  EXPECT_EQ(quantity, ScalarStrain(3.0));
}

TEST(ScalarStrain, AssignmentOperatorDivision) {
  ScalarStrain quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarStrain(4.0));
}

TEST(ScalarStrain, AssignmentOperatorMultiplication) {
  ScalarStrain quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarStrain(8.0));
}

TEST(ScalarStrain, AssignmentOperatorSubtraction) {
  ScalarStrain quantity{3.0};
  quantity -= ScalarStrain(2.0);
  EXPECT_EQ(quantity, ScalarStrain(1.0));
}

TEST(ScalarStrain, ComparisonOperators) {
  const ScalarStrain first{1.0};
  const ScalarStrain second{2.0};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarStrain, Constructor) {
  EXPECT_NO_THROW(ScalarStrain(1.0));
}

TEST(ScalarStrain, CopyAssignmentOperator) {
  {
    const ScalarStrain<float> first(1.0F);
    ScalarStrain<double> second = ScalarStrain<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarStrain<double>(1.0));
  }
  {
    const ScalarStrain<double> first(1.0);
    ScalarStrain<double> second = ScalarStrain<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarStrain<double>(1.0));
  }
  {
    const ScalarStrain<long double> first(1.0L);
    ScalarStrain<double> second = ScalarStrain<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarStrain<double>(1.0));
  }
}

TEST(ScalarStrain, CopyConstructor) {
  {
    const ScalarStrain<float> first(1.0F);
    const ScalarStrain<double> second{first};
    EXPECT_EQ(second, ScalarStrain<double>(1.0));
  }
  {
    const ScalarStrain<double> first(1.0);
    const ScalarStrain<double> second{first};
    EXPECT_EQ(second, ScalarStrain<double>(1.0));
  }
  {
    const ScalarStrain<long double> first(1.0L);
    const ScalarStrain<double> second{first};
    EXPECT_EQ(second, ScalarStrain<double>(1.0));
  }
}

TEST(ScalarStrain, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarStrain<>{});
}

TEST(ScalarStrain, Dimensions) {
  EXPECT_EQ(ScalarStrain<>::Dimensions(), Dimensionless);
}

TEST(ScalarStrain, Hash) {
  const ScalarStrain first{1.0};
  const ScalarStrain second{1.00001};
  const ScalarStrain third{-1.0};
  const std::hash<ScalarStrain<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarStrain, JSON) {
  EXPECT_EQ(ScalarStrain(1.0).JSON(), Print(1.0));
}

TEST(ScalarStrain, Mathematics) {
  EXPECT_EQ(std::abs(ScalarStrain(-1.0)), std::abs(-1.0));
  EXPECT_EQ(std::cbrt(ScalarStrain(-8.0)), std::cbrt(-8.0));
  EXPECT_EQ(std::exp(ScalarStrain(2.0)), std::exp(2.0));
  EXPECT_EQ(std::log(ScalarStrain(2.0)), std::log(2.0));
  EXPECT_EQ(std::log2(ScalarStrain(8.0)), std::log2(8.0));
  EXPECT_EQ(std::log10(ScalarStrain(100.0)), std::log10(100.0));
  EXPECT_EQ(std::pow(ScalarStrain(4.0), 3), std::pow(4.0, 3));
  EXPECT_EQ(std::pow(ScalarStrain(4.0), 3L), std::pow(4.0, 3L));
  EXPECT_EQ(std::pow(ScalarStrain(4.0), 3LL), std::pow(4.0, 3LL));
  EXPECT_EQ(std::pow(ScalarStrain(4.0), 3.0F), std::pow(4.0, 3.0F));
  EXPECT_EQ(std::pow(ScalarStrain(4.0), 3.0), std::pow(4.0, 3.0));
  EXPECT_EQ(std::pow(ScalarStrain(4.0), 3.0L), std::pow(4.0, 3.0L));
  EXPECT_EQ(std::sqrt(ScalarStrain(9.0)), std::sqrt(9.0));
}

TEST(ScalarStrain, MoveAssignmentOperator) {
  ScalarStrain first{1.0};
  ScalarStrain second = ScalarStrain<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarStrain(1.0));
}

TEST(ScalarStrain, MoveConstructor) {
  ScalarStrain first{1.0};
  const ScalarStrain second{std::move(first)};
  EXPECT_EQ(second, ScalarStrain(1.0));
}

TEST(ScalarStrain, MutableValue) {
  ScalarStrain quantity{1.0};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarStrain, Print) {
  EXPECT_EQ(ScalarStrain(1.0).Print(), Print(1.0));
}

TEST(ScalarStrain, SetValue) {
  ScalarStrain quantity{1.0};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarStrain, SizeOf) {
  EXPECT_EQ(sizeof(ScalarStrain<>{}), sizeof(double));
}

TEST(ScalarStrain, Stream) {
  std::ostringstream stream;
  stream << ScalarStrain(1.0);
  EXPECT_EQ(stream.str(), ScalarStrain(1.0).Print());
}

TEST(ScalarStrain, Value) {
  EXPECT_EQ(ScalarStrain(1.0).Value(), 1.0);
}

TEST(ScalarStrain, XML) {
  EXPECT_EQ(ScalarStrain(1.0).XML(), Print(1.0));
}

TEST(ScalarStrain, YAML) {
  EXPECT_EQ(ScalarStrain(1.0).YAML(), Print(1.0));
}

TEST(ScalarStrain, Zero) {
  EXPECT_EQ(ScalarStrain<>::Zero(), ScalarStrain(0.0));
}

}  // namespace

}  // namespace PhQ
