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

#include "../../include/PhQ/Dimension/Set.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionSet, Accessor) {
  const Set set{Time{-3},
                Length{-2},
                Mass{-1},
                ElectricCurrent{0},
                Temperature{1},
                SubstanceAmount{2},
                LuminousIntensity{3}};
  EXPECT_EQ(set.Time(), Time{-3});
  EXPECT_EQ(set.Length(), Length{-2});
  EXPECT_EQ(set.Mass(), Mass{-1});
  EXPECT_EQ(set.ElectricCurrent(), ElectricCurrent{0});
  EXPECT_EQ(set.Temperature(), Temperature{1});
  EXPECT_EQ(set.SubstanceAmount(), SubstanceAmount{2});
  EXPECT_EQ(set.LuminousIntensity(), LuminousIntensity{3});
}

TEST(DimensionSet, Comparison) {
  const Set set0{
      Time{-2}, Length{2}, Mass{1}, ElectricCurrent{0}, Temperature{-1}};
  const Set set1{Time{-2},           Length{2},      Mass{1},
                 ElectricCurrent{0}, Temperature{0}, SubstanceAmount{1}};
  EXPECT_EQ(set0, set0);
  EXPECT_NE(set0, set1);
  EXPECT_LT(set0, set1);
  EXPECT_LE(set0, set0);
  EXPECT_LE(set0, set1);
  EXPECT_GT(set1, set0);
  EXPECT_GE(set1, set0);
  EXPECT_GE(set0, set0);
  const std::set<Set> increasing{set0, set1};
  EXPECT_EQ(*increasing.begin(), set0);
  const std::set<Set, std::greater<Set>> decreasing{set0, set1};
  EXPECT_EQ(*decreasing.begin(), set1);
}

TEST(DimensionSet, Hash) {
  const Set set0;
  const Set set1{Time{2}};
  const Set set2{Time{-3}, Length{1}};
  const Set set3{Time{3}, Length{0}, Mass{-1}};
  const Set set4{Time{-2}, Length{-1}, Mass{2}, ElectricCurrent{1}};
  const Set set5{
      Time{2}, Length{1}, Mass{-2}, ElectricCurrent{0}, Temperature{-1}};
  const Set set6{
      Time{0},        Length{1},          Mass{0}, ElectricCurrent{0},
      Temperature{0}, SubstanceAmount{-1}};
  const Set set7{
      Time{0},
      Length{0},
      Mass{0},
      ElectricCurrent{0},
      Temperature{-1},
      SubstanceAmount{0},
      LuminousIntensity{1}};
  const std::hash<Set> hasher;
  EXPECT_NE(hasher(set0), hasher(set1));
  EXPECT_NE(hasher(set0), hasher(set2));
  EXPECT_NE(hasher(set0), hasher(set3));
  EXPECT_NE(hasher(set0), hasher(set4));
  EXPECT_NE(hasher(set0), hasher(set5));
  EXPECT_NE(hasher(set0), hasher(set6));
  const std::unordered_set<Set> unordered{
      set0, set1, set2, set3, set4, set5, set6, set7};
}

TEST(DimensionSet, JSON) {
  EXPECT_EQ(
      Set(Time{-2}, Length{2}, Mass{1}, ElectricCurrent{0}, Temperature{-1})
          .JSON(),
      "{\"time\":-2,\"length\":2,\"mass\":1,\"temperature\":-1}");
  EXPECT_EQ(Set(Time{0}, Length{0}, Mass{1}, ElectricCurrent{0}, Temperature{0},
                SubstanceAmount{-1})
                .JSON(),
            "{\"mass\":1,\"substance_amount\":-1}");
}

TEST(DimensionSet, Print) {
  EXPECT_EQ(Set{}.Print(), "1");
  EXPECT_EQ(Set{Time{2}}.Print(), "T^2");
  EXPECT_EQ(Set(Time{1}, Length{-3}).Print(), "T·L^(-3)");
  EXPECT_EQ(Set(Time{-1}, Length{3}, Mass{0}).Print(), "T^(-1)·L^3");
  EXPECT_EQ(Set(Time{2}, Length{-2}, Mass{-1}, ElectricCurrent{1}).Print(),
            "T^2·L^(-2)·M^(-1)·I");
  EXPECT_EQ(
      Set(Time{-2}, Length{2}, Mass{1}, ElectricCurrent{0}, Temperature{-1})
          .Print(),
      "T^(-2)·L^2·M·Θ^(-1)");
  EXPECT_EQ(Set(Time{0}, Length{0}, Mass{1}, ElectricCurrent{0}, Temperature{0},
                SubstanceAmount{-1})
                .Print(),
            "M·N^(-1)");
  EXPECT_EQ(Set(Time{0}, Length{0}, Mass{0}, ElectricCurrent{0},
                Temperature{-1}, SubstanceAmount{0}, LuminousIntensity{1})
                .Print(),
            "Θ^(-1)·J");
}

TEST(DimensionSet, Stream) {
  const Set set{Time{2}, Length{-2}, Mass{-1}, ElectricCurrent{1}};
  std::ostringstream stream;
  stream << set;
  EXPECT_EQ(stream.str(), set.Print());
}

TEST(DimensionSet, XML) {
  EXPECT_EQ(
      Set(Time{-2}, Length{2}, Mass{1}, ElectricCurrent{0}, Temperature{-1})
          .XML(),
      "<time>-2</time><length>2</length><mass>1</mass><temperature>-1</"
      "temperature>");
  EXPECT_EQ(Set(Time{0}, Length{0}, Mass{1}, ElectricCurrent{0}, Temperature{0},
                SubstanceAmount{-1})
                .XML(),
            "<mass>1</mass><substance_amount>-1</substance_amount>");
}

TEST(DimensionSet, YAML) {
  EXPECT_EQ(
      Set(Time{-2}, Length{2}, Mass{1}, ElectricCurrent{0}, Temperature{-1})
          .YAML(),
      "{time:-2,length:2,mass:1,temperature:-1}");
  EXPECT_EQ(Set(Time{0}, Length{0}, Mass{1}, ElectricCurrent{0}, Temperature{0},
                SubstanceAmount{-1})
                .YAML(),
            "{mass:1,substance_amount:-1}");
}

}  // namespace

}  // namespace PhQ::Dimension
