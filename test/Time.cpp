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

#include "../include/PhQ/Time.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(Time, ArithmeticOperatorAddition) {
  EXPECT_EQ(
      Time(1.0, Unit::Time::Second) + Time(2.0, Unit::Time::Second), Time(3.0, Unit::Time::Second));
}

TEST(Time, ArithmeticOperatorDivision) {
  EXPECT_EQ(Time(8.0, Unit::Time::Second) / 2.0, Time(4.0, Unit::Time::Second));
  EXPECT_EQ(Time(8.0, Unit::Time::Second) / Time(2.0, Unit::Time::Second), 4.0);
}

TEST(Time, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Time(4.0, Unit::Time::Second) * 2.0, Time(8.0, Unit::Time::Second));
  EXPECT_EQ(2.0 * Time(4.0, Unit::Time::Second), Time(8.0, Unit::Time::Second));
}

TEST(Time, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(
      Time(3.0, Unit::Time::Second) - Time(2.0, Unit::Time::Second), Time(1.0, Unit::Time::Second));
}

TEST(Time, AssignmentOperatorAddition) {
  Time time{1.0, Unit::Time::Second};
  time += Time(2.0, Unit::Time::Second);
  EXPECT_EQ(time, Time(3.0, Unit::Time::Second));
}

TEST(Time, AssignmentOperatorDivision) {
  Time time{8.0, Unit::Time::Second};
  time /= 2.0;
  EXPECT_EQ(time, Time(4.0, Unit::Time::Second));
}

TEST(Time, AssignmentOperatorMultiplication) {
  Time time{4.0, Unit::Time::Second};
  time *= 2.0;
  EXPECT_EQ(time, Time(8.0, Unit::Time::Second));
}

TEST(Time, AssignmentOperatorSubtraction) {
  Time time{3.0, Unit::Time::Second};
  time -= Time(2.0, Unit::Time::Second);
  EXPECT_EQ(time, Time(1.0, Unit::Time::Second));
}

TEST(Time, ComparisonOperators) {
  const Time first{1.0, Unit::Time::Second};
  const Time second{2.0, Unit::Time::Second};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Time, Constructor) {
  EXPECT_NO_THROW(Time(1.0, Unit::Time::Minute));
}

TEST(Time, CopyAssignmentOperator) {
  {
    const Time<float> first(1.0F, Unit::Time::Second);
    Time<double> second = Time<double>::Zero();
    second = first;
    EXPECT_EQ(second, Time<double>(1.0, Unit::Time::Second));
  }
  {
    const Time<double> first(1.0, Unit::Time::Second);
    Time<double> second = Time<double>::Zero();
    second = first;
    EXPECT_EQ(second, Time<double>(1.0, Unit::Time::Second));
  }
  {
    const Time<long double> first(1.0L, Unit::Time::Second);
    Time<double> second = Time<double>::Zero();
    second = first;
    EXPECT_EQ(second, Time<double>(1.0, Unit::Time::Second));
  }
}

TEST(Time, CopyConstructor) {
  {
    const Time<float> first(1.0F, Unit::Time::Second);
    const Time<double> second{first};
    EXPECT_EQ(second, Time<double>(1.0, Unit::Time::Second));
  }
  {
    const Time<double> first(1.0, Unit::Time::Second);
    const Time<double> second{first};
    EXPECT_EQ(second, Time<double>(1.0, Unit::Time::Second));
  }
  {
    const Time<long double> first(1.0L, Unit::Time::Second);
    const Time<double> second{first};
    EXPECT_EQ(second, Time<double>(1.0, Unit::Time::Second));
  }
}

TEST(Time, Create) {
  constexpr Time time = Time<>::Create<Unit::Time::Second>(1.0);
  EXPECT_EQ(time, Time(1.0, Unit::Time::Second));
}

TEST(Time, DefaultConstructor) {
  EXPECT_NO_THROW(Time<>{});
}

TEST(Time, Dimensions) {
  EXPECT_EQ(Time<>::Dimensions(), RelatedDimensions<Unit::Time>);
}

TEST(Time, Hash) {
  const Time first{1.0, Unit::Time::Second};
  const Time second{1.000001, Unit::Time::Second};
  const Time third{-1.0, Unit::Time::Second};
  const std::hash<Time<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Time, JSON) {
  EXPECT_EQ(Time(1.0, Unit::Time::Second).JSON(), "{\"value\":" + Print(1.0) + ",\"unit\":\"s\"}");
  EXPECT_EQ(Time(1.0, Unit::Time::Minute).JSON(Unit::Time::Minute),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"min\"}");
}

TEST(Time, MoveAssignmentOperator) {
  Time first{1.0, Unit::Time::Second};
  Time second = Time<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Time(1.0, Unit::Time::Second));
}

TEST(Time, MoveConstructor) {
  Time first{1.0, Unit::Time::Second};
  const Time second{std::move(first)};
  EXPECT_EQ(second, Time(1.0, Unit::Time::Second));
}

TEST(Time, MutableValue) {
  Time time{1.0, Unit::Time::Second};
  double& value = time.MutableValue();
  value = 2.0;
  EXPECT_EQ(time.Value(), 2.0);
}

TEST(Time, Print) {
  EXPECT_EQ(Time(1.0, Unit::Time::Second).Print(), Print(1.0) + " s");
  EXPECT_EQ(Time(1.0, Unit::Time::Minute).Print(Unit::Time::Minute), Print(1.0) + " min");
}

TEST(Time, SetValue) {
  Time time{1.0, Unit::Time::Second};
  time.SetValue(2.0);
  EXPECT_EQ(time.Value(), 2.0);
}

TEST(Time, SizeOf) {
  EXPECT_EQ(sizeof(Time<>{}), sizeof(double));
}

TEST(Time, StaticValue) {
  constexpr Time time = Time<>::Create<Unit::Time::Minute>(1.0);
  constexpr double value = time.StaticValue<Unit::Time::Minute>();
  EXPECT_EQ(value, 1.0);
}

TEST(Time, Stream) {
  std::ostringstream stream;
  stream << Time(1.0, Unit::Time::Second);
  EXPECT_EQ(stream.str(), Time(1.0, Unit::Time::Second).Print());
}

TEST(Time, Unit) {
  EXPECT_EQ(Time<>::Unit(), Standard<Unit::Time>);
}

TEST(Time, Value) {
  EXPECT_EQ(Time(1.0, Unit::Time::Second).Value(), 1.0);
  EXPECT_EQ(Time(1.0, Unit::Time::Minute).Value(Unit::Time::Minute), 1.0);
}

TEST(Time, XML) {
  EXPECT_EQ(Time(1.0, Unit::Time::Second).XML(), "<value>" + Print(1.0) + "</value><unit>s</unit>");
  EXPECT_EQ(Time(1.0, Unit::Time::Minute).XML(Unit::Time::Minute),
            "<value>" + Print(1.0) + "</value><unit>min</unit>");
}

TEST(Time, YAML) {
  EXPECT_EQ(Time(1.0, Unit::Time::Second).YAML(), "{value:" + Print(1.0) + ",unit:\"s\"}");
  EXPECT_EQ(Time(1.0, Unit::Time::Minute).YAML(Unit::Time::Minute),
            "{value:" + Print(1.0) + ",unit:\"min\"}");
}

TEST(Time, Zero) {
  EXPECT_EQ(Time<>::Zero(), Time(0.0, Unit::Time::Second));
}

}  // namespace

}  // namespace PhQ
