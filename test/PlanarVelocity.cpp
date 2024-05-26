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

#include "../include/PhQ/PlanarVelocity.hpp"

#include <array>
#include <functional>
#include <gtest/gtest.h>
#include <sstream>
#include <utility>

#include "../include/PhQ/Angle.hpp"
#include "../include/PhQ/Frequency.hpp"
#include "../include/PhQ/Length.hpp"
#include "../include/PhQ/PlanarDirection.hpp"
#include "../include/PhQ/PlanarDisplacement.hpp"
#include "../include/PhQ/PlanarVector.hpp"
#include "../include/PhQ/Time.hpp"
#include "../include/PhQ/Unit/Angle.hpp"
#include "../include/PhQ/Unit/Frequency.hpp"
#include "../include/PhQ/Unit/Length.hpp"
#include "../include/PhQ/Unit/Speed.hpp"
#include "../include/PhQ/Unit/Time.hpp"

namespace PhQ {

namespace {

TEST(PlanarVelocity, Angle) {
  EXPECT_EQ(PlanarVelocity({0.0, -2.0}, Unit::Speed::MetrePerSecond)
                .Angle(PlanarVelocity({3.0, 0.0}, Unit::Speed::MetrePerSecond)),
            Angle(90.0, Unit::Angle::Degree));
}

TEST(PlanarVelocity, ArithmeticOperatorAddition) {
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond)
                + PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond),
            PlanarVelocity({3.0, -6.0}, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, ArithmeticOperatorDivision) {
  EXPECT_EQ(PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond) / 2.0,
            PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond)
                / Frequency(2.0, Unit::Frequency::Hertz),
            PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarVelocity, ArithmeticOperatorMultiplication) {
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond) * 2.0,
            PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(2.0 * PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond),
            PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(PlanarDirection(3.0, -4.0) * Speed(5.0, Unit::Speed::MetrePerSecond),
            PlanarVelocity({3.0, -4.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(Speed(5.0, Unit::Speed::MetrePerSecond) * PlanarDirection(3.0, -4.0),
            PlanarVelocity({3.0, -4.0}, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(
      PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond) * Time(2.0, Unit::Time::Second),
      PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre));
  EXPECT_EQ(
      Time(2.0, Unit::Time::Second) * PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond),
      PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre));
}

