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

#include "../../include/PhQ/Dimension/ElectricCurrent.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionElectricCurrent, Abbreviation) {
  EXPECT_EQ(ElectricCurrent::Abbreviation(), "I");
}

TEST(DimensionElectricCurrent, Accessor) {
  EXPECT_EQ(ElectricCurrent{}.Value(), 0);
  EXPECT_EQ(ElectricCurrent{-2}.Value(), -2);
  EXPECT_EQ(ElectricCurrent{-1}.Value(), -1);
  EXPECT_EQ(ElectricCurrent{0}.Value(), 0);
  EXPECT_EQ(ElectricCurrent{1}.Value(), 1);
  EXPECT_EQ(ElectricCurrent{2}.Value(), 2);
  EXPECT_EQ(ElectricCurrent{3}.Value(), 3);
}

TEST(DimensionElectricCurrent, Comparison) {
  const ElectricCurrent current0{-1};
  const ElectricCurrent current1{2};
  EXPECT_EQ(current0, current0);
  EXPECT_NE(current0, current1);
  EXPECT_LT(current0, current1);
  EXPECT_LE(current0, current0);
  EXPECT_LE(current0, current1);
  EXPECT_GT(current1, current0);
  EXPECT_GE(current1, current0);
  EXPECT_GE(current0, current0);
  const std::set<ElectricCurrent> increasing{current0, current1};
  EXPECT_EQ(*increasing.begin(), current0);
  const std::set<ElectricCurrent, std::greater<ElectricCurrent>> decreasing{
      current0, current1};
  EXPECT_EQ(*decreasing.begin(), current1);
}

TEST(DimensionElectricCurrent, Hash) {
  const ElectricCurrent current0{-2};
  const ElectricCurrent current1{-1};
  const ElectricCurrent current2{0};
  const ElectricCurrent current3{1};
  const ElectricCurrent current4{2};
  const ElectricCurrent current5{3};
  const std::hash<ElectricCurrent> hasher;
  EXPECT_NE(hasher(current0), hasher(current1));
  EXPECT_NE(hasher(current0), hasher(current2));
  EXPECT_NE(hasher(current0), hasher(current3));
  EXPECT_NE(hasher(current0), hasher(current4));
  EXPECT_NE(hasher(current0), hasher(current5));
  const std::unordered_set<ElectricCurrent> unordered{
      current0, current1, current2, current3, current4, current5};
}

TEST(DimensionElectricCurrent, Label) {
  EXPECT_EQ(ElectricCurrent::Label(), "Electric Current");
}

TEST(DimensionElectricCurrent, Print) {
  EXPECT_EQ(ElectricCurrent{}.Print(), "");
  EXPECT_EQ(ElectricCurrent{-2}.Print(), "I^(-2)");
  EXPECT_EQ(ElectricCurrent{-1}.Print(), "I^(-1)");
  EXPECT_EQ(ElectricCurrent{0}.Print(), "");
  EXPECT_EQ(ElectricCurrent{1}.Print(), "I");
  EXPECT_EQ(ElectricCurrent{2}.Print(), "I^2");
  EXPECT_EQ(ElectricCurrent{3}.Print(), "I^3");
}

TEST(DimensionElectricCurrent, Stream) {
  const ElectricCurrent current{3};
  std::ostringstream stream;
  stream << current;
  EXPECT_EQ(stream.str(), current.Print());
}

}  // namespace

}  // namespace PhQ::Dimension
