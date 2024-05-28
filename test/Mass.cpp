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

#include "../include/PhQ/Mass.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Mass.hpp"

namespace PhQ {

namespace {

TEST(Mass, ArithmeticOperatorAddition) {
  EXPECT_EQ(Mass(1.0, Unit::Mass::Kilogram) + Mass(2.0, Unit::Mass::Kilogram),
            Mass(3.0, Unit::Mass::Kilogram));
}

TEST(Mass, ArithmeticOperatorDivision) {
  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram) / 2.0, Mass(4.0, Unit::Mass::Kilogram));
  EXPECT_EQ(Mass(8.0, Unit::Mass::Kilogram) / Mass(2.0, Unit::Mass::Kilogram), 4.0);
}

TEST(Mass, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Mass(4.0, Unit::Mass::Kilogram) * 2.0, Mass(8.0, Unit::Mass::Kilogram));
  EXPECT_EQ(2.0 * Mass(4.0, Unit::Mass::Kilogram), Mass(8.0, Unit::Mass::Kilogram));
}

TEST(Mass, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Mass(3.0, Unit::Mass::Kilogram) - Mass(2.0, Unit::Mass::Kilogram),
            Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, AssignmentOperatorAddition) {
  Mass mass{1.0, Unit::Mass::Kilogram};
  mass += Mass(2.0, Unit::Mass::Kilogram);
  EXPECT_EQ(mass, Mass(3.0, Unit::Mass::Kilogram));
}

TEST(Mass, AssignmentOperatorDivision) {
  Mass mass{8.0, Unit::Mass::Kilogram};
  mass /= 2.0;
  EXPECT_EQ(mass, Mass(4.0, Unit::Mass::Kilogram));
}

TEST(Mass, AssignmentOperatorMultiplication) {
  Mass mass{4.0, Unit::Mass::Kilogram};
  mass *= 2.0;
  EXPECT_EQ(mass, Mass(8.0, Unit::Mass::Kilogram));
}

