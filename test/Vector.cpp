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
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F) + Vector(2.0F, -4.0F, 6.0F), Vector(3.0F, -6.0F, 9.0F));
  EXPECT_EQ(Vector(1.0, -2.0, 3.0) + Vector(2.0, -4.0, 6.0), Vector(3.0, -6.0, 9.0));
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L) + Vector(2.0L, -4.0L, 6.0L), Vector(3.0L, -6.0L, 9.0L));
}

TEST(Vector, ArithmeticOperatorDivision) {
  EXPECT_EQ(Vector(2.0F, -4.0F, 6.0F) / 2.0F, Vector(1.0F, -2.0F, 3.0F));
  EXPECT_EQ(Vector(2.0F, -4.0F, 6.0F) / 2.0, Vector(1.0F, -2.0F, 3.0F));
  EXPECT_EQ(Vector(2.0F, -4.0F, 6.0F) / 2.0L, Vector(1.0F, -2.0F, 3.0F));
  EXPECT_EQ(Vector(2.0, -4.0, 6.0) / 2.0F, Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Vector(2.0, -4.0, 6.0) / 2.0, Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Vector(2.0, -4.0, 6.0) / 2.0L, Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Vector(2.0L, -4.0L, 6.0L) / 2.0L, Vector(1.0L, -2.0L, 3.0L));
  EXPECT_EQ(Vector(2.0L, -4.0L, 6.0L) / 2.0, Vector(1.0L, -2.0L, 3.0L));
  EXPECT_EQ(Vector(2.0L, -4.0L, 6.0L) / 2.0L, Vector(1.0L, -2.0L, 3.0L));
}

TEST(Vector, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F) * 2.0F, Vector(2.0F, -4.0F, 6.0F));
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F) * 2.0, Vector(2.0F, -4.0F, 6.0F));
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F) * 2.0L, Vector(2.0F, -4.0F, 6.0F));
  EXPECT_EQ(Vector(1.0, -2.0, 3.0) * 2.0F, Vector(2.0, -4.0, 6.0));
  EXPECT_EQ(Vector(1.0, -2.0, 3.0) * 2.0, Vector(2.0, -4.0, 6.0));
  EXPECT_EQ(Vector(1.0, -2.0, 3.0) * 2.0L, Vector(2.0, -4.0, 6.0));
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L) * 2.0F, Vector(2.0L, -4.0L, 6.0L));
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L) * 2.0, Vector(2.0L, -4.0L, 6.0L));
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L) * 2.0L, Vector(2.0L, -4.0L, 6.0L));
  EXPECT_EQ(2.0F * Vector(1.0F, -2.0F, 3.0F), Vector(2.0F, -4.0F, 6.0F));
  EXPECT_EQ(2.0 * Vector(1.0F, -2.0F, 3.0F), Vector(2.0F, -4.0F, 6.0F));
  EXPECT_EQ(2.0L * Vector(1.0F, -2.0F, 3.0F), Vector(2.0F, -4.0F, 6.0F));
  EXPECT_EQ(2.0F * Vector(1.0, -2.0, 3.0), Vector(2.0, -4.0, 6.0));
  EXPECT_EQ(2.0 * Vector(1.0, -2.0, 3.0), Vector(2.0, -4.0, 6.0));
  EXPECT_EQ(2.0L * Vector(1.0, -2.0, 3.0), Vector(2.0, -4.0, 6.0));
  EXPECT_EQ(2.0F * Vector(1.0L, -2.0L, 3.0L), Vector(2.0L, -4.0L, 6.0L));
  EXPECT_EQ(2.0 * Vector(1.0L, -2.0L, 3.0L), Vector(2.0L, -4.0L, 6.0L));
  EXPECT_EQ(2.0L * Vector(1.0L, -2.0L, 3.0L), Vector(2.0L, -4.0L, 6.0L));
}

TEST(Vector, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Vector(3.0F, -6.0F, 9.0F) - Vector(2.0F, -4.0F, 6.0F), Vector(1.0F, -2.0F, 3.0F));
  EXPECT_EQ(Vector(3.0, -6.0, 9.0) - Vector(2.0, -4.0, 6.0), Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Vector(3.0L, -6.0L, 9.0L) - Vector(2.0L, -4.0L, 6.0L), Vector(1.0L, -2.0L, 3.0L));
}

