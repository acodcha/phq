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

#include "../include/PhQ/Dyad.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <optional>
#include <sstream>
#include <utility>

#include "../include/PhQ/Base.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(Dyad, Adjugate) {
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Adjugate(),
            Dyad(32512.0, -992.0, -96.0, -4080.0, 16382.0, -496.0, 256.0, -2040.0, 8128.0));
}

TEST(Dyad, ArithmeticOperatorAddition) {
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0)
                + Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0),
            Dyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0));
}

TEST(Dyad, ArithmeticOperatorDivision) {
  EXPECT_EQ(Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0) / 2.0,
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(Dyad, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0) * 2.0,
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  EXPECT_EQ(2.0 * Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0),
            Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0) * Vector(1.0, -2.0, 3.0),
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

TEST(Dyad, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Dyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0)
                - Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0),
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(Dyad, AssignmentOperatorAddition) {
  Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  dyad += Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  EXPECT_EQ(dyad, Dyad(3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0));
}

TEST(Dyad, AssignmentOperatorDivision) {
  Dyad dyad{2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0};
  dyad /= 2.0;
  EXPECT_EQ(dyad, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(Dyad, AssignmentOperatorMultiplication) {
  Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  dyad *= 2.0;
  EXPECT_EQ(dyad, Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0));
}

TEST(Dyad, AssignmentOperatorSubtraction) {
  Dyad dyad{3.0, -6.0, 9.0, -12.0, 15.0, -18.0, 21.0, -24.0, 27.0};
  dyad -= Dyad(2.0, -4.0, 6.0, -8.0, 10.0, -12.0, 14.0, -16.0, 18.0);
  EXPECT_EQ(dyad, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(Dyad, Cofactors) {
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Cofactors(),
            Dyad(32512.0, -4080.0, 256.0, -992.0, 16382.0, -2040.0, -96.0, -496.0, 8128.0));
}

TEST(Dyad, ComparisonOperators) {
  constexpr Dyad first{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  constexpr Dyad second{1.0, 2.0, 3.0, 4.0, 5.56, 6.0, 7.0, 8.0, 9.0};
  constexpr Dyad third{1.0, 2.0, 3.0, 4.0, 5.56, 6.0, 7.0, 8.0, 9.000001};
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

TEST(Dyad, CopyAssignmentOperator) {
  constexpr Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  Dyad second{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
  second = first;
  EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(Dyad, CopyConstructor) {
  constexpr Dyad first(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0);
  constexpr Dyad second{first};
  EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(Dyad, DefaultConstructor) {
  EXPECT_NO_THROW(Dyad{});
}

TEST(Dyad, Determinant) {
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Determinant(), 2064704.0);
}

TEST(Dyad, DyadicProduct) {
  EXPECT_EQ(Vector(1.0, 2.0, 4.0).Dyadic(Vector(8.0, 16.0, 32.0)),
            Dyad(8.0, 16.0, 32.0, 16.0, 32.0, 64.0, 32.0, 64.0, 128.0));
}

TEST(Dyad, Hash) {
  constexpr Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  constexpr Dyad second{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.000001};
  constexpr Dyad third{1.0, -2.0, 3.0, -4.0, 5.0, 6.0, 7.0, -8.0, 9.0};
  constexpr std::hash<Dyad<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Dyad, Inverse) {
  {
    constexpr Dyad dyad{64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0};
    const std::optional<Dyad<>> inverse{dyad.Inverse()};
    ASSERT_TRUE(inverse.has_value());
    EXPECT_DOUBLE_EQ(inverse.value().xx(), 32512.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().xy(), -992.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().xz(), -96.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().yx(), -4080.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().yy(), 16382.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().yz(), -496.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().zx(), 256.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().zy(), -2040.0 / 2064704.0);
    EXPECT_DOUBLE_EQ(inverse.value().zz(), 8128.0 / 2064704.0);
  }
  {
    constexpr Dyad dyad{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    const std::optional<Dyad<>> inverse{dyad.Inverse()};
    EXPECT_FALSE(inverse.has_value());
  }
}

TEST(Dyad, IsSymmetric) {
  EXPECT_FALSE(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).IsSymmetric());
  EXPECT_TRUE(Dyad(1.0, -2.0, 3.0, -2.0, 4.0, -5.0, 3.0, -5.0, 6.0).IsSymmetric());
}

TEST(Dyad, JSON) {
  EXPECT_EQ(
      Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).JSON(),
      "{\"xx\":" + Print(1.0) + ",\"xy\":" + Print(-2.0) + ",\"xz\":" + Print(3.0)
          + ",\"yx\":" + Print(-4.0) + ",\"yy\":" + Print(5.0) + ",\"yz\":" + Print(-6.0)
          + ",\"zx\":" + Print(7.0) + ",\"zy\":" + Print(-8.0) + ",\"zz\":" + Print(9.0) + "}");
}

TEST(Dyad, MoveAssignmentOperator) {
  Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  Dyad second{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
  second = std::move(first);
  EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(Dyad, MoveConstructor) {
  Dyad first{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
  const Dyad second{std::move(first)};
  EXPECT_EQ(second, Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
}

TEST(Dyad, Mutable) {
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    std::array<double, 9>& mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz =
        dyad.Mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz();
    mutable_xx_xy_xz_yx_yy_yz_zx_zy_zz = {
        -10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    double& mutable_xx = dyad.Mutable_xx();
    mutable_xx = -10.0;
    double& mutable_xy = dyad.Mutable_xy();
    mutable_xy = 11.0;
    double& mutable_xz = dyad.Mutable_xz();
    mutable_xz = -12.0;
    double& mutable_yx = dyad.Mutable_yx();
    mutable_yx = 13.0;
    double& mutable_yy = dyad.Mutable_yy();
    mutable_yy = -14.0;
    double& mutable_yz = dyad.Mutable_yz();
    mutable_yz = 15.0;
    double& mutable_zx = dyad.Mutable_zx();
    mutable_zx = -16.0;
    double& mutable_zy = dyad.Mutable_zy();
    mutable_zy = 17.0;
    double& mutable_zz = dyad.Mutable_zz();
    mutable_zz = -18.0;
    EXPECT_EQ(dyad.xx(), -10.0);
    EXPECT_EQ(dyad.xy(), 11.0);
    EXPECT_EQ(dyad.xz(), -12.0);
    EXPECT_EQ(dyad.yx(), 13.0);
    EXPECT_EQ(dyad.yy(), -14.0);
    EXPECT_EQ(dyad.yz(), 15.0);
    EXPECT_EQ(dyad.zx(), -16.0);
    EXPECT_EQ(dyad.zy(), 17.0);
    EXPECT_EQ(dyad.zz(), -18.0);
  }
}

TEST(Dyad, Print) {
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + "; " + Print(-4.0) + ", "
                + Print(5.0) + ", " + Print(-6.0) + "; " + Print(7.0) + ", " + Print(-8.0) + ", "
                + Print(9.0) + ")");
}

TEST(Dyad, Set) {
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0);
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad.Set_xx_xy_xz_yx_yy_yz_zx_zy_zz(
        std::array<double, 9>{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0});
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad.Set_xx(-10.0);
    dyad.Set_xy(11.0);
    dyad.Set_xz(-12.0);
    dyad.Set_yx(13.0);
    dyad.Set_yy(-14.0);
    dyad.Set_yz(15.0);
    dyad.Set_zx(-16.0);
    dyad.Set_zy(17.0);
    dyad.Set_zz(-18.0);
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
}

TEST(Dyad, SizeOf) {
  EXPECT_EQ(sizeof(Dyad<>{}), 9 * sizeof(double));
}

TEST(Dyad, StandardConstructor) {
  EXPECT_EQ(Dyad(std::array<double, 9>{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0}),
            Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0));
  {
    Dyad dyad{1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0};
    dyad = std::array<double, 9>{-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0};
    EXPECT_EQ(dyad, Dyad(-10.0, 11.0, -12.0, 13.0, -14.0, 15.0, -16.0, 17.0, -18.0));
  }
}

TEST(Dyad, Stream) {
  std::ostringstream stream;
  stream << Dyad{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
  EXPECT_EQ(stream.str(), Dyad(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0).Print());
}

TEST(Dyad, Trace) {
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Trace(), 448.0);
}

TEST(Dyad, Transpose) {
  EXPECT_EQ(Dyad(64.0, 4.0, 1.0, 16.0, 128.0, 8.0, 2.0, 32.0, 256.0).Transpose(),
            Dyad(64.0, 16.0, 2.0, 4.0, 128.0, 32.0, 1.0, 8.0, 256.0));
}

TEST(Dyad, XML) {
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).XML(),
            "<xx>" + Print(1.0) + "</xx><xy>" + Print(-2.0) + "</xy><xz>" + Print(3.0) + "</xz><yx>"
                + Print(-4.0) + "</yx><yy>" + Print(5.0) + "</yy><yz>" + Print(-6.0) + "</yz><zx>"
                + Print(7.0) + "</zx><zy>" + Print(-8.0) + "</zy><zz>" + Print(9.0) + "</zz>");
}

TEST(Dyad, YAML) {
  EXPECT_EQ(Dyad(1.0, -2.0, 3.0, -4.0, 5.0, -6.0, 7.0, -8.0, 9.0).YAML(),
            "{xx:" + Print(1.0) + ",xy:" + Print(-2.0) + ",xz:" + Print(3.0) + ",yx:" + Print(-4.0)
                + ",yy:" + Print(5.0) + ",yz:" + Print(-6.0) + ",zx:" + Print(7.0)
                + ",zy:" + Print(-8.0) + ",zz:" + Print(9.0) + "}");
}

TEST(Dyad, Zero) {
  EXPECT_EQ(Dyad<>::Zero(), Dyad(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
