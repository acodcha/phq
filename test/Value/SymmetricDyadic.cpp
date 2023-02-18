// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/Value/SymmetricDyadic.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace {

TEST(ValueSymmetricDyadic, Accessor) {
  const PhQ::Value::SymmetricDyadic value{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  EXPECT_EQ(value.xx(), 1.11);
  EXPECT_EQ(value.xy(), 2.22);
  EXPECT_EQ(value.xz(), 3.33);
  EXPECT_EQ(value.yx(), 2.22);
  EXPECT_EQ(value.yy(), 4.44);
  EXPECT_EQ(value.yz(), 5.55);
  EXPECT_EQ(value.zx(), 3.33);
  EXPECT_EQ(value.zy(), 5.55);
  EXPECT_EQ(value.zz(), 6.66);
}

TEST(ValueSymmetricDyadic, Adjugate) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).adjugate(), PhQ::Value::SymmetricDyadic(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyadic, Arithmetic) {
  const PhQ::Value::SymmetricDyadic value0{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(value0 + value0, PhQ::Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(value0 - value0, PhQ::Value::SymmetricDyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(value0 * 2.0, PhQ::Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(2.0 * value0, PhQ::Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(value0 * PhQ::Direction(0.0, -10.0, 0.0), PhQ::Value::Vector(-2.0, -8.0, -16.0));
  EXPECT_EQ(value0 * PhQ::Value::Vector(1.0, 2.0, 3.0), PhQ::Value::Vector(17.0, 66.0, 132.0));
  EXPECT_EQ(value0 / 2.0, PhQ::Value::SymmetricDyadic(0.5, 1.0, 2.0, 4.0, 8.0, 16.0));

  PhQ::Value::SymmetricDyadic value1{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  value1 += PhQ::Value::SymmetricDyadic{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(value1, PhQ::Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));

  PhQ::Value::SymmetricDyadic value2{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  value2 -= PhQ::Value::SymmetricDyadic{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(value2, PhQ::Value::SymmetricDyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

  PhQ::Value::SymmetricDyadic value3{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  value3 *= 2.0;
  EXPECT_EQ(value3, PhQ::Value::SymmetricDyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));

  PhQ::Value::SymmetricDyadic value4{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  value4 /= 2.0;
  EXPECT_EQ(value4, PhQ::Value::SymmetricDyadic(0.5, 1.0, 2.0, 4.0, 8.0, 16.0));
}

TEST(ValueSymmetricDyadic, Cofactors) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).cofactors(), PhQ::Value::SymmetricDyadic(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyadic, Comparison) {
  const PhQ::Value::SymmetricDyadic value0{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const PhQ::Value::SymmetricDyadic value1{1.99, 2.88, 3.77, 4.66, 5.55, 6.44};
  EXPECT_EQ(value0, value0);
  EXPECT_NE(value0, value1);
}

TEST(ValueSymmetricDyadic, Constructor) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic(std::array<double, 6>{1.11, 2.22, 3.33, 4.44, 5.55, 6.66}), PhQ::Value::SymmetricDyadic(1.11, 2.22, 3.33, 4.44, 5.55, 6.66));
}

TEST(ValueSymmetricDyadic, Determinant) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).determinant(), 3840.0);
}

TEST(ValueSymmetricDyadic, Hash) {
  const PhQ::Value::SymmetricDyadic value0{10.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const PhQ::Value::SymmetricDyadic value1{0.0, 10.0, 0.0, 0.0, 0.0, 0.0};
  const PhQ::Value::SymmetricDyadic value2{0.0, 0.0, 10.0, 0.0, 0.0, 0.0};
  const PhQ::Value::SymmetricDyadic value3{-10.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const PhQ::Value::SymmetricDyadic value4{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const PhQ::Value::SymmetricDyadic value5{1.99, 2.88, 3.77, 4.66, 5.55, 6.44};
  const std::hash<PhQ::Value::SymmetricDyadic> hasher;
  EXPECT_NE(hasher(value0), hasher(value1));
  EXPECT_NE(hasher(value0), hasher(value2));
  EXPECT_NE(hasher(value0), hasher(value3));
  EXPECT_NE(hasher(value0), hasher(value4));
  EXPECT_NE(hasher(value0), hasher(value5));
  const std::unordered_set<PhQ::Value::SymmetricDyadic> unordered{value0, value1, value2, value3, value4, value5};
}

TEST(ValueSymmetricDyadic, Inverse) {
  const PhQ::Value::SymmetricDyadic value{8.0, 2.0, 1.0, 16.0, 4.0, 32.0};
  const PhQ::Value::SymmetricDyadic inverse{value.inverse()};
  EXPECT_DOUBLE_EQ(inverse.xx(), 496.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.xy(), -60.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.xz(), -8.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.yy(), 255.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.yz(), -30.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.zz(), 124.0 / 3840.0);
}

TEST(ValueSymmetricDyadic, IsSymmetric) {
  EXPECT_TRUE(PhQ::Value::SymmetricDyadic(1.11, 2.22, 3.33, 4.44, 5.55, 6.66).is_symmetric());
}

TEST(ValueSymmetricDyadic, Json) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).json(), "{\"xx\":1.000000,\"xy\":-2.000000,\"xz\":4.000000,\"yy\":0,\"yz\":-4.000000,\"zz\":0}");
}

TEST(ValueSymmetricDyadic, Print) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).print(), "(1.000000, -2.000000, 4.000000; 0, -4.000000; 0)");
}

TEST(ValueSymmetricDyadic, Stream) {
  const PhQ::Value::SymmetricDyadic value{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  std::ostringstream output_string_stream;
  output_string_stream << value;
  EXPECT_EQ(output_string_stream.str(), value.print());
}

TEST(ValueSymmetricDyadic, Trace) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic(1.0, 2.0, 4.0, 8.0, 16.0, 32.0).trace(), 41.0);
}

TEST(ValueSymmetricDyadic, Transpose) {
  const PhQ::Value::SymmetricDyadic value{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  EXPECT_EQ(value.transpose(), value);
}

TEST(ValueSymmetricDyadic, Xml) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).xml(), "<xx>1.000000</xx><xy>-2.000000</xy><xz>4.000000</xz><yy>0</yy><yz>-4.000000</yz><zz>0</zz>");
}

TEST(ValueSymmetricDyadic, Yaml) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).yaml(), "{xx:1.000000,xy:-2.000000,xz:4.000000,yy:0,yz:-4.000000,zz:0}");
}

TEST(ValueSymmetricDyadic, Zero) {
  EXPECT_EQ(PhQ::Value::SymmetricDyadic::Zero(), PhQ::Value::SymmetricDyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace
