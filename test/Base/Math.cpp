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

#include "../../include/PhQ/Base/Math.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(BaseMath, Pi) { EXPECT_EQ(Pi, 3.14159265358979323846); }

TEST(BaseMath, Power2) {
  EXPECT_EQ(Power2(-1.2345e50), std::pow(-1.2345e50, 2));
  EXPECT_EQ(Power2(-123.45), std::pow(-123.45, 2));
  EXPECT_EQ(Power2(-1.0), std::pow(-1.0, 2));
  EXPECT_EQ(Power2(-0.12345), std::pow(-0.12345, 2));
  EXPECT_EQ(Power2(-1.2345e-50), std::pow(-1.2345e-50, 2));
  EXPECT_EQ(Power2(0.0), std::pow(0.0, 2));
  EXPECT_EQ(Power2(1.2345e-50), std::pow(1.2345e-50, 2));
  EXPECT_EQ(Power2(0.12345), std::pow(0.12345, 2));
  EXPECT_EQ(Power2(1.0), std::pow(1.0, 2));
  EXPECT_EQ(Power2(123.45), std::pow(123.45, 2));
  EXPECT_EQ(Power2(1.2345e50), std::pow(1.2345e50, 2));
}

TEST(BaseMath, Power3) {
  EXPECT_EQ(Power3(-1.2345e50), std::pow(-1.2345e50, 3));
  EXPECT_EQ(Power3(-123.45), std::pow(-123.45, 3));
  EXPECT_EQ(Power3(-1.0), std::pow(-1.0, 3));
  EXPECT_EQ(Power3(-0.12345), std::pow(-0.12345, 3));
  EXPECT_EQ(Power3(-1.2345e-50), std::pow(-1.2345e-50, 3));
  EXPECT_EQ(Power3(0.0), std::pow(0.0, 3));
  EXPECT_EQ(Power3(1.2345e-50), std::pow(1.2345e-50, 3));
  EXPECT_EQ(Power3(0.12345), std::pow(0.12345, 3));
  EXPECT_EQ(Power3(1.0), std::pow(1.0, 3));
  EXPECT_EQ(Power3(123.45), std::pow(123.45, 3));
  EXPECT_EQ(Power3(1.2345e50), std::pow(1.2345e50, 3));
}

TEST(BaseMath, SquareRoot) {
  EXPECT_TRUE(std::isnan(SquareRoot(-1.2345e50)));
  EXPECT_TRUE(std::isnan(SquareRoot(-123.45)));
  EXPECT_TRUE(std::isnan(SquareRoot(-1.0)));
  EXPECT_TRUE(std::isnan(SquareRoot(-0.12345)));
  EXPECT_TRUE(std::isnan(SquareRoot(-1.2345e-50)));
  EXPECT_EQ(SquareRoot(0.0), std::sqrt(0.0));
  EXPECT_EQ(SquareRoot(1.2345e-50), std::sqrt(1.2345e-50));
  EXPECT_EQ(SquareRoot(0.12345), std::sqrt(0.12345));
  EXPECT_EQ(SquareRoot(1.0), std::sqrt(1.0));
  EXPECT_EQ(SquareRoot(123.45), std::sqrt(123.45));
  EXPECT_EQ(SquareRoot(1.2345e50), std::sqrt(1.2345e50));
}

}  // namespace

}  // namespace PhQ
