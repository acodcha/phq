// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#include "../../include/PhQ/Dimension/Set.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionSet, Json) {
  EXPECT_EQ(Set(Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{-1}).json(), "{\"length\":2,\"mass\":1,\"time\":-2,\"temperature\":-1}");
  EXPECT_EQ(Set(Length{0}, Mass{1}, Time{0}, ElectricCurrent{0}, Temperature{0}, SubstanceAmount{-1}).json(), "{\"mass\":1,\"substance_amount\":-1}");
}

TEST(DimensionSet, Hash) {
  const Set object0;
  const Set object1{Length{2}};
  const Set object2{Length{-3}, Mass{1}};
  const Set object3{Length{3}, Mass{0}, Time{-1}};
  const Set object4{Length{-2}, Mass{-1}, Time{2}, ElectricCurrent{1}};
  const Set object5{Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{-1}};
  const Set object6{Length{0}, Mass{1}, Time{0}, ElectricCurrent{0}, Temperature{0}, SubstanceAmount{-1}};
  const Set object7{Length{0}, Mass{0}, Time{0}, ElectricCurrent{0}, Temperature{-1}, SubstanceAmount{0}, LuminousIntensity{1}};
  const std::hash<Set> hasher;
  EXPECT_NE(hasher(object0), hasher(object1));
  EXPECT_NE(hasher(object0), hasher(object2));
  EXPECT_NE(hasher(object0), hasher(object3));
  EXPECT_NE(hasher(object0), hasher(object4));
  EXPECT_NE(hasher(object0), hasher(object5));
  EXPECT_NE(hasher(object0), hasher(object6));
  const std::unordered_set<Set> unordered{object0, object1, object2, object3, object4, object5, object6, object7};
}

TEST(DimensionSet, Operators) {
  const Set object0{Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{-1}};
  const Set object1{Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{0}, SubstanceAmount{1}};
  EXPECT_EQ(object0, object0);
  EXPECT_NE(object0, object1);
  EXPECT_LT(object0, object1);
  EXPECT_LE(object0, object0);
  EXPECT_LE(object0, object1);
  EXPECT_GT(object1, object0);
  EXPECT_GE(object1, object0);
  EXPECT_GE(object0, object0);
  const std::set<Set> increasing{object0, object1};
  EXPECT_EQ(*increasing.begin(), object0);
  const std::set<Set, std::greater<Set>> decreasing{object0, object1};
  EXPECT_EQ(*decreasing.begin(), object1);
}

TEST(DimensionSet, Print) {
  EXPECT_EQ(Set{}.print(), "1");
  EXPECT_EQ(Set{Length{2}}.print(), "L^2");
  EXPECT_EQ(Set(Length{-3}, Mass{1}).print(), "L^(-3)·M");
  EXPECT_EQ(Set(Length{3}, Mass{0}, Time{-1}).print(), "L^3·T^(-1)");
  EXPECT_EQ(Set(Length{-2}, Mass{-1}, Time{2}, ElectricCurrent{1}).print(), "L^(-2)·M^(-1)·T^2·I");
  EXPECT_EQ(Set(Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{-1}).print(), "L^2·M·T^(-2)·Θ^(-1)");
  EXPECT_EQ(Set(Length{0}, Mass{1}, Time{0}, ElectricCurrent{0}, Temperature{0}, SubstanceAmount{-1}).print(), "M·N^(-1)");
  EXPECT_EQ(Set(Length{0}, Mass{0}, Time{0}, ElectricCurrent{0}, Temperature{-1}, SubstanceAmount{0}, LuminousIntensity{1}).print(), "Θ^(-1)·J");
}

TEST(DimensionSet, Stream) {
  const Set object{Length{-2}, Mass{-1}, Time{2}, ElectricCurrent{1}};
  std::ostringstream output_string_stream;
  output_string_stream << object;
  EXPECT_EQ(output_string_stream.str(), object.print());
}

TEST(DimensionSet, Value) {
  const Set object{Length{-3}, Mass{-2}, Time{-1}, ElectricCurrent{0}, Temperature{1}, SubstanceAmount{2}, LuminousIntensity{3}};
  EXPECT_EQ(object.length(), Length{-3});
  EXPECT_EQ(object.mass(), Mass{-2});
  EXPECT_EQ(object.time(), Time{-1});
  EXPECT_EQ(object.electric_current(), ElectricCurrent{0});
  EXPECT_EQ(object.temperature(), Temperature{1});
  EXPECT_EQ(object.substance_amount(), SubstanceAmount{2});
  EXPECT_EQ(object.luminous_intensity(), LuminousIntensity{3});
}

TEST(DimensionSet, Xml) {
  EXPECT_EQ(Set(Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{-1}).xml(), "<length>2</length><mass>1</mass><time>-2</time><temperature>-1</temperature>");
  EXPECT_EQ(Set(Length{0}, Mass{1}, Time{0}, ElectricCurrent{0}, Temperature{0}, SubstanceAmount{-1}).xml(), "<mass>1</mass><substance_amount>-1</substance_amount>");
}

}  // namespace

}  // namespace PhQ::Dimension
