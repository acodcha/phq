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

namespace PhQ::Value {

namespace {

TEST(ValueSymmetricDyad, Accessor) {
  const std::array<double, 6> value0{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const SymmetricDyad symdyad0{value0};
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

  SymmetricDyad symdyad1{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  std::array<double, 6>& value1{symdyad1.mutable_xx_xy_xz_yy_yz_zz()};
  value1 = {0.11, 0.22, 0.33, 0.44, 0.55, 0.66};
  EXPECT_EQ(symdyad1.xx(), 0.11);
  EXPECT_EQ(symdyad1.xy(), 0.22);
  EXPECT_EQ(symdyad1.xz(), 0.33);
  EXPECT_EQ(symdyad1.yy(), 0.44);
  EXPECT_EQ(symdyad1.yz(), 0.55);
  EXPECT_EQ(symdyad1.zz(), 0.66);

  SymmetricDyad symdyad2{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  double& xx{symdyad2.mutable_xx()};
  xx = 0.11;
  double& xy{symdyad2.mutable_xy()};
  xy = 0.22;
  double& xz{symdyad2.mutable_xz()};
  xz = 0.33;
  double& yy{symdyad2.mutable_yy()};
  yy = 0.44;
  double& yz{symdyad2.mutable_yz()};
  yz = 0.55;
  double& zz{symdyad2.mutable_zz()};
  zz = 0.66;
  EXPECT_EQ(symdyad2.xx(), 0.11);
  EXPECT_EQ(symdyad2.xy(), 0.22);
  EXPECT_EQ(symdyad2.xz(), 0.33);
  EXPECT_EQ(symdyad2.yy(), 0.44);
  EXPECT_EQ(symdyad2.yz(), 0.55);
  EXPECT_EQ(symdyad2.zz(), 0.66);

  SymmetricDyad symdyad3{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  double& yx{symdyad3.mutable_yx()};
  yx = 0.11;
  double& zx{symdyad3.mutable_zx()};
  zx = 0.22;
  double& zy{symdyad3.mutable_zy()};
  zy = 0.33;
  EXPECT_EQ(symdyad3.yx(), 0.11);
  EXPECT_EQ(symdyad3.zx(), 0.22);
  EXPECT_EQ(symdyad3.zy(), 0.33);

  SymmetricDyad symdyad4{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  symdyad4.set_xx_xy_xz_yy_yz_zz({0.11, 0.22, 0.33, 0.44, 0.55, 0.66});
  EXPECT_EQ(symdyad4.xx(), 0.11);
  EXPECT_EQ(symdyad4.xy(), 0.22);
  EXPECT_EQ(symdyad4.xz(), 0.33);
  EXPECT_EQ(symdyad4.yy(), 0.44);
  EXPECT_EQ(symdyad4.yz(), 0.55);
  EXPECT_EQ(symdyad4.zz(), 0.66);

  SymmetricDyad symdyad5{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  symdyad5.set_xx(0.11);
  symdyad5.set_xy(0.22);
  symdyad5.set_xz(0.33);
  symdyad5.set_yy(0.44);
  symdyad5.set_yz(0.55);
  symdyad5.set_zz(0.66);
  EXPECT_EQ(symdyad5.xx(), 0.11);
  EXPECT_EQ(symdyad5.xy(), 0.22);
  EXPECT_EQ(symdyad5.xz(), 0.33);
  EXPECT_EQ(symdyad5.yy(), 0.44);
  EXPECT_EQ(symdyad5.yz(), 0.55);
  EXPECT_EQ(symdyad5.zz(), 0.66);

  SymmetricDyad symdyad6{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  symdyad6.set_yx(0.11);
  symdyad6.set_zx(0.22);
  symdyad6.set_zy(0.33);
  EXPECT_EQ(symdyad6.yx(), 0.11);
  EXPECT_EQ(symdyad6.zx(), 0.22);
  EXPECT_EQ(symdyad6.zy(), 0.33);
}

TEST(ValueSymmetricDyad, Adjugate) {
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Adjugate(),
            SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyad, Arithmetic) {
  const SymmetricDyad symdyad0{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(symdyad0 + symdyad0,
            SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(symdyad0 - symdyad0, SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(symdyad0 * 2.0, SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(2.0 * symdyad0, SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));
  EXPECT_EQ(symdyad0 * Vector(1.0, 2.0, 3.0), Vector(17.0, 66.0, 132.0));
  EXPECT_EQ(symdyad0 / 2.0, SymmetricDyad(0.5, 1.0, 2.0, 4.0, 8.0, 16.0));

  SymmetricDyad symdyad1{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symdyad1 += SymmetricDyad{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(symdyad1, SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));

  SymmetricDyad symdyad2{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symdyad2 -= SymmetricDyad{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  EXPECT_EQ(symdyad2, SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

  SymmetricDyad symdyad3{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symdyad3 *= 2.0;
  EXPECT_EQ(symdyad3, SymmetricDyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0));

  SymmetricDyad symdyad4{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  symdyad4 /= 2.0;
  EXPECT_EQ(symdyad4, SymmetricDyad(0.5, 1.0, 2.0, 4.0, 8.0, 16.0));
}

TEST(ValueSymmetricDyad, Cofactors) {
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Cofactors(),
            SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyad, Comparison) {
  const SymmetricDyad symdyad0{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const SymmetricDyad symdyad1{1.99, 2.88, 3.77, 4.66, 5.55, 6.44};
  EXPECT_EQ(symdyad0, symdyad0);
  EXPECT_NE(symdyad0, symdyad1);
}

TEST(ValueSymmetricDyad, Constructor) {
  EXPECT_EQ(
      SymmetricDyad(std::array<double, 6>{1.11, 2.22, 3.33, 4.44, 5.55, 6.66}),
      SymmetricDyad(1.11, 2.22, 3.33, 4.44, 5.55, 6.66));
}

TEST(ValueSymmetricDyad, Determinant) {
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Determinant(),
            3840.0);
}

TEST(ValueSymmetricDyad, Hash) {
  const SymmetricDyad symdyad0{10.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const SymmetricDyad symdyad1{0.0, 10.0, 0.0, 0.0, 0.0, 0.0};
  const SymmetricDyad symdyad2{0.0, 0.0, 10.0, 0.0, 0.0, 0.0};
  const SymmetricDyad symdyad3{-10.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const SymmetricDyad symdyad4{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  const SymmetricDyad symdyad5{1.99, 2.88, 3.77, 4.66, 5.55, 6.44};
  const std::hash<SymmetricDyad> hasher;
  EXPECT_NE(hasher(symdyad0), hasher(symdyad1));
  EXPECT_NE(hasher(symdyad0), hasher(symdyad2));
  EXPECT_NE(hasher(symdyad0), hasher(symdyad3));
  EXPECT_NE(hasher(symdyad0), hasher(symdyad4));
  EXPECT_NE(hasher(symdyad0), hasher(symdyad5));
  const std::unordered_set<SymmetricDyad> unordered{
      symdyad0, symdyad1, symdyad2, symdyad3, symdyad4, symdyad5};
}

TEST(ValueSymmetricDyad, Inverse) {
  const SymmetricDyad symdyad0{8.0, 2.0, 1.0, 16.0, 4.0, 32.0};
  const std::optional<SymmetricDyad> inverse0{symdyad0.Inverse()};
  EXPECT_TRUE(inverse0.has_value());
  EXPECT_DOUBLE_EQ(inverse0.value().xx(), 496.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse0.value().xy(), -60.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse0.value().xz(), -8.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse0.value().yy(), 255.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse0.value().yz(), -30.0 / 3840.0);
  EXPECT_DOUBLE_EQ(inverse0.value().zz(), 124.0 / 3840.0);

  const SymmetricDyad symdyad1{0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const std::optional<SymmetricDyad> inverse1{symdyad1.Inverse()};
  EXPECT_FALSE(inverse1.has_value());
}

TEST(ValueSymmetricDyad, Json) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Json(),
            "{\"xx\":1.000000,\"xy\":-2.000000,\"xz\":4.000000,\"yy\":0,\"yz\":"
            "-4.000000,\"zz\":0}");
}

TEST(ValueSymmetricDyad, Print) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Print(),
            "(1.000000, -2.000000, 4.000000; 0, -4.000000; 0)");
}

TEST(ValueSymmetricDyad, Stream) {
  const SymmetricDyad symdyad{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  std::ostringstream stream;
  stream << symdyad;
  EXPECT_EQ(stream.str(), symdyad.Print());
}

TEST(ValueSymmetricDyad, Trace) {
  EXPECT_EQ(SymmetricDyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0).Trace(), 41.0);
}

TEST(ValueSymmetricDyad, Transpose) {
  const SymmetricDyad symdyad{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  EXPECT_EQ(symdyad.Transpose(), symdyad);
}

TEST(ValueSymmetricDyad, Xml) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Xml(),
            "<xx>1.000000</xx><xy>-2.000000</xy><xz>4.000000</xz><yy>0</"
            "yy><yz>-4.000000</yz><zz>0</zz>");
}

TEST(ValueSymmetricDyad, Yaml) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Yaml(),
            "{xx:1.000000,xy:-2.000000,xz:4.000000,yy:0,yz:-4.000000,zz:0}");
}

TEST(ValueSymmetricDyad, Zero) {
  EXPECT_EQ(SymmetricDyad::Zero(), SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ::Value
