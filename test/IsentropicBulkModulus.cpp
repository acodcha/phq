// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#include "../include/PhQ/IsentropicBulkModulus.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(IsentropicBulkModulus, ArithmeticOperatorAddition) {
  EXPECT_EQ(IsentropicBulkModulus(1.0, Unit::Pressure::Pascal)
                + IsentropicBulkModulus(2.0, Unit::Pressure::Pascal),
            IsentropicBulkModulus(3.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, ArithmeticOperatorDivision) {
  EXPECT_EQ(IsentropicBulkModulus(8.0, Unit::Pressure::Pascal) / 2.0,
            IsentropicBulkModulus(4.0, Unit::Pressure::Pascal));

  EXPECT_EQ(IsentropicBulkModulus(8.0, Unit::Pressure::Pascal)
                / IsentropicBulkModulus(2.0, Unit::Pressure::Pascal),
            4.0);
}

TEST(IsentropicBulkModulus, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(IsentropicBulkModulus(4.0, Unit::Pressure::Pascal) * 2.0,
            IsentropicBulkModulus(8.0, Unit::Pressure::Pascal));

  EXPECT_EQ(2.0 * IsentropicBulkModulus(4.0, Unit::Pressure::Pascal),
            IsentropicBulkModulus(8.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(IsentropicBulkModulus(3.0, Unit::Pressure::Pascal)
                - IsentropicBulkModulus(2.0, Unit::Pressure::Pascal),
            IsentropicBulkModulus(1.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, AssignmentOperatorAddition) {
  IsentropicBulkModulus quantity{1.0, Unit::Pressure::Pascal};
  quantity += IsentropicBulkModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, IsentropicBulkModulus(3.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, AssignmentOperatorDivision) {
  IsentropicBulkModulus quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, IsentropicBulkModulus(4.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, AssignmentOperatorMultiplication) {
  IsentropicBulkModulus quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, IsentropicBulkModulus(8.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, AssignmentOperatorSubtraction) {
  IsentropicBulkModulus quantity{3.0, Unit::Pressure::Pascal};
  quantity -= IsentropicBulkModulus(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, IsentropicBulkModulus(1.0, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, ComparisonOperators) {
  const IsentropicBulkModulus first{1.11, Unit::Pressure::Pascal};
  const IsentropicBulkModulus second{2.22, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(IsentropicBulkModulus, CopyAssignmentOperator) {
  const IsentropicBulkModulus first{1.11, Unit::Pressure::Pascal};
  IsentropicBulkModulus second = IsentropicBulkModulus::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(IsentropicBulkModulus, CopyConstructor) {
  const IsentropicBulkModulus first{1.11, Unit::Pressure::Pascal};
  const IsentropicBulkModulus second{first};
  EXPECT_EQ(second, first);
}

TEST(IsentropicBulkModulus, Create) {
  constexpr IsentropicBulkModulus quantity =
      IsentropicBulkModulus::Create<Unit::Pressure::Pascal>(1.11);
  EXPECT_EQ(quantity, IsentropicBulkModulus(1.11, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, DefaultConstructor) {
  EXPECT_NO_THROW(IsentropicBulkModulus{});
}

TEST(IsentropicBulkModulus, Dimensions) {
  EXPECT_EQ(IsentropicBulkModulus::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(IsentropicBulkModulus, Hash) {
  const IsentropicBulkModulus first{1.11, Unit::Pressure::Kilopascal};
  const IsentropicBulkModulus second{1.110001, Unit::Pressure::Kilopascal};
  const IsentropicBulkModulus third{-1.11, Unit::Pressure::Kilopascal};
  const std::hash<IsentropicBulkModulus> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(IsentropicBulkModulus, JSON) {
  EXPECT_EQ(IsentropicBulkModulus(1.11, Unit::Pressure::Pascal).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Pa\"}");
  EXPECT_EQ(
      IsentropicBulkModulus(-2.22, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
      "{\"value\":-2.220000000000000,\"unit\":\"kPa\"}");
}

TEST(IsentropicBulkModulus, MoveAssignmentOperator) {
  IsentropicBulkModulus first{1.11, Unit::Pressure::Pascal};
  IsentropicBulkModulus second = IsentropicBulkModulus::Zero();
  second = std::move(first);
  EXPECT_EQ(second, IsentropicBulkModulus(1.11, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, MoveConstructor) {
  IsentropicBulkModulus first{1.11, Unit::Pressure::Pascal};
  const IsentropicBulkModulus second{std::move(first)};
  EXPECT_EQ(second, IsentropicBulkModulus(1.11, Unit::Pressure::Pascal));
}

TEST(IsentropicBulkModulus, MutableValue) {
  IsentropicBulkModulus quantity{1.11, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(IsentropicBulkModulus, Print) {
  EXPECT_EQ(IsentropicBulkModulus(1.11, Unit::Pressure::Pascal).Print(), "1.110000000000000 Pa");
  EXPECT_EQ(
      IsentropicBulkModulus(-2.22, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
      "-2.220000000000000 kPa");
}

TEST(IsentropicBulkModulus, SetValue) {
  IsentropicBulkModulus quantity{1.11, Unit::Pressure::Pascal};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(IsentropicBulkModulus, SizeOf) {
  EXPECT_EQ(sizeof(IsentropicBulkModulus{}), sizeof(double));
}

TEST(IsentropicBulkModulus, StandardConstructor) {
  EXPECT_NO_THROW(IsentropicBulkModulus(1.11, Unit::Pressure::Kilopascal));
}

TEST(IsentropicBulkModulus, StaticValue) {
  constexpr IsentropicBulkModulus quantity =
      IsentropicBulkModulus::Create<Unit::Pressure::Kilopascal>(2.0);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 2.0);
}

TEST(IsentropicBulkModulus, Stream) {
  std::ostringstream stream;
  stream << IsentropicBulkModulus(1.11, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), IsentropicBulkModulus(1.11, Unit::Pressure::Pascal).Print());
}

TEST(IsentropicBulkModulus, Unit) {
  EXPECT_EQ(IsentropicBulkModulus::Unit(), Standard<Unit::Pressure>);
}

TEST(IsentropicBulkModulus, Value) {
  EXPECT_EQ(IsentropicBulkModulus(1.11, Unit::Pressure::Pascal).Value(), 1.11);
  EXPECT_EQ(
      IsentropicBulkModulus(2.0, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal),
      2.0);
}

TEST(IsentropicBulkModulus, XML) {
  EXPECT_EQ(IsentropicBulkModulus(1.11, Unit::Pressure::Pascal).XML(),
            "<value>1.110000000000000</value><unit>Pa</unit>");
  EXPECT_EQ(
      IsentropicBulkModulus(-2.22, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
      "<value>-2.220000000000000</value><unit>kPa</unit>");
}

TEST(IsentropicBulkModulus, YAML) {
  EXPECT_EQ(IsentropicBulkModulus(1.11, Unit::Pressure::Pascal).YAML(),
            "{value:1.110000000000000,unit:\"Pa\"}");
  EXPECT_EQ(
      IsentropicBulkModulus(-2.22, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
      "{value:-2.220000000000000,unit:\"kPa\"}");
}

TEST(IsentropicBulkModulus, Zero) {
  EXPECT_EQ(IsentropicBulkModulus::Zero(), IsentropicBulkModulus(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
