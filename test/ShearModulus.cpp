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

#include "../include/PhQ/ShearModulus.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(ShearModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Pascal) + ShearModulus(2.0, Unit::Pressure::Pascal),
            ShearModulus(3.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      ShearModulus(8.0, Unit::Pressure::Pascal) / 2.0, ShearModulus(4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      ShearModulus(8.0, Unit::Pressure::Pascal) / ShearModulus(2.0, Unit::Pressure::Pascal), 4.0);
}

TEST(ShearModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      ShearModulus(4.0, Unit::Pressure::Pascal) * 2.0, ShearModulus(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      2.0 * ShearModulus(4.0, Unit::Pressure::Pascal), ShearModulus(8.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ShearModulus(3.0, Unit::Pressure::Pascal) - ShearModulus(2.0, Unit::Pressure::Pascal),
            ShearModulus(1.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, AssignmentOperatorAddition) {
  ShearModulus quantity{1.0, Unit::Pressure::Pascal};
  quantity += ShearModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, ShearModulus(3.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, AssignmentOperatorDivision) {
  ShearModulus quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ShearModulus(4.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, AssignmentOperatorMultiplication) {
  ShearModulus quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ShearModulus(8.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, AssignmentOperatorSubtraction) {
  ShearModulus quantity{3.0, Unit::Pressure::Pascal};
  quantity -= ShearModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, ShearModulus(1.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, ComparisonOperators) {
  const ShearModulus first{1.0, Unit::Pressure::Pascal};
  const ShearModulus second{2.0, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ShearModulus, CopyAssignmentOperator) {
  {
    const ShearModulus<float> first(1.0F, Unit::Pressure::Pascal);
    ShearModulus<double> second = ShearModulus<double>::Zero();
    second = first;
    EXPECT_EQ(second, ShearModulus<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const ShearModulus<double> first(1.0, Unit::Pressure::Pascal);
    ShearModulus<double> second = ShearModulus<double>::Zero();
    second = first;
    EXPECT_EQ(second, ShearModulus<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const ShearModulus<long double> first(1.0L, Unit::Pressure::Pascal);
    ShearModulus<double> second = ShearModulus<double>::Zero();
    second = first;
    EXPECT_EQ(second, ShearModulus<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(ShearModulus, CopyConstructor) {
  {
    const ShearModulus<float> first(1.0F, Unit::Pressure::Pascal);
    const ShearModulus<double> second{first};
    EXPECT_EQ(second, ShearModulus<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const ShearModulus<double> first(1.0, Unit::Pressure::Pascal);
    const ShearModulus<double> second{first};
    EXPECT_EQ(second, ShearModulus<double>(1.0, Unit::Pressure::Pascal));
  }
  {
    const ShearModulus<long double> first(1.0L, Unit::Pressure::Pascal);
    const ShearModulus<double> second{first};
    EXPECT_EQ(second, ShearModulus<double>(1.0, Unit::Pressure::Pascal));
  }
}

TEST(ShearModulus, Create) {
  constexpr ShearModulus quantity = ShearModulus<>::Create<Unit::Pressure::Pascal>(1.0);
  EXPECT_EQ(quantity, ShearModulus(1.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, DefaultConstructor) {
  EXPECT_NO_THROW(ShearModulus<>{});
}

TEST(ShearModulus, Dimensions) {
  EXPECT_EQ(ShearModulus<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(ShearModulus, Hash) {
  const ShearModulus first{1.0, Unit::Pressure::Kilopascal};
  const ShearModulus second{1.00001, Unit::Pressure::Kilopascal};
  const ShearModulus third{-1.0, Unit::Pressure::Kilopascal};
  const std::hash<ShearModulus<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(ShearModulus, JSON) {
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Pascal).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa\"}");
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa\"}");
}

TEST(ShearModulus, MoveAssignmentOperator) {
  ShearModulus first{1.0, Unit::Pressure::Pascal};
  ShearModulus second = ShearModulus<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ShearModulus(1.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, MoveConstructor) {
  ShearModulus first{1.0, Unit::Pressure::Pascal};
  const ShearModulus second{std::move(first)};
  EXPECT_EQ(second, ShearModulus(1.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, MutableValue) {
  ShearModulus quantity{1.0, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ShearModulus, Print) {
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Pascal).Print(), Print(1.0) + " Pa");
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
            Print(1.0) + " kPa");
}

TEST(ShearModulus, SetValue) {
  ShearModulus quantity{1.0, Unit::Pressure::Pascal};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ShearModulus, SizeOf) {
  EXPECT_EQ(sizeof(ShearModulus<>{}), sizeof(double));
}

TEST(ShearModulus, StandardConstructor) {
  EXPECT_NO_THROW(ShearModulus(1.0, Unit::Pressure::Kilopascal));
}

TEST(ShearModulus, StaticValue) {
  constexpr ShearModulus quantity = ShearModulus<>::Create<Unit::Pressure::Kilopascal>(1.0);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.0);
}

TEST(ShearModulus, Stream) {
  std::ostringstream stream;
  stream << ShearModulus(1.0, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), ShearModulus(1.0, Unit::Pressure::Pascal).Print());
}

TEST(ShearModulus, Unit) {
  EXPECT_EQ(ShearModulus<>::Unit(), Standard<Unit::Pressure>);
}

TEST(ShearModulus, Value) {
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Pascal).Value(), 1.0);
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal), 1.0);
}

TEST(ShearModulus, XML) {
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Pascal).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa</unit>");
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>" + Print(1.0) + "</value><unit>kPa</unit>");
}

TEST(ShearModulus, YAML) {
  EXPECT_EQ(
      ShearModulus(1.0, Unit::Pressure::Pascal).YAML(), "{value:" + Print(1.0) + ",unit:\"Pa\"}");
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:" + Print(1.0) + ",unit:\"kPa\"}");
}

TEST(ShearModulus, Zero) {
  EXPECT_EQ(ShearModulus<>::Zero(), ShearModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
