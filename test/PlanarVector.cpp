// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/PlanarVector.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

namespace PhQ {

namespace {

TEST(PlanarVector, ArithmeticOperatorAddition) {
  EXPECT_EQ(PlanarVector(1.0F, -2.0F) + PlanarVector(2.0F, -4.0F), PlanarVector(3.0F, -6.0F));
  EXPECT_EQ(PlanarVector(1.0, -2.0) + PlanarVector(2.0, -4.0), PlanarVector(3.0, -6.0));
  EXPECT_EQ(PlanarVector(1.0L, -2.0L) + PlanarVector(2.0L, -4.0L), PlanarVector(3.0L, -6.0L));
}

TEST(PlanarVector, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarVector(2.0F, -4.0F) / 2.0F, PlanarVector(1.0F, -2.0F));
  EXPECT_EQ(PlanarVector(2.0F, -4.0F) / 2.0, PlanarVector(1.0F, -2.0F));
  EXPECT_EQ(PlanarVector(2.0F, -4.0F) / 2.0L, PlanarVector(1.0F, -2.0F));
  EXPECT_EQ(PlanarVector(2.0, -4.0) / 2.0F, PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarVector(2.0, -4.0) / 2.0, PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarVector(2.0, -4.0) / 2.0L, PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarVector(2.0L, -4.0L) / 2.0L, PlanarVector(1.0L, -2.0L));
  EXPECT_EQ(PlanarVector(2.0L, -4.0L) / 2.0, PlanarVector(1.0L, -2.0L));
  EXPECT_EQ(PlanarVector(2.0L, -4.0L) / 2.0L, PlanarVector(1.0L, -2.0L));
}

TEST(PlanarVector, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarVector(1.0F, -2.0F) * 2.0F, PlanarVector(2.0F, -4.0F));
  EXPECT_EQ(PlanarVector(1.0F, -2.0F) * 2.0, PlanarVector(2.0F, -4.0F));
  EXPECT_EQ(PlanarVector(1.0F, -2.0F) * 2.0L, PlanarVector(2.0F, -4.0F));
  EXPECT_EQ(PlanarVector(1.0, -2.0) * 2.0F, PlanarVector(2.0, -4.0));
  EXPECT_EQ(PlanarVector(1.0, -2.0) * 2.0, PlanarVector(2.0, -4.0));
  EXPECT_EQ(PlanarVector(1.0, -2.0) * 2.0L, PlanarVector(2.0, -4.0));
  EXPECT_EQ(PlanarVector(1.0L, -2.0L) * 2.0F, PlanarVector(2.0L, -4.0L));
  EXPECT_EQ(PlanarVector(1.0L, -2.0L) * 2.0, PlanarVector(2.0L, -4.0L));
  EXPECT_EQ(PlanarVector(1.0L, -2.0L) * 2.0L, PlanarVector(2.0L, -4.0L));
  EXPECT_EQ(2.0F * PlanarVector(1.0F, -2.0F), PlanarVector(2.0F, -4.0F));
  EXPECT_EQ(2.0 * PlanarVector(1.0F, -2.0F), PlanarVector(2.0F, -4.0F));
  EXPECT_EQ(2.0L * PlanarVector(1.0F, -2.0F), PlanarVector(2.0F, -4.0F));
  EXPECT_EQ(2.0F * PlanarVector(1.0, -2.0), PlanarVector(2.0, -4.0));
  EXPECT_EQ(2.0 * PlanarVector(1.0, -2.0), PlanarVector(2.0, -4.0));
  EXPECT_EQ(2.0L * PlanarVector(1.0, -2.0), PlanarVector(2.0, -4.0));
  EXPECT_EQ(2.0F * PlanarVector(1.0L, -2.0L), PlanarVector(2.0L, -4.0L));
  EXPECT_EQ(2.0 * PlanarVector(1.0L, -2.0L), PlanarVector(2.0L, -4.0L));
  EXPECT_EQ(2.0L * PlanarVector(1.0L, -2.0L), PlanarVector(2.0L, -4.0L));
}

TEST(PlanarVector, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PlanarVector(3.0F, -6.0F) - PlanarVector(2.0F, -4.0F), PlanarVector(1.0F, -2.0F));
  EXPECT_EQ(PlanarVector(3.0, -6.0) - PlanarVector(2.0, -4.0), PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarVector(3.0L, -6.0L) - PlanarVector(2.0L, -4.0L), PlanarVector(1.0L, -2.0L));
}

