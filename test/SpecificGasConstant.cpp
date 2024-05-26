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

#include "../include/PhQ/SpecificGasConstant.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/GasConstant.hpp"
#include "../include/PhQ/HeatCapacityRatio.hpp"
#include "../include/PhQ/Mass.hpp"
#include "../include/PhQ/SpecificIsobaricHeatCapacity.hpp"
#include "../include/PhQ/SpecificIsochoricHeatCapacity.hpp"
#include "../include/PhQ/Unit/HeatCapacity.hpp"
#include "../include/PhQ/Unit/Mass.hpp"
#include "../include/PhQ/Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

namespace {

TEST(SpecificGasConstant, ArithmeticOperatorAddition) {
  EXPECT_EQ(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                + SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificGasConstant(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          + SpecificIsochoricHeatCapacity(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsobaricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          + SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsobaricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, ArithmeticOperatorDivision) {
  EXPECT_EQ(SpecificGasConstant(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin) / 2.0,
            SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(SpecificGasConstant(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                / SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            4.0);
  EXPECT_EQ(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin) / Mass(4.0, Unit::Mass::Kilogram),
            SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            Mass(2.0, Unit::Mass::Kilogram));
}

TEST(SpecificGasConstant, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin) * 2.0,
            SpecificGasConstant(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(2.0 * SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificGasConstant(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                * Mass(2.0, Unit::Mass::Kilogram),
            GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(Mass(4.0, Unit::Mass::Kilogram)
                * SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(SpecificGasConstant, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(SpecificGasConstant(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                - SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(SpecificIsobaricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
                - SpecificIsochoricHeatCapacity(
                    2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
            SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)
          - SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
      SpecificIsochoricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, AssignmentOperatorAddition) {
  SpecificGasConstant quantity{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity += SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(
      quantity, SpecificGasConstant(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, AssignmentOperatorDivision) {
  SpecificGasConstant quantity{8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity /= 2.0;
  EXPECT_EQ(
      quantity, SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, AssignmentOperatorMultiplication) {
  SpecificGasConstant quantity{4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity *= 2.0;
  EXPECT_EQ(
      quantity, SpecificGasConstant(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, AssignmentOperatorSubtraction) {
  SpecificGasConstant quantity{3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity -= SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(
      quantity, SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, ComparisonOperators) {
  const SpecificGasConstant first{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificGasConstant second{2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
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
  {
    const SpecificGasConstant<float> first(
        1.0F, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    SpecificGasConstant<double> second = SpecificGasConstant<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificGasConstant<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificGasConstant<double> first(
        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    SpecificGasConstant<double> second = SpecificGasConstant<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificGasConstant<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificGasConstant<long double> first(
        1.0L, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    SpecificGasConstant<double> second = SpecificGasConstant<double>::Zero();
    second = first;
    EXPECT_EQ(second, SpecificGasConstant<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
}

TEST(SpecificGasConstant, CopyConstructor) {
  {
    const SpecificGasConstant<float> first(
        1.0F, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    const SpecificGasConstant<double> second{first};
    EXPECT_EQ(second, SpecificGasConstant<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificGasConstant<double> first(
        1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    const SpecificGasConstant<double> second{first};
    EXPECT_EQ(second, SpecificGasConstant<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
  {
    const SpecificGasConstant<long double> first(
        1.0L, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
    const SpecificGasConstant<double> second{first};
    EXPECT_EQ(second, SpecificGasConstant<double>(
                          1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  }
}

TEST(SpecificGasConstant, Create) {
  constexpr SpecificGasConstant quantity =
      SpecificGasConstant<>::Create<Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin>(1.0);
  EXPECT_EQ(
      quantity, SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, DefaultConstructor) {
  EXPECT_NO_THROW(SpecificGasConstant<>{});
}

TEST(SpecificGasConstant, Dimensions) {
  EXPECT_EQ(SpecificGasConstant<>::Dimensions(), RelatedDimensions<Unit::SpecificHeatCapacity>);
}

TEST(SpecificGasConstant, Hash) {
  const SpecificGasConstant first{1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificGasConstant second{1.00001, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const SpecificGasConstant third{-1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin};
  const std::hash<SpecificGasConstant<>> hasher;
  EXPECT_NE(hasher(first), hasher(second));
  EXPECT_NE(hasher(first), hasher(third));
  EXPECT_NE(hasher(second), hasher(third));
}

TEST(SpecificGasConstant, JSON) {
  EXPECT_EQ(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"J/kg/K\"}");
  EXPECT_EQ(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .JSON(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ/g/K\"}");
}

TEST(SpecificGasConstant, MiscellaneousConstructors) {
  EXPECT_EQ(
      SpecificGasConstant(
          SpecificIsobaricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificIsochoricHeatCapacity(
              2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificGasConstant(
          HeatCapacityRatio(2.0),
          SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(SpecificGasConstant(HeatCapacityRatio(2.0),
                                SpecificIsochoricHeatCapacity(
                                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
            SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(SpecificGasConstant(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin),
                                Mass(4.0, Unit::Mass::Kilogram)),
            SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      HeatCapacityRatio(
          SpecificIsobaricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      HeatCapacityRatio(2.0));
  EXPECT_EQ(HeatCapacityRatio(
                SpecificGasConstant(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
                SpecificIsochoricHeatCapacity(
                    4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
            HeatCapacityRatio(3.0));
  EXPECT_EQ(Mass(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin),
                 SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
            Mass(2.0, Unit::Mass::Kilogram));
  EXPECT_EQ(
      GasConstant(SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
                  Mass(2.0, Unit::Mass::Kilogram)),
      GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(
          SpecificIsobaricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificIsochoricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificIsochoricHeatCapacity(
          SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          HeatCapacityRatio(2.0)),
      SpecificIsochoricHeatCapacity(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(
          SpecificIsochoricHeatCapacity(2.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin),
          SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificIsobaricHeatCapacity(3.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
  EXPECT_EQ(
      SpecificIsobaricHeatCapacity(
          HeatCapacityRatio(2.0),
          SpecificGasConstant(4.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin)),
      SpecificIsobaricHeatCapacity(8.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, MoveAssignmentOperator) {
  SpecificGasConstant first{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  SpecificGasConstant second = SpecificGasConstant<>::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, MoveConstructor) {
  SpecificGasConstant first{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  const SpecificGasConstant second{std::move(first)};
  EXPECT_EQ(
      second, SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

TEST(SpecificGasConstant, MutableValue) {
  SpecificGasConstant quantity{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificGasConstant, Print) {
  EXPECT_EQ(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin).Print(),
            Print(1.0) + " J/kg/K");
  EXPECT_EQ(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .Print(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            Print(1.0) + " nJ/g/K");
}

TEST(SpecificGasConstant, SetValue) {
  SpecificGasConstant quantity{1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(SpecificGasConstant, SizeOf) {
  EXPECT_EQ(sizeof(SpecificGasConstant<>{}), sizeof(double));
}

TEST(SpecificGasConstant, StandardConstructor) {
  EXPECT_NO_THROW(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin));
}

TEST(SpecificGasConstant, StaticValue) {
  constexpr SpecificGasConstant quantity =
      SpecificGasConstant<>::Create<Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>(2.0);
  constexpr double value =
      quantity.StaticValue<Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(SpecificGasConstant, Stream) {
  std::ostringstream stream;
  stream << SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin);
  EXPECT_EQ(
      stream.str(),
      SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin).Print());
}

TEST(SpecificGasConstant, Unit) {
  EXPECT_EQ(SpecificGasConstant<>::Unit(), Standard<Unit::SpecificHeatCapacity>);
}

TEST(SpecificGasConstant, Value) {
  EXPECT_EQ(
      SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin).Value(), 1.0);
  EXPECT_EQ(SpecificGasConstant(2.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .Value(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            2.0);
}

TEST(SpecificGasConstant, XML) {
  EXPECT_EQ(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>J/kg/K</unit>");
  EXPECT_EQ(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .XML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "<value>" + Print(1.0) + "</value><unit>nJ/g/K</unit>");
}

TEST(SpecificGasConstant, YAML) {
  EXPECT_EQ(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin).YAML(),
            "{value:" + Print(1.0) + ",unit:\"J/kg/K\"}");
  EXPECT_EQ(SpecificGasConstant(1.0, Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin)
                .YAML(Unit::SpecificHeatCapacity::NanojoulePerGramPerKelvin),
            "{value:" + Print(1.0) + ",unit:\"nJ/g/K\"}");
}

TEST(SpecificGasConstant, Zero) {
  EXPECT_EQ(SpecificGasConstant<>::Zero(),
            SpecificGasConstant(0.0, Unit::SpecificHeatCapacity::JoulePerKilogramPerKelvin));
}

}  // namespace

}  // namespace PhQ