TEST(Vector, AssignmentOperatorAddition) {
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    vector += Vector(2.0F, -4.0F, 6.0F);
    EXPECT_EQ(vector, Vector(3.0F, -6.0F, 9.0F));
  }
  {
    Vector vector{1.0, -2.0, 3.0};
    vector += Vector(2.0, -4.0, 6.0);
    EXPECT_EQ(vector, Vector(3.0, -6.0, 9.0));
  }
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    vector += Vector(2.0L, -4.0L, 6.0L);
    EXPECT_EQ(vector, Vector(3.0L, -6.0L, 9.0L));
  }
}

TEST(Vector, AssignmentOperatorDivision) {
  {
    Vector vector{2.0F, -4.0F, 6.0F};
    vector /= 2.0F;
    EXPECT_EQ(vector, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    Vector vector{2.0F, -4.0F, 6.0F};
    vector /= 2.0;
    EXPECT_EQ(vector, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    Vector vector{2.0F, -4.0F, 6.0F};
    vector /= 2.0L;
    EXPECT_EQ(vector, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    Vector vector{2.0, -4.0, 6.0};
    vector /= 2.0F;
    EXPECT_EQ(vector, Vector(1.0, -2.0, 3.0));
  }
  {
    Vector vector{2.0, -4.0, 6.0};
    vector /= 2.0;
    EXPECT_EQ(vector, Vector(1.0, -2.0, 3.0));
  }
  {
    Vector vector{2.0, -4.0, 6.0};
    vector /= 2.0L;
    EXPECT_EQ(vector, Vector(1.0, -2.0, 3.0));
  }
  {
    Vector vector{2.0L, -4.0L, 6.0L};
    vector /= 2.0F;
    EXPECT_EQ(vector, Vector(1.0L, -2.0L, 3.0L));
  }
  {
    Vector vector{2.0L, -4.0L, 6.0L};
    vector /= 2.0;
    EXPECT_EQ(vector, Vector(1.0L, -2.0L, 3.0L));
  }
  {
    Vector vector{2.0L, -4.0L, 6.0L};
    vector /= 2.0L;
    EXPECT_EQ(vector, Vector(1.0L, -2.0L, 3.0L));
  }
}

TEST(Vector, AssignmentOperatorMultiplication) {
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    vector *= 2.0F;
    EXPECT_EQ(vector, Vector(2.0F, -4.0F, 6.0F));
  }
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    vector *= 2.0;
    EXPECT_EQ(vector, Vector(2.0F, -4.0F, 6.0F));
  }
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    vector *= 2.0L;
    EXPECT_EQ(vector, Vector(2.0F, -4.0F, 6.0F));
  }
  {
    Vector vector{1.0, -2.0, 3.0};
    vector *= 2.0F;
    EXPECT_EQ(vector, Vector(2.0, -4.0, 6.0));
  }
  {
    Vector vector{1.0, -2.0, 3.0};
    vector *= 2.0;
    EXPECT_EQ(vector, Vector(2.0, -4.0, 6.0));
  }
  {
    Vector vector{1.0, -2.0, 3.0};
    vector *= 2.0L;
    EXPECT_EQ(vector, Vector(2.0, -4.0, 6.0));
  }
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    vector *= 2.0F;
    EXPECT_EQ(vector, Vector(2.0L, -4.0L, 6.0L));
  }
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    vector *= 2.0;
    EXPECT_EQ(vector, Vector(2.0L, -4.0L, 6.0L));
  }
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    vector *= 2.0L;
    EXPECT_EQ(vector, Vector(2.0L, -4.0L, 6.0L));
  }
}

