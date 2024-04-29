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

#include "../include/PhQ/SpecificIsochoricHeatCapacity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/HeatCapacityRatio.hpp"
#include "../include/PhQ/IsochoricHeatCapacity.hpp"
#include "../include/PhQ/Mass.hpp"
#include "../include/PhQ/Unit/HeatCapacity.hpp"
#include "../include/PhQ/Unit/Mass.hpp"
#include "../include/PhQ/Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

namespace {

TEST(SpecificIsochoricHeatCapacity, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          + SpecificIsochoricHeatCapacity(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsochoricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          / 2.0,
      SpecificIsochoricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          / SpecificIsochoricHeatCapacity(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      4.0);
  EXPECT_EQ(
      IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
          / Mass(4.0, Unit::Mass::Kilogram),
      SpecificIsochoricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / SpecificIsochoricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            Mass(2.0, Unit::Mass::Kilogram));
}

TEST(SpecificIsochoricHeatCapacity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          * 2.0,
      SpecificIsochoricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      2.0
          * SpecificIsochoricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsochoricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          * Mass(2.0, Unit::Mass::Kilogram),
      IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(Mass(2.0, Unit::Mass::Kilogram)
                * SpecificIsochoricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          - SpecificIsochoricHeatCapacity(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, AssignmentOperatorAddition) {
  SpecificIsochoricHeatCapacity quantity{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity +=
      SpecificIsochoricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(quantity, SpecificIsochoricHeatCapacity(
                          3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, AssignmentOperatorDivision) {
  SpecificIsochoricHeatCapacity quantity{
      8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(quantity, SpecificIsochoricHeatCapacity(
                          4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, AssignmentOperatorMultiplication) {
  SpecificIsochoricHeatCapacity quantity{
      4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(quantity, SpecificIsochoricHeatCapacity(
                          8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, AssignmentOperatorSubtraction) {
  SpecificIsochoricHeatCapacity quantity{
      3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity -=
      SpecificIsochoricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(quantity, SpecificIsochoricHeatCapacity(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, ComparisonOperators) {
  const SpecificIsochoricHeatCapacity first{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificIsochoricHeatCapacity second{
      2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(SpecificIsochoricHeatCapacity, CopyAssignmentOperator) {
  const SpecificIsochoricHeatCapacity first{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificIsochoricHeatCapacity second = SpecificIsochoricHeatCapacity::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(SpecificIsochoricHeatCapacity, CopyConstructor) {
  const SpecificIsochoricHeatCapacity first{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificIsochoricHeatCapacity second{first};
  EXPECT_EQ(second, first);
}

TEST(SpecificIsochoricHeatCapacity, Create) {
  constexpr SpecificIsochoricHeatCapacity quantity =
      SpecificIsochoricHeatCapacity::Create<Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>(
          1.0);
  EXPECT_EQ(quantity, SpecificIsochoricHeatCapacity(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, DefaultConstructor) {
  EXPECT_NO_THROW(SpecificIsochoricHeatCapacity{});
}

TEST(SpecificIsochoricHeatCapacity, Dimensions) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity::Dimensions(), RelatedDimensions<Unit::SpecificHeatCapacity>);
}

TEST(SpecificIsochoricHeatCapacity, Hash) {
  const SpecificIsochoricHeatCapacity first{
      1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificIsochoricHeatCapacity second{
      1.00001, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificIsochoricHeatCapacity third{
      -1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const std::hash<SpecificIsochoricHeatCapacity> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(SpecificIsochoricHeatCapacity, JSON) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          .JSON(),
      "{\"value\":" + Print(1.0) + ",\"unit\":\"J/kg/K\"}");
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
          .JSON(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
      "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ/g/K\"}");
}

TEST(SpecificIsochoricHeatCapacity, MiscellaneousConstructors) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin),
                                    Mass(4.0, Unit::Mass::Kilogram)),
      SpecificIsochoricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(Mass(IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin),
                 SpecificIsochoricHeatCapacity(
                     4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
            Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(
      IsochoricHeatCapacity(
          SpecificIsochoricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          Mass(2.0, Unit::Mass::Kilogram)),
      IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, MoveAssignmentOperator) {
  SpecificIsochoricHeatCapacity first{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificIsochoricHeatCapacity second = SpecificIsochoricHeatCapacity::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SpecificIsochoricHeatCapacity(
                        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, MoveConstructor) {
  SpecificIsochoricHeatCapacity first{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificIsochoricHeatCapacity second{std::move(first)};
  EXPECT_EQ(second, SpecificIsochoricHeatCapacity(
                        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, MutableValue) {
  SpecificIsochoricHeatCapacity quantity{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificIsochoricHeatCapacity, Print) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          .Print(),
      Print(1.0) + " J/kg/K");
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
          .Print(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
      Print(1.0) + " nJ/g/K");
}

TEST(SpecificIsochoricHeatCapacity, SetValue) {
  SpecificIsochoricHeatCapacity quantity{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificIsochoricHeatCapacity, SizeOf) {
  EXPECT_EQ(sizeof(SpecificIsochoricHeatCapacity{}), sizeof(double));
}

TEST(SpecificIsochoricHeatCapacity, StandardConstructor) {
  EXPECT_NO_THROW(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, StaticValue) {
  constexpr SpecificIsochoricHeatCapacity quantity =
      SpecificIsochoricHeatCapacity::Create<Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>(
          2.0);
  constexpr double value =
      quantity.StaticValue<Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(SpecificIsochoricHeatCapacity, Stream) {
  std::ostringstream stream;
  stream
      << SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(
      stream.str(),
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          .Print());
}

TEST(SpecificIsochoricHeatCapacity, Unit) {
  EXPECT_EQ(SpecificIsochoricHeatCapacity::Unit(), Standard<Unit::SpecificHeatCapacity>);
}

TEST(SpecificIsochoricHeatCapacity, Value) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          .Value(),
      1.0);
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(2.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
          .Value(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
      2.0);
}

TEST(SpecificIsochoricHeatCapacity, XML) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          .XML(),
      "<value>" + Print(1.0) + "</value><unit>J/kg/K</unit>");
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
          .XML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
      "<value>" + Print(1.0) + "</value><unit>nJ/g/K</unit>");
}

TEST(SpecificIsochoricHeatCapacity, YAML) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          .YAML(),
      "{value:" + Print(1.0) + ",unit:\"J/kg/K\"}");
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
          .YAML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
      "{value:" + Print(1.0) + ",unit:\"nJ/g/K\"}");
}

TEST(SpecificIsochoricHeatCapacity, Zero) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity::Zero(),
      SpecificIsochoricHeatCapacity(0.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

}  // namespace

}  // namespace PhQ
