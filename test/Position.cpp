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

#include <unordered_set>

namespace PhQ {

namespace {

TEST(Position, Accessor) {
  const Position position{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_DOUBLE_EQ(position.Value().x(), 1.0);
  EXPECT_DOUBLE_EQ(position.Value().y(), 2.0);
  EXPECT_DOUBLE_EQ(position.Value().z(), 4.0);
  EXPECT_DOUBLE_EQ(position.Value(Unit::Length::Millimetre).x(), 1.0 * 1000.0);
  EXPECT_DOUBLE_EQ(position.Value(Unit::Length::Millimetre).y(), 2.0 * 1000.0);
  EXPECT_DOUBLE_EQ(position.Value(Unit::Length::Millimetre).z(), 4.0 * 1000.0);
}

TEST(Position, AngleAndMagnitude) {
  const Position position0{
      {0.0, 2.0, 0.0},
      Unit::Length::Metre
  };
  const Position position1{
      {0.0, 0.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_DOUBLE_EQ(position0.Angle(position1).Value(Unit::Angle::Degree), 90.0);
  EXPECT_DOUBLE_EQ(position0.Magnitude().Value(), 2.0);
}

TEST(Position, Arithmetic) {
  const Length length{2.0, Unit::Length::Metre};
  const Direction direction{0.0, -1.0, 0.0};
  const Position position0{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  const Displacement displacement{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(
      position0 + position0, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(
      position0 + displacement, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(
      displacement + position0, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(position0 - position0,
            Displacement({0.0, 0.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(
      position0 - displacement, Position({0.0, 0.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(
      displacement - position0, Position({0.0, 0.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(position0 * 2.0, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(2.0 * position0, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(
      direction * length, Position({0.0, -2.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(
      length * direction, Position({0.0, -2.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(position0 / 2.0, Position({0.5, 1.0, 2.0}, Unit::Length::Metre));

  Position position1{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  position1 += Position{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(position1, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));

  Position position2{
      {2.0, 4.0, 8.0},
      Unit::Length::Metre
  };
  position2 -= Position{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(position2, Position({1.0, 2.0, 4.0}, Unit::Length::Metre));

  Position position3{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  position3 *= 2.0;
  EXPECT_EQ(position3, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));

  Position position4{
      {2.0, 4.0, 8.0},
      Unit::Length::Metre
  };
  position4 /= 2.0;
  EXPECT_EQ(position4, Position({1.0, 2.0, 4.0}, Unit::Length::Metre));

  Position position5{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  position5 += Displacement{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(position5, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));

  Position position6{
      {2.0, 4.0, 8.0},
      Unit::Length::Metre
  };
  position6 -= Displacement{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(position6, Position({1.0, 2.0, 4.0}, Unit::Length::Metre));
}

TEST(Position, Comparison) {
  const Position position0{
      {1.0, 2.0, 4.0},
      Unit::Length::Metre
  };
  const Position position1{
      {1.0, 2.0, 8.0},
      Unit::Length::Metre
  };
  EXPECT_EQ(position0, position0);
  EXPECT_NE(position0, position1);
  EXPECT_LT(position0, position1);
  EXPECT_GT(position1, position0);
  EXPECT_LE(position0, position0);
  EXPECT_LE(position0, position1);
  EXPECT_GE(position0, position0);
  EXPECT_GE(position1, position0);
}

TEST(Position, Constructor) {
  constexpr Position position0{};
  const Position position1{
      {1.0, 2.0, 4.0},
      Unit::Length::Millimetre
  };
  const Position position2{
      {-1.0, -2.0, -4.0},
      Unit::Length::Millimetre
  };
  constexpr Position position3{
      Position::Create<Unit::Length::Millimetre>({-1.0, -2.0, -4.0})};
  const Direction direction{position1};
  const Angle angle{position1, position2};
  const Length length{position1};
  const Displacement displacement{position1};
}

TEST(Position, Copy) {
  const Position reference{
      {1.11, 2.22, 3.33},
      Unit::Length::Metre
  };
  const Position first{reference};
  EXPECT_EQ(first, reference);
  Position second = Position::Zero();
  second = reference;
  EXPECT_EQ(second, reference);
}

TEST(Position, Dimensions) {
  EXPECT_EQ(Position::Dimensions(), RelatedDimensions<Unit::Length>);
}

TEST(Position, Hash) {
  const Position position0{
      {1.0, 2.0, 4.0},
      Unit::Length::Millimetre
  };
  const Position position1{
      {1.0, 2.000001, 4.0},
      Unit::Length::Millimetre
  };
  const Position position2{
      {1.0, 2.0, 5.0},
      Unit::Length::Millimetre
  };
  const Position position3{
      {1.0, 2.0, -4.0},
      Unit::Length::Millimetre
  };
  const Position position4{
      {1000000.0, 2000000.0, 4000000.0},
      Unit::Length::Millimetre
  };
  const Position position5{
      {-1.0, -2.0, -4.0},
      Unit::Length::Millimetre
  };
  const std::hash<Position> hasher;
  EXPECT_NE(hasher(position0), hasher(position1));
  EXPECT_NE(hasher(position0), hasher(position2));
  EXPECT_NE(hasher(position0), hasher(position3));
  EXPECT_NE(hasher(position0), hasher(position4));
  EXPECT_NE(hasher(position0), hasher(position5));
  const std::unordered_set<Position> unordered{
      position0, position1, position2, position3, position4, position5};
}

TEST(Position, JSON) {
  EXPECT_EQ(Position({1.11, 2.22, 4.44}, Unit::Length::Metre).JSON(),
            "{\"value\":{\"x\":1.110000000000000,\"y\":2.220000000000000,\"z\":"
            "4.440000000000000},\"unit\":\"m\"}");
  EXPECT_EQ(Position({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .JSON(Unit::Length::Millimetre),
            "{\"value\":{\"x\":0,\"y\":-5.000000000000000,\"z\":0},\"unit\":"
            "\"mm\"}");
}

TEST(Position, Move) {
  const Position reference{
      {1.11, 2.22, 4.44},
      Unit::Length::Metre
  };
  Position first{
      {1.11, 2.22, 4.44},
      Unit::Length::Metre
  };
  Position second{std::move(first)};
  EXPECT_EQ(second, reference);
  Position third = Position::Zero();
  third = std::move(second);
  EXPECT_EQ(third, reference);
}

TEST(Position, Print) {
  EXPECT_EQ(Position({1.11, 2.22, 4.44}, Unit::Length::Metre).Print(),
            "(1.110000000000000, 2.220000000000000, 4.440000000000000) m");
  EXPECT_EQ(Position({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .Print(Unit::Length::Millimetre),
            "(0, -5.000000000000000, 0) mm");
}

TEST(Position, SizeOf) {
  const Position position{
      {1.11, 2.22, 4.44},
      Unit::Length::Metre
  };
  EXPECT_EQ(sizeof(position), 3 * sizeof(double));
}

TEST(Position, Stream) {
  const Position position{
      {1.11, 2.22, 4.44},
      Unit::Length::Metre
  };
  std::ostringstream stream;
  stream << position;
  EXPECT_EQ(stream.str(), position.Print());
}

TEST(Position, Unit) {
  EXPECT_EQ(Position::Unit(), Standard<Unit::Length>);
}

TEST(Position, XML) {
  EXPECT_EQ(Position({1.11, 2.22, 4.44}, Unit::Length::Metre).XML(),
            "<value><x>1.110000000000000</x><y>2.220000000000000</"
            "y><z>4.440000000000000</z></value><unit>m</unit>");
  EXPECT_EQ(Position({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .XML(Unit::Length::Millimetre),
            "<value><x>0</x><y>-5.000000000000000</y><z>0</z></value><unit>mm</"
            "unit>");
}

TEST(Position, YAML) {
  EXPECT_EQ(Position({1.11, 2.22, 4.44}, Unit::Length::Metre).YAML(),
            "{value:{x:1.110000000000000,y:2.220000000000000,z:4."
            "440000000000000},unit:\"m\"}");
  EXPECT_EQ(Position({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .YAML(Unit::Length::Millimetre),
            "{value:{x:0,y:-5.000000000000000,z:0},unit:\"mm\"}");
}

TEST(Position, Zero) {
  EXPECT_EQ(Position::Zero(), Position({0.0, 0.0, 0.0}, Unit::Length::Metre));
}

}  // namespace

}  // namespace PhQ