TEST(Vector, AssignmentOperatorSubtraction) {
  {
    Vector vector{3.0F, -6.0F, 9.0F};
    vector -= Vector(2.0F, -4.0F, 6.0F);
    EXPECT_EQ(vector, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    Vector vector{3.0, -6.0, 9.0};
    vector -= Vector(2.0, -4.0, 6.0);
    EXPECT_EQ(vector, Vector(1.0, -2.0, 3.0));
  }
  {
    Vector vector{3.0L, -6.0L, 9.0L};
    vector -= Vector(2.0L, -4.0L, 6.0L);
    EXPECT_EQ(vector, Vector(1.0L, -2.0L, 3.0L));
  }
}

TEST(Vector, ComparisonOperators) {
  {
    constexpr Vector first{1.0F, -2.0F, 3.0F};
    constexpr Vector second{1.0F, -2.0F, 3.000001F};
    constexpr Vector third{1.0F, 2.0F, 3.0F};
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
  {
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
  {
    constexpr Vector first{1.0L, -2.0L, 3.0L};
    constexpr Vector second{1.0L, -2.0L, 3.000001L};
    constexpr Vector third{1.0L, 2.0L, 3.0L};
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
}

TEST(Vector, CopyAssignmentOperator) {
  {
    constexpr Vector first{1.0F, -2.0F, 3.0F};
    Vector second{-4.0F, 5.0F, -6.0F};
    second = first;
    EXPECT_EQ(second, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    constexpr Vector first{1.0F, -2.0F, 3.0F};
    Vector second{-4.0, 5.0, -6.0};
    second = first;
    EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
  }
  {
    constexpr Vector first{1.0F, -2.0F, 3.0F};
    Vector second{-4.0L, 5.0L, -6.0L};
    second = first;
    EXPECT_EQ(second, Vector(1.0L, -2.0L, 3.0L));
  }
  {
    constexpr Vector first{1.0, -2.0, 3.0};
    Vector second{-4.0F, 5.0F, -6.0F};
    second = first;
    EXPECT_EQ(second, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    constexpr Vector first{1.0, -2.0, 3.0};
    Vector second{-4.0, 5.0, -6.0};
    second = first;
    EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
  }
  {
    constexpr Vector first{1.0, -2.0, 3.0};
    Vector second{-4.0L, 5.0L, -6.0L};
    second = first;
    EXPECT_EQ(second, Vector(1.0L, -2.0L, 3.0L));
  }
  {
    constexpr Vector first{1.0L, -2.0L, 3.0L};
    Vector second{-4.0F, 5.0F, -6.0F};
    second = first;
    EXPECT_EQ(second, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    constexpr Vector first{1.0L, -2.0L, 3.0L};
    Vector second{-4.0, 5.0, -6.0};
    second = first;
    EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
  }
  {
    constexpr Vector first{1.0L, -2.0L, 3.0L};
    Vector second{-4.0L, 5.0L, -6.0L};
    second = first;
    EXPECT_EQ(second, Vector(1.0L, -2.0L, 3.0L));
  }
}

TEST(Vector, CopyConstructor) {
  {
    constexpr Vector first(1.0F, -2.0F, 3.0F);
    constexpr Vector<float> second{first};
    EXPECT_EQ(second, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    constexpr Vector first(1.0F, -2.0F, 3.0F);
    constexpr Vector<double> second{first};
    EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
  }
  {
    constexpr Vector first(1.0F, -2.0F, 3.0F);
    constexpr Vector<long double> second{first};
    EXPECT_EQ(second, Vector(1.0L, -2.0L, 3.0L));
  }
  {
    constexpr Vector first(1.0, -2.0, 3.0);
    constexpr Vector<float> second{first};
    EXPECT_EQ(second, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    constexpr Vector first(1.0, -2.0, 3.0);
    constexpr Vector<double> second{first};
    EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
  }
  {
    constexpr Vector first(1.0, -2.0, 3.0);
    constexpr Vector<long double> second{first};
    EXPECT_EQ(second, Vector(1.0L, -2.0L, 3.0L));
  }
  {
    constexpr Vector first(1.0L, -2.0L, 3.0L);
    constexpr Vector<float> second{first};
    EXPECT_EQ(second, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    constexpr Vector first(1.0L, -2.0L, 3.0L);
    constexpr Vector<double> second{first};
    EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
  }
  {
    constexpr Vector first(1.0L, -2.0L, 3.0L);
    constexpr Vector<long double> second{first};
    EXPECT_EQ(second, Vector(1.0L, -2.0L, 3.0L));
  }
}

TEST(Vector, Cross) {
  EXPECT_EQ(Vector(2.0F, 0.0F, 0.0F).Cross(Vector(0.0F, 4.0F, 0.0F)), Vector(0.0F, 0.0F, 8.0F));
  EXPECT_EQ(Vector(2.0, 0.0, 0.0).Cross(Vector(0.0, 4.0, 0.0)), Vector(0.0, 0.0, 8.0));
  EXPECT_EQ(Vector(2.0L, 0.0L, 0.0L).Cross(Vector(0.0L, 4.0L, 0.0L)), Vector(0.0L, 0.0L, 8.0L));
}

TEST(Vector, DefaultConstructor) {
  EXPECT_NO_THROW(Vector{});
  EXPECT_NO_THROW(Vector<>{});
  EXPECT_NO_THROW(Vector<float>{});
  EXPECT_NO_THROW(Vector<double>{});
  EXPECT_NO_THROW(Vector<long double>{});
}

TEST(Vector, Dot) {
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F).Dot(Vector(-4.0F, 5.0F, -6.0F)), -32.0F);
  EXPECT_EQ(Vector(1.0, -2.0, 3.0).Dot(Vector(-4.0, 5.0, -6.0)), -32.0);
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L).Dot(Vector(-4.0L, 5.0L, -6.0L)), -32.0L);
}

TEST(Vector, Hash) {
  {
    constexpr Vector first(1.0F, -2.0F, 3.0F);
    constexpr Vector second(1.0F, -2.0F, 3.000001F);
    constexpr Vector third(1.0F, 2.0F, 3.0F);
    const std::hash<Vector<float><>> hash;
    EXPECT_NE(hash(first), hash(second));
    EXPECT_NE(hash(first), hash(third));
    EXPECT_NE(hash(second), hash(third));
  }
  {
    constexpr Vector first(1.0, -2.0, 3.0);
    constexpr Vector second(1.0, -2.0, 3.000001);
    constexpr Vector third(1.0, 2.0, 3.0);
    const std::hash<Vector<><>> hash;
    EXPECT_NE(hash(first), hash(second));
    EXPECT_NE(hash(first), hash(third));
    EXPECT_NE(hash(second), hash(third));
  }
  {
    constexpr Vector first(1.0L, -2.0L, 3.0L);
    constexpr Vector second(1.0L, -2.0L, 3.000001L);
    constexpr Vector third(1.0L, 2.0L, 3.0L);
    const std::hash<Vector<long double><>> hash;
    EXPECT_NE(hash(first), hash(second));
    EXPECT_NE(hash(first), hash(third));
    EXPECT_NE(hash(second), hash(third));
  }
}

TEST(Vector, JSON) {
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F).JSON(),
            "{\"x\":" + Print(1.0F) + ",\"y\":" + Print(-2.0F) + ",\"z\":" + Print(3.0F) + "}");
  EXPECT_EQ(Vector(1.0, -2.0, 3.0).JSON(),
            "{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0) + "}");
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L).JSON(),
            "{\"x\":" + Print(1.0L) + ",\"y\":" + Print(-2.0L) + ",\"z\":" + Print(3.0L) + "}");
}

TEST(Vector, Magnitude) {
  EXPECT_EQ(Vector(6.0F, -3.0F, 2.0F).Magnitude(), 7.0F);
  EXPECT_EQ(Vector(6.0, -3.0, 2.0).Magnitude(), 7.0);
  EXPECT_EQ(Vector(6.0L, -3.0L, 2.0L).Magnitude(), 7.0L);
}

TEST(Vector, MagnitudeSquared) {
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F).MagnitudeSquared(), 14.0F);
  EXPECT_EQ(Vector(1.0, -2.0, 3.0).MagnitudeSquared(), 14.0);
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L).MagnitudeSquared(), 14.0L);
}

