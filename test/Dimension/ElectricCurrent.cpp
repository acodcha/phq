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

namespace {

TEST(DimensionElectricCurrent, abbreviation) {
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent::abbreviation(), "I");
}

TEST(DimensionElectricCurrent, hash) {
  const PhQ::Dimension::ElectricCurrent object0{-2};
  const PhQ::Dimension::ElectricCurrent object1{-1};
  const PhQ::Dimension::ElectricCurrent object2{0};
  const PhQ::Dimension::ElectricCurrent object3{1};
  const PhQ::Dimension::ElectricCurrent object4{2};
  const PhQ::Dimension::ElectricCurrent object5{3};
  const std::hash<PhQ::Dimension::ElectricCurrent> hasher;
  EXPECT_NE(hasher(object0), hasher(object1));
  EXPECT_NE(hasher(object0), hasher(object2));
  EXPECT_NE(hasher(object0), hasher(object3));
  EXPECT_NE(hasher(object0), hasher(object4));
  EXPECT_NE(hasher(object0), hasher(object5));
  const std::unordered_set<PhQ::Dimension::ElectricCurrent> unordered_set{object0, object1, object2, object3, object4, object5};
}

TEST(DimensionElectricCurrent, label) {
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent::label(), "Electric Current");
}

TEST(DimensionElectricCurrent, operators) {
  const PhQ::Dimension::ElectricCurrent object0{-1};
  const PhQ::Dimension::ElectricCurrent object1{2};
  EXPECT_EQ(object0, object0);
  EXPECT_NE(object0, object1);
  EXPECT_LT(object0, object1);
  EXPECT_LE(object0, object0);
  EXPECT_LE(object0, object1);
  EXPECT_GT(object1, object0);
  EXPECT_GE(object1, object0);
  EXPECT_GE(object0, object0);
  const std::set<PhQ::Dimension::ElectricCurrent> increasing{object0, object1};
  EXPECT_EQ(*increasing.begin(), object0);
  const std::set<PhQ::Dimension::ElectricCurrent, std::greater<PhQ::Dimension::ElectricCurrent>> decreasing{object0, object1};
  EXPECT_EQ(*decreasing.begin(), object1);
}

TEST(DimensionElectricCurrent, print) {
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{}.print(), "");
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{-2}.print(), "I^(-2)");
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{-1}.print(), "I^(-1)");
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{0}.print(), "");
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{1}.print(), "I");
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{2}.print(), "I^2");
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{3}.print(), "I^3");
}

TEST(DimensionElectricCurrent, stream) {
  const PhQ::Dimension::ElectricCurrent object{3};
  std::ostringstream output_string_stream;
  output_string_stream << object;
  EXPECT_EQ(output_string_stream.str(), object.print());
}

TEST(DimensionElectricCurrent, value) {
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{}.value(), 0);
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{-2}.value(), -2);
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{-1}.value(), -1);
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{0}.value(), 0);
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{1}.value(), 1);
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{2}.value(), 2);
  EXPECT_EQ(PhQ::Dimension::ElectricCurrent{3}.value(), 3);
}

}  // namespace
