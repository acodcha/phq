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

#include "../include/PhQ/Temperature.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/Temperature.hpp"
#include "../include/PhQ/Unit/TemperatureDifference.hpp"

namespace PhQ {

namespace {

TEST(Temperature, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      Temperature(1.0, Unit::Temperature::Kelvin) + Temperature(2.0, Unit::Temperature::Kelvin),
      Temperature(3.0, Unit::Temperature::Kelvin));
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin)
                + TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            Temperature(3.0, Unit::Temperature::Kelvin));
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin)
                + Temperature(2.0, Unit::Temperature::Kelvin),
            Temperature(3.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, ArithmeticOperatorDivision) {
  EXPECT_EQ(Temperature(8.0, Unit::Temperature::Kelvin) / 2.0,
            Temperature(4.0, Unit::Temperature::Kelvin));
  EXPECT_EQ(
      Temperature(8.0, Unit::Temperature::Kelvin) / Temperature(2.0, Unit::Temperature::Kelvin),
      4.0);
}

TEST(Temperature, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Temperature(4.0, Unit::Temperature::Kelvin) * 2.0,
            Temperature(8.0, Unit::Temperature::Kelvin));
  EXPECT_EQ(2.0 * Temperature(4.0, Unit::Temperature::Kelvin),
            Temperature(8.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      Temperature(3.0, Unit::Temperature::Kelvin) - Temperature(2.0, Unit::Temperature::Kelvin),
      TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
  EXPECT_EQ(Temperature(3.0, Unit::Temperature::Kelvin)
                - TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            Temperature(1.0, Unit::Temperature::Kelvin));
  EXPECT_EQ(TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin)
                - Temperature(2.0, Unit::Temperature::Kelvin),
            Temperature(1.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, AssignmentOperatorAddition) {
  {
    Temperature temperature{1.0, Unit::Temperature::Kelvin};
    temperature += Temperature(2.0, Unit::Temperature::Kelvin);
    EXPECT_EQ(temperature, Temperature(3.0, Unit::Temperature::Kelvin));
  }
  {
    Temperature temperature{1.0, Unit::Temperature::Kelvin};
    temperature += TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
    EXPECT_EQ(temperature, Temperature(3.0, Unit::Temperature::Kelvin));
  }
}

TEST(Temperature, AssignmentOperatorDivision) {
  Temperature temperature{8.0, Unit::Temperature::Kelvin};
  temperature /= 2.0;
  EXPECT_EQ(temperature, Temperature(4.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, AssignmentOperatorMultiplication) {
  Temperature temperature{4.0, Unit::Temperature::Kelvin};
  temperature *= 2.0;
  EXPECT_EQ(temperature, Temperature(8.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, AssignmentOperatorSubtraction) {
  {
    Temperature temperature{3.0, Unit::Temperature::Kelvin};
    temperature -= Temperature(2.0, Unit::Temperature::Kelvin);
    EXPECT_EQ(temperature, Temperature(1.0, Unit::Temperature::Kelvin));
  }
  {
    Temperature temperature{3.0, Unit::Temperature::Kelvin};
    temperature -= TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
    EXPECT_EQ(temperature, Temperature(1.0, Unit::Temperature::Kelvin));
  }
}

TEST(Temperature, ComparisonOperators) {
  const Temperature first{1.0, Unit::Temperature::Kelvin};
  const Temperature second{2.0, Unit::Temperature::Kelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Temperature, Constructor) {
  EXPECT_NO_THROW(Temperature(1.0, Unit::Temperature::Rankine));
}

TEST(Temperature, CopyAssignmentOperator) {
  {
    const Temperature<float> first(1.0F, Unit::Temperature::Kelvin);
    Temperature<double> second = Temperature<double>::Zero();
    second = first;
    EXPECT_EQ(second, Temperature<double>(1.0, Unit::Temperature::Kelvin));
  }
  {
    const Temperature<double> first(1.0, Unit::Temperature::Kelvin);
    Temperature<double> second = Temperature<double>::Zero();
    second = first;
    EXPECT_EQ(second, Temperature<double>(1.0, Unit::Temperature::Kelvin));
  }
  {
    const Temperature<long double> first(1.0L, Unit::Temperature::Kelvin);
    Temperature<double> second = Temperature<double>::Zero();
    second = first;
    EXPECT_EQ(second, Temperature<double>(1.0, Unit::Temperature::Kelvin));
  }
}

TEST(Temperature, CopyConstructor) {
  {
    const Temperature<float> first(1.0F, Unit::Temperature::Kelvin);
    const Temperature<double> second{first};
    EXPECT_EQ(second, Temperature<double>(1.0, Unit::Temperature::Kelvin));
  }
  {
    const Temperature<double> first(1.0, Unit::Temperature::Kelvin);
    const Temperature<double> second{first};
    EXPECT_EQ(second, Temperature<double>(1.0, Unit::Temperature::Kelvin));
  }
  {
    const Temperature<long double> first(1.0L, Unit::Temperature::Kelvin);
    const Temperature<double> second{first};
    EXPECT_EQ(second, Temperature<double>(1.0, Unit::Temperature::Kelvin));
  }
}

TEST(Temperature, Create) {
  constexpr Temperature temperature = Temperature<>::Create<Unit::Temperature::Kelvin>(1.0);
  EXPECT_EQ(temperature, Temperature(1.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, DefaultConstructor) {
  EXPECT_NO_THROW(Temperature<>{});
}

TEST(Temperature, Dimensions) {
  EXPECT_EQ(Temperature<>::Dimensions(), RelatedDimensions<Unit::Temperature>);
}

TEST(Temperature, Hash) {
  const Temperature first{1.0, Unit::Temperature::Kelvin};
  const Temperature second{1.000001, Unit::Temperature::Kelvin};
  const Temperature third{-1.0, Unit::Temperature::Kelvin};
  const std::hash<Temperature<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Temperature, JSON) {
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"K\"}");
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).JSON(Unit::Temperature::Rankine),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"°R\"}");
}

TEST(Temperature, MoveAssignmentOperator) {
  Temperature first{1.0, Unit::Temperature::Kelvin};
  Temperature second = Temperature<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Temperature(1.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, MoveConstructor) {
  Temperature first{1.0, Unit::Temperature::Kelvin};
  const Temperature second{std::move(first)};
  EXPECT_EQ(second, Temperature(1.0, Unit::Temperature::Kelvin));
}

TEST(Temperature, MutableValue) {
  Temperature temperature{1.0, Unit::Temperature::Kelvin};
  double& value = temperature.MutableValue();
  value = 2.0;
  EXPECT_EQ(temperature.Value(), 2.0);
}

TEST(Temperature, Print) {
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin).Print(), Print(1.0) + " K");
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).Print(Unit::Temperature::Rankine),
            Print(1.0) + " °R");
}

TEST(Temperature, SetValue) {
  Temperature temperature{1.0, Unit::Temperature::Kelvin};
  temperature.SetValue(2.0);
  EXPECT_EQ(temperature.Value(), 2.0);
}

TEST(Temperature, SizeOf) {
  EXPECT_EQ(sizeof(Temperature<>{}), sizeof(double));
}

TEST(Temperature, StaticValue) {
  constexpr Temperature temperature = Temperature<>::Create<Unit::Temperature::Rankine>(1.0);
  constexpr double value = temperature.StaticValue<Unit::Temperature::Rankine>();
  EXPECT_EQ(value, 1.0);
}

TEST(Temperature, Stream) {
  std::ostringstream stream;
  stream << Temperature(1.0, Unit::Temperature::Kelvin);
  EXPECT_EQ(stream.str(), Temperature(1.0, Unit::Temperature::Kelvin).Print());
}

TEST(Temperature, Unit) {
  EXPECT_EQ(Temperature<>::Unit(), Standard<Unit::Temperature>);
}

TEST(Temperature, Value) {
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin).Value(), 1.0);
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).Value(Unit::Temperature::Rankine), 1.0);
}

TEST(Temperature, XML) {
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Kelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>K</unit>");
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).XML(Unit::Temperature::Rankine),
            "<value>" + Print(1.0) + "</value><unit>°R</unit>");
}

TEST(Temperature, YAML) {
  EXPECT_EQ(
      Temperature(1.0, Unit::Temperature::Kelvin).YAML(), "{value:" + Print(1.0) + ",unit:\"K\"}");
  EXPECT_EQ(Temperature(1.0, Unit::Temperature::Rankine).YAML(Unit::Temperature::Rankine),
            "{value:" + Print(1.0) + ",unit:\"°R\"}");
}

TEST(Temperature, Zero) {
  EXPECT_EQ(Temperature<>::Zero(), Temperature(0.0, Unit::Temperature::Kelvin));
}

}  // namespace

}  // namespace PhQ
