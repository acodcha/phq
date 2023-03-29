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
  const Position position{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  EXPECT_DOUBLE_EQ(position.Value().x(), 1.0);
  EXPECT_DOUBLE_EQ(position.Value().y(), 2.0);
  EXPECT_DOUBLE_EQ(position.Value().z(), 4.0);
  EXPECT_DOUBLE_EQ(position.Value(Unit::Length::Millimetre).x(), 1.0 * 1000.0);
  EXPECT_DOUBLE_EQ(position.Value(Unit::Length::Millimetre).y(), 2.0 * 1000.0);
  EXPECT_DOUBLE_EQ(position.Value(Unit::Length::Millimetre).z(), 4.0 * 1000.0);
}

TEST(Position, AngleAndMagnitude) {
  const Position position0{{0.0, 2.0, 0.0}, Unit::Length::Metre};
  const Position position1{{0.0, 0.0, 4.0}, Unit::Length::Metre};
  EXPECT_DOUBLE_EQ(position0.Angle(position1).Value(Unit::Angle::Degree), 90.0);
  EXPECT_DOUBLE_EQ(position0.Magnitude().Value(), 2.0);
}

TEST(Position, Arithmetic) {
  const Length length{2.0, Unit::Length::Metre};
  const Direction direction{0.0, -1.0, 0.0};
  const Position position0{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  const Displacement displacement{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  EXPECT_EQ(position0 + position0,
            Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(position0 + displacement,
            Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(displacement + position0,
            Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(position0 - position0,
            Displacement({0.0, 0.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(position0 - displacement,
            Position({0.0, 0.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(displacement - position0,
            Position({0.0, 0.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(position0 * 2.0, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(2.0 * position0, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));
  EXPECT_EQ(direction * length,
            Position({0.0, -2.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(length * direction,
            Position({0.0, -2.0, 0.0}, Unit::Length::Metre));
  EXPECT_EQ(position0 / 2.0, Position({0.5, 1.0, 2.0}, Unit::Length::Metre));

  Position position1{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  position1 += Position{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  EXPECT_EQ(position1, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));

  Position position2{{2.0, 4.0, 8.0}, Unit::Length::Metre};
  position2 -= Position{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  EXPECT_EQ(position2, Position({1.0, 2.0, 4.0}, Unit::Length::Metre));

  Position position3{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  position3 *= 2.0;
  EXPECT_EQ(position3, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));

  Position position4{{2.0, 4.0, 8.0}, Unit::Length::Metre};
  position4 /= 2.0;
  EXPECT_EQ(position4, Position({1.0, 2.0, 4.0}, Unit::Length::Metre));

  Position position5{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  position5 += Displacement{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  EXPECT_EQ(position5, Position({2.0, 4.0, 8.0}, Unit::Length::Metre));

  Position position6{{2.0, 4.0, 8.0}, Unit::Length::Metre};
  position6 -= Displacement{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  EXPECT_EQ(position6, Position({1.0, 2.0, 4.0}, Unit::Length::Metre));
}

TEST(Position, Comparison) {
  const Position position0{{1.0, 2.0, 4.0}, Unit::Length::Metre};
  const Position position1{{1.0, 2.0, -4.0}, Unit::Length::Metre};
  EXPECT_EQ(position0, position0);
  EXPECT_NE(position0, position1);
}

TEST(Position, Constructor) {
  constexpr Position position0;
  const Position position1{{1.0, 2.0, 4.0}, Unit::Length::Millimetre};
  const Position position2{{-1.0, -2.0, -4.0}, Unit::Length::Millimetre};
  constexpr Position position3{
      Position::Create<Unit::Length::Millimetre>({-1.0, -2.0, -4.0})};
  const Direction direction{position1};
  const Angle angle{position1, position2};
  const Length length{position1};
  const Displacement displacement{position1};
}

TEST(Position, Hash) {
  const Position position0{{1.0, 2.0, 4.0}, Unit::Length::Millimetre};
  const Position position1{{1.0, 2.000001, 4.0}, Unit::Length::Millimetre};
  const Position position2{{1.0, 2.0, 5.0}, Unit::Length::Millimetre};
  const Position position3{{1.0, 2.0, -4.0}, Unit::Length::Millimetre};
  const Position position4{{1000000.0, 2000000.0, 4000000.0},
                           Unit::Length::Millimetre};
  const Position position5{{-1.0, -2.0, -4.0}, Unit::Length::Millimetre};
  const std::hash<Position> hasher;
  EXPECT_NE(hasher(position0), hasher(position1));
  EXPECT_NE(hasher(position0), hasher(position2));
  EXPECT_NE(hasher(position0), hasher(position3));
  EXPECT_NE(hasher(position0), hasher(position4));
  EXPECT_NE(hasher(position0), hasher(position5));
  const std::unordered_set<Position> unordered{position0, position1, position2,
                                               position3, position4, position5};
}

TEST(Position, Json) {
  EXPECT_EQ(Position({1.11, 2.22, 4.44}, Unit::Length::Metre).Json(),
            "{\"value\":{\"x\":1.110000,\"y\":2.220000,\"z\":4.440000},"
            "\"unit\":\"m\"}");
  EXPECT_EQ(Position({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .Json(Unit::Length::Millimetre),
            "{\"value\":{\"x\":0,\"y\":-5.000000,\"z\":0},\"unit\":\"mm\"}");
}

TEST(Position, Print) {
  EXPECT_EQ(Position({1.11, 2.22, 4.44}, Unit::Length::Metre).Print(),
            "(1.110000, 2.220000, 4.440000) m");
  EXPECT_EQ(Position({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .Print(Unit::Length::Millimetre),
            "(0, -5.000000, 0) mm");
}

TEST(Position, Stream) {
  const Position position{{1.11, 2.22, 4.44}, Unit::Length::Metre};
  std::ostringstream stream;
  stream << position;
  EXPECT_EQ(stream.str(), position.Print());
}

TEST(Position, Xml) {
  EXPECT_EQ(Position({1.11, 2.22, 4.44}, Unit::Length::Metre).Xml(),
            "<value><x>1.110000</x><y>2.220000</y><z>4.440000</z></"
            "value><unit>m</unit>");
  EXPECT_EQ(Position({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .Xml(Unit::Length::Millimetre),
            "<value><x>0</x><y>-5.000000</y><z>0</z></value><unit>mm</unit>");
}

TEST(Position, Yaml) {
  EXPECT_EQ(Position({1.11, 2.22, 4.44}, Unit::Length::Metre).Yaml(),
            "{value:{x:1.110000,y:2.220000,z:4.440000},unit:\"m\"}");
  EXPECT_EQ(Position({0.0, -5.0, 0.0}, Unit::Length::Millimetre)
                .Yaml(Unit::Length::Millimetre),
            "{value:{x:0,y:-5.000000,z:0},unit:\"mm\"}");
}

}  // namespace

}  // namespace PhQ