TEST(Vector, MoveAssignmentOperator) {
  {
    Vector first{1.0F, -2.0F, 3.0F};
    Vector second{4.0F, 5.0F, 6.0F};
    second = std::move(first);
    EXPECT_EQ(second, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    Vector first{1.0, -2.0, 3.0};
    Vector second{4.0, 5.0, 6.0};
    second = std::move(first);
    EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
  }
  {
    Vector first{1.0L, -2.0L, 3.0L};
    Vector second{4.0L, 5.0L, 6.0L};
    second = std::move(first);
    EXPECT_EQ(second, Vector(1.0L, -2.0L, 3.0L));
  }
}

TEST(Vector, MoveConstructor) {
  {
    Vector first{1.0F, -2.0F, 3.0F};
    const Vector second{std::move(first)};
    EXPECT_EQ(second, Vector(1.0F, -2.0F, 3.0F));
  }
  {
    Vector first{1.0, -2.0, 3.0};
    const Vector second{std::move(first)};
    EXPECT_EQ(second, Vector(1.0, -2.0, 3.0));
  }
  {
    Vector first{1.0L, -2.0L, 3.0L};
    const Vector second{std::move(first)};
    EXPECT_EQ(second, Vector(1.0L, -2.0L, 3.0L));
  }
}

TEST(Vector, Mutable) {
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    std::array<float, 3>& mutable_x_y_z = vector.Mutable_x_y_z();
    mutable_x_y_z = {-4.0F, 5.0F, -6.0F};
    EXPECT_EQ(vector, Vector(-4.0F, 5.0F, -6.0F));
  }
  {
    Vector vector{1.0, -2.0, 3.0};
    std::array<double, 3>& mutable_x_y_z = vector.Mutable_x_y_z();
    mutable_x_y_z = {-4.0, 5.0, -6.0};
    EXPECT_EQ(vector, Vector(-4.0, 5.0, -6.0));
  }
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    std::array<long double, 3>& mutable_x_y_z = vector.Mutable_x_y_z();
    mutable_x_y_z = {-4.0L, 5.0L, -6.0L};
    EXPECT_EQ(vector, Vector(-4.0L, 5.0L, -6.0L));
  }
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    float& mutable_x = vector.Mutable_x();
    mutable_x = -4.0F;
    float& mutable_y = vector.Mutable_y();
    mutable_y = 5.0F;
    float& mutable_z = vector.Mutable_z();
    mutable_z = -6.0F;
    EXPECT_EQ(vector.x(), -4.0F);
    EXPECT_EQ(vector.y(), 5.0F);
    EXPECT_EQ(vector.z(), -6.0F);
  }
  {
    Vector vector{1.0, -2.0, 3.0};
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
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    long double& mutable_x = vector.Mutable_x();
    mutable_x = -4.0L;
    long double& mutable_y = vector.Mutable_y();
    mutable_y = 5.0L;
    long double& mutable_z = vector.Mutable_z();
    mutable_z = -6.0L;
    EXPECT_EQ(vector.x(), -4.0L);
    EXPECT_EQ(vector.y(), 5.0L);
    EXPECT_EQ(vector.z(), -6.0L);
  }
}

