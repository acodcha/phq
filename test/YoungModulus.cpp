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

#include "../include/PhQ/YoungModulus.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(YoungModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(YoungModulus(1.0, Unit::Pressure::Pascal)
                + YoungModulus(2.0, Unit::Pressure::Pascal),
            YoungModulus(3.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(YoungModulus(8.0, Unit::Pressure::Pascal) / 2.0,
            YoungModulus(4.0, Unit::Pressure::Pascal));

  EXPECT_EQ(YoungModulus(8.0, Unit::Pressure::Pascal)
                / YoungModulus(2.0, Unit::Pressure::Pascal),
            4.0);
}

TEST(YoungModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(YoungModulus(4.0, Unit::Pressure::Pascal) * 2.0,
            YoungModulus(8.0, Unit::Pressure::Pascal));

  EXPECT_EQ(2.0 * YoungModulus(4.0, Unit::Pressure::Pascal),
            YoungModulus(8.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(YoungModulus(3.0, Unit::Pressure::Pascal)
                - YoungModulus(2.0, Unit::Pressure::Pascal),
            YoungModulus(1.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, AssignmentOperatorAddition) {
  YoungModulus quantity{1.0, Unit::Pressure::Pascal};
  quantity += YoungModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, YoungModulus(3.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, AssignmentOperatorDivision) {
  YoungModulus quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, YoungModulus(4.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, AssignmentOperatorMultiplication) {
  YoungModulus quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, YoungModulus(8.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, AssignmentOperatorSubtraction) {
  YoungModulus quantity{3.0, Unit::Pressure::Pascal};
  quantity -= YoungModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, YoungModulus(1.0, Unit::Pressure::Pascal));
}

TEST(YoungModulus, ComparisonOperators) {
  const YoungModulus first{1.11, Unit::Pressure::Pascal};
  const YoungModulus second{2.22, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(YoungModulus, CopyAssignmentOperator) {
  const YoungModulus first{1.11, Unit::Pressure::Pascal};
  YoungModulus second = YoungModulus::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(YoungModulus, CopyConstructor) {
  const YoungModulus first{1.11, Unit::Pressure::Pascal};
  const YoungModulus second{first};
  EXPECT_EQ(second, first);
}

TEST(YoungModulus, Create) {
  constexpr YoungModulus quantity =
      YoungModulus::Create<Unit::Pressure::Pascal>(1.11);
  EXPECT_EQ(quantity, YoungModulus(1.11, Unit::Pressure::Pascal));
}

TEST(YoungModulus, DefaultConstructor) {
  EXPECT_NO_THROW(YoungModulus{});
}

TEST(YoungModulus, Dimensions) {
  EXPECT_EQ(YoungModulus::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(YoungModulus, Hash) {
  const YoungModulus first{1.11, Unit::Pressure::Kilopascal};
  const YoungModulus second{1.110001, Unit::Pressure::Kilopascal};
  const YoungModulus third{-1.11, Unit::Pressure::Kilopascal};
  const std::hash<YoungModulus> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(YoungModulus, JSON) {
  EXPECT_EQ(YoungModulus(1.11, Unit::Pressure::Pascal).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Pa\"}");
  EXPECT_EQ(YoungModulus(-2.22, Unit::Pressure::Kilopascal)
                .JSON(Unit::Pressure::Kilopascal),
            "{\"value\":-2.220000000000000,\"unit\":\"kPa\"}");
}

TEST(YoungModulus, MoveAssignmentOperator) {
  YoungModulus first{1.11, Unit::Pressure::Pascal};
  YoungModulus second = YoungModulus::Zero();
  second = std::move(first);
  EXPECT_EQ(second, YoungModulus(1.11, Unit::Pressure::Pascal));
}

TEST(YoungModulus, MoveConstructor) {
  YoungModulus first{1.11, Unit::Pressure::Pascal};
  YoungModulus second{std::move(first)};
  EXPECT_EQ(second, YoungModulus(1.11, Unit::Pressure::Pascal));
}

TEST(YoungModulus, MutableValue) {
  YoungModulus quantity{1.11, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(YoungModulus, Print) {
  EXPECT_EQ(YoungModulus(1.11, Unit::Pressure::Pascal).Print(),
            "1.110000000000000 Pa");
  EXPECT_EQ(YoungModulus(-2.22, Unit::Pressure::Kilopascal)
                .Print(Unit::Pressure::Kilopascal),
            "-2.220000000000000 kPa");
}

TEST(YoungModulus, SetValue) {
  YoungModulus quantity{1.11, Unit::Pressure::Pascal};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(YoungModulus, SizeOf) {
  EXPECT_EQ(sizeof(YoungModulus{}), sizeof(double));
}

TEST(YoungModulus, StandardConstructor) {
  EXPECT_NO_THROW(YoungModulus(1.11, Unit::Pressure::Kilopascal));
}

TEST(YoungModulus, StaticValue) {
  constexpr YoungModulus quantity =
      YoungModulus::Create<Unit::Pressure::Kilopascal>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.11);
}

TEST(YoungModulus, Stream) {
  std::ostringstream stream;
  stream << YoungModulus(1.11, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), YoungModulus(1.11, Unit::Pressure::Pascal).Print());
}

TEST(YoungModulus, Unit) {
  EXPECT_EQ(YoungModulus::Unit(), Standard<Unit::Pressure>);
}

TEST(YoungModulus, Value) {
  EXPECT_EQ(YoungModulus(1.11, Unit::Pressure::Pascal).Value(), 1.11);
  EXPECT_EQ(YoungModulus(1.11, Unit::Pressure::Kilopascal)
                .Value(Unit::Pressure::Kilopascal),
            1.11);
}

TEST(YoungModulus, XML) {
  EXPECT_EQ(YoungModulus(1.11, Unit::Pressure::Pascal).XML(),
            "<value>1.110000000000000</value><unit>Pa</unit>");
  EXPECT_EQ(YoungModulus(-2.22, Unit::Pressure::Kilopascal)
                .XML(Unit::Pressure::Kilopascal),
            "<value>-2.220000000000000</value><unit>kPa</unit>");
}

TEST(YoungModulus, YAML) {
  EXPECT_EQ(YoungModulus(1.11, Unit::Pressure::Pascal).YAML(),
            "{value:1.110000000000000,unit:\"Pa\"}");
  EXPECT_EQ(YoungModulus(-2.22, Unit::Pressure::Kilopascal)
                .YAML(Unit::Pressure::Kilopascal),
            "{value:-2.220000000000000,unit:\"kPa\"}");
}

TEST(YoungModulus, Zero) {
  EXPECT_EQ(YoungModulus::Zero(), YoungModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
