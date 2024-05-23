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

#include "../include/PhQ/ScalarForce.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Force.hpp"

namespace PhQ {

namespace {

TEST(ScalarForce, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Newton) + ScalarForce(2.0, Unit::Force::Newton),
            ScalarForce(3.0, Unit::Force::Newton));
}

TEST(ScalarForce, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarForce(8.0, Unit::Force::Newton) / 2.0, ScalarForce(4.0, Unit::Force::Newton));
  EXPECT_EQ(ScalarForce(8.0, Unit::Force::Newton) / ScalarForce(2.0, Unit::Force::Newton), 4.0);
}

TEST(ScalarForce, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarForce(4.0, Unit::Force::Newton) * 2.0, ScalarForce(8.0, Unit::Force::Newton));
  EXPECT_EQ(2.0 * ScalarForce(4.0, Unit::Force::Newton), ScalarForce(8.0, Unit::Force::Newton));
}

TEST(ScalarForce, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarForce(3.0, Unit::Force::Newton) - ScalarForce(2.0, Unit::Force::Newton),
            ScalarForce(1.0, Unit::Force::Newton));
}

TEST(ScalarForce, AssignmentOperatorAddition) {
  ScalarForce quantity{1.0, Unit::Force::Newton};
  quantity += ScalarForce(2.0, Unit::Force::Newton);
  EXPECT_EQ(quantity, ScalarForce(3.0, Unit::Force::Newton));
}

TEST(ScalarForce, AssignmentOperatorDivision) {
  ScalarForce quantity{8.0, Unit::Force::Newton};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarForce(4.0, Unit::Force::Newton));
}

TEST(ScalarForce, AssignmentOperatorMultiplication) {
  ScalarForce quantity{4.0, Unit::Force::Newton};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarForce(8.0, Unit::Force::Newton));
}

TEST(ScalarForce, AssignmentOperatorSubtraction) {
  ScalarForce quantity{3.0, Unit::Force::Newton};
  quantity -= ScalarForce(2.0, Unit::Force::Newton);
  EXPECT_EQ(quantity, ScalarForce(1.0, Unit::Force::Newton));
}

TEST(ScalarForce, ComparisonOperators) {
  const ScalarForce first{1.0, Unit::Force::Newton};
  const ScalarForce second{2.0, Unit::Force::Newton};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarForce, CopyAssignmentOperator) {
  const ScalarForce first{1.0, Unit::Force::Newton};
  ScalarForce second = ScalarForce<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ScalarForce, CopyConstructor) {
  const ScalarForce first{1.0, Unit::Force::Newton};
  const ScalarForce second{first};
  EXPECT_EQ(second, first);
}

TEST(ScalarForce, Create) {
  constexpr ScalarForce quantity = ScalarForce<>::Create<Unit::Force::Newton>(1.0);
  EXPECT_EQ(quantity, ScalarForce(1.0, Unit::Force::Newton));
}

TEST(ScalarForce, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarForce<>{});
}

TEST(ScalarForce, Dimensions) {
  EXPECT_EQ(ScalarForce<>::Dimensions(), RelatedDimensions<Unit::Force>);
}

TEST(ScalarForce, Hash) {
  const ScalarForce first{1.0, Unit::Force::Micronewton};
  const ScalarForce second{1.00001, Unit::Force::Micronewton};
  const ScalarForce third{-1.0, Unit::Force::Micronewton};
  const std::hash<ScalarForce<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarForce, JSON) {
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Newton).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"N\"}");
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Micronewton).JSON(Unit::Force::Micronewton),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"μN\"}");
}

TEST(ScalarForce, MoveAssignmentOperator) {
  ScalarForce first{1.0, Unit::Force::Newton};
  ScalarForce second = ScalarForce<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarForce(1.0, Unit::Force::Newton));
}

TEST(ScalarForce, MoveConstructor) {
  ScalarForce first{1.0, Unit::Force::Newton};
  const ScalarForce second{std::move(first)};
  EXPECT_EQ(second, ScalarForce(1.0, Unit::Force::Newton));
}

TEST(ScalarForce, MutableValue) {
  ScalarForce quantity{1.0, Unit::Force::Newton};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarForce, Print) {
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Newton).Print(), Print(1.0) + " N");
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Micronewton).Print(Unit::Force::Micronewton),
            Print(1.0) + " μN");
}

TEST(ScalarForce, SetValue) {
  ScalarForce quantity{1.0, Unit::Force::Newton};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarForce, SizeOf) {
  EXPECT_EQ(sizeof(ScalarForce<>{}), sizeof(double));
}

TEST(ScalarForce, StandardConstructor) {
  EXPECT_NO_THROW(ScalarForce(1.0, Unit::Force::Micronewton));
}

TEST(ScalarForce, StaticValue) {
  constexpr ScalarForce quantity = ScalarForce<>::Create<Unit::Force::Micronewton>(2.0);
  constexpr double value = quantity.StaticValue<Unit::Force::Micronewton>();
  EXPECT_EQ(value, 2.0);
}

TEST(ScalarForce, Stream) {
  std::ostringstream stream;
  stream << ScalarForce(1.0, Unit::Force::Newton);
  EXPECT_EQ(stream.str(), ScalarForce(1.0, Unit::Force::Newton).Print());
}

TEST(ScalarForce, Unit) {
  EXPECT_EQ(ScalarForce<>::Unit(), Standard<Unit::Force>);
}

TEST(ScalarForce, Value) {
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Newton).Value(), 1.0);
  EXPECT_EQ(ScalarForce(2.0, Unit::Force::Micronewton).Value(Unit::Force::Micronewton), 2.0);
}

TEST(ScalarForce, XML) {
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Newton).XML(),
            "<value>" + Print(1.0) + "</value><unit>N</unit>");
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Micronewton).XML(Unit::Force::Micronewton),
            "<value>" + Print(1.0) + "</value><unit>μN</unit>");
}

TEST(ScalarForce, YAML) {
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Newton).YAML(), "{value:" + Print(1.0) + ",unit:\"N\"}");
  EXPECT_EQ(ScalarForce(1.0, Unit::Force::Micronewton).YAML(Unit::Force::Micronewton),
            "{value:" + Print(1.0) + ",unit:\"μN\"}");
}

TEST(ScalarForce, Zero) {
  EXPECT_EQ(ScalarForce<>::Zero(), ScalarForce(0.0, Unit::Force::Newton));
}

}  // namespace

}  // namespace PhQ
