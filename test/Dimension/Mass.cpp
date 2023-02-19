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

#include "../../include/PhQ/Dimension/Mass.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionMass, Abbreviation) { EXPECT_EQ(Mass::abbreviation(), "M"); }

TEST(DimensionMass, Accessor) {
  EXPECT_EQ(Mass{}.value(), 0);
  EXPECT_EQ(Mass{-2}.value(), -2);
  EXPECT_EQ(Mass{-1}.value(), -1);
  EXPECT_EQ(Mass{0}.value(), 0);
  EXPECT_EQ(Mass{1}.value(), 1);
  EXPECT_EQ(Mass{2}.value(), 2);
  EXPECT_EQ(Mass{3}.value(), 3);
}

TEST(DimensionMass, Comparison) {
  const Mass mass0{-1};
  const Mass mass1{2};
  EXPECT_EQ(mass0, mass0);
  EXPECT_NE(mass0, mass1);
  EXPECT_LT(mass0, mass1);
  EXPECT_LE(mass0, mass0);
  EXPECT_LE(mass0, mass1);
  EXPECT_GT(mass1, mass0);
  EXPECT_GE(mass1, mass0);
  EXPECT_GE(mass0, mass0);
  const std::set<Mass> increasing{mass0, mass1};
  EXPECT_EQ(*increasing.begin(), mass0);
  const std::set<Mass, std::greater<Mass>> decreasing{mass0, mass1};
  EXPECT_EQ(*decreasing.begin(), mass1);
}

TEST(DimensionMass, Hash) {
  const Mass mass0{-2};
  const Mass mass1{-1};
  const Mass mass2{0};
  const Mass mass3{1};
  const Mass mass4{2};
  const Mass mass5{3};
  const std::hash<Mass> hasher;
  EXPECT_NE(hasher(mass0), hasher(mass1));
  EXPECT_NE(hasher(mass0), hasher(mass2));
  EXPECT_NE(hasher(mass0), hasher(mass3));
  EXPECT_NE(hasher(mass0), hasher(mass4));
  EXPECT_NE(hasher(mass0), hasher(mass5));
  const std::unordered_set<Mass> unordered{mass0, mass1, mass2,
                                           mass3, mass4, mass5};
}

TEST(DimensionMass, Label) { EXPECT_EQ(Mass::label(), "Mass"); }

TEST(DimensionMass, Print) {
  EXPECT_EQ(Mass{}.print(), "");
  EXPECT_EQ(Mass{-2}.print(), "M^(-2)");
  EXPECT_EQ(Mass{-1}.print(), "M^(-1)");
  EXPECT_EQ(Mass{0}.print(), "");
  EXPECT_EQ(Mass{1}.print(), "M");
  EXPECT_EQ(Mass{2}.print(), "M^2");
  EXPECT_EQ(Mass{3}.print(), "M^3");
}

TEST(DimensionMass, Stream) {
  const Mass mass{3};
  std::ostringstream stream;
  stream << mass;
  EXPECT_EQ(stream.str(), mass.print());
}

}  // namespace

}  // namespace PhQ::Dimension
