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

#include "../include/PhQ/SpecificGasConstant.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(SpecificGasConstant, ArithmeticOperatorAddition) {
  EXPECT_EQ(SpecificGasConstant(
                1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                + SpecificGasConstant(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificGasConstant(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificGasConstant(
                1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                + SpecificIsochoricHeatCapacity(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificIsobaricHeatCapacity(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificIsochoricHeatCapacity(
                2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                + SpecificGasConstant(
                    1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificIsobaricHeatCapacity(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, ArithmeticOperatorDivision) {
  EXPECT_EQ(SpecificGasConstant(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                / 2.0,
            SpecificGasConstant(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificGasConstant(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                / SpecificGasConstant(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            4.0);

  EXPECT_EQ(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / Mass(4.0, Unit::Mass::Kilogram),
            SpecificGasConstant(
                2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / SpecificGasConstant(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            Mass(2.0, Unit::Mass::Kilogram));
}

TEST(SpecificGasConstant, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SpecificGasConstant(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                * 2.0,
            SpecificGasConstant(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(2.0
                * SpecificGasConstant(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificGasConstant(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificGasConstant(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                * Mass(2.0, Unit::Mass::Kilogram),
            GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(Mass(4.0, Unit::Mass::Kilogram)
                * SpecificGasConstant(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(SpecificGasConstant, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SpecificGasConstant(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                - SpecificGasConstant(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificGasConstant(
                1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                - SpecificIsochoricHeatCapacity(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificGasConstant(
                1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                - SpecificGasConstant(
                    1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificIsochoricHeatCapacity(
                2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, AssignmentOperatorAddition) {
  SpecificGasConstant quantity{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity += SpecificGasConstant(
      2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(quantity,
            SpecificGasConstant(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, AssignmentOperatorDivision) {
  SpecificGasConstant quantity{
      8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(quantity,
            SpecificGasConstant(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, AssignmentOperatorMultiplication) {
  SpecificGasConstant quantity{
      4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(quantity,
            SpecificGasConstant(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, AssignmentOperatorSubtraction) {
  SpecificGasConstant quantity{
      3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity -= SpecificGasConstant(
      2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(quantity,
            SpecificGasConstant(
                1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, ComparisonOperators) {
  const SpecificGasConstant first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificGasConstant second{
      2.22, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SpecificGasConstant, CopyAssignmentOperator) {
  const SpecificGasConstant first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificGasConstant second = SpecificGasConstant::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(SpecificGasConstant, CopyConstructor) {
  const SpecificGasConstant first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificGasConstant second{first};
  EXPECT_EQ(second, first);
}

TEST(SpecificGasConstant, Create) {
  constexpr SpecificGasConstant quantity = SpecificGasConstant::Create<
      Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>(1.11);
  EXPECT_EQ(quantity,
            SpecificGasConstant(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, DefaultConstructor) {
  EXPECT_NO_THROW(SpecificGasConstant{});
}

TEST(SpecificGasConstant, Dimensions) {
  EXPECT_EQ(SpecificGasConstant::Dimensions(),
            RelatedDimensions<Unit::SpecificHeatCapacity>);
}

TEST(SpecificGasConstant, Hash) {
  const SpecificGasConstant first{
      1.11, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificGasConstant second{
      1.110001, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificGasConstant third{
      -1.11, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const std::hash<SpecificGasConstant> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(SpecificGasConstant, JSON) {
  EXPECT_EQ(SpecificGasConstant(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"J/kg/K\"}");
  EXPECT_EQ(SpecificGasConstant(
                -2.22, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .JSON(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "{\"value\":-2.220000000000000,\"unit\":\"nJ/g/K\"}");
}

TEST(SpecificGasConstant, MiscellaneousConstructors) {
  EXPECT_EQ(
      SpecificGasConstant(
          SpecificIsobaricHeatCapacity(
              3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificIsochoricHeatCapacity(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificGasConstant(
          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(
      SpecificGasConstant(
          HeatCapacityRatio(2.0),
          SpecificIsobaricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificGasConstant(
          2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(
      SpecificGasConstant(
          HeatCapacityRatio(2.0),
          SpecificIsochoricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificGasConstant(
          4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(
      SpecificGasConstant(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin),
                          Mass(4.0, Unit::Mass::Kilogram)),
      SpecificGasConstant(
          2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(
      HeatCapacityRatio(
          SpecificIsobaricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificGasConstant(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      HeatCapacityRatio(2.0));

  EXPECT_EQ(
      HeatCapacityRatio(
          SpecificGasConstant(
              8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificIsochoricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      HeatCapacityRatio(3.0));

  EXPECT_EQ(
      Mass(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin),
           SpecificGasConstant(
               4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      Mass(2.0, Unit::Mass::Kilogram));

  EXPECT_EQ(GasConstant(
                SpecificGasConstant(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
                Mass(2.0, Unit::Mass::Kilogram)),
            GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(
          SpecificIsobaricHeatCapacity(
              3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificGasConstant(
              1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificIsochoricHeatCapacity(
          2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificIsochoricHeatCapacity(
                SpecificGasConstant(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
                HeatCapacityRatio(2.0)),
            SpecificIsochoricHeatCapacity(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(
          SpecificIsochoricHeatCapacity(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificGasConstant(
              1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificIsobaricHeatCapacity(
          3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(
          HeatCapacityRatio(2.0),
          SpecificGasConstant(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificIsobaricHeatCapacity(
          8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, MoveAssignmentOperator) {
  SpecificGasConstant first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificGasConstant second = SpecificGasConstant::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, SpecificGasConstant(
                  1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, MoveConstructor) {
  SpecificGasConstant first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificGasConstant second{std::move(first)};
  EXPECT_EQ(
      second, SpecificGasConstant(
                  1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, MutableValue) {
  SpecificGasConstant quantity{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(SpecificGasConstant, Print) {
  EXPECT_EQ(SpecificGasConstant(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .Print(),
            "1.110000000000000 J/kg/K");
  EXPECT_EQ(SpecificGasConstant(
                -2.22, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .Print(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "-2.220000000000000 nJ/g/K");
}

TEST(SpecificGasConstant, SetValue) {
  SpecificGasConstant quantity{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(SpecificGasConstant, SizeOf) {
  EXPECT_EQ(sizeof(SpecificGasConstant{}), sizeof(double));
}

TEST(SpecificGasConstant, StandardConstructor) {
  EXPECT_NO_THROW(SpecificGasConstant(
      1.11, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin));
}

TEST(SpecificGasConstant, StaticValue) {
  constexpr SpecificGasConstant quantity = SpecificGasConstant::Create<
      Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>(2.0);
  constexpr double value =
      quantity
          .StaticValue<Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(SpecificGasConstant, Stream) {
  std::ostringstream stream;
  stream << SpecificGasConstant(
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(stream.str(),
            SpecificGasConstant(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .Print());
}

TEST(SpecificGasConstant, Unit) {
  EXPECT_EQ(SpecificGasConstant::Unit(), Standard<Unit::SpecificHeatCapacity>);
}

TEST(SpecificGasConstant, Value) {
  EXPECT_EQ(SpecificGasConstant(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .Value(),
            1.11);
  EXPECT_EQ(SpecificGasConstant(
                2.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .Value(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            2.0);
}

TEST(SpecificGasConstant, XML) {
  EXPECT_EQ(SpecificGasConstant(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .XML(),
            "<value>1.110000000000000</value><unit>J/kg/K</unit>");
  EXPECT_EQ(SpecificGasConstant(
                -2.22, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .XML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "<value>-2.220000000000000</value><unit>nJ/g/K</unit>");
}

TEST(SpecificGasConstant, YAML) {
  EXPECT_EQ(SpecificGasConstant(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .YAML(),
            "{value:1.110000000000000,unit:\"J/kg/K\"}");
  EXPECT_EQ(SpecificGasConstant(
                -2.22, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .YAML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "{value:-2.220000000000000,unit:\"nJ/g/K\"}");
}

TEST(SpecificGasConstant, Zero) {
  EXPECT_EQ(SpecificGasConstant::Zero(),
            SpecificGasConstant(
                0.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

}  // namespace

}  // namespace PhQ
