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

#include "../../include/PhQ/Value/SymmetricDyad.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ {

namespace {

TEST(ValueSymmetricDyad, Accessor) {
  const std::array<double, 6> value0{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const Value::SymmetricDyad symdyad0{value0};
  EXPECT_EQ(symdyad0.xx_xy_xz_yy_yz_zz(), value0);
  EXPECT_EQ(symdyad0.xx(), 1.11);
  EXPECT_EQ(symdyad0.xy(), 2.22);
  EXPECT_EQ(symdyad0.xz(), 3.33);
  EXPECT_EQ(symdyad0.yx(), 2.22);
  EXPECT_EQ(symdyad0.yy(), 4.44);
  EXPECT_EQ(symdyad0.yz(), 5.55);
  EXPECT_EQ(symdyad0.zx(), 3.33);
  EXPECT_EQ(symdyad0.zy(), 5.55);
  EXPECT_EQ(symdyad0.zz(), 6.66);

  Value::SymmetricDyad symdyad1{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  std::array<double, 6>& value1{symdyad1.Mutable_xx_xy_xz_yy_yz_zz()};
  value1 = {0.11, 0.22, 0.33, 0.44, 0.55, 0.66};
  EXPECT_EQ(symdyad1.xx(), 0.11);
  EXPECT_EQ(symdyad1.xy(), 0.22);
  EXPECT_EQ(symdyad1.xz(), 0.33);
  EXPECT_EQ(symdyad1.yy(), 0.44);
  EXPECT_EQ(symdyad1.yz(), 0.55);
  EXPECT_EQ(symdyad1.zz(), 0.66);

  Value::SymmetricDyad symdyad2{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  double& xx{symdyad2.Mutable_xx()};
  xx = 0.11;
  double& xy{symdyad2.Mutable_xy()};
  xy = 0.22;
  double& xz{symdyad2.Mutable_xz()};
  xz = 0.33;
  double& yy{symdyad2.Mutable_yy()};
  yy = 0.44;
  double& yz{symdyad2.Mutable_yz()};
  yz = 0.55;
  double& zz{symdyad2.Mutable_zz()};
  zz = 0.66;
  EXPECT_EQ(symdyad2.xx(), 0.11);
  EXPECT_EQ(symdyad2.xy(), 0.22);
  EXPECT_EQ(symdyad2.xz(), 0.33);
  EXPECT_EQ(symdyad2.yy(), 0.44);
  EXPECT_EQ(symdyad2.yz(), 0.55);
  EXPECT_EQ(symdyad2.zz(), 0.66);

  Value::SymmetricDyad symdyad3{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  double& yx{symdyad3.Mutable_yx()};
  yx = 0.11;
  double& zx{symdyad3.Mutable_zx()};
  zx = 0.22;
  double& zy{symdyad3.Mutable_zy()};
  zy = 0.33;
  EXPECT_EQ(symdyad3.yx(), 0.11);
  EXPECT_EQ(symdyad3.zx(), 0.22);
  EXPECT_EQ(symdyad3.zy(), 0.33);

  Value::SymmetricDyad symdyad4{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  symdyad4.Set_xx_xy_xz_yy_yz_zz({0.11, 0.22, 0.33, 0.44, 0.55, 0.66});
  EXPECT_EQ(symdyad4.xx(), 0.11);
  EXPECT_EQ(symdyad4.xy(), 0.22);
  EXPECT_EQ(symdyad4.xz(), 0.33);
  EXPECT_EQ(symdyad4.yy(), 0.44);
  EXPECT_EQ(symdyad4.yz(), 0.55);
  EXPECT_EQ(symdyad4.zz(), 0.66);

  Value::SymmetricDyad symdyad5{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  symdyad5.Set_xx(0.11);
  symdyad5.Set_xy(0.22);
  symdyad5.Set_xz(0.33);
  symdyad5.Set_yy(0.44);
  symdyad5.Set_yz(0.55);
  symdyad5.Set_zz(0.66);
  EXPECT_EQ(symdyad5.xx(), 0.11);
  EXPECT_EQ(symdyad5.xy(), 0.22);
  EXPECT_EQ(symdyad5.xz(), 0.33);
  EXPECT_EQ(symdyad5.yy(), 0.44);
  EXPECT_EQ(symdyad5.yz(), 0.55);
  EXPECT_EQ(symdyad5.zz(), 0.66);

  Value::SymmetricDyad symdyad6{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  symdyad6.Set_yx(0.11);
  symdyad6.Set_zx(0.22);
  symdyad6.Set_zy(0.33);
  EXPECT_EQ(symdyad6.yx(), 0.11);
  EXPECT_EQ(symdyad6.zx(), 0.22);
  EXPECT_EQ(symdyad6.zy(), 0.33);
}

TEST(ValueSymmetricDyad, Adjugate) {
  EXPECT_EQ(Value::SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Adjugate(),
            Value::SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyad, Arithmetic) {
  const Value::SymmetricDyad symdyad0{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(symdyad0 + symdyad0,
            Value::SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(symdyad0 - symdyad0,
            Value::SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(symdyad0 * 2.0,
            Value::SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(2.0 * symdyad0,
            Value::SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(symdyad0 * Direction(0.0, -10.0, 0.0),
            Value::Vector(-2.0, -8.0, -16.0));
  EXPECT_EQ(symdyad0 * Value::Vector(1.0, 2.0, 3.0),
            Value::Vector(17.0, 66.0, 132.0));
  EXPECT_EQ(symdyad0 / 2.0,
            Value::SymmetricDyad(0.5, 1.0, 2.0, 4.0, 8.0, 16.0));

  Value::SymmetricDyad symdyad1{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symdyad1 += Value::SymmetricDyad{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(symdyad1, Value::SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));

  Value::SymmetricDyad symdyad2{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symdyad2 -= Value::SymmetricDyad{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(symdyad2, Value::SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

  Value::SymmetricDyad symdyad3{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symdyad3 *= 2.0;
  EXPECT_EQ(symdyad3, Value::SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));

  Value::SymmetricDyad symdyad4{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symdyad4 /= 2.0;
  EXPECT_EQ(symdyad4, Value::SymmetricDyad(0.5, 1.0, 2.0, 4.0, 8.0, 16.0));
}

TEST(ValueSymmetricDyad, Cofactors) {
  EXPECT_EQ(Value::SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Cofactors(),
            Value::SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyad, Comparison) {
  const Value::SymmetricDyad symdyad0{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const Value::SymmetricDyad symdyad1{1.99, 2.88, 3.77, 4.66, 5.55, 6.44};
  EXPECT_EQ(symdyad0, symdyad0);
  EXPECT_NE(symdyad0, symdyad1);
}

TEST(ValueSymmetricDyad, Constructor) {
  EXPECT_EQ(Value::SymmetricDyad(
                std::array<double, 6>{1.11, 2.22, 3.33, 4.44, 5.55, 6.66}),
            Value::SymmetricDyad(1.11, 2.22, 3.33, 4.44, 5.55, 6.66));
}

TEST(ValueSymmetricDyad, Determinant) {
  EXPECT_EQ(Value::SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Determinant(),
            3840.0);
}

TEST(ValueSymmetricDyad, Hash) {
  const Value::SymmetricDyad symdyad0{10.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Value::SymmetricDyad symdyad1{0.0, 10.0, 0.0, 0.0, 0.0, 0.0};
  const Value::SymmetricDyad symdyad2{0.0, 0.0, 10.0, 0.0, 0.0, 0.0};
  const Value::SymmetricDyad symdyad3{-10.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Value::SymmetricDyad symdyad4{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const Value::SymmetricDyad symdyad5{1.99, 2.88, 3.77, 4.66, 5.55, 6.44};
  const std::hash<Value::SymmetricDyad> hasher;
  EXPECT_NE(hasher(symdyad0), hasher(symdyad1));
  EXPECT_NE(hasher(symdyad0), hasher(symdyad2));
  EXPECT_NE(hasher(symdyad0), hasher(symdyad3));
  EXPECT_NE(hasher(symdyad0), hasher(symdyad4));
  EXPECT_NE(hasher(symdyad0), hasher(symdyad5));
  const std::unordered_set<Value::SymmetricDyad> unordered{
      symdyad0, symdyad1, symdyad2, symdyad3, symdyad4, symdyad5};
}

TEST(ValueSymmetricDyad, Inverse) {
  const Value::SymmetricDyad symdyad{8.0, 2.0, 1.0, 16.0, 4.0, 32.0};
  const Value::SymmetricDyad inverse{symdyad.Inverse()};
  EXPECT_DOUBLE_EQ(inverse.xx(), 496.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.xy(), -60.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.xz(), -8.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.yy(), 255.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.yz(), -30.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse.zz(), 124.0 / 3840.0);
}

TEST(ValueSymmetricDyad, Json) {
  EXPECT_EQ(Value::SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Json(),
            "{\"xx\":1.000000,\"xy\":-2.000000,\"xz\":4.000000,\"yy\":0,\"yz\":"
            "-4.000000,\"zz\":0}");
}

TEST(ValueSymmetricDyad, Print) {
  EXPECT_EQ(Value::SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Print(),
            "(1.000000, -2.000000, 4.000000; 0, -4.000000; 0)");
}

TEST(ValueSymmetricDyad, Stream) {
  const Value::SymmetricDyad symdyad{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  std::ostringstream stream;
  stream << symdyad;
  EXPECT_EQ(stream.str(), symdyad.Print());
}

TEST(ValueSymmetricDyad, Trace) {
  EXPECT_EQ(Value::SymmetricDyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0).Trace(), 41.0);
}

TEST(ValueSymmetricDyad, Transpose) {
  const Value::SymmetricDyad symdyad{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  EXPECT_EQ(symdyad.Transpose(), symdyad);
}

TEST(ValueSymmetricDyad, Xml) {
  EXPECT_EQ(Value::SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Xml(),
            "<xx>1.000000</xx><xy>-2.000000</xy><xz>4.000000</xz><yy>0</"
            "yy><yz>-4.000000</yz><zz>0</zz>");
}

TEST(ValueSymmetricDyad, Yaml) {
  EXPECT_EQ(Value::SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Yaml(),
            "{xx:1.000000,xy:-2.000000,xz:4.000000,yy:0,yz:-4.000000,zz:0}");
}

TEST(ValueSymmetricDyad, Zero) {
  EXPECT_EQ(Value::SymmetricDyad::Zero(),
            Value::SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
