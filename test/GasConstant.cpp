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

#include "../include/PhQ/GasConstant.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/HeatCapacityRatio.hpp"
#include "../include/PhQ/IsobaricHeatCapacity.hpp"
#include "../include/PhQ/IsochoricHeatCapacity.hpp"
#include "../include/PhQ/Unit/HeatCapacity.hpp"

namespace PhQ {

namespace {

TEST(GasConstant, ArithmeticOperatorAddition) {
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin)
                + GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin),
            GasConstant(3.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin)
                + IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin)
                + GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin),
            IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, ArithmeticOperatorDivision) {
  EXPECT_EQ(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin) / 2.0,
            GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin),
            4.0);
}

TEST(GasConstant, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin) * 2.0,
            GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(2.0 * GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin),
            GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(GasConstant(3.0, Unit::HeatCapacity::JoulePerKelvin)
                - GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin),
            GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin)
                - IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin)
                - GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin),
            IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, AssignmentOperatorAddition) {
  GasConstant gas_constant{1.0, Unit::HeatCapacity::JoulePerKelvin};
  gas_constant += GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(gas_constant, GasConstant(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, AssignmentOperatorDivision) {
  GasConstant gas_constant{8.0, Unit::HeatCapacity::JoulePerKelvin};
  gas_constant /= 2.0;
  EXPECT_EQ(gas_constant, GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, AssignmentOperatorMultiplication) {
  GasConstant gas_constant{4.0, Unit::HeatCapacity::JoulePerKelvin};
  gas_constant *= 2.0;
  EXPECT_EQ(gas_constant, GasConstant(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, AssignmentOperatorSubtraction) {
  GasConstant gas_constant{3.0, Unit::HeatCapacity::JoulePerKelvin};
  gas_constant -= GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(gas_constant, GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, ComparisonOperators) {
  const GasConstant first{1.0, Unit::HeatCapacity::JoulePerKelvin};
  const GasConstant second{2.0, Unit::HeatCapacity::JoulePerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(GasConstant, CopyAssignmentOperator) {
  const GasConstant first{1.0, Unit::HeatCapacity::JoulePerKelvin};
  GasConstant second = GasConstant<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(GasConstant, CopyConstructor) {
  const GasConstant first{1.0, Unit::HeatCapacity::JoulePerKelvin};
  const GasConstant second{first};
  EXPECT_EQ(second, first);
}

TEST(GasConstant, Create) {
  constexpr GasConstant gas_constant =
      GasConstant<>::Create<Unit::HeatCapacity::JoulePerKelvin>(1.0);
  EXPECT_EQ(gas_constant, GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, DefaultConstructor) {
  EXPECT_NO_THROW(GasConstant<>{});
}

TEST(GasConstant, Dimensions) {
  EXPECT_EQ(GasConstant<>::Dimensions(), RelatedDimensions<Unit::HeatCapacity>);
}

TEST(GasConstant, Hash) {
  const GasConstant first{1.0, Unit::HeatCapacity::NanojoulePerKelvin};
  const GasConstant second{1.000001, Unit::HeatCapacity::NanojoulePerKelvin};
  const GasConstant third{-1.0, Unit::HeatCapacity::NanojoulePerKelvin};
  const std::hash<GasConstant<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(GasConstant, JSON) {
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"J/K\"}");
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .JSON(Unit::HeatCapacity::NanojoulePerKelvin),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ/K\"}");
}

TEST(GasConstant, MiscellaneousConstructors) {
  EXPECT_EQ(GasConstant(IsobaricHeatCapacity(6.0, Unit::HeatCapacity::JoulePerKelvin),
                        IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin)),
            GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(GasConstant(HeatCapacityRatio(2.0),
                        IsobaricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin)),
            GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(GasConstant(HeatCapacityRatio(2.0),
                        IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin)),
            GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(HeatCapacityRatio(IsobaricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin),
                              GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin)),
            HeatCapacityRatio(2.0));
  EXPECT_EQ(HeatCapacityRatio(GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin),
                              IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin)),
            HeatCapacityRatio(3.0));
  EXPECT_EQ(IsochoricHeatCapacity(IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin),
                                  GasConstant(2.0, Unit::HeatCapacity::JoulePerKelvin)),
            IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(IsochoricHeatCapacity(
                GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin), HeatCapacityRatio(2.0)),
            IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(IsobaricHeatCapacity(IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
                                 GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin)),
            IsobaricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(IsobaricHeatCapacity(
                HeatCapacityRatio(2.0), GasConstant(4.0, Unit::HeatCapacity::JoulePerKelvin)),
            IsobaricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, MoveAssignmentOperator) {
  GasConstant first{1.0, Unit::HeatCapacity::JoulePerKelvin};
  GasConstant second = GasConstant<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, MoveConstructor) {
  GasConstant first{1.0, Unit::HeatCapacity::JoulePerKelvin};
  const GasConstant second{std::move(first)};
  EXPECT_EQ(second, GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(GasConstant, MutableValue) {
  GasConstant gas_constant{1.0, Unit::HeatCapacity::JoulePerKelvin};
  double& value = gas_constant.MutableValue();
  value = 2.0;
  EXPECT_EQ(gas_constant.Value(), 2.0);
}

TEST(GasConstant, Print) {
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin).Print(), Print(1.0) + " J/K");
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .Print(Unit::HeatCapacity::NanojoulePerKelvin),
            Print(1.0) + " nJ/K");
}

TEST(GasConstant, SetValue) {
  GasConstant gas_constant{1.0, Unit::HeatCapacity::JoulePerKelvin};
  gas_constant.SetValue(2.0);
  EXPECT_EQ(gas_constant.Value(), 2.0);
}

TEST(GasConstant, SizeOf) {
  EXPECT_EQ(sizeof(GasConstant<>{}), sizeof(double));
}

TEST(GasConstant, StandardConstructor) {
  EXPECT_NO_THROW(GasConstant(1.0, Unit::HeatCapacity::NanojoulePerKelvin));
}

TEST(GasConstant, StaticValue) {
  constexpr GasConstant gas_constant =
      GasConstant<>::Create<Unit::HeatCapacity::NanojoulePerKelvin>(1.0);
  constexpr double value = gas_constant.StaticValue<Unit::HeatCapacity::NanojoulePerKelvin>();
  EXPECT_EQ(value, 1.0);
}

TEST(GasConstant, Stream) {
  std::ostringstream stream;
  stream << GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(stream.str(), GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin).Print());
}

TEST(GasConstant, Unit) {
  EXPECT_EQ(GasConstant<>::Unit(), Standard<Unit::HeatCapacity>);
}

TEST(GasConstant, Value) {
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin).Value(), 1.0);
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .Value(Unit::HeatCapacity::NanojoulePerKelvin),
            1.0);
}

TEST(GasConstant, XML) {
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>J/K</unit>");
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .XML(Unit::HeatCapacity::NanojoulePerKelvin),
            "<value>" + Print(1.0) + "</value><unit>nJ/K</unit>");
}

TEST(GasConstant, YAML) {
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::JoulePerKelvin).YAML(),
            "{value:" + Print(1.0) + ",unit:\"J/K\"}");
  EXPECT_EQ(GasConstant(1.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .YAML(Unit::HeatCapacity::NanojoulePerKelvin),
            "{value:" + Print(1.0) + ",unit:\"nJ/K\"}");
}

TEST(GasConstant, Zero) {
  EXPECT_EQ(GasConstant<>::Zero(), GasConstant(0.0, Unit::HeatCapacity::JoulePerKelvin));
}

}  // namespace

}  // namespace PhQ
