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

#include "../include/PhQ/TemperatureDifference.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/TemperatureDifference.hpp"

namespace PhQ {

namespace {

TEST(TemperatureDifference, ArithmeticOperatorAddition) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin)
                + TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, ArithmeticOperatorDivision) {
  EXPECT_EQ(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin) / 2.0,
            TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin));
  EXPECT_EQ(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin)
                / TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            4.0);
}

TEST(TemperatureDifference, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin) * 2.0,
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
  EXPECT_EQ(2.0 * TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin),
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin)
                - TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin),
            TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorAddition) {
  TemperatureDifference temperature_difference{1.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference += TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(3.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorDivision) {
  TemperatureDifference temperature_difference{8.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference /= 2.0;
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(4.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorMultiplication) {
  TemperatureDifference temperature_difference{4.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference *= 2.0;
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, AssignmentOperatorSubtraction) {
  TemperatureDifference temperature_difference{3.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference -= TemperatureDifference(2.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, ComparisonOperators) {
  const TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{2.0, Unit::TemperatureDifference::Kelvin};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(TemperatureDifference, CopyAssignmentOperator) {
  {
    const TemperatureDifference<float> first(1.0F, Unit::TemperatureDifference::Kelvin);
    TemperatureDifference<double> second = TemperatureDifference<double>::Zero();
    second = first;
    EXPECT_EQ(second, TemperatureDifference<double>(1.0, Unit::TemperatureDifference::Kelvin));
  }
  {
    const TemperatureDifference<double> first(1.0, Unit::TemperatureDifference::Kelvin);
    TemperatureDifference<double> second = TemperatureDifference<double>::Zero();
    second = first;
    EXPECT_EQ(second, TemperatureDifference<double>(1.0, Unit::TemperatureDifference::Kelvin));
  }
  {
    const TemperatureDifference<long double> first(1.0L, Unit::TemperatureDifference::Kelvin);
    TemperatureDifference<double> second = TemperatureDifference<double>::Zero();
    second = first;
    EXPECT_EQ(second, TemperatureDifference<double>(1.0, Unit::TemperatureDifference::Kelvin));
  }
}

TEST(TemperatureDifference, CopyConstructor) {
  {
    const TemperatureDifference<float> first(1.0F, Unit::TemperatureDifference::Kelvin);
    const TemperatureDifference<double> second{first};
    EXPECT_EQ(second, TemperatureDifference<double>(1.0, Unit::TemperatureDifference::Kelvin));
  }
  {
    const TemperatureDifference<double> first(1.0, Unit::TemperatureDifference::Kelvin);
    const TemperatureDifference<double> second{first};
    EXPECT_EQ(second, TemperatureDifference<double>(1.0, Unit::TemperatureDifference::Kelvin));
  }
  {
    const TemperatureDifference<long double> first(1.0L, Unit::TemperatureDifference::Kelvin);
    const TemperatureDifference<double> second{first};
    EXPECT_EQ(second, TemperatureDifference<double>(1.0, Unit::TemperatureDifference::Kelvin));
  }
}

TEST(TemperatureDifference, Create) {
  constexpr TemperatureDifference temperature_difference =
      TemperatureDifference<>::Create<Unit::TemperatureDifference::Kelvin>(1.0);
  EXPECT_EQ(
      temperature_difference, TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, DefaultConstructor) {
  EXPECT_NO_THROW(TemperatureDifference<>{});
}

TEST(TemperatureDifference, Dimensions) {
  EXPECT_EQ(TemperatureDifference<>::Dimensions(), RelatedDimensions<Unit::TemperatureDifference>);
}

TEST(TemperatureDifference, Hash) {
  const TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{1.000001, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference third{-1.0, Unit::TemperatureDifference::Kelvin};
  const std::hash<TemperatureDifference<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(TemperatureDifference, JSON) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"K\"}");
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .JSON(Unit::TemperatureDifference::Rankine),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"°R\"}");
}

TEST(TemperatureDifference, MoveAssignmentOperator) {
  TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  TemperatureDifference second = TemperatureDifference<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, MoveConstructor) {
  TemperatureDifference first{1.0, Unit::TemperatureDifference::Kelvin};
  const TemperatureDifference second{std::move(first)};
  EXPECT_EQ(second, TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin));
}

TEST(TemperatureDifference, MutableValue) {
  TemperatureDifference temperature_difference{1.0, Unit::TemperatureDifference::Kelvin};
  double& value = temperature_difference.MutableValue();
  value = 2.0;
  EXPECT_EQ(temperature_difference.Value(), 2.0);
}

TEST(TemperatureDifference, Print) {
  EXPECT_EQ(
      TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).Print(), Print(1.0) + " K");
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .Print(Unit::TemperatureDifference::Rankine),
            Print(1.0) + " °R");
}

TEST(TemperatureDifference, SetValue) {
  TemperatureDifference temperature_difference{1.0, Unit::TemperatureDifference::Kelvin};
  temperature_difference.SetValue(2.0);
  EXPECT_EQ(temperature_difference.Value(), 2.0);
}

TEST(TemperatureDifference, SizeOf) {
  EXPECT_EQ(sizeof(TemperatureDifference<>{}), sizeof(double));
}

TEST(TemperatureDifference, StandardConstructor) {
  EXPECT_NO_THROW(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine));
}

TEST(TemperatureDifference, StaticValue) {
  constexpr TemperatureDifference temperature_difference =
      TemperatureDifference<>::Create<Unit::TemperatureDifference::Rankine>(1.0);
  constexpr double value =
      temperature_difference.StaticValue<Unit::TemperatureDifference::Rankine>();
  EXPECT_EQ(value, 1.0);
}

TEST(TemperatureDifference, Stream) {
  std::ostringstream stream;
  stream << TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin);
  EXPECT_EQ(stream.str(), TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).Print());
}

TEST(TemperatureDifference, Unit) {
  EXPECT_EQ(TemperatureDifference<>::Unit(), Standard<Unit::TemperatureDifference>);
}

TEST(TemperatureDifference, Value) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).Value(), 1.0);
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .Value(Unit::TemperatureDifference::Rankine),
            1.0);
}

TEST(TemperatureDifference, XML) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).XML(),
            "<value>" + Print(1.0) + "</value><unit>K</unit>");
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .XML(Unit::TemperatureDifference::Rankine),
            "<value>" + Print(1.0) + "</value><unit>°R</unit>");
}

TEST(TemperatureDifference, YAML) {
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Kelvin).YAML(),
            "{value:" + Print(1.0) + ",unit:\"K\"}");
  EXPECT_EQ(TemperatureDifference(1.0, Unit::TemperatureDifference::Rankine)
                .YAML(Unit::TemperatureDifference::Rankine),
            "{value:" + Print(1.0) + ",unit:\"°R\"}");
}

TEST(TemperatureDifference, Zero) {
  EXPECT_EQ(TemperatureDifference<>::Zero(),
            TemperatureDifference(0.0, Unit::TemperatureDifference::Kelvin));
}

}  // namespace

}  // namespace PhQ
