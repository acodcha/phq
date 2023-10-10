// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#include "../include/PhQ/Length.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Length, ArithmeticOperatorAddition) {
  EXPECT_EQ(Length(1.0, Unit::Length::Metre) + Length(2.0, Unit::Length::Metre),
            Length(3.0, Unit::Length::Metre));
}

TEST(Length, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      Length(8.0, Unit::Length::Metre) / 2.0, Length(4.0, Unit::Length::Metre));

  EXPECT_EQ(
      Length(8.0, Unit::Length::Metre) / Length(2.0, Unit::Length::Metre), 4.0);
}

TEST(Length, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      Length(4.0, Unit::Length::Metre) * 2.0, Length(8.0, Unit::Length::Metre));

  EXPECT_EQ(
      2.0 * Length(4.0, Unit::Length::Metre), Length(8.0, Unit::Length::Metre));
}

TEST(Length, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Length(3.0, Unit::Length::Metre) - Length(2.0, Unit::Length::Metre),
            Length(1.0, Unit::Length::Metre));
}

TEST(Length, AssignmentOperatorAddition) {
  Length quantity{1.0, Unit::Length::Metre};
  quantity += Length(2.0, Unit::Length::Metre);
  EXPECT_EQ(quantity, Length(3.0, Unit::Length::Metre));
}

TEST(Length, AssignmentOperatorDivision) {
  Length quantity{8.0, Unit::Length::Metre};
  quantity /= 2.0;
  EXPECT_EQ(quantity, Length(4.0, Unit::Length::Metre));
}

TEST(Length, AssignmentOperatorMultiplication) {
  Length quantity{4.0, Unit::Length::Metre};
  quantity *= 2.0;
  EXPECT_EQ(quantity, Length(8.0, Unit::Length::Metre));
}

TEST(Length, AssignmentOperatorSubtraction) {
  Length quantity{3.0, Unit::Length::Metre};
  quantity -= Length(2.0, Unit::Length::Metre);
  EXPECT_EQ(quantity, Length(1.0, Unit::Length::Metre));
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

TEST(Length, CopyAssignmentOperator) {
  const Length first{1.11, Unit::Length::Metre};
  Length second = Length::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Length, CopyConstructor) {
  const Length first{1.11, Unit::Length::Metre};
  const Length second{first};
  EXPECT_EQ(second, first);
}

TEST(Length, Create) {
  constexpr Length quantity = Length::Create<Unit::Length::Metre>(1.11);
  EXPECT_EQ(quantity, Length(1.11, Unit::Length::Metre));
}

TEST(Length, DefaultConstructor) {
  EXPECT_NO_THROW(Length{});
}

TEST(Length, Dimensions) {
  EXPECT_EQ(Length::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(Length, Hash) {
  const Length first{1.11, Unit::Length::Millimetre};
  const Length second{1.110001, Unit::Length::Millimetre};
  const Length third{-1.11, Unit::Length::Millimetre};
  const std::hash<Length> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Length, JSON) {
  EXPECT_EQ(Length(1.11, Unit::Length::Metre).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"m\"}");
  EXPECT_EQ(
      Length(-2.22, Unit::Length::Millimetre).JSON(Unit::Length::Millimetre),
      "{\"value\":-2.220000000000000,\"unit\":\"mm\"}");
}

TEST(Length, MoveAssignmentOperator) {
  Length first{1.11, Unit::Length::Metre};
  Length second = Length::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Length(1.11, Unit::Length::Metre));
}

TEST(Length, MoveConstructor) {
  Length first{1.11, Unit::Length::Metre};
  Length second{std::move(first)};
  EXPECT_EQ(second, Length(1.11, Unit::Length::Metre));
}

TEST(Length, MutableValue) {
  Length quantity{1.11, Unit::Length::Metre};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Length, Print) {
  EXPECT_EQ(Length(1.11, Unit::Length::Metre).Print(), "1.110000000000000 m");
  EXPECT_EQ(
      Length(-2.22, Unit::Length::Millimetre).Print(Unit::Length::Millimetre),
      "-2.220000000000000 mm");
}

TEST(Length, SetValue) {
  Length quantity{1.11, Unit::Length::Metre};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Length, SizeOf) {
  EXPECT_EQ(sizeof(Length{}), sizeof(double));
}

TEST(Length, StandardConstructor) {
  EXPECT_NO_THROW(Length(1.11, Unit::Length::Metre));
}

TEST(Length, StaticValue) {
  constexpr Length quantity = Length::Create<Unit::Length::Metre>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Length::Metre>();
  EXPECT_EQ(value, 1.11);
}

TEST(Length, Stream) {
  std::ostringstream stream;
  stream << Length(1.11, Unit::Length::Metre);
  EXPECT_EQ(stream.str(), Length(1.11, Unit::Length::Metre).Print());
}

TEST(Length, Unit) {
  EXPECT_EQ(Length::Unit(), Standard<Unit::Length>);
}

TEST(Length, Value) {
  EXPECT_EQ(Length(1.11, Unit::Length::Metre).Value(), 1.11);
  EXPECT_EQ(
      Length(1.11, Unit::Length::Millimetre).Value(Unit::Length::Millimetre),
      1.11);
}

TEST(Length, XML) {
  EXPECT_EQ(Length(1.11, Unit::Length::Metre).XML(),
            "<value>1.110000000000000</value><unit>m</unit>");
  EXPECT_EQ(
      Length(-2.22, Unit::Length::Millimetre).XML(Unit::Length::Millimetre),
      "<value>-2.220000000000000</value><unit>mm</unit>");
}

TEST(Length, YAML) {
  EXPECT_EQ(Length(1.11, Unit::Length::Metre).YAML(),
            "{value:1.110000000000000,unit:\"m\"}");
  EXPECT_EQ(
      Length(-2.22, Unit::Length::Millimetre).YAML(Unit::Length::Millimetre),
      "{value:-2.220000000000000,unit:\"mm\"}");
}

TEST(Length, Zero) {
  EXPECT_EQ(Length::Zero(), Length(0.0, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
