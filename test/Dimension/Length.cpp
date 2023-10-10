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

#include "../../include/PhQ/Dimension/Length.hpp"

#include <gtest/gtest.h>

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
  Length second{std::move(first)};
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
