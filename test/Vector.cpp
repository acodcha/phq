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

#include "../include/PhQ/Vector.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Base.hpp"

namespace PhQ {

namespace {

TEST(Vector, ArithmeticOperatorAddition) {
  EXPECT_EQ(Vector(1.0, -2.0, 3.0) + Vector(2.0, -4.0, 6.0), Vector(3.0, -6.0, 9.0));
}

TEST(Vector, ArithmeticOperatorDivision) {
  EXPECT_EQ(Vector(2.0, -4.0, 6.0) / 2.0, Vector(1.0, -2.0, 3.0));
}

TEST(Vector, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Vector(1.0, -2.0, 3.0) * 2.0, Vector(2.0, -4.0, 6.0));
  EXPECT_EQ(2.0 * Vector(1.0, -2.0, 3.0), Vector(2.0, -4.0, 6.0));
}

TEST(Vector, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Vector(3.0, -6.0, 9.0) - Vector(2.0, -4.0, 6.0), Vector(1.0, -2.0, 3.0));
}

TEST(Vector, AssignmentOperatorAddition) {
  Vector vector{1.0, -2.0, 3.0};
  vector += Vector(2.0, -4.0, 6.0);
  EXPECT_EQ(vector, Vector(3.0, -6.0, 9.0));
}

TEST(Vector, AssignmentOperatorDivision) {
  Vector vector{2.0, -4.0, 6.0};
  vector /= 2.0;
  EXPECT_EQ(vector, Vector(1.0, -2.0, 3.0));
}

TEST(Vector, AssignmentOperatorMultiplication) {
  Vector vector{1.0, -2.0, 3.0};
  vector *= 2.0;
  EXPECT_EQ(vector, Vector(2.0, -4.0, 6.0));
}

TEST(Vector, AssignmentOperatorSubtraction) {
  Vector vector{3.0, -6.0, 9.0};
  vector -= Vector(2.0, -4.0, 6.0);
  EXPECT_EQ(vector, Vector(1.0, -2.0, 3.0));
}

TEST(Vector, ComparisonOperators) {
  constexpr Vector first{1.0, -2.0, 3.0};
  constexpr Vector second{1.0, -2.0, 3.000001};
  constexpr Vector third{1.0, 2.0, 3.0};
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

TEST(Vector, CopyAssignmentOperator) {
  constexpr Vector first(1.0, -2.0, 3.0);
  Vector second = Vector::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Vector, CopyConstructor) {
  constexpr Vector first(1.0, -2.0, 3.0);
  constexpr Vector second{first};
  EXPECT_EQ(second, first);
}

TEST(Vector, Cross) {
  EXPECT_EQ(Vector(2.0, 0.0, 0.0).Cross(Vector(0.0, 4.0, 0.0)), Vector(0.0, 0.0, 8.0));
}

TEST(Vector, DefaultConstructor) {
  EXPECT_NO_THROW(Vector{});
}

TEST(Vector, Dot) {
  EXPECT_EQ(Vector(1.0, -2.0, 3.0).Dot(Vector(1.0, -2.0, 3.0)),
            Vector(1.0, -2.0, 3.0).MagnitudeSquared());
  EXPECT_EQ(Vector(0.0, 1.0, -2.0).Dot(Vector(3.0, 0.0, 0.0)), 0.0);
  EXPECT_EQ(Vector(1.0, -2.0, 3.0).Dot(Vector(-1.0, 2.0, -3.0)),
            -Vector(1.0, -2.0, 3.0).MagnitudeSquared());
}

TEST(Vector, Hash) {
  constexpr Vector first(1.0, -2.0, 3.0);
  constexpr Vector second(1.0, -2.0, 3.000001);
  constexpr Vector third(1.0, 2.0, 3.0);
  const std::hash<Vector> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Vector, JSON) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).JSON(),
            "{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(0.0) + "}");
}

TEST(Vector, Magnitude) {
  EXPECT_EQ(Vector(6.0, -3.0, 2.0).Magnitude(), 7.0);
  EXPECT_EQ(Vector(1.0, -2.0, 3.0).MagnitudeSquared(), 14.0);
}

TEST(Vector, MoveAssignmentOperator) {
  Vector first(1.0, -2.0, 3.0);
  Vector second = Vector::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
}

TEST(Vector, MoveConstructor) {
  Vector first(1.0, -2.0, 3.0);
  const Vector second{std::move(first)};
  EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
}

TEST(Vector, Mutable) {
  {
    Vector vector(1.0, -2.0, 3.0);
    std::array<double, 3>& mutable_x_y_z = vector.Mutable_x_y_z();
    mutable_x_y_z = {-4.0, 5.0, -6.0};
    EXPECT_EQ(vector, Vector(-4.0, 5.0, -6.0));
  }
  {
    Vector vector(1.0, -2.0, 3.0);
    double& mutable_x = vector.Mutable_x();
    mutable_x = -4.0;
    double& mutable_y = vector.Mutable_y();
    mutable_y = 5.0;
    double& mutable_z = vector.Mutable_z();
    mutable_z = -6.0;
    EXPECT_EQ(vector.x(), -4.0);
    EXPECT_EQ(vector.y(), 5.0);
    EXPECT_EQ(vector.z(), -6.0);
  }
}

TEST(Vector, Print) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(0.0) + ")");
}

TEST(Vector, Set) {
  {
    Vector vector(1.0, -2.0, 3.0);
    vector.Set_x_y_z(std::array<double, 3>{-4.0, 5.0, -6.0});
    EXPECT_EQ(vector, Vector(-4.0, 5.0, -6.0));
  }
  {
    Vector vector(1.0, -2.0, 3.0);
    vector.Set_x_y_z(-4.0, 5.0, -6.0);
    EXPECT_EQ(vector, Vector(-4.0, 5.0, -6.0));
  }
  {
    Vector vector(1.0, -2.0, 3.0);
    vector.Set_x(-4.0);
    vector.Set_y(5.0);
    vector.Set_z(-6.0);
    EXPECT_EQ(vector, Vector(-4.0, 5.0, -6.0));
  }
}

TEST(Vector, SizeOf) {
  EXPECT_EQ(sizeof(Vector{}), 3 * sizeof(double));
}

TEST(Vector, StandardConstructor) {
  EXPECT_EQ(Vector(std::array<double, 3>{1.0, -2.0, 3.0}), Vector(1.0, -2.0, 3.0));
  {
    Vector vector = Vector::Zero();
    vector = std::array<double, 3>{1.0, -2.0, 3.0};
    EXPECT_EQ(vector, Vector(1.0, -2.0, 3.0));
  }
}

TEST(Vector, Stream) {
  std::ostringstream stream;
  stream << Vector{1.0, -2.0, 3.0};
  EXPECT_EQ(stream.str(), Vector(1.0, -2.0, 3.0).Print());
}

TEST(Vector, XML) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).XML(),
            "<x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(0.0) + "</z>");
}

TEST(Vector, YAML) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).YAML(),
            "{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(0.0) + "}");
}

TEST(Vector, Zero) {
  EXPECT_EQ(Vector::Zero(), Vector(0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
