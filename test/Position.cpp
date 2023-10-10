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

#include "../include/PhQ/Position.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Position, Angle) {
  EXPECT_EQ(Position({0.0, -2.22, 0.0}, Unit::Length::Metre)
                .Angle(Position({0.0, 0.0, 3.33}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Position, ArithmeticOperatorAddition) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre)
                + Position({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Position({3.0, -6.0, 9.0}, Unit::Length::Metre));

  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre)
                + Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Position({3.0, -6.0, 9.0}, Unit::Length::Metre));

  EXPECT_EQ(Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre)
                + Position({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Position({3.0, -6.0, 9.0}, Unit::Length::Metre));
}

TEST(Position, ArithmeticOperatorDivision) {
  EXPECT_EQ(Position({2.0, -4.0, 6.0}, Unit::Length::Metre) / 2.0,
            Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Position, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre) * 2.0,
            Position({2.0, -4.0, 6.0}, Unit::Length::Metre));

  EXPECT_EQ(2.0 * Position({1.0, -2.0, 3.0}, Unit::Length::Metre),
            Position({2.0, -4.0, 6.0}, Unit::Length::Metre));

  EXPECT_EQ(Direction(2.0, -3.0, 6.0) * Length(7.0, Unit::Length::Metre),
            Position({2.0, -3.0, 6.0}, Unit::Length::Metre));

  EXPECT_EQ(Length(7.0, Unit::Length::Metre) * Direction(2.0, -3.0, 6.0),
            Position({2.0, -3.0, 6.0}, Unit::Length::Metre));
}

TEST(Position, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Position({3.0, -6.0, 9.0}, Unit::Length::Metre)
                - Position({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));

  EXPECT_EQ(Position({3.0, -6.0, 9.0}, Unit::Length::Metre)
                - Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Position({1.0, -2.0, 3.0}, Unit::Length::Metre));

  EXPECT_EQ(Displacement({3.0, -6.0, 9.0}, Unit::Length::Metre)
                - Position({2.0, -4.0, 6.0}, Unit::Length::Metre),
            Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Position, AssignmentOperatorAddition) {
  Position first({1.0, -2.0, 3.0}, Unit::Length::Metre);
  first += Position({2.0, -4.0, 6.0}, Unit::Length::Metre);
  EXPECT_EQ(first, Position({3.0, -6.0, 9.0}, Unit::Length::Metre));

  Position second({1.0, -2.0, 3.0}, Unit::Length::Metre);
  second += Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre);
  EXPECT_EQ(second, Position({3.0, -6.0, 9.0}, Unit::Length::Metre));
}

TEST(Position, AssignmentOperatorDivision) {
  Position quantity({2.0, -4.0, 6.0}, Unit::Length::Metre);
  quantity /= 2.0;
  EXPECT_EQ(quantity, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Position, AssignmentOperatorMultiplication) {
  Position quantity({1.0, -2.0, 3.0}, Unit::Length::Metre);
  quantity *= 2.0;
  EXPECT_EQ(quantity, Position({2.0, -4.0, 6.0}, Unit::Length::Metre));
}

TEST(Position, AssignmentOperatorSubtraction) {
  Position first({3.0, -6.0, 9.0}, Unit::Length::Metre);
  first -= Position({2.0, -4.0, 6.0}, Unit::Length::Metre);
  EXPECT_EQ(first, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));

  Position second({3.0, -6.0, 9.0}, Unit::Length::Metre);
  second -= Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre);
  EXPECT_EQ(second, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Position, ComparisonOperators) {
  const Position first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  const Position second({1.11, -2.22, 3.330001}, Unit::Length::Metre);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Position, CopyAssignmentOperator) {
  const Position first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Position second = Position::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Position, CopyConstructor) {
  const Position first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  const Position second{first};
  EXPECT_EQ(second, first);
}

TEST(Position, Create) {
  constexpr Position quantity =
      Position::Create<Unit::Length::Metre>({1.11, -2.22, 3.33});
  EXPECT_EQ(quantity, Position({1.11, -2.22, 3.33}, Unit::Length::Metre));
}

TEST(Position, DefaultConstructor) {
  EXPECT_NO_THROW(Position{});
}

