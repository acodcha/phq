// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

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
