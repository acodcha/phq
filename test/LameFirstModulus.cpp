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

#include "../include/PhQ/LameFirstModulus.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(LameFirstModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(LameFirstModulus(1.0, Unit::Pressure::Pascal)
                + LameFirstModulus(2.0, Unit::Pressure::Pascal),
            LameFirstModulus(3.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(LameFirstModulus(8.0, Unit::Pressure::Pascal) / 2.0,
            LameFirstModulus(4.0, Unit::Pressure::Pascal));

  EXPECT_EQ(LameFirstModulus(8.0, Unit::Pressure::Pascal)
                / LameFirstModulus(2.0, Unit::Pressure::Pascal),
            4.0);
}

TEST(LameFirstModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(LameFirstModulus(4.0, Unit::Pressure::Pascal) * 2.0,
            LameFirstModulus(8.0, Unit::Pressure::Pascal));

  EXPECT_EQ(2.0 * LameFirstModulus(4.0, Unit::Pressure::Pascal),
            LameFirstModulus(8.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(LameFirstModulus(3.0, Unit::Pressure::Pascal)
                - LameFirstModulus(2.0, Unit::Pressure::Pascal),
            LameFirstModulus(1.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, AssignmentOperatorAddition) {
  LameFirstModulus quantity{1.0, Unit::Pressure::Pascal};
  quantity += LameFirstModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, LameFirstModulus(3.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, AssignmentOperatorDivision) {
  LameFirstModulus quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, LameFirstModulus(4.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, AssignmentOperatorMultiplication) {
  LameFirstModulus quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, LameFirstModulus(8.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, AssignmentOperatorSubtraction) {
  LameFirstModulus quantity{3.0, Unit::Pressure::Pascal};
  quantity -= LameFirstModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, LameFirstModulus(1.0, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, ComparisonOperators) {
  const LameFirstModulus first{0.1, Unit::Pressure::Pascal};
  const LameFirstModulus second{0.2, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(LameFirstModulus, CopyAssignmentOperator) {
  const LameFirstModulus first{1.11, Unit::Pressure::Pascal};
  LameFirstModulus second = LameFirstModulus::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(LameFirstModulus, CopyConstructor) {
  const LameFirstModulus first{1.11, Unit::Pressure::Pascal};
  const LameFirstModulus second{first};
  EXPECT_EQ(second, first);
}

TEST(LameFirstModulus, Create) {
  constexpr LameFirstModulus quantity =
      LameFirstModulus::Create<Unit::Pressure::Pascal>(1.11);
  EXPECT_EQ(quantity, LameFirstModulus(1.11, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, DefaultConstructor) {
  EXPECT_NO_THROW(LameFirstModulus{});
}

TEST(LameFirstModulus, Dimensions) {
  EXPECT_EQ(LameFirstModulus::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(LameFirstModulus, Hash) {
  const LameFirstModulus first{1.11, Unit::Pressure::Kilopascal};
  const LameFirstModulus second{1.110001, Unit::Pressure::Kilopascal};
  const LameFirstModulus third{-1.11, Unit::Pressure::Kilopascal};
  const std::hash<LameFirstModulus> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(LameFirstModulus, JSON) {
  EXPECT_EQ(LameFirstModulus(1.11, Unit::Pressure::Pascal).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Pa\"}");
  EXPECT_EQ(LameFirstModulus(-2.22, Unit::Pressure::Kilopascal)
                .JSON(Unit::Pressure::Kilopascal),
            "{\"value\":-2.220000000000000,\"unit\":\"kPa\"}");
}

TEST(LameFirstModulus, MoveAssignmentOperator) {
  LameFirstModulus first{1.11, Unit::Pressure::Pascal};
  LameFirstModulus second = LameFirstModulus::Zero();
  second = std::move(first);
  EXPECT_EQ(second, LameFirstModulus(1.11, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, MoveConstructor) {
  LameFirstModulus first{1.11, Unit::Pressure::Pascal};
  LameFirstModulus second{std::move(first)};
  EXPECT_EQ(second, LameFirstModulus(1.11, Unit::Pressure::Pascal));
}

TEST(LameFirstModulus, MutableValue) {
  LameFirstModulus quantity{1.11, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(LameFirstModulus, Print) {
  EXPECT_EQ(LameFirstModulus(1.11, Unit::Pressure::Pascal).Print(),
            "1.110000000000000 Pa");
  EXPECT_EQ(LameFirstModulus(-2.22, Unit::Pressure::Kilopascal)
                .Print(Unit::Pressure::Kilopascal),
            "-2.220000000000000 kPa");
}

TEST(LameFirstModulus, SetValue) {
  LameFirstModulus quantity{1.11, Unit::Pressure::Pascal};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(LameFirstModulus, SizeOf) {
  EXPECT_EQ(sizeof(LameFirstModulus{}), sizeof(double));
}

TEST(LameFirstModulus, StandardConstructor) {
  EXPECT_NO_THROW(LameFirstModulus(1.11, Unit::Pressure::Kilopascal));
}

TEST(LameFirstModulus, StaticValue) {
  constexpr LameFirstModulus quantity =
      LameFirstModulus::Create<Unit::Pressure::Kilopascal>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.11);
}

TEST(LameFirstModulus, Stream) {
  std::ostringstream stream;
  stream << LameFirstModulus(1.11, Unit::Pressure::Pascal);
  EXPECT_EQ(
      stream.str(), LameFirstModulus(1.11, Unit::Pressure::Pascal).Print());
}

TEST(LameFirstModulus, Unit) {
  EXPECT_EQ(LameFirstModulus::Unit(), Standard<Unit::Pressure>);
}

TEST(LameFirstModulus, Value) {
  EXPECT_EQ(LameFirstModulus(1.11, Unit::Pressure::Pascal).Value(), 1.11);
  EXPECT_EQ(LameFirstModulus(1.11, Unit::Pressure::Kilopascal)
                .Value(Unit::Pressure::Kilopascal),
            1.11);
}

TEST(LameFirstModulus, XML) {
  EXPECT_EQ(LameFirstModulus(1.11, Unit::Pressure::Pascal).XML(),
            "<value>1.110000000000000</value><unit>Pa</unit>");
  EXPECT_EQ(LameFirstModulus(-2.22, Unit::Pressure::Kilopascal)
                .XML(Unit::Pressure::Kilopascal),
            "<value>-2.220000000000000</value><unit>kPa</unit>");
}

TEST(LameFirstModulus, YAML) {
  EXPECT_EQ(LameFirstModulus(1.11, Unit::Pressure::Pascal).YAML(),
            "{value:1.110000000000000,unit:\"Pa\"}");
  EXPECT_EQ(LameFirstModulus(-2.22, Unit::Pressure::Kilopascal)
                .YAML(Unit::Pressure::Kilopascal),
            "{value:-2.220000000000000,unit:\"kPa\"}");
}

TEST(LameFirstModulus, Zero) {
  EXPECT_EQ(
      LameFirstModulus::Zero(), LameFirstModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
