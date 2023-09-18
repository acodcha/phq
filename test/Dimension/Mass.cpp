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

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionMass, Abbreviation) {
  EXPECT_EQ(Mass::Abbreviation(), "M");
}

TEST(DimensionMass, Accessor) {
  EXPECT_EQ(Mass{}.Value(), 0);
  EXPECT_EQ(Mass{-2}.Value(), -2);
  EXPECT_EQ(Mass{-1}.Value(), -1);
  EXPECT_EQ(Mass{0}.Value(), 0);
  EXPECT_EQ(Mass{1}.Value(), 1);
  EXPECT_EQ(Mass{2}.Value(), 2);
  EXPECT_EQ(Mass{3}.Value(), 3);
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

TEST(DimensionMass, Constructor) {
  constexpr int8_t value_reference{1};
  constexpr Mass reference{1};

  // Default constructor.
  constexpr Mass default_;

  // Copy constructor.
  constexpr Mass copy_constructed{reference};
  EXPECT_EQ(copy_constructed, reference);

  // Copy assignment operator.
  Mass copy_assigned{-1};
  copy_assigned = reference;
  EXPECT_EQ(copy_assigned, reference);

  // Move constructor.
  Mass to_move_construct{value_reference};
  Mass move_constructed{std::move(to_move_construct)};
  EXPECT_EQ(move_constructed, reference);

  // Move assignment operator.
  Mass to_move_assign{value_reference};
  Mass move_assigned{-1};
  move_assigned = std::move(to_move_assign);
  EXPECT_EQ(move_assigned, reference);
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
  const std::unordered_set<Mass> unordered{
      mass0, mass1, mass2, mass3, mass4, mass5};
}

TEST(DimensionMass, Label) {
  EXPECT_EQ(Mass::Label(), "Mass");
}

TEST(DimensionMass, Print) {
  EXPECT_EQ(Mass{}.Print(), "");
  EXPECT_EQ(Mass{-2}.Print(), "M^(-2)");
  EXPECT_EQ(Mass{-1}.Print(), "M^(-1)");
  EXPECT_EQ(Mass{0}.Print(), "");
  EXPECT_EQ(Mass{1}.Print(), "M");
  EXPECT_EQ(Mass{2}.Print(), "M^2");
  EXPECT_EQ(Mass{3}.Print(), "M^3");
}

TEST(DimensionMass, SizeOf) {
  const Mass mass{3};
  EXPECT_EQ(sizeof(mass), sizeof(int8_t));
}

TEST(DimensionMass, Stream) {
  const Mass mass{3};
  std::ostringstream stream;
  stream << mass;
  EXPECT_EQ(stream.str(), mass.Print());
}

}  // namespace

}  // namespace PhQ::Dimension
