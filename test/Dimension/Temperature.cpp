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

#include "../../include/PhQ/Dimension/Temperature.hpp"

#include <gtest/gtest.h>

#include <set>
#include <sstream>
#include <unordered_set>

namespace PhQ::Dimension {

namespace {

TEST(DimensionTemperature, Abbreviation) {
  EXPECT_EQ(Temperature::Abbreviation(), "Θ");
}

TEST(DimensionTemperature, Accessor) {
  EXPECT_EQ(Temperature{}.Value(), 0);
  EXPECT_EQ(Temperature{-2}.Value(), -2);
  EXPECT_EQ(Temperature{-1}.Value(), -1);
  EXPECT_EQ(Temperature{0}.Value(), 0);
  EXPECT_EQ(Temperature{1}.Value(), 1);
  EXPECT_EQ(Temperature{2}.Value(), 2);
  EXPECT_EQ(Temperature{3}.Value(), 3);
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

TEST(DimensionTemperature, Constructor) {
  constexpr int8_t value_reference{1};
  constexpr Temperature reference{1};

  // Default constructor.
  constexpr Temperature default_;

  // Copy constructor.
  constexpr Temperature copy_constructed{reference};
  EXPECT_EQ(copy_constructed, reference);

  // Copy assignment operator.
  Temperature copy_assigned{-1};
  copy_assigned = reference;
  EXPECT_EQ(copy_assigned, reference);

  // Move constructor.
  Temperature to_move_construct{value_reference};
  Temperature move_constructed{std::move(to_move_construct)};
  EXPECT_EQ(move_constructed, reference);

  // Move assignment operator.
  Temperature to_move_assign{value_reference};
  Temperature move_assigned{-1};
  move_assigned = std::move(to_move_assign);
  EXPECT_EQ(move_assigned, reference);
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
  const std::unordered_set<Temperature> unordered{
      temperature0, temperature1, temperature2,
      temperature3, temperature4, temperature5};
}

TEST(DimensionTemperature, Label) {
  EXPECT_EQ(Temperature::Label(), "Temperature");
}

TEST(DimensionTemperature, Print) {
  EXPECT_EQ(Temperature{}.Print(), "");
  EXPECT_EQ(Temperature{-2}.Print(), "Θ^(-2)");
  EXPECT_EQ(Temperature{-1}.Print(), "Θ^(-1)");
  EXPECT_EQ(Temperature{0}.Print(), "");
  EXPECT_EQ(Temperature{1}.Print(), "Θ");
  EXPECT_EQ(Temperature{2}.Print(), "Θ^2");
  EXPECT_EQ(Temperature{3}.Print(), "Θ^3");
}

TEST(DimensionTemperature, SizeOf) {
  const Temperature temperature{3};
  EXPECT_EQ(sizeof(temperature), sizeof(int8_t));
}

TEST(DimensionTemperature, Stream) {
  const Temperature temperature{3};
  std::ostringstream stream;
  stream << temperature;
  EXPECT_EQ(stream.str(), temperature.Print());
}

}  // namespace

}  // namespace PhQ::Dimension