TEST(PlanarVector, AssignmentOperatorAddition) {
  {
    PlanarVector vector{1.0F, -2.0F};
    vector += PlanarVector(2.0F, -4.0F);
    EXPECT_EQ(vector, PlanarVector(3.0F, -6.0F));
  }
  {
    PlanarVector vector{1.0, -2.0};
    vector += PlanarVector(2.0, -4.0);
    EXPECT_EQ(vector, PlanarVector(3.0, -6.0));
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    vector += PlanarVector(2.0L, -4.0L);
    EXPECT_EQ(vector, PlanarVector(3.0L, -6.0L));
  }
}

TEST(PlanarVector, AssignmentOperatorDivision) {
  {
    PlanarVector vector{2.0F, -4.0F};
    vector /= 2.0F;
    EXPECT_EQ(vector, PlanarVector(1.0F, -2.0F));
  }
  {
    PlanarVector vector{2.0F, -4.0F};
    vector /= 2.0;
    EXPECT_EQ(vector, PlanarVector(1.0F, -2.0F));
  }
  {
    PlanarVector vector{2.0F, -4.0F};
    vector /= 2.0L;
    EXPECT_EQ(vector, PlanarVector(1.0F, -2.0F));
  }
  {
    PlanarVector vector{2.0, -4.0};
    vector /= 2.0F;
    EXPECT_EQ(vector, PlanarVector(1.0, -2.0));
  }
  {
    PlanarVector vector{2.0, -4.0};
    vector /= 2.0;
    EXPECT_EQ(vector, PlanarVector(1.0, -2.0));
  }
  {
    PlanarVector vector{2.0, -4.0};
    vector /= 2.0L;
    EXPECT_EQ(vector, PlanarVector(1.0, -2.0));
  }
  {
    PlanarVector vector{2.0L, -4.0L};
    vector /= 2.0F;
    EXPECT_EQ(vector, PlanarVector(1.0L, -2.0L));
  }
  {
    PlanarVector vector{2.0L, -4.0L};
    vector /= 2.0;
    EXPECT_EQ(vector, PlanarVector(1.0L, -2.0L));
  }
  {
    PlanarVector vector{2.0L, -4.0L};
    vector /= 2.0L;
    EXPECT_EQ(vector, PlanarVector(1.0L, -2.0L));
  }
}

TEST(PlanarVector, AssignmentOperatorMultiplication) {
  {
    PlanarVector vector{1.0F, -2.0F};
    vector *= 2.0F;
    EXPECT_EQ(vector, PlanarVector(2.0F, -4.0F));
  }
  {
    PlanarVector vector{1.0F, -2.0F};
    vector *= 2.0;
    EXPECT_EQ(vector, PlanarVector(2.0F, -4.0F));
  }
  {
    PlanarVector vector{1.0F, -2.0F};
    vector *= 2.0L;
    EXPECT_EQ(vector, PlanarVector(2.0F, -4.0F));
  }
  {
    PlanarVector vector{1.0, -2.0};
    vector *= 2.0F;
    EXPECT_EQ(vector, PlanarVector(2.0, -4.0));
  }
  {
    PlanarVector vector{1.0, -2.0};
    vector *= 2.0;
    EXPECT_EQ(vector, PlanarVector(2.0, -4.0));
  }
  {
    PlanarVector vector{1.0, -2.0};
    vector *= 2.0L;
    EXPECT_EQ(vector, PlanarVector(2.0, -4.0));
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    vector *= 2.0F;
    EXPECT_EQ(vector, PlanarVector(2.0L, -4.0L));
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    vector *= 2.0;
    EXPECT_EQ(vector, PlanarVector(2.0L, -4.0L));
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    vector *= 2.0L;
    EXPECT_EQ(vector, PlanarVector(2.0L, -4.0L));
  }
}

TEST(PlanarVector, AssignmentOperatorSubtraction) {
  {
    PlanarVector vector{3.0F, -6.0F};
    vector -= PlanarVector(2.0F, -4.0F);
    EXPECT_EQ(vector, PlanarVector(1.0F, -2.0F));
  }
  {
    PlanarVector vector{3.0, -6.0};
    vector -= PlanarVector(2.0, -4.0);
    EXPECT_EQ(vector, PlanarVector(1.0, -2.0));
  }
  {
    PlanarVector vector{3.0L, -6.0L};
    vector -= PlanarVector(2.0L, -4.0L);
    EXPECT_EQ(vector, PlanarVector(1.0L, -2.0L));
  }
}

