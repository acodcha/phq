// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
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

#include "../include/PhQ/PoissonRatio.hpp"

#include <cmath>
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
  PoissonRatio poisson_ratio{1.0};
  poisson_ratio += PoissonRatio(2.0);
  EXPECT_EQ(poisson_ratio, PoissonRatio(3.0));
}

TEST(PoissonRatio, AssignmentOperatorDivision) {
  PoissonRatio poisson_ratio{8.0};
  poisson_ratio /= 2.0;
  EXPECT_EQ(poisson_ratio, PoissonRatio(4.0));
}

TEST(PoissonRatio, AssignmentOperatorMultiplication) {
  PoissonRatio poisson_ratio{4.0};
  poisson_ratio *= 2.0;
  EXPECT_EQ(poisson_ratio, PoissonRatio(8.0));
}

TEST(PoissonRatio, AssignmentOperatorSubtraction) {
  PoissonRatio poisson_ratio{3.0};
  poisson_ratio -= PoissonRatio(2.0);
  EXPECT_EQ(poisson_ratio, PoissonRatio(1.0));
}

TEST(PoissonRatio, ComparisonOperators) {
  const PoissonRatio first{1.0};
  const PoissonRatio second{2.0};
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
  {
    const PoissonRatio<float> first(1.0F);
    PoissonRatio<double> second = PoissonRatio<double>::Zero();
    second = first;
    EXPECT_EQ(second, PoissonRatio<double>(1.0));
  }
  {
    const PoissonRatio<double> first(1.0);
    PoissonRatio<double> second = PoissonRatio<double>::Zero();
    second = first;
    EXPECT_EQ(second, PoissonRatio<double>(1.0));
  }
  {
    const PoissonRatio<long double> first(1.0L);
    PoissonRatio<double> second = PoissonRatio<double>::Zero();
    second = first;
    EXPECT_EQ(second, PoissonRatio<double>(1.0));
  }
}

TEST(PoissonRatio, CopyConstructor) {
  {
    const PoissonRatio<float> first(1.0F);
    const PoissonRatio<double> second{first};
    EXPECT_EQ(second, PoissonRatio<double>(1.0));
  }
  {
    const PoissonRatio<double> first(1.0);
    const PoissonRatio<double> second{first};
    EXPECT_EQ(second, PoissonRatio<double>(1.0));
  }
  {
    const PoissonRatio<long double> first(1.0L);
    const PoissonRatio<double> second{first};
    EXPECT_EQ(second, PoissonRatio<double>(1.0));
  }
}

TEST(PoissonRatio, DefaultConstructor) {
  EXPECT_NO_THROW(PoissonRatio<>{});
}

TEST(PoissonRatio, Dimensions) {
  EXPECT_EQ(PoissonRatio<>::Dimensions(), Dimensionless);
}

TEST(PoissonRatio, Hash) {
  const PoissonRatio first{1.0};
  const PoissonRatio second{1.00001};
  const PoissonRatio third{-1.0};
  const std::hash<PoissonRatio<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PoissonRatio, JSON) {
  EXPECT_EQ(PoissonRatio(1.0).JSON(), Print(1.0));
}

TEST(PoissonRatio, Mathematics) {
  EXPECT_EQ(std::abs(PoissonRatio(-1.0)), std::abs(-1.0));
  EXPECT_EQ(std::cbrt(PoissonRatio(-8.0)), std::cbrt(-8.0));
  EXPECT_EQ(std::exp(PoissonRatio(2.0)), std::exp(2.0));
  EXPECT_EQ(std::log(PoissonRatio(2.0)), std::log(2.0));
  EXPECT_EQ(std::log2(PoissonRatio(8.0)), std::log2(8.0));
  EXPECT_EQ(std::log10(PoissonRatio(100.0)), std::log10(100.0));
  EXPECT_EQ(std::pow(PoissonRatio(4.0), 3), std::pow(4.0, 3));
  EXPECT_EQ(std::pow(PoissonRatio(4.0), 3L), std::pow(4.0, 3L));
  EXPECT_EQ(std::pow(PoissonRatio(4.0), 3LL), std::pow(4.0, 3LL));
  EXPECT_EQ(std::pow(PoissonRatio(4.0), 3.0F), std::pow(4.0, 3.0F));
  EXPECT_EQ(std::pow(PoissonRatio(4.0), 3.0), std::pow(4.0, 3.0));
  EXPECT_EQ(std::pow(PoissonRatio(4.0), 3.0L), std::pow(4.0, 3.0L));
  EXPECT_EQ(std::sqrt(PoissonRatio(9.0)), std::sqrt(9.0));
}

TEST(PoissonRatio, MoveAssignmentOperator) {
  PoissonRatio first{1.0};
  PoissonRatio second = PoissonRatio<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PoissonRatio(1.0));
}

TEST(PoissonRatio, MoveConstructor) {
  PoissonRatio first{1.0};
  const PoissonRatio second{std::move(first)};
  EXPECT_EQ(second, PoissonRatio(1.0));
}

TEST(PoissonRatio, MutableValue) {
  PoissonRatio poisson_ratio{1.0};
  double& value = poisson_ratio.MutableValue();
  value = 2.0;
  EXPECT_EQ(poisson_ratio.Value(), 2.0);
}

TEST(PoissonRatio, Print) {
  EXPECT_EQ(PoissonRatio(1.0).Print(), Print(1.0));
}

TEST(PoissonRatio, SetValue) {
  PoissonRatio poisson_ratio{1.0};
  poisson_ratio.SetValue(2.0);
  EXPECT_EQ(poisson_ratio.Value(), 2.0);
}

TEST(PoissonRatio, SizeOf) {
  EXPECT_EQ(sizeof(PoissonRatio<>{}), sizeof(double));
}

TEST(PoissonRatio, StandardConstructor) {
  EXPECT_NO_THROW(PoissonRatio(1.0));
}

TEST(PoissonRatio, Stream) {
  std::ostringstream stream;
  stream << PoissonRatio(1.0);
  EXPECT_EQ(stream.str(), PoissonRatio(1.0).Print());
}

TEST(PoissonRatio, Value) {
  EXPECT_EQ(PoissonRatio(1.0).Value(), 1.0);
}

TEST(PoissonRatio, XML) {
  EXPECT_EQ(PoissonRatio(1.0).XML(), Print(1.0));
}

TEST(PoissonRatio, YAML) {
  EXPECT_EQ(PoissonRatio(1.0).YAML(), Print(1.0));
}

TEST(PoissonRatio, Zero) {
  EXPECT_EQ(PoissonRatio<>::Zero(), PoissonRatio(0.0));
}

}  // namespace

}  // namespace PhQ
