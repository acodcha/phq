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

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Direction, Accessor) {
  const std::array<double, 3> value{
      0.0, 0.5 * SquareRoot(2.0), -0.5 * SquareRoot(2.0)};

  const Direction direction0{0.0, 10.0, -10.0};
  EXPECT_DOUBLE_EQ(direction0.Value().x(), 0.0);
  EXPECT_DOUBLE_EQ(direction0.Value().y(), 0.5 * SquareRoot(2.0));
  EXPECT_DOUBLE_EQ(direction0.Value().z(), -0.5 * SquareRoot(2.0));

  Direction direction1{1.0, 0.0, 0.0};
  direction1.SetValue(Value::Vector{0.0, 10.0, -10.0});
  EXPECT_DOUBLE_EQ(direction1.Value().x(), value[0]);
  EXPECT_DOUBLE_EQ(direction1.Value().y(), value[1]);
  EXPECT_DOUBLE_EQ(direction1.Value().z(), value[2]);

  Direction direction2{1.0, 0.0, 0.0};
  direction2.SetValue(std::array<double, 3>{0.0, 10.0, -10.0});
  EXPECT_DOUBLE_EQ(direction2.Value().x(), value[0]);
  EXPECT_DOUBLE_EQ(direction2.Value().y(), value[1]);
  EXPECT_DOUBLE_EQ(direction2.Value().z(), value[2]);

  Direction direction3{-1.0, 2.0, -3.0};
  direction3.SetValue(0.0, 0.0, 0.0);
  EXPECT_EQ(direction3.Value().x(), 0.0);
  EXPECT_EQ(direction3.Value().y(), 0.0);
  EXPECT_EQ(direction3.Value().z(), 0.0);
}

TEST(Direction, Angle) {
  const Angle angle{90.0, Unit::Angle::Degree};
  const Direction direction0{0.0, 1.0, 0.0};
  const Direction direction1{0.0, 0.0, 1.0};
  EXPECT_DOUBLE_EQ(Angle(direction0, direction1).Value(), angle.Value());
  EXPECT_DOUBLE_EQ(
      Angle(direction0.Value(), direction1).Value(), angle.Value());
  EXPECT_DOUBLE_EQ(
      Angle(direction0, direction1.Value()).Value(), angle.Value());
  EXPECT_DOUBLE_EQ(
      Angle(direction0.Value(), direction1.Value()).Value(), angle.Value());
  EXPECT_DOUBLE_EQ(direction0.Angle(direction1).Value(), angle.Value());
  EXPECT_DOUBLE_EQ(direction0.Angle(direction1.Value()).Value(), angle.Value());
  EXPECT_DOUBLE_EQ(direction0.Value().Angle(direction1).Value(), angle.Value());
  EXPECT_DOUBLE_EQ(
      direction0.Value().Angle(direction1.Value()).Value(), angle.Value());
}

TEST(Direction, Comparison) {
  const Direction direction0{0.0, 0.0, 1.0};
  const Direction direction1{1.0, 1.0, 1.0};
  EXPECT_EQ(direction0, direction0);
  EXPECT_NE(direction0, direction1);
  EXPECT_LT(direction0, direction1);
  EXPECT_GT(direction1, direction0);
  EXPECT_LE(direction0, direction0);
  EXPECT_LE(direction0, direction1);
  EXPECT_GE(direction0, direction0);
  EXPECT_GE(direction1, direction0);
}

TEST(Direction, Constructor) {
  EXPECT_EQ(Direction{}, Direction(1.0, 0.0, 0.0));
  EXPECT_EQ(Direction(std::array<double, 3>{0.0, -10.0, 0.0}),
            Direction(0.0, -1.0, 0.0));
  EXPECT_EQ(Direction(Value::Vector{-10.0, 20.0, -30.0}),
            Direction(-10.0, 20.0, -30.0));
}

TEST(Direction, Cross) {
  EXPECT_EQ(Direction(10.0, 0.0, 0.0).Cross(Direction(0.0, 20.0, 0.0)),
            Direction(0.0, 0.0, 30.0));
  EXPECT_EQ(Value::Vector(10.0, 0.0, 0.0).Cross(Direction(0.0, 20.0, 0.0)),
            Value::Vector(0.0, 0.0, 10.0));
  EXPECT_EQ(Direction(10.0, 0.0, 0.0).Cross(Value::Vector(0.0, 20.0, 0.0)),
            Value::Vector(0.0, 0.0, 20.0));
}

