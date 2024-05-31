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

#include "../include/PhQ/IsochoricHeatCapacity.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/HeatCapacity.hpp"

namespace PhQ {

namespace {

TEST(IsochoricHeatCapacity, ArithmeticOperatorAddition) {
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin)
                + IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            IsochoricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, ArithmeticOperatorDivision) {
  EXPECT_EQ(IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin) / 2.0,
            IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin)
                / IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            4.0);
}

TEST(IsochoricHeatCapacity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin) * 2.0,
            IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
  EXPECT_EQ(2.0 * IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin),
            IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(IsochoricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin)
                - IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin),
            IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, AssignmentOperatorAddition) {
  IsochoricHeatCapacity isochoric_heat_capacity{1.0, Unit::HeatCapacity::JoulePerKelvin};
  isochoric_heat_capacity += IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(
      isochoric_heat_capacity, IsochoricHeatCapacity(3.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, AssignmentOperatorDivision) {
  IsochoricHeatCapacity isochoric_heat_capacity{8.0, Unit::HeatCapacity::JoulePerKelvin};
  isochoric_heat_capacity /= 2.0;
  EXPECT_EQ(
      isochoric_heat_capacity, IsochoricHeatCapacity(4.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, AssignmentOperatorMultiplication) {
  IsochoricHeatCapacity isochoric_heat_capacity{4.0, Unit::HeatCapacity::JoulePerKelvin};
  isochoric_heat_capacity *= 2.0;
  EXPECT_EQ(
      isochoric_heat_capacity, IsochoricHeatCapacity(8.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, AssignmentOperatorSubtraction) {
  IsochoricHeatCapacity isochoric_heat_capacity{3.0, Unit::HeatCapacity::JoulePerKelvin};
  isochoric_heat_capacity -= IsochoricHeatCapacity(2.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(
      isochoric_heat_capacity, IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, ComparisonOperators) {
  const IsochoricHeatCapacity first{1.0, Unit::HeatCapacity::JoulePerKelvin};
  const IsochoricHeatCapacity second{2.0, Unit::HeatCapacity::JoulePerKelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(IsochoricHeatCapacity, Constructor) {
  EXPECT_NO_THROW(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::NanojoulePerKelvin));
}

TEST(IsochoricHeatCapacity, CopyAssignmentOperator) {
  {
    const IsochoricHeatCapacity<float> first(1.0F, Unit::HeatCapacity::JoulePerKelvin);
    IsochoricHeatCapacity<double> second = IsochoricHeatCapacity<double>::Zero();
    second = first;
    EXPECT_EQ(second, IsochoricHeatCapacity<double>(1.0, Unit::HeatCapacity::JoulePerKelvin));
  }
  {
    const IsochoricHeatCapacity<double> first(1.0, Unit::HeatCapacity::JoulePerKelvin);
    IsochoricHeatCapacity<double> second = IsochoricHeatCapacity<double>::Zero();
    second = first;
    EXPECT_EQ(second, IsochoricHeatCapacity<double>(1.0, Unit::HeatCapacity::JoulePerKelvin));
  }
  {
    const IsochoricHeatCapacity<long double> first(1.0L, Unit::HeatCapacity::JoulePerKelvin);
    IsochoricHeatCapacity<double> second = IsochoricHeatCapacity<double>::Zero();
    second = first;
    EXPECT_EQ(second, IsochoricHeatCapacity<double>(1.0, Unit::HeatCapacity::JoulePerKelvin));
  }
}

TEST(IsochoricHeatCapacity, CopyConstructor) {
  {
    const IsochoricHeatCapacity<float> first(1.0F, Unit::HeatCapacity::JoulePerKelvin);
    const IsochoricHeatCapacity<double> second{first};
    EXPECT_EQ(second, IsochoricHeatCapacity<double>(1.0, Unit::HeatCapacity::JoulePerKelvin));
  }
  {
    const IsochoricHeatCapacity<double> first(1.0, Unit::HeatCapacity::JoulePerKelvin);
    const IsochoricHeatCapacity<double> second{first};
    EXPECT_EQ(second, IsochoricHeatCapacity<double>(1.0, Unit::HeatCapacity::JoulePerKelvin));
  }
  {
    const IsochoricHeatCapacity<long double> first(1.0L, Unit::HeatCapacity::JoulePerKelvin);
    const IsochoricHeatCapacity<double> second{first};
    EXPECT_EQ(second, IsochoricHeatCapacity<double>(1.0, Unit::HeatCapacity::JoulePerKelvin));
  }
}

TEST(IsochoricHeatCapacity, Create) {
  constexpr IsochoricHeatCapacity isochoric_heat_capacity =
      IsochoricHeatCapacity<>::Create<Unit::HeatCapacity::JoulePerKelvin>(1.0);
  EXPECT_EQ(
      isochoric_heat_capacity, IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, DefaultConstructor) {
  EXPECT_NO_THROW(IsochoricHeatCapacity<>{});
}

TEST(IsochoricHeatCapacity, Dimensions) {
  EXPECT_EQ(IsochoricHeatCapacity<>::Dimensions(), RelatedDimensions<Unit::HeatCapacity>);
}

TEST(IsochoricHeatCapacity, Hash) {
  const IsochoricHeatCapacity first{1.0, Unit::HeatCapacity::NanojoulePerKelvin};
  const IsochoricHeatCapacity second{1.00001, Unit::HeatCapacity::NanojoulePerKelvin};
  const IsochoricHeatCapacity third{-1.0, Unit::HeatCapacity::NanojoulePerKelvin};
  const std::hash<IsochoricHeatCapacity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(IsochoricHeatCapacity, JSON) {
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"J/K\"}");
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .JSON(Unit::HeatCapacity::NanojoulePerKelvin),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"nJ/K\"}");
}

TEST(IsochoricHeatCapacity, MoveAssignmentOperator) {
  IsochoricHeatCapacity first{1.0, Unit::HeatCapacity::JoulePerKelvin};
  IsochoricHeatCapacity second = IsochoricHeatCapacity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, MoveConstructor) {
  IsochoricHeatCapacity first{1.0, Unit::HeatCapacity::JoulePerKelvin};
  const IsochoricHeatCapacity second{std::move(first)};
  EXPECT_EQ(second, IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin));
}

TEST(IsochoricHeatCapacity, MutableValue) {
  IsochoricHeatCapacity isochoric_heat_capacity{1.0, Unit::HeatCapacity::JoulePerKelvin};
  double& value = isochoric_heat_capacity.MutableValue();
  value = 2.0;
  EXPECT_EQ(isochoric_heat_capacity.Value(), 2.0);
}

TEST(IsochoricHeatCapacity, Print) {
  EXPECT_EQ(
      IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin).Print(), Print(1.0) + " J/K");
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .Print(Unit::HeatCapacity::NanojoulePerKelvin),
            Print(1.0) + " nJ/K");
}

TEST(IsochoricHeatCapacity, SetValue) {
  IsochoricHeatCapacity isochoric_heat_capacity{1.0, Unit::HeatCapacity::JoulePerKelvin};
  isochoric_heat_capacity.SetValue(2.0);
  EXPECT_EQ(isochoric_heat_capacity.Value(), 2.0);
}

TEST(IsochoricHeatCapacity, SizeOf) {
  EXPECT_EQ(sizeof(IsochoricHeatCapacity<>{}), sizeof(double));
}

TEST(IsochoricHeatCapacity, StaticValue) {
  constexpr IsochoricHeatCapacity isochoric_heat_capacity =
      IsochoricHeatCapacity<>::Create<Unit::HeatCapacity::NanojoulePerKelvin>(2.0);
  constexpr double value =
      isochoric_heat_capacity.StaticValue<Unit::HeatCapacity::NanojoulePerKelvin>();
  EXPECT_EQ(value, 2.0);
}

TEST(IsochoricHeatCapacity, Stream) {
  std::ostringstream stream;
  stream << IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin);
  EXPECT_EQ(stream.str(), IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin).Print());
}

TEST(IsochoricHeatCapacity, Unit) {
  EXPECT_EQ(IsochoricHeatCapacity<>::Unit(), Standard<Unit::HeatCapacity>);
}

TEST(IsochoricHeatCapacity, Value) {
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin).Value(), 1.0);
  EXPECT_EQ(IsochoricHeatCapacity(2.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .Value(Unit::HeatCapacity::NanojoulePerKelvin),
            2.0);
}

TEST(IsochoricHeatCapacity, XML) {
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>J/K</unit>");
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .XML(Unit::HeatCapacity::NanojoulePerKelvin),
            "<value>" + Print(1.0) + "</value><unit>nJ/K</unit>");
}

TEST(IsochoricHeatCapacity, YAML) {
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::JoulePerKelvin).YAML(),
            "{value:" + Print(1.0) + ",unit:\"J/K\"}");
  EXPECT_EQ(IsochoricHeatCapacity(1.0, Unit::HeatCapacity::NanojoulePerKelvin)
                .YAML(Unit::HeatCapacity::NanojoulePerKelvin),
            "{value:" + Print(1.0) + ",unit:\"nJ/K\"}");
}

TEST(IsochoricHeatCapacity, Zero) {
  EXPECT_EQ(IsochoricHeatCapacity<>::Zero(),
            IsochoricHeatCapacity(0.0, Unit::HeatCapacity::JoulePerKelvin));
}

}  // namespace

}  // namespace PhQ
