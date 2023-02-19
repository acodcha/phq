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

#include "../../include/PhQ/Dimension/Temperature.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionTemperature, Abbreviation) {
  EXPECT_EQ(Temperature::abbreviation(), "Θ");
}

TEST(DimensionTemperature, Accessor) {
  EXPECT_EQ(Temperature{}.value(), 0);
  EXPECT_EQ(Temperature{-2}.value(), -2);
  EXPECT_EQ(Temperature{-1}.value(), -1);
  EXPECT_EQ(Temperature{0}.value(), 0);
  EXPECT_EQ(Temperature{1}.value(), 1);
  EXPECT_EQ(Temperature{2}.value(), 2);
  EXPECT_EQ(Temperature{3}.value(), 3);
}

TEST(DimensionTemperature, Comparison) {
  const Temperature temperature0{-1};
  const Temperature temperature1{2};
  EXPECT_EQ(temperature0, temperature0);
  EXPECT_NE(temperature0, temperature1);
  EXPECT_LT(temperature0, temperature1);
  EXPECT_LE(temperature0, temperature0);
  EXPECT_LE(temperature0, temperature1);
  EXPECT_GT(temperature1, temperature0);
  EXPECT_GE(temperature1, temperature0);
  EXPECT_GE(temperature0, temperature0);
  const std::set<Temperature> increasing{temperature0, temperature1};
  EXPECT_EQ(*increasing.begin(), temperature0);
  const std::set<Temperature, std::greater<Temperature>> decreasing{
      temperature0, temperature1};
  EXPECT_EQ(*decreasing.begin(), temperature1);
}

TEST(DimensionTemperature, Hash) {
  const Temperature temperature0{-2};
  const Temperature temperature1{-1};
  const Temperature temperature2{0};
  const Temperature temperature3{1};
  const Temperature temperature4{2};
  const Temperature temperature5{3};
  const std::hash<Temperature> hasher;
  EXPECT_NE(hasher(temperature0), hasher(temperature1));
  EXPECT_NE(hasher(temperature0), hasher(temperature2));
  EXPECT_NE(hasher(temperature0), hasher(temperature3));
  EXPECT_NE(hasher(temperature0), hasher(temperature4));
  EXPECT_NE(hasher(temperature0), hasher(temperature5));
  const std::unordered_set<Temperature> unordered{temperature0, temperature1,
                                                  temperature2, temperature3,
                                                  temperature4, temperature5};
}

TEST(DimensionTemperature, Label) {
  EXPECT_EQ(Temperature::label(), "Temperature");
}

TEST(DimensionTemperature, Print) {
  EXPECT_EQ(Temperature{}.print(), "");
  EXPECT_EQ(Temperature{-2}.print(), "Θ^(-2)");
  EXPECT_EQ(Temperature{-1}.print(), "Θ^(-1)");
  EXPECT_EQ(Temperature{0}.print(), "");
  EXPECT_EQ(Temperature{1}.print(), "Θ");
  EXPECT_EQ(Temperature{2}.print(), "Θ^2");
  EXPECT_EQ(Temperature{3}.print(), "Θ^3");
}

TEST(DimensionTemperature, Stream) {
  const Temperature temperature{3};
  std::ostringstream stream;
  stream << temperature;
  EXPECT_EQ(stream.str(), temperature.print());
}

}  // namespace

}  // namespace PhQ::Dimension
