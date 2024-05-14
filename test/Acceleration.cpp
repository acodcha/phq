// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

#include "../include/PhQ/Acceleration.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/ScalarAcceleration.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Acceleration.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Speed.hpp"
#include "../include/PhQ/Unit/Time.hpp"
#include "../include/PhQ/Vector.hpp"
#include "../include/PhQ/Velocity.hpp"

namespace PhQ {

namespace {

TEST(Acceleration, Angle) {
  EXPECT_EQ(Acceleration({0.0, -2.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond)
                .Angle(Acceleration({0.0, 0.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Acceleration, ArithmeticOperatorAddition) {
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond)
                + Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond),
            Acceleration({3.0, -6.0, 9.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, ArithmeticOperatorDivision) {
  EXPECT_EQ(Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond) / 2.0,
            Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond) / Time(2.0, Unit::Time::Second),
            Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond) * 2.0,
            Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(2.0 * Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond),
            Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(
      Direction(2.0, -3.0, 6.0) * ScalarAcceleration(7.0, Unit::Acceleration::MetrePerSquareSecond),
      Acceleration({2.0, -3.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(
      ScalarAcceleration(7.0, Unit::Acceleration::MetrePerSquareSecond) * Direction(2.0, -3.0, 6.0),
      Acceleration({2.0, -3.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond)
                * Time(2.0, Unit::Time::Second),
            Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Time(2.0, Unit::Time::Second)
                * Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond),
            Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond)
                * Frequency(2.0, Unit::Frequency::Hertz),
            Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Acceleration({3.0, -6.0, 9.0}, Unit::Acceleration::MetrePerSquareSecond)
                - Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond),
            Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, AssignmentOperatorAddition) {
  Acceleration acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration += Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(acceleration, Acceleration({3.0, -6.0, 9.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, AssignmentOperatorDivision) {
  Acceleration acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration /= 2.0;
  EXPECT_EQ(acceleration, Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, AssignmentOperatorMultiplication) {
  Acceleration acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration *= 2.0;
  EXPECT_EQ(acceleration, Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, AssignmentOperatorSubtraction) {
  Acceleration acceleration({3.0, -6.0, 9.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration -= Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(acceleration, Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, ComparisonOperators) {
  const Acceleration first({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  const Acceleration second({1.0, -2.0, 3.000001}, Unit::Acceleration::MetrePerSquareSecond);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Acceleration, CopyAssignmentOperator) {
  const Acceleration first({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  Acceleration second = Acceleration<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Acceleration, CopyConstructor) {
  const Acceleration first({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  const Acceleration second{first};
  EXPECT_EQ(second, first);
}

TEST(Acceleration, Create) {
  {
    constexpr Acceleration acceleration =
        Acceleration<>::Create<Unit::Acceleration::MetrePerSquareSecond>(1.0, -2.0, 3.0);
    EXPECT_EQ(
        acceleration, Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
  }
  {
    constexpr Acceleration acceleration =
        Acceleration<>::Create<Unit::Acceleration::MetrePerSquareSecond>(
            std::array<double, 3>{1.0, -2.0, 3.0});
    EXPECT_EQ(
        acceleration, Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
  }
  {
    constexpr Acceleration acceleration =
        Acceleration<>::Create<Unit::Acceleration::MetrePerSquareSecond>(Vector{1.0, -2.0, 3.0});
    EXPECT_EQ(
        acceleration, Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
  }
}

TEST(Acceleration, DefaultConstructor) {
  EXPECT_NO_THROW(Acceleration<>{});
}

TEST(Acceleration, Dimensions) {
  EXPECT_EQ(Acceleration<>::Dimensions(), RelatedDimensions<Unit::Acceleration>);
}

TEST(Acceleration, Direction) {
  EXPECT_EQ(Acceleration({2.0, -3.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond).Direction(),
            Direction(2.0, -3.0, 6.0));
}

TEST(Acceleration, Hash) {
  const Acceleration first({1.0, -2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond);
  const Acceleration second({1.0, -2.0, 3.000001}, Unit::Acceleration::MillimetrePerSquareSecond);
  const Acceleration third({1.0, 2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond);
  const std::hash<Acceleration<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Acceleration, JSON) {
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"m/s^2\"}");
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond)
                .JSON(Unit::Acceleration::MillimetrePerSquareSecond),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"mm/s^2\"}");
}

TEST(Acceleration, Magnitude) {
  EXPECT_EQ(Acceleration({2.0, -3.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond).Magnitude(),
            ScalarAcceleration(7.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond)),
            Direction(1.0, -2.0, 3.0));

  EXPECT_EQ(Angle(Acceleration({0.0, -2.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond),
                  Acceleration({0.0, 0.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond)),
            Angle(90.0, Unit::Angle::Degree));

  EXPECT_EQ(Velocity(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond),
                     Time(2.0, Unit::Time::Second)),
            Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));

  EXPECT_EQ(Velocity(Acceleration({2.0, -4.0, 6.0}, Unit::Acceleration::MetrePerSquareSecond),
                     Frequency(2.0, Unit::Frequency::Hertz)),
            Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
}

TEST(Acceleration, MoveAssignmentOperator) {
  Acceleration first({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  Acceleration second = Acceleration<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, MoveConstructor) {
  Acceleration first({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  const Acceleration second{std::move(first)};
  EXPECT_EQ(second, Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, MutableValue) {
  Acceleration acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  Vector<>& value = acceleration.MutableValue();
  value = Vector{-4.0, 5.0, -6.0};
  EXPECT_EQ(acceleration.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Acceleration, Print) {
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") m/s^2");
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond)
                .Print(Unit::Acceleration::MillimetrePerSquareSecond),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") mm/s^2");
}

TEST(Acceleration, SetValue) {
  Acceleration acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond);
  acceleration.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(acceleration.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Acceleration, SizeOf) {
  EXPECT_EQ(sizeof(Acceleration<>{}), 3 * sizeof(double));
}

TEST(Acceleration, StandardConstructor) {
  EXPECT_NO_THROW(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond));
}

TEST(Acceleration, StaticValue) {
  constexpr Acceleration acceleration =
      Acceleration<>::Create<Unit::Acceleration::MillimetrePerSquareSecond>(1.0, -2.0, 3.0);
  constexpr Vector value =
      acceleration.StaticValue<Unit::Acceleration::MillimetrePerSquareSecond>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(Acceleration, Stream) {
  std::ostringstream stream;
  stream << Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond);
  EXPECT_EQ(stream.str(),
            Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond).Print());
}

TEST(Acceleration, Unit) {
  EXPECT_EQ(Acceleration<>::Unit(), Standard<Unit::Acceleration>);
}

TEST(Acceleration, Value) {
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond).Value(),
            Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond)
                .Value(Unit::Acceleration::MillimetrePerSquareSecond),
            Vector(1.0, -2.0, 3.0));
}

TEST(Acceleration, XML) {
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>m/s^2</unit>");
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond)
                .XML(Unit::Acceleration::MillimetrePerSquareSecond),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>mm/s^2</unit>");
}

TEST(Acceleration, XYZ) {
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond).x(),
            ScalarAcceleration(1.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond).y(),
            ScalarAcceleration(-2.0, Unit::Acceleration::MetrePerSquareSecond));
  EXPECT_EQ(Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond).z(),
            ScalarAcceleration(3.0, Unit::Acceleration::MetrePerSquareSecond));
}

TEST(Acceleration, YAML) {
  EXPECT_EQ(
      Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MetrePerSquareSecond).YAML(),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"m/s^2\"}");
  EXPECT_EQ(
      Acceleration({1.0, -2.0, 3.0}, Unit::Acceleration::MillimetrePerSquareSecond)
          .YAML(Unit::Acceleration::MillimetrePerSquareSecond),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"mm/s^2\"}");
}

TEST(Acceleration, Zero) {
  EXPECT_EQ(Acceleration<>::Zero(),
            Acceleration({0.0, 0.0, 0.0}, Unit::Acceleration::MetrePerSquareSecond));
}

}  // namespace

}  // namespace PhQ
