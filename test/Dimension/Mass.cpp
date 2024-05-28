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

#include "../../include/PhQ/Dimension/Mass.hpp"

#include <cstdint>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

namespace PhQ::Dimension {

namespace {

TEST(DimensionMass, Abbreviation) {
  EXPECT_EQ(Mass::Abbreviation(), "M");
}

TEST(DimensionMass, ComparisonOperators) {
  constexpr Mass first{-1};
  constexpr Mass second{2};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GT(second, first);
  EXPECT_GE(second, first);
  EXPECT_GE(first, first);
}

TEST(DimensionMass, Constructor) {
  EXPECT_NO_THROW(Mass(1));
}

TEST(DimensionMass, CopyAssignmentOperator) {
  constexpr Mass first{3};
  Mass second{0};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DimensionMass, CopyConstructor) {
  constexpr Mass first{3};
  constexpr Mass second{first};
  EXPECT_EQ(second, first);
}

TEST(DimensionMass, DefaultConstructor) {
  EXPECT_NO_THROW(Mass{});
}

TEST(DimensionMass, Hash) {
  constexpr Mass first{0};
  constexpr Mass second{2};
  constexpr Mass third{-1};
  constexpr std::hash<Mass> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionMass, Label) {
  EXPECT_EQ(Mass::Label(), "Mass");
}

TEST(DimensionMass, MoveAssignmentOperator) {
  Mass first{3};
  Mass second{-1};
  second = std::move(first);
  EXPECT_EQ(second, Mass(3));
}

TEST(DimensionMass, MoveConstructor) {
  Mass first{3};
  const Mass second{std::move(first)};
  EXPECT_EQ(second, Mass(3));
}

TEST(DimensionMass, Print) {
  EXPECT_EQ(Mass().Print(), "");
  EXPECT_EQ(Mass(-1).Print(), "M^(-1)");
  EXPECT_EQ(Mass(0).Print(), "");
  EXPECT_EQ(Mass(1).Print(), "M");
  EXPECT_EQ(Mass(2).Print(), "M^2");
}

TEST(DimensionMass, SizeOf) {
  EXPECT_EQ(sizeof(Mass{}), sizeof(int8_t));
}

TEST(DimensionMass, Stream) {
  constexpr Mass dimension{3};
  std::ostringstream stream;
  stream << dimension;
  EXPECT_EQ(stream.str(), dimension.Print());
}

TEST(DimensionMass, Value) {
  EXPECT_EQ(Mass().Value(), 0);
  EXPECT_EQ(Mass(-1).Value(), -1);
  EXPECT_EQ(Mass(0).Value(), 0);
  EXPECT_EQ(Mass(1).Value(), 1);
  EXPECT_EQ(Mass(2).Value(), 2);
}

}  // namespace

}  // namespace PhQ::Dimension
