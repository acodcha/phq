// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/Dimension/Length.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionLength, Abbreviation) {
  EXPECT_EQ(Length::abbreviation(), "L");
}

TEST(DimensionLength, Hash) {
  const Length object0{-2};
  const Length object1{-1};
  const Length object2{0};
  const Length object3{1};
  const Length object4{2};
  const Length object5{3};
  const std::hash<Length> hasher;
  EXPECT_NE(hasher(object0), hasher(object1));
  EXPECT_NE(hasher(object0), hasher(object2));
  EXPECT_NE(hasher(object0), hasher(object3));
  EXPECT_NE(hasher(object0), hasher(object4));
  EXPECT_NE(hasher(object0), hasher(object5));
  const std::unordered_set<Length> unordered{object0, object1, object2, object3, object4, object5};
}

TEST(DimensionLength, Label) {
  EXPECT_EQ(Length::label(), "Length");
}

TEST(DimensionLength, Operators) {
  const Length object0{-1};
  const Length object1{2};
  EXPECT_EQ(object0, object0);
  EXPECT_NE(object0, object1);
  EXPECT_LT(object0, object1);
  EXPECT_LE(object0, object0);
  EXPECT_LE(object0, object1);
  EXPECT_GT(object1, object0);
  EXPECT_GE(object1, object0);
  EXPECT_GE(object0, object0);
  const std::set<Length> increasing{object0, object1};
  EXPECT_EQ(*increasing.begin(), object0);
  const std::set<Length, std::greater<Length>> decreasing{object0, object1};
  EXPECT_EQ(*decreasing.begin(), object1);
}

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
  const Length object{3};
  std::ostringstream output_string_stream;
  output_string_stream << object;
  EXPECT_EQ(output_string_stream.str(), object.print());
}

TEST(DimensionLength, Value) {
  EXPECT_EQ(Length{}.value(), 0);
  EXPECT_EQ(Length{-2}.value(), -2);
  EXPECT_EQ(Length{-1}.value(), -1);
  EXPECT_EQ(Length{0}.value(), 0);
  EXPECT_EQ(Length{1}.value(), 1);
  EXPECT_EQ(Length{2}.value(), 2);
  EXPECT_EQ(Length{3}.value(), 3);
}

}  // namespace

}  // namespace PhQ::Dimension