TEST(PlanarVector, ComparisonOperators) {
  {
    constexpr PlanarVector first{1.0F, -2.000001F};
    constexpr PlanarVector second{1.0F, -2.0F};
    constexpr PlanarVector third{1.0F, 2.0F};
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
    constexpr PlanarVector first{1.0, -2.000001};
    constexpr PlanarVector second{1.0, -2.0};
    constexpr PlanarVector third{1.0, 2.0};
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
    constexpr PlanarVector first{1.0L, -2.000001L};
    constexpr PlanarVector second{1.0L, -2.0L};
    constexpr PlanarVector third{1.0L, 2.0L};
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

TEST(PlanarVector, Constructor) {
  EXPECT_EQ(PlanarVector(std::array<float, 2>{1.0F, -2.0F}), PlanarVector(1.0F, -2.0F));
  EXPECT_EQ(PlanarVector(std::array<double, 2>{1.0, -2.0}), PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarVector(std::array<long double, 2>{1.0L, -2.0L}), PlanarVector(1.0L, -2.0L));
  {
    PlanarVector vector{1.0F, -2.0F};
    vector = std::array<float, 2>{-3.0F, 4.0F};
    EXPECT_EQ(vector, PlanarVector(-3.0F, 4.0F));
  }
  {
    PlanarVector vector{1.0, -2.0};
    vector = std::array<double, 2>{-3.0, 4.0};
    EXPECT_EQ(vector, PlanarVector(-3.0, 4.0));
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    vector = std::array<long double, 2>{-3.0L, 4.0L};
    EXPECT_EQ(vector, PlanarVector(-3.0L, 4.0L));
  }
}

TEST(PlanarVector, CopyAssignmentOperator) {
  {
    constexpr PlanarVector first{1.0F, -2.0F};
    PlanarVector second{-3.0F, 4.0F};
    second = first;
    EXPECT_EQ(second, PlanarVector(1.0F, -2.0F));
  }
  {
    constexpr PlanarVector first{1.0F, -2.0F};
    PlanarVector second{-3.0, 4.0};
    second = first;
    EXPECT_EQ(second, PlanarVector(1.0, -2.0));
  }
  {
    constexpr PlanarVector first{1.0F, -2.0F};
    PlanarVector second{-3.0L, 4.0L};
    second = first;
    EXPECT_EQ(second, PlanarVector(1.0L, -2.0L));
  }
  {
    constexpr PlanarVector first{1.0, -2.0};
    PlanarVector second{-3.0F, 4.0F};
    second = first;
    EXPECT_EQ(second, PlanarVector(1.0F, -2.0F));
  }
  {
    constexpr PlanarVector first{1.0, -2.0};
    PlanarVector second{-3.0, 4.0};
    second = first;
    EXPECT_EQ(second, PlanarVector(1.0, -2.0));
  }
  {
    constexpr PlanarVector first{1.0, -2.0};
    PlanarVector second{-3.0L, 4.0L};
    second = first;
    EXPECT_EQ(second, PlanarVector(1.0L, -2.0L));
  }
  {
    constexpr PlanarVector first{1.0L, -2.0L};
    PlanarVector second{-3.0F, 4.0F};
    second = first;
    EXPECT_EQ(second, PlanarVector(1.0F, -2.0F));
  }
  {
    constexpr PlanarVector first{1.0L, -2.0L};
    PlanarVector second{-3.0, 4.0};
    second = first;
    EXPECT_EQ(second, PlanarVector(1.0, -2.0));
  }
  {
    constexpr PlanarVector first{1.0L, -2.0L};
    PlanarVector second{-3.0L, 4.0L};
    second = first;
    EXPECT_EQ(second, PlanarVector(1.0L, -2.0L));
  }
}

TEST(PlanarVector, CopyConstructor) {
  {
    constexpr PlanarVector first(1.0F, -2.0F);
    constexpr PlanarVector<float> second{first};
    EXPECT_EQ(second, PlanarVector(1.0F, -2.0F));
  }
  {
    constexpr PlanarVector first(1.0F, -2.0F);
    constexpr PlanarVector<double> second{first};
    EXPECT_EQ(second, PlanarVector(1.0, -2.0));
  }
  {
    constexpr PlanarVector first(1.0F, -2.0F);
    constexpr PlanarVector<long double> second{first};
    EXPECT_EQ(second, PlanarVector(1.0L, -2.0L));
  }
  {
    constexpr PlanarVector first(1.0, -2.0);
    constexpr PlanarVector<float> second{first};
    EXPECT_EQ(second, PlanarVector(1.0F, -2.0F));
  }
  {
    constexpr PlanarVector first(1.0, -2.0);
    constexpr PlanarVector<double> second{first};
    EXPECT_EQ(second, PlanarVector(1.0, -2.0));
  }
  {
    constexpr PlanarVector first(1.0, -2.0);
    constexpr PlanarVector<long double> second{first};
    EXPECT_EQ(second, PlanarVector(1.0L, -2.0L));
  }
  {
    constexpr PlanarVector first(1.0L, -2.0L);
    constexpr PlanarVector<float> second{first};
    EXPECT_EQ(second, PlanarVector(1.0F, -2.0F));
  }
  {
    constexpr PlanarVector first(1.0L, -2.0L);
    constexpr PlanarVector<double> second{first};
    EXPECT_EQ(second, PlanarVector(1.0, -2.0));
  }
  {
    constexpr PlanarVector first(1.0L, -2.0L);
    constexpr PlanarVector<long double> second{first};
    EXPECT_EQ(second, PlanarVector(1.0L, -2.0L));
  }
}

TEST(PlanarVector, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarVector{});
  EXPECT_NO_THROW(PlanarVector<>{});
  EXPECT_NO_THROW(PlanarVector<float>{});
  EXPECT_NO_THROW(PlanarVector<double>{});
  EXPECT_NO_THROW(PlanarVector<long double>{});
}

TEST(PlanarVector, Dot) {
  EXPECT_EQ(PlanarVector(1.0F, -2.0F).Dot(PlanarVector(-4.0F, 5.0F)), -14.0F);
  EXPECT_EQ(PlanarVector(1.0, -2.0).Dot(PlanarVector(-4.0, 5.0)), -14.0);
  EXPECT_EQ(PlanarVector(1.0L, -2.0L).Dot(PlanarVector(-4.0L, 5.0L)), -14.0L);
}

TEST(PlanarVector, Hash) {
  {
    constexpr PlanarVector first(1.0F, -2.000001F);
    constexpr PlanarVector second(1.0F, -2.0F);
    constexpr PlanarVector third(1.0F, 2.0F);
    const std::hash<PlanarVector<float>> hash;
    EXPECT_NE(hash(first), hash(second));
    EXPECT_NE(hash(first), hash(third));
    EXPECT_NE(hash(second), hash(third));
  }
  {
    constexpr PlanarVector first(1.0, -2.000001);
    constexpr PlanarVector second(1.0, -2.0);
    constexpr PlanarVector third(1.0, 2.0);
    const std::hash<PlanarVector<>> hash;
    EXPECT_NE(hash(first), hash(second));
    EXPECT_NE(hash(first), hash(third));
    EXPECT_NE(hash(second), hash(third));
  }
  {
    constexpr PlanarVector first(1.0L, -2.000001L);
    constexpr PlanarVector second(1.0L, -2.0L);
    constexpr PlanarVector third(1.0L, 2.0L);
    const std::hash<PlanarVector<long double>> hash;
    EXPECT_NE(hash(first), hash(second));
    EXPECT_NE(hash(first), hash(third));
    EXPECT_NE(hash(second), hash(third));
  }
}

TEST(PlanarVector, JSON) {
  EXPECT_EQ(
      PlanarVector(1.0F, -2.0F).JSON(), "{\"x\":" + Print(1.0F) + ",\"y\":" + Print(-2.0F) + "}");
  EXPECT_EQ(PlanarVector(1.0, -2.0).JSON(), "{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "}");
  EXPECT_EQ(
      PlanarVector(1.0L, -2.0L).JSON(), "{\"x\":" + Print(1.0L) + ",\"y\":" + Print(-2.0L) + "}");
}

TEST(PlanarVector, Magnitude) {
  EXPECT_EQ(PlanarVector(3.0F, -4.0F).Magnitude(), 5.0F);
  EXPECT_EQ(PlanarVector(3.0, -4.0).Magnitude(), 5.0);
  EXPECT_EQ(PlanarVector(3.0L, -4.0L).Magnitude(), 5.0L);
}

TEST(PlanarVector, MagnitudeSquared) {
  EXPECT_EQ(PlanarVector(3.0F, -4.0F).MagnitudeSquared(), 25.0F);
  EXPECT_EQ(PlanarVector(3.0, -4.0).MagnitudeSquared(), 25.0);
  EXPECT_EQ(PlanarVector(3.0L, -4.0L).MagnitudeSquared(), 25.0L);
}

TEST(PlanarVector, MoveAssignmentOperator) {
  {
    PlanarVector first{1.0F, -2.0F};
    PlanarVector second{4.0F, 5.0F};
    second = std::move(first);
    EXPECT_EQ(second, PlanarVector(1.0F, -2.0F));
  }
  {
    PlanarVector first{1.0, -2.0};
    PlanarVector second{4.0, 5.0};
    second = std::move(first);
    EXPECT_EQ(second, PlanarVector(1.0, -2.0));
  }
  {
    PlanarVector first{1.0L, -2.0L};
    PlanarVector second{4.0L, 5.0L};
    second = std::move(first);
    EXPECT_EQ(second, PlanarVector(1.0L, -2.0L));
  }
}

TEST(PlanarVector, MoveConstructor) {
  {
    PlanarVector first{1.0F, -2.0F};
    const PlanarVector second{std::move(first)};
    EXPECT_EQ(second, PlanarVector(1.0F, -2.0F));
  }
  {
    PlanarVector first{1.0, -2.0};
    const PlanarVector second{std::move(first)};
    EXPECT_EQ(second, PlanarVector(1.0, -2.0));
  }
  {
    PlanarVector first{1.0L, -2.0L};
    const PlanarVector second{std::move(first)};
    EXPECT_EQ(second, PlanarVector(1.0L, -2.0L));
  }
}

TEST(PlanarVector, Mutable) {
  {
    PlanarVector vector{1.0F, -2.0F};
    std::array<float, 2>& mutable_x_y = vector.Mutable_x_y();
    mutable_x_y = {-3.0F, 4.0F};
    EXPECT_EQ(vector, PlanarVector(-3.0F, 4.0F));
  }
  {
    PlanarVector vector{1.0, -2.0};
    std::array<double, 2>& mutable_x_y = vector.Mutable_x_y();
    mutable_x_y = {-3.0, 4.0};
    EXPECT_EQ(vector, PlanarVector(-3.0, 4.0));
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    std::array<long double, 2>& mutable_x_y = vector.Mutable_x_y();
    mutable_x_y = {-3.0L, 4.0L};
    EXPECT_EQ(vector, PlanarVector(-3.0L, 4.0L));
  }
  {
    PlanarVector vector{1.0F, -2.0F};
    float& mutable_x = vector.Mutable_x();
    mutable_x = -3.0F;
    float& mutable_y = vector.Mutable_y();
    mutable_y = 4.0F;
    EXPECT_EQ(vector.x(), -3.0F);
    EXPECT_EQ(vector.y(), 4.0F);
  }
  {
    PlanarVector vector{1.0, -2.0};
    double& mutable_x = vector.Mutable_x();
    mutable_x = -3.0;
    double& mutable_y = vector.Mutable_y();
    mutable_y = 4.0;
    EXPECT_EQ(vector.x(), -3.0);
    EXPECT_EQ(vector.y(), 4.0);
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    long double& mutable_x = vector.Mutable_x();
    mutable_x = -3.0L;
    long double& mutable_y = vector.Mutable_y();
    mutable_y = 4.0L;
    EXPECT_EQ(vector.x(), -3.0L);
    EXPECT_EQ(vector.y(), 4.0L);
  }
}

TEST(PlanarVector, Print) {
  EXPECT_EQ(PlanarVector(1.0F, -2.0F).Print(), "(" + Print(1.0F) + ", " + Print(-2.0F) + ")");
  EXPECT_EQ(PlanarVector(1.0, -2.0).Print(), "(" + Print(1.0) + ", " + Print(-2.0) + ")");
  EXPECT_EQ(PlanarVector(1.0L, -2.0L).Print(), "(" + Print(1.0L) + ", " + Print(-2.0L) + ")");
}

TEST(PlanarVector, Set) {
  {
    PlanarVector vector{1.0F, -2.0F};
    vector.Set_x_y(std::array<float, 2>{-3.0F, 4.0F});
    EXPECT_EQ(vector, PlanarVector(-3.0F, 4.0F));
  }
  {
    PlanarVector vector{1.0, -2.0};
    vector.Set_x_y(std::array<double, 2>{-3.0, 4.0});
    EXPECT_EQ(vector, PlanarVector(-3.0, 4.0));
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    vector.Set_x_y(std::array<long double, 2>{-3.0L, 4.0L});
    EXPECT_EQ(vector, PlanarVector(-3.0L, 4.0L));
  }
  {
    PlanarVector vector{1.0F, -2.0F};
    vector.Set_x_y(-3.0F, 4.0F);
    EXPECT_EQ(vector, PlanarVector(-3.0F, 4.0F));
  }
  {
    PlanarVector vector{1.0, -2.0};
    vector.Set_x_y(-3.0, 4.0);
    EXPECT_EQ(vector, PlanarVector(-3.0, 4.0));
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    vector.Set_x_y(-3.0L, 4.0L);
    EXPECT_EQ(vector, PlanarVector(-3.0L, 4.0L));
  }
  {
    PlanarVector vector{1.0F, -2.0F};
    vector.Set_x(-3.0F);
    vector.Set_y(4.0F);
    EXPECT_EQ(vector, PlanarVector(-3.0F, 4.0F));
  }
  {
    PlanarVector vector{1.0, -2.0};
    vector.Set_x(-3.0);
    vector.Set_y(4.0);
    EXPECT_EQ(vector, PlanarVector(-3.0, 4.0));
  }
  {
    PlanarVector vector{1.0L, -2.0L};
    vector.Set_x(-3.0L);
    vector.Set_y(4.0L);
    EXPECT_EQ(vector, PlanarVector(-3.0L, 4.0L));
  }
}

TEST(PlanarVector, SizeOf) {
  EXPECT_EQ(sizeof(PlanarVector<>{}), 2 * sizeof(double));
  EXPECT_EQ(sizeof(PlanarVector<float>{}), 2 * sizeof(float));
  EXPECT_EQ(sizeof(PlanarVector<double>{}), 2 * sizeof(double));
  EXPECT_EQ(sizeof(PlanarVector<long double>{}), 2 * sizeof(long double));
}

TEST(PlanarVector, Stream) {
  {
    std::ostringstream stream;
    stream << PlanarVector{1.0F, -2.0F};
    EXPECT_EQ(stream.str(), PlanarVector(1.0F, -2.0F).Print());
  }
  {
    std::ostringstream stream;
    stream << PlanarVector{1.0, -2.0};
    EXPECT_EQ(stream.str(), PlanarVector(1.0, -2.0).Print());
  }
  {
    std::ostringstream stream;
    stream << PlanarVector{1.0L, -2.0L};
    EXPECT_EQ(stream.str(), PlanarVector(1.0L, -2.0L).Print());
  }
}

TEST(PlanarVector, XML) {
  EXPECT_EQ(
      PlanarVector(1.0F, -2.0F).XML(), "<x>" + Print(1.0F) + "</x><y>" + Print(-2.0F) + "</y>");
  EXPECT_EQ(PlanarVector(1.0, -2.0).XML(), "<x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y>");
  EXPECT_EQ(
      PlanarVector(1.0L, -2.0L).XML(), "<x>" + Print(1.0L) + "</x><y>" + Print(-2.0L) + "</y>");
}

TEST(PlanarVector, YAML) {
  EXPECT_EQ(PlanarVector(1.0F, -2.0F).YAML(), "{x:" + Print(1.0F) + ",y:" + Print(-2.0F) + "}");
  EXPECT_EQ(PlanarVector(1.0, -2.0).YAML(), "{x:" + Print(1.0) + ",y:" + Print(-2.0) + "}");
  EXPECT_EQ(PlanarVector(1.0L, -2.0L).YAML(), "{x:" + Print(1.0L) + ",y:" + Print(-2.0L) + "}");
}

TEST(PlanarVector, Zero) {
  EXPECT_EQ(PlanarVector<>::Zero(), PlanarVector(0.0, 0.0));
  EXPECT_EQ(PlanarVector<float>::Zero(), PlanarVector(0.0F, 0.0F));
  EXPECT_EQ(PlanarVector<double>::Zero(), PlanarVector(0.0, 0.0));
  EXPECT_EQ(PlanarVector<long double>::Zero(), PlanarVector(0.0L, 0.0L));
}

}  // namespace

}  // namespace PhQ
