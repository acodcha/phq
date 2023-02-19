// Copyright 2020 Alexandre Coderre-Chabot
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

TEST(DimensionLength, Abbreviation) { EXPECT_EQ(Length::abbreviation(), "L"); }

TEST(DimensionLength, Accessor) {
  EXPECT_EQ(Length{}.value(), 0);
  EXPECT_EQ(Length{-2}.value(), -2);
  EXPECT_EQ(Length{-1}.value(), -1);
  EXPECT_EQ(Length{0}.value(), 0);
  EXPECT_EQ(Length{1}.value(), 1);
  EXPECT_EQ(Length{2}.value(), 2);
  EXPECT_EQ(Length{3}.value(), 3);
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
  const std::unordered_set<Length> unordered{length0, length1, length2,
                                             length3, length4, length5};
}

TEST(DimensionLength, Label) { EXPECT_EQ(Length::label(), "Length"); }

TEST(DimensionLength, Print) {
  EXPECT_EQ(Length{}.print(), "");
  EXPECT_EQ(Length{-2}.print(), "L^(-2)");
  EXPECT_EQ(Length{-1}.print(), "L^(-1)");
  EXPECT_EQ(Length{0}.print(), "");
  EXPECT_EQ(Length{1}.print(), "L");
  EXPECT_EQ(Length{2}.print(), "L^2");
  EXPECT_EQ(Length{3}.print(), "L^3");
}

TEST(DimensionLength, Stream) {
  const Length length{3};
  std::ostringstream stream;
  stream << length;
  EXPECT_EQ(stream.str(), length.print());
}

}  // namespace

}  // namespace PhQ::Dimension
