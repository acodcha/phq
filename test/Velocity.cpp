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

#include "../include/PhQ/Velocity.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Direction.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Unit/Speed.hpp"
#include "../include/PhQ/Unit/Time.hpp"
#include "../include/PhQ/Vector.hpp"

namespace PhQ {

namespace {

TEST(Velocity, Angle) {
  EXPECT_EQ(Velocity({0.0, -2.0, 0.0}, Unit::Speed::MetrePerSecond)
                .Angle(Velocity({0.0, 0.0, 3.0}, Unit::Speed::MetrePerSecond)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(Velocity, ArithmeticOperatorAddition) {
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond)
                + Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond),
            Velocity({3.0, -6.0, 9.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, ArithmeticOperatorDivision) {
  EXPECT_EQ(Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond) / 2.0,
            Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Velocity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond) * 2.0,
            Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(2.0 * Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond),
            Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Direction(2.0, -3.0, 6.0) * Speed(7.0, Unit::Speed::MetrePerSecond),
            Velocity({2.0, -3.0, 6.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(7.0, Unit::Speed::MetrePerSecond) * Direction(2.0, -3.0, 6.0),
            Velocity({2.0, -3.0, 6.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond) * Time(2.0, Unit::Time::Second),
            Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));
  EXPECT_EQ(Time(2.0, Unit::Time::Second) * Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond),
            Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));
}

TEST(Velocity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(Velocity({3.0, -6.0, 9.0}, Unit::Speed::MetrePerSecond)
                - Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond),
            Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, AssignmentOperatorAddition) {
  Velocity velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  velocity += Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(velocity, Velocity({3.0, -6.0, 9.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, AssignmentOperatorDivision) {
  Velocity velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond);
  velocity /= 2.0;
  EXPECT_EQ(velocity, Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, AssignmentOperatorMultiplication) {
  Velocity velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  velocity *= 2.0;
  EXPECT_EQ(velocity, Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, AssignmentOperatorSubtraction) {
  Velocity velocity({3.0, -6.0, 9.0}, Unit::Speed::MetrePerSecond);
  velocity -= Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(velocity, Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, ComparisonOperators) {
  const Velocity first({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  const Velocity second({1.0, -2.0, 3.000001}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(Velocity, CopyAssignmentOperator) {
  const Velocity first({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  Velocity second = Velocity<>::Zero();
  second = first;
  EXPECT_EQ(second, first);
}

TEST(Velocity, CopyConstructor) {
  const Velocity first({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  const Velocity second{first};
  EXPECT_EQ(second, first);
}

TEST(Velocity, Create) {
  {
    constexpr Velocity velocity = Velocity<>::Create<Unit::Speed::MetrePerSecond>(1.0, -2.0, 3.0);
    EXPECT_EQ(velocity, Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
  }
  {
    constexpr Velocity velocity =
        Velocity<>::Create<Unit::Speed::MetrePerSecond>(std::array<double, 3>{1.0, -2.0, 3.0});
    EXPECT_EQ(velocity, Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
  }
  {
    constexpr Velocity velocity =
        Velocity<>::Create<Unit::Speed::MetrePerSecond>(Vector{1.0, -2.0, 3.0});
    EXPECT_EQ(velocity, Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
  }
}

TEST(Velocity, DefaultConstructor) {
  EXPECT_NO_THROW(Velocity<>{});
}

TEST(Velocity, Dimensions) {
  EXPECT_EQ(Velocity<>::Dimensions(), RelatedDimensions<Unit::Speed>);
}

TEST(Velocity, Direction) {
  EXPECT_EQ(Velocity({2.0, -3.0, 6.0}, Unit::Speed::MetrePerSecond).Direction(),
            Direction(2.0, -3.0, 6.0));
}

TEST(Velocity, Hash) {
  const Velocity first({1.0, -2.0, 3.0}, Unit::Speed::MillimetrePerSecond);
  const Velocity second({1.0, -2.0, 3.000001}, Unit::Speed::MillimetrePerSecond);
  const Velocity third({1.0, 2.0, 3.0}, Unit::Speed::MillimetrePerSecond);
  const std::hash<Velocity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(Velocity, JSON) {
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"m/s\"}");
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MillimetrePerSecond)
                .JSON(Unit::Speed::MillimetrePerSecond),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + ",\"z\":" + Print(3.0)
                + "},\"unit\":\"mm/s\"}");
}

TEST(Velocity, Magnitude) {
  EXPECT_EQ(Velocity({2.0, -3.0, 6.0}, Unit::Speed::MetrePerSecond).Magnitude(),
            Speed(7.0, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, MiscellaneousConstructors) {
  EXPECT_EQ(Direction(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond)),
            Direction(1.0, -2.0, 3.0));
  EXPECT_EQ(Angle(Velocity({0.0, -2.0, 0.0}, Unit::Speed::MetrePerSecond),
                  Velocity({0.0, 0.0, 3.0}, Unit::Speed::MetrePerSecond)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(Displacement(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond),
                         Time(2.0, Unit::Time::Second)),
            Displacement({2.0, -4.0, 6.0}, Unit::Length::Metre));
  EXPECT_EQ(Displacement(Velocity({2.0, -4.0, 6.0}, Unit::Speed::MetrePerSecond),
                         Frequency(2.0, Unit::Frequency::Hertz)),
            Displacement({1.0, -2.0, 3.0}, Unit::Length::Metre));
}

TEST(Velocity, MoveAssignmentOperator) {
  Velocity first({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  Velocity second = Velocity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, MoveConstructor) {
  Velocity first({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  const Velocity second{std::move(first)};
  EXPECT_EQ(second, Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, MutableValue) {
  Velocity velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  Vector<>& value = velocity.MutableValue();
  value = Vector{-4.0, 2.05, -6.0};
  EXPECT_EQ(velocity.Value(), Vector(-4.0, 2.05, -6.0));
}

TEST(Velocity, Print) {
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") m/s");
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MillimetrePerSecond)
                .Print(Unit::Speed::MillimetrePerSecond),
            "(" + Print(1.0) + ", " + Print(-2.0) + ", " + Print(3.0) + ") mm/s");
}

TEST(Velocity, SetValue) {
  Velocity velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  velocity.SetValue({-4.0, 5.0, -6.0});
  EXPECT_EQ(velocity.Value(), Vector(-4.0, 5.0, -6.0));
}

TEST(Velocity, SizeOf) {
  EXPECT_EQ(sizeof(Velocity<>{}), 3 * sizeof(double));
}

TEST(Velocity, StandardConstructor) {
  EXPECT_NO_THROW(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MillimetrePerSecond));
}

TEST(Velocity, StaticValue) {
  constexpr Velocity velocity =
      Velocity<>::Create<Unit::Speed::MillimetrePerSecond>(1.0, -2.0, 3.0);
  constexpr Vector value = velocity.StaticValue<Unit::Speed::MillimetrePerSecond>();
  EXPECT_EQ(value, Vector(1.0, -2.0, 3.0));
}

TEST(Velocity, Stream) {
  std::ostringstream stream;
  stream << Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(stream.str(), Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond).Print());
}

TEST(Velocity, Unit) {
  EXPECT_EQ(Velocity<>::Unit(), Standard<Unit::Speed>);
}

TEST(Velocity, Value) {
  EXPECT_EQ(
      Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond).Value(), Vector(1.0, -2.0, 3.0));
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MillimetrePerSecond)
                .Value(Unit::Speed::MillimetrePerSecond),
            Vector(1.0, -2.0, 3.0));
}

TEST(Velocity, XML) {
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>m/s</unit>");
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MillimetrePerSecond)
                .XML(Unit::Speed::MillimetrePerSecond),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y><z>" + Print(3.0)
                + "</z></value><unit>mm/s</unit>");
}

TEST(Velocity, XYZ) {
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond).x(),
            Speed(1.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond).y(),
            Speed(-2.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond).z(),
            Speed(3.0, Unit::Speed::MetrePerSecond));
}

TEST(Velocity, YAML) {
  EXPECT_EQ(
      Velocity({1.0, -2.0, 3.0}, Unit::Speed::MetrePerSecond).YAML(),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"m/s\"}");
  EXPECT_EQ(
      Velocity({1.0, -2.0, 3.0}, Unit::Speed::MillimetrePerSecond)
          .YAML(Unit::Speed::MillimetrePerSecond),
      "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + ",z:" + Print(3.0) + "},unit:\"mm/s\"}");
}

TEST(Velocity, Zero) {
  EXPECT_EQ(Velocity<>::Zero(), Velocity({0.0, 0.0, 0.0}, Unit::Speed::MetrePerSecond));
}

}  // namespace

}  // namespace PhQ
