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

#include "../../include/PhQ/Dimension/Set.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionSet, Accessor) {
  const Set set{Length{-3},          Mass{-2},       Time{-1},
                ElectricCurrent{0},  Temperature{1}, SubstanceAmount{2},
                LuminousIntensity{3}};
  EXPECT_EQ(set.length(), Length{-3});
  EXPECT_EQ(set.mass(), Mass{-2});
  EXPECT_EQ(set.time(), Time{-1});
  EXPECT_EQ(set.electric_current(), ElectricCurrent{0});
  EXPECT_EQ(set.temperature(), Temperature{1});
  EXPECT_EQ(set.substance_amount(), SubstanceAmount{2});
  EXPECT_EQ(set.luminous_intensity(), LuminousIntensity{3});
}

TEST(DimensionSet, Comparison) {
  const Set set0{Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0},
                 Temperature{-1}};
  const Set set1{Length{2},          Mass{1},        Time{-2},
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
  const Set set1{Length{2}};
  const Set set2{Length{-3}, Mass{1}};
  const Set set3{Length{3}, Mass{0}, Time{-1}};
  const Set set4{Length{-2}, Mass{-1}, Time{2}, ElectricCurrent{1}};
  const Set set5{Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0},
                 Temperature{-1}};
  const Set set6{Length{0},          Mass{1},        Time{0},
                 ElectricCurrent{0}, Temperature{0}, SubstanceAmount{-1}};
  const Set set7{Length{0},           Mass{0},         Time{0},
                 ElectricCurrent{0},  Temperature{-1}, SubstanceAmount{0},
                 LuminousIntensity{1}};
  const std::hash<Set> hasher;
  EXPECT_NE(hasher(set0), hasher(set1));
  EXPECT_NE(hasher(set0), hasher(set2));
  EXPECT_NE(hasher(set0), hasher(set3));
  EXPECT_NE(hasher(set0), hasher(set4));
  EXPECT_NE(hasher(set0), hasher(set5));
  EXPECT_NE(hasher(set0), hasher(set6));
  const std::unordered_set<Set> unordered{set0, set1, set2, set3,
                                          set4, set5, set6, set7};
}

TEST(DimensionSet, Json) {
  EXPECT_EQ(
      Set(Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{-1})
          .json(),
      "{\"length\":2,\"mass\":1,\"time\":-2,\"temperature\":-1}");
  EXPECT_EQ(Set(Length{0}, Mass{1}, Time{0}, ElectricCurrent{0}, Temperature{0},
                SubstanceAmount{-1})
                .json(),
            "{\"mass\":1,\"substance_amount\":-1}");
}

TEST(DimensionSet, Print) {
  EXPECT_EQ(Set{}.print(), "1");
  EXPECT_EQ(Set{Length{2}}.print(), "L^2");
  EXPECT_EQ(Set(Length{-3}, Mass{1}).print(), "L^(-3)·M");
  EXPECT_EQ(Set(Length{3}, Mass{0}, Time{-1}).print(), "L^3·T^(-1)");
  EXPECT_EQ(Set(Length{-2}, Mass{-1}, Time{2}, ElectricCurrent{1}).print(),
            "L^(-2)·M^(-1)·T^2·I");
  EXPECT_EQ(
      Set(Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{-1})
          .print(),
      "L^2·M·T^(-2)·Θ^(-1)");
  EXPECT_EQ(Set(Length{0}, Mass{1}, Time{0}, ElectricCurrent{0}, Temperature{0},
                SubstanceAmount{-1})
                .print(),
            "M·N^(-1)");
  EXPECT_EQ(Set(Length{0}, Mass{0}, Time{0}, ElectricCurrent{0},
                Temperature{-1}, SubstanceAmount{0}, LuminousIntensity{1})
                .print(),
            "Θ^(-1)·J");
}

TEST(DimensionSet, Stream) {
  const Set set{Length{-2}, Mass{-1}, Time{2}, ElectricCurrent{1}};
  std::ostringstream stream;
  stream << set;
  EXPECT_EQ(stream.str(), set.print());
}

TEST(DimensionSet, Xml) {
  EXPECT_EQ(
      Set(Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{-1})
          .xml(),
      "<length>2</length><mass>1</mass><time>-2</time><temperature>-1</"
      "temperature>");
  EXPECT_EQ(Set(Length{0}, Mass{1}, Time{0}, ElectricCurrent{0}, Temperature{0},
                SubstanceAmount{-1})
                .xml(),
            "<mass>1</mass><substance_amount>-1</substance_amount>");
}

TEST(DimensionSet, Yaml) {
  EXPECT_EQ(
      Set(Length{2}, Mass{1}, Time{-2}, ElectricCurrent{0}, Temperature{-1})
          .yaml(),
      "{length:2,mass:1,time:-2,temperature:-1}");
  EXPECT_EQ(Set(Length{0}, Mass{1}, Time{0}, ElectricCurrent{0}, Temperature{0},
                SubstanceAmount{-1})
                .yaml(),
            "{mass:1,substance_amount:-1}");
}

}  // namespace

}  // namespace PhQ::Dimension
