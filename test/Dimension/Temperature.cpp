// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#include "../../include/PhQ/Dimension/Temperature.hpp"

#include <cstdint>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

namespace PhQ::Dimension {

namespace {

TEST(DimensionTemperature, Abbreviation) {
  EXPECT_EQ(Temperature::Abbreviation(), "Θ");
}

TEST(DimensionTemperature, ComparisonOperators) {
  constexpr Temperature first{-1};
  constexpr Temperature second{2};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GT(second, first);
  EXPECT_GE(second, first);
  EXPECT_GE(first, first);
}

TEST(DimensionTemperature, CopyAssignmentOperator) {
  constexpr Temperature first{3};
  Temperature second{0};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DimensionTemperature, CopyConstructor) {
  constexpr Temperature first{3};
  constexpr Temperature second{first};
  EXPECT_EQ(second, first);
}

TEST(DimensionTemperature, DefaultConstructor) {
  EXPECT_NO_THROW(Temperature{});
}

TEST(DimensionTemperature, Hash) {
  constexpr Temperature first{0};
  constexpr Temperature second{2};
  constexpr Temperature third{-1};
  constexpr std::hash<Temperature> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionTemperature, Label) {
  EXPECT_EQ(Temperature::Label(), "Temperature");
}

TEST(DimensionTemperature, MoveAssignmentOperator) {
  Temperature first{3};
  Temperature second{-1};
  second = std::move(first);
  EXPECT_EQ(second, Temperature(3));
}

TEST(DimensionTemperature, MoveConstructor) {
  Temperature first{3};
  const Temperature second{std::move(first)};
  EXPECT_EQ(second, Temperature(3));
}

TEST(DimensionTemperature, Print) {
  EXPECT_EQ(Temperature().Print(), "");
  EXPECT_EQ(Temperature(-1).Print(), "Θ^(-1)");
  EXPECT_EQ(Temperature(0).Print(), "");
  EXPECT_EQ(Temperature(1).Print(), "Θ");
  EXPECT_EQ(Temperature(2).Print(), "Θ^2");
}

TEST(DimensionTemperature, SizeOf) {
  EXPECT_EQ(sizeof(Temperature{}), sizeof(int8_t));
}

TEST(DimensionTemperature, Stream) {
  constexpr Temperature dimension{3};
  std::ostringstream stream;
  stream << dimension;
  EXPECT_EQ(stream.str(), dimension.Print());
}

TEST(DimensionTemperature, Value) {
  EXPECT_EQ(Temperature().Value(), 0);
  EXPECT_EQ(Temperature(-1).Value(), -1);
  EXPECT_EQ(Temperature(0).Value(), 0);
  EXPECT_EQ(Temperature(1).Value(), 1);
  EXPECT_EQ(Temperature(2).Value(), 2);
}

}  // namespace

}  // namespace PhQ::Dimension
