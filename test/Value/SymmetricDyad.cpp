// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#include "../../include/PhQ/Value/SymmetricDyad.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>
#include <utility>

#include "../../include/PhQ/Base.hpp"
#include "../../include/PhQ/Value/Vector.hpp"

namespace PhQ::Value {

namespace {

TEST(ValueSymmetricDyad, Adjugate) {
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Adjugate(),
            SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyad, ArithmeticOperatorAddition) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0)
                + SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            SymmetricDyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));
}

TEST(ValueSymmetricDyad, ArithmeticOperatorDivision) {
  EXPECT_EQ(SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0) / 2.0,
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(ValueSymmetricDyad, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * 2.0,
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));

  EXPECT_EQ(2.0 * SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));

  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * Vector(1.0, -2.0, 3.0),
            Vector(14.0, 21.0, -25.0));
}

TEST(ValueSymmetricDyad, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SymmetricDyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0)
                - SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(ValueSymmetricDyad, AssignmentOperatorAddition) {
  SymmetricDyad value{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
  value += SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  EXPECT_EQ(value, SymmetricDyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));
}

TEST(ValueSymmetricDyad, AssignmentOperatorDivision) {
  SymmetricDyad value{2.0, -4.0, 6.0, -8.0, 10.0, -12.0};
  value /= 2.0;
  EXPECT_EQ(value, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(ValueSymmetricDyad, AssignmentOperatorMultiplication) {
  SymmetricDyad value{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
  value *= 2.0;
  EXPECT_EQ(value, SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
}

TEST(ValueSymmetricDyad, AssignmentOperatorSubtraction) {
  SymmetricDyad value{3.0, -6.0, 9.0, -12.0, 15.0, -18.0};
  value -= SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  EXPECT_EQ(value, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(ValueSymmetricDyad, Cofactors) {
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Cofactors(),
            SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(ValueSymmetricDyad, ComparisonOperators) {
  constexpr SymmetricDyad first{1.11, 2.22, 3.33, 4.44, 5.55, 6.66};
  constexpr SymmetricDyad second{1.11, 2.22, 3.34, 4.44, 5.55, 6.66};
  constexpr SymmetricDyad third{1.11, 2.22, 3.34, 4.44, 5.55, 6.67};
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

TEST(ValueSymmetricDyad, CopyAssignmentOperator) {
  constexpr SymmetricDyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  SymmetricDyad second = SymmetricDyad::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ValueSymmetricDyad, CopyConstructor) {
  constexpr SymmetricDyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  constexpr SymmetricDyad second{first};
  EXPECT_EQ(second, first);
}

TEST(ValueSymmetricDyad, DefaultConstructor) {
  EXPECT_NO_THROW(SymmetricDyad{});
}

TEST(ValueSymmetricDyad, Determinant) {
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Determinant(), 3840.0);
}

TEST(ValueSymmetricDyad, Hash) {
  constexpr SymmetricDyad first{1.11, -2.22, 3.33, -4.44, 5.55, -6.66};
  constexpr SymmetricDyad second{1.11, -2.22, 3.33, -4.44, 5.55, -6.660001};
  constexpr SymmetricDyad third{1.11, -2.22, 3.33, 4.44, 5.55, -6.66};
  constexpr std::hash<SymmetricDyad> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(ValueSymmetricDyad, Inverse) {
  constexpr SymmetricDyad first{8.0, 2.0, 1.0, 16.0, 4.0, 32.0};
  const std::optional<SymmetricDyad> first_inverse{first.Inverse()};
  ASSERT_TRUE(first_inverse.has_value());
  EXPECT_DOUBLE_EQ(first_inverse.value().xx(), 496.0 / 3840.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().xy(), -60.0 / 3840.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().xz(), -8.0 / 3840.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().yy(), 255.0 / 3840.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().yz(), -30.0 / 3840.0);
  EXPECT_DOUBLE_EQ(first_inverse.value().zz(), 124.0 / 3840.0);

  constexpr SymmetricDyad second{0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const std::optional<SymmetricDyad> second_inverse{second.Inverse()};
  EXPECT_FALSE(second_inverse.has_value());
}

TEST(ValueSymmetricDyad, JSON) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).JSON(),
            "{\"xx\":1.000000000000000,\"xy\":-2.000000000000000,\"xz\":4.000000000000000,\"yy\":0,"
            "\"yz\":-4.000000000000000,\"zz\":0}");
}

TEST(ValueSymmetricDyad, MoveAssignmentOperator) {
  SymmetricDyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  SymmetricDyad second = SymmetricDyad::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SymmetricDyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(ValueSymmetricDyad, MoveConstructor) {
  SymmetricDyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  const SymmetricDyad second{std::move(first)};
  EXPECT_EQ(second, SymmetricDyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(ValueSymmetricDyad, Mutable) {
  SymmetricDyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  std::array<double, 6>& mutable_xx_xy_xz_yy_yz_zz = first.Mutable_xx_xy_xz_yy_yz_zz();
  mutable_xx_xy_xz_yy_yz_zz = {-7.77, 8.88, -9.99, 10.10, -11.11, 12.12};
  constexpr std::array<double, 6> result{-7.77, 8.88, -9.99, 10.10, -11.11, 12.12};
  EXPECT_EQ(first.xx_xy_xz_yy_yz_zz(), result);

  SymmetricDyad second(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  double& mutable_xx = second.Mutable_xx();
  mutable_xx = -7.77;
  double& mutable_xy = second.Mutable_xy();
  mutable_xy = 8.88;
  double& mutable_xz = second.Mutable_xz();
  mutable_xz = -9.99;
  double& mutable_yy = second.Mutable_yy();
  mutable_yy = 10.10;
  double& mutable_yz = second.Mutable_yz();
  mutable_yz = -11.11;
  double& mutable_zz = second.Mutable_zz();
  mutable_zz = 12.12;
  EXPECT_EQ(second.xx(), -7.77);
  EXPECT_EQ(second.xy(), 8.88);
  EXPECT_EQ(second.xz(), -9.99);
  EXPECT_EQ(second.yy(), 10.10);
  EXPECT_EQ(second.yz(), -11.11);
  EXPECT_EQ(second.zz(), 12.12);

  SymmetricDyad third(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  double& mutable_yx = third.Mutable_yx();
  mutable_yx = -13.13;
  double& mutable_zx = third.Mutable_zx();
  mutable_zx = 14.14;
  double& mutable_zy = third.Mutable_zy();
  mutable_zy = -15.15;
  EXPECT_EQ(third.yx(), -13.13);
  EXPECT_EQ(third.zx(), 14.14);
  EXPECT_EQ(third.zy(), -15.15);
}

TEST(ValueSymmetricDyad, Print) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Print(),
            "(1.000000000000000, -2.000000000000000, 4.000000000000000; 0, -4.000000000000000; 0)");
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Print(Precision::Double),
            "(1.000000000000000, -2.000000000000000, 4.000000000000000; 0, -4.000000000000000; 0)");
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Print(Precision::Single),
            "(1.000000, -2.000000, 4.000000; 0, -4.000000; 0)");
}

TEST(ValueSymmetricDyad, Set) {
  SymmetricDyad first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  first.Set_xx_xy_xz_yy_yz_zz(std::array<double, 6>{-7.77, 8.88, -9.99, 10.10, -11.11, 12.12});
  EXPECT_EQ(first, SymmetricDyad(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12));

  SymmetricDyad second(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  second.Set_xx_xy_xz_yy_yz_zz(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12);
  EXPECT_EQ(second, SymmetricDyad(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12));

  SymmetricDyad third(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  third.Set_xx(-7.77);
  third.Set_xy(8.88);
  third.Set_xz(-9.99);
  third.Set_yy(10.10);
  third.Set_yz(-11.11);
  third.Set_zz(12.12);
  EXPECT_EQ(third, SymmetricDyad(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12));
}

TEST(ValueSymmetricDyad, SizeOf) {
  EXPECT_EQ(sizeof(SymmetricDyad{}), 6 * sizeof(double));
}

TEST(ValueSymmetricDyad, StandardConstructor) {
  EXPECT_EQ(SymmetricDyad(std::array<double, 6>{1.11, -2.22, 3.33, -4.44, 5.55, -6.66}),
            SymmetricDyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));

  constexpr std::array<double, 6> first_xx_xy_xz_yy_yz_zz{1.11, -2.22, 3.33, -4.44, 5.55, -6.66};
  EXPECT_EQ(
      SymmetricDyad(first_xx_xy_xz_yy_yz_zz), SymmetricDyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));

  constexpr std::array<double, 6> second_xx_xy_xz_yy_yz_zz{1.11, -2.22, 3.33, -4.44, 5.55, -6.66};
  SymmetricDyad second = SymmetricDyad::Zero();
  second = second_xx_xy_xz_yy_yz_zz;
  EXPECT_EQ(second, SymmetricDyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(ValueSymmetricDyad, Stream) {
  constexpr SymmetricDyad value{1.11, -2.22, 3.33, -4.44, 5.55, -6.66};
  std::ostringstream stream;
  stream << value;
  EXPECT_EQ(stream.str(), value.Print());
}

TEST(ValueSymmetricDyad, Trace) {
  EXPECT_EQ(SymmetricDyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0).Trace(), 41.0);
}

TEST(ValueSymmetricDyad, Transpose) {
  EXPECT_EQ(SymmetricDyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66).Transpose(),
            SymmetricDyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(ValueSymmetricDyad, XML) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).XML(),
            "<xx>1.000000000000000</xx><xy>-2.000000000000000</xy><xz>4.000000000000000</xz><yy>0</"
            "yy><yz>-4.000000000000000</yz><zz>0</zz>");
}

TEST(ValueSymmetricDyad, YAML) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).YAML(),
            "{xx:1.000000000000000,xy:-2.000000000000000,xz:4.000000000000000,yy:0,yz:-4."
            "000000000000000,zz:0}");
}

TEST(ValueSymmetricDyad, Zero) {
  EXPECT_EQ(SymmetricDyad::Zero(), SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ::Value
