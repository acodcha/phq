// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/Dimension/SubstanceAmount.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace {

TEST(DimensionSubstanceAmount, abbreviation) {
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount::abbreviation(), "N");
}

TEST(DimensionSubstanceAmount, hash) {
  const PhQ::Dimension::SubstanceAmount object0{-2};
  const PhQ::Dimension::SubstanceAmount object1{-1};
  const PhQ::Dimension::SubstanceAmount object2{0};
  const PhQ::Dimension::SubstanceAmount object3{1};
  const PhQ::Dimension::SubstanceAmount object4{2};
  const PhQ::Dimension::SubstanceAmount object5{3};
  const std::hash<PhQ::Dimension::SubstanceAmount> hasher;
  EXPECT_NE(hasher(object0), hasher(object1));
  EXPECT_NE(hasher(object0), hasher(object2));
  EXPECT_NE(hasher(object0), hasher(object3));
  EXPECT_NE(hasher(object0), hasher(object4));
  EXPECT_NE(hasher(object0), hasher(object5));
  const std::unordered_set<PhQ::Dimension::SubstanceAmount> unordered_set{object0, object1, object2, object3, object4, object5};
}

TEST(DimensionSubstanceAmount, label) {
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount::label(), "Substance Amount");
}

TEST(DimensionSubstanceAmount, operators) {
  const PhQ::Dimension::SubstanceAmount object0{-1};
  const PhQ::Dimension::SubstanceAmount object1{2};
  EXPECT_EQ(object0, object0);
  EXPECT_NE(object0, object1);
  EXPECT_LT(object0, object1);
  EXPECT_LE(object0, object0);
  EXPECT_LE(object0, object1);
  EXPECT_GT(object1, object0);
  EXPECT_GE(object1, object0);
  EXPECT_GE(object0, object0);
  const std::set<PhQ::Dimension::SubstanceAmount> increasing{object0, object1};
  EXPECT_EQ(*increasing.begin(), object0);
  const std::set<PhQ::Dimension::SubstanceAmount, std::greater<PhQ::Dimension::SubstanceAmount>> decreasing{object0, object1};
  EXPECT_EQ(*decreasing.begin(), object1);
}

TEST(DimensionSubstanceAmount, print) {
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{}.print(), "");
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{-2}.print(), "N^(-2)");
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{-1}.print(), "N^(-1)");
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{0}.print(), "");
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{1}.print(), "N");
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{2}.print(), "N^2");
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{3}.print(), "N^3");
}

TEST(DimensionSubstanceAmount, stream) {
  const PhQ::Dimension::SubstanceAmount object{3};
  std::ostringstream output_string_stream;
  output_string_stream << object;
  EXPECT_EQ(output_string_stream.str(), object.print());
}

TEST(DimensionSubstanceAmount, value) {
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{}.value(), 0);
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{-2}.value(), -2);
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{-1}.value(), -1);
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{0}.value(), 0);
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{1}.value(), 1);
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{2}.value(), 2);
  EXPECT_EQ(PhQ::Dimension::SubstanceAmount{3}.value(), 3);
}

}  // namespace