TEST(Direction, Dot) {
  EXPECT_EQ(Direction(1.0, 2.0, 4.0).Dot(Direction(1.0, 2.0, 4.0)), 1.0);
  EXPECT_EQ(Direction(0.0, 10.0, -15.0).Dot(Direction(20.0, 0.0, 0.0)), 0.0);
  EXPECT_EQ(Direction(1.0, 2.0, 4.0).Dot(Direction(-1.0, -2.0, -4.0)), -1.0);
  EXPECT_LT(Direction(1.11, 2.22, 3.33).Dot(Direction(1.99, 2.88, 3.77)), 1.0);
  EXPECT_GT(Direction(1.11, 2.22, 3.33).Dot(Direction(1.99, 2.88, 3.77)), 0.0);
  const Value::Vector vector0{1.23, 4.56, 7.89};
  EXPECT_EQ(vector0.Dot(Direction(0.0, 1.0, 0.0)), 4.56);
  EXPECT_EQ(Direction(0.0, 0.0, -1.0).Dot(vector0), -7.89);
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
  const Direction direction0{1.0, 0.0, 0.0};
  const Direction direction1{0.0, 1.0, 0.0};
  const Direction direction2{0.0, 0.0, 1.0};
  const Direction direction3{-1.0, 0.0, 0.0};
  const Direction direction4{1.11, 2.22, 3.33};
  const Direction direction5{1.23, 4.56, 7.89};
  const std::hash<Direction> hasher;
  EXPECT_NE(hasher(direction0), hasher(direction1));
  EXPECT_NE(hasher(direction0), hasher(direction2));
  EXPECT_NE(hasher(direction0), hasher(direction3));
  EXPECT_NE(hasher(direction0), hasher(direction4));
  EXPECT_NE(hasher(direction0), hasher(direction5));
  const std::unordered_set<Direction> unordered{
      direction0, direction1, direction2, direction3, direction4, direction5};
}

TEST(Direction, JSON) {
  EXPECT_EQ(
      Direction(0.0, -10.0, 0.0).JSON(), "{\"x\":0,\"y\":-1.000000,\"z\":0}");
}

TEST(Direction, Print) {
  EXPECT_EQ(Direction{}.Print(), "(1.000000, 0, 0)");
  EXPECT_EQ(Direction(0.0, 0.0, -10.0).Print(), "(0, 0, -1.000000)");
}

TEST(Direction, Stream) {
  const Direction direction{1.23, 4.56, 7.89};
  std::ostringstream stream;
  stream << direction;
  EXPECT_EQ(stream.str(), direction.Print());
}

TEST(Direction, Valid) {
  EXPECT_TRUE(Direction(10.0, -20.0, 30.0).Valid());
  EXPECT_FALSE(Direction(0.0, 0.0, 0.0).Valid());
}

TEST(Direction, ValueDyad) {
  const Value::Dyad dyad0{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  EXPECT_EQ(
      dyad0 * Direction(0.0, -10.0, 0.0), Value::Vector(-2.0, -16.0, -128.0));
}

TEST(Direction, ValueSymmetricDyad) {
  const Value::SymmetricDyad symdyad0{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(
      symdyad0 * Direction(0.0, -10.0, 0.0), Value::Vector(-2.0, -8.0, -16.0));
}

TEST(Direction, ValueVector) {
  constexpr Direction direction0{1.0, 2.0, 4.0};
  constexpr Value::Vector vector0{4.0, direction0};
  EXPECT_EQ(vector0.Direction(), direction0);

  constexpr Direction direction1{0.0, 1.0, 0.0};
  constexpr Value::Vector vector1{4.0, direction1};
  EXPECT_EQ(vector1, Value::Vector(0.0, 4.0, 0.0));
}

TEST(Direction, XML) {
  EXPECT_EQ(
      Direction(0.0, -10.0, 0.0).XML(), "<x>0</x><y>-1.000000</y><z>0</z>");
}

TEST(Direction, YAML) {
  EXPECT_EQ(Direction(0.0, -10.0, 0.0).YAML(), "{x:0,y:-1.000000,z:0}");
}

}  // namespace

}  // namespace PhQ
