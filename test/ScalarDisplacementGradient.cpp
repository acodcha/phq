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

#include "../include/PhQ/ScalarDisplacementGradient.hpp"

#include <cmath>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Dimensions.hpp"

namespace PhQ {

namespace {

TEST(ScalarDisplacementGradient, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarDisplacementGradient(1.0) + ScalarDisplacementGradient(2.0),
            ScalarDisplacementGradient(3.0));
}

TEST(ScalarDisplacementGradient, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarDisplacementGradient(8.0) / 2.0, ScalarDisplacementGradient(4.0));
  EXPECT_EQ(ScalarDisplacementGradient(8.0) / ScalarDisplacementGradient(2.0), 4.0);
}

TEST(ScalarDisplacementGradient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarDisplacementGradient(4.0) * 2.0, ScalarDisplacementGradient(8.0));
  EXPECT_EQ(2.0 * ScalarDisplacementGradient(4.0), ScalarDisplacementGradient(8.0));
}

TEST(ScalarDisplacementGradient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarDisplacementGradient(3.0) - ScalarDisplacementGradient(2.0),
            ScalarDisplacementGradient(1.0));
}

TEST(ScalarDisplacementGradient, AssignmentOperatorAddition) {
  ScalarDisplacementGradient quantity{1.0};
  quantity += ScalarDisplacementGradient(2.0);
  EXPECT_EQ(quantity, ScalarDisplacementGradient(3.0));
}

TEST(ScalarDisplacementGradient, AssignmentOperatorDivision) {
  ScalarDisplacementGradient quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarDisplacementGradient(4.0));
}

TEST(ScalarDisplacementGradient, AssignmentOperatorMultiplication) {
  ScalarDisplacementGradient quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarDisplacementGradient(8.0));
}

TEST(ScalarDisplacementGradient, AssignmentOperatorSubtraction) {
  ScalarDisplacementGradient quantity{3.0};
  quantity -= ScalarDisplacementGradient(2.0);
  EXPECT_EQ(quantity, ScalarDisplacementGradient(1.0));
}

TEST(ScalarDisplacementGradient, ComparisonOperators) {
  const ScalarDisplacementGradient first{1.0};
  const ScalarDisplacementGradient second{2.0};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarDisplacementGradient, Constructor) {
  EXPECT_NO_THROW(ScalarDisplacementGradient(1.0));
}

TEST(ScalarDisplacementGradient, CopyAssignmentOperator) {
  {
    const ScalarDisplacementGradient<float> first(1.0F);
    ScalarDisplacementGradient<double> second = ScalarDisplacementGradient<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarDisplacementGradient<double>(1.0));
  }
  {
    const ScalarDisplacementGradient<double> first(1.0);
    ScalarDisplacementGradient<double> second = ScalarDisplacementGradient<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarDisplacementGradient<double>(1.0));
  }
  {
    const ScalarDisplacementGradient<long double> first(1.0L);
    ScalarDisplacementGradient<double> second = ScalarDisplacementGradient<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarDisplacementGradient<double>(1.0));
  }
}

TEST(ScalarDisplacementGradient, CopyConstructor) {
  {
    const ScalarDisplacementGradient<float> first(1.0F);
    const ScalarDisplacementGradient<double> second{first};
    EXPECT_EQ(second, ScalarDisplacementGradient<double>(1.0));
  }
  {
    const ScalarDisplacementGradient<double> first(1.0);
    const ScalarDisplacementGradient<double> second{first};
    EXPECT_EQ(second, ScalarDisplacementGradient<double>(1.0));
  }
  {
    const ScalarDisplacementGradient<long double> first(1.0L);
    const ScalarDisplacementGradient<double> second{first};
    EXPECT_EQ(second, ScalarDisplacementGradient<double>(1.0));
  }
}

TEST(ScalarDisplacementGradient, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarDisplacementGradient<>{});
}

TEST(ScalarDisplacementGradient, Dimensions) {
  EXPECT_EQ(ScalarDisplacementGradient<>::Dimensions(), Dimensionless);
}

