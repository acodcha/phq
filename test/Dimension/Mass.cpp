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

#include "../../include/PhQ/Dimension/Mass.hpp"

#include <gtest/gtest.h>

namespace PhQ::Dimension {

namespace {

TEST(DimensionMass, Abbreviation) {
  EXPECT_EQ(Mass::Abbreviation(), "M");
}

TEST(DimensionMass, Comparisons) {
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

TEST(DimensionMass, CopyAssignment) {
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

TEST(DimensionMass, MoveAssignment) {
  constexpr Mass first{3};
  Mass second{3};
  Mass third{-1};
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(DimensionMass, MoveConstructor) {
  constexpr Mass first{3};
  Mass second{3};
  Mass third{std::move(second)};
  EXPECT_EQ(third, first);
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
