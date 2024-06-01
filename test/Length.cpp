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

#include "../include/PhQ/Length.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Length.hpp"

namespace PhQ {

namespace {

TEST(Length, ArithmeticOperatorAddition) {
  EXPECT_EQ(Length(1.0, Unit::Length::Metre) + Length(2.0, Unit::Length::Metre),
            Length(3.0, Unit::Length::Metre));
}

TEST(Length, ArithmeticOperatorDivision) {
  EXPECT_EQ(Length(8.0, Unit::Length::Metre) / 2.0, Length(4.0, Unit::Length::Metre));
  EXPECT_EQ(Length(8.0, Unit::Length::Metre) / Length(2.0, Unit::Length::Metre), 4.0);
}

TEST(Length, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Length(4.0, Unit::Length::Metre) * 2.0, Length(8.0, Unit::Length::Metre));
  EXPECT_EQ(2.0 * Length(4.0, Unit::Length::Metre), Length(8.0, Unit::Length::Metre));
}

TEST(Length, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Length(3.0, Unit::Length::Metre) - Length(2.0, Unit::Length::Metre),
            Length(1.0, Unit::Length::Metre));
}

TEST(Length, AssignmentOperatorAddition) {
  Length length{1.0, Unit::Length::Metre};
  length += Length(2.0, Unit::Length::Metre);
  EXPECT_EQ(length, Length(3.0, Unit::Length::Metre));
}

TEST(Length, AssignmentOperatorDivision) {
  Length length{8.0, Unit::Length::Metre};
  length /= 2.0;
  EXPECT_EQ(length, Length(4.0, Unit::Length::Metre));
}

TEST(Length, AssignmentOperatorMultiplication) {
  Length length{4.0, Unit::Length::Metre};
  length *= 2.0;
  EXPECT_EQ(length, Length(8.0, Unit::Length::Metre));
}

TEST(Length, AssignmentOperatorSubtraction) {
  Length length{3.0, Unit::Length::Metre};
  length -= Length(2.0, Unit::Length::Metre);
  EXPECT_EQ(length, Length(1.0, Unit::Length::Metre));
}

TEST(Length, ComparisonOperators) {
  const Length first{0.1, Unit::Length::Metre};
  const Length second{0.2, Unit::Length::Metre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Length, Constructor) {
  EXPECT_NO_THROW(Length(1.0, Unit::Length::Metre));
}

TEST(Length, CopyAssignmentOperator) {
  {
    const Length<float> first(1.0F, Unit::Length::Metre);
    Length<double> second = Length<double>::Zero();
    second = first;
    EXPECT_EQ(second, Length<double>(1.0, Unit::Length::Metre));
  }
  {
    const Length<double> first(1.0, Unit::Length::Metre);
    Length<double> second = Length<double>::Zero();
    second = first;
    EXPECT_EQ(second, Length<double>(1.0, Unit::Length::Metre));
  }
  {
    const Length<long double> first(1.0L, Unit::Length::Metre);
    Length<double> second = Length<double>::Zero();
    second = first;
    EXPECT_EQ(second, Length<double>(1.0, Unit::Length::Metre));
  }
}

TEST(Length, CopyConstructor) {
  {
    const Length<float> first(1.0F, Unit::Length::Metre);
    const Length<double> second{first};
    EXPECT_EQ(second, Length<double>(1.0, Unit::Length::Metre));
  }
  {
    const Length<double> first(1.0, Unit::Length::Metre);
    const Length<double> second{first};
    EXPECT_EQ(second, Length<double>(1.0, Unit::Length::Metre));
  }
  {
    const Length<long double> first(1.0L, Unit::Length::Metre);
    const Length<double> second{first};
    EXPECT_EQ(second, Length<double>(1.0, Unit::Length::Metre));
  }
}

TEST(Length, Create) {
  constexpr Length length = Length<>::Create<Unit::Length::Metre>(1.0);
  EXPECT_EQ(length, Length(1.0, Unit::Length::Metre));
}

TEST(Length, DefaultConstructor) {
  EXPECT_NO_THROW(Length<>{});
}

TEST(Length, Dimensions) {
  EXPECT_EQ(Length<>::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(Length, Hash) {
  const Length first{1.0, Unit::Length::Millimetre};
  const Length second{1.00001, Unit::Length::Millimetre};
  const Length third{-1.0, Unit::Length::Millimetre};
  const std::hash<Length<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Length, JSON) {
  EXPECT_EQ(
      Length(1.0, Unit::Length::Metre).JSON(), "{\"value\":" + Print(1.0) + ",\"unit\":\"m\"}");
  EXPECT_EQ(Length(1.0, Unit::Length::Millimetre).JSON(Unit::Length::Millimetre),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"mm\"}");
}

TEST(Length, MoveAssignmentOperator) {
  Length first{1.0, Unit::Length::Metre};
  Length second = Length<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Length(1.0, Unit::Length::Metre));
}

TEST(Length, MoveConstructor) {
  Length first{1.0, Unit::Length::Metre};
  const Length second{std::move(first)};
  EXPECT_EQ(second, Length(1.0, Unit::Length::Metre));
}

TEST(Length, MutableValue) {
  Length length{1.0, Unit::Length::Metre};
  double& value = length.MutableValue();
  value = 2.0;
  EXPECT_EQ(length.Value(), 2.0);
}

TEST(Length, Print) {
  EXPECT_EQ(Length(1.0, Unit::Length::Metre).Print(), Print(1.0) + " m");
  EXPECT_EQ(
      Length(1.0, Unit::Length::Millimetre).Print(Unit::Length::Millimetre), Print(1.0) + " mm");
}

TEST(Length, SetValue) {
  Length length{1.0, Unit::Length::Metre};
  length.SetValue(2.0);
  EXPECT_EQ(length.Value(), 2.0);
}

TEST(Length, SizeOf) {
  EXPECT_EQ(sizeof(Length<>{}), sizeof(double));
}

TEST(Length, StaticValue) {
  constexpr Length length = Length<>::Create<Unit::Length::Metre>(1.0);
  constexpr double value = length.StaticValue<Unit::Length::Metre>();
  EXPECT_EQ(value, 1.0);
}

TEST(Length, Stream) {
  std::ostringstream stream;
  stream << Length(1.0, Unit::Length::Metre);
  EXPECT_EQ(stream.str(), Length(1.0, Unit::Length::Metre).Print());
}

TEST(Length, Unit) {
  EXPECT_EQ(Length<>::Unit(), Standard<Unit::Length>);
}

TEST(Length, Value) {
  EXPECT_EQ(Length(1.0, Unit::Length::Metre).Value(), 1.0);
  EXPECT_EQ(Length(1.0, Unit::Length::Millimetre).Value(Unit::Length::Millimetre), 1.0);
}

TEST(Length, XML) {
  EXPECT_EQ(
      Length(1.0, Unit::Length::Metre).XML(), "<value>" + Print(1.0) + "</value><unit>m</unit>");
  EXPECT_EQ(Length(1.0, Unit::Length::Millimetre).XML(Unit::Length::Millimetre),
            "<value>" + Print(1.0) + "</value><unit>mm</unit>");
}

TEST(Length, YAML) {
  EXPECT_EQ(Length(1.0, Unit::Length::Metre).YAML(), "{value:" + Print(1.0) + ",unit:\"m\"}");
  EXPECT_EQ(Length(1.0, Unit::Length::Millimetre).YAML(Unit::Length::Millimetre),
            "{value:" + Print(1.0) + ",unit:\"mm\"}");
}

TEST(Length, Zero) {
  EXPECT_EQ(Length<>::Zero(), Length(0.0, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
