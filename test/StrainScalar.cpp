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

#include "../include/PhQ/StrainScalar.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(StrainScalar, ArithmeticAddition) {
  EXPECT_EQ(StrainScalar(1.0) + StrainScalar(2.0), StrainScalar(3.0));

  StrainScalar quantity{1.0};
  quantity += StrainScalar(2.0);
  EXPECT_EQ(quantity, StrainScalar(3.0));
}

TEST(StrainScalar, ArithmeticDivision) {
  EXPECT_EQ(StrainScalar(8.0) / 2.0, StrainScalar(4.0));

  EXPECT_EQ(StrainScalar(8.0) / StrainScalar(2.0), 4.0);

  StrainScalar quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, StrainScalar(4.0));
}

TEST(StrainScalar, ArithmeticMultiplication) {
  EXPECT_EQ(StrainScalar(4.0) * 2.0, StrainScalar(8.0));

  EXPECT_EQ(2.0 * StrainScalar(4.0), StrainScalar(8.0));

  StrainScalar quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, StrainScalar(8.0));
}

TEST(StrainScalar, ArithmeticSubtraction) {
  EXPECT_EQ(StrainScalar(3.0) - StrainScalar(2.0), StrainScalar(1.0));

  StrainScalar quantity{3.0};
  quantity -= StrainScalar(2.0);
  EXPECT_EQ(quantity, StrainScalar(1.0));
}

TEST(StrainScalar, Comparisons) {
  const StrainScalar first{1.11};
  const StrainScalar second{2.22};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(StrainScalar, CopyAssignment) {
  const StrainScalar first{1.11};
  StrainScalar second = StrainScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(StrainScalar, CopyConstructor) {
  const StrainScalar first{1.11};
  const StrainScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(StrainScalar, DefaultConstructor) {
  EXPECT_NO_THROW(StrainScalar{});
}

TEST(StrainScalar, Dimensions) {
  EXPECT_EQ(StrainScalar::Dimensions(), Dimensions{});
}

TEST(StrainScalar, Hash) {
  const StrainScalar first{1.11};
  const StrainScalar second{1.110001};
  const StrainScalar third{-1.11};
  const std::hash<StrainScalar> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(StrainScalar, JSON) {
  EXPECT_EQ(StrainScalar(1.11).JSON(), "1.110000000000000");
}

TEST(StrainScalar, MoveAssignment) {
  const StrainScalar first{1.11};
  StrainScalar second{1.11};
  StrainScalar third = StrainScalar::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(StrainScalar, MoveConstructor) {
  const StrainScalar first{1.11};
  StrainScalar second{1.11};
  StrainScalar third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(StrainScalar, MutableValue) {
  StrainScalar quantity{1.11};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(StrainScalar, Print) {
  EXPECT_EQ(StrainScalar(1.11).Print(), "1.110000000000000");
}

TEST(StrainScalar, SetValue) {
  StrainScalar quantity{1.11};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(StrainScalar, SizeOf) {
  EXPECT_EQ(sizeof(StrainScalar{}), sizeof(double));
}

TEST(StrainScalar, StandardConstructor) {
  EXPECT_NO_THROW(StrainScalar(1.11));
}

TEST(StrainScalar, Stream) {
  const StrainScalar quantity{1.11};
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(StrainScalar, Value) {
  EXPECT_EQ(StrainScalar(1.11).Value(), 1.11);
}

TEST(StrainScalar, XML) {
  EXPECT_EQ(StrainScalar(1.11).XML(), "1.110000000000000");
}

TEST(StrainScalar, YAML) {
  EXPECT_EQ(StrainScalar(1.11).YAML(), "1.110000000000000");
}

TEST(StrainScalar, Zero) {
  EXPECT_EQ(StrainScalar::Zero(), StrainScalar(0.0));
}

}  // namespace

}  // namespace PhQ
