// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

TEST(SpecificIsochoricHeatCapacity, Constructor) {
  EXPECT_NO_THROW(
      SpecificIsochoricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin));
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

TEST(SpecificIsochoricHeatCapacity, CopyAssignmentOperator) {
  {
    const SpecificIsochoricHeatCapacity<float> first(
        1.0F, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    SpecificIsochoricHeatCapacity<double> second = SpecificIsochoricHeatCapacity<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificIsochoricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificIsochoricHeatCapacity<double> first(
        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    SpecificIsochoricHeatCapacity<double> second = SpecificIsochoricHeatCapacity<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificIsochoricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificIsochoricHeatCapacity<long double> first(
        1.0L, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    SpecificIsochoricHeatCapacity<double> second = SpecificIsochoricHeatCapacity<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificIsochoricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
}

TEST(SpecificIsochoricHeatCapacity, CopyConstructor) {
  {
    const SpecificIsochoricHeatCapacity<float> first(
        1.0F, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    const SpecificIsochoricHeatCapacity<double> second{first};
    EXPECT_EQ(second, SpecificIsochoricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificIsochoricHeatCapacity<double> first(
        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    const SpecificIsochoricHeatCapacity<double> second{first};
    EXPECT_EQ(second, SpecificIsochoricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificIsochoricHeatCapacity<long double> first(
        1.0L, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    const SpecificIsochoricHeatCapacity<double> second{first};
    EXPECT_EQ(second, SpecificIsochoricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
}

TEST(SpecificIsochoricHeatCapacity, Create) {
  constexpr SpecificIsochoricHeatCapacity quantity = SpecificIsochoricHeatCapacity<>::Create<
      Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>(1.0);
  EXPECT_EQ(quantity, SpecificIsochoricHeatCapacity(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsochoricHeatCapacity, DefaultConstructor) {
  EXPECT_NO_THROW(SpecificIsochoricHeatCapacity<>{});
}

TEST(SpecificIsochoricHeatCapacity, Dimensions) {
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity<>::Dimensions(), RelatedDimensions<Unit::SpecificHeatCapacity>);
}

TEST(SpecificIsochoricHeatCapacity, Hash) {
  const SpecificIsochoricHeatCapacity first{
      1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificIsochoricHeatCapacity second{
      1.00001, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificIsochoricHeatCapacity third{
      -1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const std::hash<SpecificIsochoricHeatCapacity<>> hasher;
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

TEST(SpecificIsochoricHeatCapacity, MoveAssignmentOperator) {
  SpecificIsochoricHeatCapacity first{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificIsochoricHeatCapacity second = SpecificIsochoricHeatCapacity<>::Zero();
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
  EXPECT_EQ(sizeof(SpecificIsochoricHeatCapacity<>{}), sizeof(double));
}

TEST(SpecificIsochoricHeatCapacity, StaticValue) {
  constexpr SpecificIsochoricHeatCapacity quantity = SpecificIsochoricHeatCapacity<>::Create<
      Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>(2.0);
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
  EXPECT_EQ(SpecificIsochoricHeatCapacity<>::Unit(), Standard<Unit::SpecificHeatCapacity>);
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
      SpecificIsochoricHeatCapacity<>::Zero(),
      SpecificIsochoricHeatCapacity(0.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

}  // namespace

}  // namespace PhQ
