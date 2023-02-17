// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#include "../include/PhQ/Direction.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace {

TEST(Direction, Accessor) {
  const PhQ::Direction object{0.0, 10.0, -10.0};
  EXPECT_EQ(object.x(), 0.0);
  EXPECT_DOUBLE_EQ(object.y(), 0.5 * std::sqrt(2.0));
  EXPECT_DOUBLE_EQ(object.z(), -0.5 * std::sqrt(2.0));
}

TEST(Direction, Comparison) {
  const PhQ::Direction object0{1.11, 2.22, 3.33};
  const PhQ::Direction object1{1.23, 4.56, 7.89};
  EXPECT_EQ(object0, object0);
  EXPECT_NE(object0, object1);
}

TEST(Direction, Constructor) {
  EXPECT_EQ(PhQ::Direction{}, PhQ::Direction(1.0, 0.0, 0.0));
  EXPECT_EQ(PhQ::Direction(std::array<double, 3>{0.0, -10.0, 0.0}), PhQ::Direction(0.0, -1.0, 0.0));
}

TEST(Direction, Cross) {
  EXPECT_EQ(PhQ::Direction(10.0, 0.0, 0.0).cross(PhQ::Direction(0.0, 20.0, 0.0)), PhQ::Direction(0.0, 0.0, 30.0));
}

TEST(Direction, Dot) {
  EXPECT_EQ(PhQ::Direction(1.23, 4.56, 7.89).dot(PhQ::Direction(1.23, 4.56, 7.89)), 1.0);
  EXPECT_EQ(PhQ::Direction(0.0, 10.0, -15.0).dot(PhQ::Direction(20.0, 0.0, 0.0)), 0.0);
  EXPECT_EQ(PhQ::Direction(1.23, 4.56, 7.89).dot(PhQ::Direction(-1.23, -4.56, -7.89)), -1.0);
  EXPECT_LT(PhQ::Direction(1.11, 2.22, 3.33).dot(PhQ::Direction(1.99, 2.88, 3.77)), 1.0);
  EXPECT_GT(PhQ::Direction(1.11, 2.22, 3.33).dot(PhQ::Direction(1.99, 2.88, 3.77)), 0.0);
}

TEST(Direction, Hash) {
  const PhQ::Direction object0{1.0, 0.0, 0.0};
  const PhQ::Direction object1{0.0, 1.0, 0.0};
  const PhQ::Direction object2{0.0, 0.0, 1.0};
  const PhQ::Direction object3{-1.0, 0.0, 0.0};
  const PhQ::Direction object4{1.11, 2.22, 3.33};
  const PhQ::Direction object5{1.23, 4.56, 7.89};
  const std::hash<PhQ::Direction> hasher;
  EXPECT_NE(hasher(object0), hasher(object1));
  EXPECT_NE(hasher(object0), hasher(object2));
  EXPECT_NE(hasher(object0), hasher(object3));
  EXPECT_NE(hasher(object0), hasher(object4));
  EXPECT_NE(hasher(object0), hasher(object5));
  const std::unordered_set<PhQ::Direction> unordered{object0, object1, object2, object3, object4, object5};
}

TEST(Direction, Json) {
  EXPECT_EQ(PhQ::Direction(0.0, -10.0, 0.0).json(), "{\"x\":0,\"y\":-1.000000,\"z\":0}");
}

TEST(Direction, Magnitude) {
  EXPECT_EQ(PhQ::Direction(1.23, 4.56, 7.89).magnitude(), 1.0);
  EXPECT_EQ(PhQ::Direction(1.23, 4.56, 7.89).magnitude_squared(), 1.0);
}

TEST(Direction, Print) {
  EXPECT_EQ(PhQ::Direction{}.print(), "(1.000000, 0, 0)");
  EXPECT_EQ(PhQ::Direction(0.0, 0.0, -10.0).print(), "(0, 0, -1.000000)");
}

TEST(Direction, Stream) {
  const PhQ::Direction object{1.23, 4.56, 7.89};
  std::ostringstream output_string_stream;
  output_string_stream << object;
  EXPECT_EQ(output_string_stream.str(), object.print());
}

TEST(Direction, Xml) {
  EXPECT_EQ(PhQ::Direction(0.0, -10.0, 0.0).xml(), "<x>0</x><y>-1.000000</y><z>0</z>");
}

TEST(Direction, Yaml) {
  EXPECT_EQ(PhQ::Direction(0.0, -10.0, 0.0).yaml(), "{x:0,y:-1.000000,z:0}");
}

}  // namespace
