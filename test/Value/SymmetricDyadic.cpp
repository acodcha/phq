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

#include "../../include/PhQ/Value/SymmetricDyadic.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(ValueSymmetricDyadic, Accessor) {
  const Value::SymmetricDyadic symmetric{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  EXPECT_EQ(symmetric.xx(), 1.11);
  EXPECT_EQ(symmetric.xy(), 2.22);
  EXPECT_EQ(symmetric.xz(), 3.33);
  EXPECT_EQ(symmetric.yx(), 2.22);
  EXPECT_EQ(symmetric.yy(), 4.44);
  EXPECT_EQ(symmetric.yz(), 5.55);
  EXPECT_EQ(symmetric.zx(), 3.33);
  EXPECT_EQ(symmetric.zy(), 5.55);
  EXPECT_EQ(symmetric.zz(), 6.66);
}

TEST(ValueSymmetricDyadic, Adjugate) {
  EXPECT_EQ(Value::SymmetricDyadic(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).adjugate(),
            Value::SymmetricDyadic(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyadic, Arithmetic) {
  const Value::SymmetricDyadic symmetric0{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(symmetric0 + symmetric0,
            Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(symmetric0 - symmetric0,
            Value::SymmetricDyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(symmetric0 * 2.0,
            Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(2.0 * symmetric0,
            Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(symmetric0 * Direction(0.0, -10.0, 0.0),
            Value::Vector(-2.0, -8.0, -16.0));
  EXPECT_EQ(symmetric0 * Value::Vector(1.0, 2.0, 3.0),
            Value::Vector(17.0, 66.0, 132.0));
  EXPECT_EQ(symmetric0 / 2.0,
            Value::SymmetricDyadic(0.5, 1.0, 2.0, 4.0, 8.0, 16.0));

  Value::SymmetricDyadic symmetric1{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symmetric1 += Value::SymmetricDyadic{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(symmetric1,
            Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));

  Value::SymmetricDyadic symmetric2{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symmetric2 -= Value::SymmetricDyadic{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(symmetric2, Value::SymmetricDyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

  Value::SymmetricDyadic symmetric3{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symmetric3 *= 2.0;
  EXPECT_EQ(symmetric3,
            Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));

  Value::SymmetricDyadic symmetric4{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symmetric4 /= 2.0;
  EXPECT_EQ(symmetric4, Value::SymmetricDyadic(0.5, 1.0, 2.0, 4.0, 8.0, 16.0));
}

TEST(ValueSymmetricDyadic, Cofactors) {
  EXPECT_EQ(Value::SymmetricDyadic(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).cofactors(),
            Value::SymmetricDyadic(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyadic, Comparison) {
  const Value::SymmetricDyadic symmetric0{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const Value::SymmetricDyadic symmetric1{1.99, 2.88, 3.77, 4.66, 5.55, 6.44};
  EXPECT_EQ(symmetric0, symmetric0);
  EXPECT_NE(symmetric0, symmetric1);
}

TEST(ValueSymmetricDyadic, Constructor) {
  EXPECT_EQ(Value::SymmetricDyadic(
                std::array<double, 6>{1.11, 2.22, 3.33, 4.44, 5.55, 6.66}),
            Value::SymmetricDyadic(1.11, 2.22, 3.33, 4.44, 5.55, 6.66));
}

TEST(ValueSymmetricDyadic, Determinant) {
  EXPECT_EQ(
      Value::SymmetricDyadic(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).determinant(),
      3840.0);
}

TEST(ValueSymmetricDyadic, Hash) {
  const Value::SymmetricDyadic symmetric0{10.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Value::SymmetricDyadic symmetric1{0.0, 10.0, 0.0, 0.0, 0.0, 0.0};
  const Value::SymmetricDyadic symmetric2{0.0, 0.0, 10.0, 0.0, 0.0, 0.0};
  const Value::SymmetricDyadic symmetric3{-10.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Value::SymmetricDyadic symmetric4{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const Value::SymmetricDyadic symmetric5{1.99, 2.88, 3.77, 4.66, 5.55, 6.44};
  const std::hash<Value::SymmetricDyadic> hasher;
  EXPECT_NE(hasher(symmetric0), hasher(symmetric1));
  EXPECT_NE(hasher(symmetric0), hasher(symmetric2));
  EXPECT_NE(hasher(symmetric0), hasher(symmetric3));
  EXPECT_NE(hasher(symmetric0), hasher(symmetric4));
  EXPECT_NE(hasher(symmetric0), hasher(symmetric5));
  const std::unordered_set<Value::SymmetricDyadic> unordered{
      symmetric0, symmetric1, symmetric2, symmetric3, symmetric4, symmetric5};
}

TEST(ValueSymmetricDyadic, Inverse) {
  const Value::SymmetricDyadic symmetric{8.0, 2.0, 1.0, 16.0, 4.0, 32.0};
  const Value::SymmetricDyadic inverse{symmetric.inverse()};
  EXPECT_DOUBLE_EQ(inverse.xx(), 496.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.xy(), -60.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.xz(), -8.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.yy(), 255.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.yz(), -30.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.zz(), 124.0 / 3840.0);
}

TEST(ValueSymmetricDyadic, IsSymmetric) {
  EXPECT_TRUE(Value::SymmetricDyadic(1.11, 2.22, 3.33, 4.44, 5.55, 6.66)
                  .is_symmetric());
}

TEST(ValueSymmetricDyadic, Json) {
  EXPECT_EQ(Value::SymmetricDyadic(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).json(),
            "{\"xx\":1.000000,\"xy\":-2.000000,\"xz\":4.000000,\"yy\":0,\"yz\":"
            "-4.000000,\"zz\":0}");
}

TEST(ValueSymmetricDyadic, Print) {
  EXPECT_EQ(Value::SymmetricDyadic(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).print(),
            "(1.000000, -2.000000, 4.000000; 0, -4.000000; 0)");
}

TEST(ValueSymmetricDyadic, Stream) {
  const Value::SymmetricDyadic symmetric{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  std::ostringstream stream;
  stream << symmetric;
  EXPECT_EQ(stream.str(), symmetric.print());
}

TEST(ValueSymmetricDyadic, Trace) {
  EXPECT_EQ(Value::SymmetricDyadic(1.0, 2.0, 4.0, 8.0, 16.0, 32.0).trace(),
            41.0);
}

TEST(ValueSymmetricDyadic, Transpose) {
  const Value::SymmetricDyadic symmetric{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  EXPECT_EQ(symmetric.transpose(), symmetric);
}

TEST(ValueSymmetricDyadic, Xml) {
  EXPECT_EQ(Value::SymmetricDyadic(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).xml(),
            "<xx>1.000000</xx><xy>-2.000000</xy><xz>4.000000</xz><yy>0</"
            "yy><yz>-4.000000</yz><zz>0</zz>");
}

TEST(ValueSymmetricDyadic, Yaml) {
  EXPECT_EQ(Value::SymmetricDyadic(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).yaml(),
            "{xx:1.000000,xy:-2.000000,xz:4.000000,yy:0,yz:-4.000000,zz:0}");
}

TEST(ValueSymmetricDyadic, Zero) {
  EXPECT_EQ(Value::SymmetricDyadic::Zero(),
            Value::SymmetricDyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
