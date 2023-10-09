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

#include "../include/PhQ/Mass.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(Mass, ArithmeticAddition) {
  EXPECT_EQ(Mass(1.0, Unit::Mass::Kilogram) + Mass(2.0, Unit::Mass::Kilogram),
            Mass(3.0, Unit::Mass::Kilogram));

  Mass quantity{1.0, Unit::Mass::Kilogram};
  quantity += Mass(2.0, Unit::Mass::Kilogram);
  EXPECT_EQ(quantity, Mass(3.0, Unit::Mass::Kilogram));
}

TEST(Mass, ArithmeticDivision) {
  EXPECT_EQ(
      Mass(8.0, Unit::Mass::Kilogram) / 2.0, Mass(4.0, Unit::Mass::Kilogram));

  EXPECT_EQ(
      Mass(8.0, Unit::Mass::Kilogram) / Mass(2.0, Unit::Mass::Kilogram), 4.0);

  Mass quantity{8.0, Unit::Mass::Kilogram};
  quantity /= 2.0;
  EXPECT_EQ(quantity, Mass(4.0, Unit::Mass::Kilogram));
}

TEST(Mass, ArithmeticMultiplication) {
  EXPECT_EQ(
      Mass(4.0, Unit::Mass::Kilogram) * 2.0, Mass(8.0, Unit::Mass::Kilogram));

  EXPECT_EQ(
      2.0 * Mass(4.0, Unit::Mass::Kilogram), Mass(8.0, Unit::Mass::Kilogram));

  Mass quantity{4.0, Unit::Mass::Kilogram};
  quantity *= 2.0;
  EXPECT_EQ(quantity, Mass(8.0, Unit::Mass::Kilogram));
}

TEST(Mass, ArithmeticSubtraction) {
  EXPECT_EQ(Mass(3.0, Unit::Mass::Kilogram) - Mass(2.0, Unit::Mass::Kilogram),
            Mass(1.0, Unit::Mass::Kilogram));

  Mass quantity{3.0, Unit::Mass::Kilogram};
  quantity -= Mass(2.0, Unit::Mass::Kilogram);
  EXPECT_EQ(quantity, Mass(1.0, Unit::Mass::Kilogram));
}

TEST(Mass, Comparisons) {
  const Mass first{0.1, Unit::Mass::Kilogram};
  const Mass second{0.2, Unit::Mass::Kilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Mass, CopyAssignment) {
  const Mass first{1.11, Unit::Mass::Kilogram};
  Mass second = Mass::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Mass, CopyConstructor) {
  const Mass first{1.11, Unit::Mass::Kilogram};
  const Mass second{first};
  EXPECT_EQ(second, first);
}

TEST(Mass, Create) {
  constexpr Mass quantity = Mass::Create<Unit::Mass::Kilogram>(1.11);
  EXPECT_EQ(quantity, Mass(1.11, Unit::Mass::Kilogram));
}

TEST(Mass, DefaultConstructor) {
  EXPECT_NO_THROW(Mass{});
}

TEST(Mass, Dimensions) {
  EXPECT_EQ(Mass::Dimensions(), RelatedDimensions<Unit::Mass>);
}

TEST(Mass, Hash) {
  const Mass first{1.11, Unit::Mass::Gram};
  const Mass second{1.110001, Unit::Mass::Gram};
  const Mass third{-1.11, Unit::Mass::Gram};
  const std::hash<Mass> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Mass, JSON) {
  EXPECT_EQ(Mass(1.11, Unit::Mass::Kilogram).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"kg\"}");
  EXPECT_EQ(Mass(-2.22, Unit::Mass::Gram).JSON(Unit::Mass::Gram),
            "{\"value\":-2.220000000000000,\"unit\":\"g\"}");
}

TEST(Mass, MoveAssignment) {
  Mass first{1.11, Unit::Mass::Kilogram};
  Mass second = Mass::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Mass(1.11, Unit::Mass::Kilogram));
}

TEST(Mass, MoveConstructor) {
  Mass first{1.11, Unit::Mass::Kilogram};
  Mass second{std::move(first)};
  EXPECT_EQ(second, Mass(1.11, Unit::Mass::Kilogram));
}

TEST(Mass, MutableValue) {
  Mass quantity{1.11, Unit::Mass::Kilogram};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Mass, Print) {
  EXPECT_EQ(Mass(1.11, Unit::Mass::Kilogram).Print(), "1.110000000000000 kg");
  EXPECT_EQ(Mass(-2.22, Unit::Mass::Gram).Print(Unit::Mass::Gram),
            "-2.220000000000000 g");
}

TEST(Mass, SetValue) {
  Mass quantity{1.11, Unit::Mass::Kilogram};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(Mass, SizeOf) {
  EXPECT_EQ(sizeof(Mass{}), sizeof(double));
}

TEST(Mass, StandardConstructor) {
  EXPECT_NO_THROW(Mass(1.11, Unit::Mass::Gram));
}

TEST(Mass, StaticValue) {
  constexpr Mass quantity = Mass::Create<Unit::Mass::Gram>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Mass::Gram>();
  EXPECT_EQ(value, 1.11);
}

TEST(Mass, Stream) {
  std::ostringstream stream;
  stream << Mass(1.11, Unit::Mass::Kilogram);
  EXPECT_EQ(stream.str(), Mass(1.11, Unit::Mass::Kilogram).Print());
}

TEST(Mass, Unit) {
  EXPECT_EQ(Mass::Unit(), Standard<Unit::Mass>);
}

TEST(Mass, Value) {
  EXPECT_EQ(Mass(1.11, Unit::Mass::Kilogram).Value(), 1.11);
  EXPECT_EQ(Mass(1.11, Unit::Mass::Gram).Value(Unit::Mass::Gram), 1.11);
}

TEST(Mass, XML) {
  EXPECT_EQ(Mass(1.11, Unit::Mass::Kilogram).XML(),
            "<value>1.110000000000000</value><unit>kg</unit>");
  EXPECT_EQ(Mass(-2.22, Unit::Mass::Gram).XML(Unit::Mass::Gram),
            "<value>-2.220000000000000</value><unit>g</unit>");
}

TEST(Mass, YAML) {
  EXPECT_EQ(Mass(1.11, Unit::Mass::Kilogram).YAML(),
            "{value:1.110000000000000,unit:\"kg\"}");
  EXPECT_EQ(Mass(-2.22, Unit::Mass::Gram).YAML(Unit::Mass::Gram),
            "{value:-2.220000000000000,unit:\"g\"}");
}

TEST(Mass, Zero) {
  EXPECT_EQ(Mass::Zero(), Mass(0.0, Unit::Mass::Kilogram));
}

}  // namespace

}  // namespace PhQ
