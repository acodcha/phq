// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
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

#include "../include/PhQ/SpecificIsobaricHeatCapacity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/HeatCapacityRatio.hpp"
#include "../include/PhQ/IsobaricHeatCapacity.hpp"
#include "../include/PhQ/Mass.hpp"
#include "../include/PhQ/SpecificIsochoricHeatCapacity.hpp"
#include "../include/PhQ/Unit/HeatCapacity.hpp"
#include "../include/PhQ/Unit/Mass.hpp"
#include "../include/PhQ/Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

namespace {

TEST(SpecificIsobaricHeatCapacity, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          + SpecificIsobaricHeatCapacity(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsobaricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, ArithmeticOperatorDivision) {
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          / 2.0,
      SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                / SpecificIsobaricHeatCapacity(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            4.0);
  EXPECT_EQ(SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                / SpecificIsochoricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            HeatCapacityRatio(2.0));
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          / HeatCapacityRatio(2.0),
      SpecificIsochoricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
          / Mass(4.0, Unit::Mass::Kilogram),
      SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / SpecificIsobaricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            Mass(2.0, Unit::Mass::Kilogram));
}

TEST(SpecificIsobaricHeatCapacity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          * 2.0,
      SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      2.0
          * SpecificIsobaricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                * Mass(2.0, Unit::Mass::Kilogram),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(Mass(4.0, Unit::Mass::Kilogram)
                * SpecificIsobaricHeatCapacity(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(
      HeatCapacityRatio(2.0)
          * SpecificIsochoricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          * HeatCapacityRatio(2.0),
      SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          - SpecificIsobaricHeatCapacity(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, AssignmentOperatorAddition) {
  SpecificIsobaricHeatCapacity quantity{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity +=
      SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(quantity, SpecificIsobaricHeatCapacity(
                          3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, AssignmentOperatorDivision) {
  SpecificIsobaricHeatCapacity quantity{8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(quantity, SpecificIsobaricHeatCapacity(
                          4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, AssignmentOperatorMultiplication) {
  SpecificIsobaricHeatCapacity quantity{4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(quantity, SpecificIsobaricHeatCapacity(
                          8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, AssignmentOperatorSubtraction) {
  SpecificIsobaricHeatCapacity quantity{3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity -=
      SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(quantity, SpecificIsobaricHeatCapacity(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, ComparisonOperators) {
  const SpecificIsobaricHeatCapacity first{
      1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificIsobaricHeatCapacity second{
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

TEST(SpecificIsobaricHeatCapacity, Constructor) {
  EXPECT_NO_THROW(
      SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin));
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(
          HeatCapacityRatio(2.0), SpecificIsochoricHeatCapacity(
                                      4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin),
                                   Mass(4.0, Unit::Mass::Kilogram)),
      SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      HeatCapacityRatio(
          SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificIsochoricHeatCapacity(
              4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      HeatCapacityRatio(2.0));
  EXPECT_EQ(Mass(IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin),
                 SpecificIsobaricHeatCapacity(
                     4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
            Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(
      IsobaricHeatCapacity(
          SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          Mass(2.0, Unit::Mass::Kilogram)),
      IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(
          SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          HeatCapacityRatio(2.0)),
      SpecificIsochoricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, CopyAssignmentOperator) {
  {
    const SpecificIsobaricHeatCapacity<float> first(
        1.0F, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    SpecificIsobaricHeatCapacity<double> second = SpecificIsobaricHeatCapacity<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificIsobaricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificIsobaricHeatCapacity<double> first(
        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    SpecificIsobaricHeatCapacity<double> second = SpecificIsobaricHeatCapacity<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificIsobaricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificIsobaricHeatCapacity<long double> first(
        1.0L, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    SpecificIsobaricHeatCapacity<double> second = SpecificIsobaricHeatCapacity<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificIsobaricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
}

TEST(SpecificIsobaricHeatCapacity, CopyConstructor) {
  {
    const SpecificIsobaricHeatCapacity<float> first(
        1.0F, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    const SpecificIsobaricHeatCapacity<double> second{first};
    EXPECT_EQ(second, SpecificIsobaricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificIsobaricHeatCapacity<double> first(
        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    const SpecificIsobaricHeatCapacity<double> second{first};
    EXPECT_EQ(second, SpecificIsobaricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificIsobaricHeatCapacity<long double> first(
        1.0L, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    const SpecificIsobaricHeatCapacity<double> second{first};
    EXPECT_EQ(second, SpecificIsobaricHeatCapacity<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
}

TEST(SpecificIsobaricHeatCapacity, Create) {
  constexpr SpecificIsobaricHeatCapacity quantity =
      SpecificIsobaricHeatCapacity<>::Create<Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>(
          1.0);
  EXPECT_EQ(quantity, SpecificIsobaricHeatCapacity(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, DefaultConstructor) {
  EXPECT_NO_THROW(SpecificIsobaricHeatCapacity<>{});
}

TEST(SpecificIsobaricHeatCapacity, Dimensions) {
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity<>::Dimensions(), RelatedDimensions<Unit::SpecificHeatCapacity>);
}

TEST(SpecificIsobaricHeatCapacity, Hash) {
  const SpecificIsobaricHeatCapacity first{
      1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificIsobaricHeatCapacity second{
      1.00001, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificIsobaricHeatCapacity third{
      -1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const std::hash<SpecificIsobaricHeatCapacity<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(SpecificIsobaricHeatCapacity, JSON) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"J/kg/K\"}");
  EXPECT_EQ(SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .JSON(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ/g/K\"}");
}

TEST(SpecificIsobaricHeatCapacity, MoveAssignmentOperator) {
  SpecificIsobaricHeatCapacity first{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificIsobaricHeatCapacity second = SpecificIsobaricHeatCapacity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, SpecificIsobaricHeatCapacity(
                        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, MoveConstructor) {
  SpecificIsobaricHeatCapacity first{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificIsobaricHeatCapacity second{std::move(first)};
  EXPECT_EQ(second, SpecificIsobaricHeatCapacity(
                        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificIsobaricHeatCapacity, MutableValue) {
  SpecificIsobaricHeatCapacity quantity{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificIsobaricHeatCapacity, Print) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .Print(),
            Print(1.0) + " J/kg/K");
  EXPECT_EQ(SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .Print(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            Print(1.0) + " nJ/g/K");
}

TEST(SpecificIsobaricHeatCapacity, SetValue) {
  SpecificIsobaricHeatCapacity quantity{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificIsobaricHeatCapacity, SizeOf) {
  EXPECT_EQ(sizeof(SpecificIsobaricHeatCapacity<>{}), sizeof(double));
}

TEST(SpecificIsobaricHeatCapacity, StaticValue) {
  constexpr SpecificIsobaricHeatCapacity quantity =
      SpecificIsobaricHeatCapacity<>::Create<Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>(
          2.0);
  constexpr double value =
      quantity.StaticValue<Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(SpecificIsobaricHeatCapacity, Stream) {
  std::ostringstream stream;
  stream
      << SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(stream.str(),
            SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .Print());
}

TEST(SpecificIsobaricHeatCapacity, Unit) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity<>::Unit(), Standard<Unit::SpecificHeatCapacity>);
}

TEST(SpecificIsobaricHeatCapacity, Value) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .Value(),
            1.0);
  EXPECT_EQ(SpecificIsobaricHeatCapacity(2.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .Value(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            2.0);
}

TEST(SpecificIsobaricHeatCapacity, XML) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .XML(),
            "<value>" + Print(1.0) + "</value><unit>J/kg/K</unit>");
  EXPECT_EQ(SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .XML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "<value>" + Print(1.0) + "</value><unit>nJ/g/K</unit>");
}

TEST(SpecificIsobaricHeatCapacity, YAML) {
  EXPECT_EQ(SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                .YAML(),
            "{value:" + Print(1.0) + ",unit:\"J/kg/K\"}");
  EXPECT_EQ(SpecificIsobaricHeatCapacity(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .YAML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "{value:" + Print(1.0) + ",unit:\"nJ/g/K\"}");
}

TEST(SpecificIsobaricHeatCapacity, Zero) {
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity<>::Zero(),
      SpecificIsobaricHeatCapacity(0.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

}  // namespace

}  // namespace PhQ
