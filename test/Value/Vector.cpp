// Copyright 2020 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Value/Vector.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(ValueVector, Accessor) {
  const Value::Vector vector{1.23, 4.56, 7.89};
  EXPECT_EQ(vector.x(), 1.23);
  EXPECT_EQ(vector.y(), 4.56);
  EXPECT_EQ(vector.z(), 7.89);
}

TEST(ValueVector, Arithmetic) {
  const Value::Vector vector0{2.0, 4.0, 8.0};
  EXPECT_EQ(vector0 + vector0, Value::Vector(4.0, 8.0, 16.0));
  EXPECT_EQ(vector0 - vector0, Value::Vector(0.0, 0.0, 0.0));
  EXPECT_EQ(vector0 * 2.0, Value::Vector(4.0, 8.0, 16.0));
  EXPECT_EQ(2.0 * vector0, Value::Vector(4.0, 8.0, 16.0));
  EXPECT_EQ(vector0 / 2.0, Value::Vector(1.0, 2.0, 4.0));

  Value::Vector vector1{1.0, 2.0, 4.0};
  vector1 += Value::Vector{1.0, 2.0, 4.0};
  EXPECT_EQ(vector1, Value::Vector(2.0, 4.0, 8.0));

  Value::Vector vector2{2.0, 4.0, 8.0};
  vector2 -= Value::Vector{1.0, 2.0, 4.0};
  EXPECT_EQ(vector2, Value::Vector(1.0, 2.0, 4.0));

  Value::Vector vector3{1.0, 2.0, 4.0};
  vector3 *= 2.0;
  EXPECT_EQ(vector3, Value::Vector(2.0, 4.0, 8.0));

  Value::Vector vector4{2.0, 4.0, 8.0};
  vector4 /= 2.0;
  EXPECT_EQ(vector4, Value::Vector(1.0, 2.0, 4.0));
}

TEST(ValueVector, Comparison) {
  const Value::Vector vector0{1.11, 2.22, 3.33};
  const Value::Vector vector1{1.23, 4.56, 7.89};
  EXPECT_EQ(vector0, vector0);
  EXPECT_NE(vector0, vector1);
}

TEST(ValueVector, Constructor) {
  EXPECT_EQ(Value::Vector(std::array<double, 3>{1.23, 4.56, 7.89}),
            Value::Vector(1.23, 4.56, 7.89));
  EXPECT_EQ(Value::Vector(-5.5e10, Direction(0.0, -1.0, 0.0)),
            Value::Vector(0.0, 5.5e10, 0.0));
}

TEST(ValueVector, Cross) {
  EXPECT_EQ(Value::Vector(10.0, 0.0, 0.0).cross(Value::Vector(0.0, 20.0, 0.0)),
            Value::Vector(0.0, 0.0, 200.0));
  EXPECT_EQ(Value::Vector(10.0, 0.0, 0.0).cross(Direction(0.0, 20.0, 0.0)),
            Value::Vector(0.0, 0.0, 10.0));
  EXPECT_EQ(Direction(10.0, 0.0, 0.0).cross(Value::Vector(0.0, 20.0, 0.0)),
            Value::Vector(0.0, 0.0, 20.0));
}

TEST(ValueVector, Direction) {
  const Direction direction{1.23, 4.56, 7.89};
  EXPECT_EQ(Value::Vector(5.5e10, direction).direction(), direction);
}

TEST(ValueVector, Dot) {
  const Value::Vector vector0{1.23, 4.56, 7.89};
  EXPECT_EQ(vector0.dot(vector0), vector0.magnitude_squared());
  EXPECT_EQ(Value::Vector(0.0, 10.0, -15.0).dot(Value::Vector(20.0, 0.0, 0.0)),
            0.0);
  EXPECT_EQ(vector0.dot(Value::Vector(-1.23, -4.56, -7.89)),
            -vector0.magnitude_squared());
  EXPECT_EQ(vector0.dot(Direction(0.0, 1.0, 0.0)), 4.56);
  EXPECT_EQ(Direction(0.0, 0.0, -1.0).dot(vector0), -7.89);
}

TEST(ValueVector, Hash) {
  const Value::Vector vector0{10.0, 0.0, 0.0};
  const Value::Vector vector1{0.0, 10.0, 0.0};
  const Value::Vector vector2{0.0, 0.0, 10.0};
  const Value::Vector vector3{-10.0, 0.0, 0.0};
  const Value::Vector vector4{1.11, 2.22, 3.33};
  const Value::Vector vector5{1.23, 4.56, 7.89};
  const std::hash<Value::Vector> hasher;
  EXPECT_NE(hasher(vector0), hasher(vector1));
  EXPECT_NE(hasher(vector0), hasher(vector2));
  EXPECT_NE(hasher(vector0), hasher(vector3));
  EXPECT_NE(hasher(vector0), hasher(vector4));
  EXPECT_NE(hasher(vector0), hasher(vector5));
  const std::unordered_set<Value::Vector> unordered{vector0, vector1, vector2,
                                                    vector3, vector4, vector5};
}

TEST(ValueVector, Json) {
  EXPECT_EQ(Value::Vector(1.0, -2.0, 0.0).json(),
            "{\"x\":1.000000,\"y\":-2.000000,\"z\":0}");
}

TEST(ValueVector, Magnitude) {
  EXPECT_EQ(Value::Vector(0.0, 0.0, 5.5e10).magnitude(), 5.5e10);
  EXPECT_EQ(Value::Vector(-1.0, 2.0, -3.0).magnitude_squared(), 14.0);
}

TEST(ValueVector, Print) {
  EXPECT_EQ(Value::Vector(1.0, -2.0, 0.0).print(), "(1.000000, -2.000000, 0)");
}

TEST(ValueVector, Stream) {
  const Value::Vector vector{1.23, 4.56, 7.89};
  std::ostringstream stream;
  stream << vector;
  EXPECT_EQ(stream.str(), vector.print());
}

TEST(ValueVector, Xml) {
  EXPECT_EQ(Value::Vector(1.0, -2.0, 0.0).xml(),
            "<x>1.000000</x><y>-2.000000</y><z>0</z>");
}

TEST(ValueVector, Yaml) {
  EXPECT_EQ(Value::Vector(1.0, -2.0, 0.0).yaml(),
            "{x:1.000000,y:-2.000000,z:0}");
}

TEST(ValueVector, Zero) {
  EXPECT_EQ(Value::Vector::Zero(), Value::Vector(0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
