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

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionLength, Abbreviation) {
  EXPECT_EQ(Length::Abbreviation(), "L");
}

TEST(DimensionLength, Accessor) {
  EXPECT_EQ(Length{}.Value(), 0);
  EXPECT_EQ(Length{-2}.Value(), -2);
  EXPECT_EQ(Length{-1}.Value(), -1);
  EXPECT_EQ(Length{0}.Value(), 0);
  EXPECT_EQ(Length{1}.Value(), 1);
  EXPECT_EQ(Length{2}.Value(), 2);
  EXPECT_EQ(Length{3}.Value(), 3);
}

TEST(DimensionLength, Comparison) {
  const Length length0{-1};
  const Length length1{2};
  EXPECT_EQ(length0, length0);
  EXPECT_NE(length0, length1);
  EXPECT_LT(length0, length1);
  EXPECT_LE(length0, length0);
  EXPECT_LE(length0, length1);
  EXPECT_GT(length1, length0);
  EXPECT_GE(length1, length0);
  EXPECT_GE(length0, length0);
  const std::set<Length> increasing{length0, length1};
  EXPECT_EQ(*increasing.begin(), length0);
  const std::set<Length, std::greater<Length>> decreasing{length0, length1};
  EXPECT_EQ(*decreasing.begin(), length1);
}

TEST(DimensionLength, Constructor) {
  constexpr int8_t value_reference{1};
  constexpr Length reference{1};

  // Default constructor.
  constexpr Length default_;

  // Copy constructor.
  constexpr Length copy_constructed{reference};
  EXPECT_EQ(copy_constructed, reference);

  // Copy assignment operator.
  Length copy_assigned{-1};
  copy_assigned = reference;
  EXPECT_EQ(copy_assigned, reference);

  // Move constructor.
  Length to_move_construct{value_reference};
  Length move_constructed{std::move(to_move_construct)};
  EXPECT_EQ(move_constructed, reference);

  // Move assignment operator.
  Length to_move_assign{value_reference};
  Length move_assigned{-1};
  move_assigned = std::move(to_move_assign);
  EXPECT_EQ(move_assigned, reference);
}

TEST(DimensionLength, Hash) {
  const Length length0{-2};
  const Length length1{-1};
  const Length length2{0};
  const Length length3{1};
  const Length length4{2};
  const Length length5{3};
  const std::hash<Length> hasher;
  EXPECT_NE(hasher(length0), hasher(length1));
  EXPECT_NE(hasher(length0), hasher(length2));
  EXPECT_NE(hasher(length0), hasher(length3));
  EXPECT_NE(hasher(length0), hasher(length4));
  EXPECT_NE(hasher(length0), hasher(length5));
  const std::unordered_set<Length> unordered{
      length0, length1, length2, length3, length4, length5};
}

TEST(DimensionLength, Label) {
  EXPECT_EQ(Length::Label(), "Length");
}

TEST(DimensionLength, Print) {
  EXPECT_EQ(Length{}.Print(), "");
  EXPECT_EQ(Length{-2}.Print(), "L^(-2)");
  EXPECT_EQ(Length{-1}.Print(), "L^(-1)");
  EXPECT_EQ(Length{0}.Print(), "");
  EXPECT_EQ(Length{1}.Print(), "L");
  EXPECT_EQ(Length{2}.Print(), "L^2");
  EXPECT_EQ(Length{3}.Print(), "L^3");
}

TEST(DimensionLength, SizeOf) {
  const Length length{3};
  EXPECT_EQ(sizeof(length), sizeof(int8_t));
}

TEST(DimensionLength, Stream) {
  const Length length{3};
  std::ostringstream stream;
  stream << length;
  EXPECT_EQ(stream.str(), length.Print());
}

}  // namespace

}  // namespace PhQ::Dimension