TEST(Vector, Print) {
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F).Print(),
            "(" + Print(1.0F) + ", " + Print(-2.0F) + ", " + Print(3.0F) + ")");
  EXPECT_EQ(Vector(1.0, -2.0, 3.0).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ")");
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L).Print(),
            "(" + Print(1.0L) + ", " + Print(-2.0L) + ", " + Print(3.0L) + ")");
}

TEST(Vector, Set) {
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    vector.Set_x_y_z(std::array<float, 3>{-4.0F, 5.0F, -6.0F});
    EXPECT_EQ(vector, Vector(-4.0F, 5.0F, -6.0F));
  }
  {
    Vector vector{1.0, -2.0, 3.0};
    vector.Set_x_y_z(std::array<double, 3>{-4.0, 5.0, -6.0});
    EXPECT_EQ(vector, Vector(-4.0, 5.0, -6.0));
  }
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    vector.Set_x_y_z(std::array<long double, 3>{-4.0L, 5.0L, -6.0L});
    EXPECT_EQ(vector, Vector(-4.0L, 5.0L, -6.0L));
  }
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    vector.Set_x_y_z(-4.0F, 5.0F, -6.0F);
    EXPECT_EQ(vector, Vector(-4.0F, 5.0F, -6.0F));
  }
  {
    Vector vector{1.0, -2.0, 3.0};
    vector.Set_x_y_z(-4.0, 5.0, -6.0);
    EXPECT_EQ(vector, Vector(-4.0, 5.0, -6.0));
  }
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    vector.Set_x_y_z(-4.0L, 5.0L, -6.0L);
    EXPECT_EQ(vector, Vector(-4.0L, 5.0L, -6.0L));
  }
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    vector.Set_x(-4.0F);
    vector.Set_y(5.0F);
    vector.Set_z(-6.0F);
    EXPECT_EQ(vector, Vector(-4.0F, 5.0F, -6.0F));
  }
  {
    Vector vector{1.0, -2.0, 3.0};
    vector.Set_x(-4.0);
    vector.Set_y(5.0);
    vector.Set_z(-6.0);
    EXPECT_EQ(vector, Vector(-4.0, 5.0, -6.0));
  }
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    vector.Set_x(-4.0L);
    vector.Set_y(5.0L);
    vector.Set_z(-6.0L);
    EXPECT_EQ(vector, Vector(-4.0L, 5.0L, -6.0L));
  }
}

