// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#include "../include/PhQ/IsothermalBulkModulus.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(IsothermalBulkModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(IsothermalBulkModulus(1.0, Unit::Pressure::Pascal)
                + IsothermalBulkModulus(2.0, Unit::Pressure::Pascal),
            IsothermalBulkModulus(3.0, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(IsothermalBulkModulus(8.0, Unit::Pressure::Pascal) / 2.0,
            IsothermalBulkModulus(4.0, Unit::Pressure::Pascal));

  EXPECT_EQ(IsothermalBulkModulus(8.0, Unit::Pressure::Pascal)
                / IsothermalBulkModulus(2.0, Unit::Pressure::Pascal),
            4.0);
}

TEST(IsothermalBulkModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(IsothermalBulkModulus(4.0, Unit::Pressure::Pascal) * 2.0,
            IsothermalBulkModulus(8.0, Unit::Pressure::Pascal));

  EXPECT_EQ(2.0 * IsothermalBulkModulus(4.0, Unit::Pressure::Pascal),
            IsothermalBulkModulus(8.0, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(IsothermalBulkModulus(3.0, Unit::Pressure::Pascal)
                - IsothermalBulkModulus(2.0, Unit::Pressure::Pascal),
            IsothermalBulkModulus(1.0, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, AssignmentOperatorAddition) {
  IsothermalBulkModulus quantity{1.0, Unit::Pressure::Pascal};
  quantity += IsothermalBulkModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, IsothermalBulkModulus(3.0, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, AssignmentOperatorDivision) {
  IsothermalBulkModulus quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, IsothermalBulkModulus(4.0, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, AssignmentOperatorMultiplication) {
  IsothermalBulkModulus quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, IsothermalBulkModulus(8.0, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, AssignmentOperatorSubtraction) {
  IsothermalBulkModulus quantity{3.0, Unit::Pressure::Pascal};
  quantity -= IsothermalBulkModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, IsothermalBulkModulus(1.0, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, ComparisonOperators) {
  const IsothermalBulkModulus first{1.11, Unit::Pressure::Pascal};
  const IsothermalBulkModulus second{2.22, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(IsothermalBulkModulus, CopyAssignmentOperator) {
  const IsothermalBulkModulus first{1.11, Unit::Pressure::Pascal};
  IsothermalBulkModulus second = IsothermalBulkModulus::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(IsothermalBulkModulus, CopyConstructor) {
  const IsothermalBulkModulus first{1.11, Unit::Pressure::Pascal};
  const IsothermalBulkModulus second{first};
  EXPECT_EQ(second, first);
}

TEST(IsothermalBulkModulus, Create) {
  constexpr IsothermalBulkModulus quantity =
      IsothermalBulkModulus::Create<Unit::Pressure::Pascal>(1.11);
  EXPECT_EQ(quantity, IsothermalBulkModulus(1.11, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, DefaultConstructor) {
  EXPECT_NO_THROW(IsothermalBulkModulus{});
}

TEST(IsothermalBulkModulus, Dimensions) {
  EXPECT_EQ(IsothermalBulkModulus::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(IsothermalBulkModulus, Hash) {
  const IsothermalBulkModulus first{1.11, Unit::Pressure::Kilopascal};
  const IsothermalBulkModulus second{1.110001, Unit::Pressure::Kilopascal};
  const IsothermalBulkModulus third{-1.11, Unit::Pressure::Kilopascal};
  const std::hash<IsothermalBulkModulus> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(IsothermalBulkModulus, JSON) {
  EXPECT_EQ(IsothermalBulkModulus(1.11, Unit::Pressure::Pascal).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Pa\"}");
  EXPECT_EQ(
      IsothermalBulkModulus(-2.22, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
      "{\"value\":-2.220000000000000,\"unit\":\"kPa\"}");
}

TEST(IsothermalBulkModulus, MoveAssignmentOperator) {
  IsothermalBulkModulus first{1.11, Unit::Pressure::Pascal};
  IsothermalBulkModulus second = IsothermalBulkModulus::Zero();
  second = std::move(first);
  EXPECT_EQ(second, IsothermalBulkModulus(1.11, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, MoveConstructor) {
  IsothermalBulkModulus first{1.11, Unit::Pressure::Pascal};
  const IsothermalBulkModulus second{std::move(first)};
  EXPECT_EQ(second, IsothermalBulkModulus(1.11, Unit::Pressure::Pascal));
}

TEST(IsothermalBulkModulus, MutableValue) {
  IsothermalBulkModulus quantity{1.11, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(IsothermalBulkModulus, Print) {
  EXPECT_EQ(IsothermalBulkModulus(1.11, Unit::Pressure::Pascal).Print(), "1.110000000000000 Pa");
  EXPECT_EQ(
      IsothermalBulkModulus(-2.22, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
      "-2.220000000000000 kPa");
}

TEST(IsothermalBulkModulus, SetValue) {
  IsothermalBulkModulus quantity{1.11, Unit::Pressure::Pascal};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(IsothermalBulkModulus, SizeOf) {
  EXPECT_EQ(sizeof(IsothermalBulkModulus{}), sizeof(double));
}

TEST(IsothermalBulkModulus, StandardConstructor) {
  EXPECT_NO_THROW(IsothermalBulkModulus(1.11, Unit::Pressure::Kilopascal));
}

TEST(IsothermalBulkModulus, StaticValue) {
  constexpr IsothermalBulkModulus quantity =
      IsothermalBulkModulus::Create<Unit::Pressure::Kilopascal>(2.0);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 2.0);
}

TEST(IsothermalBulkModulus, Stream) {
  std::ostringstream stream;
  stream << IsothermalBulkModulus(1.11, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), IsothermalBulkModulus(1.11, Unit::Pressure::Pascal).Print());
}

TEST(IsothermalBulkModulus, Unit) {
  EXPECT_EQ(IsothermalBulkModulus::Unit(), Standard<Unit::Pressure>);
}

TEST(IsothermalBulkModulus, Value) {
  EXPECT_EQ(IsothermalBulkModulus(1.11, Unit::Pressure::Pascal).Value(), 1.11);
  EXPECT_EQ(
      IsothermalBulkModulus(2.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal),
      2.0);
}

TEST(IsothermalBulkModulus, XML) {
  EXPECT_EQ(IsothermalBulkModulus(1.11, Unit::Pressure::Pascal).XML(),
            "<value>1.110000000000000</value><unit>Pa</unit>");
  EXPECT_EQ(
      IsothermalBulkModulus(-2.22, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
      "<value>-2.220000000000000</value><unit>kPa</unit>");
}

TEST(IsothermalBulkModulus, YAML) {
  EXPECT_EQ(IsothermalBulkModulus(1.11, Unit::Pressure::Pascal).YAML(),
            "{value:1.110000000000000,unit:\"Pa\"}");
  EXPECT_EQ(
      IsothermalBulkModulus(-2.22, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
      "{value:-2.220000000000000,unit:\"kPa\"}");
}

TEST(IsothermalBulkModulus, Zero) {
  EXPECT_EQ(IsothermalBulkModulus::Zero(), IsothermalBulkModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
