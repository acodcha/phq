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

#include "../include/PhQ/ScalarTemperatureGradient.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Unit/TemperatureDifference.hpp"
#include "../include/PhQ/Unit/TemperatureGradient.hpp"

namespace PhQ {

namespace {

TEST(ScalarTemperatureGradient, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre)
                + ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre),
            ScalarTemperatureGradient(3.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre) / 2.0,
            ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre)
                / ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre),
            4.0);
  EXPECT_EQ(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin)
                / Length(4.0, Unit::Length::Metre),
            ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre) * 2.0,
            ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(2.0 * ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre),
            ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre)
                * Length(2.0, Unit::Length::Metre),
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(ScalarTemperatureGradient, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarTemperatureGradient(3.0, Unit::TemperatureGradient::KelvinPerMetre)
                - ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre),
            ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, AssignmentOperatorAddition) {
  ScalarTemperatureGradient quantity{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity += ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity, ScalarTemperatureGradient(3.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, AssignmentOperatorDivision) {
  ScalarTemperatureGradient quantity{8.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity /= 2.0;
  EXPECT_EQ(quantity, ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, AssignmentOperatorMultiplication) {
  ScalarTemperatureGradient quantity{4.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity *= 2.0;
  EXPECT_EQ(quantity, ScalarTemperatureGradient(8.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, AssignmentOperatorSubtraction) {
  ScalarTemperatureGradient quantity{3.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity -= ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(quantity, ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, ComparisonOperators) {
  const ScalarTemperatureGradient first{0.1, Unit::TemperatureGradient::KelvinPerMetre};
  const ScalarTemperatureGradient second{0.2, Unit::TemperatureGradient::KelvinPerMetre};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarTemperatureGradient, Constructor) {
  EXPECT_NO_THROW(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre));
  EXPECT_EQ(
      ScalarTemperatureGradient(TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin),
                                Length(4.0, Unit::Length::Metre)),
      ScalarTemperatureGradient(2.0, Unit::TemperatureGradient::KelvinPerMetre));
  EXPECT_EQ(TemperatureDifference(
                ScalarTemperatureGradient(4.0, Unit::TemperatureGradient::KelvinPerMetre),
                Length(2.0, Unit::Length::Metre)),
            TemperatureDifference(8.0, Unit::TemperatureDifference::Kelvin));
}

TEST(ScalarTemperatureGradient, CopyAssignmentOperator) {
  {
    const ScalarTemperatureGradient<float> first(1.0F, Unit::TemperatureGradient::KelvinPerMetre);
    ScalarTemperatureGradient<double> second = ScalarTemperatureGradient<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, ScalarTemperatureGradient<double>(1.0, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const ScalarTemperatureGradient<double> first(1.0, Unit::TemperatureGradient::KelvinPerMetre);
    ScalarTemperatureGradient<double> second = ScalarTemperatureGradient<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, ScalarTemperatureGradient<double>(1.0, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const ScalarTemperatureGradient<long double> first(
        1.0L, Unit::TemperatureGradient::KelvinPerMetre);
    ScalarTemperatureGradient<double> second = ScalarTemperatureGradient<double>::Zero();
    second = first;
    EXPECT_EQ(
        second, ScalarTemperatureGradient<double>(1.0, Unit::TemperatureGradient::KelvinPerMetre));
  }
}

TEST(ScalarTemperatureGradient, CopyConstructor) {
  {
    const ScalarTemperatureGradient<float> first(1.0F, Unit::TemperatureGradient::KelvinPerMetre);
    const ScalarTemperatureGradient<double> second{first};
    EXPECT_EQ(
        second, ScalarTemperatureGradient<double>(1.0, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const ScalarTemperatureGradient<double> first(1.0, Unit::TemperatureGradient::KelvinPerMetre);
    const ScalarTemperatureGradient<double> second{first};
    EXPECT_EQ(
        second, ScalarTemperatureGradient<double>(1.0, Unit::TemperatureGradient::KelvinPerMetre));
  }
  {
    const ScalarTemperatureGradient<long double> first(
        1.0L, Unit::TemperatureGradient::KelvinPerMetre);
    const ScalarTemperatureGradient<double> second{first};
    EXPECT_EQ(
        second, ScalarTemperatureGradient<double>(1.0, Unit::TemperatureGradient::KelvinPerMetre));
  }
}

TEST(ScalarTemperatureGradient, Create) {
  constexpr ScalarTemperatureGradient quantity =
      ScalarTemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMetre>(1.0);
  EXPECT_EQ(quantity, ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarTemperatureGradient<>{});
}

TEST(ScalarTemperatureGradient, Dimensions) {
  EXPECT_EQ(
      ScalarTemperatureGradient<>::Dimensions(), RelatedDimensions<Unit::TemperatureGradient>);
}

TEST(ScalarTemperatureGradient, Hash) {
  const ScalarTemperatureGradient first{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  const ScalarTemperatureGradient second{1.00001, Unit::TemperatureGradient::KelvinPerMetre};
  const ScalarTemperatureGradient third{-1.0, Unit::TemperatureGradient::KelvinPerMetre};
  const std::hash<ScalarTemperatureGradient<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarTemperatureGradient, JSON) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"K/m\"}");
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .JSON(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"K/mm\"}");
}

TEST(ScalarTemperatureGradient, MoveAssignmentOperator) {
  ScalarTemperatureGradient first{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  ScalarTemperatureGradient second = ScalarTemperatureGradient<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, MoveConstructor) {
  ScalarTemperatureGradient first{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  const ScalarTemperatureGradient second{std::move(first)};
  EXPECT_EQ(second, ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre));
}

TEST(ScalarTemperatureGradient, MutableValue) {
  ScalarTemperatureGradient quantity{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarTemperatureGradient, Print) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).Print(),
            Print(1.0) + " K/m");
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Print(Unit::TemperatureGradient::KelvinPerMillimetre),
            Print(1.0) + " K/mm");
}

TEST(ScalarTemperatureGradient, SetValue) {
  ScalarTemperatureGradient quantity{1.0, Unit::TemperatureGradient::KelvinPerMetre};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(ScalarTemperatureGradient, SizeOf) {
  EXPECT_EQ(sizeof(ScalarTemperatureGradient<>{}), sizeof(double));
}

TEST(ScalarTemperatureGradient, StaticValue) {
  constexpr ScalarTemperatureGradient quantity =
      ScalarTemperatureGradient<>::Create<Unit::TemperatureGradient::KelvinPerMillimetre>(1.0);
  constexpr double value = quantity.StaticValue<Unit::TemperatureGradient::KelvinPerMillimetre>();
  EXPECT_EQ(value, 1.0);
}

TEST(ScalarTemperatureGradient, Stream) {
  std::ostringstream stream;
  stream << ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre);
  EXPECT_EQ(stream.str(),
            ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).Print());
}

TEST(ScalarTemperatureGradient, Unit) {
  EXPECT_EQ(ScalarTemperatureGradient<>::Unit(), Standard<Unit::TemperatureGradient>);
}

TEST(ScalarTemperatureGradient, Value) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).Value(), 1.0);
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .Value(Unit::TemperatureGradient::KelvinPerMillimetre),
            1.0);
}

TEST(ScalarTemperatureGradient, XML) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).XML(),
            "<value>" + Print(1.0) + "</value><unit>K/m</unit>");
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .XML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "<value>" + Print(1.0) + "</value><unit>K/mm</unit>");
}

TEST(ScalarTemperatureGradient, YAML) {
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMetre).YAML(),
            "{value:" + Print(1.0) + ",unit:\"K/m\"}");
  EXPECT_EQ(ScalarTemperatureGradient(1.0, Unit::TemperatureGradient::KelvinPerMillimetre)
                .YAML(Unit::TemperatureGradient::KelvinPerMillimetre),
            "{value:" + Print(1.0) + ",unit:\"K/mm\"}");
}

TEST(ScalarTemperatureGradient, Zero) {
  EXPECT_EQ(ScalarTemperatureGradient<>::Zero(),
            ScalarTemperatureGradient(0.0, Unit::TemperatureGradient::KelvinPerMetre));
}

}  // namespace

}  // namespace PhQ
