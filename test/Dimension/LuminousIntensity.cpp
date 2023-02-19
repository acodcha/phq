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

#include "../../include/PhQ/Dimension/LuminousIntensity.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionLuminousIntensity, Abbreviation) {
  EXPECT_EQ(LuminousIntensity::Abbreviation(), "J");
}

TEST(DimensionLuminousIntensity, Accessor) {
  EXPECT_EQ(LuminousIntensity{}.Value(), 0);
  EXPECT_EQ(LuminousIntensity{-2}.Value(), -2);
  EXPECT_EQ(LuminousIntensity{-1}.Value(), -1);
  EXPECT_EQ(LuminousIntensity{0}.Value(), 0);
  EXPECT_EQ(LuminousIntensity{1}.Value(), 1);
  EXPECT_EQ(LuminousIntensity{2}.Value(), 2);
  EXPECT_EQ(LuminousIntensity{3}.Value(), 3);
}

TEST(DimensionLuminousIntensity, Comparison) {
  const LuminousIntensity intensity0{-1};
  const LuminousIntensity intensity1{2};
  EXPECT_EQ(intensity0, intensity0);
  EXPECT_NE(intensity0, intensity1);
  EXPECT_LT(intensity0, intensity1);
  EXPECT_LE(intensity0, intensity0);
  EXPECT_LE(intensity0, intensity1);
  EXPECT_GT(intensity1, intensity0);
  EXPECT_GE(intensity1, intensity0);
  EXPECT_GE(intensity0, intensity0);
  const std::set<LuminousIntensity> increasing{intensity0, intensity1};
  EXPECT_EQ(*increasing.begin(), intensity0);
  const std::set<LuminousIntensity, std::greater<LuminousIntensity>> decreasing{
      intensity0, intensity1};
  EXPECT_EQ(*decreasing.begin(), intensity1);
}

TEST(DimensionLuminousIntensity, Hash) {
  const LuminousIntensity intensity0{-2};
  const LuminousIntensity intensity1{-1};
  const LuminousIntensity intensity2{0};
  const LuminousIntensity intensity3{1};
  const LuminousIntensity intensity4{2};
  const LuminousIntensity intensity5{3};
  const std::hash<LuminousIntensity> hasher;
  EXPECT_NE(hasher(intensity0), hasher(intensity1));
  EXPECT_NE(hasher(intensity0), hasher(intensity2));
  EXPECT_NE(hasher(intensity0), hasher(intensity3));
  EXPECT_NE(hasher(intensity0), hasher(intensity4));
  EXPECT_NE(hasher(intensity0), hasher(intensity5));
  const std::unordered_set<LuminousIntensity> unordered{
      intensity0, intensity1, intensity2, intensity3, intensity4, intensity5};
}

TEST(DimensionLuminousIntensity, Label) {
  EXPECT_EQ(LuminousIntensity::Label(), "Luminous Intensity");
}

TEST(DimensionLuminousIntensity, Print) {
  EXPECT_EQ(LuminousIntensity{}.Print(), "");
  EXPECT_EQ(LuminousIntensity{-2}.Print(), "J^(-2)");
  EXPECT_EQ(LuminousIntensity{-1}.Print(), "J^(-1)");
  EXPECT_EQ(LuminousIntensity{0}.Print(), "");
  EXPECT_EQ(LuminousIntensity{1}.Print(), "J");
  EXPECT_EQ(LuminousIntensity{2}.Print(), "J^2");
  EXPECT_EQ(LuminousIntensity{3}.Print(), "J^3");
}

TEST(DimensionLuminousIntensity, Stream) {
  const LuminousIntensity intensity{3};
  std::ostringstream stream;
  stream << intensity;
  EXPECT_EQ(stream.str(), intensity.Print());
}

}  // namespace

}  // namespace PhQ::Dimension
