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

#include "../../include/PhQ/Dimension/SubstanceAmount.hpp"

#include <cstdint>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

namespace PhQ::Dimension {

namespace {

TEST(DimensionSubstanceAmount, Abbreviation) {
  EXPECT_EQ(SubstanceAmount::Abbreviation(), "N");
}

TEST(DimensionSubstanceAmount, ComparisonOperators) {
  constexpr SubstanceAmount first{-1};
  constexpr SubstanceAmount second{2};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GT(second, first);
  EXPECT_GE(second, first);
  EXPECT_GE(first, first);
}

TEST(DimensionSubstanceAmount, Constructor) {
  EXPECT_NO_THROW(SubstanceAmount(1));
}

TEST(DimensionSubstanceAmount, CopyAssignmentOperator) {
  constexpr SubstanceAmount first{3};
  SubstanceAmount second{0};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DimensionSubstanceAmount, CopyConstructor) {
  constexpr SubstanceAmount first{3};
  constexpr SubstanceAmount second{first};
  EXPECT_EQ(second, first);
}

TEST(DimensionSubstanceAmount, DefaultConstructor) {
  EXPECT_NO_THROW(SubstanceAmount{});
}

TEST(DimensionSubstanceAmount, Hash) {
  constexpr SubstanceAmount first{0};
  constexpr SubstanceAmount second{2};
  constexpr SubstanceAmount third{-1};
  constexpr std::hash<SubstanceAmount> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionSubstanceAmount, Label) {
  EXPECT_EQ(SubstanceAmount::Label(), "Substance Amount");
}

TEST(DimensionSubstanceAmount, MoveAssignmentOperator) {
  SubstanceAmount first{3};
  SubstanceAmount second{-1};
  second = std::move(first);
  EXPECT_EQ(second, SubstanceAmount(3));
}

TEST(DimensionSubstanceAmount, MoveConstructor) {
  SubstanceAmount first{3};
  const SubstanceAmount second{std::move(first)};
  EXPECT_EQ(second, SubstanceAmount(3));
}

TEST(DimensionSubstanceAmount, Print) {
  EXPECT_EQ(SubstanceAmount().Print(), "");
  EXPECT_EQ(SubstanceAmount(-1).Print(), "N^(-1)");
  EXPECT_EQ(SubstanceAmount(0).Print(), "");
  EXPECT_EQ(SubstanceAmount(1).Print(), "N");
  EXPECT_EQ(SubstanceAmount(2).Print(), "N^2");
}

TEST(DimensionSubstanceAmount, SizeOf) {
  EXPECT_EQ(sizeof(SubstanceAmount{}), sizeof(int8_t));
}

TEST(DimensionSubstanceAmount, Stream) {
  constexpr SubstanceAmount dimension{3};
  std::ostringstream stream;
  stream << dimension;
  EXPECT_EQ(stream.str(), dimension.Print());
}

TEST(DimensionSubstanceAmount, Value) {
  EXPECT_EQ(SubstanceAmount().Value(), 0);
  EXPECT_EQ(SubstanceAmount(-1).Value(), -1);
  EXPECT_EQ(SubstanceAmount(0).Value(), 0);
  EXPECT_EQ(SubstanceAmount(1).Value(), 1);
  EXPECT_EQ(SubstanceAmount(2).Value(), 2);
}

}  // namespace

}  // namespace PhQ::Dimension
