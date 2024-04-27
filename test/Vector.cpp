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

TEST(ValueVector, ArithmeticOperatorAddition) {
  EXPECT_EQ(Vector(1.0, -2.0, 3.0) + Vector(2.0, -4.0, 6.0), Vector(3.0, -6.0, 9.0));
}

TEST(ValueVector, ArithmeticOperatorDivision) {
  EXPECT_EQ(Vector(2.0, -4.0, 6.0) / 2.0, Vector(1.0, -2.0, 3.0));
}

TEST(ValueVector, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Vector(1.0, -2.0, 3.0) * 2.0, Vector(2.0, -4.0, 6.0));

  EXPECT_EQ(2.0 * Vector(1.0, -2.0, 3.0), Vector(2.0, -4.0, 6.0));
}

TEST(ValueVector, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Vector(3.0, -6.0, 9.0) - Vector(2.0, -4.0, 6.0), Vector(1.0, -2.0, 3.0));
}

TEST(ValueVector, AssignmentOperatorAddition) {
  Vector value{1.0, -2.0, 3.0};
  value += Vector(2.0, -4.0, 6.0);
  EXPECT_EQ(value, Vector(3.0, -6.0, 9.0));
}

TEST(ValueVector, AssignmentOperatorDivision) {
  Vector value{2.0, -4.0, 6.0};
  value /= 2.0;
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(ValueVector, AssignmentOperatorMultiplication) {
  Vector value{1.0, -2.0, 3.0};
  value *= 2.0;
  EXPECT_EQ(value, Vector(2.0, -4.0, 6.0));
}

TEST(ValueVector, AssignmentOperatorSubtraction) {
  Vector value{3.0, -6.0, 9.0};
  value -= Vector(2.0, -4.0, 6.0);
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(ValueVector, ComparisonOperators) {
  constexpr Vector first{1.11, 2.22, 3.33};
  constexpr Vector second{1.11, 2.23, 3.33};
  constexpr Vector third{1.11, 2.23, 3.34};
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

TEST(ValueVector, CopyAssignmentOperator) {
  constexpr Vector first(1.11, -2.22, 3.33);
  Vector second = Vector::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ValueVector, CopyConstructor) {
  constexpr Vector first(1.11, -2.22, 3.33);
  constexpr Vector second{first};
  EXPECT_EQ(second, first);
}

TEST(ValueVector, Cross) {
  EXPECT_EQ(Vector(10.0, 0.0, 0.0).Cross(Vector(0.0, 20.0, 0.0)), Vector(0.0, 0.0, 200.0));
}

TEST(ValueVector, DefaultConstructor) {
  EXPECT_NO_THROW(Vector{});
}

TEST(ValueVector, Dot) {
  constexpr Vector first{1.23, 4.56, 7.89};
  EXPECT_EQ(first.Dot(first), first.MagnitudeSquared());
  EXPECT_EQ(Vector(0.0, 10.0, -15.0).Dot(Vector(20.0, 0.0, 0.0)), 0.0);
  EXPECT_EQ(first.Dot(Vector(-1.23, -4.56, -7.89)), -first.MagnitudeSquared());
}

TEST(ValueVector, Hash) {
  constexpr Vector first(1.11, -2.22, 3.33);
  constexpr Vector second(1.11, -2.22, 3.330001);
  constexpr Vector third(1.11, 2.22, 3.33);
  const std::hash<Vector> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ValueVector, JSON) {
  EXPECT_EQ(
      Vector(1.0, -2.0, 0.0).JSON(), "{\"x\":1.000000000000000,\"y\":-2.000000000000000,\"z\":0}");
}

TEST(ValueVector, Magnitude) {
  EXPECT_EQ(Vector(0.0, 0.0, 5.5e10).Magnitude(), 5.5e10);
  EXPECT_EQ(Vector(-1.0, 2.0, -3.0).MagnitudeSquared(), 14.0);
}

TEST(ValueVector, MoveAssignmentOperator) {
  Vector first(1.11, -2.22, 3.33);
  Vector second = Vector::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Vector(1.11, -2.22, 3.33));
}

TEST(ValueVector, MoveConstructor) {
  Vector first(1.11, -2.22, 3.33);
  const Vector second{std::move(first)};
  EXPECT_EQ(second, Vector(1.11, -2.22, 3.33));
}

TEST(ValueVector, Mutable) {
  Vector first(1.11, -2.22, 3.33);
  std::array<double, 3>& mutable_x_y_z = first.Mutable_x_y_z();
  mutable_x_y_z = {-4.44, 5.55, -6.66};
  constexpr std::array<double, 3> result{-4.44, 5.55, -6.66};
  EXPECT_EQ(first.x_y_z(), result);

  Vector second(1.11, -2.22, 3.33);
  double& mutable_x = second.Mutable_x();
  mutable_x = -4.44;
  double& mutable_y = second.Mutable_y();
  mutable_y = 5.55;
  double& mutable_z = second.Mutable_z();
  mutable_z = -6.66;
  EXPECT_EQ(second.x(), -4.44);
  EXPECT_EQ(second.y(), 5.55);
  EXPECT_EQ(second.z(), -6.66);
}

TEST(ValueVector, Print) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).Print(), "(1.000000000000000, -2.000000000000000, 0)");
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).Print(Precision::Double),
            "(1.000000000000000, -2.000000000000000, 0)");
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).Print(Precision::Single), "(1.000000, -2.000000, 0)");
}

TEST(ValueVector, Set) {
  Vector first(1.11, -2.22, 3.33);
  first.Set_x_y_z(std::array<double, 3>{-4.44, 5.55, -6.66});
  EXPECT_EQ(first, Vector(-4.44, 5.55, -6.66));

  Vector second(1.11, -2.22, 3.33);
  second.Set_x_y_z(-4.44, 5.55, -6.66);
  EXPECT_EQ(second, Vector(-4.44, 5.55, -6.66));

  Vector third(1.11, -2.22, 3.33);
  third.Set_x(-4.44);
  third.Set_y(5.55);
  third.Set_z(-6.66);
  EXPECT_EQ(third, Vector(-4.44, 5.55, -6.66));
}

TEST(ValueVector, SizeOf) {
  EXPECT_EQ(sizeof(Vector{}), 3 * sizeof(double));
}

TEST(ValueVector, StandardConstructor) {
  EXPECT_EQ(Vector(std::array<double, 3>{1.11, -2.22, 3.33}), Vector(1.11, -2.22, 3.33));

  constexpr std::array<double, 3> first_x_y_z{1.11, -2.22, 3.33};
  EXPECT_EQ(Vector(first_x_y_z), Vector(1.11, -2.22, 3.33));

  constexpr std::array<double, 3> second_x_y_z{1.11, -2.22, 3.33};
  Vector second = Vector::Zero();
  second = second_x_y_z;
  EXPECT_EQ(second, Vector(1.11, -2.22, 3.33));
}

TEST(ValueVector, Stream) {
  constexpr Vector value{1.23, 4.56, 7.89};
  std::ostringstream stream;
  stream << value;
  EXPECT_EQ(stream.str(), value.Print());
}

TEST(ValueVector, XML) {
  EXPECT_EQ(
      Vector(1.0, -2.0, 0.0).XML(), "<x>1.000000000000000</x><y>-2.000000000000000</y><z>0</z>");
}

TEST(ValueVector, YAML) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).YAML(), "{x:1.000000000000000,y:-2.000000000000000,z:0}");
}

TEST(ValueVector, Zero) {
  EXPECT_EQ(Vector::Zero(), Vector(0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