TEST(PlanarVelocity, ArithmeticOperatorSubtraction) {
  EXPECT_EQ(PlanarVelocity({3.0, -6.0}, Unit::Speed::MetrePerSecond)
                - PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond),
            PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, AssignmentOperatorAddition) {
  PlanarVelocity velocity({1.0, -2.0}, Unit::Speed::MetrePerSecond);
  velocity += PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(velocity, PlanarVelocity({3.0, -6.0}, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, AssignmentOperatorDivision) {
  PlanarVelocity velocity({2.0, -4.0}, Unit::Speed::MetrePerSecond);
  velocity /= 2.0;
  EXPECT_EQ(velocity, PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, AssignmentOperatorMultiplication) {
  PlanarVelocity velocity({1.0, -2.0}, Unit::Speed::MetrePerSecond);
  velocity *= 2.0;
  EXPECT_EQ(velocity, PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, AssignmentOperatorSubtraction) {
  PlanarVelocity velocity({3.0, -6.0}, Unit::Speed::MetrePerSecond);
  velocity -= PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(velocity, PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, ComparisonOperators) {
  const PlanarVelocity first({1.0, -2.000001}, Unit::Speed::MetrePerSecond);
  const PlanarVelocity second({1.0, -2.0}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(first, first);
  EXPECT_NE(first, second);
  EXPECT_LT(first, second);
  EXPECT_GT(second, first);
  EXPECT_LE(first, first);
  EXPECT_LE(first, second);
  EXPECT_GE(first, first);
  EXPECT_GE(second, first);
}

TEST(PlanarVelocity, CopyAssignmentOperator) {
  {
    const PlanarVelocity<float> first({1.0F, -2.0F}, Unit::Speed::MetrePerSecond);
    PlanarVelocity<double> second = PlanarVelocity<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarVelocity<double>({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  }
  {
    const PlanarVelocity<double> first({1.0, -2.0}, Unit::Speed::MetrePerSecond);
    PlanarVelocity<double> second = PlanarVelocity<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarVelocity<double>({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  }
  {
    const PlanarVelocity<long double> first({1.0L, -2.0L}, Unit::Speed::MetrePerSecond);
    PlanarVelocity<double> second = PlanarVelocity<double>::Zero();
    second = first;
    EXPECT_EQ(second, PlanarVelocity<double>({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  }
}

TEST(PlanarVelocity, CopyConstructor) {
  {
    const PlanarVelocity<float> first({1.0F, -2.0F}, Unit::Speed::MetrePerSecond);
    const PlanarVelocity<double> second{first};
    EXPECT_EQ(second, PlanarVelocity<double>({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  }
  {
    const PlanarVelocity<double> first({1.0, -2.0}, Unit::Speed::MetrePerSecond);
    const PlanarVelocity<double> second{first};
    EXPECT_EQ(second, PlanarVelocity<double>({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  }
  {
    const PlanarVelocity<long double> first({1.0L, -2.0L}, Unit::Speed::MetrePerSecond);
    const PlanarVelocity<double> second{first};
    EXPECT_EQ(second, PlanarVelocity<double>({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  }
}

TEST(PlanarVelocity, Create) {
  {
    constexpr PlanarVelocity velocity =
        PlanarVelocity<>::Create<Unit::Speed::MetrePerSecond>(1.0, -2.0);
    EXPECT_EQ(velocity, PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  }
  {
    constexpr PlanarVelocity velocity =
        PlanarVelocity<>::Create<Unit::Speed::MetrePerSecond>(std::array<double, 2>{1.0, -2.0});
    EXPECT_EQ(velocity, PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  }
  {
    constexpr PlanarVelocity velocity =
        PlanarVelocity<>::Create<Unit::Speed::MetrePerSecond>(PlanarVector{1.0, -2.0});
    EXPECT_EQ(velocity, PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
  }
}

TEST(PlanarVelocity, DefaultConstructor) {
  EXPECT_NO_THROW(PlanarVelocity<>{});
}

TEST(PlanarVelocity, Dimensions) {
  EXPECT_EQ(PlanarVelocity<>::Dimensions(), RelatedDimensions<Unit::Speed>);
}

TEST(PlanarVelocity, Hash) {
  const PlanarVelocity first({1.0, -2.000001}, Unit::Speed::MillimetrePerSecond);
  const PlanarVelocity second({1.0, -2.0}, Unit::Speed::MillimetrePerSecond);
  const PlanarVelocity third({1.0, 2.0}, Unit::Speed::MillimetrePerSecond);
  const std::hash<PlanarVelocity<>> hash;
  EXPECT_NE(hash(first), hash(second));
  EXPECT_NE(hash(first), hash(third));
  EXPECT_NE(hash(second), hash(third));
}

TEST(PlanarVelocity, JSON) {
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond).JSON(),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"m/s\"}");
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MillimetrePerSecond)
                .JSON(Unit::Speed::MillimetrePerSecond),
            "{\"value\":{\"x\":" + Print(1.0) + ",\"y\":" + Print(-2.0) + "},\"unit\":\"mm/s\"}");
}

TEST(PlanarVelocity, Magnitude) {
  EXPECT_EQ(PlanarVelocity({3.0, -4.0}, Unit::Speed::MetrePerSecond).Magnitude(),
            Speed(5.0, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, MiscellaneousConstructors) {
  EXPECT_EQ(PlanarDirection(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond)),
            PlanarDirection(1.0, -2.0));
  EXPECT_EQ(Angle(PlanarVelocity({0.0, -2.0}, Unit::Speed::MetrePerSecond),
                  PlanarVelocity({3.0, 0.0}, Unit::Speed::MetrePerSecond)),
            Angle(90.0, Unit::Angle::Degree));
  EXPECT_EQ(PlanarDisplacement(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond),
                               Time(2.0, Unit::Time::Second)),
            PlanarDisplacement({2.0, -4.0}, Unit::Length::Metre));
  EXPECT_EQ(PlanarDisplacement(PlanarVelocity({2.0, -4.0}, Unit::Speed::MetrePerSecond),
                               Frequency(2.0, Unit::Frequency::Hertz)),
            PlanarDisplacement({1.0, -2.0}, Unit::Length::Metre));
}

TEST(PlanarVelocity, MoveAssignmentOperator) {
  PlanarVelocity first({1.0, -2.0}, Unit::Speed::MetrePerSecond);
  PlanarVelocity second = PlanarVelocity<>::Zero();
  second = std::move(first);
  EXPECT_EQ(second, PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, MoveConstructor) {
  PlanarVelocity first({1.0, -2.0}, Unit::Speed::MetrePerSecond);
  const PlanarVelocity second{std::move(first)};
  EXPECT_EQ(second, PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, MutableValue) {
  PlanarVelocity velocity({1.0, -2.0}, Unit::Speed::MetrePerSecond);
  PlanarVector<>& value = velocity.MutableValue();
  value = PlanarVector{-4.0, 5.0};
  EXPECT_EQ(velocity.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarVelocity, PlanarDirection) {
  EXPECT_EQ(PlanarVelocity({3.0, -4.0}, Unit::Speed::MetrePerSecond).PlanarDirection(),
            PlanarDirection(3.0, -4.0));
}

TEST(PlanarVelocity, Print) {
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond).Print(),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") m/s");
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MillimetrePerSecond)
                .Print(Unit::Speed::MillimetrePerSecond),
            "(" + Print(1.0) + ", " + Print(-2.0) + ") mm/s");
}

TEST(PlanarVelocity, SetValue) {
  PlanarVelocity velocity({1.0, -2.0}, Unit::Speed::MetrePerSecond);
  velocity.SetValue({-4.0, 5.0});
  EXPECT_EQ(velocity.Value(), PlanarVector(-4.0, 5.0));
}

TEST(PlanarVelocity, SizeOf) {
  EXPECT_EQ(sizeof(PlanarVelocity<>{}), 2 * sizeof(double));
}

TEST(PlanarVelocity, StandardConstructor) {
  EXPECT_NO_THROW(PlanarVelocity({1.0, -2.0}, Unit::Speed::MillimetrePerSecond));
}

TEST(PlanarVelocity, StaticValue) {
  constexpr PlanarVelocity velocity =
      PlanarVelocity<>::Create<Unit::Speed::MillimetrePerSecond>(1.0, -2.0);
  constexpr PlanarVector value = velocity.StaticValue<Unit::Speed::MillimetrePerSecond>();
  EXPECT_EQ(value, PlanarVector(1.0, -2.0));
}

TEST(PlanarVelocity, Stream) {
  std::ostringstream stream;
  stream << PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond);
  EXPECT_EQ(stream.str(), PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond).Print());
}

TEST(PlanarVelocity, Unit) {
  EXPECT_EQ(PlanarVelocity<>::Unit(), Standard<Unit::Speed>);
}

TEST(PlanarVelocity, Value) {
  EXPECT_EQ(
      PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond).Value(), PlanarVector(1.0, -2.0));
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MillimetrePerSecond)
                .Value(Unit::Speed::MillimetrePerSecond),
            PlanarVector(1.0, -2.0));
}

TEST(PlanarVelocity, XML) {
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond).XML(),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>m/s</unit>");
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MillimetrePerSecond)
                .XML(Unit::Speed::MillimetrePerSecond),
            "<value><x>" + Print(1.0) + "</x><y>" + Print(-2.0) + "</y></value><unit>mm/s</unit>");
}

TEST(PlanarVelocity, XY) {
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond).x(),
            Speed(1.0, Unit::Speed::MetrePerSecond));
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond).y(),
            Speed(-2.0, Unit::Speed::MetrePerSecond));
}

TEST(PlanarVelocity, YAML) {
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MetrePerSecond).YAML(),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"m/s\"}");
  EXPECT_EQ(PlanarVelocity({1.0, -2.0}, Unit::Speed::MillimetrePerSecond)
                .YAML(Unit::Speed::MillimetrePerSecond),
            "{value:{x:" + Print(1.0) + ",y:" + Print(-2.0) + "},unit:\"mm/s\"}");
}

TEST(PlanarVelocity, Zero) {
  EXPECT_EQ(PlanarVelocity<>::Zero(), PlanarVelocity({0.0, 0.0}, Unit::Speed::MetrePerSecond));
}

}  // namespace

}  // namespace PhQ