TEST(Position, Dimensions) {
  EXPECT_EQ(Position::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(Position, Hash) {
  const Position first({1.11, -2.22, 3.33}, Unit::Length::Millimetre);
  const Position second({1.11, -2.22, 3.330001}, Unit::Length::Millimetre);
  const Position third({1.11, 2.22, 3.33}, Unit::Length::Millimetre);
  const std::hash<Position> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Position, JSON) {
  EXPECT_EQ(Position({1.11, -2.22, 3.33}, Unit::Length::Metre).JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":-2.220000000000000,"
            "\"z\":"
            "3.330000000000000},\"unit\":\"m\"}");
  EXPECT_EQ(Position({0.0, -2.22, 0.0}, Unit::Length::Millimetre)
                .JSON(Unit::Length::Millimetre),
            "{\"value\":{\"x\":0,\"y\":-2.220000000000000,\"z\":0},\"unit\":"
            "\"mm\"}");
}

TEST(Position, Magnitude) {
  EXPECT_EQ(Position({2.0, -3.0, 6.0}, Unit::Length::Metre).Magnitude(),
            Length(7.0, Unit::Length::Metre));
}

TEST(Position, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(Position({1.11, -2.22, 3.33}, Unit::Length::Metre)),
            Direction(1.11, -2.22, 3.33));

  EXPECT_EQ(Angle(Position({0.0, -2.22, 0.0}, Unit::Length::Metre),
                  Position({0.0, 0.0, 3.33}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(Length(Position({2.0, -3.0, 6.0}, Unit::Length::Metre)),
            Length(7.0, Unit::Length::Metre));

  EXPECT_EQ(Displacement(Position({1.11, -2.22, 3.33}, Unit::Length::Metre)),
            Displacement({1.11, -2.22, 3.33}, Unit::Length::Metre));
}

TEST(Position, MoveAssignmentOperator) {
  Position first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Position second = Position::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Position({1.11, -2.22, 3.33}, Unit::Length::Metre));
}

TEST(Position, MoveConstructor) {
  Position first({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Position second{std::move(first)};
  EXPECT_EQ(second, Position({1.11, -2.22, 3.33}, Unit::Length::Metre));
}

TEST(Position, MutableValue) {
  Position quantity({1.11, -2.22, 3.33}, Unit::Length::Metre);
  Value::Vector& value = quantity.MutableValue();
  value = Value::Vector{-4.44, 5.55, -6.66};
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Position, Print) {
  EXPECT_EQ(Position({1.11, -2.22, 3.33}, Unit::Length::Metre).Print(),
            "(1.110000000000000, -2.220000000000000, 3.330000000000000) m");
  EXPECT_EQ(Position({0.0, -2.22, 0.0}, Unit::Length::Millimetre)
                .Print(Unit::Length::Millimetre),
            "(0, -2.220000000000000, 0) mm");
}

TEST(Position, SetValue) {
  Position quantity({1.11, -2.22, 3.33}, Unit::Length::Metre);
  quantity.SetValue({-4.44, 5.55, -6.66});
  EXPECT_EQ(quantity.Value(), Value::Vector(-4.44, 5.55, -6.66));
}

TEST(Position, SizeOf) {
  EXPECT_EQ(sizeof(Position{}), 3 * sizeof(double));
}

TEST(Position, StandardConstructor) {
  EXPECT_NO_THROW(Position({1.11, -2.22, 3.33}, Unit::Length::Millimetre));
}

TEST(Position, StaticValue) {
  constexpr Position quantity =
      Position::Create<Unit::Length::Millimetre>({1.11, -2.22, 3.33});
  constexpr Value::Vector value =
      quantity.StaticValue<Unit::Length::Millimetre>();
  EXPECT_EQ(value, Value::Vector(1.11, -2.22, 3.33));
}

TEST(Position, Stream) {
  std::ostringstream stream;
  stream << Position({1.11, -2.22, 3.33}, Unit::Length::Metre);
  EXPECT_EQ(
      stream.str(), Position({1.11, -2.22, 3.33}, Unit::Length::Metre).Print());
}

TEST(Position, Unit) {
  EXPECT_EQ(Position::Unit(), Standard<Unit::Length>);
}

TEST(Position, Value) {
  EXPECT_EQ(Position({1.11, -2.22, 3.33}, Unit::Length::Metre).Value(),
            Value::Vector(1.11, -2.22, 3.33));
  EXPECT_EQ(Position({1.11, -2.22, 3.33}, Unit::Length::Millimetre)
                .Value(Unit::Length::Millimetre),
            Value::Vector(1.11, -2.22, 3.33));
}

TEST(Position, XML) {
  EXPECT_EQ(Position({1.11, -2.22, 3.33}, Unit::Length::Metre).XML(),
            "<value><x>1.110000000000000</x><y>-2.220000000000000</"
            "y><z>3.330000000000000</z></value><unit>m</unit>");
  EXPECT_EQ(Position({0.0, -2.22, 0.0}, Unit::Length::Millimetre)
                .XML(Unit::Length::Millimetre),
            "<value><x>0</x><y>-2.220000000000000</y><z>0</z></value><unit>mm</"
            "unit>");
}

TEST(Position, YAML) {
  EXPECT_EQ(Position({1.11, -2.22, 3.33}, Unit::Length::Metre).YAML(),
            "{value:{x:1.110000000000000,y:-2.220000000000000,z:3."
            "330000000000000},unit:\"m\"}");
  EXPECT_EQ(Position({0.0, -2.22, 0.0}, Unit::Length::Millimetre)
                .YAML(Unit::Length::Millimetre),
            "{value:{x:0,y:-2.220000000000000,z:0},unit:\"mm\"}");
}

TEST(Position, Zero) {
  EXPECT_EQ(Position::Zero(), Position({0.0, 0.0, 0.0}, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
