// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#include <functional>
#include <gtest/gtest.h>
#include <sstream>

#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

// Since PhQ::DimensionlessVector is an abstract base class, tests use PhQ::Direction, which is one
// of its derived classes.

TEST(DimensionlessVector, Dimensions) {
  EXPECT_EQ(Direction::Dimensions(), Dimensionless);
}

TEST(DimensionlessVector, Hash) {
  const Direction first{1.0, -2.0, 3.0};
  const Direction second{1.0, -2.0, 3.000001};
  const Direction third{1.0, 2.0, 3.0};
  const std::hash<Direction> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(DimensionlessVector, JSON) {
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).JSON(),
            "{\"x\":" + Print(0.0) + ",\"y\":" + Print(-1.0) + ",\"z\":" + Print(0.0) + "}");
}

TEST(DimensionlessVector, Print) {
  EXPECT_EQ(Direction{}.Print(), "(" + Print(0.0) + ", " + Print(0.0) + ", " + Print(0.0) + ")");
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).Print(),
            "(" + Print(0.0) + ", " + Print(-1.0) + ", " + Print(0.0) + ")");
}

TEST(DimensionlessVector, SizeOf) {
  EXPECT_EQ(sizeof(Direction{}), 3 * sizeof(double));
}

TEST(DimensionlessVector, Stream) {
  std::ostringstream stream;
  stream << Direction{1.0, -2.0, 3.0};
  EXPECT_EQ(stream.str(), Direction(1.0, -2.0, 3.0).Print());
}

TEST(DimensionlessVector, Value) {
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).Value(), Vector(0.0, -1.0, 0.0));
}

TEST(DimensionlessVector, XML) {
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).XML(),
            "<x>" + Print(0.0) + "</x><y>" + Print(-1.0) + "</y><z>" + Print(0.0) + "</z>");
}

TEST(DimensionlessVector, YAML) {
  EXPECT_EQ(Direction(0.0, -2.0, 0.0).YAML(),
            "{x:" + Print(0.0) + ",y:" + Print(-1.0) + ",z:" + Print(0.0) + "}");
}

}  // namespace

}  // namespace PhQ
