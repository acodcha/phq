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

#include "../../include/PhQ/Dimension/Time.hpp"

#include <cstdint>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

namespace PhQ::Dimension {

namespace {

TEST(DimensionTime, Abbreviation) {
  EXPECT_EQ(Time::Abbreviation(), "T");
}

TEST(DimensionTime, ComparisonOperators) {
  constexpr Time first{-1};
  constexpr Time second{2};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GT(second, first);
  EXPECT_GE(second, first);
  EXPECT_GE(first, first);
}

TEST(DimensionTime, CopyAssignmentOperator) {
  constexpr Time first{3};
  Time second{0};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DimensionTime, CopyConstructor) {
  constexpr Time first{3};
  constexpr Time second{first};
  EXPECT_EQ(second, first);
}

TEST(DimensionTime, DefaultConstructor) {
  EXPECT_NO_THROW(Time{});
}

TEST(DimensionTime, Hash) {
  constexpr Time first{0};
  constexpr Time second{2};
  constexpr Time third{-1};
  constexpr std::hash<Time> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionTime, Label) {
  EXPECT_EQ(Time::Label(), "Time");
}

TEST(DimensionTime, MoveAssignmentOperator) {
  Time first{3};
  Time second{-1};
  second = std::move(first);
  EXPECT_EQ(second, Time(3));
}

TEST(DimensionTime, MoveConstructor) {
  Time first{3};
  const Time second{std::move(first)};
  EXPECT_EQ(second, Time(3));
}

TEST(DimensionTime, Print) {
  EXPECT_EQ(Time().Print(), "");
  EXPECT_EQ(Time(-1).Print(), "T^(-1)");
  EXPECT_EQ(Time(0).Print(), "");
  EXPECT_EQ(Time(1).Print(), "T");
  EXPECT_EQ(Time(2).Print(), "T^2");
}

TEST(DimensionTime, SizeOf) {
  EXPECT_EQ(sizeof(Time{}), sizeof(int8_t));
}

TEST(DimensionTime, Stream) {
  constexpr Time dimension{3};
  std::ostringstream stream;
  stream << dimension;
  EXPECT_EQ(stream.str(), dimension.Print());
}

TEST(DimensionTime, Value) {
  EXPECT_EQ(Time().Value(), 0);
  EXPECT_EQ(Time(-1).Value(), -1);
  EXPECT_EQ(Time(0).Value(), 0);
  EXPECT_EQ(Time(1).Value(), 1);
  EXPECT_EQ(Time(2).Value(), 2);
}

}  // namespace

}  // namespace PhQ::Dimension
