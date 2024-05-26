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

#include "../include/PhQ/ScalarAngularAcceleration.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/AngularSpeed.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/AngularAcceleration.hpp"
#include "../include/PhQ/Unit/AngularSpeed.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(ScalarAngularAcceleration, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                + ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            ScalarAngularAcceleration(3.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond) / 2.0,
            ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            4.0);
  EXPECT_EQ(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
            Frequency(2.0, Unit::Frequency::Hertz));
  EXPECT_EQ(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                / Frequency(4.0, Unit::Frequency::Hertz),
            AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond) / Time(4.0, Unit::Time::Second),
            ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            Time(2.0, Unit::Time::Second));
}

TEST(ScalarAngularAcceleration, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond) * 2.0,
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(2.0 * ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond)
                * Frequency(2.0, Unit::Frequency::Hertz),
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz)
                * AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarAngularAcceleration(3.0, Unit::AngularAcceleration::RadianPerSquareSecond)
                - ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond),
            ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, AssignmentOperatorAddition) {
  ScalarAngularAcceleration scalar_angular_acceleration{
      1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  scalar_angular_acceleration +=
      ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(scalar_angular_acceleration,
            ScalarAngularAcceleration(3.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, AssignmentOperatorDivision) {
  ScalarAngularAcceleration scalar_angular_acceleration{
      8.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  scalar_angular_acceleration /= 2.0;
  EXPECT_EQ(scalar_angular_acceleration,
            ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, AssignmentOperatorMultiplication) {
  ScalarAngularAcceleration scalar_angular_acceleration{
      4.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  scalar_angular_acceleration *= 2.0;
  EXPECT_EQ(scalar_angular_acceleration,
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, AssignmentOperatorSubtraction) {
  ScalarAngularAcceleration scalar_angular_acceleration{
      3.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  scalar_angular_acceleration -=
      ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(scalar_angular_acceleration,
            ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, ComparisonOperators) {
  const ScalarAngularAcceleration first{0.1, Unit::AngularAcceleration::RadianPerSquareSecond};
  const ScalarAngularAcceleration second{0.2, Unit::AngularAcceleration::RadianPerSquareSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarAngularAcceleration, CopyAssignmentOperator) {
  {
    const ScalarAngularAcceleration<float> first(
        1.0F, Unit::AngularAcceleration::RadianPerSquareSecond);
    ScalarAngularAcceleration<double> second = ScalarAngularAcceleration<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarAngularAcceleration<double>(
                          1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  }
  {
    const ScalarAngularAcceleration<double> first(
        1.0, Unit::AngularAcceleration::RadianPerSquareSecond);
    ScalarAngularAcceleration<double> second = ScalarAngularAcceleration<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarAngularAcceleration<double>(
                          1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  }
  {
    const ScalarAngularAcceleration<long double> first(
        1.0L, Unit::AngularAcceleration::RadianPerSquareSecond);
    ScalarAngularAcceleration<double> second = ScalarAngularAcceleration<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarAngularAcceleration<double>(
                          1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  }
}

TEST(ScalarAngularAcceleration, CopyConstructor) {
  {
    const ScalarAngularAcceleration<float> first(
        1.0F, Unit::AngularAcceleration::RadianPerSquareSecond);
    const ScalarAngularAcceleration<double> second{first};
    EXPECT_EQ(second, ScalarAngularAcceleration<double>(
                          1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  }
  {
    const ScalarAngularAcceleration<double> first(
        1.0, Unit::AngularAcceleration::RadianPerSquareSecond);
    const ScalarAngularAcceleration<double> second{first};
    EXPECT_EQ(second, ScalarAngularAcceleration<double>(
                          1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  }
  {
    const ScalarAngularAcceleration<long double> first(
        1.0L, Unit::AngularAcceleration::RadianPerSquareSecond);
    const ScalarAngularAcceleration<double> second{first};
    EXPECT_EQ(second, ScalarAngularAcceleration<double>(
                          1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
  }
}

TEST(ScalarAngularAcceleration, Create) {
  constexpr ScalarAngularAcceleration scalar_angular_acceleration =
      ScalarAngularAcceleration<>::Create<Unit::AngularAcceleration::RadianPerSquareSecond>(1.0);
  EXPECT_EQ(scalar_angular_acceleration,
            ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarAngularAcceleration<>{});
}

TEST(ScalarAngularAcceleration, Dimensions) {
  EXPECT_EQ(
      ScalarAngularAcceleration<>::Dimensions(), RelatedDimensions<Unit::AngularAcceleration>);
}

TEST(ScalarAngularAcceleration, Hash) {
  const ScalarAngularAcceleration first{1.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const ScalarAngularAcceleration second{
      1.000001, Unit::AngularAcceleration::DegreePerSquareSecond};
  const ScalarAngularAcceleration third{-1.0, Unit::AngularAcceleration::DegreePerSquareSecond};
  const std::hash<ScalarAngularAcceleration<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarAngularAcceleration, JSON) {
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"rad/s^2\"}");
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::DegreePerSquareSecond)
                .JSON(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"deg/s^2\"}");
}

TEST(ScalarAngularAcceleration, MiscellaneousConstructors) {
  EXPECT_EQ(ScalarAngularAcceleration(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                                      Time(4.0, Unit::Time::Second)),
            ScalarAngularAcceleration(2.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(ScalarAngularAcceleration(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
                                      Frequency(2.0, Unit::Frequency::Hertz)),
            ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond));

  EXPECT_EQ(
      AngularSpeed(ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                   Time(2.0, Unit::Time::Second)),
      AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(
      AngularSpeed(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                   Frequency(2.0, Unit::Frequency::Hertz)),
      AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));

  EXPECT_EQ(Time(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                 ScalarAngularAcceleration(4.0, Unit::AngularAcceleration::RadianPerSquareSecond)),
            Time(2.0, Unit::Time::Second));

  EXPECT_EQ(
      Frequency(ScalarAngularAcceleration(8.0, Unit::AngularAcceleration::RadianPerSquareSecond),
                AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond)),
      Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(ScalarAngularAcceleration, MoveAssignmentOperator) {
  ScalarAngularAcceleration first{1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  ScalarAngularAcceleration second = ScalarAngularAcceleration<>::Zero();
  second = std::move(first);
  EXPECT_EQ(
      second, ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, MoveConstructor) {
  ScalarAngularAcceleration first{1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  const ScalarAngularAcceleration second{std::move(first)};
  EXPECT_EQ(
      second, ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

TEST(ScalarAngularAcceleration, MutableValue) {
  ScalarAngularAcceleration scalar_angular_acceleration{
      1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  double& value = scalar_angular_acceleration.MutableValue();
  value = 2.0;
  EXPECT_EQ(scalar_angular_acceleration.Value(), 2.0);
}

TEST(ScalarAngularAcceleration, Print) {
  EXPECT_EQ(
      ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond).Print(),
      Print(1.0) + " rad/s^2");
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::DegreePerSquareSecond)
                .Print(Unit::AngularAcceleration::DegreePerSquareSecond),
            Print(1.0) + " deg/s^2");
}

TEST(ScalarAngularAcceleration, SetValue) {
  ScalarAngularAcceleration scalar_angular_acceleration{
      1.0, Unit::AngularAcceleration::RadianPerSquareSecond};
  scalar_angular_acceleration.SetValue(2.0);
  EXPECT_EQ(scalar_angular_acceleration.Value(), 2.0);
}

TEST(ScalarAngularAcceleration, SizeOf) {
  EXPECT_EQ(sizeof(ScalarAngularAcceleration<>{}), sizeof(double));
}

TEST(ScalarAngularAcceleration, StandardConstructor) {
  EXPECT_NO_THROW(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::DegreePerSquareSecond));
}

TEST(ScalarAngularAcceleration, StaticValue) {
  constexpr ScalarAngularAcceleration scalar_angular_acceleration =
      ScalarAngularAcceleration<>::Create<Unit::AngularAcceleration::DegreePerSquareSecond>(1.0);
  constexpr double value =
      scalar_angular_acceleration.StaticValue<Unit::AngularAcceleration::DegreePerSquareSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(ScalarAngularAcceleration, Stream) {
  std::ostringstream stream;
  stream << ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond);
  EXPECT_EQ(
      stream.str(),
      ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond).Print());
}

TEST(ScalarAngularAcceleration, Unit) {
  EXPECT_EQ(ScalarAngularAcceleration<>::Unit(), Standard<Unit::AngularAcceleration>);
}

TEST(ScalarAngularAcceleration, Value) {
  EXPECT_EQ(
      ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond).Value(),
      1.0);
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::DegreePerSquareSecond)
                .Value(Unit::AngularAcceleration::DegreePerSquareSecond),
            1.0);
}

TEST(ScalarAngularAcceleration, XML) {
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>rad/s^2</unit>");
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::DegreePerSquareSecond)
                .XML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "<value>" + Print(1.0) + "</value><unit>deg/s^2</unit>");
}

TEST(ScalarAngularAcceleration, YAML) {
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::RadianPerSquareSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"rad/s^2\"}");
  EXPECT_EQ(ScalarAngularAcceleration(1.0, Unit::AngularAcceleration::DegreePerSquareSecond)
                .YAML(Unit::AngularAcceleration::DegreePerSquareSecond),
            "{value:" + Print(1.0) + ",unit:\"deg/s^2\"}");
}

TEST(ScalarAngularAcceleration, Zero) {
  EXPECT_EQ(ScalarAngularAcceleration<>::Zero(),
            ScalarAngularAcceleration(0.0, Unit::AngularAcceleration::RadianPerSquareSecond));
}

}  // namespace

}  // namespace PhQ
