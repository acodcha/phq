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

#include "../include/PhQ/StaticKinematicPressure.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(StaticKinematicPressure, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram)
          + StaticKinematicPressure(
              2.0, Unit::SpecificEnergy::JoulePerKilogram),
      StaticKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      StaticKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram)
          / 2.0,
      StaticKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram));

  EXPECT_EQ(StaticKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram)
                / StaticKinematicPressure(
                    2.0, Unit::SpecificEnergy::JoulePerKilogram),
            4.0);

  EXPECT_EQ(
      StaticPressure(8.0, Unit::Pressure::Pascal)
          / MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
      StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      StaticKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram)
          * 2.0,
      StaticKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));

  EXPECT_EQ(
      2.0
          * StaticKinematicPressure(
              4.0, Unit::SpecificEnergy::JoulePerKilogram),
      StaticKinematicPressure(8.0, Unit::SpecificEnergy::JoulePerKilogram));

  EXPECT_EQ(StaticKinematicPressure(4.0, Unit::SpecificEnergy::JoulePerKilogram)
                * MassDensity(2.0, Unit::MassDensity::KilogramPerCubicMetre),
            StaticPressure(8.0, Unit::Pressure::Pascal));
}

TEST(StaticKinematicPressure, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      StaticKinematicPressure(3.0, Unit::SpecificEnergy::JoulePerKilogram)
          - StaticKinematicPressure(
              2.0, Unit::SpecificEnergy::JoulePerKilogram),
      StaticKinematicPressure(1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, AssignmentOperatorAddition) {
  StaticKinematicPressure quantity{1.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity +=
      StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(quantity, StaticKinematicPressure(
                          3.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, AssignmentOperatorDivision) {
  StaticKinematicPressure quantity{8.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity /= 2.0;
  EXPECT_EQ(quantity, StaticKinematicPressure(
                          4.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, AssignmentOperatorMultiplication) {
  StaticKinematicPressure quantity{4.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity *= 2.0;
  EXPECT_EQ(quantity, StaticKinematicPressure(
                          8.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, AssignmentOperatorSubtraction) {
  StaticKinematicPressure quantity{3.0, Unit::SpecificEnergy::JoulePerKilogram};
  quantity -=
      StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(quantity, StaticKinematicPressure(
                          1.0, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, ComparisonOperators) {
  const StaticKinematicPressure first{
      0.1, Unit::SpecificEnergy::JoulePerKilogram};
  const StaticKinematicPressure second{
      0.2, Unit::SpecificEnergy::JoulePerKilogram};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(StaticKinematicPressure, CopyAssignmentOperator) {
  const StaticKinematicPressure first{
      1.11, Unit::SpecificEnergy::JoulePerKilogram};
  StaticKinematicPressure second = StaticKinematicPressure::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(StaticKinematicPressure, CopyConstructor) {
  const StaticKinematicPressure first{
      1.11, Unit::SpecificEnergy::JoulePerKilogram};
  const StaticKinematicPressure second{first};
  EXPECT_EQ(second, first);
}

TEST(StaticKinematicPressure, Create) {
  constexpr StaticKinematicPressure quantity =
      StaticKinematicPressure::Create<Unit::SpecificEnergy::JoulePerKilogram>(
          1.11);
  EXPECT_EQ(quantity, StaticKinematicPressure(
                          1.11, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, DefaultConstructor) {
  EXPECT_NO_THROW(StaticKinematicPressure{});
}

TEST(StaticKinematicPressure, Dimensions) {
  EXPECT_EQ(StaticKinematicPressure::Dimensions(),
            RelatedDimensions<Unit::SpecificEnergy>);
}

TEST(StaticKinematicPressure, Hash) {
  const StaticKinematicPressure first{
      1.11, Unit::SpecificEnergy::NanojoulePerGram};
  const StaticKinematicPressure second{
      1.110001, Unit::SpecificEnergy::NanojoulePerGram};
  const StaticKinematicPressure third{
      -1.11, Unit::SpecificEnergy::NanojoulePerGram};
  const std::hash<StaticKinematicPressure> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(StaticKinematicPressure, JSON) {
  EXPECT_EQ(
      StaticKinematicPressure(1.11, Unit::SpecificEnergy::JoulePerKilogram)
          .JSON(),
      "{\"value\":1.110000000000000,\"unit\":\"J/kg\"}");
  EXPECT_EQ(
      StaticKinematicPressure(-2.22, Unit::SpecificEnergy::NanojoulePerGram)
          .JSON(Unit::SpecificEnergy::NanojoulePerGram),
      "{\"value\":-2.220000000000000,\"unit\":\"nJ/g\"}");
}

TEST(StaticKinematicPressure, MiscellaneousConstructors) {
  EXPECT_EQ(
      StaticKinematicPressure(
          StaticPressure(8.0, Unit::Pressure::Pascal),
          MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre)),
      StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram));

  EXPECT_EQ(
      StaticPressure(
          MassDensity(4.0, Unit::MassDensity::KilogramPerCubicMetre),
          StaticKinematicPressure(2.0, Unit::SpecificEnergy::JoulePerKilogram)),
      StaticPressure(8.0, Unit::Pressure::Pascal));
}

TEST(StaticKinematicPressure, MoveAssignmentOperator) {
  StaticKinematicPressure first{1.11, Unit::SpecificEnergy::JoulePerKilogram};
  StaticKinematicPressure second = StaticKinematicPressure::Zero();
  second = std::move(first);
  EXPECT_EQ(second, StaticKinematicPressure(
                        1.11, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, MoveConstructor) {
  StaticKinematicPressure first{1.11, Unit::SpecificEnergy::JoulePerKilogram};
  StaticKinematicPressure second{std::move(first)};
  EXPECT_EQ(second, StaticKinematicPressure(
                        1.11, Unit::SpecificEnergy::JoulePerKilogram));
}

TEST(StaticKinematicPressure, MutableValue) {
  StaticKinematicPressure quantity{
      1.11, Unit::SpecificEnergy::JoulePerKilogram};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(StaticKinematicPressure, Print) {
  EXPECT_EQ(
      StaticKinematicPressure(1.11, Unit::SpecificEnergy::JoulePerKilogram)
          .Print(),
      "1.110000000000000 J/kg");
  EXPECT_EQ(
      StaticKinematicPressure(-2.22, Unit::SpecificEnergy::NanojoulePerGram)
          .Print(Unit::SpecificEnergy::NanojoulePerGram),
      "-2.220000000000000 nJ/g");
}

TEST(StaticKinematicPressure, SetValue) {
  StaticKinematicPressure quantity{
      1.11, Unit::SpecificEnergy::JoulePerKilogram};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(StaticKinematicPressure, SizeOf) {
  EXPECT_EQ(sizeof(StaticKinematicPressure{}), sizeof(double));
}

TEST(StaticKinematicPressure, StandardConstructor) {
  EXPECT_NO_THROW(
      StaticKinematicPressure(1.11, Unit::SpecificEnergy::NanojoulePerGram));
}

TEST(StaticKinematicPressure, StaticValue) {
  constexpr StaticKinematicPressure quantity =
      StaticKinematicPressure::Create<Unit::SpecificEnergy::NanojoulePerGram>(
          2.0);
  constexpr double value =
      quantity.StaticValue<Unit::SpecificEnergy::NanojoulePerGram>();
  EXPECT_EQ(value, 2.0);
}

TEST(StaticKinematicPressure, Stream) {
  std::ostringstream stream;
  stream
      << StaticKinematicPressure(1.11, Unit::SpecificEnergy::JoulePerKilogram);
  EXPECT_EQ(
      stream.str(),
      StaticKinematicPressure(1.11, Unit::SpecificEnergy::JoulePerKilogram)
          .Print());
}

TEST(StaticKinematicPressure, Unit) {
  EXPECT_EQ(StaticKinematicPressure::Unit(), Standard<Unit::SpecificEnergy>);
}

TEST(StaticKinematicPressure, Value) {
  EXPECT_EQ(
      StaticKinematicPressure(1.11, Unit::SpecificEnergy::JoulePerKilogram)
          .Value(),
      1.11);
  EXPECT_EQ(StaticKinematicPressure(2.0, Unit::SpecificEnergy::NanojoulePerGram)
                .Value(Unit::SpecificEnergy::NanojoulePerGram),
            2.0);
}

TEST(StaticKinematicPressure, XML) {
  EXPECT_EQ(
      StaticKinematicPressure(1.11, Unit::SpecificEnergy::JoulePerKilogram)
          .XML(),
      "<value>1.110000000000000</value><unit>J/kg</unit>");
  EXPECT_EQ(
      StaticKinematicPressure(-2.22, Unit::SpecificEnergy::NanojoulePerGram)
          .XML(Unit::SpecificEnergy::NanojoulePerGram),
      "<value>-2.220000000000000</value><unit>nJ/g</unit>");
}

TEST(StaticKinematicPressure, YAML) {
  EXPECT_EQ(
      StaticKinematicPressure(1.11, Unit::SpecificEnergy::JoulePerKilogram)
          .YAML(),
      "{value:1.110000000000000,unit:\"J/kg\"}");
  EXPECT_EQ(
      StaticKinematicPressure(-2.22, Unit::SpecificEnergy::NanojoulePerGram)
          .YAML(Unit::SpecificEnergy::NanojoulePerGram),
      "{value:-2.220000000000000,unit:\"nJ/g\"}");
}

TEST(StaticKinematicPressure, Zero) {
  EXPECT_EQ(
      StaticKinematicPressure::Zero(),
      StaticKinematicPressure(0.0, Unit::SpecificEnergy::JoulePerKilogram));
}

}  // namespace

}  // namespace PhQ
