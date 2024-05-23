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

#include "../../include/PhQ/Dimension/LuminousIntensity.hpp"

#include <cstdint>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

namespace PhQ::Dimension {

namespace {

TEST(DimensionLuminousIntensity, Abbreviation) {
  EXPECT_EQ(LuminousIntensity::Abbreviation(), "J");
}

TEST(DimensionLuminousIntensity, ComparisonOperators) {
  constexpr LuminousIntensity first{-1};
  constexpr LuminousIntensity second{2};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GT(second, first);
  EXPECT_GE(second, first);
  EXPECT_GE(first, first);
}

TEST(DimensionLuminousIntensity, CopyAssignmentOperator) {
  constexpr LuminousIntensity first{3};
  LuminousIntensity second{0};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DimensionLuminousIntensity, CopyConstructor) {
  constexpr LuminousIntensity first{3};
  constexpr LuminousIntensity second{first};
  EXPECT_EQ(second, first);
}

TEST(DimensionLuminousIntensity, DefaultConstructor) {
  EXPECT_NO_THROW(LuminousIntensity{});
}

TEST(DimensionLuminousIntensity, Hash) {
  constexpr LuminousIntensity first{0};
  constexpr LuminousIntensity second{2};
  constexpr LuminousIntensity third{-1};
  constexpr std::hash<LuminousIntensity> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionLuminousIntensity, Label) {
  EXPECT_EQ(LuminousIntensity::Label(), "Luminous Intensity");
}

TEST(DimensionLuminousIntensity, MoveAssignmentOperator) {
  LuminousIntensity first{3};
  LuminousIntensity second{-1};
  second = std::move(first);
  EXPECT_EQ(second, LuminousIntensity(3));
}

TEST(DimensionLuminousIntensity, MoveConstructor) {
  LuminousIntensity first{3};
  const LuminousIntensity second{std::move(first)};
  EXPECT_EQ(second, LuminousIntensity(3));
}

TEST(DimensionLuminousIntensity, Print) {
  EXPECT_EQ(LuminousIntensity().Print(), "");
  EXPECT_EQ(LuminousIntensity(-1).Print(), "J^(-1)");
  EXPECT_EQ(LuminousIntensity(0).Print(), "");
  EXPECT_EQ(LuminousIntensity(1).Print(), "J");
  EXPECT_EQ(LuminousIntensity(2).Print(), "J^2");
}

TEST(DimensionLuminousIntensity, SizeOf) {
  EXPECT_EQ(sizeof(LuminousIntensity{}), sizeof(int8_t));
}

TEST(DimensionLuminousIntensity, Stream) {
  constexpr LuminousIntensity dimension{3};
  std::ostringstream stream;
  stream << dimension;
  EXPECT_EQ(stream.str(), dimension.Print());
}

TEST(DimensionLuminousIntensity, Value) {
  EXPECT_EQ(LuminousIntensity().Value(), 0);
  EXPECT_EQ(LuminousIntensity(-1).Value(), -1);
  EXPECT_EQ(LuminousIntensity(0).Value(), 0);
  EXPECT_EQ(LuminousIntensity(1).Value(), 1);
  EXPECT_EQ(LuminousIntensity(2).Value(), 2);
}

}  // namespace

}  // namespace PhQ::Dimension
