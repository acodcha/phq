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

#include "../include/PhQ/Dimensions.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ {

namespace {

TEST(Dimensions, Accessor) {
  const Dimensions dimensions{
      Dimension::Time{-3},
      Dimension::Length{-2},
      Dimension::Mass{-1},
      Dimension::ElectricCurrent{0},
      Dimension::Temperature{1},
      Dimension::SubstanceAmount{2},
      Dimension::LuminousIntensity{3}};
  EXPECT_EQ(dimensions.Time(), Dimension::Time{-3});
  EXPECT_EQ(dimensions.Length(), Dimension::Length{-2});
  EXPECT_EQ(dimensions.Mass(), Dimension::Mass{-1});
  EXPECT_EQ(dimensions.ElectricCurrent(), Dimension::ElectricCurrent{0});
  EXPECT_EQ(dimensions.Temperature(), Dimension::Temperature{1});
  EXPECT_EQ(dimensions.SubstanceAmount(), Dimension::SubstanceAmount{2});
  EXPECT_EQ(dimensions.LuminousIntensity(), Dimension::LuminousIntensity{3});
}

TEST(Dimensions, Comparison) {
  const Dimensions set0{
      Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
      Dimension::ElectricCurrent{0}, Dimension::Temperature{-1}};
  const Dimensions set1{
      Dimension::Time{-2},       Dimension::Length{2},
      Dimension::Mass{1},        Dimension::ElectricCurrent{0},
      Dimension::Temperature{0}, Dimension::SubstanceAmount{1}};
  EXPECT_EQ(set0, set0);
  EXPECT_NE(set0, set1);
  EXPECT_LT(set0, set1);
  EXPECT_LE(set0, set0);
  EXPECT_LE(set0, set1);
  EXPECT_GT(set1, set0);
  EXPECT_GE(set1, set0);
  EXPECT_GE(set0, set0);
  const std::set<Dimensions> increasing{set0, set1};
  EXPECT_EQ(*increasing.begin(), set0);
  const std::set<Dimensions, std::greater<Dimensions>> decreasing{set0, set1};
  EXPECT_EQ(*decreasing.begin(), set1);
}

TEST(Dimensions, Hash) {
  const Dimensions set0;
  const Dimensions set1{Dimension::Time{2}};
  const Dimensions set2{Dimension::Time{-3}, Dimension::Length{1}};
  const Dimensions set3{
      Dimension::Time{3}, Dimension::Length{0}, Dimension::Mass{-1}};
  const Dimensions set4{Dimension::Time{-2}, Dimension::Length{-1},
                        Dimension::Mass{2}, Dimension::ElectricCurrent{1}};
  const Dimensions set5{
      Dimension::Time{2}, Dimension::Length{1}, Dimension::Mass{-2},
      Dimension::ElectricCurrent{0}, Dimension::Temperature{-1}};
  const Dimensions set6{
      Dimension::Time{0},        Dimension::Length{1},
      Dimension::Mass{0},        Dimension::ElectricCurrent{0},
      Dimension::Temperature{0}, Dimension::SubstanceAmount{-1}};
  const Dimensions set7{
      Dimension::Time{0},
      Dimension::Length{0},
      Dimension::Mass{0},
      Dimension::ElectricCurrent{0},
      Dimension::Temperature{-1},
      Dimension::SubstanceAmount{0},
      Dimension::LuminousIntensity{1}};
  const std::hash<Dimensions> hasher;
  EXPECT_NE(hasher(set0), hasher(set1));
  EXPECT_NE(hasher(set0), hasher(set2));
  EXPECT_NE(hasher(set0), hasher(set3));
  EXPECT_NE(hasher(set0), hasher(set4));
  EXPECT_NE(hasher(set0), hasher(set5));
  EXPECT_NE(hasher(set0), hasher(set6));
  const std::unordered_set<Dimensions> unordered{
      set0, set1, set2, set3, set4, set5, set6, set7};
}

TEST(Dimensions, JSON) {
  EXPECT_EQ(
      Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{0}, Dimension::Temperature{-1})
          .JSON(),
      "{\"time\":-2,\"length\":2,\"mass\":1,\"temperature\":-1}");
  EXPECT_EQ(
      Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                 Dimension::SubstanceAmount{-1})
          .JSON(),
      "{\"mass\":1,\"substance_amount\":-1}");
}

TEST(Dimensions, Print) {
  EXPECT_EQ(Dimensions{}.Print(), "1");
  EXPECT_EQ(Dimensions{Dimension::Time{2}}.Print(), "T^2");
  EXPECT_EQ(Dimensions(Dimension::Time{1}, Dimension::Length{-3}).Print(),
            "T·L^(-3)");
  EXPECT_EQ(
      Dimensions(Dimension::Time{-1}, Dimension::Length{3}, Dimension::Mass{0})
          .Print(),
      "T^(-1)·L^3");
  EXPECT_EQ(Dimensions(Dimension::Time{2}, Dimension::Length{-2},
                       Dimension::Mass{-1}, Dimension::ElectricCurrent{1})
                .Print(),
            "T^2·L^(-2)·M^(-1)·I");
  EXPECT_EQ(
      Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{0}, Dimension::Temperature{-1})
          .Print(),
      "T^(-2)·L^2·M·Θ^(-1)");
  EXPECT_EQ(
      Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                 Dimension::SubstanceAmount{-1})
          .Print(),
      "M·N^(-1)");
  EXPECT_EQ(
      Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{0},
                 Dimension::ElectricCurrent{0}, Dimension::Temperature{-1},
                 Dimension::SubstanceAmount{0}, Dimension::LuminousIntensity{1})
          .Print(),
      "Θ^(-1)·J");
}

TEST(Dimensions, SizeOf) {
  const Dimensions dimensions{
      Dimension::Time{2}, Dimension::Length{-2}, Dimension::Mass{-1},
      Dimension::ElectricCurrent{1}};
  EXPECT_EQ(sizeof(dimensions), 7 * sizeof(int8_t));
}

TEST(Dimensions, Stream) {
  const Dimensions dimensions{
      Dimension::Time{2}, Dimension::Length{-2}, Dimension::Mass{-1},
      Dimension::ElectricCurrent{1}};
  std::ostringstream stream;
  stream << dimensions;
  EXPECT_EQ(stream.str(), dimensions.Print());
}

TEST(Dimensions, XML) {
  EXPECT_EQ(
      Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{0}, Dimension::Temperature{-1})
          .XML(),
      "<time>-2</time><length>2</length><mass>1</mass><temperature>-1</"
      "temperature>");
  EXPECT_EQ(
      Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                 Dimension::SubstanceAmount{-1})
          .XML(),
      "<mass>1</mass><substance_amount>-1</substance_amount>");
}

TEST(Dimensions, YAML) {
  EXPECT_EQ(
      Dimensions(Dimension::Time{-2}, Dimension::Length{2}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{0}, Dimension::Temperature{-1})
          .YAML(),
      "{time:-2,length:2,mass:1,temperature:-1}");
  EXPECT_EQ(
      Dimensions(Dimension::Time{0}, Dimension::Length{0}, Dimension::Mass{1},
                 Dimension::ElectricCurrent{0}, Dimension::Temperature{0},
                 Dimension::SubstanceAmount{-1})
          .YAML(),
      "{mass:1,substance_amount:-1}");
}

}  // namespace

}  // namespace PhQ