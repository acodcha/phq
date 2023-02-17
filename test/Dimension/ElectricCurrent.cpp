// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/Dimension/ElectricCurrent.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionElectricCurrent, Abbreviation) {
  EXPECT_EQ(ElectricCurrent::abbreviation(), "I");
}

TEST(DimensionElectricCurrent, Hash) {
  const ElectricCurrent object0{-2};
  const ElectricCurrent object1{-1};
  const ElectricCurrent object2{0};
  const ElectricCurrent object3{1};
  const ElectricCurrent object4{2};
  const ElectricCurrent object5{3};
  const std::hash<ElectricCurrent> hasher;
  EXPECT_NE(hasher(object0), hasher(object1));
  EXPECT_NE(hasher(object0), hasher(object2));
  EXPECT_NE(hasher(object0), hasher(object3));
  EXPECT_NE(hasher(object0), hasher(object4));
  EXPECT_NE(hasher(object0), hasher(object5));
  const std::unordered_set<ElectricCurrent> unordered{object0, object1, object2, object3, object4, object5};
}

TEST(DimensionElectricCurrent, Label) {
  EXPECT_EQ(ElectricCurrent::label(), "Electric Current");
}

TEST(DimensionElectricCurrent, Operators) {
  const ElectricCurrent object0{-1};
  const ElectricCurrent object1{2};
  EXPECT_EQ(object0, object0);
  EXPECT_NE(object0, object1);
  EXPECT_LT(object0, object1);
  EXPECT_LE(object0, object0);
  EXPECT_LE(object0, object1);
  EXPECT_GT(object1, object0);
  EXPECT_GE(object1, object0);
  EXPECT_GE(object0, object0);
  const std::set<ElectricCurrent> increasing{object0, object1};
  EXPECT_EQ(*increasing.begin(), object0);
  const std::set<ElectricCurrent, std::greater<ElectricCurrent>> decreasing{object0, object1};
  EXPECT_EQ(*decreasing.begin(), object1);
}

TEST(DimensionElectricCurrent, Print) {
  EXPECT_EQ(ElectricCurrent{}.print(), "");
  EXPECT_EQ(ElectricCurrent{-2}.print(), "I^(-2)");
  EXPECT_EQ(ElectricCurrent{-1}.print(), "I^(-1)");
  EXPECT_EQ(ElectricCurrent{0}.print(), "");
  EXPECT_EQ(ElectricCurrent{1}.print(), "I");
  EXPECT_EQ(ElectricCurrent{2}.print(), "I^2");
  EXPECT_EQ(ElectricCurrent{3}.print(), "I^3");
}

TEST(DimensionElectricCurrent, Stream) {
  const ElectricCurrent object{3};
  std::ostringstream output_string_stream;
  output_string_stream << object;
  EXPECT_EQ(output_string_stream.str(), object.print());
}

TEST(DimensionElectricCurrent, Value) {
  EXPECT_EQ(ElectricCurrent{}.value(), 0);
  EXPECT_EQ(ElectricCurrent{-2}.value(), -2);
  EXPECT_EQ(ElectricCurrent{-1}.value(), -1);
  EXPECT_EQ(ElectricCurrent{0}.value(), 0);
  EXPECT_EQ(ElectricCurrent{1}.value(), 1);
  EXPECT_EQ(ElectricCurrent{2}.value(), 2);
  EXPECT_EQ(ElectricCurrent{3}.value(), 3);
}

}  // namespace

}  // namespace PhQ::Dimension
