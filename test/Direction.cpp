// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

#include "../include/PhQ/Direction.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/Dyad.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(Direction, Angle) {
  EXPECT_EQ(
      Direction(0.0, -2.0, 0.0).Angle(Direction(0.0, 0.0, 3.0)), Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      Direction(0.0, -2.0, 0.0).Angle(Vector(0.0, 0.0, 3.0)), Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      Vector(0.0, -2.0, 0.0).Angle(Direction(0.0, 0.0, 3.0)), Angle(90.0, Unit::Angle::Degree));
}

TEST(Direction, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SymmetricDyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0) * Direction(0.0, -1.0, 0.0),
            Vector(-2.0, -8.0, -16.0));
}

TEST(Direction, AssignmentOperatorMultiplication) {
  EXPECT_EQ(Dyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0) * Direction(0.0, -1.0, 0.0),
            Vector(-2.0, -16.0, -128.0));
}

TEST(Direction, ComparisonOperators) {
  const Direction first{0.0, 0.0, 1.0};
  const Direction second{1.0, 1.0, 1.0};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Direction, CopyAssignmentOperator) {
  const Direction first(1.0, -2.0, 3.0);
  Direction second = Direction<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Direction, CopyConstructor) {
  const Direction first(1.0, -2.0, 3.0);
  const Direction second{first};
  EXPECT_EQ(second, first);
}

TEST(Direction, Cross) {
  EXPECT_EQ(Direction(1.0, 0.0, 0.0).Cross(Direction(0.0, 1.0, 0.0)), Direction(0.0, 0.0, 1.0));
  EXPECT_EQ(Vector(2.0, 0.0, 0.0).Cross(Direction(0.0, 1.0, 0.0)), Vector(0.0, 0.0, 2.0));
  EXPECT_EQ(Direction(1.0, 0.0, 0.0).Cross(Vector(0.0, 2.0, 0.0)), Vector(0.0, 0.0, 2.0));
}

TEST(Direction, DefaultConstructor) {
  EXPECT_EQ(Direction<>{}, Direction<>::Zero());
}

TEST(Direction, Dimensions) {
  EXPECT_EQ(Direction<>::Dimensions(), Dimensionless);
}

TEST(Direction, Dot) {
  EXPECT_EQ(Direction(0.0, -1.0, 0.0).Dot(Direction(0.0, -1.0, 0.0)), 1.0);
  EXPECT_EQ(Direction(0.0, -1.0, 0.0).Dot(Direction(0.0, 1.0, 0.0)), -1.0);
  EXPECT_EQ(Direction(0.0, 1.0, 0.0).Dot(Direction(-1.0, 0.0, 0.0)), 0.0);
  EXPECT_EQ(Direction(0.0, -1.0, 0.0).Dot(Vector(2.0, -3.0, 6.0)), 3.0);
  EXPECT_EQ(Vector(2.0, -3.0, 6.0).Dot(Direction(0.0, 0.0, 1.0)), 6.0);
}

TEST(Direction, Dyadic) {
  EXPECT_EQ(Direction(1.0, 0.0, 0.0).Dyadic(Direction(0.0, -1.0, 0.0)),
            Dyad(0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(Direction(0.0, 0.0, -1.0).Dyadic(Vector(1.0, 2.0, 4.0)),
            Dyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -2.0, -4.0));
  EXPECT_EQ(Vector(1.0, 2.0, 4.0).Dyadic(Direction(0.0, -1.0, 0.0)),
            Dyad(0.0, -1.0, 0.0, 0.0, -2.0, 0.0, 0.0, -4.0, 0.0));
}

TEST(Direction, Hash) {
  const Direction first{1.0, -2.0, 3.0};
  const Direction second{1.0, -2.0, 3.000001};
  const Direction third{1.0, 2.0, 3.0};
  const std::hash<Direction<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(Direction, IsZero) {
  EXPECT_FALSE(Direction(1.0, -2.0, 3.0).IsZero());
  EXPECT_TRUE(Direction(0.0, 0.0, 0.0).IsZero());
}

TEST(Direction, JSON) {
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).JSON(),
            "{\"x\":" + Print(0.0) + ",\"y\":" + Print(-1.0) + ",\"z\":" + Print(0.0) + "}");
}

