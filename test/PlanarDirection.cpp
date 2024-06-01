// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#include "../include/PhQ/PlanarDirection.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Dimensions.hpp"
#include "../include/PhQ/Dyad.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/SymmetricDyad.hpp"
#include "../include/PhQ/Unit/Angle.hpp"

namespace PhQ {

namespace {

TEST(PlanarDirection, Angle) {
  EXPECT_EQ(PlanarDirection(0.0, -2.0).Angle(PlanarDirection(3.0, 0.0)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      PlanarDirection(0.0, -2.0).Angle(PlanarVector(3.0, 0.0)), Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      PlanarVector(0.0, -2.0).Angle(PlanarDirection(3.0, 0.0)), Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarDirection, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SymmetricDyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0) * PlanarDirection(0.0, -1.0),
            Vector(-2.0, -8.0, -16.0));
}

TEST(PlanarDirection, AssignmentOperatorMultiplication) {
  EXPECT_EQ(Dyad(1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0) * PlanarDirection(0.0, -1.0),
            Vector(-2.0, -16.0, -128.0));
}

TEST(PlanarDirection, ComparisonOperators) {
  const PlanarDirection first{0.0, 1.0};
  const PlanarDirection second{1.0, 1.0};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarDirection, Constructor) {
  EXPECT_NO_THROW(PlanarDirection(1.0, -2.0));
  EXPECT_NO_THROW(PlanarDirection(std::array<double, 2>{1.0, -2.0}));
  EXPECT_NO_THROW(PlanarDirection(PlanarVector{1.0, -2.0}));
  EXPECT_EQ(PlanarVector(5.0, PlanarDirection(3.0, -4.0)), PlanarVector(3.0, -4.0));
  EXPECT_EQ(Angle(PlanarDirection(0.0, -2.0), PlanarDirection(3.0, 0.0)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      Angle(PlanarDirection(0.0, -2.0), PlanarVector(3.0, 0.0)), Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(
      Angle(PlanarVector(0.0, -2.0), PlanarDirection(3.0, 0.0)), Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarDirection, CopyAssignmentOperator) {
  {
    const PlanarDirection<float> first{3.0F, -4.0F};
    PlanarDirection<double> second = PlanarDirection<double>::Zero();
    second = first;
    EXPECT_NEAR(second.x(), 3.0 / 5.0, 1.0E-7);
    EXPECT_NEAR(second.y(), -4.0 / 5.0, 1.0E-7);
  }
  {
    const PlanarDirection<double> first{3.0, -4.0};
    PlanarDirection<double> second = PlanarDirection<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarDirection<double>(3.0, -4.0));
  }
  {
    const PlanarDirection<long double> first{3.0L, -4.0L};
    PlanarDirection<double> second = PlanarDirection<double>::Zero();
    second = first;
    EXPECT_NEAR(second.x(), 3.0 / 5.0, 1.0E-15);
    EXPECT_NEAR(second.y(), -4.0 / 5.0, 1.0E-15);
  }
}

TEST(PlanarDirection, CopyConstructor) {
  {
    const PlanarDirection<float> first{3.0F, -4.0F};
    const PlanarDirection<double> second{first};
    EXPECT_NEAR(second.x(), 3.0 / 5.0, 1.0E-7);
    EXPECT_NEAR(second.y(), -4.0 / 5.0, 1.0E-7);
  }
  {
    const PlanarDirection<double> first{3.0, -4.0};
    const PlanarDirection<double> second{first};
    EXPECT_EQ(second, PlanarDirection<double>(3.0, -4.0));
  }
  {
    const PlanarDirection<long double> first{3.0L, -4.0L};
    const PlanarDirection<double> second{first};
    EXPECT_NEAR(second.x(), 3.0 / 5.0, 1.0E-15);
    EXPECT_NEAR(second.y(), -4.0 / 5.0, 1.0E-15);
  }
}

TEST(PlanarDirection, Cross) {
  EXPECT_EQ(PlanarVector(2.0, 0.0).Cross(PlanarDirection(0.0, 1.0)), Vector(0.0, 0.0, 2.0));
  EXPECT_EQ(PlanarDirection(1.0, 0.0).Cross(PlanarVector(0.0, 2.0)), Vector(0.0, 0.0, 2.0));
}

TEST(PlanarDirection, DefaultConstructor) {
  EXPECT_EQ(PlanarDirection<>{}, PlanarDirection<>::Zero());
}

TEST(PlanarDirection, Dimensions) {
  EXPECT_EQ(PlanarDirection<>::Dimensions(), Dimensionless);
}

TEST(PlanarDirection, Dot) {
  EXPECT_EQ(PlanarDirection(0.0, -1.0).Dot(PlanarDirection(0.0, -1.0)), 1.0);
  EXPECT_EQ(PlanarDirection(0.0, -1.0).Dot(PlanarDirection(0.0, 1.0)), -1.0);
  EXPECT_EQ(PlanarDirection(0.0, 1.0).Dot(PlanarDirection(-1.0, 0.0)), 0.0);
  EXPECT_EQ(PlanarDirection(0.0, -1.0).Dot(PlanarVector(2.0, -3.0)), 3.0);
  EXPECT_EQ(PlanarVector(2.0, -3.0).Dot(PlanarDirection(0.0, 1.0)), -3.0);
}

TEST(PlanarDirection, Dyadic) {
  EXPECT_EQ(PlanarDirection(1.0, 0.0).Dyadic(PlanarDirection(0.0, -1.0)),
            Dyad(0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(PlanarDirection(0.0, -1.0).Dyadic(PlanarVector(1.0, 2.0)),
            Dyad(0.0, 0.0, 0.0, -1.0, -2.0, 0.0, 0.0, 0.0, 0.0));
  EXPECT_EQ(PlanarVector(1.0, 2.0).Dyadic(PlanarDirection(0.0, -1.0)),
            Dyad(0.0, -1.0, 0.0, 0.0, -2.0, 0.0, 0.0, 0.0, 0.0));
}

TEST(PlanarDirection, Hash) {
  const PlanarDirection first{1.0, -2.000001};
  const PlanarDirection second{1.0, -2.0};
  const PlanarDirection third{1.0, 2.0};
  const std::hash<PlanarDirection<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(PlanarDirection, JSON) {
  EXPECT_EQ(
      PlanarDirection(0.0, -2.0).JSON(), "{\"x\":" + Print(0.0) + ",\"y\":" + Print(-1.0) + "}");
}

TEST(PlanarDirection, Magnitude) {
  EXPECT_EQ(PlanarDirection(3.0, -4.0).Magnitude(), 1.0);
  EXPECT_EQ(PlanarDirection(0.0, 0.0).Magnitude(), 0.0);
}

TEST(PlanarDirection, MiscellaneousMethods) {
  EXPECT_EQ(PlanarVector(3.0, -4.0).PlanarDirection(), PlanarDirection(3.0, -4.0));
}

TEST(PlanarDirection, MoveAssignmentOperator) {
  PlanarDirection first{1.0, -2.0};
  PlanarDirection second = PlanarDirection<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PlanarDirection(1.0, -2.0));
}

TEST(PlanarDirection, MoveConstructor) {
  PlanarDirection first{1.0, -2.0};
  const PlanarDirection second{std::move(first)};
  EXPECT_EQ(second, PlanarDirection(1.0, -2.0));
}

TEST(PlanarDirection, Print) {
  EXPECT_EQ(PlanarDirection<>{}.Print(), "(" + Print(0.0) + ", " + Print(0.0) + ")");
  EXPECT_EQ(PlanarDirection(0.0, -2.0).Print(), "(" + Print(0.0) + ", " + Print(-1.0) + ")");
}

TEST(PlanarDirection, Set) {
  {
    PlanarDirection direction{1.0, -2.0};
    direction.Set(0.0, 0.0);
    EXPECT_EQ(direction.Value(), PlanarVector(0.0, 0.0));
  }
  {
    PlanarDirection direction{1.0, -2.0};
    direction.Set(std::array<double, 2>{0.0, 0.0});
    EXPECT_EQ(direction.Value(), PlanarVector(0.0, 0.0));
  }
  {
    PlanarDirection direction{1.0, -2.0};
    direction.Set(PlanarVector{0.0, 0.0});
    EXPECT_EQ(direction.Value(), PlanarVector(0.0, 0.0));
  }
  {
    PlanarDirection direction{1.0, -2.0};
    direction.Set(0.0, -2.0);
    EXPECT_EQ(direction.Value(), PlanarVector(0.0, -1.0));
  }
  {
    PlanarDirection direction{1.0, -2.0};
    direction.Set(std::array<double, 2>{0.0, -2.0});
    EXPECT_EQ(direction.Value(), PlanarVector(0.0, -1.0));
  }
  {
    PlanarDirection direction{1.0, -2.0};
    direction.Set(PlanarVector{0.0, -2.0});
    EXPECT_EQ(direction.Value(), PlanarVector(0.0, -1.0));
  }
}

TEST(PlanarDirection, SizeOf) {
  EXPECT_EQ(sizeof(PlanarDirection<>{}), 2 * sizeof(double));
}

TEST(PlanarDirection, Stream) {
  std::ostringstream stream;
  stream << PlanarDirection(1.0, -2.0);
  EXPECT_EQ(stream.str(), PlanarDirection(1.0, -2.0).Print());
}

TEST(PlanarDirection, Value) {
  EXPECT_EQ(PlanarDirection(0.0, -2.0).Value(), PlanarVector(0.0, -1.0));
}

TEST(PlanarDirection, XML) {
  EXPECT_EQ(
      PlanarDirection(0.0, -2.0).XML(), "<x>" + Print(0.0) + "</x><y>" + Print(-1.0) + "</y>");
}

TEST(PlanarDirection, XY) {
  EXPECT_EQ(PlanarDirection(3.0, -4.0).x(), 3.0 / 5.0);
  EXPECT_EQ(PlanarDirection(3.0, -4.0).y(), -4.0 / 5.0);
}

TEST(PlanarDirection, YAML) {
  EXPECT_EQ(PlanarDirection(0.0, -2.0).YAML(), "{x:" + Print(0.0) + ",y:" + Print(-1.0) + "}");
}

TEST(PlanarDirection, Zero) {
  EXPECT_EQ(PlanarDirection<>::Zero(), PlanarDirection(0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
