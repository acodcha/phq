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

#include "../../include/PhQ/Value/Vector.hpp"

#include <gtest/gtest.h>

#include <unordered_set>

namespace PhQ::Value {

namespace {

TEST(ValueVector, Accessor) {
  constexpr std::array<double, 3> value0{1.23, 4.56, 7.89};
  constexpr Vector vector0{value0};
  EXPECT_EQ(vector0.x_y_z(), value0);
  EXPECT_EQ(vector0.x(), 1.23);
  EXPECT_EQ(vector0.y(), 4.56);
  EXPECT_EQ(vector0.z(), 7.89);

  Vector vector1{1.23, 4.56, 7.89};
  std::array<double, 3>& value1{vector1.Mutable_x_y_z()};
  value1 = {0.11, 0.22, 0.33};
  EXPECT_EQ(vector1.x(), 0.11);
  EXPECT_EQ(vector1.y(), 0.22);
  EXPECT_EQ(vector1.z(), 0.33);

  Vector vector2{1.23, 4.56, 7.89};
  double& x{vector2.Mutable_x()};
  x = 0.11;
  double& y{vector2.Mutable_y()};
  y = 0.22;
  double& z{vector2.Mutable_z()};
  z = 0.33;
  EXPECT_EQ(vector2.x(), 0.11);
  EXPECT_EQ(vector2.y(), 0.22);
  EXPECT_EQ(vector2.z(), 0.33);

  Vector vector3{1.23, 4.56, 7.89};
  vector3.Set_x_y_z({0.11, 0.22, 0.33});
  EXPECT_EQ(vector3.x(), 0.11);
  EXPECT_EQ(vector3.y(), 0.22);
  EXPECT_EQ(vector3.z(), 0.33);

  Vector vector4{1.23, 4.56, 7.89};
  vector4.Set_x(0.11);
  vector4.Set_y(0.22);
  vector4.Set_z(0.33);
  EXPECT_EQ(vector4.x(), 0.11);
  EXPECT_EQ(vector4.y(), 0.22);
  EXPECT_EQ(vector4.z(), 0.33);
}

TEST(ValueVector, Arithmetic) {
  constexpr Vector vector0{2.0, 4.0, 8.0};
  EXPECT_EQ(vector0 + vector0, Vector(4.0, 8.0, 16.0));
  EXPECT_EQ(vector0 - vector0, Vector(0.0, 0.0, 0.0));
  EXPECT_EQ(vector0 * 2.0, Vector(4.0, 8.0, 16.0));
  EXPECT_EQ(2.0 * vector0, Vector(4.0, 8.0, 16.0));
  EXPECT_EQ(vector0 / 2.0, Vector(1.0, 2.0, 4.0));

  Vector vector1{1.0, 2.0, 4.0};
  vector1 += Vector{1.0, 2.0, 4.0};
  EXPECT_EQ(vector1, Vector(2.0, 4.0, 8.0));

  Vector vector2{2.0, 4.0, 8.0};
  vector2 -= Vector{1.0, 2.0, 4.0};
  EXPECT_EQ(vector2, Vector(1.0, 2.0, 4.0));

  Vector vector3{1.0, 2.0, 4.0};
  vector3 *= 2.0;
  EXPECT_EQ(vector3, Vector(2.0, 4.0, 8.0));

  Vector vector4{2.0, 4.0, 8.0};
  vector4 /= 2.0;
  EXPECT_EQ(vector4, Vector(1.0, 2.0, 4.0));
}

TEST(ValueVector, Comparison) {
  constexpr Vector vector0{1.1, 2.2, 3.3};
  constexpr Vector vector1{1.1, 2.3, 3.3};
  constexpr Vector vector2{1.1, 2.3, 3.4};
  EXPECT_EQ(vector0, vector0);
  EXPECT_NE(vector0, vector1);
  EXPECT_LT(vector0, vector1);
  EXPECT_LT(vector1, vector2);
  EXPECT_GT(vector1, vector0);
  EXPECT_GT(vector2, vector1);
  EXPECT_LE(vector0, vector0);
  EXPECT_LE(vector0, vector1);
  EXPECT_LE(vector1, vector2);
  EXPECT_GE(vector0, vector0);
  EXPECT_GE(vector1, vector0);
  EXPECT_GE(vector2, vector1);
}

TEST(ValueVector, Constructor) {
  constexpr std::array<double, 3> array_reference{1.23, 4.56, 7.89};
  constexpr Vector reference{1.23, 4.56, 7.89};

  // Default constructor.
  constexpr Vector default_;

  // Constructor from array.
  constexpr Vector from_array{array_reference};
  EXPECT_EQ(from_array, reference);

  // Copy constructor.
  constexpr Vector copy_constructed{reference};
  EXPECT_EQ(copy_constructed, reference);

  // Copy-assignment operator.
  Vector copy_assigned = Vector::Zero();
  copy_assigned = reference;
  EXPECT_EQ(copy_assigned, reference);

  // Copy-assignment operator from array.
  Vector copy_assigned_from_array = Vector::Zero();
  copy_assigned_from_array = array_reference;
  EXPECT_EQ(copy_assigned_from_array, reference);

  // Move constructor.
  Vector to_move_construct{1.23, 4.56, 7.89};
  Vector move_constructed{std::move(to_move_construct)};
  EXPECT_EQ(move_constructed, reference);

  // Move constructor from array.
  std::array<double, 3> array_to_move_construct{1.23, 4.56, 7.89};
  Vector move_constructed_from_array{std::move(array_to_move_construct)};
  EXPECT_EQ(move_constructed_from_array, reference);

  // Move-assignment operator.
  Vector to_move_assign{1.23, 4.56, 7.89};
  Vector move_assigned = Vector::Zero();
  move_assigned = std::move(to_move_assign);
  EXPECT_EQ(move_assigned, reference);

  // Move-assignment operator from array.
  std::array<double, 3> array_to_move_assign{1.23, 4.56, 7.89};
  Vector move_assigned_from_array = Vector::Zero();
  move_assigned_from_array = std::move(array_to_move_assign);
  EXPECT_EQ(move_assigned_from_array, reference);
}

TEST(ValueVector, Cross) {
  EXPECT_EQ(Vector(10.0, 0.0, 0.0).Cross(Vector(0.0, 20.0, 0.0)),
            Vector(0.0, 0.0, 200.0));
}

TEST(ValueVector, Dot) {
  constexpr Vector vector0{1.23, 4.56, 7.89};
  EXPECT_EQ(vector0.Dot(vector0), vector0.MagnitudeSquared());
  EXPECT_EQ(Vector(0.0, 10.0, -15.0).Dot(Vector(20.0, 0.0, 0.0)), 0.0);
  EXPECT_EQ(
      vector0.Dot(Vector(-1.23, -4.56, -7.89)), -vector0.MagnitudeSquared());
}

TEST(ValueVector, Hash) {
  constexpr Vector vector0{10.0, 0.0, 0.0};
  constexpr Vector vector1{0.0, 10.0, 0.0};
  constexpr Vector vector2{0.0, 0.0, 10.0};
  constexpr Vector vector3{-10.0, 0.0, 0.0};
  constexpr Vector vector4{1.11, 2.22, 3.33};
  constexpr Vector vector5{1.23, 4.56, 7.89};
  constexpr std::hash<Vector> hasher;
  EXPECT_NE(hasher(vector0), hasher(vector1));
  EXPECT_NE(hasher(vector0), hasher(vector2));
  EXPECT_NE(hasher(vector0), hasher(vector3));
  EXPECT_NE(hasher(vector0), hasher(vector4));
  EXPECT_NE(hasher(vector0), hasher(vector5));
  const std::unordered_set<Vector> unordered{
      vector0, vector1, vector2, vector3, vector4, vector5};
}

TEST(ValueVector, JSON) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).JSON(),
            "{\"x\":1.000000000000000,\"y\":-2.000000000000000,\"z\":0}");
}