TEST(Direction, Magnitude) {
  EXPECT_EQ(Direction(1.0, -2.0, 3.0).Magnitude(), 1.0);
  EXPECT_EQ(Direction(0.0, 0.0, 0.0).Magnitude(), 0.0);
}

TEST(Direction, MiscellaneousConstructors) {
  EXPECT_EQ(Vector(7.0, Direction(2.0, -3.0, 6.0)), Vector(2.0, -3.0, 6.0));
  EXPECT_EQ(
      Angle(Direction(0.0, -2.0, 0.0), Direction(0.0, 0.0, 3.0)), Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      Angle(Direction(0.0, -2.0, 0.0), Vector(0.0, 0.0, 3.0)), Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      Angle(Vector(0.0, -2.0, 0.0), Direction(0.0, 0.0, 3.0)), Angle(90.0, Unit::Angle::Degree));
}

TEST(Direction, MiscellaneousMethods) {
  EXPECT_EQ(Vector(2.0, -3.0, 6.0).Direction(), Direction(2.0, -3.0, 6.0));
}

TEST(Direction, MoveAssignmentOperator) {
  Direction first(1.0, -2.0, 3.0);
  Direction second = Direction<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Direction(1.0, -2.0, 3.0));
}

TEST(Direction, MoveConstructor) {
  Direction first(1.0, -2.0, 3.0);
  const Direction second{std::move(first)};
  EXPECT_EQ(second, Direction(1.0, -2.0, 3.0));
}

TEST(Direction, Print) {
  EXPECT_EQ(Direction<>{}.Print(), "(" + Print(0.0) + ", " + Print(0.0) + ", " + Print(0.0) + ")");
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).Print(),
            "(" + Print(0.0) + ", " + Print(-1.0) + ", " + Print(0.0) + ")");
}

TEST(Direction, Set) {
  {
    Direction direction(1.0, -2.0, 3.0);
    direction.Set(0.0, -2.0, 0.0);
    EXPECT_EQ(direction.Value(), Vector(0.0, -1.0, 0.0));
  }
  {
    Direction direction(1.0, -2.0, 3.0);
    direction.Set(std::array<double, 3>{0.0, -2.0, 0.0});
    EXPECT_EQ(direction.Value(), Vector(0.0, -1.0, 0.0));
  }
  {
    Direction direction(1.0, -2.0, 3.0);
    direction.Set(Vector{0.0, -2.0, 0.0});
    EXPECT_EQ(direction.Value(), Vector(0.0, -1.0, 0.0));
  }
}

TEST(Direction, SizeOf) {
  EXPECT_EQ(sizeof(Direction<>{}), 3 * sizeof(double));
}

TEST(Direction, StandardConstructor) {
  EXPECT_NO_THROW(Direction(1.0, -2.0, 3.0));
  EXPECT_NO_THROW(Direction(std::array<double, 3>{1.0, -2.0, 3.0}));
  EXPECT_NO_THROW(Direction(Vector{1.0, -2.0, 3.0}));
}

TEST(Direction, Stream) {
  std::ostringstream stream;
  stream << Direction(1.0, -2.0, 3.0);
  EXPECT_EQ(stream.str(), Direction(1.0, -2.0, 3.0).Print());
}

TEST(Direction, Value) {
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).Value(), Vector(0.0, -1.0, 0.0));
}

TEST(Direction, XML) {
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).XML(),
            "<x>" + Print(0.0) + "</x><y>" + Print(-1.0) + "</y><z>" + Print(0.0) + "</z>");
}

TEST(Direction, XYZ) {
  EXPECT_EQ(Direction(2.0, -3.0, 6.0).x(), 2.0 / 7.0);
  EXPECT_EQ(Direction(2.0, -3.0, 6.0).y(), -3.0 / 7.0);
  EXPECT_EQ(Direction(2.0, -3.0, 6.0).z(), 6.0 / 7.0);
}

TEST(Direction, YAML) {
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).YAML(),
            "{x:" + Print(0.0) + ",y:" + Print(-1.0) + ",z:" + Print(0.0) + "}");
}

TEST(Direction, Zero) {
  EXPECT_EQ(Direction<>::Zero(), Direction(0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
