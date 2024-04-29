// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#include "../include/PhQ/SymmetricDyad.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>
#include <utility>

#include "../include/PhQ/Base.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(SymmetricDyad, Adjugate) {
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Adjugate(),
            SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(SymmetricDyad, ArithmeticOperatorAddition) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0)
                + SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            SymmetricDyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));
}

TEST(SymmetricDyad, ArithmeticOperatorDivision) {
  EXPECT_EQ(SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0) / 2.0,
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(SymmetricDyad, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * 2.0,
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(2.0 * SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * Vector(1.0, -2.0, 3.0),
            Vector(14.0, 21.0, -25.0));
}

TEST(SymmetricDyad, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SymmetricDyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0)
                - SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(SymmetricDyad, AssignmentOperatorAddition) {
  SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
  symmetric_dyad += SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  EXPECT_EQ(symmetric_dyad, SymmetricDyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));
}

TEST(SymmetricDyad, AssignmentOperatorDivision) {
  SymmetricDyad symmetric_dyad{2.0, -4.0, 6.0, -8.0, 10.0, -12.0};
  symmetric_dyad /= 2.0;
  EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(SymmetricDyad, AssignmentOperatorMultiplication) {
  SymmetricDyad symmetric_dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
  symmetric_dyad *= 2.0;
  EXPECT_EQ(symmetric_dyad, SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
}

TEST(SymmetricDyad, AssignmentOperatorSubtraction) {
  SymmetricDyad symmetric_dyad{3.0, -6.0, 9.0, -12.0, 15.0, -18.0};
  symmetric_dyad -= SymmetricDyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(SymmetricDyad, Cofactors) {
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Cofactors(),
            SymmetricDyad(496.0, -60.0, -8.0, 255.0, -30.0, 124.0));
}

TEST(SymmetricDyad, ComparisonOperators) {
  constexpr SymmetricDyad first{1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  constexpr SymmetricDyad second{1.0, 2.0, 3.000001, 4.0, 5.0, 6.0};
  constexpr SymmetricDyad third{1.0, 2.0, 3.000001, 4.0, 5.0, 6.000001};
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

TEST(SymmetricDyad, CopyAssignmentOperator) {
  constexpr SymmetricDyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  SymmetricDyad second = SymmetricDyad::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(SymmetricDyad, CopyConstructor) {
  constexpr SymmetricDyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  constexpr SymmetricDyad second{first};
  EXPECT_EQ(second, first);
}

TEST(SymmetricDyad, DefaultConstructor) {
  EXPECT_NO_THROW(SymmetricDyad{});
}

TEST(SymmetricDyad, Determinant) {
  EXPECT_EQ(SymmetricDyad(8.0, 2.0, 1.0, 16.0, 4.0, 32.0).Determinant(), 3840.0);
}

TEST(SymmetricDyad, Hash) {
  constexpr SymmetricDyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
  constexpr SymmetricDyad second{1.0, -2.0, 3.0, -4.0, 5.0, -6.000001};
  constexpr SymmetricDyad third{1.0, -2.0, 3.0, 4.0, 5.0, -6.0};
  constexpr std::hash<SymmetricDyad> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(SymmetricDyad, Inverse) {
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

TEST(SymmetricDyad, JSON) {
  EXPECT_EQ(
      SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).JSON(),
      "{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(4.0)
          + ",\"yy\":" + Print(0.0) + ",\"yz\":" + Print(-4.0) + ",\"zz\":" + Print(0.0) + "}");
}

TEST(SymmetricDyad, MoveAssignmentOperator) {
  SymmetricDyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  SymmetricDyad second = SymmetricDyad::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(SymmetricDyad, MoveConstructor) {
  SymmetricDyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  const SymmetricDyad second{std::move(first)};
  EXPECT_EQ(second, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(SymmetricDyad, Mutable) {
  {
    SymmetricDyad symmetric_dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    std::array<double, 6>& mutable_xx_xy_xz_yy_yz_zz = symmetric_dyad.Mutable_xx_xy_xz_yy_yz_zz();
    mutable_xx_xy_xz_yy_yz_zz = {-7.0, 8.0, -9.0, 10.0, -11.0, 12.0};
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  }
  {
    SymmetricDyad second(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    double& mutable_xx = second.Mutable_xx();
    mutable_xx = -7.0;
    double& mutable_xy = second.Mutable_xy();
    mutable_xy = 8.0;
    double& mutable_xz = second.Mutable_xz();
    mutable_xz = -9.0;
    double& mutable_yy = second.Mutable_yy();
    mutable_yy = 10.0;
    double& mutable_yz = second.Mutable_yz();
    mutable_yz = -11.0;
    double& mutable_zz = second.Mutable_zz();
    mutable_zz = 12.0;
    EXPECT_EQ(second.xx(), -7.0);
    EXPECT_EQ(second.xy(), 8.0);
    EXPECT_EQ(second.xz(), -9.0);
    EXPECT_EQ(second.yy(), 10.0);
    EXPECT_EQ(second.yz(), -11.0);
    EXPECT_EQ(second.zz(), 12.0);
  }
  {
    SymmetricDyad symmetric_dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    double& mutable_yx = symmetric_dyad.Mutable_yx();
    mutable_yx = -13.0;
    double& mutable_zx = symmetric_dyad.Mutable_zx();
    mutable_zx = 14.0;
    double& mutable_zy = symmetric_dyad.Mutable_zy();
    mutable_zy = -15.0;
    EXPECT_EQ(symmetric_dyad.yx(), -13.0);
    EXPECT_EQ(symmetric_dyad.zx(), 14.0);
    EXPECT_EQ(symmetric_dyad.zy(), -15.0);
  }
}

TEST(SymmetricDyad, Print) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(4.0) + "; " + Print(0.0) + ", "
                + Print(-4.0) + "; " + Print(0.0) + ")");
}

TEST(SymmetricDyad, Set) {
  {
    SymmetricDyad symmetric_dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    symmetric_dyad.Set_xx_xy_xz_yy_yz_zz(std::array<double, 6>{-7.0, 8.0, -9.0, 10.0, -11.0, 12.0});
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  }
  {
    SymmetricDyad symmetric_dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    symmetric_dyad.Set_xx_xy_xz_yy_yz_zz(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  }
  {
    SymmetricDyad symmetric_dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
    symmetric_dyad.Set_xx(-7.0);
    symmetric_dyad.Set_xy(8.0);
    symmetric_dyad.Set_xz(-9.0);
    symmetric_dyad.Set_yy(10.0);
    symmetric_dyad.Set_yz(-11.0);
    symmetric_dyad.Set_zz(12.0);
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(-7.0, 8.0, -9.0, 10.0, -11.0, 12.0));
  }
}

TEST(SymmetricDyad, SizeOf) {
  EXPECT_EQ(sizeof(SymmetricDyad{}), 6 * sizeof(double));
}

TEST(SymmetricDyad, StandardConstructor) {
  EXPECT_EQ(SymmetricDyad(std::array<double, 6>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0}),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  {
    SymmetricDyad symmetric_dyad = SymmetricDyad::Zero();
    symmetric_dyad = std::array<double, 6>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    EXPECT_EQ(symmetric_dyad, SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
  }
}

TEST(SymmetricDyad, Stream) {
  std::ostringstream stream;
  stream << SymmetricDyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
  EXPECT_EQ(stream.str(), SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).Print());
}

TEST(SymmetricDyad, Trace) {
  EXPECT_EQ(SymmetricDyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0).Trace(), 41.0);
}

TEST(SymmetricDyad, Transpose) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0).Transpose(),
            SymmetricDyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(SymmetricDyad, XML) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).XML(),
            "<xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(4.0) + "</xz><yy>"
                + Print(0.0) + "</yy><yz>" + Print(-4.0) + "</yz><zz>" + Print(0.0) + "</zz>");
}

TEST(SymmetricDyad, YAML) {
  EXPECT_EQ(SymmetricDyad(1.0, -2.0, 4.0, 0.0, -4.0, 0.0).YAML(),
            "{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(4.0) + ",yy:" + Print(0.0)
                + ",yz:" + Print(-4.0) + ",zz:" + Print(0.0) + "}");
}

TEST(SymmetricDyad, Zero) {
  EXPECT_EQ(SymmetricDyad::Zero(), SymmetricDyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
