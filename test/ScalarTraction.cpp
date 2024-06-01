// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/ScalarTraction.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(ScalarTraction, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      ScalarTraction(1.0, Unit::Pressure::Pascal) + ScalarTraction(2.0, Unit::Pressure::Pascal),
      ScalarTraction(3.0, Unit::Pressure::Pascal));
}

TEST(ScalarTraction, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarTraction(8.0, Unit::Pressure::Pascal) / 2.0,
            ScalarTraction(4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      ScalarTraction(8.0, Unit::Pressure::Pascal) / ScalarTraction(2.0, Unit::Pressure::Pascal),
      4.0);
}

TEST(ScalarTraction, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarTraction(4.0, Unit::Pressure::Pascal) * 2.0,
            ScalarTraction(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(2.0 * ScalarTraction(4.0, Unit::Pressure::Pascal),
            ScalarTraction(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(ScalarTraction(4.0, Unit::Pressure::Pascal) * Area(2.0, Unit::Area::SquareMetre),
            ScalarForce(8.0, Unit::Force::Newton));
  EXPECT_EQ(Area(4.0, Unit::Area::SquareMetre) * ScalarTraction(2.0, Unit::Pressure::Pascal),
            ScalarForce(8.0, Unit::Force::Newton));
}

TEST(ScalarTraction, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      ScalarTraction(3.0, Unit::Pressure::Pascal) - ScalarTraction(2.0, Unit::Pressure::Pascal),
      ScalarTraction(1.0, Unit::Pressure::Pascal));
}

TEST(ScalarTraction, AssignmentOperatorAddition) {
  ScalarTraction quantity{1.0, Unit::Pressure::Pascal};
  quantity += ScalarTraction(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, ScalarTraction(3.0, Unit::Pressure::Pascal));
}

TEST(ScalarTraction, AssignmentOperatorDivision) {
  ScalarTraction quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarTraction(4.0, Unit::Pressure::Pascal));
}

TEST(ScalarTraction, AssignmentOperatorMultiplication) {
  ScalarTraction quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarTraction(8.0, Unit::Pressure::Pascal));
}

TEST(ScalarTraction, AssignmentOperatorSubtraction) {
  ScalarTraction quantity{3.0, Unit::Pressure::Pascal};
  quantity -= ScalarTraction(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, ScalarTraction(1.0, Unit::Pressure::Pascal));
}

