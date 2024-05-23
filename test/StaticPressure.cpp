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

#include "../include/PhQ/StaticPressure.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Area.hpp"
#include "../include/PhQ/ScalarForce.hpp"
#include "../include/PhQ/Unit/Area.hpp"
#include "../include/PhQ/Unit/Force.hpp"
#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(StaticPressure, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      StaticPressure(1.0, Unit::Pressure::Pascal) + StaticPressure(2.0, Unit::Pressure::Pascal),
      StaticPressure(3.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, ArithmeticOperatorDivision) {
  EXPECT_EQ(StaticPressure(8.0, Unit::Pressure::Pascal) / 2.0,
            StaticPressure(4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      StaticPressure(8.0, Unit::Pressure::Pascal) / StaticPressure(2.0, Unit::Pressure::Pascal),
      4.0);
  EXPECT_EQ(ScalarForce(8.0, Unit::Force::Newton) / Area(4.0, Unit::Area::SquareMetre),
            StaticPressure(2.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(StaticPressure(4.0, Unit::Pressure::Pascal) * 2.0,
            StaticPressure(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(2.0 * StaticPressure(4.0, Unit::Pressure::Pascal),
            StaticPressure(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(StaticPressure(4.0, Unit::Pressure::Pascal) * Area(2.0, Unit::Area::SquareMetre),
            ScalarForce(8.0, Unit::Force::Newton));
  EXPECT_EQ(Area(4.0, Unit::Area::SquareMetre) * StaticPressure(2.0, Unit::Pressure::Pascal),
            ScalarForce(8.0, Unit::Force::Newton));
}

TEST(StaticPressure, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      StaticPressure(3.0, Unit::Pressure::Pascal) - StaticPressure(2.0, Unit::Pressure::Pascal),
      StaticPressure(1.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, AssignmentOperatorAddition) {
  StaticPressure quantity{1.0, Unit::Pressure::Pascal};
  quantity += StaticPressure(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, StaticPressure(3.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, AssignmentOperatorDivision) {
  StaticPressure quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, StaticPressure(4.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, AssignmentOperatorMultiplication) {
  StaticPressure quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, StaticPressure(8.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, AssignmentOperatorSubtraction) {
  StaticPressure quantity{3.0, Unit::Pressure::Pascal};
  quantity -= StaticPressure(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, StaticPressure(1.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, ComparisonOperators) {
  const StaticPressure first{0.1, Unit::Pressure::Pascal};
  const StaticPressure second{0.2, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(StaticPressure, CopyAssignmentOperator) {
  const StaticPressure first{1.0, Unit::Pressure::Pascal};
  StaticPressure second = StaticPressure<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(StaticPressure, CopyConstructor) {
  const StaticPressure first{1.0, Unit::Pressure::Pascal};
  const StaticPressure second{first};
  EXPECT_EQ(second, first);
}

TEST(StaticPressure, Create) {
  constexpr StaticPressure quantity = StaticPressure<>::Create<Unit::Pressure::Pascal>(1.0);
  EXPECT_EQ(quantity, StaticPressure(1.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, DefaultConstructor) {
  EXPECT_NO_THROW(StaticPressure<>{});
}

TEST(StaticPressure, Dimensions) {
  EXPECT_EQ(StaticPressure<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(StaticPressure, Hash) {
  const StaticPressure first{1.0, Unit::Pressure::Kilopascal};
  const StaticPressure second{1.00001, Unit::Pressure::Kilopascal};
  const StaticPressure third{-1.0, Unit::Pressure::Kilopascal};
  const std::hash<StaticPressure<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(StaticPressure, JSON) {
  EXPECT_EQ(StaticPressure(1.0, Unit::Pressure::Pascal).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa\"}");
  EXPECT_EQ(StaticPressure(1.0, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa\"}");
}

TEST(StaticPressure, MiscellaneousConstructors) {
  EXPECT_EQ(
      StaticPressure(ScalarForce(8.0, Unit::Force::Newton), Area(4.0, Unit::Area::SquareMetre)),
      StaticPressure(2.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      Area(ScalarForce(8.0, Unit::Force::Newton), StaticPressure(4.0, Unit::Pressure::Pascal)),
      Area(2.0, Unit::Area::SquareMetre));
  EXPECT_EQ(
      ScalarForce(StaticPressure(4.0, Unit::Pressure::Pascal), Area(2.0, Unit::Area::SquareMetre)),
      ScalarForce(8.0, Unit::Force::Newton));
}

TEST(StaticPressure, MoveAssignmentOperator) {
  StaticPressure first{1.0, Unit::Pressure::Pascal};
  StaticPressure second = StaticPressure<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, StaticPressure(1.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, MoveConstructor) {
  StaticPressure first{1.0, Unit::Pressure::Pascal};
  const StaticPressure second{std::move(first)};
  EXPECT_EQ(second, StaticPressure(1.0, Unit::Pressure::Pascal));
}

TEST(StaticPressure, MutableValue) {
  StaticPressure quantity{1.0, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(StaticPressure, Print) {
  EXPECT_EQ(StaticPressure(1.0, Unit::Pressure::Pascal).Print(), Print(1.0) + " Pa");
  EXPECT_EQ(StaticPressure(1.0, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
            Print(1.0) + " kPa");
}

TEST(StaticPressure, SetValue) {
  StaticPressure quantity{1.0, Unit::Pressure::Pascal};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(StaticPressure, SizeOf) {
  EXPECT_EQ(sizeof(StaticPressure<>{}), sizeof(double));
}

TEST(StaticPressure, StandardConstructor) {
  EXPECT_NO_THROW(StaticPressure(1.0, Unit::Pressure::Kilopascal));
}

TEST(StaticPressure, StaticValue) {
  constexpr StaticPressure quantity = StaticPressure<>::Create<Unit::Pressure::Kilopascal>(1.0);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.0);
}

TEST(StaticPressure, Stream) {
  std::ostringstream stream;
  stream << StaticPressure(1.0, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), StaticPressure(1.0, Unit::Pressure::Pascal).Print());
}

TEST(StaticPressure, Unit) {
  EXPECT_EQ(StaticPressure<>::Unit(), Standard<Unit::Pressure>);
}

TEST(StaticPressure, Value) {
  EXPECT_EQ(StaticPressure(1.0, Unit::Pressure::Pascal).Value(), 1.0);
  EXPECT_EQ(StaticPressure(1.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal), 1.0);
}

TEST(StaticPressure, XML) {
  EXPECT_EQ(StaticPressure(1.0, Unit::Pressure::Pascal).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa</unit>");
  EXPECT_EQ(StaticPressure(1.0, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>" + Print(1.0) + "</value><unit>kPa</unit>");
}

TEST(StaticPressure, YAML) {
  EXPECT_EQ(
      StaticPressure(1.0, Unit::Pressure::Pascal).YAML(), "{value:" + Print(1.0) + ",unit:\"Pa\"}");
  EXPECT_EQ(StaticPressure(1.0, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:" + Print(1.0) + ",unit:\"kPa\"}");
}

TEST(StaticPressure, Zero) {
  EXPECT_EQ(StaticPressure<>::Zero(), StaticPressure(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
