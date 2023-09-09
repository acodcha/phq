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

#include "../../include/PhQ/Value/Dyad.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ::Value {

namespace {

TEST(ValueDyad, Accessor) {
  const std::array<double, 9> value0{
      1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  const Dyad dyad0{value0};
  EXPECT_EQ(dyad0.xx_xy_xz_yx_yy_yz_zx_zy_zz(), value0);
  EXPECT_EQ(dyad0.xx(), 1.11);
  EXPECT_EQ(dyad0.xy(), 2.22);
  EXPECT_EQ(dyad0.xz(), 3.33);
  EXPECT_EQ(dyad0.yx(), 4.44);
  EXPECT_EQ(dyad0.yy(), 5.55);
  EXPECT_EQ(dyad0.yz(), 6.66);
  EXPECT_EQ(dyad0.zx(), 7.77);
  EXPECT_EQ(dyad0.zy(), 8.88);
  EXPECT_EQ(dyad0.zz(), 9.99);

  Dyad dyad1{1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  std::array<double, 9>& value1{dyad1.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz()};
  value1 = {0.11, 0.22, 0.33, 0.44, 0.55, 0.66, 0.77, 0.88, 0.99};
  EXPECT_EQ(dyad1.xx(), 0.11);
  EXPECT_EQ(dyad1.xy(), 0.22);
  EXPECT_EQ(dyad1.xz(), 0.33);
  EXPECT_EQ(dyad1.yx(), 0.44);
  EXPECT_EQ(dyad1.yy(), 0.55);
  EXPECT_EQ(dyad1.yz(), 0.66);
  EXPECT_EQ(dyad1.zx(), 0.77);
  EXPECT_EQ(dyad1.zy(), 0.88);
  EXPECT_EQ(dyad1.zz(), 0.99);

  Dyad dyad2{1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  double& xx{dyad2.Mutable_xx()};
  xx = 0.11;
  double& xy{dyad2.Mutable_xy()};
  xy = 0.22;
  double& xz{dyad2.Mutable_xz()};
  xz = 0.33;
  double& yx{dyad2.Mutable_yx()};
  yx = 0.44;
  double& yy{dyad2.Mutable_yy()};
  yy = 0.55;
  double& yz{dyad2.Mutable_yz()};
  yz = 0.66;
  double& zx{dyad2.Mutable_zx()};
  zx = 0.77;
  double& zy{dyad2.Mutable_zy()};
  zy = 0.88;
  double& zz{dyad2.Mutable_zz()};
  zz = 0.99;
  EXPECT_EQ(dyad2.xx(), 0.11);
  EXPECT_EQ(dyad2.xy(), 0.22);
  EXPECT_EQ(dyad2.xz(), 0.33);
  EXPECT_EQ(dyad2.yx(), 0.44);
  EXPECT_EQ(dyad2.yy(), 0.55);
  EXPECT_EQ(dyad2.yz(), 0.66);
  EXPECT_EQ(dyad2.zx(), 0.77);
  EXPECT_EQ(dyad2.zy(), 0.88);
  EXPECT_EQ(dyad2.zz(), 0.99);

  Dyad dyad3{1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  dyad3.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
      {0.11, 0.22, 0.33, 0.44, 0.55, 0.66, 0.77, 0.88, 0.99});
  EXPECT_EQ(dyad3.xx(), 0.11);
  EXPECT_EQ(dyad3.xy(), 0.22);
  EXPECT_EQ(dyad3.xz(), 0.33);
  EXPECT_EQ(dyad3.yx(), 0.44);
  EXPECT_EQ(dyad3.yy(), 0.55);
  EXPECT_EQ(dyad3.yz(), 0.66);
  EXPECT_EQ(dyad3.zx(), 0.77);
  EXPECT_EQ(dyad3.zy(), 0.88);
  EXPECT_EQ(dyad3.zz(), 0.99);

  Dyad dyad4{1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  dyad4.Set_xx(0.11);
  dyad4.Set_xy(0.22);
  dyad4.Set_xz(0.33);
  dyad4.Set_yx(0.44);
  dyad4.Set_yy(0.55);
  dyad4.Set_yz(0.66);
  dyad4.Set_zx(0.77);
  dyad4.Set_zy(0.88);
  dyad4.Set_zz(0.99);
  EXPECT_EQ(dyad4.xx(), 0.11);
  EXPECT_EQ(dyad4.xy(), 0.22);
  EXPECT_EQ(dyad4.xz(), 0.33);
  EXPECT_EQ(dyad4.yx(), 0.44);
  EXPECT_EQ(dyad4.yy(), 0.55);
  EXPECT_EQ(dyad4.yz(), 0.66);
  EXPECT_EQ(dyad4.zx(), 0.77);
  EXPECT_EQ(dyad4.zy(), 0.88);
  EXPECT_EQ(dyad4.zz(), 0.99);
}

TEST(ValueDyad, Adjugate) {
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Adjugate(),
            Dyad(32512.0, -992.0, -96.0, -4080.0, 16382.0, -496.0, 256.0,
                 -2040.0, 8128.0));
}

TEST(ValueDyad, Arithmetic) {
  const Vector vector{1.0, 2.0, 4.0};
  const SymmetricDyad symdyad{1.0, 2.0, 4.0, 8.0, 16.0, 32.0};
  const Dyad dyad0{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  EXPECT_EQ(dyad0 + dyad0,
            Dyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0));
  EXPECT_EQ(dyad0 - dyad0, Dyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(
      dyad0 * 2.0, Dyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0));
  EXPECT_EQ(
      2.0 * dyad0, Dyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0));
  EXPECT_EQ(dyad0 * vector, Vector(21.0, 168.0, 1344.0));
  EXPECT_EQ(symdyad * symdyad,
            Dyad(21.0, 82.0, 164.0, 82.0, 324.0, 648.0, 164.0, 648.0, 1296.0));
  EXPECT_EQ(dyad0 * symdyad, Dyad(21.0, 82.0, 164.0, 168.0, 656.0, 1312.0,
                                  1344.0, 5248.0, 10496.0));
  EXPECT_EQ(symdyad * dyad0, Dyad(273.0, 546.0, 1092.0, 1090.0, 2180.0, 4360.0,
                                  2180.0, 4360.0, 8720.0));
  EXPECT_EQ(dyad0 * dyad0, Dyad(273.0, 546.0, 1092.0, 2184.0, 4368.0, 8736.0,
                                17472.0, 34944.0, 69888.0));
  EXPECT_EQ(
      dyad0 / 2.0, Dyad(0.5, 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0));

  Dyad dyad1{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  dyad1 += Dyad{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  EXPECT_EQ(dyad1, Dyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0));

  Dyad dyad2{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  dyad2 -= Dyad{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  EXPECT_EQ(dyad2, Dyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));

  Dyad dyad3{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  dyad3 *= 2.0;
  EXPECT_EQ(dyad3, Dyad(2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0));

  Dyad dyad4{1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0};
  dyad4 /= 2.0;
  EXPECT_EQ(dyad4, Dyad(0.5, 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0));
}

TEST(ValueDyad, Cofactors) {
  EXPECT_EQ(
      Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Cofactors(),
      Dyad(32512.0, -4080.0, 256.0, -992.0, 16382.0, -2040.0, -96.0, -496.0,
           8128.0));
}

TEST(ValueDyad, Comparison) {
  constexpr Dyad dyad0{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
  constexpr Dyad dyad1{1.1, 2.2, 3.3, 4.4, 5.6, 6.6, 7.7, 8.8, 9.9};
  constexpr Dyad dyad2{1.1, 2.2, 3.3, 4.4, 5.6, 6.6, 7.7, 8.8, 9.99};
  EXPECT_EQ(dyad0, dyad0);
  EXPECT_NE(dyad0, dyad1);
  EXPECT_LT(dyad0, dyad1);
  EXPECT_LT(dyad1, dyad2);
  EXPECT_GT(dyad1, dyad0);
  EXPECT_GT(dyad2, dyad1);
  EXPECT_LE(dyad0, dyad0);
  EXPECT_LE(dyad0, dyad1);
  EXPECT_LE(dyad1, dyad2);
  EXPECT_GE(dyad0, dyad0);
  EXPECT_GE(dyad1, dyad0);
  EXPECT_GE(dyad2, dyad1);
}

TEST(ValueDyad, Constructor) {
  EXPECT_EQ(Dyad(std::array<double, 9>{
                1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99}),
            Dyad(1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99));
  EXPECT_EQ(Dyad(SymmetricDyad(1.11, 2.22, 3.33, 4.44, 5.55, 6.66)),
            Dyad(1.11, 2.22, 3.33, 2.22, 4.44, 5.55, 3.33, 5.55, 6.66));
}

TEST(ValueDyad, Determinant) {
  EXPECT_EQ(
      Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Determinant(),
      2064704.0);
}

TEST(ValueDyad, DyadicProduct) {
  EXPECT_EQ(Vector(1.0, 2.0, 4.0).Dyadic(Vector(8.0, 16.0, 32.0)),
            Dyad(8.0, 16.0, 32.0, 16.0, 32.0, 64.0, 32.0, 64.0, 128.0));
}

TEST(ValueDyad, Hash) {
  const Dyad dyad0{10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Dyad dyad1{0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Dyad dyad2{0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Dyad dyad3{-10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const Dyad dyad4{1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  const Dyad dyad5{1.99, 2.88, 3.77, 4.66, 5.55, 6.44, 7.33, 8.22, 9.11};
  const std::hash<Dyad> hasher;
  EXPECT_NE(hasher(dyad0), hasher(dyad1));
  EXPECT_NE(hasher(dyad0), hasher(dyad2));
  EXPECT_NE(hasher(dyad0), hasher(dyad3));
  EXPECT_NE(hasher(dyad0), hasher(dyad4));
  EXPECT_NE(hasher(dyad0), hasher(dyad5));
  const std::unordered_set<Dyad> unordered{
      dyad0, dyad1, dyad2, dyad3, dyad4, dyad5};
}

TEST(ValueDyad, Inverse) {
  const Dyad dyad0{64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0};
  const std::optional<Dyad> inverse0{dyad0.Inverse()};
  EXPECT_TRUE(inverse0.has_value());
  EXPECT_DOUBLE_EQ(inverse0.value().xx(), 32512.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse0.value().xy(), -992.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse0.value().xz(), -96.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse0.value().yx(), -4080.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse0.value().yy(), 16382.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse0.value().yz(), -496.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse0.value().zx(), 256.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse0.value().zy(), -2040.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(inverse0.value().zz(), 8128.0 / 2064704.0);

  const Dyad dyad1{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const std::optional<Dyad> inverse1{dyad1.Inverse()};
  EXPECT_FALSE(inverse1.has_value());
}

TEST(ValueDyad, IsSymmetric) {
  EXPECT_FALSE(
      Dyad(1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99).IsSymmetric());
  EXPECT_TRUE(
      Dyad(1.11, 2.22, 3.33, 2.22, 4.44, 5.55, 3.33, 5.55, 6.66).IsSymmetric());
}

TEST(ValueDyad, JSON) {
  EXPECT_EQ(Dyad(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0).JSON(),
            "{\"xx\":1.000000000000000,\"xy\":-2.000000000000000,\"xz\":0,"
            "\"yx\":2.000000000000000,\"yy\":-4.000000000000000,\"yz\":0,"
            "\"zx\":4.000000000000000,\"zy\":-8.000000000000000,\"zz\":0}");
}

TEST(ValueDyad, Print) {
  EXPECT_EQ(Dyad(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0).Print(),
            "(1.000000000000000, -2.000000000000000, 0; 2.000000000000000, "
            "-4.000000000000000, 0; 4.000000000000000, -8.000000000000000, 0)");
  EXPECT_EQ(Dyad(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0)
                .Print(Precision::Double),
            "(1.000000000000000, -2.000000000000000, 0; 2.000000000000000, "
            "-4.000000000000000, 0; 4.000000000000000, -8.000000000000000, 0)");
  EXPECT_EQ(Dyad(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0)
                .Print(Precision::Single),
            "(1.000000, -2.000000, 0; 2.000000, -4.000000, 0; 4.000000, "
            "-8.000000, 0)");
}

TEST(ValueDyad, SizeOf) {
  const Dyad dyad{1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  EXPECT_EQ(sizeof(dyad), 9 * sizeof(double));
}

TEST(ValueDyad, Stream) {
  const Dyad dyad{1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  std::ostringstream stream;
  stream << dyad;
  EXPECT_EQ(stream.str(), dyad.Print());
}

TEST(ValueDyad, Trace) {
  EXPECT_EQ(
      Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Trace(), 448.0);
}

TEST(ValueDyad, Transpose) {
  EXPECT_EQ(
      Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Transpose(),
      Dyad(64.0, 16.0, 2.0, 4.0, 128.0, 32.0, 1.0, 8.0, 256.0));
}

TEST(ValueDyad, XML) {
  EXPECT_EQ(Dyad(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0).XML(),
            "<xx>1.000000000000000</xx><xy>-2.000000000000000</xy><xz>0</"
            "xz><yx>2.000000000000000</yx><yy>-4.000000000000000</yy><yz>0</"
            "yz><zx>4.000000000000000</zx><zy>-8.000000000000000</zy><zz>0</"
            "zz>");
}

TEST(ValueDyad, YAML) {
  EXPECT_EQ(Dyad(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0).YAML(),
            "{xx:1.000000000000000,xy:-2.000000000000000,xz:0,yx:2."
            "000000000000000,yy:-4.000000000000000,yz:0,zx:4.000000000000000,"
            "zy:-8.000000000000000,zz:0}");
}

TEST(ValueDyad, Zero) {
  EXPECT_EQ(Dyad::Zero(), Dyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ::Value
