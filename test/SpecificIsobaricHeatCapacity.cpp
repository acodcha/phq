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

#include "../include/PhQ/SpecificIsobaricHeatCapacity.hpp"

#include <gtest/gtest.h>

namespace PhQ {

namespace {

TEST(SpecificIsobaricHeatCapacity, ArithmeticOperatorAddition) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                + SpecificIsobaricHeatCapacity(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificIsobaricHeatCapacity(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, ArithmeticOperatorDivision) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                / 2.0,
            SpecificIsobaricHeatCapacity(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                / SpecificIsobaricHeatCapacity(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            4.0);

  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                / SpecificIsochoricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            HeatCapacityRatio(2.0));

  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                / HeatCapacityRatio(2.0),
            SpecificIsochoricHeatCapacity(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / Mass(4.0, Unit::Mass::Kilogram),
            SpecificIsobaricHeatCapacity(
                2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / SpecificIsobaricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            Mass(2.0, Unit::Mass::Kilogram));
}

TEST(SpecificIsobaricHeatCapacity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                * 2.0,
            SpecificIsobaricHeatCapacity(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(2.0
                * SpecificIsobaricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificIsobaricHeatCapacity(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                * Mass(2.0, Unit::Mass::Kilogram),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(Mass(4.0, Unit::Mass::Kilogram)
                * SpecificIsobaricHeatCapacity(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(HeatCapacityRatio(2.0)
                * SpecificIsochoricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificIsobaricHeatCapacity(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificIsochoricHeatCapacity(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                * HeatCapacityRatio(2.0),
            SpecificIsobaricHeatCapacity(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                - SpecificIsobaricHeatCapacity(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificIsobaricHeatCapacity(
                1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, AssignmentOperatorAddition) {
  SpecificIsobaricHeatCapacity quantity{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity += SpecificIsobaricHeatCapacity(
      2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(quantity,
            SpecificIsobaricHeatCapacity(
                3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, AssignmentOperatorDivision) {
  SpecificIsobaricHeatCapacity quantity{
      8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(quantity,
            SpecificIsobaricHeatCapacity(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, AssignmentOperatorMultiplication) {
  SpecificIsobaricHeatCapacity quantity{
      4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(quantity,
            SpecificIsobaricHeatCapacity(
                8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, AssignmentOperatorSubtraction) {
  SpecificIsobaricHeatCapacity quantity{
      3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity -= SpecificIsobaricHeatCapacity(
      2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(quantity,
            SpecificIsobaricHeatCapacity(
                1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, ComparisonOperators) {
  const SpecificIsobaricHeatCapacity first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificIsobaricHeatCapacity second{
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

TEST(SpecificIsobaricHeatCapacity, CopyAssignmentOperator) {
  const SpecificIsobaricHeatCapacity first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificIsobaricHeatCapacity second = SpecificIsobaricHeatCapacity::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(SpecificIsobaricHeatCapacity, CopyConstructor) {
  const SpecificIsobaricHeatCapacity first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificIsobaricHeatCapacity second{first};
  EXPECT_EQ(second, first);
}

TEST(SpecificIsobaricHeatCapacity, Create) {
  constexpr SpecificIsobaricHeatCapacity quantity =
      SpecificIsobaricHeatCapacity::Create<
          Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>(1.11);
  EXPECT_EQ(quantity,
            SpecificIsobaricHeatCapacity(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, DefaultConstructor) {
  EXPECT_NO_THROW(SpecificIsobaricHeatCapacity{});
}

TEST(SpecificIsobaricHeatCapacity, Dimensions) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity::Dimensions(),
            RelatedDimensions<Unit::SpecificHeatCapacity>);
}

TEST(SpecificIsobaricHeatCapacity, Hash) {
  const SpecificIsobaricHeatCapacity first{
      1.11, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificIsobaricHeatCapacity second{
      1.110001, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificIsobaricHeatCapacity third{
      -1.11, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const std::hash<SpecificIsobaricHeatCapacity> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(SpecificIsobaricHeatCapacity, JSON) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .JSON(),
            "{\"value\":1.110000000000000,\"unit\":\"J/kg/K\"}");
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                -2.22, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .JSON(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "{\"value\":-2.220000000000000,\"unit\":\"nJ/g/K\"}");
}

TEST(SpecificIsobaricHeatCapacity, MiscellaneousConstructors) {
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(
          HeatCapacityRatio(2.0),
          SpecificIsochoricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificIsobaricHeatCapacity(
          8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin),
                Mass(4.0, Unit::Mass::Kilogram)),
            SpecificIsobaricHeatCapacity(
                2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));

  EXPECT_EQ(
      HeatCapacityRatio(
          SpecificIsobaricHeatCapacity(
              8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificIsochoricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      HeatCapacityRatio(2.0));

  EXPECT_EQ(
      Mass(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin),
           SpecificIsobaricHeatCapacity(
               4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      Mass(2.0, Unit::Mass::Kilogram));

  EXPECT_EQ(IsobaricHeatCapacity(
                SpecificIsobaricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
                Mass(2.0, Unit::Mass::Kilogram)),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));

  EXPECT_EQ(SpecificIsochoricHeatCapacity(
                SpecificIsobaricHeatCapacity(
                    8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
                HeatCapacityRatio(2.0)),
            SpecificIsochoricHeatCapacity(
                4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, MoveAssignmentOperator) {
  SpecificIsobaricHeatCapacity first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificIsobaricHeatCapacity second = SpecificIsobaricHeatCapacity::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, SpecificIsobaricHeatCapacity(
                  1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, MoveConstructor) {
  SpecificIsobaricHeatCapacity first{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificIsobaricHeatCapacity second{std::move(first)};
  EXPECT_EQ(
      second, SpecificIsobaricHeatCapacity(
                  1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, MutableValue) {
  SpecificIsobaricHeatCapacity quantity{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  double& value = quantity.MutableValue();
  value = 2.22;
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(SpecificIsobaricHeatCapacity, Print) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .Print(),
            "1.110000000000000 J/kg/K");
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                -2.22, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .Print(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "-2.220000000000000 nJ/g/K");
}

TEST(SpecificIsobaricHeatCapacity, SetValue) {
  SpecificIsobaricHeatCapacity quantity{
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity.SetValue(2.22);
  EXPECT_EQ(quantity.Value(), 2.22);
}

TEST(SpecificIsobaricHeatCapacity, SizeOf) {
  EXPECT_EQ(sizeof(SpecificIsobaricHeatCapacity{}), sizeof(double));
}

TEST(SpecificIsobaricHeatCapacity, StandardConstructor) {
  EXPECT_NO_THROW(SpecificIsobaricHeatCapacity(
      1.11, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, StaticValue) {
  constexpr SpecificIsobaricHeatCapacity quantity =
      SpecificIsobaricHeatCapacity::Create<
          Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>(2.0);
  constexpr double value =
      quantity
          .StaticValue<Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(SpecificIsobaricHeatCapacity, Stream) {
  std::ostringstream stream;
  stream << SpecificIsobaricHeatCapacity(
      1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(stream.str(),
            SpecificIsobaricHeatCapacity(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .Print());
}

TEST(SpecificIsobaricHeatCapacity, Unit) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity::Unit(),
            Standard<Unit::SpecificHeatCapacity>);
}

TEST(SpecificIsobaricHeatCapacity, Value) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .Value(),
            1.11);
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                2.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .Value(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            2.0);
}

TEST(SpecificIsobaricHeatCapacity, XML) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .XML(),
            "<value>1.110000000000000</value><unit>J/kg/K</unit>");
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                -2.22, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .XML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "<value>-2.220000000000000</value><unit>nJ/g/K</unit>");
}

TEST(SpecificIsobaricHeatCapacity, YAML) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                1.11, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .YAML(),
            "{value:1.110000000000000,unit:\"J/kg/K\"}");
  EXPECT_EQ(SpecificIsobaricHeatCapacity(
                -2.22, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .YAML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "{value:-2.220000000000000,unit:\"nJ/g/K\"}");
}

TEST(SpecificIsobaricHeatCapacity, Zero) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity::Zero(),
            SpecificIsobaricHeatCapacity(
                0.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

}  // namespace

}  // namespace PhQ
