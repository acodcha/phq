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

#include "../include/PhQ/Strain.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Strain, ArithmeticAddition) {
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0)
                + Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            Strain(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));

  Strain quantity(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  quantity += Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  EXPECT_EQ(quantity, Strain(3.0, -6.0, 9.0, -12.0, 15.0, -18.0));
}

TEST(Strain, ArithmeticDivision) {
  EXPECT_EQ(Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0) / 2.0,
            Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));

  Strain quantity(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  quantity /= 2.0;
  EXPECT_EQ(quantity, Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, ArithmeticMultiplication) {
  EXPECT_EQ(Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0) * 2.0,
            Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));

  EXPECT_EQ(2.0 * Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0),
            Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));

  Strain quantity(1.0, -2.0, 3.0, -4.0, 5.0, -6.0);
  quantity *= 2.0;
  EXPECT_EQ(quantity, Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0));
}

TEST(Strain, ArithmeticSubtraction) {
  EXPECT_EQ(Strain(3.0, -6.0, 9.0, -12.0, 15.0, -18.0)
                - Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0),
            Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));

  Strain quantity(3.0, -6.0, 9.0, -12.0, 15.0, -18.0);
  quantity -= Strain(2.0, -4.0, 6.0, -8.0, 10.0, -12.0);
  EXPECT_EQ(quantity, Strain(1.0, -2.0, 3.0, -4.0, 5.0, -6.0));
}

TEST(Strain, Comparisons) {
  constexpr Strain first(1.11, -2.22, 3.33, -4.44, 5.55, -6.660001);
  constexpr Strain second(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Strain, CopyAssignment) {
  constexpr Strain first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  Strain second = Strain::Zero();
  second = first;
  EXPECT_EQ(second, Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(Strain, CopyConstructor) {
  constexpr Strain first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  constexpr Strain second{first};
  EXPECT_EQ(second, Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(Strain, DefaultConstructor) {
  EXPECT_NO_THROW(Strain{});
}

TEST(Strain, Dimensions) {
  EXPECT_EQ(Strain::Dimensions(), Dimensions());
}

TEST(Strain, Hash) {
  constexpr Strain first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  constexpr Strain second(1.11, -2.22, 3.33, -4.44, 5.55, -6.660001);
  constexpr Strain third(1.11, -2.22, 3.33, 4.44, 5.55, -6.66);
  const std::hash<Strain> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Strain, JSON) {
  EXPECT_EQ(Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66).JSON(),
            "{\"xx\":1.110000000000000,\"xy\":-2.220000000000000,\"xz\":3."
            "330000000000000,\"yy\":-4.440000000000000,\"yz\":5."
            "550000000000000,\"zz\":-6.660000000000000}");
}

TEST(Strain, MoveAssignment) {
  Strain first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  Strain second = Strain::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(Strain, MoveConstructor) {
  Strain first(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  Strain second{std::move(first)};
  EXPECT_EQ(second, Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(Strain, MutableValue) {
  Strain quantity(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  Value::SymmetricDyad& value = quantity.MutableValue();
  value = Value::SymmetricDyad{-7.77, 8.88, -9.99, 10.10, -11.11, 12.12};
  EXPECT_EQ(quantity.Value(),
            Value::SymmetricDyad(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12));
}

TEST(Strain, Print) {
  EXPECT_EQ(Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66).Print(),
            "(1.110000000000000, -2.220000000000000, 3.330000000000000; "
            "-4.440000000000000, 5.550000000000000; -6.660000000000000)");
}

TEST(Strain, SetValue) {
  Strain quantity(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  quantity.SetValue(
      Value::SymmetricDyad(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12));
  EXPECT_EQ(quantity.Value(),
            Value::SymmetricDyad(-7.77, 8.88, -9.99, 10.10, -11.11, 12.12));
}

TEST(Strain, SizeOf) {
  EXPECT_EQ(sizeof(Strain{}), 6 * sizeof(double));
}

TEST(Strain, StandardConstructor) {
  constexpr std::array<double, 6> array{1.11, -2.22, 3.33, -4.44, 5.55, -6.66};
  EXPECT_EQ(Strain(array), Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));

  std::array<double, 6> movable_array{1.11, -2.22, 3.33, -4.44, 5.55, -6.66};
  EXPECT_EQ(Strain(std::move(movable_array)),
            Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));

  constexpr Value::SymmetricDyad value{1.11, -2.22, 3.33, -4.44, 5.55, -6.66};
  EXPECT_EQ(Strain(value), Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));

  Value::SymmetricDyad movable_value{1.11, -2.22, 3.33, -4.44, 5.55, -6.66};
  EXPECT_EQ(Strain(std::move(movable_value)),
            Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(Strain, Stream) {
  std::ostringstream stream;
  stream << Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66);
  EXPECT_EQ(
      stream.str(), Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66).Print());
}

TEST(Strain, Value) {
  EXPECT_EQ(Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66).Value(),
            Value::SymmetricDyad(1.11, -2.22, 3.33, -4.44, 5.55, -6.66));
}

TEST(Strain, XML) {
  EXPECT_EQ(Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66).XML(),
            "<xx>1.110000000000000</xx><xy>-2.220000000000000</"
            "xy><xz>3.330000000000000</xz><yy>-4.440000000000000</"
            "yy><yz>5.550000000000000</yz><zz>-6.660000000000000</zz>");
}

TEST(Strain, YAML) {
  EXPECT_EQ(Strain(1.11, -2.22, 3.33, -4.44, 5.55, -6.66).YAML(),
            "{xx:1.110000000000000,xy:-2.220000000000000,xz:3.330000000000000,"
            "yy:-4.440000000000000,yz:5.550000000000000,zz:-6."
            "660000000000000}");
}

TEST(Strain, Zero) {
  EXPECT_EQ(Strain::Zero(), Strain(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
}

}  // namespace

}  // namespace PhQ