TEST(Vector, SizeOf) {
  EXPECT_EQ(sizeof(Vector<>{}), 3 * sizeof(double));
  EXPECT_EQ(sizeof(Vector<float>{}), 3 * sizeof(float));
  EXPECT_EQ(sizeof(Vector<double>{}), 3 * sizeof(double));
  EXPECT_EQ(sizeof(Vector<long double>{}), 3 * sizeof(long double));
}

TEST(Vector, StandardConstructor) {
  EXPECT_EQ(Vector(std::array<float, 3>{1.0F, -2.0F, 3.0F}), Vector(1.0F, -2.0F, 3.0F));
  EXPECT_EQ(Vector(std::array<double, 3>{1.0, -2.0, 3.0}), Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Vector(std::array<long double, 3>{1.0L, -2.0L, 3.0L}), Vector(1.0L, -2.0L, 3.0L));
  {
    Vector vector{1.0F, -2.0F, 3.0F};
    vector = std::array<float, 3>{-4.0F, 5.0F, -6.0F};
    EXPECT_EQ(vector, Vector(-4.0F, 5.0F, -6.0F));
  }
  {
    Vector vector{1.0, -2.0, 3.0};
    vector = std::array<double, 3>{-4.0, 5.0, -6.0};
    EXPECT_EQ(vector, Vector(-4.0, 5.0, -6.0));
  }
  {
    Vector vector{1.0L, -2.0L, 3.0L};
    vector = std::array<long double, 3>{-4.0L, 5.0L, -6.0L};
    EXPECT_EQ(vector, Vector(-4.0L, 5.0L, -6.0L));
  }
}

TEST(Vector, Stream) {
  {
    std::ostringstream stream;
    stream << Vector{1.0F, -2.0F, 3.0F};
    EXPECT_EQ(stream.str(), Vector(1.0F, -2.0F, 3.0F).Print());
  }
  {
    std::ostringstream stream;
    stream << Vector{1.0, -2.0, 3.0};
    EXPECT_EQ(stream.str(), Vector(1.0, -2.0, 3.0).Print());
  }
  {
    std::ostringstream stream;
    stream << Vector{1.0L, -2.0L, 3.0L};
    EXPECT_EQ(stream.str(), Vector(1.0L, -2.0L, 3.0L).Print());
  }
}

TEST(Vector, XML) {
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F).XML(),
            "<x>" + Print(1.0F) + "</x><y>" + Print(-2.0F) + "</y><z>" + Print(3.0F) + "</z>");
  EXPECT_EQ(Vector(1.0, -2.0, 3.0).XML(),
            "<x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0) + "</z>");
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L).XML(),
            "<x>" + Print(1.0L) + "</x><y>" + Print(-2.0L) + "</y><z>" + Print(3.0L) + "</z>");
}

TEST(Vector, YAML) {
  EXPECT_EQ(Vector(1.0F, -2.0F, 3.0F).YAML(),
            "{x:" + Print(1.0F) + ",y:" + Print(-2.0F) + ",z:" + Print(3.0F) + "}");
  EXPECT_EQ(Vector(1.0, -2.0, 3.0).YAML(),
            "{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "}");
  EXPECT_EQ(Vector(1.0L, -2.0L, 3.0L).YAML(),
            "{x:" + Print(1.0L) + ",y:" + Print(-2.0L) + ",z:" + Print(3.0L) + "}");
}

TEST(Vector, Zero) {
  EXPECT_EQ(Vector<><>::Zero(), Vector(0.0, 0.0, 0.0));
  EXPECT_EQ(Vector<float><>::Zero(), Vector(0.0F, 0.0F, 0.0F));
  EXPECT_EQ(Vector<double><>::Zero(), Vector(0.0, 0.0, 0.0));
  EXPECT_EQ(Vector<long double><>::Zero(), Vector(0.0L, 0.0L, 0.0L));
}

}  // namespace

}  // namespace PhQ
