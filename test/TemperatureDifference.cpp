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

#include "../include/PhQ/TemperatureDifference.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(TemperatureDifference, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin)
          + TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
      TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin) / 2.0,
      TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin));

  EXPECT_EQ(
      TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin)
          / TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
      4.0);
}

TEST(TemperatureDifference, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin) * 2.0,
      TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));

  EXPECT_EQ(
      2.0 * TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin),
      TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin)
          - TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
      TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorAddition) {
  TemperatureDifference quantity{1.0, Unit::TemperatureDifference::Kelvin};
  quantity += TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(quantity,
            TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorDivision) {
  TemperatureDifference quantity{8.0, Unit::TemperatureDifference::Kelvin};
  quantity /= 2.0;
  EXPECT_EQ(quantity,
            TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorMultiplication) {
  TemperatureDifference quantity{4.0, Unit::TemperatureDifference::Kelvin};
  quantity *= 2.0;
  EXPECT_EQ(quantity,
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorSubtraction) {
  TemperatureDifference quantity{3.0, Unit::TemperatureDifference::Kelvin};
  quantity -= TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(quantity,
            TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, ComparisonOperators) {
  const TemperatureDifference first{0.1, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{0.2, Unit::TemperatureDifference::Kelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TemperatureDifference, CopyAssignmentOperator) {
  const TemperatureDifference first{1.11, Unit::TemperatureDifference::Kelvin};
  TemperatureDifference second = TemperatureDifference::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(TemperatureDifference, CopyConstructor) {
  const TemperatureDifference first{1.11, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{first};
  EXPECT_EQ(second, first);
}

TEST(TemperatureDifference, Create) {
  constexpr TemperatureDifference quantity =
      TemperatureDifference::Create<Unit::TemperatureDifference::Kelvin>(1.11);
  EXPECT_EQ(quantity,
            TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, DefaultConstructor) {
  EXPECT_NO_THROW(TemperatureDifference{});
}

TEST(TemperatureDifference, Dimensions) {
  EXPECT_EQ(TemperatureDifference::Dimensions(),
            RelatedDimensions<Unit::TemperatureDifference>);
}

TEST(TemperatureDifference, Hash) {
  const TemperatureDifference first{1.11, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{
      1.110001, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference third{-1.11, Unit::TemperatureDifference::Kelvin};
  const std::hash<TemperatureDifference> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(TemperatureDifference, JSON) {
  EXPECT_EQ(
      TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin).JSON(),
      "{\"value\":1.110000000000000,\"unit\":\"K\"}");
  EXPECT_EQ(TemperatureDifference(-2.22, Unit::TemperatureDifference::Rankine)
                .JSON(Unit::TemperatureDifference::Rankine),
            "{\"value\":-2.220000000000000,\"unit\":\"°R\"}");
}

TEST(TemperatureDifference, MoveAssignmentOperator) {
  TemperatureDifference first{1.11, Unit::TemperatureDifference::Kelvin};
  TemperatureDifference second = TemperatureDifference::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, MoveConstructor) {
  TemperatureDifference first{1.11, Unit::TemperatureDifference::Kelvin};
  TemperatureDifference second{std::move(first)};
  EXPECT_EQ(
      second, TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, MutableValue) {
  TemperatureDifference quantity{1.11, Unit::TemperatureDifference::Kelvin};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(TemperatureDifference, Print) {
  EXPECT_EQ(
      TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin).Print(),
      "1.110000000000000 K");
  EXPECT_EQ(TemperatureDifference(-2.22, Unit::TemperatureDifference::Rankine)
                .Print(Unit::TemperatureDifference::Rankine),
            "-2.220000000000000 °R");
}

TEST(TemperatureDifference, SetValue) {
  TemperatureDifference quantity{1.11, Unit::TemperatureDifference::Kelvin};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(TemperatureDifference, SizeOf) {
  EXPECT_EQ(sizeof(TemperatureDifference{}), sizeof(double));
}

TEST(TemperatureDifference, StandardConstructor) {
  EXPECT_NO_THROW(
      TemperatureDifference(1.11, Unit::TemperatureDifference::Rankine));
}

TEST(TemperatureDifference, StaticValue) {
  constexpr TemperatureDifference quantity =
      TemperatureDifference::Create<Unit::TemperatureDifference::Rankine>(1.11);
  constexpr double value =
      quantity.StaticValue<Unit::TemperatureDifference::Rankine>();
  EXPECT_EQ(value, 1.11);
}

TEST(TemperatureDifference, Stream) {
  std::ostringstream stream;
  stream << TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(
      stream.str(),
      TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin).Print());
}

TEST(TemperatureDifference, Unit) {
  EXPECT_EQ(
      TemperatureDifference::Unit(), Standard<Unit::TemperatureDifference>);
}

TEST(TemperatureDifference, Value) {
  EXPECT_EQ(
      TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin).Value(),
      1.11);
  EXPECT_EQ(TemperatureDifference(1.11, Unit::TemperatureDifference::Rankine)
                .Value(Unit::TemperatureDifference::Rankine),
            1.11);
}

TEST(TemperatureDifference, XML) {
  EXPECT_EQ(
      TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin).XML(),
      "<value>1.110000000000000</value><unit>K</unit>");
  EXPECT_EQ(TemperatureDifference(-2.22, Unit::TemperatureDifference::Rankine)
                .XML(Unit::TemperatureDifference::Rankine),
            "<value>-2.220000000000000</value><unit>°R</unit>");
}

TEST(TemperatureDifference, YAML) {
  EXPECT_EQ(
      TemperatureDifference(1.11, Unit::TemperatureDifference::Kelvin).YAML(),
      "{value:1.110000000000000,unit:\"K\"}");
  EXPECT_EQ(TemperatureDifference(-2.22, Unit::TemperatureDifference::Rankine)
                .YAML(Unit::TemperatureDifference::Rankine),
            "{value:-2.220000000000000,unit:\"°R\"}");
}

TEST(TemperatureDifference, Zero) {
  EXPECT_EQ(TemperatureDifference::Zero(),
            TemperatureDifference(0.0, Unit::TemperatureDifference::Kelvin));
}

}  // namespace

}  // namespace PhQ
