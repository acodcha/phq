// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "../include/PhQ/AngularSpeed.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/AngularSpeed.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Time.hpp"
#include "Performance.hpp"

namespace PhQ {

namespace {

TEST(AngularSpeed, ArithmeticOperatorAddition) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond)
                + AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            AngularSpeed(3.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, ArithmeticOperatorDivision) {
  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond) / 2.0,
            AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            4.0);
  EXPECT_EQ(
      AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond) / Angle(2.0, Unit::Angle::Radian),
      Frequency(4.0, Unit::Frequency::Hertz));
  EXPECT_EQ(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Angle(4.0, Unit::Angle::Radian));
  EXPECT_EQ(Angle(8.0, Unit::Angle::Radian) / Time(2.0, Unit::Time::Second),
            AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(
      Angle(8.0, Unit::Angle::Radian) / AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
      Time(4.0, Unit::Time::Second));
}

TEST(AngularSpeed, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond) * 2.0,
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(2.0 * AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(Time(4.0, Unit::Time::Second) * AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            Angle(8.0, Unit::Angle::Radian));
  EXPECT_EQ(Angle(4.0, Unit::Angle::Radian) * Frequency(2.0, Unit::Frequency::Hertz),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * Angle(2.0, Unit::Angle::Radian),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(AngularSpeed(3.0, Unit::AngularSpeed::RadianPerSecond)
                - AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond),
            AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, AssignmentOperatorAddition) {
  AngularSpeed angular_speed{1.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed += AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond);
  EXPECT_EQ(angular_speed, AngularSpeed(3.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, AssignmentOperatorDivision) {
  AngularSpeed angular_speed{8.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed /= 2.0;
  EXPECT_EQ(angular_speed, AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, AssignmentOperatorMultiplication) {
  AngularSpeed angular_speed{4.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed *= 2.0;
  EXPECT_EQ(angular_speed, AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, AssignmentOperatorSubtraction) {
  AngularSpeed angular_speed{3.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed -= AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond);
  EXPECT_EQ(angular_speed, AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, ComparisonOperators) {
  const AngularSpeed first{1.0, Unit::AngularSpeed::RadianPerSecond};
  const AngularSpeed second{2.0, Unit::AngularSpeed::RadianPerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(AngularSpeed, Constructor) {
  EXPECT_NO_THROW(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond));
  EXPECT_EQ(AngularSpeed(Angle(8.0, Unit::Angle::Radian), Time(2.0, Unit::Time::Second)),
            AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(AngularSpeed(Angle(4.0, Unit::Angle::Radian), Frequency(2.0, Unit::Frequency::Hertz)),
            AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond));
  EXPECT_EQ(
      Angle(AngularSpeed(4.0, Unit::AngularSpeed::RadianPerSecond), Time(2.0, Unit::Time::Second)),
      Angle(8.0, Unit::Angle::Radian));
  EXPECT_EQ(Angle(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                  Frequency(2.0, Unit::Frequency::Hertz)),
            Angle(4.0, Unit::Angle::Radian));
  EXPECT_EQ(
      Time(Angle(8.0, Unit::Angle::Radian), AngularSpeed(2.0, Unit::AngularSpeed::RadianPerSecond)),
      Time(4.0, Unit::Time::Second));
  EXPECT_EQ(Frequency(AngularSpeed(8.0, Unit::AngularSpeed::RadianPerSecond),
                      Angle(2.0, Unit::Angle::Radian)),
            Frequency(4.0, Unit::Frequency::Hertz));
}

TEST(AngularSpeed, CopyAssignmentOperator) {
  {
    const AngularSpeed<float> first(1.0F, Unit::AngularSpeed::RadianPerSecond);
    AngularSpeed<double> second = AngularSpeed<double>::Zero();
    second = first;
    EXPECT_EQ(second, AngularSpeed<double>(1.0, Unit::AngularSpeed::RadianPerSecond));
  }
  {
    const AngularSpeed<double> first(1.0, Unit::AngularSpeed::RadianPerSecond);
    AngularSpeed<double> second = AngularSpeed<double>::Zero();
    second = first;
    EXPECT_EQ(second, AngularSpeed<double>(1.0, Unit::AngularSpeed::RadianPerSecond));
  }
  {
    const AngularSpeed<long double> first(1.0L, Unit::AngularSpeed::RadianPerSecond);
    AngularSpeed<double> second = AngularSpeed<double>::Zero();
    second = first;
    EXPECT_EQ(second, AngularSpeed<double>(1.0, Unit::AngularSpeed::RadianPerSecond));
  }
}

TEST(AngularSpeed, CopyConstructor) {
  {
    const AngularSpeed<float> first(1.0F, Unit::AngularSpeed::RadianPerSecond);
    const AngularSpeed<double> second{first};
    EXPECT_EQ(second, AngularSpeed<double>(1.0, Unit::AngularSpeed::RadianPerSecond));
  }
  {
    const AngularSpeed<double> first(1.0, Unit::AngularSpeed::RadianPerSecond);
    const AngularSpeed<double> second{first};
    EXPECT_EQ(second, AngularSpeed<double>(1.0, Unit::AngularSpeed::RadianPerSecond));
  }
  {
    const AngularSpeed<long double> first(1.0L, Unit::AngularSpeed::RadianPerSecond);
    const AngularSpeed<double> second{first};
    EXPECT_EQ(second, AngularSpeed<double>(1.0, Unit::AngularSpeed::RadianPerSecond));
  }
}

TEST(AngularSpeed, Create) {
  constexpr AngularSpeed angular_speed =
      AngularSpeed<>::Create<Unit::AngularSpeed::RadianPerSecond>(1.0);
  EXPECT_EQ(angular_speed, AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, DefaultConstructor) {
  EXPECT_NO_THROW(AngularSpeed<>{});
}

TEST(AngularSpeed, Dimensions) {
  EXPECT_EQ(AngularSpeed<>::Dimensions(), RelatedDimensions<Unit::AngularSpeed>);
}

TEST(AngularSpeed, Hash) {
  const AngularSpeed first{1.0, Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed second{1.000001, Unit::AngularSpeed::DegreePerSecond};
  const AngularSpeed third{-1.0, Unit::AngularSpeed::DegreePerSecond};
  const std::hash<AngularSpeed<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(AngularSpeed, JSON) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"rad/s\"}");
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .JSON(Unit::AngularSpeed::DegreePerSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"deg/s\"}");
}

TEST(AngularSpeed, MoveAssignmentOperator) {
  AngularSpeed first{1.0, Unit::AngularSpeed::RadianPerSecond};
  AngularSpeed second = AngularSpeed<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, MoveConstructor) {
  AngularSpeed first{1.0, Unit::AngularSpeed::RadianPerSecond};
  const AngularSpeed second{std::move(first)};
  EXPECT_EQ(second, AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond));
}

TEST(AngularSpeed, MutableValue) {
  AngularSpeed angular_speed{1.0, Unit::AngularSpeed::RadianPerSecond};
  double& value = angular_speed.MutableValue();
  value = 2.0;
  EXPECT_EQ(angular_speed.Value(), 2.0);
}

TEST(AngularSpeed, Performance) {
  AngularSpeed first{1.2345678901234567890, Unit::AngularSpeed::RadianPerSecond};
  AngularSpeed second{1.2345678901234567890, Unit::AngularSpeed::RadianPerSecond};
  double first_reference{1.2345678901234567890};
  double second_reference{1.2345678901234567890};
  Internal::TestScalarPerformance(first, second, first_reference, second_reference);
}

TEST(AngularSpeed, Print) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).Print(), Print(1.0) + " rad/s");
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .Print(Unit::AngularSpeed::DegreePerSecond),
            Print(1.0) + " deg/s");
}

TEST(AngularSpeed, SetValue) {
  AngularSpeed angular_speed{1.0, Unit::AngularSpeed::RadianPerSecond};
  angular_speed.SetValue(2.0);
  EXPECT_EQ(angular_speed.Value(), 2.0);
}

TEST(AngularSpeed, SizeOf) {
  EXPECT_EQ(sizeof(AngularSpeed<>{}), sizeof(double));
}

TEST(AngularSpeed, StaticValue) {
  constexpr AngularSpeed angular_speed =
      AngularSpeed<>::Create<Unit::AngularSpeed::DegreePerSecond>(1.0);
  constexpr double value = angular_speed.StaticValue<Unit::AngularSpeed::DegreePerSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(AngularSpeed, Stream) {
  std::ostringstream stream;
  stream << AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond);
  EXPECT_EQ(stream.str(), AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).Print());
}

TEST(AngularSpeed, Unit) {
  EXPECT_EQ(AngularSpeed<>::Unit(), Standard<Unit::AngularSpeed>);
}

TEST(AngularSpeed, Value) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).Value(), 1.0);
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .Value(Unit::AngularSpeed::DegreePerSecond),
            1.0);
}

TEST(AngularSpeed, XML) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>rad/s</unit>");
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .XML(Unit::AngularSpeed::DegreePerSecond),
            "<value>" + Print(1.0) + "</value><unit>deg/s</unit>");
}

TEST(AngularSpeed, YAML) {
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::RadianPerSecond).YAML(),
            "{value:" + Print(1.0) + ",unit:\"rad/s\"}");
  EXPECT_EQ(AngularSpeed(1.0, Unit::AngularSpeed::DegreePerSecond)
                .YAML(Unit::AngularSpeed::DegreePerSecond),
            "{value:" + Print(1.0) + ",unit:\"deg/s\"}");
}

TEST(AngularSpeed, Zero) {
  EXPECT_EQ(AngularSpeed<>::Zero(), AngularSpeed(0.0, Unit::AngularSpeed::RadianPerSecond));
}

}  // namespace

}  // namespace PhQ
