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

#include "../../include/PhQ/Dimension/Length.hpp"

#include <cstdint>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

namespace PhQ::Dimension {

namespace {

TEST(DimensionLength, Abbreviation) {
  EXPECT_EQ(Length::Abbreviation(), "L");
}

TEST(DimensionLength, ComparisonOperators) {
  constexpr Length first{-1};
  constexpr Length second{2};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GT(second, first);
  EXPECT_GE(second, first);
  EXPECT_GE(first, first);
}

TEST(DimensionLength, Constructor) {
  EXPECT_NO_THROW(Length(1));
}

TEST(DimensionLength, CopyAssignmentOperator) {
  constexpr Length first{3};
  Length second{0};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DimensionLength, CopyConstructor) {
  constexpr Length first{3};
  constexpr Length second{first};
  EXPECT_EQ(second, first);
}

TEST(DimensionLength, DefaultConstructor) {
  EXPECT_NO_THROW(Length{});
}

TEST(DimensionLength, Hash) {
  constexpr Length first{0};
  constexpr Length second{2};
  constexpr Length third{-1};
  constexpr std::hash<Length> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionLength, Label) {
  EXPECT_EQ(Length::Label(), "Length");
}

TEST(DimensionLength, MoveAssignmentOperator) {
  Length first{3};
  Length second{-1};
  second = std::move(first);
  EXPECT_EQ(second, Length(3));
}

TEST(DimensionLength, MoveConstructor) {
  Length first{3};
  const Length second{std::move(first)};
  EXPECT_EQ(second, Length(3));
}

TEST(DimensionLength, Print) {
  EXPECT_EQ(Length().Print(), "");
  EXPECT_EQ(Length(-1).Print(), "L^(-1)");
  EXPECT_EQ(Length(0).Print(), "");
  EXPECT_EQ(Length(1).Print(), "L");
  EXPECT_EQ(Length(2).Print(), "L^2");
}

TEST(DimensionLength, SizeOf) {
  EXPECT_EQ(sizeof(Length{}), sizeof(int8_t));
}

TEST(DimensionLength, Stream) {
  constexpr Length dimension{3};
  std::ostringstream stream;
  stream << dimension;
  EXPECT_EQ(stream.str(), dimension.Print());
}

TEST(DimensionLength, Value) {
  EXPECT_EQ(Length().Value(), 0);
  EXPECT_EQ(Length(-1).Value(), -1);
  EXPECT_EQ(Length(0).Value(), 0);
  EXPECT_EQ(Length(1).Value(), 1);
  EXPECT_EQ(Length(2).Value(), 2);
}

}  // namespace

}  // namespace PhQ::Dimension
