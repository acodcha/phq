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

#include "../include/PhQ/Position.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/Displacement.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(Position, Angle) {
  EXPECT_EQ(Position({0.0, -2.0, 0.0}, Unit::Length::Metre)
                .Angle(Position({0.0, 0.0, 3.0}, Unit::Length::Metre)),
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
  {
    Position position({1.0, -2.0, 3.0}, Unit::Length::Metre);
    position += Position({2.0, -4.0, 6.0}, Unit::Length::Metre);
    EXPECT_EQ(position, Position({3.0, -6.0, 9.0}, Unit::Length::Metre));
  }
  {
    Position position({1.0, -2.0, 3.0}, Unit::Length::Metre);
    position += Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre);
    EXPECT_EQ(position, Position({3.0, -6.0, 9.0}, Unit::Length::Metre));
  }
}

TEST(Position, AssignmentOperatorDivision) {
  Position position({2.0, -4.0, 6.0}, Unit::Length::Metre);
  position /= 2.0;
  EXPECT_EQ(position, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Position, AssignmentOperatorMultiplication) {
  Position position({1.0, -2.0, 3.0}, Unit::Length::Metre);
  position *= 2.0;
  EXPECT_EQ(position, Position({2.0, -4.0, 6.0}, Unit::Length::Metre));
}

TEST(Position, AssignmentOperatorSubtraction) {
  {
    Position position({3.0, -6.0, 9.0}, Unit::Length::Metre);
    position -= Position({2.0, -4.0, 6.0}, Unit::Length::Metre);
    EXPECT_EQ(position, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
  {
    Position position({3.0, -6.0, 9.0}, Unit::Length::Metre);
    position -= Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre);
    EXPECT_EQ(position, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
}

TEST(Position, ComparisonOperators) {
  const Position first({1.0, -2.0, 3.0}, Unit::Length::Metre);
  const Position second({1.0, -2.0, 3.000001}, Unit::Length::Metre);
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
  const Position first({1.0, -2.0, 3.0}, Unit::Length::Metre);
  Position second = Position<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Position, CopyConstructor) {
  const Position first({1.0, -2.0, 3.0}, Unit::Length::Metre);
  const Position second{first};
  EXPECT_EQ(second, first);
}

TEST(Position, Create) {
  {
    constexpr Position position = Position<>::Create<Unit::Length::Metre>(1.0, -2.0, 3.0);
    EXPECT_EQ(position, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
  {
    constexpr Position position =
        Position<>::Create<Unit::Length::Metre>(std::array<double, 3>{1.0, -2.0, 3.0});
    EXPECT_EQ(position, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
  {
    constexpr Position position = Position<>::Create<Unit::Length::Metre>(Vector{1.0, -2.0, 3.0});
    EXPECT_EQ(position, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
  }
}

TEST(Position, DefaultConstructor) {
  EXPECT_NO_THROW(Position<>{});
}

TEST(Position, Dimensions) {
  EXPECT_EQ(Position<>::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(Position, Direction) {
  EXPECT_EQ(Position({2.0, -3.0, 6.0}, Unit::Length::Metre).Direction(), Direction(2.0, -3.0, 6.0));
}

TEST(Position, Hash) {
  const Position first({1.0, -2.0, 3.0}, Unit::Length::Millimetre);
  const Position second({1.0, -2.0, 3.000001}, Unit::Length::Millimetre);
  const Position third({1.0, 2.0, 3.0}, Unit::Length::Millimetre);
  const std::hash<Position<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Position, JSON) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"m\"}");
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).JSON(Unit::Length::Millimetre),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"mm\"}");
}

TEST(Position, Magnitude) {
  EXPECT_EQ(Position({2.0, -3.0, 6.0}, Unit::Length::Metre).Magnitude(),
            Length(7.0, Unit::Length::Metre));
}

TEST(Position, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(Position({1.0, -2.0, 3.0}, Unit::Length::Metre)), Direction(1.0, -2.0, 3.0));
  EXPECT_EQ(Angle(Position({0.0, -2.0, 0.0}, Unit::Length::Metre),
                  Position({0.0, 0.0, 3.0}, Unit::Length::Metre)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(Displacement(Position({1.0, -2.0, 3.0}, Unit::Length::Metre)),
            Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
  EXPECT_EQ(PlanarPosition(Position({1.0, -2.0, 3.0}, Unit::Length::Metre)),
            PlanarPosition({1.0, -2.0}, Unit::Length::Metre));
  EXPECT_EQ(Position(PlanarPosition({1.0, -2.0}, Unit::Length::Metre)),
            Position({1.0, -2.0, 0.0}, Unit::Length::Metre));
}

TEST(Position, MoveAssignmentOperator) {
  Position first({1.0, -2.0, 3.0}, Unit::Length::Metre);
  Position second = Position<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Position, MoveConstructor) {
  Position first({1.0, -2.0, 3.0}, Unit::Length::Metre);
  const Position second{std::move(first)};
  EXPECT_EQ(second, Position({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Position, MutableValue) {
  Position position({1.0, -2.0, 3.0}, Unit::Length::Metre);
  Vector<>& value = position.MutableValue();
  value = Vector{-4.0, 5.0, -6.0};
  EXPECT_EQ(position.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Position, Print) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") m");
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).Print(Unit::Length::Millimetre),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") mm");
}

TEST(Position, SetValue) {
  Position position({1.0, -2.0, 3.0}, Unit::Length::Metre);
  position.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(position.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Position, SizeOf) {
  EXPECT_EQ(sizeof(Position<>{}), 3 * sizeof(double));
}

TEST(Position, StandardConstructor) {
  EXPECT_NO_THROW(Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre));
}

TEST(Position, StaticValue) {
  constexpr Position position = Position<>::Create<Unit::Length::Millimetre>(1.0, -2.0, 3.0);
  constexpr Vector value = position.StaticValue<Unit::Length::Millimetre>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(Position, Stream) {
  std::ostringstream stream;
  stream << Position({1.0, -2.0, 3.0}, Unit::Length::Metre);
  EXPECT_EQ(stream.str(), Position({1.0, -2.0, 3.0}, Unit::Length::Metre).Print());
}

TEST(Position, Unit) {
  EXPECT_EQ(Position<>::Unit(), Standard<Unit::Length>);
}

TEST(Position, Value) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).Value(), Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).Value(Unit::Length::Millimetre),
            Vector(1.0, -2.0, 3.0));
}

TEST(Position, XML) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>m</unit>");
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).XML(Unit::Length::Millimetre),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>mm</unit>");
}

TEST(Position, XYZ) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).x(), Length(1.0, Unit::Length::Metre));
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).y(), Length(-2.0, Unit::Length::Metre));
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).z(), Length(3.0, Unit::Length::Metre));
}

TEST(Position, YAML) {
  EXPECT_EQ(Position({1.0, -2.0, 3.0}, Unit::Length::Metre).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"m\"}");
  EXPECT_EQ(
      Position({1.0, -2.0, 3.0}, Unit::Length::Millimetre).YAML(Unit::Length::Millimetre),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"mm\"}");
}

TEST(Position, Zero) {
  EXPECT_EQ(Position<>::Zero(), Position({0.0, 0.0, 0.0}, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
