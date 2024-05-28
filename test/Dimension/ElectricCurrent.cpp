// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../../include/PhQ/Dimension/ElectricCurrent.hpp"

#include <cstdint>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

namespace PhQ::Dimension {

namespace {

TEST(DimensionElectricCurrent, Abbreviation) {
  EXPECT_EQ(ElectricCurrent::Abbreviation(), "I");
}

TEST(DimensionElectricCurrent, ComparisonOperators) {
  constexpr ElectricCurrent first{-1};
  constexpr ElectricCurrent second{2};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GT(second, first);
  EXPECT_GE(second, first);
  EXPECT_GE(first, first);
}

TEST(DimensionElectricCurrent, Constructor) {
  EXPECT_NO_THROW(ElectricCurrent(1));
}

TEST(DimensionElectricCurrent, CopyAssignmentOperator) {
  constexpr ElectricCurrent first{3};
  ElectricCurrent second{0};
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DimensionElectricCurrent, CopyConstructor) {
  constexpr ElectricCurrent first{3};
  constexpr ElectricCurrent second{first};
  EXPECT_EQ(second, first);
}

TEST(DimensionElectricCurrent, DefaultConstructor) {
  EXPECT_NO_THROW(ElectricCurrent{});
}

TEST(DimensionElectricCurrent, Hash) {
  constexpr ElectricCurrent first{0};
  constexpr ElectricCurrent second{2};
  constexpr ElectricCurrent third{-1};
  constexpr std::hash<ElectricCurrent> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DimensionElectricCurrent, Label) {
  EXPECT_EQ(ElectricCurrent::Label(), "Electric Current");
}

TEST(DimensionElectricCurrent, MoveAssignmentOperator) {
  ElectricCurrent first{3};
  ElectricCurrent second{-1};
  second = std::move(first);
  EXPECT_EQ(second, ElectricCurrent(3));
}

TEST(DimensionElectricCurrent, MoveConstructor) {
  ElectricCurrent first{3};
  const ElectricCurrent second{std::move(first)};
  EXPECT_EQ(second, ElectricCurrent(3));
}

TEST(DimensionElectricCurrent, Print) {
  EXPECT_EQ(ElectricCurrent().Print(), "");
  EXPECT_EQ(ElectricCurrent(-1).Print(), "I^(-1)");
  EXPECT_EQ(ElectricCurrent(0).Print(), "");
  EXPECT_EQ(ElectricCurrent(1).Print(), "I");
  EXPECT_EQ(ElectricCurrent(2).Print(), "I^2");
}

TEST(DimensionElectricCurrent, SizeOf) {
  EXPECT_EQ(sizeof(ElectricCurrent{}), sizeof(int8_t));
}

TEST(DimensionElectricCurrent, Stream) {
  constexpr ElectricCurrent dimension{3};
  std::ostringstream stream;
  stream << dimension;
  EXPECT_EQ(stream.str(), dimension.Print());
}

TEST(DimensionElectricCurrent, Value) {
  EXPECT_EQ(ElectricCurrent().Value(), 0);
  EXPECT_EQ(ElectricCurrent(-1).Value(), -1);
  EXPECT_EQ(ElectricCurrent(0).Value(), 0);
  EXPECT_EQ(ElectricCurrent(1).Value(), 1);
  EXPECT_EQ(ElectricCurrent(2).Value(), 2);
}

}  // namespace

}  // namespace PhQ::Dimension