TEST(Mass, AssignmentOperatorSubtraction) {
  Mass mass{3.0, Unit::Mass::Kilogram};
  mass -= Mass(2.0, Unit::Mass::Kilogram);
  EXPECT_EQ(mass, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, ComparisonOperators) {
  const Mass first{1.0, Unit::Mass::Kilogram};
  const Mass second{2.0, Unit::Mass::Kilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Mass, Constructor) {
  EXPECT_NO_THROW(Mass(1.0, Unit::Mass::Gram));
}

TEST(Mass, CopyAssignmentOperator) {
  {
    const Mass<float> first(1.0F, Unit::Mass::Kilogram);
    Mass<double> second = Mass<double>::Zero();
    second = first;
    EXPECT_EQ(second, Mass<double>(1.0, Unit::Mass::Kilogram));
  }
  {
    const Mass<double> first(1.0, Unit::Mass::Kilogram);
    Mass<double> second = Mass<double>::Zero();
    second = first;
    EXPECT_EQ(second, Mass<double>(1.0, Unit::Mass::Kilogram));
  }
  {
    const Mass<long double> first(1.0L, Unit::Mass::Kilogram);
    Mass<double> second = Mass<double>::Zero();
    second = first;
    EXPECT_EQ(second, Mass<double>(1.0, Unit::Mass::Kilogram));
  }
}

TEST(Mass, CopyConstructor) {
  {
    const Mass<float> first(1.0F, Unit::Mass::Kilogram);
    const Mass<double> second{first};
    EXPECT_EQ(second, Mass<double>(1.0, Unit::Mass::Kilogram));
  }
  {
    const Mass<double> first(1.0, Unit::Mass::Kilogram);
    const Mass<double> second{first};
    EXPECT_EQ(second, Mass<double>(1.0, Unit::Mass::Kilogram));
  }
  {
    const Mass<long double> first(1.0L, Unit::Mass::Kilogram);
    const Mass<double> second{first};
    EXPECT_EQ(second, Mass<double>(1.0, Unit::Mass::Kilogram));
  }
}

TEST(Mass, Create) {
  constexpr Mass mass = Mass<>::Create<Unit::Mass::Kilogram>(1.0);
  EXPECT_EQ(mass, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, DefaultConstructor) {
  EXPECT_NO_THROW(Mass<>{});
}

TEST(Mass, Dimensions) {
  EXPECT_EQ(Mass<>::Dimensions(), RelatedDimensions<Unit::Mass>);
}

TEST(Mass, Hash) {
  const Mass first{1.0, Unit::Mass::Gram};
  const Mass second{1.00001, Unit::Mass::Gram};
  const Mass third{-1.0, Unit::Mass::Gram};
  const std::hash<Mass<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Mass, JSON) {
  EXPECT_EQ(
      Mass(1.0, Unit::Mass::Kilogram).JSON(), "{\"value\":" + Print(1.0) + ",\"unit\":\"kg\"}");
  EXPECT_EQ(Mass(1.0, Unit::Mass::Gram).JSON(Unit::Mass::Gram),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"g\"}");
}

TEST(Mass, MoveAssignmentOperator) {
  Mass first{1.0, Unit::Mass::Kilogram};
  Mass second = Mass<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, MoveConstructor) {
  Mass first{1.0, Unit::Mass::Kilogram};
  const Mass second{std::move(first)};
  EXPECT_EQ(second, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, MutableValue) {
  Mass mass{1.0, Unit::Mass::Kilogram};
  double& value = mass.MutableValue();
  value = 2.0;
  EXPECT_EQ(mass.Value(), 2.0);
}

TEST(Mass, Print) {
  EXPECT_EQ(Mass(1.0, Unit::Mass::Kilogram).Print(), Print(1.0) + " kg");
  EXPECT_EQ(Mass(1.0, Unit::Mass::Gram).Print(Unit::Mass::Gram), Print(1.0) + " g");
}

TEST(Mass, SetValue) {
  Mass mass{1.0, Unit::Mass::Kilogram};
  mass.SetValue(2.0);
  EXPECT_EQ(mass.Value(), 2.0);
}

TEST(Mass, SizeOf) {
  EXPECT_EQ(sizeof(Mass<>{}), sizeof(double));
}

TEST(Mass, StaticValue) {
  constexpr Mass mass = Mass<>::Create<Unit::Mass::Gram>(1.0);
  constexpr double value = mass.StaticValue<Unit::Mass::Gram>();
  EXPECT_EQ(value, 1.0);
}

TEST(Mass, Stream) {
  std::ostringstream stream;
  stream << Mass(1.0, Unit::Mass::Kilogram);
  EXPECT_EQ(stream.str(), Mass(1.0, Unit::Mass::Kilogram).Print());
}

TEST(Mass, Unit) {
  EXPECT_EQ(Mass<>::Unit(), Standard<Unit::Mass>);
}

TEST(Mass, Value) {
  EXPECT_EQ(Mass(1.0, Unit::Mass::Kilogram).Value(), 1.0);
  EXPECT_EQ(Mass(1.0, Unit::Mass::Gram).Value(Unit::Mass::Gram), 1.0);
}

TEST(Mass, XML) {
  EXPECT_EQ(
      Mass(1.0, Unit::Mass::Kilogram).XML(), "<value>" + Print(1.0) + "</value><unit>kg</unit>");
  EXPECT_EQ(Mass(1.0, Unit::Mass::Gram).XML(Unit::Mass::Gram),
            "<value>" + Print(1.0) + "</value><unit>g</unit>");
}

TEST(Mass, YAML) {
  EXPECT_EQ(Mass(1.0, Unit::Mass::Kilogram).YAML(), "{value:" + Print(1.0) + ",unit:\"kg\"}");
  EXPECT_EQ(
      Mass(1.0, Unit::Mass::Gram).YAML(Unit::Mass::Gram), "{value:" + Print(1.0) + ",unit:\"g\"}");
}

TEST(Mass, Zero) {
  EXPECT_EQ(Mass<>::Zero(), Mass(0.0, Unit::Mass::Kilogram));
}

}  // namespace

}  // namespace PhQ
