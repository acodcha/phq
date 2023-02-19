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

#include "../../include/PhQ/Dimension/SubstanceAmount.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionSubstanceAmount, Abbreviation) {
  EXPECT_EQ(SubstanceAmount::Abbreviation(), "N");
}

TEST(DimensionSubstanceAmount, Accessor) {
  EXPECT_EQ(SubstanceAmount{}.Value(), 0);
  EXPECT_EQ(SubstanceAmount{-2}.Value(), -2);
  EXPECT_EQ(SubstanceAmount{-1}.Value(), -1);
  EXPECT_EQ(SubstanceAmount{0}.Value(), 0);
  EXPECT_EQ(SubstanceAmount{1}.Value(), 1);
  EXPECT_EQ(SubstanceAmount{2}.Value(), 2);
  EXPECT_EQ(SubstanceAmount{3}.Value(), 3);
}

TEST(DimensionSubstanceAmount, Comparison) {
  const SubstanceAmount amount0{-1};
  const SubstanceAmount amount1{2};
  EXPECT_EQ(amount0, amount0);
  EXPECT_NE(amount0, amount1);
  EXPECT_LT(amount0, amount1);
  EXPECT_LE(amount0, amount0);
  EXPECT_LE(amount0, amount1);
  EXPECT_GT(amount1, amount0);
  EXPECT_GE(amount1, amount0);
  EXPECT_GE(amount0, amount0);
  const std::set<SubstanceAmount> increasing{amount0, amount1};
  EXPECT_EQ(*increasing.begin(), amount0);
  const std::set<SubstanceAmount, std::greater<SubstanceAmount>> decreasing{
      amount0, amount1};
  EXPECT_EQ(*decreasing.begin(), amount1);
}

TEST(DimensionSubstanceAmount, Hash) {
  const SubstanceAmount amount0{-2};
  const SubstanceAmount amount1{-1};
  const SubstanceAmount amount2{0};
  const SubstanceAmount amount3{1};
  const SubstanceAmount amount4{2};
  const SubstanceAmount amount5{3};
  const std::hash<SubstanceAmount> hasher;
  EXPECT_NE(hasher(amount0), hasher(amount1));
  EXPECT_NE(hasher(amount0), hasher(amount2));
  EXPECT_NE(hasher(amount0), hasher(amount3));
  EXPECT_NE(hasher(amount0), hasher(amount4));
  EXPECT_NE(hasher(amount0), hasher(amount5));
  const std::unordered_set<SubstanceAmount> unordered{
      amount0, amount1, amount2, amount3, amount4, amount5};
}

TEST(DimensionSubstanceAmount, Label) {
  EXPECT_EQ(SubstanceAmount::Label(), "Substance Amount");
}

TEST(DimensionSubstanceAmount, Print) {
  EXPECT_EQ(SubstanceAmount{}.Print(), "");
  EXPECT_EQ(SubstanceAmount{-2}.Print(), "N^(-2)");
  EXPECT_EQ(SubstanceAmount{-1}.Print(), "N^(-1)");
  EXPECT_EQ(SubstanceAmount{0}.Print(), "");
  EXPECT_EQ(SubstanceAmount{1}.Print(), "N");
  EXPECT_EQ(SubstanceAmount{2}.Print(), "N^2");
  EXPECT_EQ(SubstanceAmount{3}.Print(), "N^3");
}

TEST(DimensionSubstanceAmount, Stream) {
  const SubstanceAmount amount{3};
  std::ostringstream stream;
  stream << amount;
  EXPECT_EQ(stream.str(), amount.Print());
}

}  // namespace

}  // namespace PhQ::Dimension
