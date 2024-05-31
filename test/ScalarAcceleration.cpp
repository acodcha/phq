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

#include "../include/PhQ/ScalarAcceleration.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Speed.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Acceleration.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Speed.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(ScalarAcceleration, ArithmeticOperatorAddition) {
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond)
                + ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond),
            ScalarAcceleration(3.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, ArithmeticOperatorDivision) {
  EXPECT_EQ(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond) / 2.0,
            ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond),
            4.0);
  EXPECT_EQ(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Speed(4.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond)
                / Speed(2.0, Unit::Speed::MetrePerSecond),
            Frequency(4.0, Unit::Frequency::Hertz));
  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond) / Time(2.0, Unit::Time::Second),
            ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond)
                / ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond),
            Time(4.0, Unit::Time::Second));
}

TEST(ScalarAcceleration, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond) * 2.0,
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(2.0 * ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond),
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond)
                * Time(4.0, Unit::Time::Second),
            Speed(8.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Time(2.0, Unit::Time::Second)
                * ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond),
            Speed(8.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(2.0, Unit::Speed::MetrePerSecond) * Frequency(4.0, Unit::Frequency::Hertz),
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(Frequency(2.0, Unit::Frequency::Hertz) * Speed(4.0, Unit::Speed::MetrePerSecond),
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(ScalarAcceleration(3.0, Unit::Acceleration::MetrePerSquareSecond)
                - ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond),
            ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, AssignmentOperatorAddition) {
  ScalarAcceleration scalar_acceleration{1.0, Unit::Acceleration::MetrePerSquareSecond};
  scalar_acceleration += ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(scalar_acceleration, ScalarAcceleration(3.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, AssignmentOperatorDivision) {
  ScalarAcceleration scalar_acceleration{8.0, Unit::Acceleration::MetrePerSquareSecond};
  scalar_acceleration /= 2.0;
  EXPECT_EQ(scalar_acceleration, ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, AssignmentOperatorMultiplication) {
  ScalarAcceleration scalar_acceleration{4.0, Unit::Acceleration::MetrePerSquareSecond};
  scalar_acceleration *= 2.0;
  EXPECT_EQ(scalar_acceleration, ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, AssignmentOperatorSubtraction) {
  ScalarAcceleration scalar_acceleration{3.0, Unit::Acceleration::MetrePerSquareSecond};
  scalar_acceleration -= ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(scalar_acceleration, ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, ComparisonOperators) {
  const ScalarAcceleration first{0.1, Unit::Acceleration::MetrePerSquareSecond};
  const ScalarAcceleration second{0.2, Unit::Acceleration::MetrePerSquareSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(ScalarAcceleration, Constructor) {
  EXPECT_NO_THROW(ScalarAcceleration(1.0, Unit::Acceleration::MillimetrePerSquareSecond));
  EXPECT_EQ(
      ScalarAcceleration(Speed(8.0, Unit::Speed::MetrePerSecond), Time(2.0, Unit::Time::Second)),
      ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(ScalarAcceleration(
                Speed(4.0, Unit::Speed::MetrePerSecond), Frequency(2.0, Unit::Frequency::Hertz)),
            ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(Speed(ScalarAcceleration(4.0, Unit::Acceleration::MetrePerSquareSecond),
                  Time(2.0, Unit::Time::Second)),
            Speed(8.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond),
                  Frequency(2.0, Unit::Frequency::Hertz)),
            Speed(4.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Time(Speed(8.0, Unit::Speed::MetrePerSecond),
                 ScalarAcceleration(2.0, Unit::Acceleration::MetrePerSquareSecond)),
            Time(4.0, Unit::Time::Second));
  EXPECT_EQ(Frequency(ScalarAcceleration(8.0, Unit::Acceleration::MetrePerSquareSecond),
                      Speed(2.0, Unit::Speed::MetrePerSecond)),
            Frequency(4.0, Unit::Frequency::Hertz));
}

TEST(ScalarAcceleration, CopyAssignmentOperator) {
  {
    const ScalarAcceleration<float> first(1.0F, Unit::Acceleration::MetrePerSquareSecond);
    ScalarAcceleration<double> second = ScalarAcceleration<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarAcceleration<double>(1.0, Unit::Acceleration::MetrePerSquareSecond));
  }
  {
    const ScalarAcceleration<double> first(1.0, Unit::Acceleration::MetrePerSquareSecond);
    ScalarAcceleration<double> second = ScalarAcceleration<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarAcceleration<double>(1.0, Unit::Acceleration::MetrePerSquareSecond));
  }
  {
    const ScalarAcceleration<long double> first(1.0L, Unit::Acceleration::MetrePerSquareSecond);
    ScalarAcceleration<double> second = ScalarAcceleration<double>::Zero();
    second = first;
    EXPECT_EQ(second, ScalarAcceleration<double>(1.0, Unit::Acceleration::MetrePerSquareSecond));
  }
}

TEST(ScalarAcceleration, CopyConstructor) {
  {
    const ScalarAcceleration<float> first(1.0F, Unit::Acceleration::MetrePerSquareSecond);
    const ScalarAcceleration<double> second{first};
    EXPECT_EQ(second, ScalarAcceleration<double>(1.0, Unit::Acceleration::MetrePerSquareSecond));
  }
  {
    const ScalarAcceleration<double> first(1.0, Unit::Acceleration::MetrePerSquareSecond);
    const ScalarAcceleration<double> second{first};
    EXPECT_EQ(second, ScalarAcceleration<double>(1.0, Unit::Acceleration::MetrePerSquareSecond));
  }
  {
    const ScalarAcceleration<long double> first(1.0L, Unit::Acceleration::MetrePerSquareSecond);
    const ScalarAcceleration<double> second{first};
    EXPECT_EQ(second, ScalarAcceleration<double>(1.0, Unit::Acceleration::MetrePerSquareSecond));
  }
}

TEST(ScalarAcceleration, Create) {
  constexpr ScalarAcceleration scalar_acceleration =
      ScalarAcceleration<>::Create<Unit::Acceleration::MetrePerSquareSecond>(1.0);
  EXPECT_EQ(scalar_acceleration, ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, DefaultConstructor) {
  EXPECT_NO_THROW(ScalarAcceleration<>{});
}

TEST(ScalarAcceleration, Dimensions) {
  EXPECT_EQ(ScalarAcceleration<>::Dimensions(), RelatedDimensions<Unit::Acceleration>);
}

TEST(ScalarAcceleration, Hash) {
  const ScalarAcceleration first{1.0, Unit::Acceleration::MillimetrePerSquareSecond};
  const ScalarAcceleration second{1.000001, Unit::Acceleration::MillimetrePerSquareSecond};
  const ScalarAcceleration third{-1.0, Unit::Acceleration::MillimetrePerSquareSecond};
  const std::hash<ScalarAcceleration<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(ScalarAcceleration, JSON) {
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"m/s^2\"}");
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MillimetrePerSquareSecond)
                .JSON(Unit::Acceleration::MillimetrePerSquareSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"mm/s^2\"}");
}

TEST(ScalarAcceleration, MoveAssignmentOperator) {
  ScalarAcceleration first{1.0, Unit::Acceleration::MetrePerSquareSecond};
  ScalarAcceleration second = ScalarAcceleration<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, MoveConstructor) {
  ScalarAcceleration first{1.0, Unit::Acceleration::MetrePerSquareSecond};
  const ScalarAcceleration second{std::move(first)};
  EXPECT_EQ(second, ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(ScalarAcceleration, MutableValue) {
  ScalarAcceleration scalar_acceleration{1.0, Unit::Acceleration::MetrePerSquareSecond};
  double& value = scalar_acceleration.MutableValue();
  value = 2.0;
  EXPECT_EQ(scalar_acceleration.Value(), 2.0);
}

TEST(ScalarAcceleration, Print) {
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond).Print(),
            Print(1.0) + " m/s^2");
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MillimetrePerSquareSecond)
                .Print(Unit::Acceleration::MillimetrePerSquareSecond),
            Print(1.0) + " mm/s^2");
}

TEST(ScalarAcceleration, SetValue) {
  ScalarAcceleration scalar_acceleration{1.0, Unit::Acceleration::MetrePerSquareSecond};
  scalar_acceleration.SetValue(2.0);
  EXPECT_EQ(scalar_acceleration.Value(), 2.0);
}

TEST(ScalarAcceleration, SizeOf) {
  EXPECT_EQ(sizeof(ScalarAcceleration<>{}), sizeof(double));
}

TEST(ScalarAcceleration, StaticValue) {
  constexpr ScalarAcceleration scalar_acceleration =
      ScalarAcceleration<>::Create<Unit::Acceleration::MillimetrePerSquareSecond>(1.0);
  constexpr double value =
      scalar_acceleration.StaticValue<Unit::Acceleration::MillimetrePerSquareSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(ScalarAcceleration, Stream) {
  std::ostringstream stream;
  stream << ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(
      stream.str(), ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond).Print());
}

TEST(ScalarAcceleration, Unit) {
  EXPECT_EQ(ScalarAcceleration<>::Unit(), Standard<Unit::Acceleration>);
}

TEST(ScalarAcceleration, Value) {
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond).Value(), 1.0);
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MillimetrePerSquareSecond)
                .Value(Unit::Acceleration::MillimetrePerSquareSecond),
            1.0);
}

TEST(ScalarAcceleration, XML) {
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>m/s^2</unit>");
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MillimetrePerSquareSecond)
                .XML(Unit::Acceleration::MillimetrePerSquareSecond),
            "<value>" + Print(1.0) + "</value><unit>mm/s^2</unit>");
}

TEST(ScalarAcceleration, YAML) {
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"m/s^2\"}");
  EXPECT_EQ(ScalarAcceleration(1.0, Unit::Acceleration::MillimetrePerSquareSecond)
                .YAML(Unit::Acceleration::MillimetrePerSquareSecond),
            "{value:" + Print(1.0) + ",unit:\"mm/s^2\"}");
}

TEST(ScalarAcceleration, Zero) {
  EXPECT_EQ(ScalarAcceleration<>::Zero(),
            ScalarAcceleration(0.0, Unit::Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ
