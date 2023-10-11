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

#include "../include/PhQ/DynamicPressure.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(DynamicPressure, ArithmeticOperatorAddition) {
  EXPECT_EQ(DynamicPressure(1.0, Unit::Pressure::Pascal)
                + DynamicPressure(2.0, Unit::Pressure::Pascal),
            DynamicPressure(3.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, ArithmeticOperatorDivision) {
  EXPECT_EQ(DynamicPressure(8.0, Unit::Pressure::Pascal) / 2.0,
            DynamicPressure(4.0, Unit::Pressure::Pascal));

  EXPECT_EQ(DynamicPressure(8.0, Unit::Pressure::Pascal)
                / DynamicPressure(2.0, Unit::Pressure::Pascal),
            4.0);
}

TEST(DynamicPressure, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(DynamicPressure(4.0, Unit::Pressure::Pascal) * 2.0,
            DynamicPressure(8.0, Unit::Pressure::Pascal));

  EXPECT_EQ(2.0 * DynamicPressure(4.0, Unit::Pressure::Pascal),
            DynamicPressure(8.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(DynamicPressure(3.0, Unit::Pressure::Pascal)
                - DynamicPressure(2.0, Unit::Pressure::Pascal),
            DynamicPressure(1.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, AssignmentOperatorAddition) {
  DynamicPressure quantity{1.0, Unit::Pressure::Pascal};
  quantity += DynamicPressure(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, DynamicPressure(3.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, AssignmentOperatorDivision) {
  DynamicPressure quantity{8.0, Unit::Pressure::Pascal};
  quantity /= 2.0;
  EXPECT_EQ(quantity, DynamicPressure(4.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, AssignmentOperatorMultiplication) {
  DynamicPressure quantity{4.0, Unit::Pressure::Pascal};
  quantity *= 2.0;
  EXPECT_EQ(quantity, DynamicPressure(8.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, AssignmentOperatorSubtraction) {
  DynamicPressure quantity{3.0, Unit::Pressure::Pascal};
  quantity -= DynamicPressure(2.0, Unit::Pressure::Pascal);
  EXPECT_EQ(quantity, DynamicPressure(1.0, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, ComparisonOperators) {
  const DynamicPressure first{1.11, Unit::Pressure::Pascal};
  const DynamicPressure second{2.22, Unit::Pressure::Pascal};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(DynamicPressure, CopyAssignmentOperator) {
  const DynamicPressure first{1.11, Unit::Pressure::Pascal};
  DynamicPressure second = DynamicPressure::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(DynamicPressure, CopyConstructor) {
  const DynamicPressure first{1.11, Unit::Pressure::Pascal};
  const DynamicPressure second{first};
  EXPECT_EQ(second, first);
}

TEST(DynamicPressure, Create) {
  constexpr DynamicPressure quantity =
      DynamicPressure::Create<Unit::Pressure::Pascal>(1.11);
  EXPECT_EQ(quantity, DynamicPressure(1.11, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, DefaultConstructor) {
  EXPECT_NO_THROW(DynamicPressure{});
}

TEST(DynamicPressure, Dimensions) {
  EXPECT_EQ(DynamicPressure::Dimensions(), RelatedDimensions<Unit::Pressure>);
}

TEST(DynamicPressure, Hash) {
  const DynamicPressure first{1.11, Unit::Pressure::Kilopascal};
  const DynamicPressure second{1.110001, Unit::Pressure::Kilopascal};
  const DynamicPressure third{-1.11, Unit::Pressure::Kilopascal};
  const std::hash<DynamicPressure> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(DynamicPressure, JSON) {
  EXPECT_EQ(DynamicPressure(1.11, Unit::Pressure::Pascal).JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"Pa\"}");
  EXPECT_EQ(DynamicPressure(-2.22, Unit::Pressure::Kilopascal)
                .JSON(Unit::Pressure::Kilopascal),
            "{\"value\":-2.220000000000000,\"unit\":\"kPa\"}");
}

TEST(DynamicPressure, MiscellaneousConstructors) {
  EXPECT_EQ(DynamicPressure(
                MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
                Speed(4.0, Unit::Speed::MetrePerSecond)),
            DynamicPressure(16.0, Unit::Pressure::Pascal));

  EXPECT_EQ(MassDensity(DynamicPressure(16.0, Unit::Pressure::Pascal),
                        Speed(4.0, Unit::Speed::MetrePerSecond)),
            MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre));

  EXPECT_EQ(Speed(DynamicPressure(16.0, Unit::Pressure::Pascal),
                  MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre)),
            Speed(4.0, Unit::Speed::MetrePerSecond));
}

TEST(DynamicPressure, MoveAssignmentOperator) {
  DynamicPressure first{1.11, Unit::Pressure::Pascal};
  DynamicPressure second = DynamicPressure::Zero();
  second = std::move(first);
  EXPECT_EQ(second, DynamicPressure(1.11, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, MoveConstructor) {
  DynamicPressure first{1.11, Unit::Pressure::Pascal};
  DynamicPressure second{std::move(first)};
  EXPECT_EQ(second, DynamicPressure(1.11, Unit::Pressure::Pascal));
}

TEST(DynamicPressure, MutableValue) {
  DynamicPressure quantity{1.11, Unit::Pressure::Pascal};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(DynamicPressure, Print) {
  EXPECT_EQ(DynamicPressure(1.11, Unit::Pressure::Pascal).Print(),
            "1.110000000000000 Pa");
  EXPECT_EQ(DynamicPressure(-2.22, Unit::Pressure::Kilopascal)
                .Print(Unit::Pressure::Kilopascal),
            "-2.220000000000000 kPa");
}

TEST(DynamicPressure, SetValue) {
  DynamicPressure quantity{1.11, Unit::Pressure::Pascal};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(DynamicPressure, SizeOf) {
  EXPECT_EQ(sizeof(DynamicPressure{}), sizeof(double));
}

TEST(DynamicPressure, StandardConstructor) {
  EXPECT_NO_THROW(DynamicPressure(1.11, Unit::Pressure::Kilopascal));
}

TEST(DynamicPressure, StaticValue) {
  constexpr DynamicPressure quantity =
      DynamicPressure::Create<Unit::Pressure::Kilopascal>(1.11);
  constexpr double value = quantity.StaticValue<Unit::Pressure::Kilopascal>();
  EXPECT_EQ(value, 1.11);
}

TEST(DynamicPressure, Stream) {
  std::ostringstream stream;
  stream << DynamicPressure(1.11, Unit::Pressure::Pascal);
  EXPECT_EQ(
      stream.str(), DynamicPressure(1.11, Unit::Pressure::Pascal).Print());
}

TEST(DynamicPressure, Unit) {
  EXPECT_EQ(DynamicPressure::Unit(), Standard<Unit::Pressure>);
}

TEST(DynamicPressure, Value) {
  EXPECT_EQ(DynamicPressure(1.11, Unit::Pressure::Pascal).Value(), 1.11);
  EXPECT_EQ(DynamicPressure(1.11, Unit::Pressure::Kilopascal)
                .Value(Unit::Pressure::Kilopascal),
            1.11);
}

TEST(DynamicPressure, XML) {
  EXPECT_EQ(DynamicPressure(1.11, Unit::Pressure::Pascal).XML(),
            "<value>1.110000000000000</value><unit>Pa</unit>");
  EXPECT_EQ(DynamicPressure(-2.22, Unit::Pressure::Kilopascal)
                .XML(Unit::Pressure::Kilopascal),
            "<value>-2.220000000000000</value><unit>kPa</unit>");
}

TEST(DynamicPressure, YAML) {
  EXPECT_EQ(DynamicPressure(1.11, Unit::Pressure::Pascal).YAML(),
            "{value:1.110000000000000,unit:\"Pa\"}");
  EXPECT_EQ(DynamicPressure(-2.22, Unit::Pressure::Kilopascal)
                .YAML(Unit::Pressure::Kilopascal),
            "{value:-2.220000000000000,unit:\"kPa\"}");
}

TEST(DynamicPressure, Zero) {
  EXPECT_EQ(
      DynamicPressure::Zero(), DynamicPressure(0.0, Unit::Pressure::Pascal));
}

}  // namespace

}  // namespace PhQ
