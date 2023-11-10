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

#include "../include/PhQ/StressScalar.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Pressure.hpp"

namespace PhQ {

namespace {

TEST(StressScalar, ArithmeticOperatorAddition) {
  EXPECT_EQ(StressScalar(1.0, Unit::Pressure::Pascal) + StressScalar(2.0, Unit::Pressure::Pascal),
            StressScalar(3.0, Unit::Pressure::Pascal));
}

TEST(StressScalar, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      StressScalar(8.0, Unit::Pressure::Pascal) / 2.0, StressScalar(4.0, Unit::Pressure::Pascal));

  EXPECT_EQ(
      StressScalar(8.0, Unit::Pressure::Pascal) / StressScalar(2.0, Unit::Pressure::Pascal), 4.0);
}

TEST(StressScalar, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      StressScalar(4.0, Unit::Pressure::Pascal) * 2.0, StressScalar(8.0, Unit::Pressure::Pascal));

  EXPECT_EQ(
      2.0 * StressScalar(4.0, Unit::Pressure::Pascal), StressScalar(8.0, Unit::Pressure::Pascal));
}

TEST(StressScalar, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(StressScalar(3.0, Unit::Pressure::Pascal) - StressScalar(2.0, Unit::Pressure::Pascal),
            StressScalar(1.0, Unit::Pressure::Pascal));
}

TEST(StressScalar, AssignmentOperatorAddition) {
  StressScalar quantity{1.0, Unit::Pressure::Pascal};
  quantity += StressScalar(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, StressScalar(3.0, Unit::Pressure::Pascal));
}

TEST(StressScalar, AssignmentOperatorDivision) {
  StressScalar quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, StressScalar(4.0, Unit::Pressure::Pascal));
}

TEST(StressScalar, AssignmentOperatorMultiplication) {
  StressScalar quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, StressScalar(8.0, Unit::Pressure::Pascal));
}

TEST(StressScalar, AssignmentOperatorSubtraction) {
  StressScalar quantity{3.0, Unit::Pressure::Pascal};
  quantity -= StressScalar(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, StressScalar(1.0, Unit::Pressure::Pascal));
}

TEST(StressScalar, ComparisonOperators) {
  const StressScalar first{0.1, Unit::Pressure::Pascal};
  const StressScalar second{0.2, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(StressScalar, CopyAssignmentOperator) {
  const StressScalar first{1.11, Unit::Pressure::Pascal};
  StressScalar second = StressScalar::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(StressScalar, CopyConstructor) {
  const StressScalar first{1.11, Unit::Pressure::Pascal};
  const StressScalar second{first};
  EXPECT_EQ(second, first);
}

TEST(StressScalar, Create) {
  constexpr StressScalar quantity = StressScalar::Create<Unit::Pressure::Pascal>(1.11);
  EXPECT_EQ(quantity, StressScalar(1.11, Unit::Pressure::Pascal));
}

TEST(StressScalar, DefaultConstructor) {
  EXPECT_NO_THROW(StressScalar{});
}

TEST(StressScalar, Dimensions) {
  EXPECT_EQ(StressScalar::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(StressScalar, Hash) {
  const StressScalar first{1.11, Unit::Pressure::Kilopascal};
  const StressScalar second{1.110001, Unit::Pressure::Kilopascal};
  const StressScalar third{-1.11, Unit::Pressure::Kilopascal};
  const std::hash<StressScalar> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(StressScalar, JSON) {
  EXPECT_EQ(StressScalar(1.11, Unit::Pressure::Pascal).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Pa\"}");
  EXPECT_EQ(StressScalar(-2.22, Unit::Pressure::Kilopascal).JSON(Unit::Pressure::Kilopascal),
            "{\"value\":-2.220000000000000,\"unit\":\"kPa\"}");
}

TEST(StressScalar, MoveAssignmentOperator) {
  StressScalar first{1.11, Unit::Pressure::Pascal};
  StressScalar second = StressScalar::Zero();
  second = std::move(first);
  EXPECT_EQ(second, StressScalar(1.11, Unit::Pressure::Pascal));
}

TEST(StressScalar, MoveConstructor) {
  StressScalar first{1.11, Unit::Pressure::Pascal};
  const StressScalar second{std::move(first)};
  EXPECT_EQ(second, StressScalar(1.11, Unit::Pressure::Pascal));
}

TEST(StressScalar, MutableValue) {
  StressScalar quantity{1.11, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(StressScalar, Print) {
  EXPECT_EQ(StressScalar(1.11, Unit::Pressure::Pascal).Print(), "1.110000000000000 Pa");
  EXPECT_EQ(StressScalar(-2.22, Unit::Pressure::Kilopascal).Print(Unit::Pressure::Kilopascal),
            "-2.220000000000000 kPa");
}

TEST(StressScalar, SetValue) {
  StressScalar quantity{1.11, Unit::Pressure::Pascal};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(StressScalar, SizeOf) {
  EXPECT_EQ(sizeof(StressScalar{}), sizeof(double));
}

TEST(StressScalar, StandardConstructor) {
  EXPECT_NO_THROW(StressScalar(1.11, Unit::Pressure::Kilopascal));
}

TEST(StressScalar, StaticValue) {
  constexpr StressScalar quantity = StressScalar::Create<Unit::Pressure::Kilopascal>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.11);
}

TEST(StressScalar, Stream) {
  std::ostringstream stream;
  stream << StressScalar(1.11, Unit::Pressure::Pascal);
  EXPECT_EQ(stream.str(), StressScalar(1.11, Unit::Pressure::Pascal).Print());
}

TEST(StressScalar, Unit) {
  EXPECT_EQ(StressScalar::Unit(), Standard<Unit::Pressure>);
}

TEST(StressScalar, Value) {
  EXPECT_EQ(StressScalar(1.11, Unit::Pressure::Pascal).Value(), 1.11);
  EXPECT_EQ(StressScalar(1.11, Unit::Pressure::Kilopascal).Value(Unit::Pressure::Kilopascal), 1.11);
}

TEST(StressScalar, XML) {
  EXPECT_EQ(StressScalar(1.11, Unit::Pressure::Pascal).XML(),
            "<value>1.110000000000000</value><unit>Pa</unit>");
  EXPECT_EQ(StressScalar(-2.22, Unit::Pressure::Kilopascal).XML(Unit::Pressure::Kilopascal),
            "<value>-2.220000000000000</value><unit>kPa</unit>");
}

TEST(StressScalar, YAML) {
  EXPECT_EQ(
      StressScalar(1.11, Unit::Pressure::Pascal).YAML(), "{value:1.110000000000000,unit:\"Pa\"}");
  EXPECT_EQ(StressScalar(-2.22, Unit::Pressure::Kilopascal).YAML(Unit::Pressure::Kilopascal),
            "{value:-2.220000000000000,unit:\"kPa\"}");
}

TEST(StressScalar, Zero) {
  EXPECT_EQ(StressScalar::Zero(), StressScalar(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
