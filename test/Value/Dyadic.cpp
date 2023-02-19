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

#include "../../include/PhQ/Value/Dyadic.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(ValueDyadic, Accessor) {
  const Value::Dyadic dyadic{1.11, 2.22, 3.33, 4.44, 5.55,
                             6.66, 7.77, 8.88, 9.99};
  EXPECT_EQ(dyadic.xx(), 1.11);
  EXPECT_EQ(dyadic.xy(), 2.22);
  EXPECT_EQ(dyadic.xz(), 3.33);
  EXPECT_EQ(dyadic.yx(), 4.44);
  EXPECT_EQ(dyadic.yy(), 5.55);
  EXPECT_EQ(dyadic.yz(), 6.66);
  EXPECT_EQ(dyadic.zx(), 7.77);
  EXPECT_EQ(dyadic.zy(), 8.88);
  EXPECT_EQ(dyadic.zz(), 9.99);
}

TEST(ValueDyadic, Adjugate) {
  EXPECT_EQ(Value::Dyadic(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0)
                .adjugate(),
            Value::Dyadic(32512.0, -992.0, -96.0, -4080.0, 16382.0, -496.0,
                          256.0, -2040.0, 8128.0));
}

TEST(ValueDyadic, Arithmetic) {
  const Value::Vector vector{1.0, 2.0, 4.0};
  const Value::SymmetricDyadic symmetric{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  const Value::Dyadic dyadic0{1.0,  2.0,  4.0,   8.0,  16.0,
                              32.0, 64.0, 128.0, 256.0};
  EXPECT_EQ(dyadic0 + dyadic0, Value::Dyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0,
                                             128.0, 256.0, 512.0));
  EXPECT_EQ(dyadic0 - dyadic0,
            Value::Dyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(dyadic0 * 2.0, Value::Dyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0,
                                         256.0, 512.0));
  EXPECT_EQ(2.0 * dyadic0, Value::Dyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0,
                                         256.0, 512.0));
  EXPECT_EQ(dyadic0 * vector, Value::Vector(21.0, 168.0, 1344.0));
  EXPECT_EQ(symmetric * symmetric, Value::Dyadic(21.0, 82.0, 164.0, 82.0, 324.0,
                                                 648.0, 164.0, 648.0, 1296.0));
  EXPECT_EQ(dyadic0 * symmetric,
            Value::Dyadic(21.0, 82.0, 164.0, 168.0, 656.0, 1312.0, 1344.0,
                          5248.0, 10496.0));
  EXPECT_EQ(symmetric * dyadic0,
            Value::Dyadic(273.0, 546.0, 1092.0, 1090.0, 2180.0, 4360.0, 2180.0,
                          4360.0, 8720.0));
  EXPECT_EQ(dyadic0 * dyadic0,
            Value::Dyadic(273.0, 546.0, 1092.0, 2184.0, 4368.0, 8736.0, 17472.0,
                          34944.0, 69888.0));
  EXPECT_EQ(dyadic0 / 2.0,
            Value::Dyadic(0.5, 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0));

  Value::Dyadic dyadic1{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  dyadic1 += Value::Dyadic{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  EXPECT_EQ(dyadic1, Value::Dyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0,
                                   256.0, 512.0));

  Value::Dyadic dyadic2{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  dyadic2 -= Value::Dyadic{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  EXPECT_EQ(dyadic2,
            Value::Dyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

  Value::Dyadic dyadic3{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  dyadic3 *= 2.0;
  EXPECT_EQ(dyadic3, Value::Dyadic(2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0,
                                   256.0, 512.0));

  Value::Dyadic dyadic4{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  dyadic4 /= 2.0;
  EXPECT_EQ(dyadic4,
            Value::Dyadic(0.5, 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0));
}

TEST(ValueDyadic, Cofactors) {
  EXPECT_EQ(Value::Dyadic(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0)
                .cofactors(),
            Value::Dyadic(32512.0, -4080.0, 256.0, -992.0, 16382.0, -2040.0,
                          -96.0, -496.0, 8128.0));
}

TEST(ValueDyadic, Comparison) {
  const Value::Dyadic dyadic0{1.11, 2.22, 3.33, 4.44, 5.55,
                              6.66, 7.77, 8.88, 9.99};
  const Value::Dyadic dyadic1{1.99, 2.88, 3.77, 4.66, 5.55,
                              6.44, 7.33, 8.22, 9.11};
  EXPECT_EQ(dyadic0, dyadic0);
  EXPECT_NE(dyadic0, dyadic1);
}

TEST(ValueDyadic, Constructor) {
  EXPECT_EQ(
      Value::Dyadic(std::array<double, 9>{1.11, 2.22, 3.33, 4.44, 5.55, 6.66,
                                          7.77, 8.88, 9.99}),
      Value::Dyadic(1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99));
  EXPECT_EQ(
      Value::Dyadic(Value::SymmetricDyadic(1.11, 2.22, 3.33, 4.44, 5.55, 6.66)),
      Value::Dyadic(1.11, 2.22, 3.33, 2.22, 4.44, 5.55, 3.33, 5.55, 6.66));
}

TEST(ValueDyadic, Determinant) {
  EXPECT_EQ(Value::Dyadic(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0)
                .determinant(),
            2064704.0);
}

TEST(ValueDyadic, DyadicProduct) {
  EXPECT_EQ(Direction(1.0, 0.0, 0.0).dyadic(Direction(0.0, -1.0, 0.0)),
            Value::Dyadic(0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(Direction(0.0, 0.0, -1.0).dyadic(Value::Vector(1.0, 2.0, 4.0)),
            Value::Dyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -2.0, -4.0));
  EXPECT_EQ(Value::Vector(1.0, 2.0, 4.0).dyadic(Direction(0.0, -1.0, 0.0)),
            Value::Dyadic(0.0, -1.0, 0.0, 0.0, -2.0, 0.0, 0.0, -4.0, 0.0));
  EXPECT_EQ(
      Value::Vector(1.0, 2.0, 4.0).dyadic(Value::Vector(8.0, 16.0, 32.0)),
      Value::Dyadic(8.0, 16.0, 32.0, 16.0, 32.0, 64.0, 32.0, 64.0, 128.0));
}

TEST(ValueDyadic, Hash) {
  const Value::Dyadic dyadic0{10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Value::Dyadic dyadic1{0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Value::Dyadic dyadic2{0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Value::Dyadic dyadic3{-10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Value::Dyadic dyadic4{1.11, 2.22, 3.33, 4.44, 5.55,
                              6.66, 7.77, 8.88, 9.99};
  const Value::Dyadic dyadic5{1.99, 2.88, 3.77, 4.66, 5.55,
                              6.44, 7.33, 8.22, 9.11};
  const std::hash<Value::Dyadic> hasher;
  EXPECT_NE(hasher(dyadic0), hasher(dyadic1));
  EXPECT_NE(hasher(dyadic0), hasher(dyadic2));
  EXPECT_NE(hasher(dyadic0), hasher(dyadic3));
  EXPECT_NE(hasher(dyadic0), hasher(dyadic4));
  EXPECT_NE(hasher(dyadic0), hasher(dyadic5));
  const std::unordered_set<Value::Dyadic> unordered{dyadic0, dyadic1, dyadic2,
                                                    dyadic3, dyadic4, dyadic5};
}

TEST(ValueDyadic, Inverse) {
  const Value::Dyadic dyadic{64.0, 4.0, 1.0,  16.0, 128.0,
                             8.0,  2.0, 32.0, 256.0};
  const Value::Dyadic inverse{dyadic.inverse()};
  EXPECT_DOUBLE_EQ(inverse.xx(), 32512.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse.xy(), -992.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse.xz(), -96.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse.yx(), -4080.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse.yy(), 16382.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse.yz(), -496.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse.zx(), 256.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse.zy(), -2040.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse.zz(), 8128.0 / 2064704.0);
}

TEST(ValueDyadic, IsSymmetric) {
  EXPECT_FALSE(
      Value::Dyadic(1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99)
          .is_symmetric());
  EXPECT_TRUE(
      Value::Dyadic(1.11, 2.22, 3.33, 2.22, 4.44, 5.55, 3.33, 5.55, 6.66)
          .is_symmetric());
}

TEST(ValueDyadic, Json) {
  EXPECT_EQ(
      Value::Dyadic(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0).json(),
      "{\"xx\":1.000000,\"xy\":-2.000000,\"xz\":0,\"yx\":2.000000,\"yy\":-4."
      "000000,\"yz\":0,\"zx\":4.000000,\"zy\":-8.000000,\"zz\":0}");
}

TEST(ValueDyadic, Print) {
  EXPECT_EQ(
      Value::Dyadic(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0).print(),
      "(1.000000, -2.000000, 0; 2.000000, -4.000000, 0; 4.000000, "
      "-8.000000, 0)");
}

TEST(ValueDyadic, Stream) {
  const Value::Dyadic dyadic{1.11, 2.22, 3.33, 4.44, 5.55,
                             6.66, 7.77, 8.88, 9.99};
  std::ostringstream stream;
  stream << dyadic;
  EXPECT_EQ(stream.str(), dyadic.print());
}

TEST(ValueDyadic, Trace) {
  EXPECT_EQ(
      Value::Dyadic(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).trace(),
      448.0);
}

TEST(ValueDyadic, Transpose) {
  EXPECT_EQ(Value::Dyadic(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0)
                .transpose(),
            Value::Dyadic(64.0, 16.0, 2.0, 4.0, 128.0, 32.0, 1.0, 8.0, 256.0));
}

TEST(ValueDyadic, Xml) {
  EXPECT_EQ(Value::Dyadic(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0).xml(),
            "<xx>1.000000</xx><xy>-2.000000</xy><xz>0</xz><yx>2.000000</"
            "yx><yy>-4.000000</yy><yz>0</yz><zx>4.000000</zx><zy>-8.000000</"
            "zy><zz>0</zz>");
}

TEST(ValueDyadic, Yaml) {
  EXPECT_EQ(
      Value::Dyadic(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0).yaml(),
      "{xx:1.000000,xy:-2.000000,xz:0,yx:2.000000,yy:-4.000000,yz:0,zx:4."
      "000000,zy:-8.000000,zz:0}");
}

TEST(ValueDyadic, Zero) {
  EXPECT_EQ(Value::Dyadic::Zero(),
            Value::Dyadic(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
