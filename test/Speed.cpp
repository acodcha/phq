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

#include "../include/PhQ/Speed.hpp"

#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Unit/Speed.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(Speed, ArithmeticOperatorAddition) {
  EXPECT_EQ(Speed(1.0, Unit::Speed::MetrePerSecond) + Speed(2.0, Unit::Speed::MetrePerSecond),
            Speed(3.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, ArithmeticOperatorDivision) {
  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond) / 2.0, Speed(4.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond) / Speed(2.0, Unit::Speed::MetrePerSecond), 4.0);
  EXPECT_EQ(Speed(8.0, Unit::Speed::MetrePerSecond) / Frequency(2.0, Unit::Frequency::Hertz),
            Length(4.0, Unit::Length::Metre));
  EXPECT_EQ(Length(8.0, Unit::Length::Metre) / Speed(4.0, Unit::Speed::MetrePerSecond),
            Time(2.0, Unit::Time::Second));
  EXPECT_EQ(Length(8.0, Unit::Length::Metre) / Time(4.0, Unit::Time::Second),
            Speed(2.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Speed(4.0, Unit::Speed::MetrePerSecond) * 2.0, Speed(8.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(2.0 * Speed(4.0, Unit::Speed::MetrePerSecond), Speed(8.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(4.0, Unit::Speed::MetrePerSecond) * Time(2.0, Unit::Time::Second),
            Length(8.0, Unit::Length::Metre));
  EXPECT_EQ(Length(4.0, Unit::Length::Metre) * Frequency(2.0, Unit::Frequency::Hertz),
            Speed(8.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Frequency(4.0, Unit::Frequency::Hertz) * Length(2.0, Unit::Length::Metre),
            Speed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Speed(3.0, Unit::Speed::MetrePerSecond) - Speed(2.0, Unit::Speed::MetrePerSecond),
            Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, AssignmentOperatorAddition) {
  Speed quantity{1.0, Unit::Speed::MetrePerSecond};
  quantity += Speed(2.0, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(quantity, Speed(3.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, AssignmentOperatorDivision) {
  Speed quantity{8.0, Unit::Speed::MetrePerSecond};
  quantity /= 2.0;
  EXPECT_EQ(quantity, Speed(4.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, AssignmentOperatorMultiplication) {
  Speed quantity{4.0, Unit::Speed::MetrePerSecond};
  quantity *= 2.0;
  EXPECT_EQ(quantity, Speed(8.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, AssignmentOperatorSubtraction) {
  Speed quantity{3.0, Unit::Speed::MetrePerSecond};
  quantity -= Speed(2.0, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(quantity, Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, ComparisonOperators) {
  const Speed first{0.1, Unit::Speed::MetrePerSecond};
  const Speed second{0.2, Unit::Speed::MetrePerSecond};
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Speed, Constructor) {
  EXPECT_NO_THROW(Speed(1.0, Unit::Speed::MillimetrePerSecond));
  EXPECT_EQ(Speed(Length(8.0, Unit::Length::Metre), Time(4.0, Unit::Time::Second)),
            Speed(2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(Length(4.0, Unit::Length::Metre), Frequency(2.0, Unit::Frequency::Hertz)),
            Speed(8.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Length(Speed(4.0, Unit::Speed::MetrePerSecond), Time(2.0, Unit::Time::Second)),
            Length(8.0, Unit::Length::Metre));
  EXPECT_EQ(Length(Speed(8.0, Unit::Speed::MetrePerSecond), Frequency(4.0, Unit::Frequency::Hertz)),
            Length(2.0, Unit::Length::Metre));
  EXPECT_EQ(Time(Length(8.0, Unit::Length::Metre), Speed(4.0, Unit::Speed::MetrePerSecond)),
            Time(2.0, Unit::Time::Second));
  EXPECT_EQ(Frequency(Speed(8.0, Unit::Speed::MetrePerSecond), Length(4.0, Unit::Length::Metre)),
            Frequency(2.0, Unit::Frequency::Hertz));
}

TEST(Speed, CopyAssignmentOperator) {
  {
    const Speed<float> first(1.0F, Unit::Speed::MetrePerSecond);
    Speed<double> second = Speed<double>::Zero();
    second = first;
    EXPECT_EQ(second, Speed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
  {
    const Speed<double> first(1.0, Unit::Speed::MetrePerSecond);
    Speed<double> second = Speed<double>::Zero();
    second = first;
    EXPECT_EQ(second, Speed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
  {
    const Speed<long double> first(1.0L, Unit::Speed::MetrePerSecond);
    Speed<double> second = Speed<double>::Zero();
    second = first;
    EXPECT_EQ(second, Speed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
}

TEST(Speed, CopyConstructor) {
  {
    const Speed<float> first(1.0F, Unit::Speed::MetrePerSecond);
    const Speed<double> second{first};
    EXPECT_EQ(second, Speed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
  {
    const Speed<double> first(1.0, Unit::Speed::MetrePerSecond);
    const Speed<double> second{first};
    EXPECT_EQ(second, Speed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
  {
    const Speed<long double> first(1.0L, Unit::Speed::MetrePerSecond);
    const Speed<double> second{first};
    EXPECT_EQ(second, Speed<double>(1.0, Unit::Speed::MetrePerSecond));
  }
}

TEST(Speed, Create) {
  constexpr Speed quantity = Speed<>::Create<Unit::Speed::MetrePerSecond>(1.0);
  EXPECT_EQ(quantity, Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, DefaultConstructor) {
  EXPECT_NO_THROW(Speed<>{});
}

TEST(Speed, Dimensions) {
  EXPECT_EQ(Speed<>::Dimensions(), RelatedDimensions<Unit::Speed>);
}

TEST(Speed, Hash) {
  const Speed first{1.0, Unit::Speed::MillimetrePerSecond};
  const Speed second{1.00001, Unit::Speed::MillimetrePerSecond};
  const Speed third{-1.0, Unit::Speed::MillimetrePerSecond};
  const std::hash<Speed<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Speed, JSON) {
  EXPECT_EQ(Speed(1.0, Unit::Speed::MetrePerSecond).JSON(),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"m/s\"}");
  EXPECT_EQ(Speed(1.0, Unit::Speed::MillimetrePerSecond).JSON(Unit::Speed::MillimetrePerSecond),
            "{\"value\":" + Print(1.0) + ",\"unit\":\"mm/s\"}");
}

TEST(Speed, MoveAssignmentOperator) {
  Speed first{1.0, Unit::Speed::MetrePerSecond};
  Speed second = Speed<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, MoveConstructor) {
  Speed first{1.0, Unit::Speed::MetrePerSecond};
  const Speed second{std::move(first)};
  EXPECT_EQ(second, Speed(1.0, Unit::Speed::MetrePerSecond));
}

TEST(Speed, MutableValue) {
  Speed quantity{1.0, Unit::Speed::MetrePerSecond};
  double& value = quantity.MutableValue();
  value = 2.0;
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(Speed, Print) {
  EXPECT_EQ(Speed(1.0, Unit::Speed::MetrePerSecond).Print(), Print(1.0) + " m/s");
  EXPECT_EQ(Speed(1.0, Unit::Speed::MillimetrePerSecond).Print(Unit::Speed::MillimetrePerSecond),
            Print(1.0) + " mm/s");
}

TEST(Speed, SetValue) {
  Speed quantity{1.0, Unit::Speed::MetrePerSecond};
  quantity.SetValue(2.0);
  EXPECT_EQ(quantity.Value(), 2.0);
}

TEST(Speed, SizeOf) {
  EXPECT_EQ(sizeof(Speed<>{}), sizeof(double));
}

TEST(Speed, StaticValue) {
  constexpr Speed quantity = Speed<>::Create<Unit::Speed::MillimetrePerSecond>(1.0);
  constexpr double value = quantity.StaticValue<Unit::Speed::MillimetrePerSecond>();
  EXPECT_EQ(value, 1.0);
}

TEST(Speed, Stream) {
  std::ostringstream stream;
  stream << Speed(1.0, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(stream.str(), Speed(1.0, Unit::Speed::MetrePerSecond).Print());
}

TEST(Speed, Unit) {
  EXPECT_EQ(Speed<>::Unit(), Standard<Unit::Speed>);
}

TEST(Speed, Value) {
  EXPECT_EQ(Speed(1.0, Unit::Speed::MetrePerSecond).Value(), 1.0);
  EXPECT_EQ(
      Speed(1.0, Unit::Speed::MillimetrePerSecond).Value(Unit::Speed::MillimetrePerSecond), 1.0);
}

TEST(Speed, XML) {
  EXPECT_EQ(Speed(1.0, Unit::Speed::MetrePerSecond).XML(),
            "<value>" + Print(1.0) + "</value><unit>m/s</unit>");
  EXPECT_EQ(Speed(1.0, Unit::Speed::MillimetrePerSecond).XML(Unit::Speed::MillimetrePerSecond),
            "<value>" + Print(1.0) + "</value><unit>mm/s</unit>");
}

TEST(Speed, YAML) {
  EXPECT_EQ(
      Speed(1.0, Unit::Speed::MetrePerSecond).YAML(), "{value:" + Print(1.0) + ",unit:\"m/s\"}");
  EXPECT_EQ(Speed(1.0, Unit::Speed::MillimetrePerSecond).YAML(Unit::Speed::MillimetrePerSecond),
            "{value:" + Print(1.0) + ",unit:\"mm/s\"}");
}

TEST(Speed, Zero) {
  EXPECT_EQ(Speed<>::Zero(), Speed(0.0, Unit::Speed::MetrePerSecond));
}

}  // namespace

}  // namespace PhQ
