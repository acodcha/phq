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

#include "../include/PhQ/Direction.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Direction, Angle) {
  EXPECT_EQ(Direction(0.0, -2.22, 0.0).Angle(Direction(0.0, 0.0, 3.33)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(Direction(0.0, -2.22, 0.0).Angle(Value::Vector(0.0, 0.0, 3.33)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(Value::Vector(0.0, -2.22, 0.0).Angle(Direction(0.0, 0.0, 3.33)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Direction, ArithmeticMultiplication) {
  EXPECT_EQ(Value::SymmetricDyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0)
                * Direction(0.0, -1.0, 0.0),
            Value::Vector(-2.0, -8.0, -16.0));

  EXPECT_EQ(Value::Dyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0)
                * Direction(0.0, -1.0, 0.0),
            Value::Vector(-2.0, -16.0, -128.0));
}

TEST(Direction, Comparisons) {
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

TEST(Direction, CopyAssignment) {
  const Direction first(1.11, -2.22, 3.33);
  Direction second = Direction::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Direction, CopyConstructor) {
  const Direction first(1.11, -2.22, 3.33);
  const Direction second{first};
  EXPECT_EQ(second, first);
}

TEST(Direction, Cross) {
  EXPECT_EQ(Direction(1.0, 0.0, 0.0).Cross(Direction(0.0, 1.0, 0.0)),
            Direction(0.0, 0.0, 1.0));
  EXPECT_EQ(Value::Vector(2.0, 0.0, 0.0).Cross(Direction(0.0, 1.0, 0.0)),
            Value::Vector(0.0, 0.0, 2.0));
  EXPECT_EQ(Direction(1.0, 0.0, 0.0).Cross(Value::Vector(0.0, 2.0, 0.0)),
            Value::Vector(0.0, 0.0, 2.0));
}

TEST(Direction, DefaultConstructor) {
  EXPECT_EQ(Direction{}, Direction::Zero());
}

TEST(Direction, Dimensions) {
  EXPECT_EQ(Direction::Dimensions(), Dimensions{});
}

TEST(Direction, Dot) {
  EXPECT_EQ(Direction(0.0, -1.0, 0.0).Dot(Direction(0.0, -1.0, 0.0)), 1.0);
  EXPECT_EQ(Direction(0.0, -1.0, 0.0).Dot(Direction(0.0, 1.0, 0.0)), -1.0);
  EXPECT_EQ(Direction(0.0, 1.0, 0.0).Dot(Direction(-1.0, 0.0, 0.0)), 0.0);
  EXPECT_EQ(Direction(0.0, -1.0, 0.0).Dot(Value::Vector(2.0, -3.0, 6.0)), 3.0);
  EXPECT_EQ(Value::Vector(2.0, -3.0, 6.0).Dot(Direction(0.0, 0.0, 1.0)), 6.0);
}

TEST(Direction, Dyadic) {
  EXPECT_EQ(Direction(1.0, 0.0, 0.0).Dyadic(Direction(0.0, -1.0, 0.0)),
            Value::Dyad(0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(Direction(0.0, 0.0, -1.0).Dyadic(Value::Vector(1.0, 2.0, 4.0)),
            Value::Dyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -2.0, -4.0));
  EXPECT_EQ(Value::Vector(1.0, 2.0, 4.0).Dyadic(Direction(0.0, -1.0, 0.0)),
            Value::Dyad(0.0, -1.0, 0.0, 0.0, -2.0, 0.0, 0.0, -4.0, 0.0));
}

TEST(Direction, Hash) {
  const Direction first{1.11, -2.22, 3.33};
  const Direction second{1.11, -2.22, 3.330001};
  const Direction third{1.11, 2.22, 3.33};
  const std::hash<Direction> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(Direction, JSON) {
  EXPECT_EQ(Direction(0.0, -2.22, 0.0).JSON(),
            "{\"x\":0,\"y\":-1.000000000000000,\"z\":0}");
}

TEST(Direction, Magnitude) {
  EXPECT_EQ(Direction(1.11, -2.22, 3.33).Magnitude(), 1.0);
  EXPECT_EQ(Direction(0.0, 0.0, 0.0).Magnitude(), 0.0);
}

TEST(Direction, MiscellaneousConstructors) {
  EXPECT_EQ(Value::Vector(7.0, Direction(2.0, -3.0, 6.0)),
            Value::Vector(2.0, -3.0, 6.0));

  EXPECT_EQ(Angle(Direction(0.0, -2.22, 0.0), Direction(0.0, 0.0, 3.33)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(Angle(Direction(0.0, -2.22, 0.0), Value::Vector(0.0, 0.0, 3.33)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(Angle(Value::Vector(0.0, -2.22, 0.0), Direction(0.0, 0.0, 3.33)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Direction, MiscellaneousMethods) {
  EXPECT_EQ(
      Value::Vector(2.0, -3.0, 6.0).Direction(), Direction(2.0, -3.0, 6.0));
}

TEST(Direction, MoveAssignment) {
  const Direction first(1.11, -2.22, 3.33);
  Direction second(1.11, -2.22, 3.33);
  Direction third = Direction::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(Direction, MoveConstructor) {
  const Direction first(1.11, -2.22, 3.33);
  Direction second(1.11, -2.22, 3.33);
  Direction third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(Direction, Print) {
  EXPECT_EQ(Direction{}.Print(), "(0, 0, 0)");
  EXPECT_EQ(Direction(0.0, -2.22, 0.0).Print(), "(0, -1.000000000000000, 0)");
}

TEST(Direction, SetValue) {
  Direction first(1.11, -2.22, 3.33);
  first.SetValue(0.0, -2.22, 0.0);
  EXPECT_EQ(first.Value(), Value::Vector(0, -1.0, 0.0));

  Direction second(1.11, -2.22, 3.33);
  second.SetValue(std::array<double, 3>{0.0, -2.22, 0.0});
  EXPECT_EQ(second.Value(), Value::Vector(0, -1.0, 0.0));

  Direction third(1.11, -2.22, 3.33);
  third.SetValue(Value::Vector{0.0, -2.22, 0.0});
  EXPECT_EQ(third.Value(), Value::Vector(0, -1.0, 0.0));
}

TEST(Direction, SizeOf) {
  EXPECT_EQ(sizeof(Direction{}), 3 * sizeof(double));
}

TEST(Direction, StandardConstructor) {
  EXPECT_NO_THROW(Direction(1.11, -2.22, 3.33));
  EXPECT_NO_THROW(Direction(std::array<double, 3>{1.11, -2.22, 3.33}));
  EXPECT_NO_THROW(Direction(Value::Vector{1.11, -2.22, 3.33}));
}

TEST(Direction, Stream) {
  std::ostringstream stream;
  stream << Direction(1.11, -2.22, 3.33);
  EXPECT_EQ(stream.str(), Direction(1.11, -2.22, 3.33).Print());
}

TEST(Direction, Valid) {
  EXPECT_TRUE(Direction(1.11, -2.22, 3.33).Valid());
  EXPECT_FALSE(Direction(0.0, 0.0, 0.0).Valid());
}

TEST(Direction, Value) {
  EXPECT_EQ(Direction(0.0, -2.22, 0.0).Value(), Value::Vector(0.0, -1.0, 0.0));
}

TEST(Direction, XML) {
  EXPECT_EQ(Direction(0.0, -2.22, 0.0).XML(),
            "<x>0</x><y>-1.000000000000000</y><z>0</z>");
}

TEST(Direction, YAML) {
  EXPECT_EQ(Direction(0.0, -2.22, 0.0).YAML(),
            "{x:0,y:-1.000000000000000,z:"
            "0}");
}

TEST(Direction, Zero) {
  EXPECT_EQ(Direction::Zero(), Direction(0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