TEST(ScalarTraction, ComparisonOperators) {
  const ScalarTraction first{1.0, Unit::Pressure::Pascal};
  const ScalarTraction second{2.0, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarTraction, Constructor) {
  EXPECT_NO_THROW(ScalarTraction(1.0, Unit::Pressure::Kilopascal));
  EXPECT_EQ(
      ScalarTraction(ScalarForce(8.0, Unit::Force::Newton), Area(4.0, Unit::Area::SquareMetre)),
      ScalarTraction(2.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      Area(ScalarForce(8.0, Unit::Force::Newton), ScalarTraction(4.0, Unit::Pressure::Pascal)),
      Area(2.0, Unit::Area::SquareMetre));
  EXPECT_EQ(
      ScalarForce(ScalarTraction(4.0, Unit::Pressure::Pascal), Area(2.0, Unit::Area::SquareMetre)),
      ScalarForce(8.0, Unit::Force::Newton));
}

TEST(ScalarTraction, CopyAssignmentOperator) {
  {
    const ScalarTraction<float> first(1.0F, Unit::Pressure::Pascal);
    ScalarTraction<double> second = ScalarTraction<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarTraction<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const ScalarTraction<double> first(1.0, Unit::Pressure::Pascal);
    ScalarTraction<double> second = ScalarTraction<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarTraction<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const ScalarTraction<long double> first(1.0L, Unit::Pressure::Pascal);
    ScalarTraction<double> second = ScalarTraction<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarTraction<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(ScalarTraction, CopyConstructor) {
  {
    const ScalarTraction<float> first(1.0F, Unit::Pressure::Pascal);
    const ScalarTraction<double> second{first};
    EXPECT_EQ(second, ScalarTraction<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const ScalarTraction<double> first(1.0, Unit::Pressure::Pascal);
    const ScalarTraction<double> second{first};
    EXPECT_EQ(second, ScalarTraction<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const ScalarTraction<long double> first(1.0L, Unit::Pressure::Pascal);
    const ScalarTraction<double> second{first};
    EXPECT_EQ(second, ScalarTraction<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(ScalarTraction, Create) {
  constexpr ScalarTraction quantity = ScalarTraction<>::Create<Unit::Pressure::Pascal>(1.0);
  EXPECT_EQ(quantity, ScalarTraction(1.0, Unit::Pressure::Pascal));
}

TEST(ScalarTraction, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarTraction<>{});
}

TEST(ScalarTraction, Dimensions) {
  EXPECT_EQ(ScalarTraction<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(ScalarTraction, Hash) {
  const ScalarTraction first{1.0, Unit::Pressure::Kilopascal};
  const ScalarTraction second{1.00001, Unit::Pressure::Kilopascal};
  const ScalarTraction third{-1.0, Unit::Pressure::Kilopascal};
  const std::hash<ScalarTraction<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarTraction, JSON) {
  EXPECT_EQ(ScalarTraction(1.0, Unit::Pressure::Pascal).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa\"}");
  EXPECT_EQ(ScalarTraction(1.0, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa\"}");
}

TEST(ScalarTraction, MoveAssignmentOperator) {
  ScalarTraction first{1.0, Unit::Pressure::Pascal};
  ScalarTraction second = ScalarTraction<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarTraction(1.0, Unit::Pressure::Pascal));
}

TEST(ScalarTraction, MoveConstructor) {
  ScalarTraction first{1.0, Unit::Pressure::Pascal};
  const ScalarTraction second{std::move(first)};
  EXPECT_EQ(second, ScalarTraction(1.0, Unit::Pressure::Pascal));
}

TEST(ScalarTraction, MutableValue) {
  ScalarTraction quantity{1.0, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarTraction, Print) {
  EXPECT_EQ(ScalarTraction(1.0, Unit::Pressure::Pascal).Print(), Print(1.0) + " Pa");
  EXPECT_EQ(ScalarTraction(1.0, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
            Print(1.0) + " kPa");
}

TEST(ScalarTraction, SetValue) {
  ScalarTraction quantity{1.0, Unit::Pressure::Pascal};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarTraction, SizeOf) {
  EXPECT_EQ(sizeof(ScalarTraction<>{}), sizeof(double));
}

TEST(ScalarTraction, StaticValue) {
  constexpr ScalarTraction quantity = ScalarTraction<>::Create<Unit::Pressure::Kilopascal>(2.0);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 2.0);
}

TEST(ScalarTraction, Stream) {
  std::ostringstream stream;
  stream << ScalarTraction(1.0, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), ScalarTraction(1.0, Unit::Pressure::Pascal).Print());
}

TEST(ScalarTraction, Unit) {
  EXPECT_EQ(ScalarTraction<>::Unit(), Standard<Unit::Pressure>);
}

TEST(ScalarTraction, Value) {
  EXPECT_EQ(ScalarTraction(1.0, Unit::Pressure::Pascal).Value(), 1.0);
  EXPECT_EQ(ScalarTraction(2.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal), 2.0);
}

TEST(ScalarTraction, XML) {
  EXPECT_EQ(ScalarTraction(1.0, Unit::Pressure::Pascal).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa</unit>");
  EXPECT_EQ(ScalarTraction(1.0, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>" + Print(1.0) + "</value><unit>kPa</unit>");
}

TEST(ScalarTraction, YAML) {
  EXPECT_EQ(
      ScalarTraction(1.0, Unit::Pressure::Pascal).YAML(), "{value:" + Print(1.0) + ",unit:\"Pa\"}");
  EXPECT_EQ(ScalarTraction(1.0, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:" + Print(1.0) + ",unit:\"kPa\"}");
}

TEST(ScalarTraction, Zero) {
  EXPECT_EQ(ScalarTraction<>::Zero(), ScalarTraction(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
