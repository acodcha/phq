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

#include "../include/PhQ/SquareRoot.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(BaseSquareRoot, CornerCases) {
  EXPECT_TRUE(std::isnan(SquareRoot(std::numeric_limits<double>::quiet_NaN())));
  EXPECT_TRUE(std::isnan(SquareRoot(-std::numeric_limits<double>::infinity())));
  EXPECT_TRUE(std::isnan(SquareRoot(-2.0)));
  EXPECT_EQ(SquareRoot(0.0), std::sqrt(0.0));
  EXPECT_EQ(SquareRoot(1.0), std::sqrt(1.0));
  EXPECT_EQ(SquareRoot(std::numeric_limits<double>::min()),
            std::sqrt(std::numeric_limits<double>::min()));
  EXPECT_DOUBLE_EQ(SquareRoot(std::numeric_limits<double>::max()),
                   std::sqrt(std::numeric_limits<double>::max()));
  EXPECT_TRUE(std::isinf(SquareRoot(std::numeric_limits<double>::infinity())));
}

TEST(BaseSquareRoot, Numbers) {
  EXPECT_EQ(SquareRoot(1.234567890123456789e-128),
            std::sqrt(1.234567890123456789e-128));
  EXPECT_EQ(SquareRoot(1.234567890123456789e-64),
            std::sqrt(1.234567890123456789e-64));
  EXPECT_EQ(SquareRoot(1.234567890123456789e-32),
            std::sqrt(1.234567890123456789e-32));
  EXPECT_EQ(SquareRoot(1.234567890123456789e-16),
            std::sqrt(1.234567890123456789e-16));
  EXPECT_EQ(
      SquareRoot(1.234567890123456789e-8), std::sqrt(1.234567890123456789e-8));
  EXPECT_EQ(
      SquareRoot(1.234567890123456789e-4), std::sqrt(1.234567890123456789e-4));
  EXPECT_DOUBLE_EQ(
      SquareRoot(1.234567890123456789e-3), std::sqrt(1.234567890123456789e-3));
  EXPECT_DOUBLE_EQ(
      SquareRoot(1.234567890123456789e-2), std::sqrt(1.234567890123456789e-2));
  EXPECT_DOUBLE_EQ(
      SquareRoot(1.234567890123456789e-1), std::sqrt(1.234567890123456789e-1));
  EXPECT_DOUBLE_EQ(
      SquareRoot(0.1234567890123456789), std::sqrt(0.1234567890123456789));
  EXPECT_DOUBLE_EQ(
      SquareRoot(1.234567890123456789), std::sqrt(1.234567890123456789));
  EXPECT_DOUBLE_EQ(
      SquareRoot(12.34567890123456789), std::sqrt(12.34567890123456789));
  EXPECT_DOUBLE_EQ(
      SquareRoot(123.4567890123456789), std::sqrt(123.4567890123456789));
  EXPECT_DOUBLE_EQ(
      SquareRoot(1234.567890123456789), std::sqrt(1234.567890123456789));
  EXPECT_DOUBLE_EQ(
      SquareRoot(1.234567890123456789e4), std::sqrt(1.234567890123456789e4));
  EXPECT_EQ(
      SquareRoot(1.234567890123456789e8), std::sqrt(1.234567890123456789e8));
  EXPECT_EQ(
      SquareRoot(1.234567890123456789e16), std::sqrt(1.234567890123456789e16));
  EXPECT_EQ(
      SquareRoot(1.234567890123456789e32), std::sqrt(1.234567890123456789e32));
  EXPECT_EQ(
      SquareRoot(1.234567890123456789e64), std::sqrt(1.234567890123456789e64));
  EXPECT_EQ(SquareRoot(1.234567890123456789e128),
            std::sqrt(1.234567890123456789e128));
}

}  // namespace

}  // namespace PhQ