TEST(ScalarDisplacementGradient, Hash) {
  const ScalarDisplacementGradient first{1.0};
  const ScalarDisplacementGradient second{1.00001};
  const ScalarDisplacementGradient third{-1.0};
  const std::hash<ScalarDisplacementGradient<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarDisplacementGradient, JSON) {
  EXPECT_EQ(ScalarDisplacementGradient(1.0).JSON(), Print(1.0));
}

TEST(ScalarDisplacementGradient, Mathematics) {
  EXPECT_EQ(std::abs(ScalarDisplacementGradient(-1.0)), std::abs(-1.0));
  EXPECT_EQ(std::cbrt(ScalarDisplacementGradient(-8.0)), std::cbrt(-8.0));
  EXPECT_EQ(std::exp(ScalarDisplacementGradient(2.0)), std::exp(2.0));
  EXPECT_EQ(std::log(ScalarDisplacementGradient(2.0)), std::log(2.0));
  EXPECT_EQ(std::log2(ScalarDisplacementGradient(8.0)), std::log2(8.0));
  EXPECT_EQ(std::log10(ScalarDisplacementGradient(100.0)), std::log10(100.0));
  EXPECT_EQ(std::pow(ScalarDisplacementGradient(4.0), 3), std::pow(4.0, 3));
  EXPECT_EQ(std::pow(ScalarDisplacementGradient(4.0), 3L), std::pow(4.0, 3L));
  EXPECT_EQ(std::pow(ScalarDisplacementGradient(4.0), 3LL), std::pow(4.0, 3LL));
  EXPECT_EQ(std::pow(ScalarDisplacementGradient(4.0), 3.0F), std::pow(4.0, 3.0F));
  EXPECT_EQ(std::pow(ScalarDisplacementGradient(4.0), 3.0), std::pow(4.0, 3.0));
  EXPECT_EQ(std::pow(ScalarDisplacementGradient(4.0), 3.0L), std::pow(4.0, 3.0L));
  EXPECT_EQ(std::sqrt(ScalarDisplacementGradient(9.0)), std::sqrt(9.0));
}

TEST(ScalarDisplacementGradient, MoveAssignmentOperator) {
  ScalarDisplacementGradient first{1.0};
  ScalarDisplacementGradient second = ScalarDisplacementGradient<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarDisplacementGradient(1.0));
}

TEST(ScalarDisplacementGradient, MoveConstructor) {
  ScalarDisplacementGradient first{1.0};
  const ScalarDisplacementGradient second{std::move(first)};
  EXPECT_EQ(second, ScalarDisplacementGradient(1.0));
}

TEST(ScalarDisplacementGradient, MutableValue) {
  ScalarDisplacementGradient quantity{1.0};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarDisplacementGradient, Print) {
  EXPECT_EQ(ScalarDisplacementGradient(1.0).Print(), Print(1.0));
}

TEST(ScalarDisplacementGradient, SetValue) {
  ScalarDisplacementGradient quantity{1.0};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarDisplacementGradient, SizeOf) {
  EXPECT_EQ(sizeof(ScalarDisplacementGradient<>{}), sizeof(double));
}

TEST(ScalarDisplacementGradient, Stream) {
  std::ostringstream stream;
  stream << ScalarDisplacementGradient(1.0);
  EXPECT_EQ(stream.str(), ScalarDisplacementGradient(1.0).Print());
}

TEST(ScalarDisplacementGradient, Value) {
  EXPECT_EQ(ScalarDisplacementGradient(1.0).Value(), 1.0);
}

TEST(ScalarDisplacementGradient, XML) {
  EXPECT_EQ(ScalarDisplacementGradient(1.0).XML(), Print(1.0));
}

TEST(ScalarDisplacementGradient, YAML) {
  EXPECT_EQ(ScalarDisplacementGradient(1.0).YAML(), Print(1.0));
}

TEST(ScalarDisplacementGradient, Zero) {
  EXPECT_EQ(ScalarDisplacementGradient<>::Zero(), ScalarDisplacementGradient(0.0));
}

}  // namespace

}  // namespace PhQ
