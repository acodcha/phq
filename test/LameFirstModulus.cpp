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

#include "../include/PhQ/LameFirstModulus.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(LameFirstModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      LameFirstModulus(1.0, Unit::Pressure::Pascal) + LameFirstModulus(2.0, Unit::Pressure::Pascal),
      LameFirstModulus(3.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(LameFirstModulus(8.0, Unit::Pressure::Pascal) / 2.0,
            LameFirstModulus(4.0, Unit::Pressure::Pascal));
  EXPECT_EQ(
      LameFirstModulus(8.0, Unit::Pressure::Pascal) / LameFirstModulus(2.0, Unit::Pressure::Pascal),
      4.0);
}

TEST(LameFirstModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(LameFirstModulus(4.0, Unit::Pressure::Pascal) * 2.0,
            LameFirstModulus(8.0, Unit::Pressure::Pascal));
  EXPECT_EQ(2.0 * LameFirstModulus(4.0, Unit::Pressure::Pascal),
            LameFirstModulus(8.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      LameFirstModulus(3.0, Unit::Pressure::Pascal) - LameFirstModulus(2.0, Unit::Pressure::Pascal),
      LameFirstModulus(1.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, AssignmentOperatorAddition) {
  LameFirstModulus lame_first_modulus{1.0, Unit::Pressure::Pascal};
  lame_first_modulus += LameFirstModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(lame_first_modulus, LameFirstModulus(3.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, AssignmentOperatorDivision) {
  LameFirstModulus lame_first_modulus{8.0, Unit::Pressure::Pascal};
  lame_first_modulus /= 2.0;
  EXPECT_EQ(lame_first_modulus, LameFirstModulus(4.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, AssignmentOperatorMultiplication) {
  LameFirstModulus lame_first_modulus{4.0, Unit::Pressure::Pascal};
  lame_first_modulus *= 2.0;
  EXPECT_EQ(lame_first_modulus, LameFirstModulus(8.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, AssignmentOperatorSubtraction) {
  LameFirstModulus lame_first_modulus{3.0, Unit::Pressure::Pascal};
  lame_first_modulus -= LameFirstModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(lame_first_modulus, LameFirstModulus(1.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, ComparisonOperators) {
  const LameFirstModulus first{0.1, Unit::Pressure::Pascal};
  const LameFirstModulus second{0.2, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(LameFirstModulus, CopyAssignmentOperator) {
  const LameFirstModulus first{1.0, Unit::Pressure::Pascal};
  LameFirstModulus second = LameFirstModulus<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(LameFirstModulus, CopyConstructor) {
  const LameFirstModulus first{1.0, Unit::Pressure::Pascal};
  const LameFirstModulus second{first};
  EXPECT_EQ(second, first);
}

TEST(LameFirstModulus, Create) {
  constexpr LameFirstModulus lame_first_modulus =
      LameFirstModulus<>::Create<Unit::Pressure::Pascal>(1.0);
  EXPECT_EQ(lame_first_modulus, LameFirstModulus(1.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, DefaultConstructor) {
  EXPECT_NO_THROW(LameFirstModulus<>{});
}

TEST(LameFirstModulus, Dimensions) {
  EXPECT_EQ(LameFirstModulus<>::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(LameFirstModulus, Hash) {
  const LameFirstModulus first{1.0, Unit::Pressure::Kilopascal};
  const LameFirstModulus second{1.00001, Unit::Pressure::Kilopascal};
  const LameFirstModulus third{-1.0, Unit::Pressure::Kilopascal};
  const std::hash<LameFirstModulus<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(LameFirstModulus, JSON) {
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Pascal).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"Pa\"}");
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"kPa\"}");
}

TEST(LameFirstModulus, MoveAssignmentOperator) {
  LameFirstModulus first{1.0, Unit::Pressure::Pascal};
  LameFirstModulus second = LameFirstModulus<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, LameFirstModulus(1.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, MoveConstructor) {
  LameFirstModulus first{1.0, Unit::Pressure::Pascal};
  const LameFirstModulus second{std::move(first)};
  EXPECT_EQ(second, LameFirstModulus(1.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, MutableValue) {
  LameFirstModulus lame_first_modulus{1.0, Unit::Pressure::Pascal};
  double& value = lame_first_modulus.MutableValue();
  value = 2.0;
  EXPECT_EQ(lame_first_modulus.Value(), 2.0);
}

TEST(LameFirstModulus, Print) {
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Pascal).Print(), Print(1.0) + " Pa");
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
            Print(1.0) + " kPa");
}

TEST(LameFirstModulus, SetValue) {
  LameFirstModulus lame_first_modulus{1.0, Unit::Pressure::Pascal};
  lame_first_modulus.SetValue(2.0);
  EXPECT_EQ(lame_first_modulus.Value(), 2.0);
}

TEST(LameFirstModulus, SizeOf) {
  EXPECT_EQ(sizeof(LameFirstModulus<>{}), sizeof(double));
}

TEST(LameFirstModulus, StandardConstructor) {
  EXPECT_NO_THROW(LameFirstModulus(1.0, Unit::Pressure::Kilopascal));
}

TEST(LameFirstModulus, StaticValue) {
  constexpr LameFirstModulus lame_first_modulus =
      LameFirstModulus<>::Create<Unit::Pressure::Kilopascal>(1.0);
  constexpr double value = lame_first_modulus.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.0);
}

TEST(LameFirstModulus, Stream) {
  std::ostringstream stream;
  stream << LameFirstModulus(1.0, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), LameFirstModulus(1.0, Unit::Pressure::Pascal).Print());
}

TEST(LameFirstModulus, Unit) {
  EXPECT_EQ(LameFirstModulus<>::Unit(), Standard<Unit::Pressure>);
}

TEST(LameFirstModulus, Value) {
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Pascal).Value(), 1.0);
  EXPECT_EQ(
      LameFirstModulus(1.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal), 1.0);
}

TEST(LameFirstModulus, XML) {
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Pascal).XML(),
            "<value>" + Print(1.0) + "</value><unit>Pa</unit>");
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>" + Print(1.0) + "</value><unit>kPa</unit>");
}

TEST(LameFirstModulus, YAML) {
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Pascal).YAML(),
            "{value:" + Print(1.0) + ",unit:\"Pa\"}");
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:" + Print(1.0) + ",unit:\"kPa\"}");
}

TEST(LameFirstModulus, Zero) {
  EXPECT_EQ(LameFirstModulus<>::Zero(), LameFirstModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
