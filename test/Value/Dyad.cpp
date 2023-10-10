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

namespace PhQ::Value {

namespace {

TEST(ValueDyad, Adjugate) {
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Adjugate(),
            Dyad(32512.0, -992.0, -96.0, -4080.0, 16382.0, -496.0, 256.0,
                 -2040.0, 8128.0));
}

TEST(ValueDyad, ArithmeticOperatorAddition) {
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)
                + Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0),
            Dyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0));
}

TEST(ValueDyad, ArithmeticOperatorDivision) {
  EXPECT_EQ(Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0) / 2.0,
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(ValueDyad, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0) * 2.0,
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));

  EXPECT_EQ(2.0 * Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));

  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)
                * Vector(1.0, -2.0, 3.0),
            Vector(14.0, -32.0, 50.0));

  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0)
                * SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            Dyad(14.0, 21.0, -25.0, 21.0, 45.0, -56.0, -25.0, -56.0, 70.0));

  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)
                * SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            Dyad(14.0, 21.0, -25.0, -32.0, -42.0, 49.0, 50.0, 63.0, -73.0));

  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0)
                * Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            Dyad(30.0, -36.0, 42.0, 49.0, -56.0, 63.0, -59.0, 67.0, -75.0));

  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)
                * Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            Dyad(30.0, -36.0, 42.0, -66.0, 81.0, -96.0, 102.0, -126.0, 150.0));
}

TEST(ValueDyad, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Dyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0)
                - Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0),
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(ValueDyad, AssignmentOperatorAddition) {
  Dyad value{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  value += Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  EXPECT_EQ(value, Dyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0));
}

TEST(ValueDyad, AssignmentOperatorDivision) {
  Dyad value{2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0};
  value /= 2.0;
  EXPECT_EQ(value, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(ValueDyad, AssignmentOperatorMultiplication) {
  Dyad value{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  value *= 2.0;
  EXPECT_EQ(value, Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
}

TEST(ValueDyad, AssignmentOperatorSubtraction) {
  Dyad value{3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0};
  value -= Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  EXPECT_EQ(value, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(ValueDyad, Cofactors) {
  EXPECT_EQ(
      Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Cofactors(),
      Dyad(32512.0, -4080.0, 256.0, -992.0, 16382.0, -2040.0, -96.0, -496.0,
           8128.0));
}

TEST(ValueDyad, ComparisonOperators) {
  constexpr Dyad first{1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  constexpr Dyad second{1.11, 2.22, 3.33, 4.44, 5.56, 6.66, 7.77, 8.88, 9.99};
  constexpr Dyad third{
      1.11, 2.22, 3.33, 4.44, 5.56, 6.66, 7.77, 8.88, 9.990001};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_LT(second, third);
  EXPECT_GT(second, first);
  EXPECT_GT(third, second);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_LE(second, third);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
  EXPECT_GE(third, second);
}

TEST(ValueDyad, CopyAssignmentOperator) {
  constexpr Dyad first(
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  Dyad second = Dyad::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ValueDyad, CopyConstructor) {
  constexpr Dyad first(
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  constexpr Dyad second{first};
  EXPECT_EQ(second, first);
}

TEST(ValueDyad, DefaultConstructor) {
  EXPECT_NO_THROW(Dyad{});
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
  constexpr Dyad first{
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99};
  constexpr Dyad second{
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.990001};
  constexpr Dyad third{1.11, -2.22, 3.33, -4.44, 5.55, 6.66, 7.77, -8.88, 9.99};
  constexpr std::hash<Dyad> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ValueDyad, Inverse) {
  constexpr Dyad first{64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0};
  const std::optional<Dyad> first_inverse{first.Inverse()};
  EXPECT_TRUE(first_inverse.has_value());
  EXPECT_DOUBLE_EQ(first_inverse.value().xx(), 32512.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().xy(), -992.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().xz(), -96.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().yx(), -4080.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().yy(), 16382.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().yz(), -496.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().zx(), 256.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().zy(), -2040.0 / 2064704.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().zz(), 8128.0 / 2064704.0);

  constexpr Dyad second{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const std::optional<Dyad> second_inverse{second.Inverse()};
  EXPECT_FALSE(second_inverse.has_value());
}

TEST(ValueDyad, IsSymmetric) {
  EXPECT_FALSE(Dyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99)
                   .IsSymmetric());
  EXPECT_TRUE(Dyad(1.11, -2.22, 3.33, -2.22, 4.44, -5.55, 3.33, -5.55, 6.66)
                  .IsSymmetric());
}

TEST(ValueDyad, JSON) {
  EXPECT_EQ(Dyad(1.0, -2.0, 0.0, 2.0, -4.0, 0.0, 4.0, -8.0, 0.0).JSON(),
            "{\"xx\":1.000000000000000,\"xy\":-2.000000000000000,\"xz\":0,"
            "\"yx\":2.000000000000000,\"yy\":-4.000000000000000,\"yz\":0,"
            "\"zx\":4.000000000000000,\"zy\":-8.000000000000000,\"zz\":0}");
}

TEST(ValueDyad, MoveAssignmentOperator) {
  Dyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  Dyad second = Dyad::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, Dyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
}

TEST(ValueDyad, MoveConstructor) {
  Dyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  Dyad second{std::move(first)};
  EXPECT_EQ(
      second, Dyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
}

TEST(ValueDyad, Mutable) {
  Dyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  std::array<double, 9>& mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz =
      first.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz();
  mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz = {
      -10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18};
  constexpr std::array<double, 9> result{
      -10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18};
  EXPECT_EQ(first.xx_xy_xz_yx_yy_yz_zx_zy_zz(), result);

  Dyad second(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  double& mutable_xx = second.Mutable_xx();
  mutable_xx = -10.10;
  double& mutable_xy = second.Mutable_xy();
  mutable_xy = 11.11;
  double& mutable_xz = second.Mutable_xz();
  mutable_xz = -12.12;
  double& mutable_yx = second.Mutable_yx();
  mutable_yx = 13.13;
  double& mutable_yy = second.Mutable_yy();
  mutable_yy = -14.14;
  double& mutable_yz = second.Mutable_yz();
  mutable_yz = 15.15;
  double& mutable_zx = second.Mutable_zx();
  mutable_zx = -16.16;
  double& mutable_zy = second.Mutable_zy();
  mutable_zy = 17.17;
  double& mutable_zz = second.Mutable_zz();
  mutable_zz = -18.18;
  EXPECT_EQ(second.xx(), -10.10);
  EXPECT_EQ(second.xy(), 11.11);
  EXPECT_EQ(second.xz(), -12.12);
  EXPECT_EQ(second.yx(), 13.13);
  EXPECT_EQ(second.yy(), -14.14);
  EXPECT_EQ(second.yz(), 15.15);
  EXPECT_EQ(second.zx(), -16.16);
  EXPECT_EQ(second.zy(), 17.17);
  EXPECT_EQ(second.zz(), -18.18);
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

TEST(ValueDyad, Set) {
  Dyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  first.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(std::array<double, 9>{
      -10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18});
  EXPECT_EQ(first, Dyad(-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16,
                        17.17, -18.18));

  Dyad second(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  second.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
      -10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16, 17.17, -18.18);
  EXPECT_EQ(second, Dyad(-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16,
                         17.17, -18.18));

  Dyad third(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99);
  third.Set_xx(-10.10);
  third.Set_xy(11.11);
  third.Set_xz(-12.12);
  third.Set_yx(13.13);
  third.Set_yy(-14.14);
  third.Set_yz(15.15);
  third.Set_zx(-16.16);
  third.Set_zy(17.17);
  third.Set_zz(-18.18);
  EXPECT_EQ(third, Dyad(-10.10, 11.11, -12.12, 13.13, -14.14, 15.15, -16.16,
                        17.17, -18.18));
}

TEST(ValueDyad, SizeOf) {
  EXPECT_EQ(sizeof(Dyad{}), 9 * sizeof(double));
}

TEST(ValueDyad, StandardConstructor) {
  EXPECT_EQ(Dyad(std::array<double, 9>{
                1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99}),
            Dyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));

  std::array<double, 9> first_xx_xy_xz_yx_yy_yz_zx_zy_zz{
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99};
  EXPECT_EQ(Dyad(first_xx_xy_xz_yx_yy_yz_zx_zy_zz),
            Dyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));

  constexpr std::array<double, 9> second_xx_xy_xz_yx_yy_yz_zx_zy_zz{
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99};
  Dyad second = Dyad::Zero();
  second = second_xx_xy_xz_yx_yy_yz_zx_zy_zz;
  EXPECT_EQ(
      second, Dyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));

  std::array<double, 9> third_xx_xy_xz_yx_yy_yz_zx_zy_zz{
      1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99};
  Dyad third = Dyad::Zero();
  third = std::move(third_xx_xy_xz_yx_yy_yz_zx_zy_zz);
  EXPECT_EQ(
      third, Dyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66, 7.77, -8.88, 9.99));
}

TEST(ValueDyad, Stream) {
  constexpr Dyad value{1.11, 2.22, 3.33, 4.44, 5.55, 6.66, 7.77, 8.88, 9.99};
  std::ostringstream stream;
  stream << value;
  EXPECT_EQ(stream.str(), value.Print());
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
