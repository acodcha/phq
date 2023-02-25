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

namespace {

TEST(Direction, Accessor) {
  const PhQ::Direction direction{0.0, 10.0, -10.0};
  EXPECT_EQ(direction.x(), 0.0);
  EXPECT_DOUBLE_EQ(direction.y(), 0.5 * std::sqrt(2.0));
  EXPECT_DOUBLE_EQ(direction.z(), -0.5 * std::sqrt(2.0));
  const std::array<double, 3> value{0.0, 0.5 * std::sqrt(2.0),
                                    -0.5 * std::sqrt(2.0)};
  EXPECT_EQ(direction.Value().size(), value.size());
  EXPECT_EQ(direction.Value()[0], value[0]);
  EXPECT_DOUBLE_EQ(direction.Value()[1], value[1]);
  EXPECT_DOUBLE_EQ(direction.Value()[2], value[2]);
}

TEST(Direction, Comparison) {
  const PhQ::Direction direction0{1.11, 2.22, 3.33};
  const PhQ::Direction direction1{1.23, 4.56, 7.89};
  EXPECT_EQ(direction0, direction0);
  EXPECT_NE(direction0, direction1);
}

TEST(Direction, Constructor) {
  EXPECT_EQ(PhQ::Direction{}, PhQ::Direction(1.0, 0.0, 0.0));
  EXPECT_EQ(PhQ::Direction(std::array<double, 3>{0.0, -10.0, 0.0}),
            PhQ::Direction(0.0, -1.0, 0.0));
}

TEST(Direction, Cross) {
  EXPECT_EQ(
      PhQ::Direction(10.0, 0.0, 0.0).Cross(PhQ::Direction(0.0, 20.0, 0.0)),
      PhQ::Direction(0.0, 0.0, 30.0));
}

TEST(Direction, Dot) {
  EXPECT_EQ(
      PhQ::Direction(1.23, 4.56, 7.89).Dot(PhQ::Direction(1.23, 4.56, 7.89)),
      1.0);
  EXPECT_EQ(
      PhQ::Direction(0.0, 10.0, -15.0).Dot(PhQ::Direction(20.0, 0.0, 0.0)),
      0.0);
  EXPECT_EQ(
      PhQ::Direction(1.23, 4.56, 7.89).Dot(PhQ::Direction(-1.23, -4.56, -7.89)),
      -1.0);
  EXPECT_LT(
      PhQ::Direction(1.11, 2.22, 3.33).Dot(PhQ::Direction(1.99, 2.88, 3.77)),
      1.0);
  EXPECT_GT(
      PhQ::Direction(1.11, 2.22, 3.33).Dot(PhQ::Direction(1.99, 2.88, 3.77)),
      0.0);
}

TEST(Direction, Hash) {
  const PhQ::Direction direction0{1.0, 0.0, 0.0};
  const PhQ::Direction direction1{0.0, 1.0, 0.0};
  const PhQ::Direction direction2{0.0, 0.0, 1.0};
  const PhQ::Direction direction3{-1.0, 0.0, 0.0};
  const PhQ::Direction direction4{1.11, 2.22, 3.33};
  const PhQ::Direction direction5{1.23, 4.56, 7.89};
  const std::hash<PhQ::Direction> hasher;
  EXPECT_NE(hasher(direction0), hasher(direction1));
  EXPECT_NE(hasher(direction0), hasher(direction2));
  EXPECT_NE(hasher(direction0), hasher(direction3));
  EXPECT_NE(hasher(direction0), hasher(direction4));
  EXPECT_NE(hasher(direction0), hasher(direction5));
  const std::unordered_set<PhQ::Direction> unordered{
      direction0, direction1, direction2, direction3, direction4, direction5};
}

TEST(Direction, Json) {
  EXPECT_EQ(PhQ::Direction(0.0, -10.0, 0.0).Json(),
            "{\"x\":0,\"y\":-1.000000,\"z\":0}");
}

TEST(Direction, Print) {
  EXPECT_EQ(PhQ::Direction{}.Print(), "(1.000000, 0, 0)");
  EXPECT_EQ(PhQ::Direction(0.0, 0.0, -10.0).Print(), "(0, 0, -1.000000)");
}

TEST(Direction, Stream) {
  const PhQ::Direction direction{1.23, 4.56, 7.89};
  std::ostringstream stream;
  stream << direction;
  EXPECT_EQ(stream.str(), direction.Print());
}

TEST(Direction, Xml) {
  EXPECT_EQ(PhQ::Direction(0.0, -10.0, 0.0).Xml(),
            "<x>0</x><y>-1.000000</y><z>0</z>");
}

TEST(Direction, Yaml) {
  EXPECT_EQ(PhQ::Direction(0.0, -10.0, 0.0).Yaml(), "{x:0,y:-1.000000,z:0}");
}

}  // namespace
