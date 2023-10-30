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

#include "../include/PhQ/ShearModulus.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(ShearModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(ShearModulus(1.0, Unit::Pressure::Pascal)
                + ShearModulus(2.0, Unit::Pressure::Pascal),
            ShearModulus(3.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(ShearModulus(8.0, Unit::Pressure::Pascal) / 2.0,
            ShearModulus(4.0, Unit::Pressure::Pascal));

  EXPECT_EQ(ShearModulus(8.0, Unit::Pressure::Pascal)
                / ShearModulus(2.0, Unit::Pressure::Pascal),
            4.0);
}

TEST(ShearModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ShearModulus(4.0, Unit::Pressure::Pascal) * 2.0,
            ShearModulus(8.0, Unit::Pressure::Pascal));

  EXPECT_EQ(2.0 * ShearModulus(4.0, Unit::Pressure::Pascal),
            ShearModulus(8.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ShearModulus(3.0, Unit::Pressure::Pascal)
                - ShearModulus(2.0, Unit::Pressure::Pascal),
            ShearModulus(1.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, AssignmentOperatorAddition) {
  ShearModulus quantity{1.0, Unit::Pressure::Pascal};
  quantity += ShearModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, ShearModulus(3.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, AssignmentOperatorDivision) {
  ShearModulus quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ShearModulus(4.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, AssignmentOperatorMultiplication) {
  ShearModulus quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ShearModulus(8.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, AssignmentOperatorSubtraction) {
  ShearModulus quantity{3.0, Unit::Pressure::Pascal};
  quantity -= ShearModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, ShearModulus(1.0, Unit::Pressure::Pascal));
}

TEST(ShearModulus, ComparisonOperators) {
  const ShearModulus first{1.11, Unit::Pressure::Pascal};
  const ShearModulus second{2.22, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ShearModulus, CopyAssignmentOperator) {
  const ShearModulus first{1.11, Unit::Pressure::Pascal};
  ShearModulus second = ShearModulus::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(ShearModulus, CopyConstructor) {
  const ShearModulus first{1.11, Unit::Pressure::Pascal};
  const ShearModulus second{first};
  EXPECT_EQ(second, first);
}

TEST(ShearModulus, Create) {
  constexpr ShearModulus quantity =
      ShearModulus::Create<Unit::Pressure::Pascal>(1.11);
  EXPECT_EQ(quantity, ShearModulus(1.11, Unit::Pressure::Pascal));
}

TEST(ShearModulus, DefaultConstructor) {
  EXPECT_NO_THROW(ShearModulus{});
}

TEST(ShearModulus, Dimensions) {
  EXPECT_EQ(ShearModulus::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(ShearModulus, Hash) {
  const ShearModulus first{1.11, Unit::Pressure::Kilopascal};
  const ShearModulus second{1.110001, Unit::Pressure::Kilopascal};
  const ShearModulus third{-1.11, Unit::Pressure::Kilopascal};
  const std::hash<ShearModulus> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(ShearModulus, JSON) {
  EXPECT_EQ(ShearModulus(1.11, Unit::Pressure::Pascal).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Pa\"}");
  EXPECT_EQ(ShearModulus(-2.22, Unit::Pressure::Kilopascal)
                .JSON(Unit::Pressure::Kilopascal),
            "{\"value\":-2.220000000000000,\"unit\":\"kPa\"}");
}

TEST(ShearModulus, MoveAssignmentOperator) {
  ShearModulus first{1.11, Unit::Pressure::Pascal};
  ShearModulus second = ShearModulus::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ShearModulus(1.11, Unit::Pressure::Pascal));
}

TEST(ShearModulus, MoveConstructor) {
  ShearModulus first{1.11, Unit::Pressure::Pascal};
  ShearModulus second{std::move(first)};
  EXPECT_EQ(second, ShearModulus(1.11, Unit::Pressure::Pascal));
}

TEST(ShearModulus, MutableValue) {
  ShearModulus quantity{1.11, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ShearModulus, Print) {
  EXPECT_EQ(ShearModulus(1.11, Unit::Pressure::Pascal).Print(),
            "1.110000000000000 Pa");
  EXPECT_EQ(ShearModulus(-2.22, Unit::Pressure::Kilopascal)
                .Print(Unit::Pressure::Kilopascal),
            "-2.220000000000000 kPa");
}

TEST(ShearModulus, SetValue) {
  ShearModulus quantity{1.11, Unit::Pressure::Pascal};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(ShearModulus, SizeOf) {
  EXPECT_EQ(sizeof(ShearModulus{}), sizeof(double));
}

TEST(ShearModulus, StandardConstructor) {
  EXPECT_NO_THROW(ShearModulus(1.11, Unit::Pressure::Kilopascal));
}

TEST(ShearModulus, StaticValue) {
  constexpr ShearModulus quantity =
      ShearModulus::Create<Unit::Pressure::Kilopascal>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.11);
}

TEST(ShearModulus, Stream) {
  std::ostringstream stream;
  stream << ShearModulus(1.11, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), ShearModulus(1.11, Unit::Pressure::Pascal).Print());
}

TEST(ShearModulus, Unit) {
  EXPECT_EQ(ShearModulus::Unit(), Standard<Unit::Pressure>);
}

TEST(ShearModulus, Value) {
  EXPECT_EQ(ShearModulus(1.11, Unit::Pressure::Pascal).Value(), 1.11);
  EXPECT_EQ(ShearModulus(1.11, Unit::Pressure::Kilopascal)
                .Value(Unit::Pressure::Kilopascal),
            1.11);
}

TEST(ShearModulus, XML) {
  EXPECT_EQ(ShearModulus(1.11, Unit::Pressure::Pascal).XML(),
            "<value>1.110000000000000</value><unit>Pa</unit>");
  EXPECT_EQ(ShearModulus(-2.22, Unit::Pressure::Kilopascal)
                .XML(Unit::Pressure::Kilopascal),
            "<value>-2.220000000000000</value><unit>kPa</unit>");
}

TEST(ShearModulus, YAML) {
  EXPECT_EQ(ShearModulus(1.11, Unit::Pressure::Pascal).YAML(),
            "{value:1.110000000000000,unit:\"Pa\"}");
  EXPECT_EQ(ShearModulus(-2.22, Unit::Pressure::Kilopascal)
                .YAML(Unit::Pressure::Kilopascal),
            "{value:-2.220000000000000,unit:\"kPa\"}");
}

TEST(ShearModulus, Zero) {
  EXPECT_EQ(ShearModulus::Zero(), ShearModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