TEST(ValueVector, Magnitude) {
  EXPECT_EQ(Vector(0.0, 0.0, 5.5e10).Magnitude(), 5.5e10);
  EXPECT_EQ(Vector(-1.0, 2.0, -3.0).MagnitudeSquared(), 14.0);
}

TEST(ValueVector, Print) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).Print(),
            "(1.000000000000000, -2.000000000000000, 0)");
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).Print(Precision::Double),
            "(1.000000000000000, -2.000000000000000, 0)");
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).Print(Precision::Single),
            "(1.000000, -2.000000, 0)");
}

TEST(ValueVector, SizeOf) {
  constexpr Vector vector{1.23, 4.56, 7.89};
  EXPECT_EQ(sizeof(vector), 3 * sizeof(double));
}

TEST(ValueVector, Stream) {
  constexpr Vector vector{1.23, 4.56, 7.89};
  std::ostringstream stream;
  stream << vector;
  EXPECT_EQ(stream.str(), vector.Print());
}

TEST(ValueVector, XML) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).XML(),
            "<x>1.000000000000000</x><y>-2.000000000000000</y><z>0</z>");
}

TEST(ValueVector, YAML) {
  EXPECT_EQ(Vector(1.0, -2.0, 0.0).YAML(),
            "{x:1.000000000000000,y:-2.000000000000000,z:0}");
}

TEST(ValueVector, Zero) {
  EXPECT_EQ(Vector::Zero(), Vector(0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ::Value
