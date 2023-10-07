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

#include "../include/PhQ/PoissonRatio.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(PoissonRatio, ArithmeticAddition) {
  EXPECT_EQ(PoissonRatio(1.0) + PoissonRatio(2.0), PoissonRatio(3.0));

  PoissonRatio quantity{1.0};
  quantity += PoissonRatio(2.0);
  EXPECT_EQ(quantity, PoissonRatio(3.0));
}

TEST(PoissonRatio, ArithmeticDivision) {
  EXPECT_EQ(PoissonRatio(8.0) / 2.0, PoissonRatio(4.0));

  EXPECT_EQ(PoissonRatio(8.0) / PoissonRatio(2.0), 4.0);

  PoissonRatio quantity{8.0};
  quantity /= 2.0;
  EXPECT_EQ(quantity, PoissonRatio(4.0));
}

TEST(PoissonRatio, ArithmeticMultiplication) {
  EXPECT_EQ(PoissonRatio(4.0) * 2.0, PoissonRatio(8.0));

  EXPECT_EQ(2.0 * PoissonRatio(4.0), PoissonRatio(8.0));

  PoissonRatio quantity{4.0};
  quantity *= 2.0;
  EXPECT_EQ(quantity, PoissonRatio(8.0));
}

TEST(PoissonRatio, ArithmeticSubtraction) {
  EXPECT_EQ(PoissonRatio(3.0) - PoissonRatio(2.0), PoissonRatio(1.0));

  PoissonRatio quantity{3.0};
  quantity -= PoissonRatio(2.0);
  EXPECT_EQ(quantity, PoissonRatio(1.0));
}

TEST(PoissonRatio, Comparisons) {
  const PoissonRatio first{1.11};
  const PoissonRatio second{2.22};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PoissonRatio, CopyAssignment) {
  const PoissonRatio first{1.11};
  PoissonRatio second = PoissonRatio::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(PoissonRatio, CopyConstructor) {
  const PoissonRatio first{1.11};
  const PoissonRatio second{first};
  EXPECT_EQ(second, first);
}

TEST(PoissonRatio, DefaultConstructor) {
  EXPECT_NO_THROW(PoissonRatio{});
}

TEST(PoissonRatio, Dimensions) {
  EXPECT_EQ(PoissonRatio::Dimensions(), Dimensions{});
}

TEST(PoissonRatio, Hash) {
  const PoissonRatio first{1.11};
  const PoissonRatio second{1.110001};
  const PoissonRatio third{-1.11};
  const std::hash<PoissonRatio> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PoissonRatio, JSON) {
  EXPECT_EQ(PoissonRatio(1.11).JSON(), "1.110000000000000");
}

TEST(PoissonRatio, MoveAssignment) {
  const PoissonRatio first{1.11};
  PoissonRatio second{1.11};
  PoissonRatio third = PoissonRatio::Zero();
  third = std::move(second);
  EXPECT_EQ(third, first);
}

TEST(PoissonRatio, MoveConstructor) {
  const PoissonRatio first{1.11};
  PoissonRatio second{1.11};
  PoissonRatio third{std::move(second)};
  EXPECT_EQ(third, first);
}

TEST(PoissonRatio, MutableValue) {
  PoissonRatio quantity{1.11};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(PoissonRatio, Print) {
  EXPECT_EQ(PoissonRatio(1.11).Print(), "1.110000000000000");
}

TEST(PoissonRatio, SetValue) {
  PoissonRatio quantity{1.11};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(PoissonRatio, SizeOf) {
  EXPECT_EQ(sizeof(PoissonRatio{}), sizeof(double));
}

TEST(PoissonRatio, StandardConstructor) {
  EXPECT_NO_THROW(PoissonRatio(1.11));
}

TEST(PoissonRatio, Stream) {
  const PoissonRatio quantity{1.11};
  std::ostringstream stream;
  stream << quantity;
  EXPECT_EQ(stream.str(), quantity.Print());
}

TEST(PoissonRatio, Value) {
  EXPECT_EQ(PoissonRatio(1.11).Value(), 1.11);
}

TEST(PoissonRatio, XML) {
  EXPECT_EQ(PoissonRatio(1.11).XML(), "1.110000000000000");
}

TEST(PoissonRatio, YAML) {
  EXPECT_EQ(PoissonRatio(1.11).YAML(), "1.110000000000000");
}

TEST(PoissonRatio, Zero) {
  EXPECT_EQ(PoissonRatio::Zero(), PoissonRatio(0.0));
}

}  // namespace

}  // namespace PhQ
