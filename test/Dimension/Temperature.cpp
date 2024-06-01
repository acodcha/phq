// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

TEST(DimensionTemperature, Constructor) {
  EXPECT_NO_THROW(Temperature(1));
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
